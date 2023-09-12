// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdecode_tb.h for the primary calling header

#include "Vdecode_tb.h"
#include "Vdecode_tb__Syms.h"

//==========

VL_CTOR_IMP(Vdecode_tb) {
    Vdecode_tb__Syms* __restrict vlSymsp = __VlSymsp = new Vdecode_tb__Syms(this, name());
    Vdecode_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vdecode_tb::__Vconfigure(Vdecode_tb__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-9);
    Verilated::timeprecision(-12);
}

Vdecode_tb::~Vdecode_tb() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vdecode_tb::_settle__TOP__4(Vdecode_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecode_tb::_settle__TOP__4\n"); );
    Vdecode_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((0U == (0x3fU & (vlTOPp->decode_tb__DOT__instr 
                         >> 0x1aU)))) {
        vlTOPp->decode_tb__DOT__rdst_id = (0x1fU & 
                                           ((0x20U 
                                             & vlTOPp->decode_tb__DOT__instr)
                                             ? ((0x10U 
                                                 & vlTOPp->decode_tb__DOT__instr)
                                                 ? 0U
                                                 : 
                                                ((8U 
                                                  & vlTOPp->decode_tb__DOT__instr)
                                                  ? 
                                                 ((4U 
                                                   & vlTOPp->decode_tb__DOT__instr)
                                                   ? 0U
                                                   : 
                                                  ((2U 
                                                    & vlTOPp->decode_tb__DOT__instr)
                                                    ? 
                                                   ((1U 
                                                     & vlTOPp->decode_tb__DOT__instr)
                                                     ? 0U
                                                     : 
                                                    (vlTOPp->decode_tb__DOT__instr 
                                                     >> 0xbU))
                                                    : 0U))
                                                  : 
                                                 ((4U 
                                                   & vlTOPp->decode_tb__DOT__instr)
                                                   ? 
                                                  ((2U 
                                                    & vlTOPp->decode_tb__DOT__instr)
                                                    ? 
                                                   ((1U 
                                                     & vlTOPp->decode_tb__DOT__instr)
                                                     ? 
                                                    (vlTOPp->decode_tb__DOT__instr 
                                                     >> 0xbU)
                                                     : 0U)
                                                    : 
                                                   ((1U 
                                                     & vlTOPp->decode_tb__DOT__instr)
                                                     ? 
                                                    (vlTOPp->decode_tb__DOT__instr 
                                                     >> 0xbU)
                                                     : 
                                                    (vlTOPp->decode_tb__DOT__instr 
                                                     >> 0xbU)))
                                                   : 
                                                  ((2U 
                                                    & vlTOPp->decode_tb__DOT__instr)
                                                    ? 
                                                   ((1U 
                                                     & vlTOPp->decode_tb__DOT__instr)
                                                     ? 0U
                                                     : 
                                                    (vlTOPp->decode_tb__DOT__instr 
                                                     >> 0xbU))
                                                    : 
                                                   ((1U 
                                                     & vlTOPp->decode_tb__DOT__instr)
                                                     ? 0U
                                                     : 
                                                    (vlTOPp->decode_tb__DOT__instr 
                                                     >> 0xbU))))))
                                             : 0U));
        vlTOPp->decode_tb__DOT__rs2_id = ((0x20U & vlTOPp->decode_tb__DOT__instr)
                                           ? ((0x10U 
                                               & vlTOPp->decode_tb__DOT__instr)
                                               ? 0U
                                               : (0x1fU 
                                                  & ((8U 
                                                      & vlTOPp->decode_tb__DOT__instr)
                                                      ? 
                                                     ((4U 
                                                       & vlTOPp->decode_tb__DOT__instr)
                                                       ? 0U
                                                       : 
                                                      ((2U 
                                                        & vlTOPp->decode_tb__DOT__instr)
                                                        ? 
                                                       ((1U 
                                                         & vlTOPp->decode_tb__DOT__instr)
                                                         ? 0U
                                                         : 
                                                        (vlTOPp->decode_tb__DOT__instr 
                                                         >> 0x10U))
                                                        : 0U))
                                                      : 
                                                     ((4U 
                                                       & vlTOPp->decode_tb__DOT__instr)
                                                       ? 
                                                      ((2U 
                                                        & vlTOPp->decode_tb__DOT__instr)
                                                        ? 
                                                       ((1U 
                                                         & vlTOPp->decode_tb__DOT__instr)
                                                         ? 
                                                        (vlTOPp->decode_tb__DOT__instr 
                                                         >> 0x10U)
                                                         : 0U)
                                                        : 
                                                       ((1U 
                                                         & vlTOPp->decode_tb__DOT__instr)
                                                         ? 
                                                        (vlTOPp->decode_tb__DOT__instr 
                                                         >> 0x10U)
                                                         : 
                                                        (vlTOPp->decode_tb__DOT__instr 
                                                         >> 0x10U)))
                                                       : 
                                                      ((2U 
                                                        & vlTOPp->decode_tb__DOT__instr)
                                                        ? 
                                                       ((1U 
                                                         & vlTOPp->decode_tb__DOT__instr)
                                                         ? 0U
                                                         : 
                                                        (vlTOPp->decode_tb__DOT__instr 
                                                         >> 0x10U))
                                                        : 
                                                       ((1U 
                                                         & vlTOPp->decode_tb__DOT__instr)
                                                         ? 0U
                                                         : 
                                                        (vlTOPp->decode_tb__DOT__instr 
                                                         >> 0x10U)))))))
                                           : 0U);
        vlTOPp->decode_tb__DOT__rs1_id = (0x1fU & (
                                                   (0x20U 
                                                    & vlTOPp->decode_tb__DOT__instr)
                                                    ? 
                                                   ((0x10U 
                                                     & vlTOPp->decode_tb__DOT__instr)
                                                     ? 0U
                                                     : 
                                                    ((8U 
                                                      & vlTOPp->decode_tb__DOT__instr)
                                                      ? 
                                                     ((4U 
                                                       & vlTOPp->decode_tb__DOT__instr)
                                                       ? 0U
                                                       : 
                                                      ((2U 
                                                        & vlTOPp->decode_tb__DOT__instr)
                                                        ? 
                                                       ((1U 
                                                         & vlTOPp->decode_tb__DOT__instr)
                                                         ? 0U
                                                         : 
                                                        (vlTOPp->decode_tb__DOT__instr 
                                                         >> 0x15U))
                                                        : 0U))
                                                      : 
                                                     ((4U 
                                                       & vlTOPp->decode_tb__DOT__instr)
                                                       ? 
                                                      ((2U 
                                                        & vlTOPp->decode_tb__DOT__instr)
                                                        ? 
                                                       ((1U 
                                                         & vlTOPp->decode_tb__DOT__instr)
                                                         ? 
                                                        (vlTOPp->decode_tb__DOT__instr 
                                                         >> 0x15U)
                                                         : 0U)
                                                        : 
                                                       ((1U 
                                                         & vlTOPp->decode_tb__DOT__instr)
                                                         ? 
                                                        (vlTOPp->decode_tb__DOT__instr 
                                                         >> 0x15U)
                                                         : 
                                                        (vlTOPp->decode_tb__DOT__instr 
                                                         >> 0x15U)))
                                                       : 
                                                      ((2U 
                                                        & vlTOPp->decode_tb__DOT__instr)
                                                        ? 
                                                       ((1U 
                                                         & vlTOPp->decode_tb__DOT__instr)
                                                         ? 0U
                                                         : 
                                                        (vlTOPp->decode_tb__DOT__instr 
                                                         >> 0x15U))
                                                        : 
                                                       ((1U 
                                                         & vlTOPp->decode_tb__DOT__instr)
                                                         ? 0U
                                                         : 
                                                        (vlTOPp->decode_tb__DOT__instr 
                                                         >> 0x15U))))))
                                                    : 0U));
        vlTOPp->decode_tb__DOT__op = ((0x20U & vlTOPp->decode_tb__DOT__instr)
                                       ? ((0x10U & vlTOPp->decode_tb__DOT__instr)
                                           ? 0xfU : 
                                          ((8U & vlTOPp->decode_tb__DOT__instr)
                                            ? ((4U 
                                                & vlTOPp->decode_tb__DOT__instr)
                                                ? 0xfU
                                                : (
                                                   (2U 
                                                    & vlTOPp->decode_tb__DOT__instr)
                                                    ? 
                                                   ((1U 
                                                     & vlTOPp->decode_tb__DOT__instr)
                                                     ? 0xfU
                                                     : 7U)
                                                    : 0xfU))
                                            : ((4U 
                                                & vlTOPp->decode_tb__DOT__instr)
                                                ? (
                                                   (2U 
                                                    & vlTOPp->decode_tb__DOT__instr)
                                                    ? 
                                                   ((1U 
                                                     & vlTOPp->decode_tb__DOT__instr)
                                                     ? 0xcU
                                                     : 0xfU)
                                                    : 
                                                   ((1U 
                                                     & vlTOPp->decode_tb__DOT__instr)
                                                     ? 1U
                                                     : 0U))
                                                : (
                                                   (2U 
                                                    & vlTOPp->decode_tb__DOT__instr)
                                                    ? 
                                                   ((1U 
                                                     & vlTOPp->decode_tb__DOT__instr)
                                                     ? 0xfU
                                                     : 6U)
                                                    : 
                                                   ((1U 
                                                     & vlTOPp->decode_tb__DOT__instr)
                                                     ? 0xfU
                                                     : 2U)))))
                                       : 0xfU);
        vlTOPp->decode_tb__DOT__imm = 0U;
        vlTOPp->decode_tb__DOT__ssel = (((vlTOPp->decode_tb__DOT__instr 
                                          >> 5U) & 
                                         ((~ (vlTOPp->decode_tb__DOT__instr 
                                              >> 4U)) 
                                          & ((8U & vlTOPp->decode_tb__DOT__instr)
                                              ? ((~ 
                                                  (vlTOPp->decode_tb__DOT__instr 
                                                   >> 2U)) 
                                                 & ((vlTOPp->decode_tb__DOT__instr 
                                                     >> 1U) 
                                                    & (~ vlTOPp->decode_tb__DOT__instr)))
                                              : ((4U 
                                                  & vlTOPp->decode_tb__DOT__instr)
                                                  ? 
                                                 ((~ 
                                                   (vlTOPp->decode_tb__DOT__instr 
                                                    >> 1U)) 
                                                  | vlTOPp->decode_tb__DOT__instr)
                                                  : 
                                                 ((2U 
                                                   & vlTOPp->decode_tb__DOT__instr)
                                                   ? 
                                                  (~ vlTOPp->decode_tb__DOT__instr)
                                                   : 
                                                  (~ vlTOPp->decode_tb__DOT__instr)))))) 
                                        & 1U);
    } else {
        vlTOPp->decode_tb__DOT__rdst_id = (0x1fU & 
                                           ((8U == 
                                             (0x3fU 
                                              & (vlTOPp->decode_tb__DOT__instr 
                                                 >> 0x1aU)))
                                             ? (vlTOPp->decode_tb__DOT__instr 
                                                >> 0x10U)
                                             : ((0xaU 
                                                 == 
                                                 (0x3fU 
                                                  & (vlTOPp->decode_tb__DOT__instr 
                                                     >> 0x1aU)))
                                                 ? 
                                                (vlTOPp->decode_tb__DOT__instr 
                                                 >> 0x10U)
                                                 : 0U)));
        vlTOPp->decode_tb__DOT__rs2_id = 0U;
        vlTOPp->decode_tb__DOT__rs1_id = (0x1fU & (
                                                   (8U 
                                                    == 
                                                    (0x3fU 
                                                     & (vlTOPp->decode_tb__DOT__instr 
                                                        >> 0x1aU)))
                                                    ? 
                                                   (vlTOPp->decode_tb__DOT__instr 
                                                    >> 0x15U)
                                                    : 
                                                   ((0xaU 
                                                     == 
                                                     (0x3fU 
                                                      & (vlTOPp->decode_tb__DOT__instr 
                                                         >> 0x1aU)))
                                                     ? 
                                                    (vlTOPp->decode_tb__DOT__instr 
                                                     >> 0x15U)
                                                     : 0U)));
        vlTOPp->decode_tb__DOT__op = ((8U == (0x3fU 
                                              & (vlTOPp->decode_tb__DOT__instr 
                                                 >> 0x1aU)))
                                       ? 2U : ((0xaU 
                                                == 
                                                (0x3fU 
                                                 & (vlTOPp->decode_tb__DOT__instr 
                                                    >> 0x1aU)))
                                                ? 7U
                                                : 0xfU));
        vlTOPp->decode_tb__DOT__imm = ((8U == (0x3fU 
                                               & (vlTOPp->decode_tb__DOT__instr 
                                                  >> 0x1aU)))
                                        ? VL_EXTENDS_II(32,16, 
                                                        (0xffffU 
                                                         & vlTOPp->decode_tb__DOT__instr))
                                        : ((0xaU == 
                                            (0x3fU 
                                             & (vlTOPp->decode_tb__DOT__instr 
                                                >> 0x1aU)))
                                            ? VL_EXTENDS_II(32,16, 
                                                            (0xffffU 
                                                             & vlTOPp->decode_tb__DOT__instr))
                                            : 0U));
        vlTOPp->decode_tb__DOT__ssel = 0U;
    }
    vlTOPp->decode_tb__DOT__rs2 = ((IData)(vlTOPp->decode_tb__DOT__ssel)
                                    ? vlTOPp->decode_tb__DOT__rs2_reg_file_out
                                    : vlTOPp->decode_tb__DOT__imm);
    vlTOPp->decode_tb__DOT__overflow = 0U;
    if ((8U & (IData)(vlTOPp->decode_tb__DOT__op))) {
        vlTOPp->decode_tb__DOT__rd = ((4U & (IData)(vlTOPp->decode_tb__DOT__op))
                                       ? ((2U & (IData)(vlTOPp->decode_tb__DOT__op))
                                           ? 0U : (
                                                   (1U 
                                                    & (IData)(vlTOPp->decode_tb__DOT__op))
                                                    ? 0U
                                                    : 
                                                   (~ 
                                                    (vlTOPp->decode_tb__DOT__rs1 
                                                     | vlTOPp->decode_tb__DOT__rs2))))
                                       : 0U);
    } else {
        if ((4U & (IData)(vlTOPp->decode_tb__DOT__op))) {
            if ((2U & (IData)(vlTOPp->decode_tb__DOT__op))) {
                if ((1U & (IData)(vlTOPp->decode_tb__DOT__op))) {
                    vlTOPp->decode_tb__DOT__rd = (VL_LTS_III(1,32,32, vlTOPp->decode_tb__DOT__rs1, vlTOPp->decode_tb__DOT__rs2)
                                                   ? 1U
                                                   : 0U);
                } else {
                    vlTOPp->decode_tb__DOT__rd = (vlTOPp->decode_tb__DOT__rs1 
                                                  - vlTOPp->decode_tb__DOT__rs2);
                    vlTOPp->decode_tb__DOT__overflow 
                        = (((1U & (vlTOPp->decode_tb__DOT__rs1 
                                   >> 0x1fU)) != (1U 
                                                  & (vlTOPp->decode_tb__DOT__rs2 
                                                     >> 0x1fU))) 
                           & ((1U & (vlTOPp->decode_tb__DOT__rs1 
                                     >> 0x1fU)) != 
                              (1U & (vlTOPp->decode_tb__DOT__rd 
                                     >> 0x1fU))));
                }
            } else {
                vlTOPp->decode_tb__DOT__rd = 0U;
            }
        } else {
            if ((2U & (IData)(vlTOPp->decode_tb__DOT__op))) {
                if ((1U & (IData)(vlTOPp->decode_tb__DOT__op))) {
                    vlTOPp->decode_tb__DOT__rd = 0U;
                } else {
                    vlTOPp->decode_tb__DOT__rd = (vlTOPp->decode_tb__DOT__rs1 
                                                  + vlTOPp->decode_tb__DOT__rs2);
                    vlTOPp->decode_tb__DOT__overflow 
                        = (((1U & (vlTOPp->decode_tb__DOT__rs1 
                                   >> 0x1fU)) == (1U 
                                                  & (vlTOPp->decode_tb__DOT__rs2 
                                                     >> 0x1fU))) 
                           & ((1U & (vlTOPp->decode_tb__DOT__rs1 
                                     >> 0x1fU)) != 
                              (1U & (vlTOPp->decode_tb__DOT__rd 
                                     >> 0x1fU))));
                }
            } else {
                vlTOPp->decode_tb__DOT__rd = ((1U & (IData)(vlTOPp->decode_tb__DOT__op))
                                               ? (vlTOPp->decode_tb__DOT__rs1 
                                                  | vlTOPp->decode_tb__DOT__rs2)
                                               : (vlTOPp->decode_tb__DOT__rs1 
                                                  & vlTOPp->decode_tb__DOT__rs2));
            }
        }
    }
    vlTOPp->decode_tb__DOT__zero = ((0U == vlTOPp->decode_tb__DOT__rd)
                                     ? 1U : 0U);
}

