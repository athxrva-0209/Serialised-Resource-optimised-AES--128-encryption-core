// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop_sbox.h"

extern const VlUnpacked<CData/*7:0*/, 256> Vtop__ConstPool__TABLE_h94daf570_0;

VL_INLINE_OPT void Vtop_sbox___ico_sequent__TOP__aes_cipher_top__DOT__sub_unit__DOT__my_sbox__0(Vtop_sbox* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_sbox___ico_sequent__TOP__aes_cipher_top__DOT__sub_unit__DOT__my_sbox__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*7:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    vlSelfRef.a = (0xffU & ((8U & (IData)(vlSymsp->TOP.aes_cipher_top__DOT__sub_unit__DOT__counter))
                             ? ((4U & (IData)(vlSymsp->TOP.aes_cipher_top__DOT__sub_unit__DOT__counter))
                                 ? ((2U & (IData)(vlSymsp->TOP.aes_cipher_top__DOT__sub_unit__DOT__counter))
                                     ? ((1U & (IData)(vlSymsp->TOP.aes_cipher_top__DOT__sub_unit__DOT__counter))
                                         ? vlSymsp->TOP.aes_cipher_top__DOT__state_reg[0U]
                                         : ((vlSymsp->TOP.aes_cipher_top__DOT__state_reg[0U] 
                                             << 0x18U) 
                                            | (vlSymsp->TOP.aes_cipher_top__DOT__state_reg[0U] 
                                               >> 8U)))
                                     : ((1U & (IData)(vlSymsp->TOP.aes_cipher_top__DOT__sub_unit__DOT__counter))
                                         ? ((vlSymsp->TOP.aes_cipher_top__DOT__state_reg[0U] 
                                             << 0x10U) 
                                            | (vlSymsp->TOP.aes_cipher_top__DOT__state_reg[0U] 
                                               >> 0x10U))
                                         : ((vlSymsp->TOP.aes_cipher_top__DOT__state_reg[0U] 
                                             << 8U) 
                                            | (vlSymsp->TOP.aes_cipher_top__DOT__state_reg[0U] 
                                               >> 0x18U))))
                                 : ((2U & (IData)(vlSymsp->TOP.aes_cipher_top__DOT__sub_unit__DOT__counter))
                                     ? ((1U & (IData)(vlSymsp->TOP.aes_cipher_top__DOT__sub_unit__DOT__counter))
                                         ? vlSymsp->TOP.aes_cipher_top__DOT__state_reg[1U]
                                         : ((vlSymsp->TOP.aes_cipher_top__DOT__state_reg[1U] 
                                             << 0x18U) 
                                            | (vlSymsp->TOP.aes_cipher_top__DOT__state_reg[1U] 
                                               >> 8U)))
                                     : ((1U & (IData)(vlSymsp->TOP.aes_cipher_top__DOT__sub_unit__DOT__counter))
                                         ? ((vlSymsp->TOP.aes_cipher_top__DOT__state_reg[1U] 
                                             << 0x10U) 
                                            | (vlSymsp->TOP.aes_cipher_top__DOT__state_reg[1U] 
                                               >> 0x10U))
                                         : ((vlSymsp->TOP.aes_cipher_top__DOT__state_reg[1U] 
                                             << 8U) 
                                            | (vlSymsp->TOP.aes_cipher_top__DOT__state_reg[1U] 
                                               >> 0x18U)))))
                             : ((4U & (IData)(vlSymsp->TOP.aes_cipher_top__DOT__sub_unit__DOT__counter))
                                 ? ((2U & (IData)(vlSymsp->TOP.aes_cipher_top__DOT__sub_unit__DOT__counter))
                                     ? ((1U & (IData)(vlSymsp->TOP.aes_cipher_top__DOT__sub_unit__DOT__counter))
                                         ? vlSymsp->TOP.aes_cipher_top__DOT__state_reg[2U]
                                         : ((vlSymsp->TOP.aes_cipher_top__DOT__state_reg[2U] 
                                             << 0x18U) 
                                            | (vlSymsp->TOP.aes_cipher_top__DOT__state_reg[2U] 
                                               >> 8U)))
                                     : ((1U & (IData)(vlSymsp->TOP.aes_cipher_top__DOT__sub_unit__DOT__counter))
                                         ? ((vlSymsp->TOP.aes_cipher_top__DOT__state_reg[2U] 
                                             << 0x10U) 
                                            | (vlSymsp->TOP.aes_cipher_top__DOT__state_reg[2U] 
                                               >> 0x10U))
                                         : ((vlSymsp->TOP.aes_cipher_top__DOT__state_reg[2U] 
                                             << 8U) 
                                            | (vlSymsp->TOP.aes_cipher_top__DOT__state_reg[2U] 
                                               >> 0x18U))))
                                 : ((2U & (IData)(vlSymsp->TOP.aes_cipher_top__DOT__sub_unit__DOT__counter))
                                     ? ((1U & (IData)(vlSymsp->TOP.aes_cipher_top__DOT__sub_unit__DOT__counter))
                                         ? vlSymsp->TOP.aes_cipher_top__DOT__state_reg[3U]
                                         : ((vlSymsp->TOP.aes_cipher_top__DOT__state_reg[3U] 
                                             << 0x18U) 
                                            | (vlSymsp->TOP.aes_cipher_top__DOT__state_reg[3U] 
                                               >> 8U)))
                                     : ((1U & (IData)(vlSymsp->TOP.aes_cipher_top__DOT__sub_unit__DOT__counter))
                                         ? ((vlSymsp->TOP.aes_cipher_top__DOT__state_reg[3U] 
                                             << 0x10U) 
                                            | (vlSymsp->TOP.aes_cipher_top__DOT__state_reg[3U] 
                                               >> 0x10U))
                                         : ((vlSymsp->TOP.aes_cipher_top__DOT__state_reg[3U] 
                                             << 8U) 
                                            | (vlSymsp->TOP.aes_cipher_top__DOT__state_reg[3U] 
                                               >> 0x18U)))))));
    __Vtableidx1 = vlSelfRef.a;
    vlSelfRef.c = Vtop__ConstPool__TABLE_h94daf570_0
        [__Vtableidx1];
}

