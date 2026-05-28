# import cocotb
# from cocotb.clock import Clock
# from cocotb.triggers import RisingEdge, Timer

# # ---------------------------------------------------------
# # AES Reference (FIPS-197 Appendix B)
# # ---------------------------------------------------------
# ROUND1_IN     = 0x193de3bea0f4e22b9ac68d2ae9f84808
# ROUND1_SUB    = 0xd42711aee0bf98f1b8b45de51e415230
# ROUND1_SHIFT  = 0xd4e0b81e27bfb44111985d52aef1e530
# ROUND1_MIX    = 0x04e0482866cbf8068119d326e59a7a4c
# ROUND1_ADD    = 0xa0fafe1788542cb123a339392a6c7605
# EXPECTED_CT   = 0x3925841d02dc09fbdc118597196a0b32

# PLAINTEXT     = 0x3243f6a8885a308d313198a2e0370734
# KEY           = 0x2b7e151628aed2a6abf7158809cf4f3c

# # ---------------------------------------------------------
# # FSM state encoding — must match aes_top localparam
# # ---------------------------------------------------------
# ST_IDLE         = 0
# ST_LOAD_WAIT    = 1
# ST_INIT_ARK     = 2
# ST_KEY_UPDATE   = 3
# ST_KEY_WAIT     = 4
# ST_SUBBYTES     = 5
# ST_SB_LATCH     = 6   # new
# ST_SHIFTROWS    = 7   # was 6
# ST_MIXCOL_START = 8   # was 7
# ST_MIXCOL_WAIT  = 9   # was 8
# ST_MIXCOL_NEXT  = 10  # was 9
# ST_ARK_WAIT     = 11  # was 10
# ST_MIXCOL_ARK   = 12  # was 11
# ST_LAST_ARK     = 13  # was 12
# ST_DONE         = 14  # was 13

# STATE_NAMES = {
#     0:  "ST_IDLE",
#     1:  "ST_LOAD_WAIT",
#     2:  "ST_INIT_ARK",
#     3:  "ST_KEY_UPDATE",
#     4:  "ST_KEY_WAIT",
#     5:  "ST_SUBBYTES",
#     6:  "ST_SHIFTROWS",
#     7:  "ST_MIXCOL_START",
#     8:  "ST_MIXCOL_WAIT",
#     9:  "ST_MIXCOL_NEXT",
#     10: "ST_ARK_WAIT",
#     11: "ST_MIXCOL_ARK",
#     12: "ST_LAST_ARK",
#     13: "ST_DONE",
# }

# TIMEOUT_CYCLES = 2000   # fail fast if any stage hangs


# # ---------------------------------------------------------
# # Helpers
# # ---------------------------------------------------------
# async def reset_dut(dut):
#     dut.rst_n.value = 0
#     dut.start.value = 0
#     await Timer(20, unit="ns")
#     dut.rst_n.value = 1
#     await RisingEdge(dut.clk)


# def state_name(val):
#     return STATE_NAMES.get(int(val), f"UNKNOWN({val})")


# async def wait_for_state(dut, target_state, timeout=TIMEOUT_CYCLES):
#     """
#     Wait until FSM reaches target_state.
#     Logs every state transition so you can see exactly where it gets stuck.
#     Raises on timeout.
#     """
#     prev = -1
#     for cycle in range(timeout):
#         cur = int(dut.state.value)
#         if cur != prev:
#             dut._log.info(f"  [cycle {cycle:4d}] FSM → {state_name(cur)}")
#             prev = cur
#         if cur == target_state:
#             return cycle
#         await RisingEdge(dut.clk)

#     raise RuntimeError(
#         f"TIMEOUT after {timeout} cycles waiting for "
#         f"{STATE_NAMES.get(target_state, target_state)}. "
#         f"Last state: {state_name(dut.state.value)}"
#     )


# def check(dut, label, got, expected):
#     if got == expected:
#         dut._log.info(f"  ✅ {label} PASS : {hex(got)}")
#     else:
#         dut._log.error(f"  ❌ {label} MISMATCH")
#         dut._log.error(f"       Got      : {hex(got)}")
#         dut._log.error(f"       Expected : {hex(expected)}")

# @cocotb.test()
# async def test_sbox_direct(dut):
#     """
#     Probe sbox_in and sbox_out wires directly from the top module
#     for each of the 16 bytes being processed.
#     """
#     cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
#     await reset_dut(dut)

#     TEST_INPUT = 0x000102030405060708090a0b0c0d0e0f
#     SBOX_EXPECTED = [
#         0x63,0x7c,0x77,0x7b,0xf2,0x6b,0x6f,0xc5,
#         0x30,0x01,0x67,0x2b,0xfe,0xd7,0xab,0x76
#     ]

#     dut.plaintext.value = TEST_INPUT
#     dut.key.value       = 0x00000000000000000000000000000000
#     dut.start.value     = 1
#     await RisingEdge(dut.clk)
#     dut.start.value = 0

#     # Wait for FSM to enter ST_SUBBYTES
#     for _ in range(100):
#         await RisingEdge(dut.clk)
#         if int(dut.state.value) == 5:
#             break

