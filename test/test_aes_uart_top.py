# import cocotb
# from cocotb.clock import Clock
# from cocotb.triggers import RisingEdge, Timer
# import random

# # =============================================================
# #  Constants
# # =============================================================
# CLKS_PER_BIT = 4       # 100MHz / 9600 baud
# BIT_PERIOD_NS = 10         # 10ns per clock cycle
# BAUD_NS       = CLKS_PER_BIT * BIT_PERIOD_NS  # one bit period in ns

# # FIPS-197 test vectors
# FIPS_VECTORS = [
#     (
#         0x3243f6a8885a308d313198a2e0370734,
#         0x2b7e151628aed2a6abf7158809cf4f3c,
#         0x3925841d02dc09fbdc118597196a0b32,
#         "FIPS-197 Appendix B"
#     ),
#     (
#         0x00112233445566778899aabbccddeeff,
#         0x000102030405060708090a0b0c0d0e0f,
#         int("69c4e0d86a7b0430d8cdb78070b4c55a", 16),
#         "FIPS-197 Appendix C.1"
#     ),
#     (
#         0x00000000000000000000000000000000,
#         0x00000000000000000000000000000000,
#         0x66e94bd4ef8a2c3b884cfa59ca342b2e,
#         "All-zeros"
#     ),
#     (
#         0xffffffffffffffffffffffffffffffff,
#         0xffffffffffffffffffffffffffffffff,
#         0xbcbf217cb280cf30b2517052193ab979,
#         "All-ones"
#     ),
# ]

# # FSM state names for logging
# FSM_STATES = {
#     0: "S_IDLE",
#     1: "S_RECV_PT",
#     2: "S_RECV_KEY",
#     3: "S_START_AES",
#     4: "S_WAIT_AES",
#     5: "S_SEND_CT",
#     6: "S_WAIT_TX",
# }

# # =============================================================
# #  Helpers
# # =============================================================
# def fmt(val, width=32):
#     try:
#         return f"0x{int(val):0{width}x}"
#     except Exception:
#         return "0x" + "?" * width


# async def reset_dut(dut):
#     dut.rst_btn.value = 1
#     dut.rx.value      = 1    # UART idle line is high
#     await Timer(200, unit="ns")
#     dut.rst_btn.value = 0
#     await RisingEdge(dut.clk)
#     await RisingEdge(dut.clk)


# async def uart_send_byte(dut, byte_val):
#     """
#     Bit-bang one UART byte into dut.rx.
#     8N1 format: start bit + 8 data bits (LSB first) + stop bit
#     """
#     # Start bit
#     dut.rx.value = 0
#     await Timer(BAUD_NS, unit="ns")

#     # Data bits LSB first
#     for i in range(8):
#         dut.rx.value = (byte_val >> i) & 1
#         await Timer(BAUD_NS, unit="ns")

#     # Stop bit
#     dut.rx.value = 1
#     await Timer(BAUD_NS, unit="ns")


# async def uart_send_128(dut, value_128):
#     """
#     Send a 128-bit value as 16 bytes, MSB first.
#     """
#     for i in range(15, -1, -1):
#         byte = (value_128 >> (i * 8)) & 0xff
#         await uart_send_byte(dut, byte)


# async def uart_recv_byte(dut, timeout_ns=50_000_000):
#     """
#     Receive one UART byte from dut.tx.
#     Waits for start bit then samples each bit at the centre.
#     Returns the received byte value.
#     """
#     # Wait for start bit (tx goes low)
#     for _ in range(timeout_ns // 10):
#         await RisingEdge(dut.clk)
#         if int(dut.tx.value) == 0:
#             break
#     else:
#         assert False, "TIMEOUT waiting for UART start bit"

#     # Wait half a bit period to sample in the middle of start bit
#     await Timer(BAUD_NS // 2, unit="ns")

#     # Confirm still low (valid start bit)
#     assert int(dut.tx.value) == 0, "False start bit detected"

