// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop__Syms.h"
#include "Vtop___024root.h"

// Parameter definitions for Vtop___024root
constexpr CData/*3:0*/ Vtop___024root::aes_cipher_top__DOT__IDLE;
constexpr CData/*3:0*/ Vtop___024root::aes_cipher_top__DOT__LOAD_WAIT;
constexpr CData/*3:0*/ Vtop___024root::aes_cipher_top__DOT__INIT_ARK;
constexpr CData/*3:0*/ Vtop___024root::aes_cipher_top__DOT__KEY_UPD;
constexpr CData/*3:0*/ Vtop___024root::aes_cipher_top__DOT__KEY_WAIT;
constexpr CData/*3:0*/ Vtop___024root::aes_cipher_top__DOT__SUB_ST;
constexpr CData/*3:0*/ Vtop___024root::aes_cipher_top__DOT__SUB_WAIT;
constexpr CData/*3:0*/ Vtop___024root::aes_cipher_top__DOT__SB_LATCH;
constexpr CData/*3:0*/ Vtop___024root::aes_cipher_top__DOT__SHIFT;
constexpr CData/*3:0*/ Vtop___024root::aes_cipher_top__DOT__MIX_ST;
constexpr CData/*3:0*/ Vtop___024root::aes_cipher_top__DOT__MIX_WAIT;
constexpr CData/*3:0*/ Vtop___024root::aes_cipher_top__DOT__ADD_KEY;
constexpr CData/*3:0*/ Vtop___024root::aes_cipher_top__DOT__DONE_ST;


void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf);

Vtop___024root::Vtop___024root(Vtop__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtop___024root___ctor_var_reset(this);
}

void Vtop___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtop___024root::~Vtop___024root() {
}