#     dut._log.info(f"{'Cyc':>4} {'counter':>8} {'sbox_in':>9} {'sbox_out':>10} {'exp_out':>9} {'match':>6}")

#     for _ in range(20):
#         await Timer(1, unit="ns")  # sample after clock edge settles
#         st = int(dut.state.value)
#         if st != 5:  # left ST_SUBBYTES
#             break

#         cnt     = int(dut.u_subbytes.counter.value)
#         sb_in   = int(dut.u_subbytes.sbox_in.value)
#         sb_out  = int(dut.u_subbytes.sbox_out.value)
#         exp_in  = cnt  # since TEST_INPUT byte i = i
#         exp_out = SBOX_EXPECTED[cnt] if cnt < 16 else 0xff
#         match   = "✅" if sb_out == exp_out else "❌"

#         dut._log.info(
#             f"     {cnt:>8}   0x{sb_in:02x}      0x{sb_out:02x}    0x{exp_out:02x}    {match}"
#         )
#         await RisingEdge(dut.clk)

#     dut._log.info("Done probing sbox")

# @cocotb.test()
# async def test_sbox_sanity(dut):
#     """Quick sbox spot-check via subbytes single-byte verification"""
#     cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
#     await reset_dut(dut)

#     # Feed a state where all 16 bytes are the same known value: 0x19
#     # sbox(0x19) should = 0xd4 per FIPS-197
#     TEST_INPUT = 0x19191919191919191919191919191919
#     EXPECTED   = 0xd4d4d4d4d4d4d4d4d4d4d4d4d4d4d4d4

#     dut.plaintext.value = TEST_INPUT
#     dut.key.value       = 0x00000000000000000000000000000000
#     dut.start.value     = 1
#     await RisingEdge(dut.clk)
#     dut.start.value = 0

#     # Wait for ST_SHIFTROWS (subbytes done)
#     for _ in range(500):
#         await RisingEdge(dut.clk)
#         if int(dut.state.value) == 6:  # ST_SHIFTROWS
#             break

#     await Timer(1, unit="ns")
#     result = int(dut.state_reg.value)

#     if result == EXPECTED:
#         dut._log.info(f"✅ sbox(0x19) = 0xd4 across all 16 bytes PASS")
#     else:
#         dut._log.error(f"❌ sbox sanity FAIL")
#         dut._log.error(f"   Got      : {hex(result)}")
#         dut._log.error(f"   Expected : {hex(EXPECTED)}")

# @cocotb.test()
# async def test_subbytes_bytemapping(dut):
#     """
#     Each byte of state_in is unique (0x00..0x0F).
#     We know sbox(0x00)=0x63, sbox(0x01)=0x7c ... sbox(0x0F)=0x76
#     So we can see exactly which input byte maps to which output position.
#     """
#     cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
#     await reset_dut(dut)

#     # FIPS sbox values for 0x00..0x0F
#     SBOX = {
#         0x00:0x63, 0x01:0x7c, 0x02:0x77, 0x03:0x7b,
#         0x04:0xf2, 0x05:0x6b, 0x06:0x6f, 0x07:0xc5,
#         0x08:0x30, 0x09:0x01, 0x0a:0x67, 0x0b:0x2b,
#         0x0c:0xfe, 0x0d:0xd7, 0x0e:0xab, 0x0f:0x76
#     }

#     # state_in byte layout (MSB first):
#     # bits[127:120]=0x00, bits[119:112]=0x01, ..., bits[7:0]=0x0F
#     TEST_INPUT = 0x000102030405060708090a0b0c0d0e0f
#     EXPECTED   = 0x00
#     for i in range(16):
#         EXPECTED = (EXPECTED << 8) | SBOX[i]
#     EXPECTED &= (1 << 128) - 1

#     dut._log.info(f"Expected SubBytes output: {hex(EXPECTED)}")

#     dut.plaintext.value = TEST_INPUT
#     dut.key.value       = 0x00000000000000000000000000000000
#     dut.start.value     = 1
#     await RisingEdge(dut.clk)
#     dut.start.value = 0

#     for _ in range(500):
#         await RisingEdge(dut.clk)
#         if int(dut.state.value) == 6:  # ST_SHIFTROWS
#             break

#     await Timer(1, unit="ns")
#     result = int(dut.state_reg.value)

#     dut._log.info(f"Got SubBytes output     : {hex(result)}")
#     dut._log.info("")
#     dut._log.info("Byte-by-byte breakdown:")
#     dut._log.info(f"{'Pos':>4} {'In':>6} {'Got':>6} {'Exp':>6} {'Match':>6}")
#     for i in range(16):
#         shift  = (15 - i) * 8
#         inp    = (TEST_INPUT >> shift) & 0xff
#         got    = (result    >> shift) & 0xff
#         exp    = SBOX[inp]
#         mark   = "✅" if got == exp else "❌"
#         dut._log.info(f"  {i:>2}   0x{inp:02x}   0x{got:02x}   0x{exp:02x}    {mark}")
# # ---------------------------------------------------------
# # Main test
# # ---------------------------------------------------------
# @cocotb.test()
# async def test_aes_verbose(dut):