#     # Sample 8 data bits
#     received = 0
#     for i in range(8):
#         await Timer(BAUD_NS, unit="ns")
#         bit = int(dut.tx.value)
#         received |= (bit << i)

#     # Wait for stop bit
#     await Timer(BAUD_NS, unit="ns")
#     assert int(dut.tx.value) == 1, "Stop bit error"

#     return received


# async def uart_recv_128(dut):
#     """
#     Receive 16 bytes from dut.tx and reassemble as 128-bit int.
#     MSB first.
#     """
#     result = 0
#     for i in range(16):
#         byte = await uart_recv_byte(dut)
#         result = (result << 8) | byte
#     return result


# def check(dut, label, got, expected, failures):
#     if got == expected:
#         dut._log.info(f"  ✅  {label}")
#         dut._log.info(f"      {fmt(got)}")
#     else:
#         dut._log.error(f"  ❌  {label}")
#         dut._log.error(f"      Got      : {fmt(got)}")
#         dut._log.error(f"      Expected : {fmt(expected)}")
#         failures.append(label)


# async def wait_for_fsm(dut, target_state, timeout=20_000_000):
#     """Wait for top-level FSM to reach target state."""
#     for _ in range(timeout // 10):
#         await RisingEdge(dut.clk)
#         if int(dut.state.value) == target_state:
#             return True
#     return False


# # =============================================================
# #  Test 1 — FIPS Known Answer Vectors
# # =============================================================
# @cocotb.test()
# async def test_fips_vectors(dut):
#     cocotb.start_soon(Clock(dut.clk, BIT_PERIOD_NS, unit="ns").start())
#     await reset_dut(dut)
#     failures = []

#     dut._log.info("=" * 60)
#     dut._log.info("  TEST 1 — FIPS Known Answer Vectors via UART")
#     dut._log.info("=" * 60)

#     for pt, key, exp_ct, name in FIPS_VECTORS:
#         dut._log.info(f"\n  Vector : {name}")
#         dut._log.info(f"  PT     : {fmt(pt)}")
#         dut._log.info(f"  Key    : {fmt(key)}")

#         # Send plaintext then key
#         await uart_send_128(dut, pt)
#         await uart_send_128(dut, key)

#         # Wait for AES to start
#         await wait_for_fsm(dut, 4)  # S_WAIT_AES
#         dut._log.info("  AES core running...")

#         # Receive ciphertext
#         got_ct = await uart_recv_128(dut)

#         check(dut, name, got_ct, exp_ct, failures)

#         # Wait for FSM to return to IDLE before next vector
#         await wait_for_fsm(dut, 0)  # S_IDLE
#         await Timer(1000, unit="ns")

#     assert not failures, f"{len(failures)} vector(s) failed"
#     dut._log.info(f"\n  All {len(FIPS_VECTORS)} FIPS vectors passed ✅")


# # =============================================================
# #  Test 2 — LED Status Verification
# #  Checks LEDs assert/deassert at correct stages
# # =============================================================
# @cocotb.test()
# async def test_led_status(dut):
#     cocotb.start_soon(Clock(dut.clk, BIT_PERIOD_NS, unit="ns").start())
#     await reset_dut(dut)
#     failures = []

#     dut._log.info("=" * 60)
#     dut._log.info("  TEST 2 — LED Status")
#     dut._log.info("=" * 60)

#     PT  = 0x3243f6a8885a308d313198a2e0370734
#     KEY = 0x2b7e151628aed2a6abf7158809cf4f3c

#     # All LEDs should be off at IDLE
#     await Timer(1, unit="ns")
#     if int(dut.led_rx_busy.value)    == 0 and \
#        int(dut.led_encrypting.value) == 0 and \
#        int(dut.led_tx_busy.value)    == 0 and \
#        int(dut.led_done.value)       == 0:
#         dut._log.info("  ✅  All LEDs off at IDLE")
#     else:
#         dut._log.error("  ❌  LEDs not all off at IDLE")
#         failures.append("LEDs not off at IDLE")

