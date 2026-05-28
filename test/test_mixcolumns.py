# import cocotb
# from cocotb.clock import Clock
# from cocotb.triggers import RisingEdge


# async def reset_dut(dut):
#     dut.rst_n.value = 0
#     dut.start.value = 0
#     dut.col_in.value = 0

#     # Hold reset for a few cycles
#     for _ in range(3):
#         await RisingEdge(dut.clk)

#     dut.rst_n.value = 1
#     await RisingEdge(dut.clk)


# async def run_transaction(dut, val_in, expected):
#     # Apply input
#     dut.col_in.value = val_in
#     dut.start.value = 1
#     await RisingEdge(dut.clk)

#     # Deassert start (1-cycle pulse)
#     dut.start.value = 0

#     # Wait for done (level-based, NOT edge-based)
#     while dut.done.value == 0:
#         await RisingEdge(dut.clk)

#     # Wait one extra cycle for safety (FSM settle)
#     await RisingEdge(dut.clk)

#     actual = dut.col_out.value.integer

#     dut._log.info(
#         f"Input: {hex(val_in)} | Expected: {hex(expected)} | Got: {hex(actual)}"
#     )

#     assert actual == expected, f"Mismatch! Got {hex(actual)}, expected {hex(expected)}"


# @cocotb.test()
# async def test_mix_columns(dut):

#     # Start clock
#     cocotb.start_soon(Clock(dut.clk, 10, units="ns").start())

#     # Reset DUT
#     await reset_dut(dut)

#     # AES standard test vectors (column-wise)
#     test_vectors = [
#         (0xd4bf5d30, 0x046681e5),
#         (0xe0b452ae, 0xe0cb199a),
#         (0xb84111f1, 0x48f8d37a),
#         (0x1e2798e5, 0x2806264c),
#     ]   

#     for val_in, expected in test_vectors:
#         await run_transaction(dut, val_in, expected)

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, Timer

# Helper to format 128-bit integers as clean hex strings for logging
def to_hex(val):
    return f"0x{int(val):032x}"

async def reset_dut(dut):
    dut.rst_n.value = 0
    dut.start.value = 0
    dut.state_in.value = 0
    # Hold reset for a few cycles
    for _ in range(5):
        await RisingEdge(dut.clk)
    dut.rst_n.value = 1
    await RisingEdge(dut.clk)

async def run_transaction(dut, val_in, expected):
    """Tests the full 128-bit MixColumns transformation"""
    dut._log.info("Starting 128-bit MixColumns Transaction...")
    
    # Apply 128-bit input
    dut.state_in.value = val_in
    dut.start.value = 1
    await RisingEdge(dut.clk)

    # Deassert start (1-cycle pulse)
    dut.start.value = 0

    # Wait for the internal FSM to iterate through all 4 columns
    # We set a timeout loop to prevent infinite hangs
    timeout = 0
    while int(dut.done.value) == 0:
        await RisingEdge(dut.clk)
        timeout += 1
        if timeout > 20: # Should take ~4-5 cycles
            raise Exception("Timeout: 'done' signal never asserted!")

    # Capture result
    actual = int(dut.state_out.value)

    dut._log.info(f"Full State Input:    {to_hex(val_in)}")
    dut._log.info(f"Expected Output:     {to_hex(expected)}")
    dut._log.info(f"Actual Output:       {to_hex(actual)}")

    assert actual == expected, f"Mismatch!\nGot:      {to_hex(actual)}\nExpected: {to_hex(expected)}"
    dut._log.info("✅ 128-bit Transformation Verified.")

@cocotb.test()
async def test_mix_columns_iterated(dut):
    """Testbench for the iterating 128-bit MixColumns design"""

    # Start 100MHz clock
    cocotb.start_soon(Clock(dut.clk, 10, units="ns").start())

    # Initial Reset
    await reset_dut(dut)

    # Combined test vector using your confirmed values
    # These are your 4 column pairs joined into 128-bit blocks
    input_state    = 0xd4bf5d30e0b452aeb84111f11e2798e5
    expected_state = 0x046681e5e0cb199a48f8d37a2806264c

    # Execute the test
    await run_transaction(dut, input_state, expected_state)
    
    # Optional: Add a second test vector if you have one to ensure 
    # the module can handle back-to-back starts.
    dut._log.info("Checking back-to-back capability...")
    await Timer(50, units="ns") 
    await run_transaction(dut, input_state, expected_state)
    
    dut._log.info("⭐⭐⭐ ALL MIXCOLUMNS TESTS PASSED ⭐⭐⭐")