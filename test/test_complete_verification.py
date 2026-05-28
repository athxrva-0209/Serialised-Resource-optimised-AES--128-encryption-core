import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, Timer
import random

# =============================================================
#  Utilities
# =============================================================
def fmt(val, width=32):
    try:
        return f"0x{int(val):0{width}x}"
    except Exception:
        return "0x" + "?" * width

# def aes_encrypt_sw(plaintext, key):
#     """
#     Pure-Python AES-128 reference implementation.
#     Used to generate expected values for random test vectors.
#     """
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
#         return ((b << 1) ^ 0x1b) & 0xff if b & 0x80 else (b << 1) & 0xff

#     def mix_col(col):
#         s0,s1,s2,s3 = col
#         return [
#             xtime(s0)^xtime(s1)^s1^s2^s3,
#             s0^xtime(s1)^xtime(s2)^s2^s3,
#             s0^s1^xtime(s2)^xtime(s3)^s3,
#             xtime(s0)^s0^s1^s2^xtime(s3),
#         ]

#     # State as 4x4 column-major bytes
#     def int_to_state(v):
#         b = [(v >> (120 - 8*i)) & 0xff for i in range(16)]
#         return [[b[r*4+c] for r in range(4)] for c in range(4)]

#     def state_to_int(s):
#         v = 0
#         for c in range(4):
#             for r in range(4):
#                 v = (v << 8) | s[c][r]
#         return v

#     # Key expansion
#     def key_expand(key_int):
#         w = [(key_int >> (96 - 32*i)) & 0xffffffff for i in range(4)]
#         for i in range(4, 44):
#             tmp = w[i-1]
#             if i % 4 == 0:
#                 b = [(tmp >> (24-8*j)) & 0xff for j in range(4)]
#                 b = [SBOX[b[1]], SBOX[b[2]], SBOX[b[3]], SBOX[b[0]]]
#                 b[0] ^= RCON[i//4 - 1]
#                 tmp = (b[0]<<24)|(b[1]<<16)|(b[2]<<8)|b[3]
#             w.append(w[i-4] ^ tmp)
#         return [((w[4*i]<<96)|(w[4*i+1]<<64)|(w[4*i+2]<<32)|w[4*i+3])
#                 for i in range(11)]

#     round_keys = key_expand(key)
#     state = int_to_state(plaintext ^ round_keys[0])

#     for rnd in range(1, 11):
#         # SubBytes
#         state = [[SBOX[state[c][r]] for r in range(4)] for c in range(4)]
#         # ShiftRows
#         for r in range(1, 4):
#             row = [state[c][r] for c in range(4)]
#             row = row[r:] + row[:r]
#             for c in range(4):
#                 state[c][r] = row[c]
#         # MixColumns (skip round 10)
#         if rnd < 10:
#             state = [mix_col([state[c][r] for r in range(4)])
#                      for c in range(4)]
#             state = [[state[c][r] for r in range(4)] for c in range(4)]
#         # AddRoundKey
#         rk = int_to_state(round_keys[rnd])
#         state = [[state[c][r] ^ rk[c][r] for r in range(4)] for c in range(4)]

#     return state_to_int(state)

def aes_encrypt_sw(plaintext, key):
    """
    AES-128 reference using pycryptodome.
    Install: pip install pycryptodome
    """
    from Crypto.Cipher import AES
    import struct

    # Convert 128-bit integers to 16-byte big-endian bytes
    pt_bytes  = plaintext.to_bytes(16, 'big')
    key_bytes = key.to_bytes(16, 'big')

    cipher = AES.new(key_bytes, AES.MODE_ECB)
    ct_bytes = cipher.encrypt(pt_bytes)

    return int.from_bytes(ct_bytes, 'big')

async def reset_dut(dut):
    dut.rst_n.value = 0
    dut.start.value = 0
    await Timer(20, unit="ns")
    dut.rst_n.value = 1
    await RisingEdge(dut.clk)

async def wait_done(dut, timeout=5000):
    for _ in range(timeout):
        await RisingEdge(dut.clk)
        if int(dut.done.value) == 1:
            return True
    return False

async def encrypt(dut, plaintext, key):
    """Drive inputs, wait for done, return ciphertext."""
    dut.plaintext.value = plaintext
    dut.key.value       = key
    dut.start.value     = 1
    await RisingEdge(dut.clk)
    dut.start.value     = 0
    ok = await wait_done(dut)
    assert ok, f"TIMEOUT encrypting {fmt(plaintext)}"
    await Timer(1, unit="ns")
    return int(dut.ciphertext.value)

def check(dut, label, got, expected, failures):
    if got == expected:
        dut._log.info(f"  ✅  {label}")
    else:
        dut._log.error(f"  ❌  {label}")
        dut._log.error(f"       Got      : {fmt(got)}")
        dut._log.error(f"       Expected : {fmt(expected)}")
        failures.append(label)

