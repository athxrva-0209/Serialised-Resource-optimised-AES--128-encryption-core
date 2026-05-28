// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval_triggers__ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered.setBit(0U, (IData)(vlSelfRef.__VicoFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__ico(vlSelf);
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

void Vtop___024root___eval_ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
        Vtop_sbox___ico_sequent__TOP__aes_cipher_top__DOT__sub_unit__DOT__my_sbox__0((&vlSymsp->TOP__aes_cipher_top__DOT__sub_unit__DOT__my_sbox));
        Vtop_sbox___ico_sequent__TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst1__0((&vlSymsp->TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst1));
        Vtop_sbox___ico_sequent__TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst2__0((&vlSymsp->TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst2));
        Vtop_sbox___ico_sequent__TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst3__0((&vlSymsp->TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst3));
        Vtop_sbox___ico_sequent__TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst0__0((&vlSymsp->TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst0));
        Vtop___024root___ico_sequent__TOP__1(vlSelf);
    }
}

VL_INLINE_OPT void Vtop___024root___ico_sequent__TOP__1(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__sbox_in 
        = vlSymsp->TOP__aes_cipher_top__DOT__sub_unit__DOT__my_sbox.a;
    vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__sbox_out 
        = vlSymsp->TOP__aes_cipher_top__DOT__sub_unit__DOT__my_sbox.c;
    vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__sub_out1 
        = vlSymsp->TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst1.c;
    vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__sub_out2 
        = vlSymsp->TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst2.c;
    vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__sub_out3 
        = vlSymsp->TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst3.c;
    vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__g_out 
        = ((0xff000000U & vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__g_out) 
           | (((IData)(vlSymsp->TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst1.c) 
               << 0x10U) | (((IData)(vlSymsp->TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst2.c) 
                             << 8U) | (IData)(vlSymsp->TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst3.c))));
    vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__sub_out0 
        = vlSymsp->TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst0.c;
    VL_ASSIGNSEL_II(32,8,0x18U, vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__g_out, 
                    ((IData)(vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__sub_out0) 
                     ^ ([&]() {
                    vlSelfRef.__Vfunc_aes_cipher_top__DOT__key_unit__DOT__get_rcon__4__r 
                        = vlSelfRef.aes_cipher_top__DOT__round;
                    vlSelfRef.__Vfunc_aes_cipher_top__DOT__key_unit__DOT__get_rcon__4__Vfuncout 
                        = ((8U & (IData)(vlSelfRef.__Vfunc_aes_cipher_top__DOT__key_unit__DOT__get_rcon__4__r))
                            ? ((4U & (IData)(vlSelfRef.__Vfunc_aes_cipher_top__DOT__key_unit__DOT__get_rcon__4__r))
                                ? 0U : ((2U & (IData)(vlSelfRef.__Vfunc_aes_cipher_top__DOT__key_unit__DOT__get_rcon__4__r))
                                         ? ((1U & (IData)(vlSelfRef.__Vfunc_aes_cipher_top__DOT__key_unit__DOT__get_rcon__4__r))
                                             ? 0U : 0x36U)
                                         : ((1U & (IData)(vlSelfRef.__Vfunc_aes_cipher_top__DOT__key_unit__DOT__get_rcon__4__r))
                                             ? 0x1bU
                                             : 0x80U)))
                            : ((4U & (IData)(vlSelfRef.__Vfunc_aes_cipher_top__DOT__key_unit__DOT__get_rcon__4__r))
                                ? ((2U & (IData)(vlSelfRef.__Vfunc_aes_cipher_top__DOT__key_unit__DOT__get_rcon__4__r))
                                    ? ((1U & (IData)(vlSelfRef.__Vfunc_aes_cipher_top__DOT__key_unit__DOT__get_rcon__4__r))
                                        ? 0x40U : 0x20U)
                                    : ((1U & (IData)(vlSelfRef.__Vfunc_aes_cipher_top__DOT__key_unit__DOT__get_rcon__4__r))
                                        ? 0x10U : 8U))
                                : ((2U & (IData)(vlSelfRef.__Vfunc_aes_cipher_top__DOT__key_unit__DOT__get_rcon__4__r))
                                    ? ((1U & (IData)(vlSelfRef.__Vfunc_aes_cipher_top__DOT__key_unit__DOT__get_rcon__4__r))
                                        ? 4U : 2U) : 
                                   ((1U & (IData)(vlSelfRef.__Vfunc_aes_cipher_top__DOT__key_unit__DOT__get_rcon__4__r))
                                     ? 1U : 0U))));
                }(), (IData)(vlSelfRef.__Vfunc_aes_cipher_top__DOT__key_unit__DOT__get_rcon__4__Vfuncout))));
    vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__w0_next 
        = (vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__round_key[3U] 
           ^ vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__g_out);
    vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__w1_next 
        = (vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__round_key[2U] 
           ^ vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__w0_next);
    vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__w2_next 
        = (vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__round_key[1U] 
           ^ vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__w1_next);
    vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__w3_next 
        = (vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__last_word 
           ^ vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__w2_next);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.setBit(0U, ((IData)(vlSelfRef.clk) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0))));
    vlSelfRef.__VactTriggered.setBit(1U, ((~ (IData)(vlSelfRef.rst_n)) 
                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rst_n__0)));
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst_n__0 = vlSelfRef.rst_n;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__act(vlSelf);
    }
#endif
}

void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf);

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
        Vtop_sbox___ico_sequent__TOP__aes_cipher_top__DOT__sub_unit__DOT__my_sbox__0((&vlSymsp->TOP__aes_cipher_top__DOT__sub_unit__DOT__my_sbox));
        Vtop_sbox___ico_sequent__TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst1__0((&vlSymsp->TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst1));
        Vtop_sbox___ico_sequent__TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst2__0((&vlSymsp->TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst2));
        Vtop_sbox___ico_sequent__TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst3__0((&vlSymsp->TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst3));
        Vtop_sbox___ico_sequent__TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst0__0((&vlSymsp->TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst0));
        Vtop___024root___ico_sequent__TOP__1(vlSelf);
    }
}
