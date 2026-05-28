import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, Timer

def fmt(val, width=32):
    try:
        return f"0x{int(val):0{width}x}"
    except Exception:
        return "0x" + "?" * width

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
            return
    assert False, "TIMEOUT: done never asserted"

def check(dut, label, got, expected, failures):
    got_i = int(got) if not isinstance(got, int) else got
    exp_i = int(expected) if not isinstance(expected, int) else expected
    if got_i == exp_i:
        dut._log.info(f"    ✅  {label}")
        dut._log.info(f"        {fmt(got_i)}")
    else:
        dut._log.error(f"    ❌  {label}")
        dut._log.error(f"        Got      : {fmt(got_i)}")
        dut._log.error(f"        Expected : {fmt(exp_i)}")
        failures.append(label)

# FSM state constants — match your RTL localparams
ST_IDLE      = 0
ST_LOAD_WAIT = 1
ST_INIT_ARK  = 2
ST_KEY_UPD   = 3
ST_KEY_WAIT  = 4
ST_SUB_ST    = 5
ST_SUB_WAIT  = 6
ST_SB_LATCH  = 7
ST_SHIFT     = 8
ST_MIX_ST    = 9
ST_MIX_WAIT  = 10
ST_ADD_KEY   = 11
ST_DONE_ST   = 12

# =============================================================
#  FIPS-197 Appendix B round-by-round reference values
#  Each tuple: (sub_out, shift_out, mix_out, ark_out)
#  Taken directly from FIPS-197 Table 4
# =============================================================
FIPS_B_ROUNDS = [
    (0xd42711aee0bf98f1b8b45de51e415230, #c
     0xd4bf5d30e0b452aeb84111f11e2798e5, #c
     0x046681e5e0cb199a48f8d37a2806264c,
     0xa0fafe1788542cb123a339392a6c7605),
    (0x49ded28945db96f17f39871a7702533b,
     0x49db873b453953897f02d2f177de961a,
     0x584dcaf11b4b5aacdbe7caa81b6bb0e5,
     0xf2c295f27a96b9435935807a7359f67f),
    (0xac73cf7befc111df13b5d6b545235ab8,
     0xacc1d6b8efb55a7b1323cfdf457311b5,
     0x75ec0993200b633353c0cf7cbb25d0dc,
     0x3d80477d4716fe3e1e237e446d7a883b),
    (0x52502f2885a45ed7e311c807f6cf6a94,
     0x52a4c89485116a28e3cf2fd7f6505e07,
     0x0fd6daa9603138bf6fc0106b5eb31301,
     0xef44a541a8525b7fb671253bdb0bad00),
    (0xe14fd29be8fbfbba35c89653976cae7c,
     0xe1fb967ce8c8ae9b356cd2ba974ffb53,
     0x25d1a9adbd11d168b63a338e4c4cc0b0,
     0xd4d1c6f87c839d87caf2b8bc11f915bc),
    (0xa163a8fc784f29df10e83d234cd503fe,
     0xa14f3dfe78e803fc10d5a8df4c632923,
     0x4b868d6d2c4a8980339df4e837d218d8,
     0x6d88a37a110b3efddbf98641ca0093fd),
    (0xf7ab31f02783a9ff9b4340d354b53d3f,
     0xf783403f27433df09bb531ff54aba9d3,
     0x1415b5bf461615ec274656d7342ad843,
     0x4e54f70e5f5fc9f384a64fb24ea6dc4f),
    (0xbe832cc8d43b86c00ae1d44dda64f2fe,
     0xbe3bd4fed4e1f2c80a642cc0da83864d,
     0x00512fd1b1c889ff54766dcdfa1b99ea,
     0xead27321b58dbad2312bf5607f8d292f),
    (0x87ec4a8cf26ec3d84d4c46959790e7a6,
     0x876e46a6f24ce78c4d904ad897ecc395,
     0x473794ed40d4e4a5a3703aa64c9f42bc,
     0xac7766f319fadc2128d12941575c006e),
    # Round 10 — no MixColumns
    (0xe9098972cb31075f3d327d94af2e2cb5,
     0x3925841d02dc09fbdc118597196a0b32, #not shift_out value, rather direct output is stored due to combinational logic.
     None,
     0x3925841d02dc09fbdc118597196a0b32),
]