#     # Start sending — led_rx_busy should go high
#     cocotb.start_soon(uart_send_128(dut, PT))
#     await wait_for_fsm(dut, 1)  # S_RECV_PT
#     await Timer(1, unit="ns")
#     if int(dut.led_rx_busy.value) == 1:
#         dut._log.info("  ✅  led_rx_busy high during RX")
#     else:
#         dut._log.error("  ❌  led_rx_busy not high during RX")
#         failures.append("led_rx_busy not asserted")

#     await uart_send_128(dut, KEY)

#     # led_encrypting should go high during AES
#     await wait_for_fsm(dut, 4)  # S_WAIT_AES
#     await Timer(1, unit="ns")
#     if int(dut.led_encrypting.value) == 1:
#         dut._log.info("  ✅  led_encrypting high during AES")
#     else:
#         dut._log.error("  ❌  led_encrypting not high during AES")
#         failures.append("led_encrypting not asserted")

#     # led_tx_busy should go high during TX
#     await wait_for_fsm(dut, 5)  # S_SEND_CT
#     await Timer(1, unit="ns")
#     if int(dut.led_tx_busy.value) == 1:
#         dut._log.info("  ✅  led_tx_busy high during TX")
#     else:
#         dut._log.error("  ❌  led_tx_busy not high during TX")
#         failures.append("led_tx_busy not asserted")

#     # Drain the TX
#     await uart_recv_128(dut)
#     await wait_for_fsm(dut, 0)  # S_IDLE
#     await Timer(1, unit="ns")
#     if int(dut.led_tx_busy.value) == 0:
#         dut._log.info("  ✅  led_tx_busy low after TX done")
#     else:
#         dut._log.error("  ❌  led_tx_busy still high after TX")
#         failures.append("led_tx_busy not deasserted")

#     assert not failures, f"{len(failures)} LED check(s) failed"
#     dut._log.info("  LED status test passed ✅")


# # =============================================================
# #  Test 3 — Back-to-back transactions
# #  Send multiple encrypt requests without reset
# # =============================================================
# @cocotb.test()
# async def test_back_to_back(dut):
#     cocotb.start_soon(Clock(dut.clk, BIT_PERIOD_NS, unit="ns").start())
#     await reset_dut(dut)
#     failures = []

#     dut._log.info("=" * 60)
#     dut._log.info("  TEST 3 — Back-to-back Transactions")
#     dut._log.info("=" * 60)

#     for i, (pt, key, exp_ct, name) in enumerate(FIPS_VECTORS):
#         dut._log.info(f"\n  Transaction {i+1}: {name}")

#         await uart_send_128(dut, pt)
#         await uart_send_128(dut, key)
#         got_ct = await uart_recv_128(dut)

#         check(dut, f"Back-to-back #{i+1} ({name})", got_ct, exp_ct, failures)

#         # Small gap between transactions
#         await Timer(5000, unit="ns")

#     assert not failures, f"{len(failures)} back-to-back test(s) failed"
#     dut._log.info("  Back-to-back test passed ✅")


# # =============================================================
# #  Test 4 — Reset during receive
# #  Assert reset mid-way through receiving plaintext
# #  Then send fresh data and verify correct result
# # =============================================================
# @cocotb.test()
# async def test_reset_during_rx(dut):
#     cocotb.start_soon(Clock(dut.clk, BIT_PERIOD_NS, unit="ns").start())
#     await reset_dut(dut)
#     failures = []

#     dut._log.info("=" * 60)
#     dut._log.info("  TEST 4 — Reset During RX")
#     dut._log.info("=" * 60)

#     PT  = 0x3243f6a8885a308d313198a2e0370734
#     KEY = 0x2b7e151628aed2a6abf7158809cf4f3c
#     EXP = 0x3925841d02dc09fbdc118597196a0b32

