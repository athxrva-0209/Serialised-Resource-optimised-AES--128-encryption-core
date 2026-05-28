import cocotb
from cocotb.triggers import Timer
import random

def reference_shiftrows(state_int):
    """
    Python implementation of AES ShiftRows.
    Maps a 128-bit integer into a 4x4 matrix (column-major),
    performs the shifts, and packs it back.
    """
    # Step 1: Extract 128-bit int into a list of 16 bytes
    # Index 0 is the least significant byte (LSB)
    in_bytes = [(state_int >> (i * 8)) & 0xFF for i in range(16)]
    
    out_bytes = [0] * 16

    # AES Mapping Logic:
    # Row 0: Bytes 0, 4, 8, 12  -> Shift 0
    out_bytes[0]  = in_bytes[0]
    out_bytes[4]  = in_bytes[4]
    out_bytes[8]  = in_bytes[8]
    out_bytes[12] = in_bytes[12]

    # Row 1: Bytes 1, 5, 9, 13  -> Shift Left 1
    # 1 moves to 13, 5 moves to 1, 9 moves to 5, 13 moves to 9
    out_bytes[13] = in_bytes[1]
    out_bytes[1]  = in_bytes[5]
    out_bytes[5]  = in_bytes[9]
    out_bytes[9]  = in_bytes[13]

    # Row 2: Bytes 2, 6, 10, 14 -> Shift Left 2
    # 2 moves to 10, 6 moves to 14, 10 moves to 2, 14 moves to 6
    out_bytes[10] = in_bytes[2]
    out_bytes[14] = in_bytes[6]
    out_bytes[2]  = in_bytes[10]
    out_bytes[6]  = in_bytes[14]

    # Row 3: Bytes 3, 7, 11, 15 -> Shift Left 3
    # 3 moves to 7, 7 moves to 11, 11 moves to 15, 15 moves to 3
    out_bytes[7]  = in_bytes[3]
    out_bytes[11] = in_bytes[7]
    out_bytes[15] = in_bytes[11]
    out_bytes[3]  = in_bytes[15]

    # Step 2: Reconstruct 128-bit integer
    res = 0
    for i in range(16):
        res |= (out_bytes[i] << (i * 8))
    return res

@cocotb.test()
async def test_shiftrows_logic(dut):
    """Verify that combinational ShiftRows correctly maps all 16 bytes"""

    dut._log.info("Starting AES ShiftRows Combinational Test...")

    # Test Case 1: Known pattern (00, 01, 02 ... 0F)
    # This makes it very easy to debug which byte went to the wrong wire.
    input_pattern = 0x0F0E0D0C0B0A09080706050403020100
    expected = reference_shiftrows(input_pattern)
    
    dut.state_in.value = input_pattern
    await Timer(1, units="ns") # Give simulator time to propagate
    
    actual = int(dut.state_out.value)
    
    if actual != expected:
        dut._log.error(f"Pattern Test Failed!")
        dut._log.error(f"Expected: {hex(expected)}")
        dut._log.error(f"Actual:   {hex(actual)}")
        assert actual == expected
    else:
        dut._log.info("Pattern Test Passed.")

    # Test Case 2: Randomized stress test
    dut._log.info("Running 50 random test vectors...")
    for i in range(50):
        rand_val = random.getrandbits(128)
        expected_rand = reference_shiftrows(rand_val)
        
        dut.state_in.value = rand_val
        await Timer(1, units="ns")
        
        actual_rand = int(dut.state_out.value)
        assert actual_rand == expected_rand, f"Random mismatch at iteration {i}"

    dut._log.info("All ShiftRows tests PASSED successfully!")