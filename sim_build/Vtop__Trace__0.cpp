// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtop___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtop___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0_sub_0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    bufp->chgBit(oldp+0,(vlSelfRef.clk));
    bufp->chgBit(oldp+1,(vlSelfRef.rst_n));
    bufp->chgBit(oldp+2,(vlSelfRef.start));
    bufp->chgWData(oldp+3,(vlSelfRef.plaintext),128);
    bufp->chgWData(oldp+7,(vlSelfRef.key),128);
    bufp->chgWData(oldp+11,(vlSelfRef.ciphertext),128);
    bufp->chgBit(oldp+15,(vlSelfRef.done));
    bufp->chgBit(oldp+16,(vlSelfRef.aes_cipher_top__DOT__clk));
    bufp->chgBit(oldp+17,(vlSelfRef.aes_cipher_top__DOT__rst_n));
    bufp->chgBit(oldp+18,(vlSelfRef.aes_cipher_top__DOT__start));
    bufp->chgWData(oldp+19,(vlSelfRef.aes_cipher_top__DOT__plaintext),128);
    bufp->chgWData(oldp+23,(vlSelfRef.aes_cipher_top__DOT__key),128);
    bufp->chgWData(oldp+27,(vlSelfRef.aes_cipher_top__DOT__ciphertext),128);
    bufp->chgBit(oldp+31,(vlSelfRef.aes_cipher_top__DOT__done));
    bufp->chgCData(oldp+32,(vlSelfRef.aes_cipher_top__DOT__state),4);
    bufp->chgCData(oldp+33,(vlSelfRef.aes_cipher_top__DOT__next_state),4);
    bufp->chgCData(oldp+34,(vlSelfRef.aes_cipher_top__DOT__round),4);
    bufp->chgWData(oldp+35,(vlSelfRef.aes_cipher_top__DOT__state_reg),128);
    bufp->chgBit(oldp+39,(vlSelfRef.aes_cipher_top__DOT__sub_start));
    bufp->chgBit(oldp+40,(vlSelfRef.aes_cipher_top__DOT__mix_start));
    bufp->chgBit(oldp+41,(vlSelfRef.aes_cipher_top__DOT__load_key));
    bufp->chgBit(oldp+42,(vlSelfRef.aes_cipher_top__DOT__key_update));
    bufp->chgWData(oldp+43,(vlSelfRef.aes_cipher_top__DOT__sub_out),128);
    bufp->chgBit(oldp+47,(vlSelfRef.aes_cipher_top__DOT__sub_done));
    bufp->chgWData(oldp+48,(vlSelfRef.aes_cipher_top__DOT__shift_out),128);
    bufp->chgWData(oldp+52,(vlSelfRef.aes_cipher_top__DOT__mix_out),128);
    bufp->chgBit(oldp+56,(vlSelfRef.aes_cipher_top__DOT__mix_done));
    bufp->chgWData(oldp+57,(vlSelfRef.aes_cipher_top__DOT__round_key),128);
    bufp->chgBit(oldp+61,(vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__clk));
    bufp->chgBit(oldp+62,(vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__rst_n));
    bufp->chgBit(oldp+63,(vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__load_key));
    bufp->chgBit(oldp+64,(vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__update_key));
    bufp->chgWData(oldp+65,(vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__key_in),128);
    bufp->chgCData(oldp+69,(vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__round_in),4);
    bufp->chgWData(oldp+70,(vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__round_key),128);
    bufp->chgIData(oldp+74,(vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__last_word),32);
    bufp->chgCData(oldp+75,(vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__sub_out0),8);
    bufp->chgCData(oldp+76,(vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__sub_out1),8);
    bufp->chgCData(oldp+77,(vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__sub_out2),8);
    bufp->chgCData(oldp+78,(vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__sub_out3),8);
    bufp->chgIData(oldp+79,(vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__g_out),32);
    bufp->chgIData(oldp+80,(vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__w0_next),32);
    bufp->chgIData(oldp+81,(vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__w1_next),32);
    bufp->chgIData(oldp+82,(vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__w2_next),32);
    bufp->chgIData(oldp+83,(vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__w3_next),32);
    bufp->chgBit(oldp+84,(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__clk));
    bufp->chgBit(oldp+85,(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__rst_n));
    bufp->chgBit(oldp+86,(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__start));
    bufp->chgWData(oldp+87,(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__state_in),128);
    bufp->chgWData(oldp+91,(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__state_out),128);
    bufp->chgBit(oldp+95,(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__done));
    bufp->chgCData(oldp+96,(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__col_count),2);
    bufp->chgBit(oldp+97,(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__busy));
    bufp->chgWData(oldp+98,(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__internal_state),128);
    bufp->chgIData(oldp+102,(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__current_col),32);
    bufp->chgCData(oldp+103,(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s0),8);
    bufp->chgCData(oldp+104,(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s1),8);
    bufp->chgCData(oldp+105,(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s2),8);
    bufp->chgCData(oldp+106,(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s3),8);
    bufp->chgCData(oldp+107,(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s0_x2),8);
    bufp->chgCData(oldp+108,(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s0_x3),8);
    bufp->chgCData(oldp+109,(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s1_x2),8);
    bufp->chgCData(oldp+110,(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s1_x3),8);
    bufp->chgCData(oldp+111,(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s2_x2),8);
    bufp->chgCData(oldp+112,(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s2_x3),8);
    bufp->chgCData(oldp+113,(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s3_x2),8);
    bufp->chgCData(oldp+114,(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s3_x3),8);
    bufp->chgWData(oldp+115,(vlSelfRef.aes_cipher_top__DOT__shift_unit__DOT__state_in),128);
    bufp->chgWData(oldp+119,(vlSelfRef.aes_cipher_top__DOT__shift_unit__DOT__state_out),128);
    bufp->chgBit(oldp+123,(vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__clk));
    bufp->chgBit(oldp+124,(vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__reset));
    bufp->chgBit(oldp+125,(vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__start));
    bufp->chgWData(oldp+126,(vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__state_in),128);
    bufp->chgWData(oldp+130,(vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__state_out),128);
    bufp->chgBit(oldp+134,(vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__done));
    bufp->chgCData(oldp+135,(vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__counter),4);
    bufp->chgCData(oldp+136,(vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__sbox_in),8);
    bufp->chgCData(oldp+137,(vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__sbox_out),8);
    bufp->chgBit(oldp+138,(vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__busy));
    bufp->chgCData(oldp+139,(vlSymsp->TOP__aes_cipher_top__DOT__sub_unit__DOT__my_sbox.a),8);
    bufp->chgCData(oldp+140,(vlSymsp->TOP__aes_cipher_top__DOT__sub_unit__DOT__my_sbox.c),8);
    bufp->chgCData(oldp+141,(vlSymsp->TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst0.a),8);
    bufp->chgCData(oldp+142,(vlSymsp->TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst0.c),8);
    bufp->chgCData(oldp+143,(vlSymsp->TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst1.a),8);
    bufp->chgCData(oldp+144,(vlSymsp->TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst1.c),8);
    bufp->chgCData(oldp+145,(vlSymsp->TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst2.a),8);
    bufp->chgCData(oldp+146,(vlSymsp->TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst2.c),8);
    bufp->chgCData(oldp+147,(vlSymsp->TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst3.a),8);
    bufp->chgCData(oldp+148,(vlSymsp->TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst3.c),8);
}

void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_cleanup\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = 0;
    }
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
