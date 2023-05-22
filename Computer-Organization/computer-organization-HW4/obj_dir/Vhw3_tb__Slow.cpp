// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vhw3_tb.h for the primary calling header

#include "Vhw3_tb.h"
#include "Vhw3_tb__Syms.h"

#include "verilated_dpi.h"

//==========

VL_CTOR_IMP(Vhw3_tb) {
    Vhw3_tb__Syms* __restrict vlSymsp = __VlSymsp = new Vhw3_tb__Syms(this, name());
    Vhw3_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    VL_CELL(hw3_tb, Vhw3_tb_hw3_tb);
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vhw3_tb::__Vconfigure(Vhw3_tb__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vhw3_tb::~Vhw3_tb() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vhw3_tb::_eval_initial(Vhw3_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhw3_tb::_eval_initial\n"); );
    Vhw3_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlSymsp->TOP__hw3_tb._initial__TOP__hw3_tb__2(vlSymsp);
    vlTOPp->__Vm_traceActivity[2U] = 1U;
    vlTOPp->__Vm_traceActivity[1U] = 1U;
    vlTOPp->__Vm_traceActivity[0U] = 1U;
    vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst._initial__TOP__hw3_tb__core_top_inst__dmem_inst__2(vlSymsp);
    vlSymsp->TOP__hw3_tb__core_top_inst__imem_inst._initial__TOP__hw3_tb__core_top_inst__imem_inst__1(vlSymsp);
}

void Vhw3_tb::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhw3_tb::final\n"); );
    // Variables
    Vhw3_tb__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vhw3_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vhw3_tb::_eval_settle(Vhw3_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhw3_tb::_eval_settle\n"); );
    Vhw3_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__hw3_tb__core_top_inst._settle__TOP__hw3_tb__core_top_inst__3(vlSymsp);
    vlTOPp->__Vm_traceActivity[2U] = 1U;
    vlTOPp->__Vm_traceActivity[1U] = 1U;
    vlTOPp->__Vm_traceActivity[0U] = 1U;
    vlTOPp->_sequent__TOP__1(vlSymsp);
}

void Vhw3_tb::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhw3_tb::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    rst = VL_RAND_RESET_I(1);
    finish = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<3; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}
