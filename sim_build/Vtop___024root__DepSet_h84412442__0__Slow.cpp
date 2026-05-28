// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___eval_triggers__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered.setBit(0U, (IData)(vlSelfRef.__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__stl(vlSelf);
    }
#endif
}

void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf);
void Vtop_sbox___ico_sequent__TOP__aes_cipher_top__DOT__sub_unit__DOT__my_sbox__0(Vtop_sbox* vlSelf);
void Vtop_sbox___ico_sequent__TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst1__0(Vtop_sbox* vlSelf);
void Vtop_sbox___ico_sequent__TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst2__0(Vtop_sbox* vlSelf);
void Vtop_sbox___ico_sequent__TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst3__0(Vtop_sbox* vlSelf);
void Vtop_sbox___ico_sequent__TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst0__0(Vtop_sbox* vlSelf);
void Vtop___024root___ico_sequent__TOP__1(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
        Vtop_sbox___ico_sequent__TOP__aes_cipher_top__DOT__sub_unit__DOT__my_sbox__0((&vlSymsp->TOP__aes_cipher_top__DOT__sub_unit__DOT__my_sbox));
        Vtop_sbox___ico_sequent__TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst1__0((&vlSymsp->TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst1));
        Vtop_sbox___ico_sequent__TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst2__0((&vlSymsp->TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst2));
        Vtop_sbox___ico_sequent__TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst3__0((&vlSymsp->TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst3));
        Vtop_sbox___ico_sequent__TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst0__0((&vlSymsp->TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst0));
        Vtop___024root___ico_sequent__TOP__1(vlSelf);
    }
}
