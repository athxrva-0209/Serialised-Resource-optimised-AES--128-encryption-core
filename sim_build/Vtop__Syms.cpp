// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtop__pch.h"
#include "Vtop.h"
#include "Vtop___024root.h"
#include "Vtop_sbox.h"

// FUNCTIONS
Vtop__Syms::~Vtop__Syms()
{

    // Tear down scope hierarchy
    __Vhier.remove(0, &__Vscope_aes_cipher_top);
    __Vhier.remove(&__Vscope_aes_cipher_top, &__Vscope_aes_cipher_top__key_unit);
    __Vhier.remove(&__Vscope_aes_cipher_top, &__Vscope_aes_cipher_top__mix_unit);
    __Vhier.remove(&__Vscope_aes_cipher_top, &__Vscope_aes_cipher_top__shift_unit);
    __Vhier.remove(&__Vscope_aes_cipher_top, &__Vscope_aes_cipher_top__sub_unit);
    __Vhier.remove(&__Vscope_aes_cipher_top__key_unit, &__Vscope_aes_cipher_top__key_unit__sbox_inst0);
    __Vhier.remove(&__Vscope_aes_cipher_top__key_unit, &__Vscope_aes_cipher_top__key_unit__sbox_inst1);
    __Vhier.remove(&__Vscope_aes_cipher_top__key_unit, &__Vscope_aes_cipher_top__key_unit__sbox_inst2);
    __Vhier.remove(&__Vscope_aes_cipher_top__key_unit, &__Vscope_aes_cipher_top__key_unit__sbox_inst3);
    __Vhier.remove(&__Vscope_aes_cipher_top__sub_unit, &__Vscope_aes_cipher_top__sub_unit__my_sbox);

}