#     # Send only 8 bytes of plaintext then reset
#     dut._log.info("  Sending partial plaintext (8 bytes) then resetting...")
#     for i in range(15, 7, -1):
#         byte = (PT >> (i * 8)) & 0xff
#         await uart_send_byte(dut, byte)

#     # Assert reset
#     dut.rst_btn.value = 1
#     await Timer(200, unit="ns")
#     dut.rst_btn.value = 0
#     await RisingEdge(dut.clk)

#     # Verify FSM returned to IDLE
#     await Timer(100, unit="ns")
#     st = int(dut.state.value)
#     if st == 0:
#         dut._log.info("  ✅  FSM back to IDLE after reset")
#     else:
#         dut._log.error(f"  ❌  FSM not in IDLE after reset, state={st}")
#         failures.append("FSM not IDLE after reset")

#     # Now send a fresh complete transaction
#     dut._log.info("  Sending fresh transaction after reset...")
#     await uart_send_128(dut, PT)
#     await uart_send_128(dut, KEY)
#     got_ct = await uart_recv_128(dut)

#     check(dut, "Encryption after mid-RX reset", got_ct, EXP, failures)

#     assert not failures, f"{len(failures)} reset test(s) failed"
#     dut._log.info("  Reset during RX test passed ✅")


# # =============================================================
# #  Test 5 — Random vectors (UART + SW reference)
# # =============================================================
# def aes_encrypt_sw(plaintext, key):
#     """Pure Python AES-128 reference."""
#     SBOX = [
#         0x63,0x7c,0x77,0x7b,0xf2,0x6b,0x6f,0xc5,0x30,0x01,0x67,0x2b,0xfe,0xd7,0xab,0x76,
#         0xca,0x82,0xc9,0x7d,0xfa,0x59,0x47,0xf0,0xad,0xd4,0xa2,0xaf,0x9c,0xa4,0x72,0xc0,
#         0xb7,0xfd,0x93,0x26,0x36,0x3f,0xf7,0xcc,0x34,0xa5,0xe5,0xf1,0x71,0xd8,0x31,0x15,
#         0x04,0xc7,0x23,0xc3,0x18,0x96,0x05,0x9a,0x07,0x12,0x80,0xe2,0xeb,0x27,0xb2,0x75,
#         0x09,0x83,0x2c,0x1a,0x1b,0x6e,0x5a,0xa0,0x52,0x3b,0xd6,0xb3,0x29,0xe3,0x2f,0x84,
#         0x53,0xd1,0x00,0xed,0x20,0xfc,0xb1,0x5b,0x6a,0xcb,0xbe,0x39,0x4a,0x4c,0x58,0xcf,
#         0xd0,0xef,0xaa,0xfb,0x43,0x4d,0x33,0x85,0x45,0xf9,0x02,0x7f,0x50,0x3c,0x9f,0xa8,
#         0x51,0xa3,0x40,0x8f,0x92,0x9d,0x38,0xf5,0xbc,0xb6,0xda,0x21,0x10,0xff,0xf3,0xd2,
#         0xcd,0x0c,0x13,0xec,0x5f,0x97,0x44,0x17,0xc4,0xa7,0x7e,0x3d,0x64,0x5d,0x19,0x73,
#         0x60,0x81,0x4f,0xdc,0x22,0x2a,0x90,0x88,0x46,0xee,0xb8,0x14,0xde,0x5e,0x0b,0xdb,
#         0xe0,0x32,0x3a,0x0a,0x49,0x06,0x24,0x5c,0xc2,0xd3,0xac,0x62,0x91,0x95,0xe4,0x79,
#         0xe7,0xc8,0x37,0x6d,0x8d,0xd5,0x4e,0xa9,0x6c,0x56,0xf4,0xea,0x65,0x7a,0xae,0x08,
#         0xba,0x78,0x25,0x2e,0x1c,0xa6,0xb4,0xc6,0xe8,0xdd,0x74,0x1f,0x4b,0xbd,0x8b,0x8a,
#         0x70,0x3e,0xb5,0x66,0x48,0x03,0xf6,0x0e,0x61,0x35,0x57,0xb9,0x86,0xc1,0x1d,0x9e,
#         0xe1,0xf8,0x98,0x11,0x69,0xd9,0x8e,0x94,0x9b,0x1e,0x87,0xe9,0xce,0x55,0x28,0xdf,
#         0x8c,0xa1,0x89,0x0d,0xbf,0xe6,0x42,0x68,0x41,0x99,0x2d,0x0f,0xb0,0x54,0xbb,0x16,
#     ]
#     RCON = [0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80,0x1b,0x36]

