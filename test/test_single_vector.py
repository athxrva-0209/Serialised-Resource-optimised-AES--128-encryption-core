import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, Timer


# ============================================================
# Helper Functions
# ============================================================

async def reset_dut(dut):
    dut.rst_n.value = 0
    dut.start.value = 0

    await Timer(20, unit="ns")

    dut.rst_n.value = 1
    await RisingEdge(dut.clk)


async def wait_done(dut, timeout=5000):
    for _ in range(timeout):
        await RisingEdge(dut.clk)

        if dut.done.value == 1:
            return

    assert False, "TIMEOUT: done never asserted"


# ============================================================
# Single AES Test
# ============================================================

@cocotb.test()
async def test_single_vector(dut):

    # Start clock
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())

    # Reset DUT
    await reset_dut(dut)

    # --------------------------------------------------------
    # Test Vector (FIPS-197)
    # --------------------------------------------------------

    plaintext  = 0x00112233445566778899aabbccddeeff
    key        = 0x000102030405060708090a0b0c0d0e0f
    expected   = 0x69c4e0d86a7b0430d8cdb78070b4c55a

    # --------------------------------------------------------
    # Apply Inputs
    # --------------------------------------------------------

    dut.plaintext.value = plaintext
    dut.key.value       = key

    dut.start.value = 1
    await RisingEdge(dut.clk)
    dut.start.value = 0

    # --------------------------------------------------------
    # Wait for encryption to finish
    # --------------------------------------------------------

    await wait_done(dut)

    # await Timer(1, unit="ns")
    await Timer(900, unit="ns")

    # --------------------------------------------------------
    # Check Output
    # --------------------------------------------------------

    result = int(dut.ciphertext.value)

    dut._log.info(f"Ciphertext = 0x{result:032x}")
    dut._log.info(f"Expected   = 0x{expected:032x}")

    assert result == expected, (
        f"Mismatch!\n"
        f"Got      : 0x{result:032x}\n"
        f"Expected : 0x{expected:032x}"
    )

    dut._log.info("✅ TEST PASSED")