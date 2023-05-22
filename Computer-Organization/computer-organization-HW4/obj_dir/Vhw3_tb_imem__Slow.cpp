// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vhw3_tb.h for the primary calling header

#include "Vhw3_tb_imem.h"
#include "Vhw3_tb__Syms.h"

#include "verilated_dpi.h"

//==========

VL_CTOR_IMP(Vhw3_tb_imem) {
    // Reset internal values
    // Reset structure values
    _ctor_var_reset();
}

void Vhw3_tb_imem::__Vconfigure(Vhw3_tb__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
}

Vhw3_tb_imem::~Vhw3_tb_imem() {
}

void Vhw3_tb_imem::_initial__TOP__hw3_tb__core_top_inst__imem_inst__1(Vhw3_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vhw3_tb_imem::_initial__TOP__hw3_tb__core_top_inst__imem_inst__1\n"); );
    Vhw3_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__hw3_tb__core_top_inst__imem_inst.RAM[0U] = 0x20080017U;
    vlSymsp->TOP__hw3_tb__core_top_inst__imem_inst.RAM[1U] = 0x2109002dU;
    vlSymsp->TOP__hw3_tb__core_top_inst__imem_inst.RAM[2U] = 0xac090008U;
    vlSymsp->TOP__hw3_tb__core_top_inst__imem_inst.RAM[3U] = 0x8c0a0008U;
    vlSymsp->TOP__hw3_tb__core_top_inst__imem_inst.RAM[4U] = 0x214bffd3U;
    vlSymsp->TOP__hw3_tb__core_top_inst__imem_inst.RAM[5U] = 0x110b0001U;
    vlSymsp->TOP__hw3_tb__core_top_inst__imem_inst.RAM[6U] = 0xac080000U;
    vlSymsp->TOP__hw3_tb__core_top_inst__imem_inst.RAM[7U] = 0x8100007U;
    vlSymsp->TOP__hw3_tb__core_top_inst__imem_inst.RAM[8U] = 0U;
    vlSymsp->TOP__hw3_tb__core_top_inst__imem_inst.RAM[9U] = 0U;
    vlSymsp->TOP__hw3_tb__core_top_inst__imem_inst.RAM[0xaU] = 0U;
    vlSymsp->TOP__hw3_tb__core_top_inst__imem_inst.RAM[0xbU] = 0U;
    vlSymsp->TOP__hw3_tb__core_top_inst__imem_inst.RAM[0xcU] = 0U;
    vlSymsp->TOP__hw3_tb__core_top_inst__imem_inst.RAM[0xdU] = 0U;
    vlSymsp->TOP__hw3_tb__core_top_inst__imem_inst.RAM[0xeU] = 0U;
    vlSymsp->TOP__hw3_tb__core_top_inst__imem_inst.RAM[0xfU] = 0U;
}

void Vhw3_tb_imem::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vhw3_tb_imem::_ctor_var_reset\n"); );
    // Body
    __PVT__addr = VL_RAND_RESET_I(6);
    __PVT__rdata = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<16; ++__Vi0) {
            RAM[__Vi0] = VL_RAND_RESET_I(32);
    }}
}
