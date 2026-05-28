// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP_SBOX_H_
#define VERILATED_VTOP_SBOX_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_sbox final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(a,7,0);
    VL_OUT8(c,7,0);

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop_sbox(Vtop__Syms* symsp, const char* v__name);
    ~Vtop_sbox();
    VL_UNCOPYABLE(Vtop_sbox);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