#     cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
#     await reset_dut(dut)

#     dut._log.info("=" * 60)
#     dut._log.info("  AES VERBOSE DIAGNOSTIC TEST")
#     dut._log.info("=" * 60)

#     # --------------------------------------------------
#     # Sanity-check: confirm clock and reset are toggling
#     # --------------------------------------------------
#     dut._log.info("\n[SANITY] Checking clock and reset ...")
#     await RisingEdge(dut.clk)
#     await Timer(1, unit="ns")
#     dut._log.info(f"  rst_n after release : {int(dut.rst_n.value)}")
#     dut._log.info(f"  FSM state at reset  : {state_name(dut.state.value)}")
#     assert int(dut.rst_n.value) == 1,  "rst_n did not de-assert — check reset wiring"
#     assert int(dut.state.value) == ST_IDLE, \
#         f"FSM not in ST_IDLE after reset — in {state_name(dut.state.value)}"
#     dut._log.info("  ✅ Clock and reset OK")

#     # --------------------------------------------------
#     # Apply inputs and pulse start
#     # --------------------------------------------------
#     dut._log.info("\n[START] Applying plaintext, key, start ...")
#     dut.plaintext.value = PLAINTEXT
#     dut.key.value       = KEY
#     dut.start.value     = 1
#     await RisingEdge(dut.clk)
#     dut.start.value     = 0
#     await Timer(1, unit="ns")
#     dut._log.info(f"  FSM after start pulse : {state_name(dut.state.value)}")
#     dut._log.info(f"  round_key             : {hex(int(dut.round_key.value))}")
#     dut._log.info(f"  state_reg             : {hex(int(dut.state_reg.value))}")

#     # --------------------------------------------------
#     # INIT ARK  (Round 0)
#     # --------------------------------------------------
#     dut._log.info("\n[INIT ARK] Waiting for ST_INIT_ARK ...")
#     await wait_for_state(dut, ST_INIT_ARK)
#     await Timer(1, unit="ns")
#     dut._log.info(f"  round_key : {hex(int(dut.round_key.value))}")
#     dut._log.info(f"  Expected  : {hex(KEY)}")
#     check(dut, "Round-0 key", int(dut.round_key.value), KEY)

#     # --------------------------------------------------
#     # SUBBYTES  — check input (should be plaintext XOR key)
#     # --------------------------------------------------
#     dut._log.info("\n[SUBBYTES] Waiting for ST_SUBBYTES ...")
#     await wait_for_state(dut, ST_SUBBYTES)
#     await Timer(1, unit="ns")

#     sub_in = int(dut.state_reg.value)
#     dut._log.info(f"  state_reg (SubBytes input) : {hex(sub_in)}")
#     check(dut, "SubBytes input", sub_in, ROUND1_IN)

#     # Wait for SubBytes to finish
#     dut._log.info("  Waiting for ST_SHIFTROWS (sb_done) ...")
#     await wait_for_state(dut, ST_SHIFTROWS)
#     await Timer(1, unit="ns")

#     sub_out = int(dut.state_reg.value)
#     dut._log.info(f"  state_reg (SubBytes output) : {hex(sub_out)}")
#     check(dut, "SubBytes output", sub_out, ROUND1_SUB)

#     # --------------------------------------------------
#     # SHIFTROWS  (combinational)
#     # --------------------------------------------------
#     dut._log.info("\n[SHIFTROWS] Reading combinational output ...")
#     await RisingEdge(dut.clk)
#     await Timer(1, unit="ns")

#     shift_out = int(dut.u_shiftrows.state_out.value)
#     dut._log.info(f"  ShiftRows output : {hex(shift_out)}")
#     check(dut, "ShiftRows output", shift_out, ROUND1_SHIFT)

#     # --------------------------------------------------
#     # MIXCOLUMNS  — count 4 mc_done pulses
#     # --------------------------------------------------
#     dut._log.info("\n[MIXCOLUMNS] Waiting for ST_MIXCOL_START ...")
#     await wait_for_state(dut, ST_MIXCOL_START)

#     mix_done_count = 0
#     for cycle in range(TIMEOUT_CYCLES):
#         await RisingEdge(dut.clk)
#         if int(dut.mc_done.value) == 1:
#             mix_done_count += 1
#             dut._log.info(f"  mc_done pulse {mix_done_count}/4 at {state_name(dut.state.value)}")
#         if mix_done_count == 4:
#             break
#     else:
#         raise RuntimeError("TIMEOUT: did not see 4 mc_done pulses")

#     await wait_for_state(dut, ST_MIXCOL_ARK)
#     await Timer(1, unit="ns")

#     mix_out = int(dut.state_reg.value)
#     dut._log.info(f"  MixColumns output : {hex(mix_out)}")
#     check(dut, "MixColumns output", mix_out, ROUND1_MIX)

#     # --------------------------------------------------
#     # ADDROUNDKEY  (Round 1)
#     # --------------------------------------------------
#     dut._log.info("\n[ADDROUNDKEY] Waiting one cycle for ARK to register ...")
#     await RisingEdge(dut.clk)
#     await Timer(1, unit="ns")