#     def xtime(b):
#         return ((b<<1)^0x1b)&0xff if b&0x80 else (b<<1)&0xff

#     def gmul(a,b):
#         p=0
#         for _ in range(8):
#             if b&1: p^=a
#             hi=a&0x80; a=(a<<1)&0xff
#             if hi: a^=0x1b
#             b>>=1
#         return p

#     key_bytes = [(key>>(120-8*i))&0xff for i in range(16)]
#     w=[]
#     for i in range(4): w.append(key_bytes[4*i:4*i+4])
#     for i in range(4,44):
#         tmp=w[i-1][:]
#         if i%4==0:
#             tmp=[SBOX[tmp[1]],SBOX[tmp[2]],SBOX[tmp[3]],SBOX[tmp[0]]]
#             tmp[0]^=RCON[i//4-1]
#         w.append([w[i-4][j]^tmp[j] for j in range(4)])
#     round_keys=[[(w[4*r+c][b]) for c in range(4) for b in range(4)]
#                  for r in range(11)]
#     # Fix round key format
#     rks=[]
#     for r in range(11):
#         rk=[]
#         for c in range(4): rk.extend(w[r*4+c])
#         rks.append(rk)

#     pt_bytes=[(plaintext>>(120-8*i))&0xff for i in range(16)]
#     state=[[pt_bytes[r*4+c] for c in range(4)] for r in range(4)]

#     def add_rk(state,rk):
#         for r in range(4):
#             for c in range(4):
#                 state[r][c]^=rk[r*4+c]

#     add_rk(state,rks[0])
#     for rnd in range(1,11):
#         for r in range(4):
#             for c in range(4):
#                 state[r][c]=SBOX[state[r][c]]
#         for r in range(1,4):
#             state[r]=state[r][r:]+state[r][:r]
#         if rnd<10:
#             for c in range(4):
#                 s0,s1,s2,s3=state[0][c],state[1][c],state[2][c],state[3][c]
#                 state[0][c]=gmul(2,s0)^gmul(3,s1)^s2^s3
#                 state[1][c]=s0^gmul(2,s1)^gmul(3,s2)^s3
#                 state[2][c]=s0^s1^gmul(2,s2)^gmul(3,s3)
#                 state[3][c]=gmul(3,s0)^s1^s2^gmul(2,s3)
#         add_rk(state,rks[rnd])

#     result=0
#     for r in range(4):
#         for c in range(4):
#             result=(result<<8)|state[r][c]
#     return result


# @cocotb.test()
# async def test_random_vectors(dut):
#     cocotb.start_soon(Clock(dut.clk, BIT_PERIOD_NS, unit="ns").start())
#     await reset_dut(dut)
#     failures = []

#     NUM    = 5
#     MASK   = (1 << 128) - 1
#     rng    = random.Random(0xDEADBEEF)

#     dut._log.info("=" * 60)
#     dut._log.info(f"  TEST 5 — {NUM} Random Vectors via UART")
#     dut._log.info("=" * 60)

#     for i in range(NUM):
#         pt  = rng.randint(0, MASK)
#         key = rng.randint(0, MASK)
#         exp = aes_encrypt_sw(pt, key)