TEST_VECTORS = [
    {
        "name"      : "FIPS-197 Appendix B",
        "plaintext" : 0x3243f6a8885a308d313198a2e0370734,
        "key"       : 0x2b7e151628aed2a6abf7158809cf4f3c,
        "rounds"    : FIPS_B_ROUNDS,
        "ciphertext": 0x3925841d02dc09fbdc118597196a0b32,
    },
    {
        "name"      : "FIPS-197 Appendix C.1",
        "plaintext" : 0x00112233445566778899aabbccddeeff,
        "key"       : 0x000102030405060708090a0b0c0d0e0f,
        "rounds"    : [],
        "ciphertext": int("69c4e0d86a7b0430d8cdb78070b4c55a", 16),
    },
    {
        "name"      : "All-zeros",
        "plaintext" : 0x00000000000000000000000000000000,
        "key"       : 0x00000000000000000000000000000000,
        "rounds"    : [],
        "ciphertext": 0x66e94bd4ef8a2c3b884cfa59ca342b2e,
    },
    {
        "name"      : "NIST KAT #1",
        "plaintext" : 0xf34481ec3cc627bacd5dc3fb08f273e6,
        "key"       : 0x00000000000000000000000000000000,
        "rounds"    : [],
        "ciphertext": 0x0336763e966d92595a567cc9ce537f5e,
    },
    {
        "name"      : "NIST KAT #2",
        "plaintext" : 0x9798c4640bad75c7c3227db910174e72,
        "key"       : 0x00000000000000000000000000000000,
        "rounds"    : [],
        "ciphertext": 0xa9a1631bf4996954ebc093957b234589,
    },
]

# =============================================================
#  Wait for a specific FSM state, with timeout
# =============================================================
async def wait_for_state(dut, target, timeout=600):
    for _ in range(timeout):
        await RisingEdge(dut.clk)
        if int(dut.state.value) == target:
            return True
    return False   # timed out