#     add_out = int(dut.state_reg.value)
#     dut._log.info(f"  round_key : {hex(int(dut.round_key.value))}")
#     dut._log.info(f"  ARK output : {hex(add_out)}")
#     check(dut, "AddRoundKey output", add_out, ROUND1_ADD)

#     # --------------------------------------------------
#     # FULL ENCRYPTION  — wait for done
#     # --------------------------------------------------
#     dut._log.info("\n[FULL AES] Waiting for done ...")
#     for cycle in range(5000):
#         await RisingEdge(dut.clk)
#         if int(dut.done.value) == 1:
#             dut._log.info(f"  done asserted at cycle {cycle}")
#             break
#     else:
#         raise RuntimeError("TIMEOUT: done never asserted")

#     await Timer(1, unit="ns")
#     final_ct = int(dut.ciphertext.value)
#     dut._log.info(f"  Ciphertext (RTL)   : {hex(final_ct)}")
#     dut._log.info(f"  Expected           : {hex(EXPECTED_CT)}")
#     check(dut, "Full AES ciphertext", final_ct, EXPECTED_CT)

#     dut._log.info("\n" + "=" * 60)
#     dut._log.info("  ROUND 1 TRACE COMPLETE")
#     dut._log.info("=" * 60)

#################################################################################################################################################

# import cocotb
# from cocotb.clock import Clock
# from cocotb.triggers import RisingEdge, Timer

# PLAINTEXT    = 0x3243f6a8885a308d313198a2e0370734
# KEY          = 0x2b7e151628aed2a6abf7158809cf4f3c
# ROUND1_IN    = 0x193de3bea0f4e22b9ac68d2ae9f84808
# ROUND1_SUB   = 0xd42711aee0bf98f1b8b45de51e415230
# ROUND1_SHIFT = 0xd4e0b81e27bfb44111985d52aef1e530

# ST_IDLE       = 0
# ST_LOAD_WAIT  = 1
# ST_INIT_ARK   = 2
# ST_KEY_UPDATE = 3
# ST_KEY_WAIT   = 4
# ST_SUBBYTES   = 5
# ST_SB_LATCH   = 6
# ST_SHIFTROWS  = 7
# ST_DONE       = 8


# async def reset_dut(dut):
#     dut.rst_n.value = 0
#     dut.start.value = 0
#     await Timer(20, unit="ns")
#     dut.rst_n.value = 1
#     await RisingEdge(dut.clk)


# def check(dut, label, got, expected):
#     if got == expected:
#         dut._log.info(f"✅ {label} PASS : {hex(got)}")
#     else:
#         dut._log.error(f"❌ {label} MISMATCH")
#         dut._log.error(f"   Got      : {hex(got)}")
#         dut._log.error(f"   Expected : {hex(expected)}")


# async def wait_for_state(dut, target, timeout=500):
#     for _ in range(timeout):
#         await RisingEdge(dut.clk)
#         if int(dut.state.value) == target:
#             return
#     raise RuntimeError(f"Timeout waiting for state {target}, "
#                        f"stuck at {int(dut.state.value)}")


# @cocotb.test()
# async def test_sub_shift(dut):
#     cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
#     await reset_dut(dut)

#     dut._log.info("===== SubBytes + ShiftRows Test =====")

#     dut.plaintext.value = PLAINTEXT
#     dut.key.value       = KEY
#     dut.start.value     = 1
#     await RisingEdge(dut.clk)
#     dut.start.value = 0

#     # Check SubBytes input
#     await wait_for_state(dut, ST_SUBBYTES)
#     await Timer(1, unit="ns")
#     check(dut, "SubBytes input", int(dut.state_reg.value), ROUND1_IN)

#     # Check SubBytes output (after SB_LATCH)
#     await wait_for_state(dut, ST_SHIFTROWS)
#     await Timer(1, unit="ns")
#     check(dut, "SubBytes output (in state_reg)", int(dut.state_reg.value), ROUND1_SUB)

#     # ShiftRows is combinational off state_reg — read sr_state_out directly
#     shift_out = int(dut.u_shiftrows.state_out.value)
#     check(dut, "ShiftRows output (combinational)", shift_out, ROUND1_SHIFT)

#     # Check final result at DONE — state_reg latched from sr_state_out
#     await wait_for_state(dut, ST_DONE)
#     await Timer(1, unit="ns")
#     check(dut, "ShiftRows output (latched)", int(dut.ciphertext.value), ROUND1_SHIFT)

#     dut._log.info("===== DONE =====")

# @cocotb.test()
# async def test_sb_output_timing(dut):
#     """
#     Watch sb_state_out every cycle after sb_done fires.
#     We want to see exactly when it stabilises to the correct value.
#     """
#     cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
#     await reset_dut(dut)

#     dut.plaintext.value = PLAINTEXT
#     dut.key.value       = KEY
#     dut.start.value     = 1
#     await RisingEdge(dut.clk)
#     dut.start.value = 0

