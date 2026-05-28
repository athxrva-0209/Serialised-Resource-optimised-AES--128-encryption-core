// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop___024root.h"

extern const VlUnpacked<CData/*3:0*/, 2048> Vtop__ConstPool__TABLE_hf0f6d167_0;

VL_INLINE_OPT void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*7:0*/ __Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__0__Vfuncout;
    __Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__0__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__0__b;
    __Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__0__b = 0;
    CData/*7:0*/ __Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__1__Vfuncout;
    __Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__1__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__1__b;
    __Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__1__b = 0;
    CData/*7:0*/ __Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__2__Vfuncout;
    __Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__2__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__2__b;
    __Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__2__b = 0;
    CData/*7:0*/ __Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__3__Vfuncout;
    __Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__3__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__3__b;
    __Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__3__b = 0;
    SData/*10:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    vlSelfRef.aes_cipher_top__DOT__start = vlSelfRef.start;
    vlSelfRef.aes_cipher_top__DOT__plaintext[0U] = 
        vlSelfRef.plaintext[0U];
    vlSelfRef.aes_cipher_top__DOT__plaintext[1U] = 
        vlSelfRef.plaintext[1U];
    vlSelfRef.aes_cipher_top__DOT__plaintext[2U] = 
        vlSelfRef.plaintext[2U];
    vlSelfRef.aes_cipher_top__DOT__plaintext[3U] = 
        vlSelfRef.plaintext[3U];
    vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__reset 
        = (1U & (~ (IData)(vlSelfRef.rst_n)));
    vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__start 
        = vlSelfRef.aes_cipher_top__DOT__sub_start;
    vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__state_in[0U] 
        = vlSelfRef.aes_cipher_top__DOT__state_reg[0U];
    vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__state_in[1U] 
        = vlSelfRef.aes_cipher_top__DOT__state_reg[1U];
    vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__state_in[2U] 
        = vlSelfRef.aes_cipher_top__DOT__state_reg[2U];
    vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__state_in[3U] 
        = vlSelfRef.aes_cipher_top__DOT__state_reg[3U];
    vlSelfRef.aes_cipher_top__DOT__shift_unit__DOT__state_in[0U] 
        = vlSelfRef.aes_cipher_top__DOT__state_reg[0U];
    vlSelfRef.aes_cipher_top__DOT__shift_unit__DOT__state_in[1U] 
        = vlSelfRef.aes_cipher_top__DOT__state_reg[1U];
    vlSelfRef.aes_cipher_top__DOT__shift_unit__DOT__state_in[2U] 
        = vlSelfRef.aes_cipher_top__DOT__state_reg[2U];
    vlSelfRef.aes_cipher_top__DOT__shift_unit__DOT__state_in[3U] 
        = vlSelfRef.aes_cipher_top__DOT__state_reg[3U];
    vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__start 
        = vlSelfRef.aes_cipher_top__DOT__mix_start;
    vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__state_in[0U] 
        = vlSelfRef.aes_cipher_top__DOT__state_reg[0U];
    vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__state_in[1U] 
        = vlSelfRef.aes_cipher_top__DOT__state_reg[1U];
    vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__state_in[2U] 
        = vlSelfRef.aes_cipher_top__DOT__state_reg[2U];
    vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__state_in[3U] 
        = vlSelfRef.aes_cipher_top__DOT__state_reg[3U];
    vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__load_key 
        = vlSelfRef.aes_cipher_top__DOT__load_key;
    vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__update_key 
        = vlSelfRef.aes_cipher_top__DOT__key_update;
    vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__round_in 
        = vlSelfRef.aes_cipher_top__DOT__round;
    vlSelfRef.aes_cipher_top__DOT__round_key[0U] = 
        vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__round_key[0U];
    vlSelfRef.aes_cipher_top__DOT__round_key[1U] = 
        vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__round_key[1U];
    vlSelfRef.aes_cipher_top__DOT__round_key[2U] = 
        vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__round_key[2U];
    vlSelfRef.aes_cipher_top__DOT__round_key[3U] = 
        vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__round_key[3U];
    vlSelfRef.ciphertext[0U] = vlSelfRef.aes_cipher_top__DOT__ciphertext[0U];
    vlSelfRef.ciphertext[1U] = vlSelfRef.aes_cipher_top__DOT__ciphertext[1U];
    vlSelfRef.ciphertext[2U] = vlSelfRef.aes_cipher_top__DOT__ciphertext[2U];
    vlSelfRef.ciphertext[3U] = vlSelfRef.aes_cipher_top__DOT__ciphertext[3U];
    vlSelfRef.done = vlSelfRef.aes_cipher_top__DOT__done;
    vlSelfRef.aes_cipher_top__DOT__sub_out[0U] = vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__state_out[0U];
    vlSelfRef.aes_cipher_top__DOT__sub_out[1U] = vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__state_out[1U];
    vlSelfRef.aes_cipher_top__DOT__sub_out[2U] = vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__state_out[2U];
    vlSelfRef.aes_cipher_top__DOT__sub_out[3U] = vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__state_out[3U];
    vlSelfRef.aes_cipher_top__DOT__mix_out[0U] = vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__state_out[0U];
    vlSelfRef.aes_cipher_top__DOT__mix_out[1U] = vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__state_out[1U];
    vlSelfRef.aes_cipher_top__DOT__mix_out[2U] = vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__state_out[2U];
    vlSelfRef.aes_cipher_top__DOT__mix_out[3U] = vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__state_out[3U];
    vlSelfRef.aes_cipher_top__DOT__key[0U] = vlSelfRef.key[0U];
    vlSelfRef.aes_cipher_top__DOT__key[1U] = vlSelfRef.key[1U];
    vlSelfRef.aes_cipher_top__DOT__key[2U] = vlSelfRef.key[2U];
    vlSelfRef.aes_cipher_top__DOT__key[3U] = vlSelfRef.key[3U];
    vlSelfRef.aes_cipher_top__DOT__shift_unit__DOT__state_out[0U] 
        = (((0xff000000U & vlSelfRef.aes_cipher_top__DOT__state_reg[0U]) 
            | (0xff0000U & vlSelfRef.aes_cipher_top__DOT__state_reg[3U])) 
           | ((0xff00U & vlSelfRef.aes_cipher_top__DOT__state_reg[2U]) 
              | (0xffU & vlSelfRef.aes_cipher_top__DOT__state_reg[1U])));
    vlSelfRef.aes_cipher_top__DOT__shift_unit__DOT__state_out[1U] 
        = (((0xff000000U & vlSelfRef.aes_cipher_top__DOT__state_reg[1U]) 
            | (0xff0000U & vlSelfRef.aes_cipher_top__DOT__state_reg[0U])) 
           | ((0xff00U & vlSelfRef.aes_cipher_top__DOT__state_reg[3U]) 
              | (0xffU & vlSelfRef.aes_cipher_top__DOT__state_reg[2U])));
    vlSelfRef.aes_cipher_top__DOT__shift_unit__DOT__state_out[2U] 
        = (((0xff000000U & vlSelfRef.aes_cipher_top__DOT__state_reg[2U]) 
            | (0xff0000U & vlSelfRef.aes_cipher_top__DOT__state_reg[1U])) 
           | ((0xff00U & vlSelfRef.aes_cipher_top__DOT__state_reg[0U]) 
              | (0xffU & vlSelfRef.aes_cipher_top__DOT__state_reg[3U])));
    vlSelfRef.aes_cipher_top__DOT__shift_unit__DOT__state_out[3U] 
        = (((0xff000000U & vlSelfRef.aes_cipher_top__DOT__state_reg[3U]) 
            | (0xff0000U & vlSelfRef.aes_cipher_top__DOT__state_reg[2U])) 
           | ((0xff00U & vlSelfRef.aes_cipher_top__DOT__state_reg[1U]) 
              | (0xffU & vlSelfRef.aes_cipher_top__DOT__state_reg[0U])));
    vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__last_word 
        = vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__round_key[0U];
    vlSelfRef.aes_cipher_top__DOT__rst_n = vlSelfRef.rst_n;
    vlSelfRef.aes_cipher_top__DOT__clk = vlSelfRef.clk;
    vlSelfRef.aes_cipher_top__DOT__sub_done = vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__done;
    vlSelfRef.aes_cipher_top__DOT__mix_done = vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__done;
    vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__current_col 
        = ((2U & (IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__col_count))
            ? ((1U & (IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__col_count))
                ? vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__internal_state[0U]
                : vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__internal_state[1U])
            : ((1U & (IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__col_count))
                ? vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__internal_state[2U]
                : vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__internal_state[3U]));
    vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__key_in[0U] 
        = vlSelfRef.aes_cipher_top__DOT__key[0U];
    vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__key_in[1U] 
        = vlSelfRef.aes_cipher_top__DOT__key[1U];
    vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__key_in[2U] 
        = vlSelfRef.aes_cipher_top__DOT__key[2U];
    vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__key_in[3U] 
        = vlSelfRef.aes_cipher_top__DOT__key[3U];
    vlSelfRef.aes_cipher_top__DOT__shift_out[0U] = 
        vlSelfRef.aes_cipher_top__DOT__shift_unit__DOT__state_out[0U];
    vlSelfRef.aes_cipher_top__DOT__shift_out[1U] = 
        vlSelfRef.aes_cipher_top__DOT__shift_unit__DOT__state_out[1U];
    vlSelfRef.aes_cipher_top__DOT__shift_out[2U] = 
        vlSelfRef.aes_cipher_top__DOT__shift_unit__DOT__state_out[2U];
    vlSelfRef.aes_cipher_top__DOT__shift_out[3U] = 
        vlSelfRef.aes_cipher_top__DOT__shift_unit__DOT__state_out[3U];
    vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__rst_n 
        = vlSelfRef.aes_cipher_top__DOT__rst_n;
    vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__rst_n 
        = vlSelfRef.aes_cipher_top__DOT__rst_n;
    vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__clk 
        = vlSelfRef.aes_cipher_top__DOT__clk;
    vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__clk 
        = vlSelfRef.aes_cipher_top__DOT__clk;
    vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__clk 
        = vlSelfRef.aes_cipher_top__DOT__clk;
    __Vtableidx1 = ((((IData)(vlSelfRef.start) << 0xaU) 
                     | (((IData)(vlSelfRef.aes_cipher_top__DOT__sub_done) 
                         << 9U) | ((IData)(vlSelfRef.aes_cipher_top__DOT__mix_done) 
                                   << 8U))) | (((IData)(vlSelfRef.aes_cipher_top__DOT__round) 
                                                << 4U) 
                                               | (IData)(vlSelfRef.aes_cipher_top__DOT__state)));
    vlSelfRef.aes_cipher_top__DOT__next_state = Vtop__ConstPool__TABLE_hf0f6d167_0
        [__Vtableidx1];
    vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s0 
        = (vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__current_col 
           >> 0x18U);
    vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s1 
        = (0xffU & (vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__current_col 
                    >> 0x10U));
    vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s2 
        = (0xffU & (vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__current_col 
                    >> 8U));
    vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s3 
        = (0xffU & vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__current_col);
    __Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__0__b 
        = vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s0;
    __Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__0__Vfuncout 
        = (0xffU & ((0x80U & (IData)(__Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__0__b))
                     ? (0x1bU ^ VL_SHIFTL_III(8,8,32, (IData)(__Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__0__b), 1U))
                     : VL_SHIFTL_III(8,8,32, (IData)(__Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__0__b), 1U)));
    vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s0_x2 
        = __Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__0__Vfuncout;
    __Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__1__b 
        = vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s1;
    __Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__1__Vfuncout 
        = (0xffU & ((0x80U & (IData)(__Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__1__b))
                     ? (0x1bU ^ VL_SHIFTL_III(8,8,32, (IData)(__Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__1__b), 1U))
                     : VL_SHIFTL_III(8,8,32, (IData)(__Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__1__b), 1U)));
    vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s1_x2 
        = __Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__1__Vfuncout;
    __Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__2__b 
        = vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s2;
    __Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__2__Vfuncout 
        = (0xffU & ((0x80U & (IData)(__Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__2__b))
                     ? (0x1bU ^ VL_SHIFTL_III(8,8,32, (IData)(__Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__2__b), 1U))
                     : VL_SHIFTL_III(8,8,32, (IData)(__Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__2__b), 1U)));
    vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s2_x2 
        = __Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__2__Vfuncout;
    __Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__3__b 
        = vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s3;
    __Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__3__Vfuncout 
        = (0xffU & ((0x80U & (IData)(__Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__3__b))
                     ? (0x1bU ^ VL_SHIFTL_III(8,8,32, (IData)(__Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__3__b), 1U))
                     : VL_SHIFTL_III(8,8,32, (IData)(__Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__3__b), 1U)));
    vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s3_x2 
        = __Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__3__Vfuncout;
    vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s0_x3 
        = ((IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s0_x2) 
           ^ (IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s0));
    vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s1_x3 
        = ((IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s1_x2) 
           ^ (IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s1));
    vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s2_x3 
        = ((IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s2_x2) 
           ^ (IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s2));
    vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s3_x3 
        = ((IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s3_x2) 
           ^ (IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s3));
}

void Vtop___024root___eval_triggers__ico(Vtop___024root* vlSelf);
void Vtop___024root___eval_ico(Vtop___024root* vlSelf);

bool Vtop___024root___eval_phase__ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vtop___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelfRef.__VicoTriggered.any();
    if (__VicoExecute) {
        Vtop___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vtop___024root___eval_act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*7:0*/ __Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__0__Vfuncout;
    __Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__0__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__0__b;
    __Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__0__b = 0;
    CData/*7:0*/ __Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__1__Vfuncout;
    __Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__1__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__1__b;
    __Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__1__b = 0;
    CData/*7:0*/ __Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__2__Vfuncout;
    __Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__2__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__2__b;
    __Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__2__b = 0;
    CData/*7:0*/ __Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__3__Vfuncout;
    __Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__3__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__3__b;
    __Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__3__b = 0;
    SData/*10:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    VlWide<4>/*127:0*/ __Vdly__aes_cipher_top__DOT__state_reg;
    VL_ZERO_W(128, __Vdly__aes_cipher_top__DOT__state_reg);
    CData/*0:0*/ __Vdly__aes_cipher_top__DOT__mix_unit__DOT__busy;
    __Vdly__aes_cipher_top__DOT__mix_unit__DOT__busy = 0;
    CData/*1:0*/ __Vdly__aes_cipher_top__DOT__mix_unit__DOT__col_count;
    __Vdly__aes_cipher_top__DOT__mix_unit__DOT__col_count = 0;
    CData/*3:0*/ __Vdly__aes_cipher_top__DOT__sub_unit__DOT__counter;
    __Vdly__aes_cipher_top__DOT__sub_unit__DOT__counter = 0;
    CData/*0:0*/ __Vdly__aes_cipher_top__DOT__sub_unit__DOT__busy;
    __Vdly__aes_cipher_top__DOT__sub_unit__DOT__busy = 0;
    // Body
    __Vdly__aes_cipher_top__DOT__sub_unit__DOT__busy 
        = vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__busy;
    __Vdly__aes_cipher_top__DOT__sub_unit__DOT__counter 
        = vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__counter;
    __Vdly__aes_cipher_top__DOT__state_reg[0U] = vlSelfRef.aes_cipher_top__DOT__state_reg[0U];
    __Vdly__aes_cipher_top__DOT__state_reg[1U] = vlSelfRef.aes_cipher_top__DOT__state_reg[1U];
    __Vdly__aes_cipher_top__DOT__state_reg[2U] = vlSelfRef.aes_cipher_top__DOT__state_reg[2U];
    __Vdly__aes_cipher_top__DOT__state_reg[3U] = vlSelfRef.aes_cipher_top__DOT__state_reg[3U];
    __Vdly__aes_cipher_top__DOT__mix_unit__DOT__busy 
        = vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__busy;
    __Vdly__aes_cipher_top__DOT__mix_unit__DOT__col_count 
        = vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__col_count;
    if (vlSelfRef.rst_n) {
        vlSelfRef.aes_cipher_top__DOT__done = 0U;
        if (((IData)(vlSelfRef.aes_cipher_top__DOT__sub_start) 
             & (~ (IData)(vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__busy)))) {
            __Vdly__aes_cipher_top__DOT__sub_unit__DOT__counter = 0U;
            vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__done = 0U;
            __Vdly__aes_cipher_top__DOT__sub_unit__DOT__busy = 1U;
        } else if (vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__busy) {
            if ((8U & (IData)(vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__counter))) {
                if ((4U & (IData)(vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__counter))) {
                    vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__state_out[0U] 
                        = ((2U & (IData)(vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__counter))
                            ? ((1U & (IData)(vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__counter))
                                ? ((0xffffff00U & vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__state_out[0U]) 
                                   | (IData)(vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__sbox_out))
                                : ((0xffff00ffU & vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__state_out[0U]) 
                                   | ((IData)(vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__sbox_out) 
                                      << 8U))) : ((1U 
                                                   & (IData)(vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__counter))
                                                   ? 
                                                  ((0xff00ffffU 
                                                    & vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__state_out[0U]) 
                                                   | ((IData)(vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__sbox_out) 
                                                      << 0x10U))
                                                   : 
                                                  ((0xffffffU 
                                                    & vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__state_out[0U]) 
                                                   | ((IData)(vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__sbox_out) 
                                                      << 0x18U))));
                } else {
                    vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__state_out[1U] 
                        = ((2U & (IData)(vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__counter))
                            ? ((1U & (IData)(vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__counter))
                                ? ((0xffffff00U & vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__state_out[1U]) 
                                   | (IData)(vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__sbox_out))
                                : ((0xffff00ffU & vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__state_out[1U]) 
                                   | ((IData)(vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__sbox_out) 
                                      << 8U))) : ((1U 
                                                   & (IData)(vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__counter))
                                                   ? 
                                                  ((0xff00ffffU 
                                                    & vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__state_out[1U]) 
                                                   | ((IData)(vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__sbox_out) 
                                                      << 0x10U))
                                                   : 
                                                  ((0xffffffU 
                                                    & vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__state_out[1U]) 
                                                   | ((IData)(vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__sbox_out) 
                                                      << 0x18U))));
                }
            } else if ((4U & (IData)(vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__counter))) {
                vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__state_out[2U] 
                    = ((2U & (IData)(vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__counter))
                        ? ((1U & (IData)(vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__counter))
                            ? ((0xffffff00U & vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__state_out[2U]) 
                               | (IData)(vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__sbox_out))
                            : ((0xffff00ffU & vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__state_out[2U]) 
                               | ((IData)(vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__sbox_out) 
                                  << 8U))) : ((1U & (IData)(vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__counter))
                                               ? ((0xff00ffffU 
                                                   & vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__state_out[2U]) 
                                                  | ((IData)(vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__sbox_out) 
                                                     << 0x10U))
                                               : ((0xffffffU 
                                                   & vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__state_out[2U]) 
                                                  | ((IData)(vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__sbox_out) 
                                                     << 0x18U))));
            } else {
                vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__state_out[3U] 
                    = ((2U & (IData)(vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__counter))
                        ? ((1U & (IData)(vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__counter))
                            ? ((0xffffff00U & vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__state_out[3U]) 
                               | (IData)(vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__sbox_out))
                            : ((0xffff00ffU & vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__state_out[3U]) 
                               | ((IData)(vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__sbox_out) 
                                  << 8U))) : ((1U & (IData)(vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__counter))
                                               ? ((0xff00ffffU 
                                                   & vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__state_out[3U]) 
                                                  | ((IData)(vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__sbox_out) 
                                                     << 0x10U))
                                               : ((0xffffffU 
                                                   & vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__state_out[3U]) 
                                                  | ((IData)(vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__sbox_out) 
                                                     << 0x18U))));
            }
            if ((0xfU == (IData)(vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__counter))) {
                vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__done = 1U;
                __Vdly__aes_cipher_top__DOT__sub_unit__DOT__busy = 0U;
            } else {
                __Vdly__aes_cipher_top__DOT__sub_unit__DOT__counter 
                    = (0xfU & ((IData)(1U) + (IData)(vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__counter)));
            }
        } else {
            vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__done = 0U;
        }
        if (((IData)(vlSelfRef.aes_cipher_top__DOT__mix_start) 
             & (~ (IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__busy)))) {
            vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__internal_state[0U] 
                = vlSelfRef.aes_cipher_top__DOT__state_reg[0U];
            vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__internal_state[1U] 
                = vlSelfRef.aes_cipher_top__DOT__state_reg[1U];
            vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__internal_state[2U] 
                = vlSelfRef.aes_cipher_top__DOT__state_reg[2U];
            vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__internal_state[3U] 
                = vlSelfRef.aes_cipher_top__DOT__state_reg[3U];
            __Vdly__aes_cipher_top__DOT__mix_unit__DOT__busy = 1U;
            __Vdly__aes_cipher_top__DOT__mix_unit__DOT__col_count = 0U;
            vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__done = 0U;
        } else if (vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__busy) {
            if ((2U & (IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__col_count))) {
                if ((1U & (IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__col_count))) {
                    vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__state_out[0U] 
                        = (((((((IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s0_x2) 
                                ^ (IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s1_x3)) 
                               ^ (IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s2)) 
                              ^ (IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s3)) 
                             << 0x18U) | (((((IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s0) 
                                             ^ (IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s1_x2)) 
                                            ^ (IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s2_x3)) 
                                           ^ (IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s3)) 
                                          << 0x10U)) 
                           | ((((((IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s0) 
                                  ^ (IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s1)) 
                                 ^ (IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s2_x2)) 
                                ^ (IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s3_x3)) 
                               << 8U) | ((((IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s0_x3) 
                                           ^ (IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s1)) 
                                          ^ (IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s2)) 
                                         ^ (IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s3_x2))));
                } else {
                    vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__state_out[1U] 
                        = (((((((IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s0_x2) 
                                ^ (IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s1_x3)) 
                               ^ (IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s2)) 
                              ^ (IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s3)) 
                             << 0x18U) | (((((IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s0) 
                                             ^ (IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s1_x2)) 
                                            ^ (IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s2_x3)) 
                                           ^ (IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s3)) 
                                          << 0x10U)) 
                           | ((((((IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s0) 
                                  ^ (IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s1)) 
                                 ^ (IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s2_x2)) 
                                ^ (IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s3_x3)) 
                               << 8U) | ((((IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s0_x3) 
                                           ^ (IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s1)) 
                                          ^ (IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s2)) 
                                         ^ (IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s3_x2))));
                }
            } else if ((1U & (IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__col_count))) {
                vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__state_out[2U] 
                    = (((((((IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s0_x2) 
                            ^ (IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s1_x3)) 
                           ^ (IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s2)) 
                          ^ (IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s3)) 
                         << 0x18U) | (((((IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s0) 
                                         ^ (IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s1_x2)) 
                                        ^ (IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s2_x3)) 
                                       ^ (IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s3)) 
                                      << 0x10U)) | 
                       ((((((IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s0) 
                            ^ (IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s1)) 
                           ^ (IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s2_x2)) 
                          ^ (IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s3_x3)) 
                         << 8U) | ((((IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s0_x3) 
                                     ^ (IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s1)) 
                                    ^ (IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s2)) 
                                   ^ (IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s3_x2))));
            } else {
                vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__state_out[3U] 
                    = (((((((IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s0_x2) 
                            ^ (IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s1_x3)) 
                           ^ (IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s2)) 
                          ^ (IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s3)) 
                         << 0x18U) | (((((IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s0) 
                                         ^ (IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s1_x2)) 
                                        ^ (IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s2_x3)) 
                                       ^ (IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s3)) 
                                      << 0x10U)) | 
                       ((((((IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s0) 
                            ^ (IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s1)) 
                           ^ (IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s2_x2)) 
                          ^ (IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s3_x3)) 
                         << 8U) | ((((IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s0_x3) 
                                     ^ (IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s1)) 
                                    ^ (IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s2)) 
                                   ^ (IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s3_x2))));
            }
            if ((3U == (IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__col_count))) {
                __Vdly__aes_cipher_top__DOT__mix_unit__DOT__busy = 0U;
                vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__done = 1U;
            } else {
                __Vdly__aes_cipher_top__DOT__mix_unit__DOT__col_count 
                    = (3U & ((IData)(1U) + (IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__col_count)));
            }
        } else {
            vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__done = 0U;
        }
        if (vlSelfRef.aes_cipher_top__DOT__load_key) {
            vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__round_key[0U] 
                = vlSelfRef.key[0U];
            vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__round_key[1U] 
                = vlSelfRef.key[1U];
            vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__round_key[2U] 
                = vlSelfRef.key[2U];
            vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__round_key[3U] 
                = vlSelfRef.key[3U];
        } else if (vlSelfRef.aes_cipher_top__DOT__key_update) {
            vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__round_key[0U] 
                = vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__w3_next;
            vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__round_key[1U] 
                = vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__w2_next;
            vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__round_key[2U] 
                = (IData)((((QData)((IData)(vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__w0_next)) 
                            << 0x20U) | (QData)((IData)(vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__w1_next))));
            vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__round_key[3U] 
                = (IData)(((((QData)((IData)(vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__w0_next)) 
                             << 0x20U) | (QData)((IData)(vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__w1_next))) 
                           >> 0x20U));
        }
        vlSelfRef.aes_cipher_top__DOT__sub_start = 0U;
        vlSelfRef.aes_cipher_top__DOT__mix_start = 0U;
        if ((8U & (IData)(vlSelfRef.aes_cipher_top__DOT__state))) {
            if ((1U & (~ ((IData)(vlSelfRef.aes_cipher_top__DOT__state) 
                          >> 2U)))) {
                if ((2U & (IData)(vlSelfRef.aes_cipher_top__DOT__state))) {
                    if ((1U & (IData)(vlSelfRef.aes_cipher_top__DOT__state))) {
                        if ((0xaU > (IData)(vlSelfRef.aes_cipher_top__DOT__round))) {
                            vlSelfRef.aes_cipher_top__DOT__round 
                                = (0xfU & ((IData)(1U) 
                                           + (IData)(vlSelfRef.aes_cipher_top__DOT__round)));
                        }
                    }
                }
                if ((1U & (~ ((IData)(vlSelfRef.aes_cipher_top__DOT__state) 
                              >> 1U)))) {
                    if ((1U & (IData)(vlSelfRef.aes_cipher_top__DOT__state))) {
                        vlSelfRef.aes_cipher_top__DOT__mix_start = 1U;
                    }
                }
            }
            if ((4U & (IData)(vlSelfRef.aes_cipher_top__DOT__state))) {
                if ((1U & (~ ((IData)(vlSelfRef.aes_cipher_top__DOT__state) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlSelfRef.aes_cipher_top__DOT__state)))) {
                        vlSelfRef.aes_cipher_top__DOT__done = 1U;
                        vlSelfRef.aes_cipher_top__DOT__ciphertext[0U] 
                            = vlSelfRef.aes_cipher_top__DOT__state_reg[0U];
                        vlSelfRef.aes_cipher_top__DOT__ciphertext[1U] 
                            = vlSelfRef.aes_cipher_top__DOT__state_reg[1U];
                        vlSelfRef.aes_cipher_top__DOT__ciphertext[2U] 
                            = vlSelfRef.aes_cipher_top__DOT__state_reg[2U];
                        vlSelfRef.aes_cipher_top__DOT__ciphertext[3U] 
                            = vlSelfRef.aes_cipher_top__DOT__state_reg[3U];
                    }
                }
            } else if ((2U & (IData)(vlSelfRef.aes_cipher_top__DOT__state))) {
                if ((1U & (IData)(vlSelfRef.aes_cipher_top__DOT__state))) {
                    __Vdly__aes_cipher_top__DOT__state_reg[0U] 
                        = (vlSelfRef.aes_cipher_top__DOT__state_reg[0U] 
                           ^ vlSelfRef.aes_cipher_top__DOT__round_key[0U]);
                    __Vdly__aes_cipher_top__DOT__state_reg[1U] 
                        = (vlSelfRef.aes_cipher_top__DOT__state_reg[1U] 
                           ^ vlSelfRef.aes_cipher_top__DOT__round_key[1U]);
                    __Vdly__aes_cipher_top__DOT__state_reg[2U] 
                        = (vlSelfRef.aes_cipher_top__DOT__state_reg[2U] 
                           ^ vlSelfRef.aes_cipher_top__DOT__round_key[2U]);
                    __Vdly__aes_cipher_top__DOT__state_reg[3U] 
                        = (vlSelfRef.aes_cipher_top__DOT__state_reg[3U] 
                           ^ vlSelfRef.aes_cipher_top__DOT__round_key[3U]);
                } else if (vlSelfRef.aes_cipher_top__DOT__mix_done) {
                    __Vdly__aes_cipher_top__DOT__state_reg[0U] 
                        = vlSelfRef.aes_cipher_top__DOT__mix_out[0U];
                    __Vdly__aes_cipher_top__DOT__state_reg[1U] 
                        = vlSelfRef.aes_cipher_top__DOT__mix_out[1U];
                    __Vdly__aes_cipher_top__DOT__state_reg[2U] 
                        = vlSelfRef.aes_cipher_top__DOT__mix_out[2U];
                    __Vdly__aes_cipher_top__DOT__state_reg[3U] 
                        = vlSelfRef.aes_cipher_top__DOT__mix_out[3U];
                }
            } else if ((1U & (~ (IData)(vlSelfRef.aes_cipher_top__DOT__state)))) {
                __Vdly__aes_cipher_top__DOT__state_reg[0U] 
                    = vlSelfRef.aes_cipher_top__DOT__shift_out[0U];
                __Vdly__aes_cipher_top__DOT__state_reg[1U] 
                    = vlSelfRef.aes_cipher_top__DOT__shift_out[1U];
                __Vdly__aes_cipher_top__DOT__state_reg[2U] 
                    = vlSelfRef.aes_cipher_top__DOT__shift_out[2U];
                __Vdly__aes_cipher_top__DOT__state_reg[3U] 
                    = vlSelfRef.aes_cipher_top__DOT__shift_out[3U];
            }
        } else {
            if ((1U & (~ ((IData)(vlSelfRef.aes_cipher_top__DOT__state) 
                          >> 2U)))) {
                if ((2U & (IData)(vlSelfRef.aes_cipher_top__DOT__state))) {
                    if ((1U & (~ (IData)(vlSelfRef.aes_cipher_top__DOT__state)))) {
                        vlSelfRef.aes_cipher_top__DOT__round = 1U;
                    }
                } else if ((1U & (~ (IData)(vlSelfRef.aes_cipher_top__DOT__state)))) {
                    if (vlSelfRef.start) {
                        vlSelfRef.aes_cipher_top__DOT__round = 0U;
                    }
                }
            }
            if ((4U & (IData)(vlSelfRef.aes_cipher_top__DOT__state))) {
                if ((2U & (IData)(vlSelfRef.aes_cipher_top__DOT__state))) {
                    if ((1U & (IData)(vlSelfRef.aes_cipher_top__DOT__state))) {
                        __Vdly__aes_cipher_top__DOT__state_reg[0U] 
                            = vlSelfRef.aes_cipher_top__DOT__sub_out[0U];
                        __Vdly__aes_cipher_top__DOT__state_reg[1U] 
                            = vlSelfRef.aes_cipher_top__DOT__sub_out[1U];
                        __Vdly__aes_cipher_top__DOT__state_reg[2U] 
                            = vlSelfRef.aes_cipher_top__DOT__sub_out[2U];
                        __Vdly__aes_cipher_top__DOT__state_reg[3U] 
                            = vlSelfRef.aes_cipher_top__DOT__sub_out[3U];
                    }
                }
            } else if ((2U & (IData)(vlSelfRef.aes_cipher_top__DOT__state))) {
                if ((1U & (~ (IData)(vlSelfRef.aes_cipher_top__DOT__state)))) {
                    __Vdly__aes_cipher_top__DOT__state_reg[0U] 
                        = (vlSelfRef.aes_cipher_top__DOT__state_reg[0U] 
                           ^ vlSelfRef.aes_cipher_top__DOT__round_key[0U]);
                    __Vdly__aes_cipher_top__DOT__state_reg[1U] 
                        = (vlSelfRef.aes_cipher_top__DOT__state_reg[1U] 
                           ^ vlSelfRef.aes_cipher_top__DOT__round_key[1U]);
                    __Vdly__aes_cipher_top__DOT__state_reg[2U] 
                        = (vlSelfRef.aes_cipher_top__DOT__state_reg[2U] 
                           ^ vlSelfRef.aes_cipher_top__DOT__round_key[2U]);
                    __Vdly__aes_cipher_top__DOT__state_reg[3U] 
                        = (vlSelfRef.aes_cipher_top__DOT__state_reg[3U] 
                           ^ vlSelfRef.aes_cipher_top__DOT__round_key[3U]);
                }
            } else if ((1U & (~ (IData)(vlSelfRef.aes_cipher_top__DOT__state)))) {
                if (vlSelfRef.start) {
                    __Vdly__aes_cipher_top__DOT__state_reg[0U] 
                        = vlSelfRef.plaintext[0U];
                    __Vdly__aes_cipher_top__DOT__state_reg[1U] 
                        = vlSelfRef.plaintext[1U];
                    __Vdly__aes_cipher_top__DOT__state_reg[2U] 
                        = vlSelfRef.plaintext[2U];
                    __Vdly__aes_cipher_top__DOT__state_reg[3U] 
                        = vlSelfRef.plaintext[3U];
                }
            }
        }
        vlSelfRef.aes_cipher_top__DOT__key_update = 0U;
        vlSelfRef.aes_cipher_top__DOT__load_key = 0U;
        if ((1U & (~ ((IData)(vlSelfRef.aes_cipher_top__DOT__state) 
                      >> 3U)))) {
            if ((4U & (IData)(vlSelfRef.aes_cipher_top__DOT__state))) {
                if ((1U & (~ ((IData)(vlSelfRef.aes_cipher_top__DOT__state) 
                              >> 1U)))) {
                    if ((1U & (IData)(vlSelfRef.aes_cipher_top__DOT__state))) {
                        vlSelfRef.aes_cipher_top__DOT__sub_start = 1U;
                    }
                }
            }
            if ((1U & (~ ((IData)(vlSelfRef.aes_cipher_top__DOT__state) 
                          >> 2U)))) {
                if ((2U & (IData)(vlSelfRef.aes_cipher_top__DOT__state))) {
                    if ((1U & (IData)(vlSelfRef.aes_cipher_top__DOT__state))) {
                        vlSelfRef.aes_cipher_top__DOT__key_update = 1U;
                    }
                }
                if ((1U & (~ ((IData)(vlSelfRef.aes_cipher_top__DOT__state) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlSelfRef.aes_cipher_top__DOT__state)))) {
                        if (vlSelfRef.start) {
                            vlSelfRef.aes_cipher_top__DOT__load_key = 1U;
                        }
                    }
                }
            }
        }
        vlSelfRef.aes_cipher_top__DOT__state = vlSelfRef.aes_cipher_top__DOT__next_state;
    } else {
        vlSelfRef.aes_cipher_top__DOT__round = 0U;
        vlSelfRef.aes_cipher_top__DOT__done = 0U;
        __Vdly__aes_cipher_top__DOT__state_reg[0U] = 0U;
        __Vdly__aes_cipher_top__DOT__state_reg[1U] = 0U;
        __Vdly__aes_cipher_top__DOT__state_reg[2U] = 0U;
        __Vdly__aes_cipher_top__DOT__state_reg[3U] = 0U;
        vlSelfRef.aes_cipher_top__DOT__ciphertext[0U] = 0U;
        vlSelfRef.aes_cipher_top__DOT__ciphertext[1U] = 0U;
        vlSelfRef.aes_cipher_top__DOT__ciphertext[2U] = 0U;
        vlSelfRef.aes_cipher_top__DOT__ciphertext[3U] = 0U;
        __Vdly__aes_cipher_top__DOT__sub_unit__DOT__counter = 0U;
        vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__state_out[0U] = 0U;
        vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__state_out[1U] = 0U;
        vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__state_out[2U] = 0U;
        vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__state_out[3U] = 0U;
        vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__done = 0U;
        __Vdly__aes_cipher_top__DOT__sub_unit__DOT__busy = 0U;
        __Vdly__aes_cipher_top__DOT__mix_unit__DOT__col_count = 0U;
        vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__state_out[0U] = 0U;
        vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__state_out[1U] = 0U;
        vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__state_out[2U] = 0U;
        vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__state_out[3U] = 0U;
        vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__done = 0U;
        __Vdly__aes_cipher_top__DOT__mix_unit__DOT__busy = 0U;
        vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__internal_state[0U] = 0U;
        vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__internal_state[1U] = 0U;
        vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__internal_state[2U] = 0U;
        vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__internal_state[3U] = 0U;
        vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__round_key[0U] = 0U;
        vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__round_key[1U] = 0U;
        vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__round_key[2U] = 0U;
        vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__round_key[3U] = 0U;
        vlSelfRef.aes_cipher_top__DOT__sub_start = 0U;
        vlSelfRef.aes_cipher_top__DOT__mix_start = 0U;
        vlSelfRef.aes_cipher_top__DOT__key_update = 0U;
        vlSelfRef.aes_cipher_top__DOT__load_key = 0U;
        vlSelfRef.aes_cipher_top__DOT__state = 0U;
    }
    vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__busy 
        = __Vdly__aes_cipher_top__DOT__sub_unit__DOT__busy;
    vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__counter 
        = __Vdly__aes_cipher_top__DOT__sub_unit__DOT__counter;
    vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__busy 
        = __Vdly__aes_cipher_top__DOT__mix_unit__DOT__busy;
    vlSelfRef.aes_cipher_top__DOT__state_reg[0U] = 
        __Vdly__aes_cipher_top__DOT__state_reg[0U];
    vlSelfRef.aes_cipher_top__DOT__state_reg[1U] = 
        __Vdly__aes_cipher_top__DOT__state_reg[1U];
    vlSelfRef.aes_cipher_top__DOT__state_reg[2U] = 
        __Vdly__aes_cipher_top__DOT__state_reg[2U];
    vlSelfRef.aes_cipher_top__DOT__state_reg[3U] = 
        __Vdly__aes_cipher_top__DOT__state_reg[3U];
    vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__col_count 
        = __Vdly__aes_cipher_top__DOT__mix_unit__DOT__col_count;
    vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__round_in 
        = vlSelfRef.aes_cipher_top__DOT__round;
    vlSelfRef.done = vlSelfRef.aes_cipher_top__DOT__done;
    vlSelfRef.ciphertext[0U] = vlSelfRef.aes_cipher_top__DOT__ciphertext[0U];
    vlSelfRef.ciphertext[1U] = vlSelfRef.aes_cipher_top__DOT__ciphertext[1U];
    vlSelfRef.ciphertext[2U] = vlSelfRef.aes_cipher_top__DOT__ciphertext[2U];
    vlSelfRef.ciphertext[3U] = vlSelfRef.aes_cipher_top__DOT__ciphertext[3U];
    vlSelfRef.aes_cipher_top__DOT__sub_out[0U] = vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__state_out[0U];
    vlSelfRef.aes_cipher_top__DOT__sub_out[1U] = vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__state_out[1U];
    vlSelfRef.aes_cipher_top__DOT__sub_out[2U] = vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__state_out[2U];
    vlSelfRef.aes_cipher_top__DOT__sub_out[3U] = vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__state_out[3U];
    vlSelfRef.aes_cipher_top__DOT__sub_done = vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__done;
    vlSelfRef.aes_cipher_top__DOT__mix_out[0U] = vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__state_out[0U];
    vlSelfRef.aes_cipher_top__DOT__mix_out[1U] = vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__state_out[1U];
    vlSelfRef.aes_cipher_top__DOT__mix_out[2U] = vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__state_out[2U];
    vlSelfRef.aes_cipher_top__DOT__mix_out[3U] = vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__state_out[3U];
    vlSelfRef.aes_cipher_top__DOT__mix_done = vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__done;
    vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__state_in[0U] 
        = vlSelfRef.aes_cipher_top__DOT__state_reg[0U];
    vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__state_in[1U] 
        = vlSelfRef.aes_cipher_top__DOT__state_reg[1U];
    vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__state_in[2U] 
        = vlSelfRef.aes_cipher_top__DOT__state_reg[2U];
    vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__state_in[3U] 
        = vlSelfRef.aes_cipher_top__DOT__state_reg[3U];
    vlSelfRef.aes_cipher_top__DOT__shift_unit__DOT__state_in[0U] 
        = vlSelfRef.aes_cipher_top__DOT__state_reg[0U];
    vlSelfRef.aes_cipher_top__DOT__shift_unit__DOT__state_in[1U] 
        = vlSelfRef.aes_cipher_top__DOT__state_reg[1U];
    vlSelfRef.aes_cipher_top__DOT__shift_unit__DOT__state_in[2U] 
        = vlSelfRef.aes_cipher_top__DOT__state_reg[2U];
    vlSelfRef.aes_cipher_top__DOT__shift_unit__DOT__state_in[3U] 
        = vlSelfRef.aes_cipher_top__DOT__state_reg[3U];
    vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__state_in[0U] 
        = vlSelfRef.aes_cipher_top__DOT__state_reg[0U];
    vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__state_in[1U] 
        = vlSelfRef.aes_cipher_top__DOT__state_reg[1U];
    vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__state_in[2U] 
        = vlSelfRef.aes_cipher_top__DOT__state_reg[2U];
    vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__state_in[3U] 
        = vlSelfRef.aes_cipher_top__DOT__state_reg[3U];
    vlSelfRef.aes_cipher_top__DOT__shift_unit__DOT__state_out[0U] 
        = (((0xff000000U & vlSelfRef.aes_cipher_top__DOT__state_reg[0U]) 
            | (0xff0000U & vlSelfRef.aes_cipher_top__DOT__state_reg[3U])) 
           | ((0xff00U & vlSelfRef.aes_cipher_top__DOT__state_reg[2U]) 
              | (0xffU & vlSelfRef.aes_cipher_top__DOT__state_reg[1U])));
    vlSelfRef.aes_cipher_top__DOT__shift_unit__DOT__state_out[1U] 
        = (((0xff000000U & vlSelfRef.aes_cipher_top__DOT__state_reg[1U]) 
            | (0xff0000U & vlSelfRef.aes_cipher_top__DOT__state_reg[0U])) 
           | ((0xff00U & vlSelfRef.aes_cipher_top__DOT__state_reg[3U]) 
              | (0xffU & vlSelfRef.aes_cipher_top__DOT__state_reg[2U])));
    vlSelfRef.aes_cipher_top__DOT__shift_unit__DOT__state_out[2U] 
        = (((0xff000000U & vlSelfRef.aes_cipher_top__DOT__state_reg[2U]) 
            | (0xff0000U & vlSelfRef.aes_cipher_top__DOT__state_reg[1U])) 
           | ((0xff00U & vlSelfRef.aes_cipher_top__DOT__state_reg[0U]) 
              | (0xffU & vlSelfRef.aes_cipher_top__DOT__state_reg[3U])));
    vlSelfRef.aes_cipher_top__DOT__shift_unit__DOT__state_out[3U] 
        = (((0xff000000U & vlSelfRef.aes_cipher_top__DOT__state_reg[3U]) 
            | (0xff0000U & vlSelfRef.aes_cipher_top__DOT__state_reg[2U])) 
           | ((0xff00U & vlSelfRef.aes_cipher_top__DOT__state_reg[1U]) 
              | (0xffU & vlSelfRef.aes_cipher_top__DOT__state_reg[0U])));
    vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__current_col 
        = ((2U & (IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__col_count))
            ? ((1U & (IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__col_count))
                ? vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__internal_state[0U]
                : vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__internal_state[1U])
            : ((1U & (IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__col_count))
                ? vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__internal_state[2U]
                : vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__internal_state[3U]));
    vlSelfRef.aes_cipher_top__DOT__round_key[0U] = 
        vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__round_key[0U];
    vlSelfRef.aes_cipher_top__DOT__round_key[1U] = 
        vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__round_key[1U];
    vlSelfRef.aes_cipher_top__DOT__round_key[2U] = 
        vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__round_key[2U];
    vlSelfRef.aes_cipher_top__DOT__round_key[3U] = 
        vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__round_key[3U];
    vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__last_word 
        = vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__round_key[0U];
    vlSelfRef.aes_cipher_top__DOT__shift_out[0U] = 
        vlSelfRef.aes_cipher_top__DOT__shift_unit__DOT__state_out[0U];
    vlSelfRef.aes_cipher_top__DOT__shift_out[1U] = 
        vlSelfRef.aes_cipher_top__DOT__shift_unit__DOT__state_out[1U];
    vlSelfRef.aes_cipher_top__DOT__shift_out[2U] = 
        vlSelfRef.aes_cipher_top__DOT__shift_unit__DOT__state_out[2U];
    vlSelfRef.aes_cipher_top__DOT__shift_out[3U] = 
        vlSelfRef.aes_cipher_top__DOT__shift_unit__DOT__state_out[3U];
    vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s0 
        = (vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__current_col 
           >> 0x18U);
    vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s1 
        = (0xffU & (vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__current_col 
                    >> 0x10U));
    vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s2 
        = (0xffU & (vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__current_col 
                    >> 8U));
    vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s3 
        = (0xffU & vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__current_col);
    vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__start 
        = vlSelfRef.aes_cipher_top__DOT__sub_start;
    __Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__0__b 
        = vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s0;
    __Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__0__Vfuncout 
        = (0xffU & ((0x80U & (IData)(__Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__0__b))
                     ? (0x1bU ^ VL_SHIFTL_III(8,8,32, (IData)(__Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__0__b), 1U))
                     : VL_SHIFTL_III(8,8,32, (IData)(__Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__0__b), 1U)));
    vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s0_x2 
        = __Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__0__Vfuncout;
    __Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__1__b 
        = vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s1;
    __Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__1__Vfuncout 
        = (0xffU & ((0x80U & (IData)(__Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__1__b))
                     ? (0x1bU ^ VL_SHIFTL_III(8,8,32, (IData)(__Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__1__b), 1U))
                     : VL_SHIFTL_III(8,8,32, (IData)(__Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__1__b), 1U)));
    vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s1_x2 
        = __Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__1__Vfuncout;
    __Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__2__b 
        = vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s2;
    __Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__2__Vfuncout 
        = (0xffU & ((0x80U & (IData)(__Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__2__b))
                     ? (0x1bU ^ VL_SHIFTL_III(8,8,32, (IData)(__Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__2__b), 1U))
                     : VL_SHIFTL_III(8,8,32, (IData)(__Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__2__b), 1U)));
    vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s2_x2 
        = __Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__2__Vfuncout;
    __Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__3__b 
        = vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s3;
    __Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__3__Vfuncout 
        = (0xffU & ((0x80U & (IData)(__Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__3__b))
                     ? (0x1bU ^ VL_SHIFTL_III(8,8,32, (IData)(__Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__3__b), 1U))
                     : VL_SHIFTL_III(8,8,32, (IData)(__Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__3__b), 1U)));
    vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s3_x2 
        = __Vfunc_aes_cipher_top__DOT__mix_unit__DOT__xtime__3__Vfuncout;
    vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__start 
        = vlSelfRef.aes_cipher_top__DOT__mix_start;
    vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__update_key 
        = vlSelfRef.aes_cipher_top__DOT__key_update;
    vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__load_key 
        = vlSelfRef.aes_cipher_top__DOT__load_key;
    vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s0_x3 
        = ((IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s0_x2) 
           ^ (IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s0));
    vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s1_x3 
        = ((IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s1_x2) 
           ^ (IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s1));
    vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s2_x3 
        = ((IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s2_x2) 
           ^ (IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s2));
    vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s3_x3 
        = ((IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s3_x2) 
           ^ (IData)(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s3));
    __Vtableidx1 = ((((IData)(vlSelfRef.start) << 0xaU) 
                     | (((IData)(vlSelfRef.aes_cipher_top__DOT__sub_done) 
                         << 9U) | ((IData)(vlSelfRef.aes_cipher_top__DOT__mix_done) 
                                   << 8U))) | (((IData)(vlSelfRef.aes_cipher_top__DOT__round) 
                                                << 4U) 
                                               | (IData)(vlSelfRef.aes_cipher_top__DOT__state)));
    vlSelfRef.aes_cipher_top__DOT__next_state = Vtop__ConstPool__TABLE_hf0f6d167_0
        [__Vtableidx1];
}

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf);

bool Vtop___024root___eval_phase__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtop___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vtop___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

void Vtop___024root___eval_nba(Vtop___024root* vlSelf);

bool Vtop___024root___eval_phase__nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtop___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY(((0x64U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("/home/athxrva/AESCoreStage2/aes_cipher_top.v", 304, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vtop___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelfRef.__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("/home/athxrva/AESCoreStage2/aes_cipher_top.v", 304, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("/home/athxrva/AESCoreStage2/aes_cipher_top.v", 304, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vtop___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vtop___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY(((vlSelfRef.rst_n & 0xfeU)))) {
        Verilated::overWidthError("rst_n");}
    if (VL_UNLIKELY(((vlSelfRef.start & 0xfeU)))) {
        Verilated::overWidthError("start");}
}
#endif  // VL_DEBUG
