// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vhw3_tb.h for the primary calling header

#include "Vhw3_tb.h"
#include "Vhw3_tb__Syms.h"

//==========

VL_CTOR_IMP(Vhw3_tb) {
    Vhw3_tb__Syms* __restrict vlSymsp = __VlSymsp = new Vhw3_tb__Syms(this, name());
    Vhw3_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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

void Vhw3_tb::_initial__TOP__1(Vhw3_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhw3_tb::_initial__TOP__1\n"); );
    Vhw3_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imem_inst__DOT__RAM[0U] = 0x20080017U;
    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imem_inst__DOT__RAM[1U] = 0x2109002dU;
    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imem_inst__DOT__RAM[2U] = 0xac090008U;
    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imem_inst__DOT__RAM[3U] = 0x8c0a0008U;
    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imem_inst__DOT__RAM[4U] = 0x214bffd3U;
    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imem_inst__DOT__RAM[5U] = 0x110b0001U;
    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imem_inst__DOT__RAM[6U] = 0xac080000U;
    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imem_inst__DOT__RAM[7U] = 0x8100007U;
    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imem_inst__DOT__RAM[8U] = 0U;
    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imem_inst__DOT__RAM[9U] = 0U;
    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imem_inst__DOT__RAM[0xaU] = 0U;
    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imem_inst__DOT__RAM[0xbU] = 0U;
    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imem_inst__DOT__RAM[0xcU] = 0U;
    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imem_inst__DOT__RAM[0xdU] = 0U;
    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imem_inst__DOT__RAM[0xeU] = 0U;
    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imem_inst__DOT__RAM[0xfU] = 0U;
    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM[0U] = 0U;
    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM[1U] = 0U;
    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM[2U] = 0U;
    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM[3U] = 0U;
    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM[4U] = 0U;
    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM[5U] = 0U;
    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM[6U] = 0U;
    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM[7U] = 0U;
    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM[8U] = 0U;
    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM[9U] = 0U;
    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM[0xaU] = 0U;
    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM[0xbU] = 0U;
    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM[0xcU] = 0U;
    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM[0xdU] = 0U;
    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM[0xeU] = 0U;
    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM[0xfU] = 0U;
    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__idx = 0x10U;
    vlTOPp->hw3_tb__DOT__cycle_count = 0U;
    vlTOPp->finish = 0U;
    vlTOPp->hw3_tb__DOT__start = 1U;
}

void Vhw3_tb::_settle__TOP__2(Vhw3_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhw3_tb::_settle__TOP__2\n"); );
    Vhw3_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((0x80000000U & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)) {
        vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__op 
            = ((0x40000000U & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                ? 0xfU : ((0x20000000U & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                           ? ((0x10000000U & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                               ? 0xfU : ((0x8000000U 
                                          & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                          ? ((0x4000000U 
                                              & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                              ? 2U : 0xfU)
                                          : 0xfU)) : 
                          ((0x10000000U & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                            ? 0xfU : ((0x8000000U & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                       ? ((0x4000000U 
                                           & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                           ? 2U : 0xfU)
                                       : 0xfU))));
        vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__rs2_id 
            = (0x1fU & ((0x40000000U & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                         ? 0U : ((0x20000000U & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                  ? ((0x10000000U & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                      ? 0U : ((0x8000000U 
                                               & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                               ? ((0x4000000U 
                                                   & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                   ? 
                                                  (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr 
                                                   >> 0x10U)
                                                   : 0U)
                                               : 0U))
                                  : 0U)));
        vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__ssel = 0U;
        vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__imm 
            = ((0x40000000U & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                ? 0U : ((0x20000000U & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                         ? ((0x10000000U & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                             ? 0U : ((0x8000000U & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                      ? ((0x4000000U 
                                          & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                          ? VL_EXTENDS_II(32,16, 
                                                          (0xffffU 
                                                           & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr))
                                          : 0U) : 0U))
                         : ((0x10000000U & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                             ? 0U : ((0x8000000U & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                      ? ((0x4000000U 
                                          & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                          ? VL_EXTENDS_II(32,16, 
                                                          (0xffffU 
                                                           & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr))
                                          : 0U) : 0U))));
        vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__jump_type = 0U;
        vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__jump_addr = 0U;
    } else {
        vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__op 
            = ((0x40000000U & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                ? 0xfU : ((0x20000000U & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                           ? ((0x10000000U & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                               ? 0xfU : ((0x8000000U 
                                          & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                          ? ((0x4000000U 
                                              & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                              ? 0xfU
                                              : 7U)
                                          : ((0x4000000U 
                                              & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                              ? 0xfU
                                              : 2U)))
                           : ((0x10000000U & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                               ? ((0x8000000U & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                   ? 0xfU : ((0x4000000U 
                                              & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                              ? 0xfU
                                              : 6U))
                               : ((0x8000000U & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                   ? ((0x4000000U & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                       ? 2U : 0xfU)
                                   : ((0x4000000U & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                       ? 0xfU : ((0x20U 
                                                  & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                  ? 
                                                 ((0x10U 
                                                   & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                   ? 0xfU
                                                   : 
                                                  ((8U 
                                                    & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                    ? 
                                                   ((4U 
                                                     & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                     ? 0xfU
                                                     : 
                                                    ((2U 
                                                      & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                      ? 
                                                     ((1U 
                                                       & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                       ? 0xfU
                                                       : 7U)
                                                      : 0xfU))
                                                    : 
                                                   ((4U 
                                                     & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                     ? 
                                                    ((2U 
                                                      & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                      ? 
                                                     ((1U 
                                                       & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                       ? 0xcU
                                                       : 0xfU)
                                                      : 
                                                     ((1U 
                                                       & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                       ? 1U
                                                       : 0U))
                                                     : 
                                                    ((2U 
                                                      & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                      ? 
                                                     ((1U 
                                                       & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                       ? 0xfU
                                                       : 6U)
                                                      : 
                                                     ((1U 
                                                       & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                       ? 0xfU
                                                       : 2U)))))
                                                  : 0xfU))))));
        vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__rs2_id 
            = (0x1fU & ((0x40000000U & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                         ? 0U : ((0x20000000U & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                  ? 0U : ((0x10000000U 
                                           & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                           ? ((0x8000000U 
                                               & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                               ? 0U
                                               : ((0x4000000U 
                                                   & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                   ? 0U
                                                   : 
                                                  (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr 
                                                   >> 0x10U)))
                                           : ((0x8000000U 
                                               & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                               ? 0U
                                               : ((0x4000000U 
                                                   & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                   ? 0U
                                                   : 
                                                  ((0x20U 
                                                    & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                    ? 
                                                   ((0x10U 
                                                     & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                     ? 0U
                                                     : 
                                                    ((8U 
                                                      & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                      ? 
                                                     ((4U 
                                                       & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                       ? 0U
                                                       : 
                                                      ((2U 
                                                        & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                        ? 
                                                       ((1U 
                                                         & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                         ? 0U
                                                         : 
                                                        (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr 
                                                         >> 0x10U))
                                                        : 0U))
                                                      : 
                                                     ((4U 
                                                       & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                       ? 
                                                      ((2U 
                                                        & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                        ? 
                                                       ((1U 
                                                         & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                         ? 
                                                        (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr 
                                                         >> 0x10U)
                                                         : 0U)
                                                        : 
                                                       ((1U 
                                                         & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                         ? 
                                                        (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr 
                                                         >> 0x10U)
                                                         : 
                                                        (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr 
                                                         >> 0x10U)))
                                                       : 
                                                      ((2U 
                                                        & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                        ? 
                                                       ((1U 
                                                         & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                         ? 0U
                                                         : 
                                                        (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr 
                                                         >> 0x10U))
                                                        : 
                                                       ((1U 
                                                         & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                         ? 0U
                                                         : 
                                                        (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr 
                                                         >> 0x10U))))))
                                                    : 0U)))))));
        vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__ssel 
            = ((0x40000000U & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                ? 0U : ((0x20000000U & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                         ? ((0x10000000U & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                             ? 0U : ((0x8000000U & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                      ? ((0x4000000U 
                                          & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                          ? 0U : 3U)
                                      : ((0x4000000U 
                                          & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                          ? 0U : 3U)))
                         : ((0x10000000U & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                             ? 0U : ((0x8000000U & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                      ? 0U : ((0x4000000U 
                                               & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                               ? 0U
                                               : ((0x20U 
                                                   & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                   ? 
                                                  ((0x10U 
                                                    & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                    ? 0U
                                                    : 
                                                   ((8U 
                                                     & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                     ? 
                                                    ((4U 
                                                      & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                      ? 0U
                                                      : 
                                                     ((2U 
                                                       & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                       ? 
                                                      ((1U 
                                                        & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                        ? 0U
                                                        : 1U)
                                                       : 0U))
                                                     : 
                                                    ((4U 
                                                      & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                      ? 
                                                     ((2U 
                                                       & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                       ? 
                                                      ((1U 
                                                        & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                        ? 1U
                                                        : 0U)
                                                       : 1U)
                                                      : 
                                                     ((2U 
                                                       & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                       ? 
                                                      ((1U 
                                                        & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                        ? 0U
                                                        : 1U)
                                                       : 
                                                      ((1U 
                                                        & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                        ? 0U
                                                        : 1U)))))
                                                   : 0U))))));
        vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__imm 
            = ((0x40000000U & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                ? 0U : ((0x20000000U & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                         ? ((0x10000000U & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                             ? 0U : ((0x8000000U & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                      ? ((0x4000000U 
                                          & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                          ? 0U : VL_EXTENDS_II(32,16, 
                                                               (0xffffU 
                                                                & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)))
                                      : ((0x4000000U 
                                          & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                          ? 0U : VL_EXTENDS_II(32,16, 
                                                               (0xffffU 
                                                                & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)))))
                         : ((0x10000000U & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                             ? ((0x8000000U & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                 ? 0U : ((0x4000000U 
                                          & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                          ? 0U : VL_EXTENDS_II(32,16, 
                                                               (0xffffU 
                                                                & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr))))
                             : 0U)));
        vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__jump_type 
            = ((0x40000000U & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                ? 0U : ((0x20000000U & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                         ? 0U : ((0x10000000U & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                  ? ((0x8000000U & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                      ? 0U : ((0x4000000U 
                                               & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                               ? 0U
                                               : 1U))
                                  : ((0x8000000U & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                      ? 2U : 0U))));
        vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__jump_addr 
            = ((0x40000000U & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                ? 0U : ((0x20000000U & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                         ? 0U : ((0x10000000U & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                  ? 0U : ((0x8000000U 
                                           & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                           ? ((0x4000000U 
                                               & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                               ? (0x3ffffffU 
                                                  & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                               : (0x3ffffffU 
                                                  & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr))
                                           : 0U))));
    }
    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__we_dmem 
        = (1U & ((vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr 
                  >> 0x1fU) & ((~ (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr 
                                   >> 0x1eU)) & ((vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr 
                                                  >> 0x1dU) 
                                                 & ((~ 
                                                     (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr 
                                                      >> 0x1cU)) 
                                                    & ((vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr 
                                                        >> 0x1bU) 
                                                       & (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr 
                                                          >> 0x1aU)))))));
    if ((0x80000000U & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)) {
        vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__we_regfile 
            = (1U & ((~ (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr 
                         >> 0x1eU)) & ((~ (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr 
                                           >> 0x1dU)) 
                                       & ((~ (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr 
                                              >> 0x1cU)) 
                                          & ((vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr 
                                              >> 0x1bU) 
                                             & (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr 
                                                >> 0x1aU))))));
        vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__rs1_id 
            = (0x1fU & ((0x40000000U & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                         ? 0U : ((0x20000000U & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                  ? ((0x10000000U & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                      ? 0U : ((0x8000000U 
                                               & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                               ? ((0x4000000U 
                                                   & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                   ? 
                                                  (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr 
                                                   >> 0x15U)
                                                   : 0U)
                                               : 0U))
                                  : ((0x10000000U & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                      ? 0U : ((0x8000000U 
                                               & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                               ? ((0x4000000U 
                                                   & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                   ? 
                                                  (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr 
                                                   >> 0x15U)
                                                   : 0U)
                                               : 0U)))));
        vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__rdst_id 
            = (0x1fU & ((0x40000000U & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                         ? 0U : ((0x20000000U & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                  ? 0U : ((0x10000000U 
                                           & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                           ? 0U : (
                                                   (0x8000000U 
                                                    & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                    ? 
                                                   ((0x4000000U 
                                                     & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                     ? 
                                                    (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr 
                                                     >> 0x10U)
                                                     : 0U)
                                                    : 0U)))));
    } else {
        vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__we_regfile 
            = (1U & ((~ (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr 
                         >> 0x1eU)) & ((0x20000000U 
                                        & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                        ? ((~ (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr 
                                               >> 0x1cU)) 
                                           & ((0x8000000U 
                                               & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                               ? (~ 
                                                  (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr 
                                                   >> 0x1aU))
                                               : (~ 
                                                  (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr 
                                                   >> 0x1aU))))
                                        : ((~ (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr 
                                               >> 0x1cU)) 
                                           & ((0x8000000U 
                                               & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                               ? (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr 
                                                  >> 0x1aU)
                                               : ((~ 
                                                   (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr 
                                                    >> 0x1aU)) 
                                                  & ((vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr 
                                                      >> 5U) 
                                                     & ((~ 
                                                         (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr 
                                                          >> 4U)) 
                                                        & ((8U 
                                                            & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                            ? 
                                                           ((~ 
                                                             (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr 
                                                              >> 2U)) 
                                                            & ((vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr 
                                                                >> 1U) 
                                                               & (~ vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)))
                                                            : 
                                                           ((4U 
                                                             & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                             ? 
                                                            ((~ 
                                                              (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr 
                                                               >> 1U)) 
                                                             | vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                             : 
                                                            ((2U 
                                                              & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                              ? 
                                                             (~ vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                              : 
                                                             (~ vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr))))))))))));
        vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__rs1_id 
            = (0x1fU & ((0x40000000U & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                         ? 0U : ((0x20000000U & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                  ? ((0x10000000U & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                      ? 0U : ((0x8000000U 
                                               & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                               ? ((0x4000000U 
                                                   & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                   ? 0U
                                                   : 
                                                  (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr 
                                                   >> 0x15U))
                                               : ((0x4000000U 
                                                   & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                   ? 0U
                                                   : 
                                                  (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr 
                                                   >> 0x15U))))
                                  : ((0x10000000U & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                      ? ((0x8000000U 
                                          & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                          ? 0U : ((0x4000000U 
                                                   & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                   ? 0U
                                                   : 
                                                  (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr 
                                                   >> 0x15U)))
                                      : ((0x8000000U 
                                          & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                          ? 0U : ((0x4000000U 
                                                   & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                   ? 0U
                                                   : 
                                                  ((0x20U 
                                                    & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                    ? 
                                                   ((0x10U 
                                                     & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                     ? 0U
                                                     : 
                                                    ((8U 
                                                      & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                      ? 
                                                     ((4U 
                                                       & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                       ? 0U
                                                       : 
                                                      ((2U 
                                                        & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                        ? 
                                                       ((1U 
                                                         & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                         ? 0U
                                                         : 
                                                        (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr 
                                                         >> 0x15U))
                                                        : 0U))
                                                      : 
                                                     ((4U 
                                                       & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                       ? 
                                                      ((2U 
                                                        & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                        ? 
                                                       ((1U 
                                                         & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                         ? 
                                                        (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr 
                                                         >> 0x15U)
                                                         : 0U)
                                                        : 
                                                       ((1U 
                                                         & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                         ? 
                                                        (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr 
                                                         >> 0x15U)
                                                         : 
                                                        (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr 
                                                         >> 0x15U)))
                                                       : 
                                                      ((2U 
                                                        & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                        ? 
                                                       ((1U 
                                                         & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                         ? 0U
                                                         : 
                                                        (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr 
                                                         >> 0x15U))
                                                        : 
                                                       ((1U 
                                                         & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                         ? 0U
                                                         : 
                                                        (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr 
                                                         >> 0x15U))))))
                                                    : 
                                                   ((0x10U 
                                                     & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                     ? 0U
                                                     : 
                                                    ((8U 
                                                      & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                      ? 
                                                     ((4U 
                                                       & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                       ? 0U
                                                       : 
                                                      ((2U 
                                                        & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                        ? 0U
                                                        : 
                                                       ((1U 
                                                         & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                         ? 0U
                                                         : 
                                                        (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr 
                                                         >> 0x15U))))
                                                      : 0U)))))))));
        vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__rdst_id 
            = (0x1fU & ((0x40000000U & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                         ? 0U : ((0x20000000U & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                  ? ((0x10000000U & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                      ? 0U : ((0x8000000U 
                                               & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                               ? ((0x4000000U 
                                                   & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                   ? 0U
                                                   : 
                                                  (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr 
                                                   >> 0x10U))
                                               : ((0x4000000U 
                                                   & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                   ? 0U
                                                   : 
                                                  (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr 
                                                   >> 0x10U))))
                                  : ((0x10000000U & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                      ? 0U : ((0x8000000U 
                                               & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                               ? ((0x4000000U 
                                                   & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                   ? 
                                                  (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr 
                                                   >> 0x10U)
                                                   : 0U)
                                               : ((0x4000000U 
                                                   & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                   ? 0U
                                                   : 
                                                  ((0x20U 
                                                    & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                    ? 
                                                   ((0x10U 
                                                     & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                     ? 0U
                                                     : 
                                                    ((8U 
                                                      & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                      ? 
                                                     ((4U 
                                                       & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                       ? 0U
                                                       : 
                                                      ((2U 
                                                        & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                        ? 
                                                       ((1U 
                                                         & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                         ? 0U
                                                         : 
                                                        (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr 
                                                         >> 0xbU))
                                                        : 0U))
                                                      : 
                                                     ((4U 
                                                       & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                       ? 
                                                      ((2U 
                                                        & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                        ? 
                                                       ((1U 
                                                         & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                         ? 
                                                        (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr 
                                                         >> 0xbU)
                                                         : 0U)
                                                        : 
                                                       ((1U 
                                                         & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                         ? 
                                                        (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr 
                                                         >> 0xbU)
                                                         : 
                                                        (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr 
                                                         >> 0xbU)))
                                                       : 
                                                      ((2U 
                                                        & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                        ? 
                                                       ((1U 
                                                         & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                         ? 0U
                                                         : 
                                                        (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr 
                                                         >> 0xbU))
                                                        : 
                                                       ((1U 
                                                         & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr)
                                                         ? 0U
                                                         : 
                                                        (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr 
                                                         >> 0xbU))))))
                                                    : 0U)))))));
    }
    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__alu_inst__DOT__overflow = 0U;
    if ((8U & (IData)(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__alu_inst__DOT__op))) {
        vlTOPp->hw3_tb__DOT__core_top_inst__DOT__alu_inst__DOT__rd 
            = ((4U & (IData)(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__alu_inst__DOT__op))
                ? ((2U & (IData)(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__alu_inst__DOT__op))
                    ? 0U : ((1U & (IData)(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__alu_inst__DOT__op))
                             ? 0U : (~ (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__alu_inst__DOT__rs1 
                                        | vlTOPp->hw3_tb__DOT__core_top_inst__DOT__alu_inst__DOT__rs2))))
                : 0U);
    } else {
        if ((4U & (IData)(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__alu_inst__DOT__op))) {
            if ((2U & (IData)(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__alu_inst__DOT__op))) {
                if ((1U & (IData)(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__alu_inst__DOT__op))) {
                    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__alu_inst__DOT__rd 
                        = (VL_LTS_III(1,32,32, vlTOPp->hw3_tb__DOT__core_top_inst__DOT__alu_inst__DOT__rs1, vlTOPp->hw3_tb__DOT__core_top_inst__DOT__alu_inst__DOT__rs2)
                            ? 1U : 0U);
                } else {
                    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__alu_inst__DOT__rd 
                        = (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__alu_inst__DOT__rs1 
                           - vlTOPp->hw3_tb__DOT__core_top_inst__DOT__alu_inst__DOT__rs2);
                    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__alu_inst__DOT__overflow 
                        = (((1U & (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__alu_inst__DOT__rs1 
                                   >> 0x1fU)) != (1U 
                                                  & (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__alu_inst__DOT__rs2 
                                                     >> 0x1fU))) 
                           & ((1U & (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__alu_inst__DOT__rs1 
                                     >> 0x1fU)) != 
                              (1U & (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__alu_inst__DOT__rd 
                                     >> 0x1fU))));
                }
            } else {
                vlTOPp->hw3_tb__DOT__core_top_inst__DOT__alu_inst__DOT__rd = 0U;
            }
        } else {
            if ((2U & (IData)(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__alu_inst__DOT__op))) {
                if ((1U & (IData)(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__alu_inst__DOT__op))) {
                    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__alu_inst__DOT__rd = 0U;
                } else {
                    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__alu_inst__DOT__rd 
                        = (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__alu_inst__DOT__rs1 
                           + vlTOPp->hw3_tb__DOT__core_top_inst__DOT__alu_inst__DOT__rs2);
                    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__alu_inst__DOT__overflow 
                        = (((1U & (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__alu_inst__DOT__rs1 
                                   >> 0x1fU)) == (1U 
                                                  & (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__alu_inst__DOT__rs2 
                                                     >> 0x1fU))) 
                           & ((1U & (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__alu_inst__DOT__rs1 
                                     >> 0x1fU)) != 
                              (1U & (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__alu_inst__DOT__rd 
                                     >> 0x1fU))));
                }
            } else {
                vlTOPp->hw3_tb__DOT__core_top_inst__DOT__alu_inst__DOT__rd 
                    = ((1U & (IData)(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__alu_inst__DOT__op))
                        ? (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__alu_inst__DOT__rs1 
                           | vlTOPp->hw3_tb__DOT__core_top_inst__DOT__alu_inst__DOT__rs2)
                        : (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__alu_inst__DOT__rs1 
                           & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__alu_inst__DOT__rs2));
            }
        }
    }
    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__alu_inst__DOT__zero 
        = ((0U == vlTOPp->hw3_tb__DOT__core_top_inst__DOT__alu_inst__DOT__rd)
            ? 1U : 0U);
}

void Vhw3_tb::_eval_initial(Vhw3_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhw3_tb::_eval_initial\n"); );
    Vhw3_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vm_traceActivity[4U] = 1U;
    vlTOPp->__Vm_traceActivity[3U] = 1U;
    vlTOPp->__Vm_traceActivity[2U] = 1U;
    vlTOPp->__Vm_traceActivity[1U] = 1U;
    vlTOPp->__Vm_traceActivity[0U] = 1U;
    vlTOPp->__Vclklast__TOP__hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__rst 
        = vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__rst;
    vlTOPp->__Vclklast__TOP__hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__clk 
        = vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__clk;
    vlTOPp->__Vclklast__TOP__hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__clk 
        = vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__clk;
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
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
    vlTOPp->_settle__TOP__2(vlSymsp);
    vlTOPp->__Vm_traceActivity[4U] = 1U;
    vlTOPp->__Vm_traceActivity[3U] = 1U;
    vlTOPp->__Vm_traceActivity[2U] = 1U;
    vlTOPp->__Vm_traceActivity[1U] = 1U;
    vlTOPp->__Vm_traceActivity[0U] = 1U;
}

void Vhw3_tb::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhw3_tb::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    rst = VL_RAND_RESET_I(1);
    finish = VL_RAND_RESET_I(1);
    hw3_tb__DOT__i = VL_RAND_RESET_I(32);
    hw3_tb__DOT__tmp = VL_RAND_RESET_I(32);
    hw3_tb__DOT__cycle_count = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<32; ++__Vi0) {
            hw3_tb__DOT__golden_reg[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<16; ++__Vi0) {
            hw3_tb__DOT__golden_dmem[__Vi0] = VL_RAND_RESET_I(32);
    }}
    hw3_tb__DOT__start = VL_RAND_RESET_I(1);
    hw3_tb__DOT__core_top_inst__DOT__pc = VL_RAND_RESET_I(32);
    hw3_tb__DOT__core_top_inst__DOT__imem_inst__DOT__addr = VL_RAND_RESET_I(6);
    { int __Vi0=0; for (; __Vi0<16; ++__Vi0) {
            hw3_tb__DOT__core_top_inst__DOT__imem_inst__DOT__RAM[__Vi0] = VL_RAND_RESET_I(32);
    }}
    hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr = VL_RAND_RESET_I(32);
    hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__jump_type = VL_RAND_RESET_I(2);
    hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__jump_addr = VL_RAND_RESET_I(32);
    hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__we_dmem = VL_RAND_RESET_I(1);
    hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__we_regfile = VL_RAND_RESET_I(1);
    hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__op = VL_RAND_RESET_I(4);
    hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__ssel = VL_RAND_RESET_I(2);
    hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__imm = VL_RAND_RESET_I(32);
    hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__rs1_id = VL_RAND_RESET_I(5);
    hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__rs2_id = VL_RAND_RESET_I(5);
    hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__rdst_id = VL_RAND_RESET_I(5);
    hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__clk = VL_RAND_RESET_I(1);
    hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__rst = VL_RAND_RESET_I(1);
    hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__rs1_id = VL_RAND_RESET_I(5);
    hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__rs2_id = VL_RAND_RESET_I(5);
    hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__we = VL_RAND_RESET_I(1);
    hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__rdst_id = VL_RAND_RESET_I(5);
    hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__rdst = VL_RAND_RESET_I(32);
    hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__rs1 = VL_RAND_RESET_I(32);
    hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__rs2 = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<32; ++__Vi0) {
            hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[__Vi0] = VL_RAND_RESET_I(32);
    }}
    hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__unnamedblk1__DOT__i = 0;
    hw3_tb__DOT__core_top_inst__DOT__alu_inst__DOT__op = VL_RAND_RESET_I(4);
    hw3_tb__DOT__core_top_inst__DOT__alu_inst__DOT__rs1 = VL_RAND_RESET_I(32);
    hw3_tb__DOT__core_top_inst__DOT__alu_inst__DOT__rs2 = VL_RAND_RESET_I(32);
    hw3_tb__DOT__core_top_inst__DOT__alu_inst__DOT__rd = VL_RAND_RESET_I(32);
    hw3_tb__DOT__core_top_inst__DOT__alu_inst__DOT__zero = VL_RAND_RESET_I(1);
    hw3_tb__DOT__core_top_inst__DOT__alu_inst__DOT__overflow = VL_RAND_RESET_I(1);
    hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__clk = VL_RAND_RESET_I(1);
    hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__addr = VL_RAND_RESET_I(6);
    hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__we = VL_RAND_RESET_I(1);
    hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__wdata = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<16; ++__Vi0) {
            hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM[__Vi0] = VL_RAND_RESET_I(32);
    }}
    hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__idx = VL_RAND_RESET_I(32);
    __Vdlyvdim0__hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM__v0 = 0;
    __Vdlyvval__hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM__v0 = VL_RAND_RESET_I(32);
    __Vdlyvset__hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM__v0 = 0;
    { int __Vi0=0; for (; __Vi0<5; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}
