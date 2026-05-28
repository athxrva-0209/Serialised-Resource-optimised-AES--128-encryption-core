import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, Timer

# AES-128 Key Expansion Golden Reference (FIPS-197 Appendix A.1)
ROUND_KEYS = [
    0x2b7e151628aed2a6abf7158809cf4f3c,
    0xa0fafe1788542cb123a339392a6c7605,
    0xf2c295f27a96b9435935807a7359f67f,
    0x3d80477d4716fe3e1e237e446d7a883b,
    0xef44a541a8525b7fb671253bdb0bad00,
    0xd4d1c6f87c839d87caf2b8bc11f915bc,
    0x6d88a37a110b3efddbf98641ca0093fd,
    0x4e54f70e5f5fc9f384a64fb24ea6dc4f,
    0xead27321b58dbad2312bf5607f8d292f,
    0xac7766f319fadc2128d12941575c006e,
    0xd014f9a8c9ee2589e13f0cc8b6630ca6
]


async def reset_dut(dut):
    """Apply reset"""
    dut.rst_n.value = 0
    dut.load_key.value = 0
    dut.update_key.value = 0
    dut.round_in.value = 0
    dut.key_in.value = 0

    await Timer(20, units="ns")
    dut.rst_n.value = 1
    await RisingEdge(dut.clk)


@cocotb.test()
async def test_aes_key_expansion(dut):
    """Main AES key expansion test"""

    # Start clock
    cocotb.start_soon(Clock(dut.clk, 10, units="ns").start())

    # Reset
    await reset_dut(dut)

    dut._log.info("==== Starting AES Key Expansion Test ====")

    # -------------------------------
    # Load initial key (Round 0)
    # -------------------------------
    dut._log.info("Loading initial key...")

    dut.key_in.value = ROUND_KEYS[0]
    dut.load_key.value = 1

    await RisingEdge(dut.clk)

    dut.load_key.value = 0

    # Small settle
    await Timer(1, units="ns")

    got = int(dut.round_key.value)
    exp = ROUND_KEYS[0]

    assert got == exp, (
        f"\n❌ Round 0 FAILED\n"
        f"Expected: {hex(exp)}\n"
        f"Got     : {hex(got)}"
    )

    dut._log.info(f"✅ Round 0 PASS: {hex(got)}")

    # -------------------------------
    # Generate Round 1 → Round 10
    # -------------------------------
    for i in range(1, 11):
        dut._log.info(f"--- Testing Round {i} ---")

        # Apply inputs BEFORE clock edge
        dut.round_in.value = i
        dut.update_key.value = 1

        await RisingEdge(dut.clk)

        dut.update_key.value = 0

        # Wait for output settle
        await Timer(1, units="ns")

        got = int(dut.round_key.value)
        exp = ROUND_KEYS[i]

        if got != exp:
            dut._log.error(
                f"\n❌ Round {i} FAILED\n"
                f"Expected: {hex(exp)}\n"
                f"Got     : {hex(got)}"
            )
            assert False

        dut._log.info(f"✅ Round {i} PASS: {hex(got)}")

    dut._log.info("🎉 ALL ROUNDS PASSED 🎉")