Vtop__Syms::Vtop__Syms(VerilatedContext* contextp, const char* namep, Vtop* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
    , TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst0{this, Verilated::catName(namep, "aes_cipher_top.key_unit.sbox_inst0")}
    , TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst1{this, Verilated::catName(namep, "aes_cipher_top.key_unit.sbox_inst1")}
    , TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst2{this, Verilated::catName(namep, "aes_cipher_top.key_unit.sbox_inst2")}
    , TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst3{this, Verilated::catName(namep, "aes_cipher_top.key_unit.sbox_inst3")}
    , TOP__aes_cipher_top__DOT__sub_unit__DOT__my_sbox{this, Verilated::catName(namep, "aes_cipher_top.sub_unit.my_sbox")}
{
        // Check resources
        Verilated::stackCheck(155);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    TOP.__PVT__aes_cipher_top__DOT__key_unit__DOT__sbox_inst0 = &TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst0;
    TOP.__PVT__aes_cipher_top__DOT__key_unit__DOT__sbox_inst1 = &TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst1;
    TOP.__PVT__aes_cipher_top__DOT__key_unit__DOT__sbox_inst2 = &TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst2;
    TOP.__PVT__aes_cipher_top__DOT__key_unit__DOT__sbox_inst3 = &TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst3;
    TOP.__PVT__aes_cipher_top__DOT__sub_unit__DOT__my_sbox = &TOP__aes_cipher_top__DOT__sub_unit__DOT__my_sbox;
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst0.__Vconfigure(true);
    TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst1.__Vconfigure(false);
    TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst2.__Vconfigure(false);
    TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst3.__Vconfigure(false);
    TOP__aes_cipher_top__DOT__sub_unit__DOT__my_sbox.__Vconfigure(false);
    // Setup scopes
    __Vscope_TOP.configure(this, name(), "TOP", "TOP", "<null>", 0, VerilatedScope::SCOPE_OTHER);
    __Vscope_aes_cipher_top.configure(this, name(), "aes_cipher_top", "aes_cipher_top", "aes_cipher_top", -9, VerilatedScope::SCOPE_MODULE);
    __Vscope_aes_cipher_top__key_unit.configure(this, name(), "aes_cipher_top.key_unit", "key_unit", "keyexpansion", -9, VerilatedScope::SCOPE_MODULE);
    __Vscope_aes_cipher_top__key_unit__sbox_inst0.configure(this, name(), "aes_cipher_top.key_unit.sbox_inst0", "sbox_inst0", "sbox", -9, VerilatedScope::SCOPE_MODULE);
    __Vscope_aes_cipher_top__key_unit__sbox_inst1.configure(this, name(), "aes_cipher_top.key_unit.sbox_inst1", "sbox_inst1", "sbox", -9, VerilatedScope::SCOPE_MODULE);
    __Vscope_aes_cipher_top__key_unit__sbox_inst2.configure(this, name(), "aes_cipher_top.key_unit.sbox_inst2", "sbox_inst2", "sbox", -9, VerilatedScope::SCOPE_MODULE);
    __Vscope_aes_cipher_top__key_unit__sbox_inst3.configure(this, name(), "aes_cipher_top.key_unit.sbox_inst3", "sbox_inst3", "sbox", -9, VerilatedScope::SCOPE_MODULE);
    __Vscope_aes_cipher_top__mix_unit.configure(this, name(), "aes_cipher_top.mix_unit", "mix_unit", "mixcolumns", -9, VerilatedScope::SCOPE_MODULE);
    __Vscope_aes_cipher_top__shift_unit.configure(this, name(), "aes_cipher_top.shift_unit", "shift_unit", "shiftrows", -9, VerilatedScope::SCOPE_MODULE);
    __Vscope_aes_cipher_top__sub_unit.configure(this, name(), "aes_cipher_top.sub_unit", "sub_unit", "subbytes", -9, VerilatedScope::SCOPE_MODULE);
    __Vscope_aes_cipher_top__sub_unit__my_sbox.configure(this, name(), "aes_cipher_top.sub_unit.my_sbox", "my_sbox", "sbox", -9, VerilatedScope::SCOPE_MODULE);

    // Set up scope hierarchy
    __Vhier.add(0, &__Vscope_aes_cipher_top);
    __Vhier.add(&__Vscope_aes_cipher_top, &__Vscope_aes_cipher_top__key_unit);
    __Vhier.add(&__Vscope_aes_cipher_top, &__Vscope_aes_cipher_top__mix_unit);
    __Vhier.add(&__Vscope_aes_cipher_top, &__Vscope_aes_cipher_top__shift_unit);
    __Vhier.add(&__Vscope_aes_cipher_top, &__Vscope_aes_cipher_top__sub_unit);
    __Vhier.add(&__Vscope_aes_cipher_top__key_unit, &__Vscope_aes_cipher_top__key_unit__sbox_inst0);
    __Vhier.add(&__Vscope_aes_cipher_top__key_unit, &__Vscope_aes_cipher_top__key_unit__sbox_inst1);
    __Vhier.add(&__Vscope_aes_cipher_top__key_unit, &__Vscope_aes_cipher_top__key_unit__sbox_inst2);
    __Vhier.add(&__Vscope_aes_cipher_top__key_unit, &__Vscope_aes_cipher_top__key_unit__sbox_inst3);
    __Vhier.add(&__Vscope_aes_cipher_top__sub_unit, &__Vscope_aes_cipher_top__sub_unit__my_sbox);

    // Setup export functions
    for (int __Vfinal = 0; __Vfinal < 2; ++__Vfinal) {
        __Vscope_TOP.varInsert(__Vfinal,"ciphertext", &(TOP.ciphertext), false, VLVT_WDATA,VLVD_OUT|VLVF_PUB_RW,0,1 ,127,0);
        __Vscope_TOP.varInsert(__Vfinal,"clk", &(TOP.clk), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"done", &(TOP.done), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"key", &(TOP.key), false, VLVT_WDATA,VLVD_IN|VLVF_PUB_RW,0,1 ,127,0);
        __Vscope_TOP.varInsert(__Vfinal,"plaintext", &(TOP.plaintext), false, VLVT_WDATA,VLVD_IN|VLVF_PUB_RW,0,1 ,127,0);
        __Vscope_TOP.varInsert(__Vfinal,"rst_n", &(TOP.rst_n), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_TOP.varInsert(__Vfinal,"start", &(TOP.start), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,0);
        __Vscope_aes_cipher_top.varInsert(__Vfinal,"ADD_KEY", const_cast<void*>(static_cast<const void*>(&(TOP.aes_cipher_top__DOT__ADD_KEY))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,3,0);
        __Vscope_aes_cipher_top.varInsert(__Vfinal,"DONE_ST", const_cast<void*>(static_cast<const void*>(&(TOP.aes_cipher_top__DOT__DONE_ST))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,3,0);
        __Vscope_aes_cipher_top.varInsert(__Vfinal,"IDLE", const_cast<void*>(static_cast<const void*>(&(TOP.aes_cipher_top__DOT__IDLE))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,3,0);
        __Vscope_aes_cipher_top.varInsert(__Vfinal,"INIT_ARK", const_cast<void*>(static_cast<const void*>(&(TOP.aes_cipher_top__DOT__INIT_ARK))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,3,0);
        __Vscope_aes_cipher_top.varInsert(__Vfinal,"KEY_UPD", const_cast<void*>(static_cast<const void*>(&(TOP.aes_cipher_top__DOT__KEY_UPD))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,3,0);
        __Vscope_aes_cipher_top.varInsert(__Vfinal,"KEY_WAIT", const_cast<void*>(static_cast<const void*>(&(TOP.aes_cipher_top__DOT__KEY_WAIT))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,3,0);
        __Vscope_aes_cipher_top.varInsert(__Vfinal,"LOAD_WAIT", const_cast<void*>(static_cast<const void*>(&(TOP.aes_cipher_top__DOT__LOAD_WAIT))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,3,0);
        __Vscope_aes_cipher_top.varInsert(__Vfinal,"MIX_ST", const_cast<void*>(static_cast<const void*>(&(TOP.aes_cipher_top__DOT__MIX_ST))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,3,0);
        __Vscope_aes_cipher_top.varInsert(__Vfinal,"MIX_WAIT", const_cast<void*>(static_cast<const void*>(&(TOP.aes_cipher_top__DOT__MIX_WAIT))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,3,0);
        __Vscope_aes_cipher_top.varInsert(__Vfinal,"SB_LATCH", const_cast<void*>(static_cast<const void*>(&(TOP.aes_cipher_top__DOT__SB_LATCH))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,3,0);
        __Vscope_aes_cipher_top.varInsert(__Vfinal,"SHIFT", const_cast<void*>(static_cast<const void*>(&(TOP.aes_cipher_top__DOT__SHIFT))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,3,0);
        __Vscope_aes_cipher_top.varInsert(__Vfinal,"SUB_ST", const_cast<void*>(static_cast<const void*>(&(TOP.aes_cipher_top__DOT__SUB_ST))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,3,0);
        __Vscope_aes_cipher_top.varInsert(__Vfinal,"SUB_WAIT", const_cast<void*>(static_cast<const void*>(&(TOP.aes_cipher_top__DOT__SUB_WAIT))), true, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,3,0);
        __Vscope_aes_cipher_top.varInsert(__Vfinal,"ciphertext", &(TOP.aes_cipher_top__DOT__ciphertext), false, VLVT_WDATA,VLVD_NODIR|VLVF_PUB_RW,0,1 ,127,0);
        __Vscope_aes_cipher_top.varInsert(__Vfinal,"clk", &(TOP.aes_cipher_top__DOT__clk), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_aes_cipher_top.varInsert(__Vfinal,"done", &(TOP.aes_cipher_top__DOT__done), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_aes_cipher_top.varInsert(__Vfinal,"key", &(TOP.aes_cipher_top__DOT__key), false, VLVT_WDATA,VLVD_NODIR|VLVF_PUB_RW,0,1 ,127,0);
        __Vscope_aes_cipher_top.varInsert(__Vfinal,"key_update", &(TOP.aes_cipher_top__DOT__key_update), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_aes_cipher_top.varInsert(__Vfinal,"load_key", &(TOP.aes_cipher_top__DOT__load_key), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_aes_cipher_top.varInsert(__Vfinal,"mix_done", &(TOP.aes_cipher_top__DOT__mix_done), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_aes_cipher_top.varInsert(__Vfinal,"mix_out", &(TOP.aes_cipher_top__DOT__mix_out), false, VLVT_WDATA,VLVD_NODIR|VLVF_PUB_RW,0,1 ,127,0);
        __Vscope_aes_cipher_top.varInsert(__Vfinal,"mix_start", &(TOP.aes_cipher_top__DOT__mix_start), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_aes_cipher_top.varInsert(__Vfinal,"next_state", &(TOP.aes_cipher_top__DOT__next_state), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,3,0);
        __Vscope_aes_cipher_top.varInsert(__Vfinal,"plaintext", &(TOP.aes_cipher_top__DOT__plaintext), false, VLVT_WDATA,VLVD_NODIR|VLVF_PUB_RW,0,1 ,127,0);
        __Vscope_aes_cipher_top.varInsert(__Vfinal,"round", &(TOP.aes_cipher_top__DOT__round), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,3,0);
        __Vscope_aes_cipher_top.varInsert(__Vfinal,"round_key", &(TOP.aes_cipher_top__DOT__round_key), false, VLVT_WDATA,VLVD_NODIR|VLVF_PUB_RW,0,1 ,127,0);
        __Vscope_aes_cipher_top.varInsert(__Vfinal,"rst_n", &(TOP.aes_cipher_top__DOT__rst_n), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_aes_cipher_top.varInsert(__Vfinal,"shift_out", &(TOP.aes_cipher_top__DOT__shift_out), false, VLVT_WDATA,VLVD_NODIR|VLVF_PUB_RW,0,1 ,127,0);
        __Vscope_aes_cipher_top.varInsert(__Vfinal,"start", &(TOP.aes_cipher_top__DOT__start), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_aes_cipher_top.varInsert(__Vfinal,"state", &(TOP.aes_cipher_top__DOT__state), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,3,0);
        __Vscope_aes_cipher_top.varInsert(__Vfinal,"state_reg", &(TOP.aes_cipher_top__DOT__state_reg), false, VLVT_WDATA,VLVD_NODIR|VLVF_PUB_RW,0,1 ,127,0);
        __Vscope_aes_cipher_top.varInsert(__Vfinal,"sub_done", &(TOP.aes_cipher_top__DOT__sub_done), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_aes_cipher_top.varInsert(__Vfinal,"sub_out", &(TOP.aes_cipher_top__DOT__sub_out), false, VLVT_WDATA,VLVD_NODIR|VLVF_PUB_RW,0,1 ,127,0);
        __Vscope_aes_cipher_top.varInsert(__Vfinal,"sub_start", &(TOP.aes_cipher_top__DOT__sub_start), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_aes_cipher_top__key_unit.varInsert(__Vfinal,"clk", &(TOP.aes_cipher_top__DOT__key_unit__DOT__clk), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_aes_cipher_top__key_unit.varInsert(__Vfinal,"g_out", &(TOP.aes_cipher_top__DOT__key_unit__DOT__g_out), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_aes_cipher_top__key_unit.varInsert(__Vfinal,"key_in", &(TOP.aes_cipher_top__DOT__key_unit__DOT__key_in), false, VLVT_WDATA,VLVD_NODIR|VLVF_PUB_RW,0,1 ,127,0);
        __Vscope_aes_cipher_top__key_unit.varInsert(__Vfinal,"last_word", &(TOP.aes_cipher_top__DOT__key_unit__DOT__last_word), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_aes_cipher_top__key_unit.varInsert(__Vfinal,"load_key", &(TOP.aes_cipher_top__DOT__key_unit__DOT__load_key), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_aes_cipher_top__key_unit.varInsert(__Vfinal,"round_in", &(TOP.aes_cipher_top__DOT__key_unit__DOT__round_in), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,3,0);
        __Vscope_aes_cipher_top__key_unit.varInsert(__Vfinal,"round_key", &(TOP.aes_cipher_top__DOT__key_unit__DOT__round_key), false, VLVT_WDATA,VLVD_NODIR|VLVF_PUB_RW,0,1 ,127,0);
        __Vscope_aes_cipher_top__key_unit.varInsert(__Vfinal,"rst_n", &(TOP.aes_cipher_top__DOT__key_unit__DOT__rst_n), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_aes_cipher_top__key_unit.varInsert(__Vfinal,"sub_out0", &(TOP.aes_cipher_top__DOT__key_unit__DOT__sub_out0), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_aes_cipher_top__key_unit.varInsert(__Vfinal,"sub_out1", &(TOP.aes_cipher_top__DOT__key_unit__DOT__sub_out1), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_aes_cipher_top__key_unit.varInsert(__Vfinal,"sub_out2", &(TOP.aes_cipher_top__DOT__key_unit__DOT__sub_out2), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_aes_cipher_top__key_unit.varInsert(__Vfinal,"sub_out3", &(TOP.aes_cipher_top__DOT__key_unit__DOT__sub_out3), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_aes_cipher_top__key_unit.varInsert(__Vfinal,"update_key", &(TOP.aes_cipher_top__DOT__key_unit__DOT__update_key), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_aes_cipher_top__key_unit.varInsert(__Vfinal,"w0_next", &(TOP.aes_cipher_top__DOT__key_unit__DOT__w0_next), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_aes_cipher_top__key_unit.varInsert(__Vfinal,"w1_next", &(TOP.aes_cipher_top__DOT__key_unit__DOT__w1_next), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_aes_cipher_top__key_unit.varInsert(__Vfinal,"w2_next", &(TOP.aes_cipher_top__DOT__key_unit__DOT__w2_next), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_aes_cipher_top__key_unit.varInsert(__Vfinal,"w3_next", &(TOP.aes_cipher_top__DOT__key_unit__DOT__w3_next), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_aes_cipher_top__key_unit__sbox_inst0.varInsert(__Vfinal,"a", &(TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst0.a), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_aes_cipher_top__key_unit__sbox_inst0.varInsert(__Vfinal,"c", &(TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst0.c), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_aes_cipher_top__key_unit__sbox_inst1.varInsert(__Vfinal,"a", &(TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst1.a), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_aes_cipher_top__key_unit__sbox_inst1.varInsert(__Vfinal,"c", &(TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst1.c), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_aes_cipher_top__key_unit__sbox_inst2.varInsert(__Vfinal,"a", &(TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst2.a), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_aes_cipher_top__key_unit__sbox_inst2.varInsert(__Vfinal,"c", &(TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst2.c), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_aes_cipher_top__key_unit__sbox_inst3.varInsert(__Vfinal,"a", &(TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst3.a), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_aes_cipher_top__key_unit__sbox_inst3.varInsert(__Vfinal,"c", &(TOP__aes_cipher_top__DOT__key_unit__DOT__sbox_inst3.c), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_aes_cipher_top__mix_unit.varInsert(__Vfinal,"busy", &(TOP.aes_cipher_top__DOT__mix_unit__DOT__busy), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_aes_cipher_top__mix_unit.varInsert(__Vfinal,"clk", &(TOP.aes_cipher_top__DOT__mix_unit__DOT__clk), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_aes_cipher_top__mix_unit.varInsert(__Vfinal,"col_count", &(TOP.aes_cipher_top__DOT__mix_unit__DOT__col_count), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,1,0);
        __Vscope_aes_cipher_top__mix_unit.varInsert(__Vfinal,"current_col", &(TOP.aes_cipher_top__DOT__mix_unit__DOT__current_col), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,0,1 ,31,0);
        __Vscope_aes_cipher_top__mix_unit.varInsert(__Vfinal,"done", &(TOP.aes_cipher_top__DOT__mix_unit__DOT__done), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_aes_cipher_top__mix_unit.varInsert(__Vfinal,"internal_state", &(TOP.aes_cipher_top__DOT__mix_unit__DOT__internal_state), false, VLVT_WDATA,VLVD_NODIR|VLVF_PUB_RW,0,1 ,127,0);
        __Vscope_aes_cipher_top__mix_unit.varInsert(__Vfinal,"rst_n", &(TOP.aes_cipher_top__DOT__mix_unit__DOT__rst_n), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_aes_cipher_top__mix_unit.varInsert(__Vfinal,"s0", &(TOP.aes_cipher_top__DOT__mix_unit__DOT__s0), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_aes_cipher_top__mix_unit.varInsert(__Vfinal,"s0_x2", &(TOP.aes_cipher_top__DOT__mix_unit__DOT__s0_x2), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_aes_cipher_top__mix_unit.varInsert(__Vfinal,"s0_x3", &(TOP.aes_cipher_top__DOT__mix_unit__DOT__s0_x3), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_aes_cipher_top__mix_unit.varInsert(__Vfinal,"s1", &(TOP.aes_cipher_top__DOT__mix_unit__DOT__s1), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_aes_cipher_top__mix_unit.varInsert(__Vfinal,"s1_x2", &(TOP.aes_cipher_top__DOT__mix_unit__DOT__s1_x2), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_aes_cipher_top__mix_unit.varInsert(__Vfinal,"s1_x3", &(TOP.aes_cipher_top__DOT__mix_unit__DOT__s1_x3), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_aes_cipher_top__mix_unit.varInsert(__Vfinal,"s2", &(TOP.aes_cipher_top__DOT__mix_unit__DOT__s2), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_aes_cipher_top__mix_unit.varInsert(__Vfinal,"s2_x2", &(TOP.aes_cipher_top__DOT__mix_unit__DOT__s2_x2), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_aes_cipher_top__mix_unit.varInsert(__Vfinal,"s2_x3", &(TOP.aes_cipher_top__DOT__mix_unit__DOT__s2_x3), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_aes_cipher_top__mix_unit.varInsert(__Vfinal,"s3", &(TOP.aes_cipher_top__DOT__mix_unit__DOT__s3), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_aes_cipher_top__mix_unit.varInsert(__Vfinal,"s3_x2", &(TOP.aes_cipher_top__DOT__mix_unit__DOT__s3_x2), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_aes_cipher_top__mix_unit.varInsert(__Vfinal,"s3_x3", &(TOP.aes_cipher_top__DOT__mix_unit__DOT__s3_x3), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_aes_cipher_top__mix_unit.varInsert(__Vfinal,"start", &(TOP.aes_cipher_top__DOT__mix_unit__DOT__start), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_aes_cipher_top__mix_unit.varInsert(__Vfinal,"state_in", &(TOP.aes_cipher_top__DOT__mix_unit__DOT__state_in), false, VLVT_WDATA,VLVD_NODIR|VLVF_PUB_RW,0,1 ,127,0);
        __Vscope_aes_cipher_top__mix_unit.varInsert(__Vfinal,"state_out", &(TOP.aes_cipher_top__DOT__mix_unit__DOT__state_out), false, VLVT_WDATA,VLVD_NODIR|VLVF_PUB_RW,0,1 ,127,0);
        __Vscope_aes_cipher_top__shift_unit.varInsert(__Vfinal,"state_in", &(TOP.aes_cipher_top__DOT__shift_unit__DOT__state_in), false, VLVT_WDATA,VLVD_NODIR|VLVF_PUB_RW,0,1 ,127,0);
        __Vscope_aes_cipher_top__shift_unit.varInsert(__Vfinal,"state_out", &(TOP.aes_cipher_top__DOT__shift_unit__DOT__state_out), false, VLVT_WDATA,VLVD_NODIR|VLVF_PUB_RW,0,1 ,127,0);
        __Vscope_aes_cipher_top__sub_unit.varInsert(__Vfinal,"busy", &(TOP.aes_cipher_top__DOT__sub_unit__DOT__busy), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_aes_cipher_top__sub_unit.varInsert(__Vfinal,"clk", &(TOP.aes_cipher_top__DOT__sub_unit__DOT__clk), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_aes_cipher_top__sub_unit.varInsert(__Vfinal,"counter", &(TOP.aes_cipher_top__DOT__sub_unit__DOT__counter), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,3,0);
        __Vscope_aes_cipher_top__sub_unit.varInsert(__Vfinal,"done", &(TOP.aes_cipher_top__DOT__sub_unit__DOT__done), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_aes_cipher_top__sub_unit.varInsert(__Vfinal,"reset", &(TOP.aes_cipher_top__DOT__sub_unit__DOT__reset), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_aes_cipher_top__sub_unit.varInsert(__Vfinal,"sbox_in", &(TOP.aes_cipher_top__DOT__sub_unit__DOT__sbox_in), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_aes_cipher_top__sub_unit.varInsert(__Vfinal,"sbox_out", &(TOP.aes_cipher_top__DOT__sub_unit__DOT__sbox_out), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_aes_cipher_top__sub_unit.varInsert(__Vfinal,"start", &(TOP.aes_cipher_top__DOT__sub_unit__DOT__start), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,0,0);
        __Vscope_aes_cipher_top__sub_unit.varInsert(__Vfinal,"state_in", &(TOP.aes_cipher_top__DOT__sub_unit__DOT__state_in), false, VLVT_WDATA,VLVD_NODIR|VLVF_PUB_RW,0,1 ,127,0);
        __Vscope_aes_cipher_top__sub_unit.varInsert(__Vfinal,"state_out", &(TOP.aes_cipher_top__DOT__sub_unit__DOT__state_out), false, VLVT_WDATA,VLVD_NODIR|VLVF_PUB_RW,0,1 ,127,0);
        __Vscope_aes_cipher_top__sub_unit__my_sbox.varInsert(__Vfinal,"a", &(TOP__aes_cipher_top__DOT__sub_unit__DOT__my_sbox.a), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0,1 ,7,0);
        __Vscope_aes_cipher_top__sub_unit__my_sbox.varInsert(__Vfinal,"c", &(TOP__aes_cipher_top__DOT__sub_unit__DOT__my_sbox.c), false, VLVT_UINT8,VLVD_OUT|VLVF_PUB_RW,0,1 ,7,0);
    }
}