# =============================================================
#  Test 1 — FIPS-197 Known Answer Vectors
# =============================================================
@cocotb.test()
async def test_fips_vectors(dut):
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    await reset_dut(dut)
    failures = []

    vectors = [
        ("FIPS-197 Appendix B",
         0x3243f6a8885a308d313198a2e0370734,
         0x2b7e151628aed2a6abf7158809cf4f3c,
         0x3925841d02dc09fbdc118597196a0b32),
        ("FIPS-197 Appendix C.1",
         0x00112233445566778899aabbccddeeff,
         0x000102030405060708090a0b0c0d0e0f,
         int("69c4e0d86a7b0430d8cdb78070b4c55a", 16)),
        ("All-zeros PT and Key",
         0x00000000000000000000000000000000,
         0x00000000000000000000000000000000,
         0x66e94bd4ef8a2c3b884cfa59ca342b2e),
        ("All-ones PT and Key",
         0xffffffffffffffffffffffffffffffff,
         0xffffffffffffffffffffffffffffffff,
         0xbcbf217cb280cf30b2517052193ab979),
        ("NIST KAT #1",
         0xf34481ec3cc627bacd5dc3fb08f273e6,
         0x00000000000000000000000000000000,
         0x0336763e966d92595a567cc9ce537f5e),
        ("NIST KAT #2",
         0x9798c4640bad75c7c3227db910174e72,
         0x00000000000000000000000000000000,
         0xa9a1631bf4996954ebc093957b234589),
        ("NIST KAT #3",
         0x96ab5c2ff612d9dfaae8c31f30c42168,
         0x00000000000000000000000000000000,
         0xff4f8391a6a40ca5b25d23bedd44a597),
        ("Zero PT non-zero Key",
         0x00000000000000000000000000000000,
         0x2b7e151628aed2a6abf7158809cf4f3c,
         0x7df76b0c1ab899b33e42f047b91b546f),
        ("Non-zero PT zero Key",
         0x3243f6a8885a308d313198a2e0370734,
         0x00000000000000000000000000000000,
         0xe527936d049f88872a4903305b975bd1),
    ]

    dut._log.info("=" * 60)
    dut._log.info("  TEST 1 — FIPS / NIST Known Answer Vectors")
    dut._log.info("=" * 60)

    for name, pt, key, exp_ct in vectors:
        got = await encrypt(dut, pt, key)
        check(dut, name, got, exp_ct, failures)

    assert not failures, f"{len(failures)} FIPS vector(s) failed"
    dut._log.info(f"  All {len(vectors)} FIPS/NIST vectors passed ✅")


# =============================================================
#  Test 2 — Random Vectors (RTL vs SW reference)
# =============================================================
@cocotb.test()
async def test_random_vectors(dut):
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    await reset_dut(dut)
    failures = []

    NUM_VECTORS = 20
    MASK128     = (1 << 128) - 1
    SEED = 0xDEADBEEF
    rng  = random.Random(SEED)

    dut._log.info("=" * 60)
    dut._log.info(f"  TEST 2 — {NUM_VECTORS} Random Vectors (RTL vs SW ref)")
    dut._log.info("=" * 60)

    for i in range(NUM_VECTORS):
        pt  = rng.randint(0, MASK128)
        key = rng.randint(0, MASK128)
        exp = aes_encrypt_sw(pt, key)
        got = await encrypt(dut, pt, key)
        label = f"Random #{i+1:02d}  pt={fmt(pt)}  key={fmt(key)}"
        check(dut, label, got, exp, failures)

    assert not failures, f"{len(failures)} random vector(s) failed"
    dut._log.info(f"  All {NUM_VECTORS} random vectors passed ✅")


# =============================================================
#  Test 3 — Back-to-back Encryptions (no state leakage)
# =============================================================
@cocotb.test()
async def test_back_to_back(dut):
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    await reset_dut(dut)
    failures = []

    dut._log.info("=" * 60)
    dut._log.info("  TEST 3 — Back-to-back Encryptions")
    dut._log.info("=" * 60)

    pairs = [
        (0x3243f6a8885a308d313198a2e0370734,
         0x2b7e151628aed2a6abf7158809cf4f3c),
        (0x00112233445566778899aabbccddeeff,
         0x000102030405060708090a0b0c0d0e0f),
        (0x00000000000000000000000000000000,
         0x00000000000000000000000000000000),
        (0xffffffffffffffffffffffffffffffff,
         0xffffffffffffffffffffffffffffffff),
        # Same plaintext, different key
        (0x3243f6a8885a308d313198a2e0370734,
         0x000102030405060708090a0b0c0d0e0f),
        # Different plaintext, same key
        (0x00112233445566778899aabbccddeeff,
         0x2b7e151628aed2a6abf7158809cf4f3c),
    ]

    for i, (pt, key) in enumerate(pairs):
        exp = aes_encrypt_sw(pt, key)
        got = await encrypt(dut, pt, key)
        check(dut, f"Back-to-back #{i+1}", got, exp, failures)
        # No reset between encryptions — tests state isolation

    assert not failures, f"{len(failures)} back-to-back test(s) failed"
    dut._log.info("  All back-to-back tests passed ✅")