void Vdecode_tb::_initial__TOP__5(Vdecode_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecode_tb::_initial__TOP__5\n"); );
    Vdecode_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    WData/*95:0*/ __Vtemp2[3];
    WData/*95:0*/ __Vtemp3[3];
    // Body
    VL_WRITEF("HIHI I'm testbench of HW2 ^u^ <3\n");
    vlTOPp->decode_tb__DOT__pat_num = 0U;
    __Vtemp2[0U] = 0x2e747874U;
    __Vtemp2[1U] = 0x6e707574U;
    __Vtemp2[2U] = 0x69U;
    vlTOPp->decode_tb__DOT__pattern = VL_FOPEN_NN(VL_CVT_PACK_STR_NW(3, __Vtemp2)
                                                  , 
                                                  std::string("r"));
    __Vtemp3[0U] = 0x2e747874U;
    __Vtemp3[1U] = 0x66696c65U;
    __Vtemp3[2U] = 0x7265675fU;
    vlTOPp->decode_tb__DOT__reg_pattern = VL_FOPEN_NN(
                                                      VL_CVT_PACK_STR_NW(3, __Vtemp3)
                                                      , 
                                                      std::string("r"));
    vlTOPp->finish = 0U;
}

void Vdecode_tb::_eval_initial(Vdecode_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecode_tb::_eval_initial\n"); );
    Vdecode_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__rst = vlTOPp->rst;
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->_initial__TOP__5(vlSymsp);
    vlTOPp->__Vm_traceActivity[3U] = 1U;
    vlTOPp->__Vm_traceActivity[2U] = 1U;
    vlTOPp->__Vm_traceActivity[1U] = 1U;
    vlTOPp->__Vm_traceActivity[0U] = 1U;
}