#         dut._log.info(f"\n  Random #{i+1}")
#         dut._log.info(f"  PT  : {fmt(pt)}")
#         dut._log.info(f"  Key : {fmt(key)}")

#         await uart_send_128(dut, pt)
#         await uart_send_128(dut, key)
#         got = await uart_recv_128(dut)

#         check(dut, f"Random #{i+1}", got, exp, failures)
#         await Timer(5000, unit="ns")

#     assert not failures, f"{len(failures)} random vector(s) failed"
#     dut._log.info(f"  All {NUM} random vectors passed ✅")


# # =============================================================
# #  Test 6 — UART Framing Verification
# #  Checks actual bit timing on TX output
# # =============================================================
# @cocotb.test()
# async def test_uart_framing(dut):
#     cocotb.start_soon(Clock(dut.clk, BIT_PERIOD_NS, unit="ns").start())
#     await reset_dut(dut)
#     failures = []

#     dut._log.info("=" * 60)
#     dut._log.info("  TEST 6 — UART TX Framing")
#     dut._log.info("=" * 60)

#     PT  = 0x3243f6a8885a308d313198a2e0370734
#     KEY = 0x2b7e151628aed2a6abf7158809cf4f3c
#     EXP_BYTE = 0x39  # MSB of expected ciphertext 0x3925841d...

#     await uart_send_128(dut, PT)
#     await uart_send_128(dut, KEY)

#     # Wait for TX start bit
#     for _ in range(50_000_000 // 10):
#         await RisingEdge(dut.clk)
#         if int(dut.tx.value) == 0:
#             break
#     else:
#         assert False, "TIMEOUT waiting for TX start bit"

#     dut._log.info("  Start bit detected ✅")

#     # Verify start bit holds for full bit period
#     await Timer(BAUD_NS // 2, unit="ns")
#     if int(dut.tx.value) == 0:
#         dut._log.info("  ✅  Start bit stable at mid-sample")
#     else:
#         dut._log.error("  ❌  Start bit unstable")
#         failures.append("Start bit unstable")

#     # Sample 8 data bits at centre of each bit period
#     received = 0
#     for i in range(8):
#         await Timer(BAUD_NS, unit="ns")
#         bit = int(dut.tx.value)
#         received |= (bit << i)
#         dut._log.info(f"  Bit {i} = {bit}")

#     # Check stop bit
#     await Timer(BAUD_NS, unit="ns")
#     if int(dut.tx.value) == 1:
#         dut._log.info("  ✅  Stop bit correct (high)")
#     else:
#         dut._log.error("  ❌  Stop bit incorrect (should be high)")
#         failures.append("Stop bit error")

#     dut._log.info(f"  First byte received : 0x{received:02x}")
#     dut._log.info(f"  Expected            : 0x{EXP_BYTE:02x}")

#     if received == EXP_BYTE:
#         dut._log.info("  ✅  First ciphertext byte correct")
#     else:
#         dut._log.error("  ❌  First ciphertext byte wrong")
#         failures.append(f"First byte: got 0x{received:02x} expected 0x{EXP_BYTE:02x}")

#     # Drain remaining 15 bytes
#     for _ in range(15):
#         await uart_recv_byte(dut)

#     assert not failures, f"{len(failures)} framing check(s) failed"
#     dut._log.info("  UART framing test passed ✅")

"""
CocoTB Testbench for aes_top.v
Tests UART-driven AES encryption over the top-level FSM.

Requirements:
    pip install cocotb
    Simulator: iverilog or verilator (see Makefile below)

How it works:
    1. Drive 16 key bytes over the simulated UART RX line.
    2. Drive 16 plaintext bytes over the same line.
    3. Wait for the AES core to finish (aes_done goes high).
    4. Collect the 16 ciphertext bytes that are sent back over TX.
    5. Compare against a known-good AES-128 ECB reference vector.
"""

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, FallingEdge, Timer, ClockCycles
from cocotb.utils import get_sim_time

