// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"
class Vtop_sbox;


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop___024root final : public VerilatedModule {
  public:
    // CELLS
    Vtop_sbox* __PVT__aes_cipher_top__DOT__sub_unit__DOT__my_sbox;
    Vtop_sbox* __PVT__aes_cipher_top__DOT__key_unit__DOT__sbox_inst0;
    Vtop_sbox* __PVT__aes_cipher_top__DOT__key_unit__DOT__sbox_inst1;
    Vtop_sbox* __PVT__aes_cipher_top__DOT__key_unit__DOT__sbox_inst2;
    Vtop_sbox* __PVT__aes_cipher_top__DOT__key_unit__DOT__sbox_inst3;

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk,0,0);
        VL_IN8(rst_n,0,0);
        VL_IN8(start,0,0);
        VL_OUT8(done,0,0);
        CData/*0:0*/ aes_cipher_top__DOT__clk;
        CData/*0:0*/ aes_cipher_top__DOT__rst_n;
        CData/*0:0*/ aes_cipher_top__DOT__start;
        CData/*0:0*/ aes_cipher_top__DOT__done;
        CData/*3:0*/ aes_cipher_top__DOT__state;
        CData/*3:0*/ aes_cipher_top__DOT__next_state;
        CData/*3:0*/ aes_cipher_top__DOT__round;
        CData/*0:0*/ aes_cipher_top__DOT__sub_start;
        CData/*0:0*/ aes_cipher_top__DOT__mix_start;
        CData/*0:0*/ aes_cipher_top__DOT__load_key;
        CData/*0:0*/ aes_cipher_top__DOT__key_update;
        CData/*0:0*/ aes_cipher_top__DOT__sub_done;
        CData/*0:0*/ aes_cipher_top__DOT__mix_done;
        CData/*0:0*/ aes_cipher_top__DOT__sub_unit__DOT__clk;
        CData/*0:0*/ aes_cipher_top__DOT__sub_unit__DOT__reset;
        CData/*0:0*/ aes_cipher_top__DOT__sub_unit__DOT__start;
        CData/*0:0*/ aes_cipher_top__DOT__sub_unit__DOT__done;
        CData/*3:0*/ aes_cipher_top__DOT__sub_unit__DOT__counter;
        CData/*7:0*/ aes_cipher_top__DOT__sub_unit__DOT__sbox_in;
        CData/*7:0*/ aes_cipher_top__DOT__sub_unit__DOT__sbox_out;
        CData/*0:0*/ aes_cipher_top__DOT__sub_unit__DOT__busy;
        CData/*0:0*/ aes_cipher_top__DOT__mix_unit__DOT__clk;
        CData/*0:0*/ aes_cipher_top__DOT__mix_unit__DOT__rst_n;
        CData/*0:0*/ aes_cipher_top__DOT__mix_unit__DOT__start;
        CData/*0:0*/ aes_cipher_top__DOT__mix_unit__DOT__done;
        CData/*1:0*/ aes_cipher_top__DOT__mix_unit__DOT__col_count;
        CData/*0:0*/ aes_cipher_top__DOT__mix_unit__DOT__busy;
        CData/*7:0*/ aes_cipher_top__DOT__mix_unit__DOT__s0;
        CData/*7:0*/ aes_cipher_top__DOT__mix_unit__DOT__s1;
        CData/*7:0*/ aes_cipher_top__DOT__mix_unit__DOT__s2;
        CData/*7:0*/ aes_cipher_top__DOT__mix_unit__DOT__s3;
        CData/*7:0*/ aes_cipher_top__DOT__mix_unit__DOT__s0_x2;
        CData/*7:0*/ aes_cipher_top__DOT__mix_unit__DOT__s0_x3;
        CData/*7:0*/ aes_cipher_top__DOT__mix_unit__DOT__s1_x2;
        CData/*7:0*/ aes_cipher_top__DOT__mix_unit__DOT__s1_x3;
        CData/*7:0*/ aes_cipher_top__DOT__mix_unit__DOT__s2_x2;
        CData/*7:0*/ aes_cipher_top__DOT__mix_unit__DOT__s2_x3;
        CData/*7:0*/ aes_cipher_top__DOT__mix_unit__DOT__s3_x2;
        CData/*7:0*/ aes_cipher_top__DOT__mix_unit__DOT__s3_x3;
        CData/*0:0*/ aes_cipher_top__DOT__key_unit__DOT__clk;
        CData/*0:0*/ aes_cipher_top__DOT__key_unit__DOT__rst_n;
        CData/*0:0*/ aes_cipher_top__DOT__key_unit__DOT__load_key;
        CData/*0:0*/ aes_cipher_top__DOT__key_unit__DOT__update_key;
        CData/*3:0*/ aes_cipher_top__DOT__key_unit__DOT__round_in;
        CData/*7:0*/ aes_cipher_top__DOT__key_unit__DOT__sub_out0;
        CData/*7:0*/ aes_cipher_top__DOT__key_unit__DOT__sub_out1;
        CData/*7:0*/ aes_cipher_top__DOT__key_unit__DOT__sub_out2;
        CData/*7:0*/ aes_cipher_top__DOT__key_unit__DOT__sub_out3;
        CData/*7:0*/ __Vfunc_aes_cipher_top__DOT__key_unit__DOT__get_rcon__4__Vfuncout;
        CData/*3:0*/ __Vfunc_aes_cipher_top__DOT__key_unit__DOT__get_rcon__4__r;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __VicoFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__rst_n__0;
        CData/*0:0*/ __VactContinue;
        VL_INW(plaintext,127,0,4);
        VL_INW(key,127,0,4);
        VL_OUTW(ciphertext,127,0,4);
        VlWide<4>/*127:0*/ aes_cipher_top__DOT__plaintext;
        VlWide<4>/*127:0*/ aes_cipher_top__DOT__key;
    };
    struct {
        VlWide<4>/*127:0*/ aes_cipher_top__DOT__ciphertext;
        VlWide<4>/*127:0*/ aes_cipher_top__DOT__state_reg;
        VlWide<4>/*127:0*/ aes_cipher_top__DOT__sub_out;
        VlWide<4>/*127:0*/ aes_cipher_top__DOT__shift_out;
        VlWide<4>/*127:0*/ aes_cipher_top__DOT__mix_out;
        VlWide<4>/*127:0*/ aes_cipher_top__DOT__round_key;
        VlWide<4>/*127:0*/ aes_cipher_top__DOT__sub_unit__DOT__state_in;
        VlWide<4>/*127:0*/ aes_cipher_top__DOT__sub_unit__DOT__state_out;
        VlWide<4>/*127:0*/ aes_cipher_top__DOT__shift_unit__DOT__state_in;
        VlWide<4>/*127:0*/ aes_cipher_top__DOT__shift_unit__DOT__state_out;
        VlWide<4>/*127:0*/ aes_cipher_top__DOT__mix_unit__DOT__state_in;
        VlWide<4>/*127:0*/ aes_cipher_top__DOT__mix_unit__DOT__state_out;
        VlWide<4>/*127:0*/ aes_cipher_top__DOT__mix_unit__DOT__internal_state;
        IData/*31:0*/ aes_cipher_top__DOT__mix_unit__DOT__current_col;
        VlWide<4>/*127:0*/ aes_cipher_top__DOT__key_unit__DOT__key_in;
        VlWide<4>/*127:0*/ aes_cipher_top__DOT__key_unit__DOT__round_key;
        IData/*31:0*/ aes_cipher_top__DOT__key_unit__DOT__last_word;
        IData/*31:0*/ aes_cipher_top__DOT__key_unit__DOT__g_out;
        IData/*31:0*/ aes_cipher_top__DOT__key_unit__DOT__w0_next;
        IData/*31:0*/ aes_cipher_top__DOT__key_unit__DOT__w1_next;
        IData/*31:0*/ aes_cipher_top__DOT__key_unit__DOT__w2_next;
        IData/*31:0*/ aes_cipher_top__DOT__key_unit__DOT__w3_next;
        IData/*31:0*/ __VactIterCount;
    };
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // PARAMETERS
    static constexpr CData/*3:0*/ aes_cipher_top__DOT__IDLE = 0U;
    static constexpr CData/*3:0*/ aes_cipher_top__DOT__LOAD_WAIT = 1U;
    static constexpr CData/*3:0*/ aes_cipher_top__DOT__INIT_ARK = 2U;
    static constexpr CData/*3:0*/ aes_cipher_top__DOT__KEY_UPD = 3U;
    static constexpr CData/*3:0*/ aes_cipher_top__DOT__KEY_WAIT = 4U;
    static constexpr CData/*3:0*/ aes_cipher_top__DOT__SUB_ST = 5U;
    static constexpr CData/*3:0*/ aes_cipher_top__DOT__SUB_WAIT = 6U;
    static constexpr CData/*3:0*/ aes_cipher_top__DOT__SB_LATCH = 7U;
    static constexpr CData/*3:0*/ aes_cipher_top__DOT__SHIFT = 8U;
    static constexpr CData/*3:0*/ aes_cipher_top__DOT__MIX_ST = 9U;
    static constexpr CData/*3:0*/ aes_cipher_top__DOT__MIX_WAIT = 0x0aU;
    static constexpr CData/*3:0*/ aes_cipher_top__DOT__ADD_KEY = 0x0bU;
    static constexpr CData/*3:0*/ aes_cipher_top__DOT__DONE_ST = 0x0cU;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* v__name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