#     # Wait for sb_done to go high
#     for _ in range(500):
#         await RisingEdge(dut.clk)
#         if int(dut.u_subbytes.done.value) == 1:
#             break

#     dut._log.info("sb_done just fired — sampling sb_state_out each cycle:")
#     dut._log.info(f"{'Cycle':>6}  {'sb_state_out':>34}  {'correct?':>8}")

#     for i in range(5):
#         await Timer(1, unit="ns")   # sample after edge settles
#         val = int(dut.u_subbytes.state_out.value)
#         ok  = "✅" if val == ROUND1_SUB else "❌"
#         dut._log.info(f"  +{i}     {hex(val):>34}  {ok}")
#         await RisingEdge(dut.clk)

# @cocotb.test()
# async def test_sb_start_probe(dut):
#     """Check sb_start never fires more than once"""
#     cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
#     await reset_dut(dut)

#     dut.plaintext.value = PLAINTEXT
#     dut.key.value       = KEY
#     dut.start.value     = 1
#     await RisingEdge(dut.clk)
#     dut.start.value = 0

#     sb_start_count = 0
#     sb_done_cycle  = -1

#     for cycle in range(500):
#         await RisingEdge(dut.clk)
#         await Timer(1, unit="ns")

#         if int(dut.sb_start.value) == 1:
#             sb_start_count += 1
#             dut._log.info(f"  sb_start pulse #{sb_start_count} at cycle {cycle}, "
#                           f"state={int(dut.state.value)}")

#         if int(dut.u_subbytes.done.value) == 1 and sb_done_cycle == -1:
#             sb_done_cycle = cycle
#             dut._log.info(f"  sb_done at cycle {cycle}")
#             dut._log.info(f"  sb_state_out = {hex(int(dut.u_subbytes.state_out.value))}")
#             dut._log.info(f"  state_reg    = {hex(int(dut.state_reg.value))}")

#         if int(dut.state.value) == ST_SB_LATCH:
#             dut._log.info(f"  ST_SB_LATCH at cycle {cycle}")
#             dut._log.info(f"  sb_state_out = {hex(int(dut.u_subbytes.state_out.value))}")

#         if int(dut.state.value) == ST_SHIFTROWS:
#             dut._log.info(f"  ST_SHIFTROWS at cycle {cycle}")
#             dut._log.info(f"  state_reg    = {hex(int(dut.state_reg.value))}")
#             dut._log.info(f"  Expected     = {hex(ROUND1_SUB)}")
#             break

#     dut._log.info(f"\n  Total sb_start pulses: {sb_start_count}")
#     if sb_start_count > 1:
#         dut._log.error("❌ sb_start fired more than once — subbytes restarted mid-run")
#     else:
#         dut._log.info("✅ sb_start fired exactly once")

############################################################################################################################################

# import cocotb
# from cocotb.clock import Clock
# from cocotb.triggers import RisingEdge, Timer

# INPUT  = 0x193de3bea0f4e22b9ac68d2ae9f84808
# SUBEXP = 0xd42711aee0bf98f1b8b45de51e415230
# SHFEXP = 0xd4e0b81e27bfb44111985d52aef1e530

# @cocotb.test()
# async def test_subbytes_only(dut):
#     cocotb.start_soon(Clock(dut.clk, 10, "ns").start())
    
#     # Reset
#     dut.rst_n.value = 0
#     await Timer(20, unit="ns")
#     dut.rst_n.value = 1
#     await RisingEdge(dut.clk)

#     # Start Input
#     dut.plaintext.value = 0x3243f6a8885a308d313198a2e0370734
#     dut.key.value       = 0x2b7e151628aed2a6abf7158809cf4f3c
#     dut.start.value = 1
#     await RisingEdge(dut.clk)
#     dut.start.value = 0

#     # 1. Verify Initial XOR (Round 0)
#     while int(dut.state.value) != 3: # SUB_START
#         await RisingEdge(dut.clk)
    
#     await Timer(1, unit="ns")
#     init_xor = int(dut.state_reg.value)
#     expected_xor = 0x193de3bea0f4e22b9ac68d2ae9f84808
    
#     dut._log.info(f"INIT XOR: {hex(init_xor)}")
#     assert init_xor == expected_xor, f"XOR Error! Got {hex(init_xor)}"

#     # 2. Verify SubBytes Output
#     # Wait for the sub_unit to signal completion
#     await RisingEdge(dut.sub_done)
#     await Timer(1, unit="ns") # Settle time
    
#     rtl_sub_out = int(dut.sub_out.value)
#     expected_sub = 0xd42711aee0bf98f1b8b45de51e415230
    
#     dut._log.info(f"SUBBYTES OUT: {hex(rtl_sub_out)}")
    
#     if rtl_sub_out == expected_sub:
#         dut._log.info("✅ SUBBYTES IS PERFECT")
#     else:
#         dut._log.error(f"❌ MISMATCH! Expected {hex(expected_sub)}")

#     # ... (After SubBytes verification)
    
#     # Wait for FSM to enter HOLD state (where state_reg has latched shift_out)
#     while int(dut.state.value) != 5: # HOLD
#         await RisingEdge(dut.clk)
    
