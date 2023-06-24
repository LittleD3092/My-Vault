// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vhw3_tb.h for the primary calling header

#include "Vhw3_tb_dmem.h"
#include "Vhw3_tb__Syms.h"

#include "verilated_dpi.h"

//==========

VL_CTOR_IMP(Vhw3_tb_dmem) {
    // Reset internal values
    // Reset structure values
    _ctor_var_reset();
}

void Vhw3_tb_dmem::__Vconfigure(Vhw3_tb__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
}

Vhw3_tb_dmem::~Vhw3_tb_dmem() {
}

void Vhw3_tb_dmem::_initial__TOP__hw3_tb__core_top_inst__dmem_inst__2(Vhw3_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vhw3_tb_dmem::_initial__TOP__hw3_tb__core_top_inst__dmem_inst__2\n"); );
    Vhw3_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM[0U] = 0U;
    vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM[1U] = 0U;
    vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM[2U] = 0U;
    vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM[3U] = 0U;
    vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM[4U] = 0U;
    vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM[5U] = 0U;
    vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM[6U] = 0U;
    vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM[7U] = 0U;
    vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM[8U] = 0U;
    vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM[9U] = 0U;
    vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM[0xaU] = 0U;
    vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM[0xbU] = 0U;
    vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM[0xcU] = 0U;
    vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM[0xdU] = 0U;
    vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM[0xeU] = 0U;
    vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM[0xfU] = 0U;
    vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.__PVT__idx = 0x10U;
}

void Vhw3_tb_dmem::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vhw3_tb_dmem::_ctor_var_reset\n"); );
    // Body
    __PVT__clk = VL_RAND_RESET_I(1);
    __PVT__addr = VL_RAND_RESET_I(6);
    __PVT__we = VL_RAND_RESET_I(1);
    __PVT__wdata = VL_RAND_RESET_I(32);
    __PVT__rdata = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<16; ++__Vi0) {
            RAM[__Vi0] = VL_RAND_RESET_I(32);
    }}
    __PVT__idx = VL_RAND_RESET_I(32);
}
