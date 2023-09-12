// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vhw3_tb.h for the primary calling header

#include "Vhw3_tb_hw3_tb.h"
#include "Vhw3_tb__Syms.h"

#include "verilated_dpi.h"

//==========

VL_CTOR_IMP(Vhw3_tb_hw3_tb) {
    VL_CELL(core_top_inst, Vhw3_tb_core_top);
    // Reset internal values
    // Reset structure values
    _ctor_var_reset();
}

void Vhw3_tb_hw3_tb::__Vconfigure(Vhw3_tb__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
}

Vhw3_tb_hw3_tb::~Vhw3_tb_hw3_tb() {
}

void Vhw3_tb_hw3_tb::_initial__TOP__hw3_tb__2(Vhw3_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vhw3_tb_hw3_tb::_initial__TOP__hw3_tb__2\n"); );
    Vhw3_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__hw3_tb.__PVT__cycle_count = 0U;
    vlSymsp->TOP__hw3_tb.finish = 0U;
    vlSymsp->TOP__hw3_tb.__PVT__start = 1U;
}

void Vhw3_tb_hw3_tb::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vhw3_tb_hw3_tb::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    rst = VL_RAND_RESET_I(1);
    finish = VL_RAND_RESET_I(1);
    __PVT__i = VL_RAND_RESET_I(32);
    __PVT__tmp = VL_RAND_RESET_I(32);
    __PVT__cycle_count = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<32; ++__Vi0) {
            __PVT__golden_reg[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<16; ++__Vi0) {
            __PVT__golden_dmem[__Vi0] = VL_RAND_RESET_I(32);
    }}
    __PVT__start = VL_RAND_RESET_I(1);
}