#     await Timer(1, unit="ns")
#     rtl_shift_out = int(dut.state_reg.value)
#     expected_shift = 0xd4bf5d30e0b452aeb84111f11e2798e5
    
#     dut._log.info(f"SHIFTROWS OUT: {hex(rtl_shift_out)}")
    
#     if rtl_shift_out == expected_shift:
#         dut._log.info("✅ SHIFTROWS IS PERFECT")
#     else:
#         dut._log.error(f"❌ MISMATCH! Expected {hex(expected_shift)}")

#     while int(dut.state.value) != 7: # HOLD
#         await RisingEdge(dut.clk)
    
#     await Timer(1, unit="ns")
#     rtl_mix = int(dut.state_reg.value)
#     expected_mix = 0x046681e5e0cb199a48f8d37a2806264c
    
#     dut._log.info(f"MIXCOLUMNS OUT: {hex(rtl_mix)}")
#     if rtl_mix == expected_mix:
#         dut._log.info("✅ MIXCOLUMNS PASSED")
#     else:
#         dut._log.error(f"❌ MISMATCH! Expected {hex(expected_mix)}")

# import cocotb
# from cocotb.clock import Clock
# from cocotb.triggers import RisingEdge, Timer

# # Helper function to format 128-bit integers as clean hex strings
# def to_hex(val):
#     return f"0x{int(val):032x}"

# @cocotb.test()
# async def test_aes_full_encryption(dut):
#     # Setup Clock
#     cocotb.start_soon(Clock(dut.clk, 10, "ns").start())

#     # Reset
#     dut.rst_n.value = 0
#     await Timer(20, unit="ns")
#     dut.rst_n.value = 1
#     await RisingEdge(dut.clk)

#     # Input FIPS-197 Test Vector
#     # Plaintext: 32 43 f6 a8 88 5a 30 8d 31 31 98 a2 e0 37 07 34
#     # Key:       2b 7e 15 16 28 ae d2 a6 ab f7 15 88 09 cf 4f 3c
#     dut.plaintext.value = 0x3243f6a8885a308d313198a2e0370734
#     dut.key.value       = 0x2b7e151628aed2a6abf7158809cf4f3c
    
#     dut.start.value = 1
#     await RisingEdge(dut.clk)
#     dut.start.value = 0


#     # --- 1. Verify Round 0 (AddRoundKey) ---
#     while int(dut.state.value) != 3: # SUB_START
#         await RisingEdge(dut.clk)
    
#     expected_r0 = 0x193de3bea0f4e22b9ac68d2ae9f84808
#     actual_r0   = int(dut.state_reg.value)
    
#     dut._log.info(f"Round 0 Expected: {to_hex(expected_r0)}")
#     dut._log.info(f"Round 0 Actual:   {to_hex(actual_r0)}")
#     assert actual_r0 == expected_r0, "❌ Round 0 Mismatch!"
#     dut._log.info("✅ Round 0 Pass")

#     # --- 2. Verify Round 1 SubBytes ---
#     while int(dut.state.value) != 5: # SHIFT
#         await RisingEdge(dut.clk)
    
#     expected_sub = 0xd42711aee0bf98f1b8b45de51e415230
#     actual_sub   = int(dut.state_reg.value)
    
#     dut._log.info(f"SubBytes Expected: {to_hex(expected_sub)}")
#     dut._log.info(f"SubBytes Actual:   {to_hex(actual_sub)}")
#     assert actual_sub == expected_sub, "❌ SubBytes Mismatch!"
#     dut._log.info("✅ Round 1 SubBytes Pass")

#     # --- 3. Verify Round 1 ShiftRows ---
#     # FIPS Expected: d4 e0 b8 1e 27 bf b4 41 11 98 5d 52 ae f1 e5 30
#     expected_shift = 0xd4bf5d30e0b452aeb84111f11e2798e5
#     actual_shift   = int(dut.shift_out.value)
    
#     dut._log.info(f"ShiftRows Expected: {to_hex(expected_shift)}")
#     dut._log.info(f"ShiftRows Actual:   {to_hex(actual_shift)}")
#     assert actual_shift == expected_shift, "❌ ShiftRows Mismatch!"
#     dut._log.info("✅ Round 1 ShiftRows Pass")

#     # --- 4. Verify Round 1 MixColumns ---
#     while int(dut.state.value) != 8: # ADD_KEY
#         await RisingEdge(dut.clk)
    
#     # FIPS Expected: 04 e0 48 28 66 cb f8 06 81 19 d3 26 e5 9a 7a 4c
#     expected_mix = 0x046681e5e0cb199a48f8d37a2806264c
#     actual_mix   = int(dut.state_reg.value)
    
#     dut._log.info(f"MixColumns Expected: {to_hex(expected_mix)}")
#     dut._log.info(f"MixColumns Actual:   {to_hex(actual_mix)}")
#     assert actual_mix == expected_mix, "❌ MixColumns Mismatch!"
#     dut._log.info("✅ Round 1 MixColumns Pass")