# =============================================================
#  Test 4 — Reset During Operation
# =============================================================
@cocotb.test()
async def test_reset_during_operation(dut):
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    await reset_dut(dut)
    failures = []

    dut._log.info("=" * 60)
    dut._log.info("  TEST 4 — Reset During Operation")
    dut._log.info("=" * 60)

    PT  = 0x3243f6a8885a308d313198a2e0370734
    KEY = 0x2b7e151628aed2a6abf7158809cf4f3c
    EXP = 0x3925841d02dc09fbdc118597196a0b32

    # Start encryption then reset mid-way
    dut.plaintext.value = PT
    dut.key.value       = KEY
    dut.start.value     = 1
    await RisingEdge(dut.clk)
    dut.start.value     = 0

    # Wait a few cycles then assert reset
    for _ in range(10):
        await RisingEdge(dut.clk)

    dut._log.info("  Asserting reset mid-encryption...")
    dut.rst_n.value = 0
    await Timer(20, unit="ns")
    dut.rst_n.value = 1
    await RisingEdge(dut.clk)

    # Verify FSM returned to IDLE
    await Timer(1, unit="ns")
    st = int(dut.state.value)
    if st == 0:  # ST_IDLE
        dut._log.info("  ✅  FSM correctly returned to IDLE after reset")
    else:
        dut._log.error(f"  ❌  FSM not in IDLE after reset, state = {st}")
        failures.append("FSM not IDLE after mid-operation reset")

    # Now run a clean encryption and verify correct result
    dut._log.info("  Running clean encryption after reset...")
    got = await encrypt(dut, PT, KEY)
    check(dut, "Encryption after mid-op reset", got, EXP, failures)

    assert not failures, f"{len(failures)} reset test(s) failed"
    dut._log.info("  Reset during operation tests passed ✅")


# =============================================================
#  Test 5 — done Pulse Width (exactly 1 cycle)
# =============================================================
@cocotb.test()
async def test_done_pulse_width(dut):
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    await reset_dut(dut)
    failures = []

    dut._log.info("=" * 60)
    dut._log.info("  TEST 5 — done Pulse Width")
    dut._log.info("=" * 60)

    PT  = 0x3243f6a8885a308d313198a2e0370734
    KEY = 0x2b7e151628aed2a6abf7158809cf4f3c

    dut.plaintext.value = PT
    dut.key.value       = KEY
    dut.start.value     = 1
    await RisingEdge(dut.clk)
    dut.start.value     = 0

    # Manually wait for done so we can sample on the exact cycle
    done_seen = False
    for _ in range(5000):
        await RisingEdge(dut.clk)
        await Timer(1, unit="ns")
        if int(dut.done.value) == 1:
            done_seen = True
            break

    assert done_seen, "TIMEOUT: done never asserted"
    dut._log.info("  ✅  done asserted on cycle N")
    dut._log.info(f"      ciphertext : {fmt(int(dut.ciphertext.value))}")

    # Now check next cycle — done must be deasserted
    await RisingEdge(dut.clk)
    await Timer(1, unit="ns")
    done_next = int(dut.done.value)

    if done_next == 0:
        dut._log.info("  ✅  done deasserted on cycle N+1 (pulse width = 1 cycle)")
    else:
        # Count how many extra cycles done stays high
        count = 1
        for _ in range(10):
            await RisingEdge(dut.clk)
            await Timer(1, unit="ns")
            if int(dut.done.value) == 0:
                break
            count += 1
        dut._log.error(f"  ❌  done stayed high for {count + 1} cycles")
        failures.append(f"done pulse width = {count + 1}, expected 1")

    assert not failures, "done pulse width test failed"
    dut._log.info("  done pulse width test passed ✅")

