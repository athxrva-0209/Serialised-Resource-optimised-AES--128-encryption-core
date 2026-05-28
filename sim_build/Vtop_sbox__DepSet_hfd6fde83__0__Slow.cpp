// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop_sbox.h"

VL_ATTR_COLD void Vtop_sbox___ctor_var_reset(Vtop_sbox* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_sbox___ctor_var_reset\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->a = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 510903276987443985ull);
    vlSelf->c = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15598372446745583797ull);
}
