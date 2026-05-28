// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop___024root.h"

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst_n__0 = vlSelfRef.rst_n;
}

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vtop___024root___eval_final(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_final\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY(((0x64U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("/home/athxrva/AESCoreStage2/aes_cipher_top.v", 304, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtop___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___eval_triggers__stl(Vtop___024root* vlSelf);
VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf);

VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtop___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vtop___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VicoTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(negedge rst_n)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(negedge rst_n)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1638864771569018232ull);
    vlSelf->start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9867861323841650631ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->plaintext, __VscopeHash, 15306753485699558102ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->key, __VscopeHash, 14066609003741847747ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->ciphertext, __VscopeHash, 5156948722554576173ull);
    vlSelf->done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10296494685231209730ull);
    vlSelf->aes_cipher_top__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4376030881050810536ull);
    vlSelf->aes_cipher_top__DOT__rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7937620076377317081ull);
    vlSelf->aes_cipher_top__DOT__start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11737052946623350033ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->aes_cipher_top__DOT__plaintext, __VscopeHash, 8429394660660799822ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->aes_cipher_top__DOT__key, __VscopeHash, 3988739231174173225ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->aes_cipher_top__DOT__ciphertext, __VscopeHash, 14253965233558324245ull);
    vlSelf->aes_cipher_top__DOT__done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4500308099340269064ull);
    vlSelf->aes_cipher_top__DOT__state = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 13886837466269653540ull);
    vlSelf->aes_cipher_top__DOT__next_state = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 9856269693456160250ull);
    vlSelf->aes_cipher_top__DOT__round = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 14497295270323392295ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->aes_cipher_top__DOT__state_reg, __VscopeHash, 15043648545174443927ull);
    vlSelf->aes_cipher_top__DOT__sub_start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16873132480919671902ull);
    vlSelf->aes_cipher_top__DOT__mix_start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8026308008387739337ull);
    vlSelf->aes_cipher_top__DOT__load_key = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17056069308922248651ull);
    vlSelf->aes_cipher_top__DOT__key_update = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3456034495227117270ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->aes_cipher_top__DOT__sub_out, __VscopeHash, 786368519874896079ull);
    vlSelf->aes_cipher_top__DOT__sub_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17134931332943675700ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->aes_cipher_top__DOT__shift_out, __VscopeHash, 15191116410409145058ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->aes_cipher_top__DOT__mix_out, __VscopeHash, 14216177999098369282ull);
    vlSelf->aes_cipher_top__DOT__mix_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7508491005733533286ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->aes_cipher_top__DOT__round_key, __VscopeHash, 15811332542657439175ull);
    vlSelf->aes_cipher_top__DOT__sub_unit__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17617118294334611234ull);
    vlSelf->aes_cipher_top__DOT__sub_unit__DOT__reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4173375103955941435ull);
    vlSelf->aes_cipher_top__DOT__sub_unit__DOT__start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9881597868503390422ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->aes_cipher_top__DOT__sub_unit__DOT__state_in, __VscopeHash, 4587290382067221915ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->aes_cipher_top__DOT__sub_unit__DOT__state_out, __VscopeHash, 436886787195893747ull);
    vlSelf->aes_cipher_top__DOT__sub_unit__DOT__done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8474033617905246315ull);
    vlSelf->aes_cipher_top__DOT__sub_unit__DOT__counter = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 14786472457510694423ull);
    vlSelf->aes_cipher_top__DOT__sub_unit__DOT__sbox_in = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 18235010093780528891ull);
    vlSelf->aes_cipher_top__DOT__sub_unit__DOT__sbox_out = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3574643466832240517ull);
    vlSelf->aes_cipher_top__DOT__sub_unit__DOT__busy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10712769483222923804ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->aes_cipher_top__DOT__shift_unit__DOT__state_in, __VscopeHash, 16896140306543307150ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->aes_cipher_top__DOT__shift_unit__DOT__state_out, __VscopeHash, 1246190691562070741ull);
    vlSelf->aes_cipher_top__DOT__mix_unit__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7693215025743891499ull);
    vlSelf->aes_cipher_top__DOT__mix_unit__DOT__rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1961205635894753621ull);
    vlSelf->aes_cipher_top__DOT__mix_unit__DOT__start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 747572368329759551ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->aes_cipher_top__DOT__mix_unit__DOT__state_in, __VscopeHash, 12123508989980201589ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->aes_cipher_top__DOT__mix_unit__DOT__state_out, __VscopeHash, 10387095344026275241ull);
    vlSelf->aes_cipher_top__DOT__mix_unit__DOT__done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11756309908659648725ull);
    vlSelf->aes_cipher_top__DOT__mix_unit__DOT__col_count = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 14707966825836200487ull);
    vlSelf->aes_cipher_top__DOT__mix_unit__DOT__busy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3168059714166561140ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->aes_cipher_top__DOT__mix_unit__DOT__internal_state, __VscopeHash, 2046899481368326311ull);
    vlSelf->aes_cipher_top__DOT__mix_unit__DOT__current_col = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12365150487131403526ull);
    vlSelf->aes_cipher_top__DOT__mix_unit__DOT__s0 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11607209143140993354ull);
    vlSelf->aes_cipher_top__DOT__mix_unit__DOT__s1 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8815502383419309096ull);
    vlSelf->aes_cipher_top__DOT__mix_unit__DOT__s2 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16278233981161046490ull);
    vlSelf->aes_cipher_top__DOT__mix_unit__DOT__s3 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8832522138897945372ull);
    vlSelf->aes_cipher_top__DOT__mix_unit__DOT__s0_x2 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9639786448801669511ull);
    vlSelf->aes_cipher_top__DOT__mix_unit__DOT__s0_x3 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12450237051198593517ull);
    vlSelf->aes_cipher_top__DOT__mix_unit__DOT__s1_x2 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17576859195222808565ull);
    vlSelf->aes_cipher_top__DOT__mix_unit__DOT__s1_x3 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1603497348915624483ull);
    vlSelf->aes_cipher_top__DOT__mix_unit__DOT__s2_x2 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10933340876051809314ull);
    vlSelf->aes_cipher_top__DOT__mix_unit__DOT__s2_x3 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6280010479360497030ull);
    vlSelf->aes_cipher_top__DOT__mix_unit__DOT__s3_x2 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6063824646440872874ull);
    vlSelf->aes_cipher_top__DOT__mix_unit__DOT__s3_x3 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9436491985377207815ull);
    vlSelf->aes_cipher_top__DOT__key_unit__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15496191880296829975ull);
    vlSelf->aes_cipher_top__DOT__key_unit__DOT__rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15191737592698793054ull);
    vlSelf->aes_cipher_top__DOT__key_unit__DOT__load_key = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18342847267986871004ull);
    vlSelf->aes_cipher_top__DOT__key_unit__DOT__update_key = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4289892695030973943ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->aes_cipher_top__DOT__key_unit__DOT__key_in, __VscopeHash, 2452979707872288170ull);
    vlSelf->aes_cipher_top__DOT__key_unit__DOT__round_in = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 2858067044344063807ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->aes_cipher_top__DOT__key_unit__DOT__round_key, __VscopeHash, 1653945134337288602ull);
    vlSelf->aes_cipher_top__DOT__key_unit__DOT__last_word = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4404791666965070641ull);
    vlSelf->aes_cipher_top__DOT__key_unit__DOT__sub_out0 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4258517654859699572ull);
    vlSelf->aes_cipher_top__DOT__key_unit__DOT__sub_out1 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10261356791027359171ull);
    vlSelf->aes_cipher_top__DOT__key_unit__DOT__sub_out2 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7310410579365500592ull);
    vlSelf->aes_cipher_top__DOT__key_unit__DOT__sub_out3 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2972395559209060503ull);
    vlSelf->aes_cipher_top__DOT__key_unit__DOT__g_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14010785232450561414ull);
    vlSelf->aes_cipher_top__DOT__key_unit__DOT__w0_next = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5548650030107361150ull);
    vlSelf->aes_cipher_top__DOT__key_unit__DOT__w1_next = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7409372255723598298ull);
    vlSelf->aes_cipher_top__DOT__key_unit__DOT__w2_next = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3927187432245176650ull);
    vlSelf->aes_cipher_top__DOT__key_unit__DOT__w3_next = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15069203066421548974ull);
    vlSelf->__Vfunc_aes_cipher_top__DOT__key_unit__DOT__get_rcon__4__Vfuncout = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10446424214171531374ull);
    vlSelf->__Vfunc_aes_cipher_top__DOT__key_unit__DOT__get_rcon__4__r = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 10248072352646151084ull);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9526919608049418986ull);
    vlSelf->__Vtrigprevexpr___TOP__rst_n__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14803524876191471008ull);
}