# =============================================================
#  Test 6 — Output Stability
#  ciphertext must hold its value until the next encryption
# =============================================================
@cocotb.test()
async def test_output_stability(dut):
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    await reset_dut(dut)
    failures = []

    dut._log.info("=" * 60)
    dut._log.info("  TEST 6 — Output Stability")
    dut._log.info("=" * 60)

    PT  = 0x3243f6a8885a308d313198a2e0370734
    KEY = 0x2b7e151628aed2a6abf7158809cf4f3c
    EXP = 0x3925841d02dc09fbdc118597196a0b32

    got = await encrypt(dut, PT, KEY)
    check(dut, "Initial ciphertext", got, EXP, failures)

    # Wait 20 cycles without starting new encryption
    for _ in range(20):
        await RisingEdge(dut.clk)

    await Timer(1, unit="ns")
    held = int(dut.ciphertext.value)
    if held == EXP:
        dut._log.info("  ✅  ciphertext stable for 20 idle cycles")
    else:
        dut._log.error(f"  ❌  ciphertext changed during idle")
        dut._log.error(f"       Was : {fmt(EXP)}")
        dut._log.error(f"       Now : {fmt(held)}")
        failures.append("ciphertext not stable during idle")

    assert not failures, "Output stability test failed"
    dut._log.info("  Output stability test passed ✅")


# =============================================================
#  Test 7 — Start Pulse Width Robustness
#  start held high for multiple cycles must not corrupt result
# =============================================================
@cocotb.test()
async def test_latency_breakdown(dut):

    CLOCK_PERIOD_NS = 4  # ← change this to any value (e.g. 5, 20, 100)

    cocotb.start_soon(Clock(dut.clk, CLOCK_PERIOD_NS, unit="ns").start())
    await reset_dut(dut)

    STATE_NAMES = {
        0:  "IDLE",       1:  "LOAD_WAIT",
        2:  "INIT_ARK",   3:  "KEY_UPD",
        4:  "KEY_WAIT",   5:  "SUB_ST",
        6:  "SUB_WAIT",   7:  "SB_LATCH",
        8:  "SHIFT",      9:  "MIX_ST",
        10: "MIX_WAIT",   11: "ADD_KEY",
        12: "DONE_ST",
    }

    PT  = 0x3243f6a8885a308d313198a2e0370734
    KEY = 0x2b7e151628aed2a6abf7158809cf4f3c
    EXP = 0x3925841d02dc09fbdc118597196a0b32

    dut.plaintext.value = PT
    dut.key.value       = KEY
    dut.start.value     = 1
    await RisingEdge(dut.clk)
    dut.start.value     = 0

    prev_state   = -1
    current_run  = 0
    total_cycles = 1
    log          = []

    for _ in range(10000):
        await RisingEdge(dut.clk)
        await Timer(1, unit="ns")
        total_cycles += 1

        st = int(dut.state.value)
        rn = int(dut.round.value)

        if st != prev_state:
            if prev_state != -1:
                name = STATE_NAMES.get(prev_state, f"S{prev_state}")
                log.append((name, current_run, rn))
            current_run = 1
            prev_state  = st
        else:
            current_run += 1

        if int(dut.done.value) == 1:
            name = STATE_NAMES.get(st, f"S{st}")
            log.append((name, current_run, rn))
            break

    await Timer(1, unit="ns")
    got = int(dut.ciphertext.value)

    total_latency_ns  = total_cycles * CLOCK_PERIOD_NS
    throughput_mbps   = 128 / (total_latency_ns * 1e-9) / 1e6

    dut._log.info("=" * 60)
    dut._log.info("  Cycle Breakdown by State")
    dut._log.info("=" * 60)
    dut._log.info(f"  {'State':<14} {'Cycles':>6}  {'At Round':>8}")
    dut._log.info(f"  {'-'*14} {'-'*6}  {'-'*8}")
    for name, cyc, rn in log:
        dut._log.info(f"  {name:<14} {cyc:>6}  round={rn}")
    dut._log.info(f"  {'-'*14} {'-'*6}")
    dut._log.info(f"  {'TOTAL':<14} {total_cycles:>6}")
    dut._log.info("=" * 60)

    dut._log.info(f"  Plaintext  : {fmt(PT)}")
    dut._log.info(f"  Key        : {fmt(KEY)}")
    dut._log.info(f"  Ciphertext : {fmt(got)}")
    dut._log.info(f"  Expected   : {fmt(EXP)}")
    dut._log.info("")
    dut._log.info(f"  Clock period       : {CLOCK_PERIOD_NS} ns  "
                  f"({1000 / CLOCK_PERIOD_NS:.1f} MHz)")
    dut._log.info(f"  Total clock cycles : {total_cycles}")
    dut._log.info(f"  Total latency      : {total_latency_ns} ns  "
                  f"({total_latency_ns / 1000:.3f} us)")
    dut._log.info(f"  Throughput         : {throughput_mbps:.1f} Mbps  "
                  f"({throughput_mbps / 1000:.3f} Gbps)")

    assert got == EXP, f"Ciphertext mismatch — got {fmt(got)}"
    dut._log.info("  ✅  Latency breakdown test passed")