VL_INLINE_OPT void Vtop_sbox___ico_sequent__TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst0__0(Vtop_sbox* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_sbox___ico_sequent__TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst0__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*7:0*/ __Vtableidx2;
    __Vtableidx2 = 0;
    // Body
    vlSelfRef.a = (0xffU & (vlSymsp->TOP.aes_cipher_top__DOT__key_unit__DOT__round_key[0U] 
                            >> 0x10U));
    __Vtableidx2 = vlSelfRef.a;
    vlSelfRef.c = Vtop__ConstPool__TABLE_h94daf570_0
        [__Vtableidx2];
}

VL_INLINE_OPT void Vtop_sbox___ico_sequent__TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst1__0(Vtop_sbox* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_sbox___ico_sequent__TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst1__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*7:0*/ __Vtableidx3;
    __Vtableidx3 = 0;
    // Body
    vlSelfRef.a = (0xffU & (vlSymsp->TOP.aes_cipher_top__DOT__key_unit__DOT__round_key[0U] 
                            >> 8U));
    __Vtableidx3 = vlSelfRef.a;
    vlSelfRef.c = Vtop__ConstPool__TABLE_h94daf570_0
        [__Vtableidx3];
}

VL_INLINE_OPT void Vtop_sbox___ico_sequent__TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst2__0(Vtop_sbox* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_sbox___ico_sequent__TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst2__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*7:0*/ __Vtableidx4;
    __Vtableidx4 = 0;
    // Body
    vlSelfRef.a = (0xffU & vlSymsp->TOP.aes_cipher_top__DOT__key_unit__DOT__round_key[0U]);
    __Vtableidx4 = vlSelfRef.a;
    vlSelfRef.c = Vtop__ConstPool__TABLE_h94daf570_0
        [__Vtableidx4];
}

VL_INLINE_OPT void Vtop_sbox___ico_sequent__TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst3__0(Vtop_sbox* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_sbox___ico_sequent__TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst3__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*7:0*/ __Vtableidx5;
    __Vtableidx5 = 0;
    // Body
    vlSelfRef.a = (vlSymsp->TOP.aes_cipher_top__DOT__key_unit__DOT__round_key[0U] 
                   >> 0x18U);
    __Vtableidx5 = vlSelfRef.a;
    vlSelfRef.c = Vtop__ConstPool__TABLE_h94daf570_0
        [__Vtableidx5];
}
