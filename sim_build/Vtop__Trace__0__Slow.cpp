// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst0__0(Vtop___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst1__0(Vtop___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst2__0(Vtop___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst3__0(Vtop___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__aes_cipher_top__DOT__sub_unit__DOT__my_sbox__0(Vtop___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("$rootio", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+3,0,"start",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+4,0,"plaintext",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 127,0);
    tracep->declArray(c+8,0,"key",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 127,0);
    tracep->declArray(c+12,0,"ciphertext",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 127,0);
    tracep->declBit(c+16,0,"done",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("aes_cipher_top", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+17,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+18,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+19,0,"start",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+20,0,"plaintext",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 127,0);
    tracep->declArray(c+24,0,"key",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 127,0);
    tracep->declArray(c+28,0,"ciphertext",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 127,0);
    tracep->declBit(c+32,0,"done",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+150,0,"IDLE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+151,0,"LOAD_WAIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+152,0,"INIT_ARK",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+153,0,"KEY_UPD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+154,0,"KEY_WAIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+155,0,"SUB_ST",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+156,0,"SUB_WAIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+157,0,"SB_LATCH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+158,0,"SHIFT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+159,0,"MIX_ST",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+160,0,"MIX_WAIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+161,0,"ADD_KEY",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+162,0,"DONE_ST",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+33,0,"state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+34,0,"next_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+35,0,"round",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declArray(c+36,0,"state_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 127,0);
    tracep->declBit(c+40,0,"sub_start",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+41,0,"mix_start",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+42,0,"load_key",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+43,0,"key_update",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+44,0,"sub_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 127,0);
    tracep->declBit(c+48,0,"sub_done",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+49,0,"shift_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 127,0);
    tracep->declArray(c+53,0,"mix_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 127,0);
    tracep->declBit(c+57,0,"mix_done",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+58,0,"round_key",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 127,0);
    tracep->pushPrefix("key_unit", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+62,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+63,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+64,0,"load_key",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+65,0,"update_key",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+66,0,"key_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 127,0);
    tracep->declBus(c+70,0,"round_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declArray(c+71,0,"round_key",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 127,0);
    tracep->declBus(c+75,0,"last_word",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+76,0,"sub_out0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+77,0,"sub_out1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+78,0,"sub_out2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+79,0,"sub_out3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->pushPrefix("sbox_inst0", VerilatedTracePrefixType::SCOPE_MODULE);
    Vtop___024root__trace_init_sub__TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst0__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("sbox_inst1", VerilatedTracePrefixType::SCOPE_MODULE);
    Vtop___024root__trace_init_sub__TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst1__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("sbox_inst2", VerilatedTracePrefixType::SCOPE_MODULE);
    Vtop___024root__trace_init_sub__TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst2__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("sbox_inst3", VerilatedTracePrefixType::SCOPE_MODULE);
    Vtop___024root__trace_init_sub__TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst3__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->declBus(c+80,0,"g_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+81,0,"w0_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+82,0,"w1_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+83,0,"w2_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+84,0,"w3_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("mix_unit", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+85,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+86,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+87,0,"start",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+88,0,"state_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 127,0);
    tracep->declArray(c+92,0,"state_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 127,0);
    tracep->declBit(c+96,0,"done",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+97,0,"col_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+98,0,"busy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+99,0,"internal_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 127,0);
    tracep->declBus(c+103,0,"current_col",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+104,0,"s0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+105,0,"s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+106,0,"s2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+107,0,"s3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+108,0,"s0_x2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+109,0,"s0_x3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+110,0,"s1_x2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+111,0,"s1_x3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+112,0,"s2_x2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+113,0,"s2_x3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+114,0,"s3_x2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+115,0,"s3_x3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("shift_unit", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declArray(c+116,0,"state_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 127,0);
    tracep->declArray(c+120,0,"state_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 127,0);
    tracep->popPrefix();
    tracep->pushPrefix("sub_unit", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+124,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+125,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+126,0,"start",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+127,0,"state_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 127,0);
    tracep->declArray(c+131,0,"state_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 127,0);
    tracep->declBit(c+135,0,"done",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+136,0,"counter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+137,0,"sbox_in",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+138,0,"sbox_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+139,0,"busy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("my_sbox", VerilatedTracePrefixType::SCOPE_MODULE);
    Vtop___024root__trace_init_sub__TOP__aes_cipher_top__DOT__sub_unit__DOT__my_sbox__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__aes_cipher_top__DOT__sub_unit__DOT__my_sbox__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__aes_cipher_top__DOT__sub_unit__DOT__my_sbox__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+140,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+141,0,"c",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst0__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst0__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+142,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+143,0,"c",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst1__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst1__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+144,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+145,0,"c",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst2__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst2__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+146,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+147,0,"c",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst3__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst3__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+148,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+149,0,"c",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
}

VL_ATTR_COLD void Vtop___024root__trace_init_top(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_top\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtop___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vtop___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vtop___024root__trace_register(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_register\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vtop___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vtop___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vtop___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vtop___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtop___024root__trace_const_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtop___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_const_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtop___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtop___024root__trace_const_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_const_0_sub_0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullCData(oldp+150,(0U),4);
    bufp->fullCData(oldp+151,(1U),4);
    bufp->fullCData(oldp+152,(2U),4);
    bufp->fullCData(oldp+153,(3U),4);
    bufp->fullCData(oldp+154,(4U),4);
    bufp->fullCData(oldp+155,(5U),4);
    bufp->fullCData(oldp+156,(6U),4);
    bufp->fullCData(oldp+157,(7U),4);
    bufp->fullCData(oldp+158,(8U),4);
    bufp->fullCData(oldp+159,(9U),4);
    bufp->fullCData(oldp+160,(0xaU),4);
    bufp->fullCData(oldp+161,(0xbU),4);
    bufp->fullCData(oldp+162,(0xcU),4);
}

VL_ATTR_COLD void Vtop___024root__trace_full_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtop___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtop___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtop___024root__trace_full_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_0_sub_0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelfRef.clk));
    bufp->fullBit(oldp+2,(vlSelfRef.rst_n));
    bufp->fullBit(oldp+3,(vlSelfRef.start));
    bufp->fullWData(oldp+4,(vlSelfRef.plaintext),128);
    bufp->fullWData(oldp+8,(vlSelfRef.key),128);
    bufp->fullWData(oldp+12,(vlSelfRef.ciphertext),128);
    bufp->fullBit(oldp+16,(vlSelfRef.done));
    bufp->fullBit(oldp+17,(vlSelfRef.aes_cipher_top__DOT__clk));
    bufp->fullBit(oldp+18,(vlSelfRef.aes_cipher_top__DOT__rst_n));
    bufp->fullBit(oldp+19,(vlSelfRef.aes_cipher_top__DOT__start));
    bufp->fullWData(oldp+20,(vlSelfRef.aes_cipher_top__DOT__plaintext),128);
    bufp->fullWData(oldp+24,(vlSelfRef.aes_cipher_top__DOT__key),128);
    bufp->fullWData(oldp+28,(vlSelfRef.aes_cipher_top__DOT__ciphertext),128);
    bufp->fullBit(oldp+32,(vlSelfRef.aes_cipher_top__DOT__done));
    bufp->fullCData(oldp+33,(vlSelfRef.aes_cipher_top__DOT__state),4);
    bufp->fullCData(oldp+34,(vlSelfRef.aes_cipher_top__DOT__next_state),4);
    bufp->fullCData(oldp+35,(vlSelfRef.aes_cipher_top__DOT__round),4);
    bufp->fullWData(oldp+36,(vlSelfRef.aes_cipher_top__DOT__state_reg),128);
    bufp->fullBit(oldp+40,(vlSelfRef.aes_cipher_top__DOT__sub_start));
    bufp->fullBit(oldp+41,(vlSelfRef.aes_cipher_top__DOT__mix_start));
    bufp->fullBit(oldp+42,(vlSelfRef.aes_cipher_top__DOT__load_key));
    bufp->fullBit(oldp+43,(vlSelfRef.aes_cipher_top__DOT__key_update));
    bufp->fullWData(oldp+44,(vlSelfRef.aes_cipher_top__DOT__sub_out),128);
    bufp->fullBit(oldp+48,(vlSelfRef.aes_cipher_top__DOT__sub_done));
    bufp->fullWData(oldp+49,(vlSelfRef.aes_cipher_top__DOT__shift_out),128);
    bufp->fullWData(oldp+53,(vlSelfRef.aes_cipher_top__DOT__mix_out),128);
    bufp->fullBit(oldp+57,(vlSelfRef.aes_cipher_top__DOT__mix_done));
    bufp->fullWData(oldp+58,(vlSelfRef.aes_cipher_top__DOT__round_key),128);
    bufp->fullBit(oldp+62,(vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__clk));
    bufp->fullBit(oldp+63,(vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__rst_n));
    bufp->fullBit(oldp+64,(vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__load_key));
    bufp->fullBit(oldp+65,(vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__update_key));
    bufp->fullWData(oldp+66,(vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__key_in),128);
    bufp->fullCData(oldp+70,(vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__round_in),4);
    bufp->fullWData(oldp+71,(vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__round_key),128);
    bufp->fullIData(oldp+75,(vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__last_word),32);
    bufp->fullCData(oldp+76,(vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__sub_out0),8);
    bufp->fullCData(oldp+77,(vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__sub_out1),8);
    bufp->fullCData(oldp+78,(vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__sub_out2),8);
    bufp->fullCData(oldp+79,(vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__sub_out3),8);
    bufp->fullIData(oldp+80,(vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__g_out),32);
    bufp->fullIData(oldp+81,(vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__w0_next),32);
    bufp->fullIData(oldp+82,(vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__w1_next),32);
    bufp->fullIData(oldp+83,(vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__w2_next),32);
    bufp->fullIData(oldp+84,(vlSelfRef.aes_cipher_top__DOT__key_unit__DOT__w3_next),32);
    bufp->fullBit(oldp+85,(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__clk));
    bufp->fullBit(oldp+86,(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__rst_n));
    bufp->fullBit(oldp+87,(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__start));
    bufp->fullWData(oldp+88,(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__state_in),128);
    bufp->fullWData(oldp+92,(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__state_out),128);
    bufp->fullBit(oldp+96,(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__done));
    bufp->fullCData(oldp+97,(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__col_count),2);
    bufp->fullBit(oldp+98,(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__busy));
    bufp->fullWData(oldp+99,(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__internal_state),128);
    bufp->fullIData(oldp+103,(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__current_col),32);
    bufp->fullCData(oldp+104,(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s0),8);
    bufp->fullCData(oldp+105,(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s1),8);
    bufp->fullCData(oldp+106,(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s2),8);
    bufp->fullCData(oldp+107,(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s3),8);
    bufp->fullCData(oldp+108,(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s0_x2),8);
    bufp->fullCData(oldp+109,(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s0_x3),8);
    bufp->fullCData(oldp+110,(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s1_x2),8);
    bufp->fullCData(oldp+111,(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s1_x3),8);
    bufp->fullCData(oldp+112,(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s2_x2),8);
    bufp->fullCData(oldp+113,(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s2_x3),8);
    bufp->fullCData(oldp+114,(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s3_x2),8);
    bufp->fullCData(oldp+115,(vlSelfRef.aes_cipher_top__DOT__mix_unit__DOT__s3_x3),8);
    bufp->fullWData(oldp+116,(vlSelfRef.aes_cipher_top__DOT__shift_unit__DOT__state_in),128);
    bufp->fullWData(oldp+120,(vlSelfRef.aes_cipher_top__DOT__shift_unit__DOT__state_out),128);
    bufp->fullBit(oldp+124,(vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__clk));
    bufp->fullBit(oldp+125,(vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__reset));
    bufp->fullBit(oldp+126,(vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__start));
    bufp->fullWData(oldp+127,(vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__state_in),128);
    bufp->fullWData(oldp+131,(vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__state_out),128);
    bufp->fullBit(oldp+135,(vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__done));
    bufp->fullCData(oldp+136,(vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__counter),4);
    bufp->fullCData(oldp+137,(vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__sbox_in),8);
    bufp->fullCData(oldp+138,(vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__sbox_out),8);
    bufp->fullBit(oldp+139,(vlSelfRef.aes_cipher_top__DOT__sub_unit__DOT__busy));
    bufp->fullCData(oldp+140,(vlSymsp->TOP__aes_cipher_top__DOT__sub_unit__DOT__my_sbox.a),8);
    bufp->fullCData(oldp+141,(vlSymsp->TOP__aes_cipher_top__DOT__sub_unit__DOT__my_sbox.c),8);
    bufp->fullCData(oldp+142,(vlSymsp->TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst0.a),8);
    bufp->fullCData(oldp+143,(vlSymsp->TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst0.c),8);
    bufp->fullCData(oldp+144,(vlSymsp->TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst1.a),8);
    bufp->fullCData(oldp+145,(vlSymsp->TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst1.c),8);
    bufp->fullCData(oldp+146,(vlSymsp->TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst2.a),8);
    bufp->fullCData(oldp+147,(vlSymsp->TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst2.c),8);
    bufp->fullCData(oldp+148,(vlSymsp->TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst3.a),8);
    bufp->fullCData(oldp+149,(vlSymsp->TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst3.c),8);
}
