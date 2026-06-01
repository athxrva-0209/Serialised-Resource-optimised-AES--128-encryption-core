# 🔐 AES-128 Encryption Core — Serialised / Resource-Optimised

![Language](https://img.shields.io/badge/Language-Verilog%2FHDL-blue?style=flat-square)
![Simulation](https://img.shields.io/badge/Simulation-Verilator-orange?style=flat-square)
![Testbench](https://img.shields.io/badge/Testbench-cocotb-green?style=flat-square&logo=python)
![Target](https://img.shields.io/badge/FPGA-Spartan--6%20XC6SLX9-purple?style=flat-square)
![Standard](https://img.shields.io/badge/Standard-AES--128%20FIPS%20197-red?style=flat-square)
![License](https://img.shields.io/badge/License-MIT-lightgrey?style=flat-square)

A hardware implementation of the **Advanced Encryption Standard (AES-128)** in Verilog HDL, targeting the **Xilinx Spartan-6 XC6SLX9** FPGA. The design prioritises **area efficiency over throughput** through a serialised architecture that reuses a single shared S-Box and iterative datapaths — making it well-suited for IoT devices, embedded security modules, and resource-constrained FPGA platforms.

Verification is done entirely in Python using **cocotb** with **Verilator** as the simulation backend.

---

## 📋 Table of Contents

- [Overview](#overview)
- [What Makes This Implementation Different](#-what-makes-this-implementation-different)
- [Architecture](#-architecture)
- [Tech Stack](#-tech-stack)
- [Project Structure](#-project-structure)
- [Getting Started](#-getting-started)
- [Running the Testbenches](#-running-the-testbenches)
- [Viewing Waveforms](#-viewing-waveforms)
- [Results](#-results)
- [References](#-references)

---

## Overview

This project implements the AES-128 block cipher at the RTL level. It accepts a 128-bit plaintext and a 128-bit key, and produces the 128-bit ciphertext after 10 encryption rounds, all controlled by a central FSM. The design is synthesised on the **Xilinx Spartan-6 XC6SLX9** using Xilinx ISE, and the generated ciphertext is displayed on the FPGA's onboard LCD.

> AES (FIPS 197) operates on a 4×4 matrix of bytes (the "state"), applying four transformations per round — `SubBytes`, `ShiftRows`, `MixColumns`, and `AddRoundKey` — for 10 rounds total.

---

## 🧠 What Makes This Implementation Different

Most open-source AES cores are either fully unrolled (fast but huge) or use naive iterative designs. This implementation takes a **serialised, resource-first** approach:

| Design Choice | Impact |
|---|---|
| **Single shared S-Box** for all 16 SubBytes operations | Eliminates 15 duplicate S-Box instances; runs 16 cycles instead of 1 |
| **Iterative MixColumns** — one column per cycle | Reduces combinational logic vs. fully parallel column processing |
| **On-the-fly key expansion** | No need to pre-store all 11 round keys simultaneously |
| **FSM-based control** reuses the same datapath for all 10 rounds | ~10× fewer logic cells vs. fully unrolled |
| **LUT-based S-Box** using a 256-entry combinational case statement | Simple, synthesis-friendly, meets timing at 111 MHz |

> 💡 The trade-off is deliberate: 307 clock cycles per encryption, in exchange for only **1,079 LUTs** — well within the Spartan-6 XC6SLX9's resource budget of 5,720 slice LUTs.

---

## 🏗️ Architecture

```
         ┌──────────────────────────────────────────────────────┐
         │                    AES Cipher Top                    │
  key ──►│                                                      │
         │  ┌─────────────┐    ┌───────────────────────────┐   │
plain ──►│  │    Key      │    │        Round Datapath     │   │►── ciphertext
  text   │  │  Expansion  │───►│  SubBytes  (1 sbox × 16)  │   │
         │  │  (on-the-   │    │  ShiftRows (wiring, 1 cy) │   │►── done
         │  │   fly)      │    │  MixColumns (1 col/cycle) │   │
         │  └─────────────┘    │  AddRoundKey  (128b XOR)  │   │
         │                     └───────────────────────────┘   │
         │            ▲ FSM — 307 cycles total / encryption     │
         └──────────────────────────────────────────────────────┘
                              │
                     ┌────────▼────────┐
                     │  aes_top_       │
                     │  spartan6.v     │──► LCD (ciphertext)
                     │  (FPGA top)     │──► LEDs (debug/done)
                     └─────────────────┘
```

The FSM cycles through states: `IDLE → INIT_ARK → KEY_UPD → SUB_ST → SHIFT → MIX_ST → ADD_KEY → DONE`. On round 10, `MixColumns` is skipped per the AES-128 specification.

---

## 🛠️ Tech Stack

| Tool / Technology | Role |
|---|---|
| **Verilog HDL** | RTL implementation of all AES modules |
| **Xilinx ISE 14.7** | Synthesis, place-and-route for Spartan-6 |
| **Spartan-6 XC6SLX9** | Target FPGA device |
| **Verilator** | Compiles Verilog to C++ simulation model |
| **cocotb** | Python-based testbench framework |
| **Python 3** | Test logic, NIST vector validation, assertions |
| **GTKWave** | VCD waveform viewer (`wave.vcd` generated automatically) |
| **Make** | Single-command simulation runs |

---

## 📁 Project Structure

```
aes-core/
├── addroundkey.v          # 128-bit XOR AddRoundKey module
├── aes_cipher_top.v       # Top-level AES core with FSM controller
├── aes_top_spartan6.v     # FPGA top module (clock, reset, LCD, LEDs)
├── aes_top.ucf            # Xilinx UCF pin constraints for Spartan-6
├── aes_uart_top.v         # UART wrapper top module (future use)
├── keyexpansion.v         # On-the-fly AES-128 key schedule
├── Makefile               # Verilator + cocotb simulation targets
├── mixcolumns.v           # Iterative MixColumns (1 column/cycle)
├── sbox.v                 # 256-entry combinational S-Box LUT
├── shiftrows.v            # Combinational ShiftRows byte permutation
├── subbytes.v             # Serialised SubBytes (1 sbox × 16 cycles)
├── uart_rx.v              # UART receiver module
├── uart_tx.v              # UART transmitter module
├── wave.vcd               # Simulation waveform output (auto-generated)
└── test/
    ├── test_aes_cypher_top.py         # AES cipher top-level test
    ├── test_aes_test_nist_vectors.py  # NIST FIPS-197 known-answer tests
    ├── test_aes_uart_top.py           # UART top-level test
    ├── test_complete_verification.py  # Full verification suite (7 tests)
    ├── test_keyexpansion.py           # Key expansion unit test
    ├── test_mixcolumns.py             # MixColumns unit test
    ├── test_sbox.py                   # S-Box unit test
    ├── test_shiftrows.py              # ShiftRows unit test
    ├── test_single_vector.py          # Single AES vector test
    └── test_subbytes.py               # SubBytes unit test
```

---

## 🚀 Getting Started

### Prerequisites

```bash
# Verilator (v5.x recommended)
sudo apt install verilator

# Python dependencies
pip install cocotb

# Optional: GTKWave for waveform viewing
sudo apt install gtkwave
```

Verify installations:

```bash
verilator --version
python -c "import cocotb; print(cocotb.__version__)"
```

### Clone the Repository

```bash
git clone https://github.com/yourusername/aes-core.git
cd aes-core
```

---

## 🧪 Running the Testbenches

All simulation is driven by the **`Makefile`** in the project root. Two variables control what gets simulated:

```makefile
TOPLEVEL = aes_cipher_top          # ← Change this: top module under test
MODULE   = test_complete_verification  # ← Change this: testbench to run
```

> **Line 14** sets `TOPLEVEL` — the DUT (Device Under Test).
> **Line 17** sets `MODULE` — the cocotb testbench file (without `.py`).

### Run the Full Verification Suite

```bash
make
```

This runs `test_complete_verification` against `aes_cipher_top` by default.

### Run a Specific Testbench

Edit the `MODULE` variable in the `Makefile` to any test file in `test/`, then run:

```bash
make
```

For example, to run only the NIST vector test:

```makefile
TOPLEVEL = aes_cipher_top
MODULE   = test_aes_test_nist_vectors
```

### Available Testbenches

| Module name | What it tests |
|---|---|
| `test_complete_verification` | Full suite: FIPS vectors, random, back-to-back, reset, timing |
| `test_aes_test_nist_vectors` | NIST FIPS-197 known-answer vectors |
| `test_aes_cypher_top` | AES top-level encrypt/decrypt |
| `test_single_vector` | Single AES-128 test vector |
| `test_keyexpansion` | Key schedule correctness |
| `test_subbytes` | SubBytes byte substitution |
| `test_sbox` | S-Box lookup correctness |
| `test_shiftrows` | ShiftRows permutation |
| `test_mixcolumns` | MixColumns GF(2⁸) arithmetic |
| `test_aes_uart_top` | UART wrapper integration |

### Expected Output

A passing run of `test_complete_verification` looks like:

```
************************************************************************************
** TEST                                        STATUS  SIM TIME (ns)  REAL TIME (s)
************************************************************************************
** test_complete_verification.test_fips_vectors         PASS   27741.00       0.03
** test_complete_verification.test_random_vectors       PASS   61621.00       0.10
** test_complete_verification.test_back_to_back         PASS   18501.00       0.02
** test_complete_verification.test_reset_during_operation PASS  3231.00       0.00
** test_complete_verification.test_done_pulse_width     PASS    3101.00       0.01
** test_complete_verification.test_output_stability     PASS    3301.00       0.00
** test_complete_verification.test_latency_breakdown    PASS    1250.00       0.01
************************************************************************************
** TESTS=7 PASS=7 FAIL=0 SKIP=0                       118746.01       0.19
************************************************************************************
```

---

## 📡 Viewing Waveforms

Verilator generates a `wave.vcd` file automatically (enabled via `EXTRA_ARGS += --trace` and `VERILATOR_TRACE = 1` in the Makefile). To open it:

```bash
gtkwave wave.vcd
```

---

## 📊 Results

### FPGA Synthesis — Spartan-6 XC6SLX9

Synthesised using **Xilinx ISE 14.7**. All metrics are from post-synthesis reports.

| Metric | Value |
|---|---|
| Target Device | Xilinx Spartan-6 XC6SLX9 |
| Slice LUTs used | 1,079 / 5,720 (18.9%) |
| Flip-Flops | 866 / 11,440 (7.6%) |
| Block RAMs | 0 |
| DSP Slices | 0 |
| Max Frequency (Fmax) | 111.21 MHz |
| Latency | 307 clock cycles / encryption |
| Throughput | ~165.52 Mbps |

### Architecture Trade-off Comparison

| Configuration | LUTs | FFs | Fmax (MHz) | Latency (cycles) | Throughput |
|---|---|---|---|---|---|
| **1-S-Box (this design)** | **1,119** | **866** | **111.21** | **307** | **~46 Mbps** |
| 4-S-Box | 2,143 | 1,024 | 112.08 | 85 | ~169 Mbps |
| 16-S-Box (fully parallel) | 3,812 | 1,280 | 115.40 | 21 | ~703 Mbps |

> The 1-S-Box design uses **~3.4× fewer LUTs** than fully parallel, at the cost of higher latency — an intentional trade-off for resource-constrained deployments.

---

## 🔗 References

1. NIST, *FIPS Publication 197: Advanced Encryption Standard*, 2001.
2. J. Daemen and V. Rijmen, *The Design of Rijndael: AES*, Springer, 2002.
3. P. Chodowiec and K. Gaj, "Very Compact FPGA Implementation of the AES Algorithm," *CHES 2003*.
4. G. Bertoni et al., "Efficient Implementation of SHA-3 and AES on Reconfigurable Hardware," *FPL 2003*.
5. G. Rouvroy et al., "Compact and Efficient Encryption/Decryption Module for FPGA Implementation of AES," *ITCC 2004*.
6. A. Satoh et al., "A Compact Rijndael Hardware Architecture with S-Box Optimization," *ASIACRYPT 2001*.
7. V. Fischer and M. Drutarovsky, "Two Methods of Rijndael Implementation in Reconfigurable Hardware," *CHES 2001*.
8. Xilinx Inc., *Spartan-6 Family Overview*, DS160, 2015.
9. Xilinx Inc., *ISE Design Suite 14.7 User Guide*, 2014.
10. I. Verbauwhede et al., "Design and Performance Testing of a 2.29-GB/s Rijndael Processor," *IEEE JSSC*, vol. 38, no. 3, 2003.

---

## 📄 License

This project is licensed under the MIT License. See [LICENSE](LICENSE) for details.
