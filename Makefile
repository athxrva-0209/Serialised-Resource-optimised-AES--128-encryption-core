TOPLEVEL_LANG = verilog

VERILOG_SOURCES = $(PWD)/sbox.v \
                  $(PWD)/subbytes.v \
                  $(PWD)/shiftrows.v \
                  $(PWD)/mixcolumns.v \
                  $(PWD)/keyexpansion.v \
                  $(PWD)/addroundkey.v \
                  $(PWD)/aes_cipher_top.v\
                  $(PWD)/uart_tx.v \
                  $(PWD)/uart_rx.v \
                  $(PWD)/aes_uart_top.v 

TOPLEVEL = aes_cipher_top

# Tell cocotb where tests are
export PYTHONPATH := $(PWD)/test
MODULE = test_complete_verification

SIM = verilator

EXTRA_ARGS += --trace

VERILATOR_TRACE = 1

include $(shell cocotb-config --makefiles)/Makefile.sim

# TOPLEVEL_LANG = verilog

# VERILOG_SOURCES = $(PWD)/sbox.v \
#                   $(PWD)/subbytes.v \
#                   $(PWD)/shiftrows.v \
#                   $(PWD)/mixcolumns.v \
#                   $(PWD)/keyexpansion.v \
#                   $(PWD)/addroundkey.v \
#                   $(PWD)/aes_cipher_top.v \
#                   $(PWD)/uart_tx.v \
#                   $(PWD)/uart_rx.v \
#                   $(PWD)/aes_uart_top.v

# TOPLEVEL = aes_uart_top

# export PYTHONPATH := $(PWD)/test
# MODULE = test_aes_uart_top

# SIM = verilator

# COMPILE_ARGS += -GCLKS_PER_BIT=4
# COMPILE_ARGS += -Wno-fatal

# EXTRA_ARGS += --trace
# EXTRA_ARGS += --timing

# include $(shell cocotb-config --makefiles)/Makefile.sim