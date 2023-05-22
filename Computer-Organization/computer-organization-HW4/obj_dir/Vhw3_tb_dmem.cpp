// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vhw3_tb.h for the primary calling header

#include "Vhw3_tb_dmem.h"
#include "Vhw3_tb__Syms.h"

#include "verilated_dpi.h"

//==========

VL_INLINE_OPT void Vhw3_tb_dmem::_sequent__TOP__hw3_tb__core_top_inst__dmem_inst__1(Vhw3_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vhw3_tb_dmem::_sequent__TOP__hw3_tb__core_top_inst__dmem_inst__1\n"); );
    Vhw3_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*3:0*/ __Vdlyvdim0__RAM__v0;
    CData/*0:0*/ __Vdlyvset__RAM__v0;
    IData/*31:0*/ __Vdlyvval__RAM__v0;
    // Body
    __Vdlyvset__RAM__v0 = 0U;
    if (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__ex_mem_we_dmem) {
        __Vdlyvval__RAM__v0 = vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__ex_mem_rs2_out;
        __Vdlyvset__RAM__v0 = 1U;
        __Vdlyvdim0__RAM__v0 = (0xfU & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__ex_mem_alu_out 
                                        >> 2U));
    }
    if (__Vdlyvset__RAM__v0) {
        vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM[__Vdlyvdim0__RAM__v0] 
            = __Vdlyvval__RAM__v0;
    }
}
