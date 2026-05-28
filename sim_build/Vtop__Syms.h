// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VTOP__SYMS_H_
#define VERILATED_VTOP__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vtop.h"

// INCLUDE MODULE CLASSES
#include "Vtop___024root.h"
#include "Vtop_sbox.h"

// DPI TYPES for DPI Export callbacks (Internal use)

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vtop__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vtop* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vtop___024root                 TOP;
    Vtop_sbox                      TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst0;
    Vtop_sbox                      TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst1;
    Vtop_sbox                      TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst2;
    Vtop_sbox                      TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst3;
    Vtop_sbox                      TOP__aes_cipher_top__DOT__sub_unit__DOT__my_sbox;

    // SCOPE NAMES
    VerilatedScope __Vscope_TOP;
    VerilatedScope __Vscope_aes_cipher_top;
    VerilatedScope __Vscope_aes_cipher_top__key_unit;
    VerilatedScope __Vscope_aes_cipher_top__key_unit__sbox_inst0;
    VerilatedScope __Vscope_aes_cipher_top__key_unit__sbox_inst1;
    VerilatedScope __Vscope_aes_cipher_top__key_unit__sbox_inst2;
    VerilatedScope __Vscope_aes_cipher_top__key_unit__sbox_inst3;
    VerilatedScope __Vscope_aes_cipher_top__mix_unit;
    VerilatedScope __Vscope_aes_cipher_top__shift_unit;
    VerilatedScope __Vscope_aes_cipher_top__sub_unit;
    VerilatedScope __Vscope_aes_cipher_top__sub_unit__my_sbox;

    // SCOPE HIERARCHY
    VerilatedHierarchy __Vhier;

    // CONSTRUCTORS
    Vtop__Syms(VerilatedContext* contextp, const char* namep, Vtop* modelp);
    ~Vtop__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