# ──────────────────────────────────────────────
# UART helpers (bit-bang at 10 MHz / 1041 clks per bit)
# ──────────────────────────────────────────────
CLKS_PER_BIT = 4   # must match the DUT parameter


async def uart_send_byte(dut, byte: int):
    """Bit-bang one byte onto dut.RsRx (LSB first, 8N1)."""
    # Start bit (low)
    dut.RsRx.value = 0
    await ClockCycles(dut.clk, CLKS_PER_BIT)

    # Data bits (LSB first)
    for i in range(8):
        dut.RsRx.value = (byte >> i) & 1
        await ClockCycles(dut.clk, CLKS_PER_BIT)

    # Stop bit (high)
    dut.RsRx.value = 1
    await ClockCycles(dut.clk, CLKS_PER_BIT)


async def uart_send_bytes(dut, data: bytes):
    """Send a sequence of bytes over UART with a small inter-byte gap."""
    for b in data:
        await uart_send_byte(dut, b)
        await ClockCycles(dut.clk, 10)   # small idle gap


async def uart_recv_byte(dut) -> int:
    """
    Wait for a falling edge on RsTx (start bit), then sample 8 data bits.
    Returns the received byte value.
    """
    # Wait for start bit (TX goes low)
    await FallingEdge(dut.RsTx)

    # Skip past the start bit; sample in the middle of each data bit
    await ClockCycles(dut.clk, CLKS_PER_BIT + CLKS_PER_BIT // 2)

    received = 0
    for i in range(8):
        bit = int(dut.RsTx.value)
        received |= (bit << i)
        if i < 7:
            await ClockCycles(dut.clk, CLKS_PER_BIT)

    # Wait for stop bit
    await ClockCycles(dut.clk, CLKS_PER_BIT)
    return received


async def uart_recv_bytes(dut, n: int) -> bytes:
    """Receive n bytes from the DUT TX line."""
    result = []
    for _ in range(n):
        b = await uart_recv_byte(dut)
        result.append(b)
    return bytes(result)


# ──────────────────────────────────────────────
# Reset helper
# ──────────────────────────────────────────────
async def do_reset(dut, cycles: int = 20):
    dut.btnC.value = 1
    dut.RsRx.value = 1          # idle high
    dut.sw_encrypt.value = 0
    await ClockCycles(dut.clk, cycles)
    dut.btnC.value = 0
    await ClockCycles(dut.clk, 5)


# ──────────────────────────────────────────────
# Test 1 – NIST FIPS-197 Appendix B known-answer vector
# ──────────────────────────────────────────────
@cocotb.test()
async def test_nist_vector(dut):
    """
    NIST FIPS-197 Appendix B
      Key       : 2b 7e 15 16 28 ae d2 a6 ab f7 15 88 09 cf 4f 3c
      Plaintext : 32 43 f6 a8 88 5a 30 8d 31 31 98 a2 e0 37 07 34
      Ciphertext: 39 25 84 1d 02 dc 09 fb dc 11 85 97 19 6a 0b 32
    """
    KEY        = bytes.fromhex("2b7e151628aed2a6abf7158809cf4f3c")
    PLAINTEXT  = bytes.fromhex("3243f6a8885a308d313198a2e0370734")
    EXPECTED   = bytes.fromhex("3925841d02dc09fbdc118597196a0b32")

    # Start 100 MHz clock
    cocotb.start_soon(Clock(dut.clk, 10, units="ns").start())

    await do_reset(dut)

    dut._log.info("Sending 16-byte key …")
    await uart_send_bytes(dut, KEY)

    dut._log.info("Sending 16-byte plaintext …")
    await uart_send_bytes(dut, PLAINTEXT)

    dut._log.info("Waiting for 16-byte ciphertext …")
    received = await uart_recv_bytes(dut, 16)

    dut._log.info(f"Received : {received.hex()}")
    dut._log.info(f"Expected : {EXPECTED.hex()}")

    assert received == EXPECTED, (
        f"Ciphertext mismatch!\n"
        f"  Got     : {received.hex()}\n"
        f"  Expected: {EXPECTED.hex()}"
    )
    dut._log.info("✓ NIST vector passed")


# ──────────────────────────────────────────────
# Test 2 – All-zeros key & plaintext
# ──────────────────────────────────────────────
@cocotb.test()
async def test_all_zeros(dut):
    """
    AES-128 ECB, all-zero key and plaintext.
      Key       : 00 * 16
      Plaintext : 00 * 16
      Ciphertext: 66 e9 4b d4 ef 8a 2c 3b 88 4c fa 59 ca 34 2b 2e
    """
    KEY       = bytes(16)
    PLAINTEXT = bytes(16)
    EXPECTED  = bytes.fromhex("66e94bd4ef8a2c3b884cfa59ca342b2e")

    cocotb.start_soon(Clock(dut.clk, 10, units="ns").start())

    await do_reset(dut)

    await uart_send_bytes(dut, KEY)
    await uart_send_bytes(dut, PLAINTEXT)
    received = await uart_recv_bytes(dut, 16)

    dut._log.info(f"Received : {received.hex()}")
    dut._log.info(f"Expected : {EXPECTED.hex()}")

    assert received == EXPECTED, (
        f"All-zeros test failed!\n"
        f"  Got     : {received.hex()}\n"
        f"  Expected: {EXPECTED.hex()}"
    )
    dut._log.info("✓ All-zeros vector passed")


# ──────────────────────────────────────────────
# Test 3 – Reset mid-transaction
# ──────────────────────────────────────────────
@cocotb.test()
async def test_reset_mid_transaction(dut):
    """
    Send only 8 key bytes, assert reset, then run a full valid transaction.
    The FSM must restart cleanly from WAIT_KEY.
    """
    KEY       = bytes.fromhex("2b7e151628aed2a6abf7158809cf4f3c")
    PLAINTEXT = bytes.fromhex("3243f6a8885a308d313198a2e0370734")
    EXPECTED  = bytes.fromhex("3925841d02dc09fbdc11859719 6a0b32".replace(" ", ""))

    cocotb.start_soon(Clock(dut.clk, 10, units="ns").start())

    await do_reset(dut)

    # Send only 8 bytes then reset
    dut._log.info("Sending partial key (8 bytes) then resetting …")
    await uart_send_bytes(dut, KEY[:8])
    await do_reset(dut)

    # Now run the full test
    dut._log.info("Running full transaction after reset …")
    await uart_send_bytes(dut, KEY)
    await uart_send_bytes(dut, PLAINTEXT)
    received = await uart_recv_bytes(dut, 16)

    assert received == EXPECTED, (
        f"Post-reset transaction failed!\n"
        f"  Got     : {received.hex()}\n"
        f"  Expected: {EXPECTED.hex()}"
    )
    dut._log.info("✓ Reset mid-transaction test passed")


# ──────────────────────────────────────────────
# Test 4 – LED sanity check (DONE bit set after encryption)
# ──────────────────────────────────────────────
@cocotb.test()
async def test_led_done_flag(dut):
    """
    After a successful encryption, led[15] (the DONE state bit) must be high.
    """
    KEY       = bytes(16)
    PLAINTEXT = bytes(16)

    cocotb.start_soon(Clock(dut.clk, 10, units="ns").start())

    await do_reset(dut)

    await uart_send_bytes(dut, KEY)
    await uart_send_bytes(dut, PLAINTEXT)
    await uart_recv_bytes(dut, 16)
    await ClockCycles(dut.clk, 50)  # give FSM time to reach DONE state
    led_val = int(dut.led.value)
    assert (led_val >> 15) & 1, (
        f"led[15] (DONE flag) should be 1, got led = {led_val:#06x}"
    )
    dut._log.info(f"✓ LED DONE flag is set (led = {led_val:#06x})")