#     # --- 5. Verify Final Ciphertext (Round 10) ---
#     while not int(dut.done.value):
#         await RisingEdge(dut.clk)

#     expected_cipher = 0x3925841d02dc09fbdc118597196a0b32
#     actual_cipher   = int(dut.ciphertext.value)
    
#     dut._log.info(f"Final Expected: {to_hex(expected_cipher)}")
#     dut._log.info(f"Final Actual:   {to_hex(actual_cipher)}")

    
#     assert actual_cipher == expected_cipher, "❌ Final Ciphertext Mismatch!"
#     dut._log.info("⭐⭐⭐ FULL AES-128 ENCRYPTION SUCCESS ⭐⭐⭐")

# import cocotb
# from cocotb.clock import Clock
# from cocotb.triggers import RisingEdge, Timer

# def to_hex(val):
#     try: return f"0x{int(val):032x}"
#     except: return "0x" + "x" * 32

# @cocotb.test()
# async def test_aes_live_output(dut):
#     """
#     Monitors the FSM and prints state_reg every time the operation shifts.
#     """

#     # 1. Setup
#     cocotb.start_soon(Clock(dut.clk, 10, units="ns").start())
#     dut.rst_n.value = 0
#     await Timer(20, units="ns")
#     dut.rst_n.value = 1
#     await RisingEdge(dut.clk)

#     # 2. Input Data (Standard FIPS-197)
#     dut.plaintext.value = 0x3243f6a8885a308d313198a2e0370734
#     dut.key.value       = 0x2b7e151628aed2a6abf7158809cf4f3c
    
#     dut._log.info("🔥 Starting AES Core - Live Output Log")
#     dut.start.value = 1
#     await RisingEdge(dut.clk)
#     dut.start.value = 0

#     # 3. State Mapping (Update these numbers to match your Verilog localparams)
#     # 0:IDLE, 1:SUB_ST, 2:SUB_WAIT, 3:SHIFT, 4:MIX_ST, 5:MIX_WAIT, 6:ADD_KEY, 7:DONE
#     STATE_MAP = {
#         0: "IDLE",
#         1: "SUB_START",
#         2: "SUB_WAITING",
#         3: "SHIFTROWS",
#         4: "MIX_START",
#         5: "MIX_WAITING",
#         6: "ADD_ROUND_KEY",
#         7: "DONE"
#     }

#     last_state = -1
    
#     # 4. Monitoring Loop
#     while not int(dut.done.value):
#         await RisingEdge(dut.clk)
        
#         curr_state = int(dut.state.value)
#         curr_round = int(dut.round.value)
#         curr_data  = to_hex(dut.state_reg.value)
        
#         # Only print when the state changes to keep the log clean
#         if curr_state != last_state:
#             state_name = STATE_MAP.get(curr_state, f"STATE_{curr_state}")
            
#             # Formatting the output based on the stage
#             if state_name == "SUB_WAITING":
#                 dut._log.info(f"--- Round {curr_round} Starting ---")
#                 dut._log.info(f"  [Input to Sub] : {curr_data}")
            
#             elif state_name == "SHIFTROWS":
#                 dut._log.info(f"  [After Sub]    : {curr_data}")
            
#             elif state_name == "MIX_WAITING":
#                 dut._log.info(f"  [After Shift]  : {curr_data}")
            
#             elif state_name == "ADD_ROUND_KEY":
#                 # For MixColumns output, we check if it was bypassed (Round 10)
#                 label = "After Mix" if curr_round < 10 else "Mix Bypassed"
#                 dut._log.info(f"  [{label:12}] : {curr_data}")
            
#             last_state = curr_state

#         # Special check for when ADD_ROUND_KEY finishes (after the XOR)
#         if last_state == 6: # ADD_ROUND_KEY
#             # Wait for the clock edge where the XOR is actually latched
#             await RisingEdge(dut.clk)
#             post_xor = to_hex(dut.state_reg.value)
#             dut._log.info(f"  [After XOR]    : {post_xor}")
#             dut._log.info(f"--- Round {curr_round} Complete ---")
#             last_state = -1 # Force a reprint for the next state

#     # 5. Final Output
#     dut._log.info("🏁 Encryption Finished.")
#     dut._log.info(f"FINAL CIPHERTEXT: {to_hex(dut.ciphertext.value)}")

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, Timer

# Helper to format 128-bit integers as clean hex strings
def to_hex(val):
    try:
        return f"0x{int(val):032x}"
    except:
        return "0x" + "x" * 32