void Vdecode_tb::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecode_tb::final\n"); );
    // Variables
    Vdecode_tb__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vdecode_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vdecode_tb::_eval_settle(Vdecode_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecode_tb::_eval_settle\n"); );
    Vdecode_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__4(vlSymsp);
    vlTOPp->__Vm_traceActivity[3U] = 1U;
    vlTOPp->__Vm_traceActivity[2U] = 1U;
    vlTOPp->__Vm_traceActivity[1U] = 1U;
    vlTOPp->__Vm_traceActivity[0U] = 1U;
}

void Vdecode_tb::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecode_tb::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    rst = VL_RAND_RESET_I(1);
    finish = VL_RAND_RESET_I(1);
    decode_tb__DOT__instr = VL_RAND_RESET_I(32);
    decode_tb__DOT__op = VL_RAND_RESET_I(4);
    decode_tb__DOT__ssel = VL_RAND_RESET_I(1);
    decode_tb__DOT__imm = VL_RAND_RESET_I(32);
    decode_tb__DOT__rs1_id = VL_RAND_RESET_I(5);
    decode_tb__DOT__rs2_id = VL_RAND_RESET_I(5);
    decode_tb__DOT__rdst_id = VL_RAND_RESET_I(5);
    decode_tb__DOT__rs2_reg_file_out = VL_RAND_RESET_I(32);
    decode_tb__DOT__rd = VL_RAND_RESET_I(32);
    decode_tb__DOT__rs1 = VL_RAND_RESET_I(32);
    decode_tb__DOT__rs2 = VL_RAND_RESET_I(32);
    decode_tb__DOT__zero = VL_RAND_RESET_I(1);
    decode_tb__DOT__overflow = VL_RAND_RESET_I(1);
    decode_tb__DOT__golden_op = VL_RAND_RESET_I(4);
    decode_tb__DOT__golden_ssel = VL_RAND_RESET_I(1);
    decode_tb__DOT__golden_imm = VL_RAND_RESET_I(32);
    decode_tb__DOT__golden_rs1_id = VL_RAND_RESET_I(5);
    decode_tb__DOT__golden_rs2_id = VL_RAND_RESET_I(5);
    decode_tb__DOT__golden_rdst_id = VL_RAND_RESET_I(5);
    { int __Vi0=0; for (; __Vi0<32; ++__Vi0) {
            decode_tb__DOT__golden_R[__Vi0] = VL_RAND_RESET_I(32);
    }}
    decode_tb__DOT__golden_reg = VL_RAND_RESET_I(32);
    decode_tb__DOT__i = VL_RAND_RESET_I(32);
    decode_tb__DOT__pat_num = VL_RAND_RESET_I(32);
    decode_tb__DOT__pattern = 0;
    decode_tb__DOT__tmp = VL_RAND_RESET_I(32);
    decode_tb__DOT__reg_pattern = 0;
    { int __Vi0=0; for (; __Vi0<32; ++__Vi0) {
            decode_tb__DOT__reg_file_inst__DOT__R[__Vi0] = VL_RAND_RESET_I(32);
    }}
    decode_tb__DOT__reg_file_inst__DOT__unnamedblk1__DOT__i = 0;
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}