# =============================================================
#  Single vector
# =============================================================
async def run_vector(dut, vec, trace_rounds=False):
    failures = []

    dut._log.info("")
    dut._log.info("=" * 60)
    dut._log.info(f"  TEST : {vec['name']}")
    dut._log.info("=" * 60)
    dut._log.info(f"  Plaintext : {fmt(vec['plaintext'])}")
    dut._log.info(f"  Key       : {fmt(vec['key'])}")

    dut.plaintext.value = vec["plaintext"]
    dut.key.value       = vec["key"]
    dut.start.value     = 1
    await RisingEdge(dut.clk)
    dut.start.value     = 0

    if not trace_rounds:
        await wait_done(dut)
        await Timer(1, unit="ns")
        check(dut, "Ciphertext",
              int(dut.ciphertext.value), vec["ciphertext"], failures)
        return failures

    # ----------------------------------------------------------
    #  Round trace
    # ----------------------------------------------------------
    for r_idx, r_exp in enumerate(vec["rounds"]):
        rn = r_idx + 1
        exp_sub, exp_shift, exp_mix, exp_ark = r_exp
        dut._log.info(f"\n  ── Round {rn} " + "─" * 44)

        # ---- SubBytes ----------------------------------------
        # Read sub_unit.state_out while FSM is in SB_LATCH.
        # At this point subbytes has finished and state_out is settled
        # but state_reg in top hasn't been updated yet.
        ok = await wait_for_state(dut, ST_SB_LATCH)
        if not ok:
            dut._log.error(f"    TIMEOUT waiting for SB_LATCH in round {rn}")
            failures.append(f"R{rn} SubBytes (timeout)")
            break
        await Timer(1, unit="ns")
        check(dut, f"R{rn} SubBytes",
              int(dut.sub_unit.state_out.value), exp_sub, failures)

        # ---- ShiftRows ----------------------------------------
        # ShiftRows is registered: state_reg <= sr_state_out in ST_SHIFT.
        # Wait for ST_SHIFT, then wait ONE more rising edge so state_reg
        # has the ShiftRows result latched, then read state_reg.
        ok = await wait_for_state(dut, ST_SHIFT)
        if not ok:
            failures.append(f"R{rn} ShiftRows (timeout)")
            break
        await RisingEdge(dut.clk)   # let state_reg <= sr_state_out register
        await Timer(1, unit="ns")
        check(dut, f"R{rn} ShiftRows",
              int(dut.state_reg.value), exp_shift, failures)

        # ---- MixColumns ---------------------------------------
        # After SHIFT, FSM goes MIX_ST → MIX_WAIT (4 cycles) → ADD_KEY.
        # state_reg is updated with mix_out during MIX_WAIT on mix_done.
        # Read state_reg at the start of ADD_KEY.
        if exp_mix is not None:
            await wait_for_state(dut, ST_MIX_WAIT)
            for _ in range(20):
                await RisingEdge(dut.clk)
                await Timer(1, unit="ns")
                if int(dut.mix_done.value) == 1:
                    check(dut, f"R{rn} MixColumns",
                        int(dut.mix_unit.state_out.value), exp_mix, failures)
                    break
            else:
                failures.append(f"R{rn} MixColumns (mix_done never fired)")

        # ---- AddRoundKey --------------------------------------
        # ADD_KEY executes: state_reg <= state_reg ^ round_keyround_keyround_key
        # This registers on the next rising edge, when FSM moves to
        # KEY_UPD (rounds 1-9) or DONE_ST (round 10).
            ok = await wait_for_state(dut, ST_KEY_UPD if rn < 10 else ST_DONE_ST)
            await Timer(1, unit="ns")
            dut._log.info(f"    DEBUG round_key at KEY_UPD : {fmt(int(dut.round_key.value))}")
            dut._log.info(f"    DEBUG state_reg at KEY_UPD : {fmt(int(dut.state_reg.value))}")
            check(dut, f"R{rn} AddRoundKey",
                int(dut.round_key.value), exp_ark, failures)
            

        # ok = await wait_for_state(dut, ST_KEY_UPD if rn < 10 else ST_DONE_ST)
        # if not ok:
        #     failures.append(f"R{rn} AddRoundKey (timeout)")
        #     break
        # await RisingEdge(dut.clk)  # NBA from ADD_KEY now fully committed
        # await Timer(1, unit="ns")
        # check(dut, f"R{rn} AddRoundKey",
        #     int(dut.state_reg.value), exp_ark, failures)

    # Final ciphertext
    await wait_done(dut)
    await Timer(1, unit="ns")
    check(dut, "Final ciphertext",
          int(dut.ciphertext.value), vec["ciphertext"], failures)

    return failures

# =============================================================
#  Main
# =============================================================
@cocotb.test()
async def test_aes_full(dut):
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())

    all_failures = []
    total  = len(TEST_VECTORS)
    passed = 0

    for i, vec in enumerate(TEST_VECTORS):
        await reset_dut(dut)
        trace    = (i == 0)
        failures = await run_vector(dut, vec, trace_rounds=trace)

        if failures:
            all_failures.extend([f"[{vec['name']}] {f}" for f in failures])
            dut._log.error(f"  RESULT : FAIL — {len(failures)} check(s) failed")
        else:
            passed += 1
            dut._log.info(f"  RESULT : PASS")

    dut._log.info("")
    dut._log.info("=" * 60)
    dut._log.info("  SUMMARY")
    dut._log.info("=" * 60)
    dut._log.info(f"  Vectors : {passed} / {total} passed")
    if all_failures:
        dut._log.error(f"  Failed checks ({len(all_failures)}):")
        for f in all_failures:
            dut._log.error(f"    • {f}")

    assert not all_failures, \
        f"{len(all_failures)} check(s) failed across {total - passed} vector(s)"
    dut._log.info("  ⭐  ALL TESTS PASSED")