@cocotb.test()
async def test_aes_full_trace(dut):
    """
    Final Diagnostic Testbench:
    - Logs every sub-stage (Sub, Shift, Mix, XOR)
    - Monitors Round Key updates
    - Compares Round 1 results against FIPS-197 Standard
    """

    # 1. Standard Reference Values (FIPS-197)
    # Plaintext: 3243f6a8885a308d313198a2e0370734 | Key: 2b7e151628aed2a6abf7158809cf4f3c
    FIPS_ROUND_1 = {
        "SubBytes":   "0xd42711aee0bf98f1b8b45de51e415230",
        "ShiftRows":  "0xd4bf5d30e0b452aeb84111f11e2798e5",
        "MixColumns": "0x046681e5e0cb199a48f8d37a2806264c",
        "RoundKey":   "0xa2e85f68a54e0903f0664c127fd2a48a",
        "Expected":   "0xa49c7ff2689f352b6b5be133a2744a28"
    }

    # 2. Clock and Reset Initialization
    cocotb.start_soon(Clock(dut.clk, 10, units="ns").start())
    dut.rst_n.value = 0
    dut.start.value = 0
    await Timer(20, units="ns")
    dut.rst_n.value = 1
    await RisingEdge(dut.clk)

    # 3. Apply Test Vectors
    dut.plaintext.value = 0x3243f6a8885a308d313198a2e0370734
    dut.key.value       = 0x2b7e151628aed2a6abf7158809cf4f3c
    
    dut._log.info("🚀 Starting AES Encryption Trace...")
    dut.start.value = 1
    await RisingEdge(dut.clk)
    dut.start.value = 0

    # 4. State Mapping (Update these numbers to match your Verilog localparams)
    # 0:IDLE, 1:SUB_ST, 2:SUB_WAIT, 3:SHIFT, 4:MIX_ST, 5:MIX_WAIT, 6:ADD_KEY, 7:DONE
    STATE_MAP = {
        0: "IDLE",
        1: "SUB_START",
        2: "SUB_WAITING",
        3: "SHIFTROWS",
        4: "MIX_START",
        5: "MIX_WAITING",
        6: "ADD_ROUND_KEY",
        7: "DONE"
    }

    last_state = -1
    timeout = 0
    
    # 5. Monitoring Loop
    while not int(dut.done.value):
        await RisingEdge(dut.clk)
        timeout += 1
        if timeout > 3000:
            raise Exception("Simulation Timeout: FSM is likely stuck.")

        curr_state = int(dut.state.value)
        curr_round = int(dut.round.value)
        curr_data  = to_hex(dut.state_reg.value)
        
        if curr_state != last_state:
            state_name = STATE_MAP.get(curr_state, f"STATE_{curr_state}")
            
            if state_name == "SUB_WAITING":
                dut._log.info(f"\n--- Round {curr_round} ---")
                dut._log.info(f"  [Input to Sub] : {curr_data}")
            
            elif state_name == "SHIFTROWS":
                dut._log.info(f"  [After Sub]    : {curr_data}")
                # Verification for Round 1
                if curr_round == 1 and curr_data != FIPS_ROUND_1["SubBytes"]:
                    dut._log.error(f"  ❌ ERROR: Expected SubBytes {FIPS_ROUND_1['SubBytes']}")

            elif state_name == "MIX_START":
                dut._log.info(f"  [After Shift]  : {curr_data}")
                if curr_round == 1 and curr_data != FIPS_ROUND_1["ShiftRows"]:
                    dut._log.error(f"  ❌ ERROR: Expected ShiftRows {FIPS_ROUND_1['ShiftRows']}")

            elif state_name == "ADD_ROUND_KEY":
                # Print the Round Key that is about to be XORed
                rk = to_hex(dut.round_key.value)
                dut._log.info(f"  [Round Key]    : {rk}")

                round_val = int(dut.round.value)
                key_in_module = to_hex(dut.key_unit.round_key.value)
                
                dut._log.info(f"DEBUG: FSM Round={round_val} | KeyUnit_Internal_Reg={key_in_module}")
                
                # Check MixCols result
                label = "After Mix" if curr_round < 10 else "Mix Bypassed"
                dut._log.info(f"  [{label:12}] : {curr_data}")
                
                if curr_round == 1 and label == "After Mix" and curr_data != FIPS_ROUND_1["MixColumns"]:
                    dut._log.error(f"  ❌ ERROR: Expected MixColumns {FIPS_ROUND_1['MixColumns']}")

            last_state = curr_state

        # Capture the result AFTER the XOR operation
        if last_state == 6: # ADD_ROUND_KEY
            await RisingEdge(dut.clk) # Wait for XOR to latch into register
            post_xor = to_hex(dut.state_reg.value)
            dut._log.info(f"  [After XOR]    : {post_xor}")
            
            if curr_round == 1 and post_xor != FIPS_ROUND_1["Expected"]:
                dut._log.error(f"  ❌ ERROR: Round 1 XOR Output is wrong!")
                dut._log.error(f"     Expected: {FIPS_ROUND_1['Expected']}")
            
            last_state = -1 # Reset so next state prints correctly

    # 6. Final Results
    final_actual = to_hex(dut.ciphertext.value)
    final_expected = "0x3925841d02dc09fbdc118597196a0b32"
    
    dut._log.info("\n" + "="*50)
    dut._log.info(f"🏁 FINAL ACTUAL:   {final_actual}")
    dut._log.info(f"🏁 FINAL EXPECTED: {final_expected}")
    dut._log.info("="*50)

    assert final_actual == final_expected, "Final Ciphertext Mismatch!"
    dut._log.info("⭐⭐⭐ AES ENCRYPTION SUCCESS ⭐⭐⭐")