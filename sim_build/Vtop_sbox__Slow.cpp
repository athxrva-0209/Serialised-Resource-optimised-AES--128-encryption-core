// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop_sbox.h"

void Vtop_sbox___ctor_var_reset(Vtop_sbox* vlSelf);

Vtop_sbox::Vtop_sbox(Vtop__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtop_sbox___ctor_var_reset(this);
}

void Vtop_sbox::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtop_sbox::~Vtop_sbox() {
}
