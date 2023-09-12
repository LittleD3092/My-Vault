// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdecode_tb.h for the primary calling header

#include "Vdecode_tb.h"
#include "Vdecode_tb__Syms.h"

//==========

void Vdecode_tb::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vdecode_tb::eval\n"); );
    Vdecode_tb__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vdecode_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("decode_tb.v", 8, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vdecode_tb::_eval_initial_loop(Vdecode_tb__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("decode_tb.v", 8, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vdecode_tb::_sequent__TOP__1(Vdecode_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecode_tb::_sequent__TOP__1\n"); );
    Vdecode_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->decode_tb__DOT__reg_file_inst__DOT__unnamedblk1__DOT__i = 0x20U;
    vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[0U] = 0U;
    vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[1U] = 0U;
    vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[2U] = 0U;
    vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[3U] = 0U;
    vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[4U] = 0U;
    vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[5U] = 0U;
    vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[6U] = 0U;
    vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[7U] = 0U;
    vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[8U] = 0U;
    vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[9U] = 0U;
    vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[0xaU] = 0U;
    vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[0xbU] = 0U;
    vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[0xcU] = 0U;
    vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[0xdU] = 0U;
    vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[0xeU] = 0U;
    vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[0xfU] = 0U;
    vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[0x10U] = 0U;
    vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[0x11U] = 0U;
    vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[0x12U] = 0U;
    vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[0x13U] = 0U;
    vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[0x14U] = 0U;
    vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[0x15U] = 0U;
    vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[0x16U] = 0U;
    vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[0x17U] = 0U;
    vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[0x18U] = 0U;
    vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[0x19U] = 0U;
    vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[0x1aU] = 0U;
    vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[0x1bU] = 0U;
    vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[0x1cU] = 0U;
    vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[0x1dU] = 0U;
    vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[0x1eU] = 0U;
    vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[0x1fU] = 0U;
}

VL_INLINE_OPT void Vdecode_tb::_sequent__TOP__2(Vdecode_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecode_tb::_sequent__TOP__2\n"); );
    Vdecode_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[vlTOPp->decode_tb__DOT__rdst_id] 
        = vlTOPp->decode_tb__DOT__rd;
    vlTOPp->decode_tb__DOT__rs1 = vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R
        [vlTOPp->decode_tb__DOT__rs1_id];
    vlTOPp->decode_tb__DOT__rs2_reg_file_out = vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R
        [vlTOPp->decode_tb__DOT__rs2_id];
    if ((vlTOPp->decode_tb__DOT__pattern ? feof(VL_CVT_I_FP(vlTOPp->decode_tb__DOT__pattern)) : true)) {
        vlTOPp->finish = 1U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->rst)))) {
            vlTOPp->decode_tb__DOT__tmp = VL_FSCANF_IX(vlTOPp->decode_tb__DOT__pattern,"%# %# %# %# %# %# %#\n",
                                                       32,
                                                       &(vlTOPp->decode_tb__DOT__instr),
                                                       4,
                                                       &(vlTOPp->decode_tb__DOT__golden_op),
                                                       1,
                                                       &(vlTOPp->decode_tb__DOT__golden_ssel),
                                                       32,
                                                       &(vlTOPp->decode_tb__DOT__golden_imm),
                                                       5,
                                                       &(vlTOPp->decode_tb__DOT__golden_rs1_id),
                                                       5,
                                                       &(vlTOPp->decode_tb__DOT__golden_rs2_id),
                                                       5,
                                                       &(vlTOPp->decode_tb__DOT__golden_rdst_id)) ;
        }
    }
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

VL_INLINE_OPT void Vdecode_tb::_sequent__TOP__3(Vdecode_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecode_tb::_sequent__TOP__3\n"); );
    Vdecode_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((1U & (~ (IData)(vlTOPp->rst)))) {
        if (VL_UNLIKELY((((((((IData)(vlTOPp->decode_tb__DOT__op) 
                              != (IData)(vlTOPp->decode_tb__DOT__golden_op)) 
                             | ((IData)(vlTOPp->decode_tb__DOT__ssel) 
                                != (IData)(vlTOPp->decode_tb__DOT__golden_ssel))) 
                            | ((vlTOPp->decode_tb__DOT__imm 
                                != vlTOPp->decode_tb__DOT__golden_imm) 
                               & (~ (IData)(vlTOPp->decode_tb__DOT__golden_ssel)))) 
                           | ((IData)(vlTOPp->decode_tb__DOT__rs1_id) 
                              != (IData)(vlTOPp->decode_tb__DOT__golden_rs1_id))) 
                          | (((IData)(vlTOPp->decode_tb__DOT__rs2_id) 
                              != (IData)(vlTOPp->decode_tb__DOT__golden_rs2_id)) 
                             & (IData)(vlTOPp->decode_tb__DOT__golden_ssel))) 
                         | ((IData)(vlTOPp->decode_tb__DOT__rdst_id) 
                            != (IData)(vlTOPp->decode_tb__DOT__golden_rdst_id))))) {
            VL_WRITEF("Fail Pattern %11d\n",32,vlTOPp->decode_tb__DOT__pat_num);
            VL_WRITEF("Your op      : %10#,  Golden op      : %10#\n",
                      4,vlTOPp->decode_tb__DOT__op,
                      4,(IData)(vlTOPp->decode_tb__DOT__golden_op));
            VL_WRITEF("Your ssel    : %10#,  Golden ssel    : %10#\n",
                      1,vlTOPp->decode_tb__DOT__ssel,
                      1,(IData)(vlTOPp->decode_tb__DOT__golden_ssel));
            VL_WRITEF("Your imm     : %10d,  Golden imm     : %10d\n",
                      32,vlTOPp->decode_tb__DOT__imm,
                      32,vlTOPp->decode_tb__DOT__golden_imm);
            VL_WRITEF("Your rs1_id  : %10#,  Golden rs1_id  : %10#\n",
                      5,vlTOPp->decode_tb__DOT__rs1_id,
                      5,(IData)(vlTOPp->decode_tb__DOT__golden_rs1_id));
            VL_WRITEF("Your rs2_id  : %10#,  Golden rs2_id  : %10#\n",
                      5,vlTOPp->decode_tb__DOT__rs2_id,
                      5,(IData)(vlTOPp->decode_tb__DOT__golden_rs2_id));
            VL_WRITEF("Your rdst_id : %10#,  Golden rdst_id : %10#\n",
                      5,vlTOPp->decode_tb__DOT__rdst_id,
                      5,(IData)(vlTOPp->decode_tb__DOT__golden_rdst_id));
            VL_FINISH_MT("decode_tb.v", 127, "");
            VL_FINISH_MT("decode_tb.v", 128, "");
        } else {
            VL_WRITEF("Pass Pattern %11d\n",32,vlTOPp->decode_tb__DOT__pat_num);
        }
        vlTOPp->decode_tb__DOT__pat_num = ((IData)(1U) 
                                           + vlTOPp->decode_tb__DOT__pat_num);
    }
    if (VL_UNLIKELY(vlTOPp->finish)) {
        vlTOPp->decode_tb__DOT__tmp = VL_FSCANF_IX(vlTOPp->decode_tb__DOT__reg_pattern,"%#",
                                                   32,
                                                   &(vlTOPp->decode_tb__DOT__golden_reg)) ;
        vlTOPp->decode_tb__DOT__i = 0x20U;
        vlTOPp->decode_tb__DOT__golden_R[0U] = vlTOPp->decode_tb__DOT__golden_reg;
        VL_WRITEF("Check reg[ 0] : ");
        if (VL_UNLIKELY((vlTOPp->decode_tb__DOT__golden_R
                         [0U] != vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R
                         [0U]))) {
            VL_WRITEF("Failed\n");
            VL_WRITEF("Your reg : %10d, Golden reg : %10d\n",
                      32,vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R
                      [0U],32,vlTOPp->decode_tb__DOT__golden_R
                      [0U]);
        } else {
            VL_WRITEF("Pass\n");
        }
        vlTOPp->decode_tb__DOT__tmp = VL_FSCANF_IX(vlTOPp->decode_tb__DOT__reg_pattern,"%#",
                                                   32,
                                                   &(vlTOPp->decode_tb__DOT__golden_reg)) ;
        vlTOPp->decode_tb__DOT__golden_R[1U] = vlTOPp->decode_tb__DOT__golden_reg;
        VL_WRITEF("Check reg[ 1] : ");
        if (VL_UNLIKELY((vlTOPp->decode_tb__DOT__golden_R
                         [1U] != vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R
                         [1U]))) {
            VL_WRITEF("Failed\n");
            VL_WRITEF("Your reg : %10d, Golden reg : %10d\n",
                      32,vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R
                      [1U],32,vlTOPp->decode_tb__DOT__golden_R
                      [1U]);
        } else {
            VL_WRITEF("Pass\n");
        }
        vlTOPp->decode_tb__DOT__tmp = VL_FSCANF_IX(vlTOPp->decode_tb__DOT__reg_pattern,"%#",
                                                   32,
                                                   &(vlTOPp->decode_tb__DOT__golden_reg)) ;
        vlTOPp->decode_tb__DOT__golden_R[2U] = vlTOPp->decode_tb__DOT__golden_reg;
        VL_WRITEF("Check reg[ 2] : ");
        if (VL_UNLIKELY((vlTOPp->decode_tb__DOT__golden_R
                         [2U] != vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R
                         [2U]))) {
            VL_WRITEF("Failed\n");
            VL_WRITEF("Your reg : %10d, Golden reg : %10d\n",
                      32,vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R
                      [2U],32,vlTOPp->decode_tb__DOT__golden_R
                      [2U]);
        } else {
            VL_WRITEF("Pass\n");
        }
        vlTOPp->decode_tb__DOT__tmp = VL_FSCANF_IX(vlTOPp->decode_tb__DOT__reg_pattern,"%#",
                                                   32,
                                                   &(vlTOPp->decode_tb__DOT__golden_reg)) ;
        vlTOPp->decode_tb__DOT__golden_R[3U] = vlTOPp->decode_tb__DOT__golden_reg;
        VL_WRITEF("Check reg[ 3] : ");
        if (VL_UNLIKELY((vlTOPp->decode_tb__DOT__golden_R
                         [3U] != vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R
                         [3U]))) {
            VL_WRITEF("Failed\n");
            VL_WRITEF("Your reg : %10d, Golden reg : %10d\n",
                      32,vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R
                      [3U],32,vlTOPp->decode_tb__DOT__golden_R
                      [3U]);
        } else {
            VL_WRITEF("Pass\n");
        }
        vlTOPp->decode_tb__DOT__tmp = VL_FSCANF_IX(vlTOPp->decode_tb__DOT__reg_pattern,"%#",
                                                   32,
                                                   &(vlTOPp->decode_tb__DOT__golden_reg)) ;
        vlTOPp->decode_tb__DOT__golden_R[4U] = vlTOPp->decode_tb__DOT__golden_reg;
        VL_WRITEF("Check reg[ 4] : ");
        if (VL_UNLIKELY((vlTOPp->decode_tb__DOT__golden_R
                         [4U] != vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R
                         [4U]))) {
            VL_WRITEF("Failed\n");
            VL_WRITEF("Your reg : %10d, Golden reg : %10d\n",
                      32,vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R
                      [4U],32,vlTOPp->decode_tb__DOT__golden_R
                      [4U]);
        } else {
            VL_WRITEF("Pass\n");
        }
        vlTOPp->decode_tb__DOT__tmp = VL_FSCANF_IX(vlTOPp->decode_tb__DOT__reg_pattern,"%#",
                                                   32,
                                                   &(vlTOPp->decode_tb__DOT__golden_reg)) ;
        vlTOPp->decode_tb__DOT__golden_R[5U] = vlTOPp->decode_tb__DOT__golden_reg;
        VL_WRITEF("Check reg[ 5] : ");
        if (VL_UNLIKELY((vlTOPp->decode_tb__DOT__golden_R
                         [5U] != vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R
                         [5U]))) {
            VL_WRITEF("Failed\n");
            VL_WRITEF("Your reg : %10d, Golden reg : %10d\n",
                      32,vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R
                      [5U],32,vlTOPp->decode_tb__DOT__golden_R
                      [5U]);
        } else {
            VL_WRITEF("Pass\n");
        }
        vlTOPp->decode_tb__DOT__tmp = VL_FSCANF_IX(vlTOPp->decode_tb__DOT__reg_pattern,"%#",
                                                   32,
                                                   &(vlTOPp->decode_tb__DOT__golden_reg)) ;
        vlTOPp->decode_tb__DOT__golden_R[6U] = vlTOPp->decode_tb__DOT__golden_reg;
        VL_WRITEF("Check reg[ 6] : ");
        if (VL_UNLIKELY((vlTOPp->decode_tb__DOT__golden_R
                         [6U] != vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R
                         [6U]))) {
            VL_WRITEF("Failed\n");
            VL_WRITEF("Your reg : %10d, Golden reg : %10d\n",
                      32,vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R
                      [6U],32,vlTOPp->decode_tb__DOT__golden_R
                      [6U]);
        } else {
            VL_WRITEF("Pass\n");
        }
        vlTOPp->decode_tb__DOT__tmp = VL_FSCANF_IX(vlTOPp->decode_tb__DOT__reg_pattern,"%#",
                                                   32,
                                                   &(vlTOPp->decode_tb__DOT__golden_reg)) ;
        vlTOPp->decode_tb__DOT__golden_R[7U] = vlTOPp->decode_tb__DOT__golden_reg;
        VL_WRITEF("Check reg[ 7] : ");
        if (VL_UNLIKELY((vlTOPp->decode_tb__DOT__golden_R
                         [7U] != vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R
                         [7U]))) {
            VL_WRITEF("Failed\n");
            VL_WRITEF("Your reg : %10d, Golden reg : %10d\n",
                      32,vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R
                      [7U],32,vlTOPp->decode_tb__DOT__golden_R
                      [7U]);
        } else {
            VL_WRITEF("Pass\n");
        }
        vlTOPp->decode_tb__DOT__tmp = VL_FSCANF_IX(vlTOPp->decode_tb__DOT__reg_pattern,"%#",
                                                   32,
                                                   &(vlTOPp->decode_tb__DOT__golden_reg)) ;
        vlTOPp->decode_tb__DOT__golden_R[8U] = vlTOPp->decode_tb__DOT__golden_reg;
        VL_WRITEF("Check reg[ 8] : ");
        if (VL_UNLIKELY((vlTOPp->decode_tb__DOT__golden_R
                         [8U] != vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R
                         [8U]))) {
            VL_WRITEF("Failed\n");
            VL_WRITEF("Your reg : %10d, Golden reg : %10d\n",
                      32,vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R
                      [8U],32,vlTOPp->decode_tb__DOT__golden_R
                      [8U]);
        } else {
            VL_WRITEF("Pass\n");
        }
        vlTOPp->decode_tb__DOT__tmp = VL_FSCANF_IX(vlTOPp->decode_tb__DOT__reg_pattern,"%#",
                                                   32,
                                                   &(vlTOPp->decode_tb__DOT__golden_reg)) ;
        vlTOPp->decode_tb__DOT__golden_R[9U] = vlTOPp->decode_tb__DOT__golden_reg;
        VL_WRITEF("Check reg[ 9] : ");
        if (VL_UNLIKELY((vlTOPp->decode_tb__DOT__golden_R
                         [9U] != vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R
                         [9U]))) {
            VL_WRITEF("Failed\n");
            VL_WRITEF("Your reg : %10d, Golden reg : %10d\n",
                      32,vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R
                      [9U],32,vlTOPp->decode_tb__DOT__golden_R
                      [9U]);
        } else {
            VL_WRITEF("Pass\n");
        }
        vlTOPp->decode_tb__DOT__tmp = VL_FSCANF_IX(vlTOPp->decode_tb__DOT__reg_pattern,"%#",
                                                   32,
                                                   &(vlTOPp->decode_tb__DOT__golden_reg)) ;
        vlTOPp->decode_tb__DOT__golden_R[0xaU] = vlTOPp->decode_tb__DOT__golden_reg;
        VL_WRITEF("Check reg[10] : ");
        if (VL_UNLIKELY((vlTOPp->decode_tb__DOT__golden_R
                         [0xaU] != vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R
                         [0xaU]))) {
            VL_WRITEF("Failed\n");
            VL_WRITEF("Your reg : %10d, Golden reg : %10d\n",
                      32,vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R
                      [0xaU],32,vlTOPp->decode_tb__DOT__golden_R
                      [0xaU]);
        } else {
            VL_WRITEF("Pass\n");
        }
        vlTOPp->decode_tb__DOT__tmp = VL_FSCANF_IX(vlTOPp->decode_tb__DOT__reg_pattern,"%#",
                                                   32,
                                                   &(vlTOPp->decode_tb__DOT__golden_reg)) ;
        vlTOPp->decode_tb__DOT__golden_R[0xbU] = vlTOPp->decode_tb__DOT__golden_reg;
        VL_WRITEF("Check reg[11] : ");
        if (VL_UNLIKELY((vlTOPp->decode_tb__DOT__golden_R
                         [0xbU] != vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R
                         [0xbU]))) {
            VL_WRITEF("Failed\n");
            VL_WRITEF("Your reg : %10d, Golden reg : %10d\n",
                      32,vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R
                      [0xbU],32,vlTOPp->decode_tb__DOT__golden_R
                      [0xbU]);
        } else {
            VL_WRITEF("Pass\n");
        }
        vlTOPp->decode_tb__DOT__tmp = VL_FSCANF_IX(vlTOPp->decode_tb__DOT__reg_pattern,"%#",
                                                   32,
                                                   &(vlTOPp->decode_tb__DOT__golden_reg)) ;
        vlTOPp->decode_tb__DOT__golden_R[0xcU] = vlTOPp->decode_tb__DOT__golden_reg;
        VL_WRITEF("Check reg[12] : ");
        if (VL_UNLIKELY((vlTOPp->decode_tb__DOT__golden_R
                         [0xcU] != vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R
                         [0xcU]))) {
            VL_WRITEF("Failed\n");
            VL_WRITEF("Your reg : %10d, Golden reg : %10d\n",
                      32,vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R
                      [0xcU],32,vlTOPp->decode_tb__DOT__golden_R
                      [0xcU]);
        } else {
            VL_WRITEF("Pass\n");
        }
        vlTOPp->decode_tb__DOT__tmp = VL_FSCANF_IX(vlTOPp->decode_tb__DOT__reg_pattern,"%#",
                                                   32,
                                                   &(vlTOPp->decode_tb__DOT__golden_reg)) ;
        vlTOPp->decode_tb__DOT__golden_R[0xdU] = vlTOPp->decode_tb__DOT__golden_reg;
        VL_WRITEF("Check reg[13] : ");
        if (VL_UNLIKELY((vlTOPp->decode_tb__DOT__golden_R
                         [0xdU] != vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R
                         [0xdU]))) {
            VL_WRITEF("Failed\n");
            VL_WRITEF("Your reg : %10d, Golden reg : %10d\n",
                      32,vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R
                      [0xdU],32,vlTOPp->decode_tb__DOT__golden_R
                      [0xdU]);
        } else {
            VL_WRITEF("Pass\n");
        }
        vlTOPp->decode_tb__DOT__tmp = VL_FSCANF_IX(vlTOPp->decode_tb__DOT__reg_pattern,"%#",
                                                   32,
                                                   &(vlTOPp->decode_tb__DOT__golden_reg)) ;
        vlTOPp->decode_tb__DOT__golden_R[0xeU] = vlTOPp->decode_tb__DOT__golden_reg;
        VL_WRITEF("Check reg[14] : ");
        if (VL_UNLIKELY((vlTOPp->decode_tb__DOT__golden_R
                         [0xeU] != vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R
                         [0xeU]))) {
            VL_WRITEF("Failed\n");
            VL_WRITEF("Your reg : %10d, Golden reg : %10d\n",
                      32,vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R
                      [0xeU],32,vlTOPp->decode_tb__DOT__golden_R
                      [0xeU]);
        } else {
            VL_WRITEF("Pass\n");
        }
        vlTOPp->decode_tb__DOT__tmp = VL_FSCANF_IX(vlTOPp->decode_tb__DOT__reg_pattern,"%#",
                                                   32,
                                                   &(vlTOPp->decode_tb__DOT__golden_reg)) ;
        vlTOPp->decode_tb__DOT__golden_R[0xfU] = vlTOPp->decode_tb__DOT__golden_reg;
        VL_WRITEF("Check reg[15] : ");
        if (VL_UNLIKELY((vlTOPp->decode_tb__DOT__golden_R
                         [0xfU] != vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R
                         [0xfU]))) {
            VL_WRITEF("Failed\n");
            VL_WRITEF("Your reg : %10d, Golden reg : %10d\n",
                      32,vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R
                      [0xfU],32,vlTOPp->decode_tb__DOT__golden_R
                      [0xfU]);
        } else {
            VL_WRITEF("Pass\n");
        }
        vlTOPp->decode_tb__DOT__tmp = VL_FSCANF_IX(vlTOPp->decode_tb__DOT__reg_pattern,"%#",
                                                   32,
                                                   &(vlTOPp->decode_tb__DOT__golden_reg)) ;
        vlTOPp->decode_tb__DOT__golden_R[0x10U] = vlTOPp->decode_tb__DOT__golden_reg;
        VL_WRITEF("Check reg[16] : ");
        if (VL_UNLIKELY((vlTOPp->decode_tb__DOT__golden_R
                         [0x10U] != vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R
                         [0x10U]))) {
            VL_WRITEF("Failed\n");
            VL_WRITEF("Your reg : %10d, Golden reg : %10d\n",
                      32,vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R
                      [0x10U],32,vlTOPp->decode_tb__DOT__golden_R
                      [0x10U]);
        } else {
            VL_WRITEF("Pass\n");
        }
        vlTOPp->decode_tb__DOT__tmp = VL_FSCANF_IX(vlTOPp->decode_tb__DOT__reg_pattern,"%#",
                                                   32,
                                                   &(vlTOPp->decode_tb__DOT__golden_reg)) ;
        vlTOPp->decode_tb__DOT__golden_R[0x11U] = vlTOPp->decode_tb__DOT__golden_reg;
        VL_WRITEF("Check reg[17] : ");
        if (VL_UNLIKELY((vlTOPp->decode_tb__DOT__golden_R
                         [0x11U] != vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R
                         [0x11U]))) {
            VL_WRITEF("Failed\n");
            VL_WRITEF("Your reg : %10d, Golden reg : %10d\n",
                      32,vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R
                      [0x11U],32,vlTOPp->decode_tb__DOT__golden_R
                      [0x11U]);
        } else {
            VL_WRITEF("Pass\n");
        }
        vlTOPp->decode_tb__DOT__tmp = VL_FSCANF_IX(vlTOPp->decode_tb__DOT__reg_pattern,"%#",
                                                   32,
                                                   &(vlTOPp->decode_tb__DOT__golden_reg)) ;
        vlTOPp->decode_tb__DOT__golden_R[0x12U] = vlTOPp->decode_tb__DOT__golden_reg;
        VL_WRITEF("Check reg[18] : ");
        if (VL_UNLIKELY((vlTOPp->decode_tb__DOT__golden_R
                         [0x12U] != vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R
                         [0x12U]))) {
            VL_WRITEF("Failed\n");
            VL_WRITEF("Your reg : %10d, Golden reg : %10d\n",
                      32,vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R
                      [0x12U],32,vlTOPp->decode_tb__DOT__golden_R
                      [0x12U]);
        } else {
            VL_WRITEF("Pass\n");
        }
        vlTOPp->decode_tb__DOT__tmp = VL_FSCANF_IX(vlTOPp->decode_tb__DOT__reg_pattern,"%#",
                                                   32,
                                                   &(vlTOPp->decode_tb__DOT__golden_reg)) ;
        vlTOPp->decode_tb__DOT__golden_R[0x13U] = vlTOPp->decode_tb__DOT__golden_reg;
        VL_WRITEF("Check reg[19] : ");
        if (VL_UNLIKELY((vlTOPp->decode_tb__DOT__golden_R
                         [0x13U] != vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R
                         [0x13U]))) {
            VL_WRITEF("Failed\n");
            VL_WRITEF("Your reg : %10d, Golden reg : %10d\n",
                      32,vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R
                      [0x13U],32,vlTOPp->decode_tb__DOT__golden_R
                      [0x13U]);
        } else {
            VL_WRITEF("Pass\n");
        }
        vlTOPp->decode_tb__DOT__tmp = VL_FSCANF_IX(vlTOPp->decode_tb__DOT__reg_pattern,"%#",
                                                   32,
                                                   &(vlTOPp->decode_tb__DOT__golden_reg)) ;
        vlTOPp->decode_tb__DOT__golden_R[0x14U] = vlTOPp->decode_tb__DOT__golden_reg;
        VL_WRITEF("Check reg[20] : ");
        if (VL_UNLIKELY((vlTOPp->decode_tb__DOT__golden_R
                         [0x14U] != vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R
                         [0x14U]))) {
            VL_WRITEF("Failed\n");
            VL_WRITEF("Your reg : %10d, Golden reg : %10d\n",
                      32,vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R
                      [0x14U],32,vlTOPp->decode_tb__DOT__golden_R
                      [0x14U]);
        } else {
            VL_WRITEF("Pass\n");
        }
        vlTOPp->decode_tb__DOT__tmp = VL_FSCANF_IX(vlTOPp->decode_tb__DOT__reg_pattern,"%#",
                                                   32,
                                                   &(vlTOPp->decode_tb__DOT__golden_reg)) ;
        vlTOPp->decode_tb__DOT__golden_R[0x15U] = vlTOPp->decode_tb__DOT__golden_reg;
        VL_WRITEF("Check reg[21] : ");
        if (VL_UNLIKELY((vlTOPp->decode_tb__DOT__golden_R
                         [0x15U] != vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R
                         [0x15U]))) {
            VL_WRITEF("Failed\n");
            VL_WRITEF("Your reg : %10d, Golden reg : %10d\n",
                      32,vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R
                      [0x15U],32,vlTOPp->decode_tb__DOT__golden_R
                      [0x15U]);
        } else {
            VL_WRITEF("Pass\n");
        }
        vlTOPp->decode_tb__DOT__tmp = VL_FSCANF_IX(vlTOPp->decode_tb__DOT__reg_pattern,"%#",
                                                   32,
                                                   &(vlTOPp->decode_tb__DOT__golden_reg)) ;
        vlTOPp->decode_tb__DOT__golden_R[0x16U] = vlTOPp->decode_tb__DOT__golden_reg;
        VL_WRITEF("Check reg[22] : ");
        if (VL_UNLIKELY((vlTOPp->decode_tb__DOT__golden_R
                         [0x16U] != vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R
                         [0x16U]))) {
            VL_WRITEF("Failed\n");
            VL_WRITEF("Your reg : %10d, Golden reg : %10d\n",
                      32,vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R
                      [0x16U],32,vlTOPp->decode_tb__DOT__golden_R
                      [0x16U]);
        } else {
            VL_WRITEF("Pass\n");
        }
        vlTOPp->decode_tb__DOT__tmp = VL_FSCANF_IX(vlTOPp->decode_tb__DOT__reg_pattern,"%#",
                                                   32,
                                                   &(vlTOPp->decode_tb__DOT__golden_reg)) ;
        vlTOPp->decode_tb__DOT__golden_R[0x17U] = vlTOPp->decode_tb__DOT__golden_reg;
        VL_WRITEF("Check reg[23] : ");
        if (VL_UNLIKELY((vlTOPp->decode_tb__DOT__golden_R
                         [0x17U] != vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R
                         [0x17U]))) {
            VL_WRITEF("Failed\n");
            VL_WRITEF("Your reg : %10d, Golden reg : %10d\n",
                      32,vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R
                      [0x17U],32,vlTOPp->decode_tb__DOT__golden_R
                      [0x17U]);
        } else {
            VL_WRITEF("Pass\n");
        }
        vlTOPp->decode_tb__DOT__tmp = VL_FSCANF_IX(vlTOPp->decode_tb__DOT__reg_pattern,"%#",
                                                   32,
                                                   &(vlTOPp->decode_tb__DOT__golden_reg)) ;
        vlTOPp->decode_tb__DOT__golden_R[0x18U] = vlTOPp->decode_tb__DOT__golden_reg;
        VL_WRITEF("Check reg[24] : ");
        if (VL_UNLIKELY((vlTOPp->decode_tb__DOT__golden_R
                         [0x18U] != vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R
                         [0x18U]))) {
            VL_WRITEF("Failed\n");
            VL_WRITEF("Your reg : %10d, Golden reg : %10d\n",
                      32,vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R
                      [0x18U],32,vlTOPp->decode_tb__DOT__golden_R
                      [0x18U]);
        } else {
            VL_WRITEF("Pass\n");
        }
        vlTOPp->decode_tb__DOT__tmp = VL_FSCANF_IX(vlTOPp->decode_tb__DOT__reg_pattern,"%#",
                                                   32,
                                                   &(vlTOPp->decode_tb__DOT__golden_reg)) ;
        vlTOPp->decode_tb__DOT__golden_R[0x19U] = vlTOPp->decode_tb__DOT__golden_reg;
        VL_WRITEF("Check reg[25] : ");
        if (VL_UNLIKELY((vlTOPp->decode_tb__DOT__golden_R
                         [0x19U] != vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R
                         [0x19U]))) {
            VL_WRITEF("Failed\n");
            VL_WRITEF("Your reg : %10d, Golden reg : %10d\n",
                      32,vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R
                      [0x19U],32,vlTOPp->decode_tb__DOT__golden_R
                      [0x19U]);
        } else {
            VL_WRITEF("Pass\n");
        }
        vlTOPp->decode_tb__DOT__tmp = VL_FSCANF_IX(vlTOPp->decode_tb__DOT__reg_pattern,"%#",
                                                   32,
                                                   &(vlTOPp->decode_tb__DOT__golden_reg)) ;
        vlTOPp->decode_tb__DOT__golden_R[0x1aU] = vlTOPp->decode_tb__DOT__golden_reg;
        VL_WRITEF("Check reg[26] : ");
        if (VL_UNLIKELY((vlTOPp->decode_tb__DOT__golden_R
                         [0x1aU] != vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R
                         [0x1aU]))) {
            VL_WRITEF("Failed\n");
            VL_WRITEF("Your reg : %10d, Golden reg : %10d\n",
                      32,vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R
                      [0x1aU],32,vlTOPp->decode_tb__DOT__golden_R
                      [0x1aU]);
        } else {
            VL_WRITEF("Pass\n");
        }
        vlTOPp->decode_tb__DOT__tmp = VL_FSCANF_IX(vlTOPp->decode_tb__DOT__reg_pattern,"%#",
                                                   32,
                                                   &(vlTOPp->decode_tb__DOT__golden_reg)) ;
        vlTOPp->decode_tb__DOT__golden_R[0x1bU] = vlTOPp->decode_tb__DOT__golden_reg;
        VL_WRITEF("Check reg[27] : ");
        if (VL_UNLIKELY((vlTOPp->decode_tb__DOT__golden_R
                         [0x1bU] != vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R
                         [0x1bU]))) {
            VL_WRITEF("Failed\n");
            VL_WRITEF("Your reg : %10d, Golden reg : %10d\n",
                      32,vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R
                      [0x1bU],32,vlTOPp->decode_tb__DOT__golden_R
                      [0x1bU]);
        } else {
            VL_WRITEF("Pass\n");
        }
        vlTOPp->decode_tb__DOT__tmp = VL_FSCANF_IX(vlTOPp->decode_tb__DOT__reg_pattern,"%#",
                                                   32,
                                                   &(vlTOPp->decode_tb__DOT__golden_reg)) ;
        vlTOPp->decode_tb__DOT__golden_R[0x1cU] = vlTOPp->decode_tb__DOT__golden_reg;
        VL_WRITEF("Check reg[28] : ");
        if (VL_UNLIKELY((vlTOPp->decode_tb__DOT__golden_R
                         [0x1cU] != vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R
                         [0x1cU]))) {
            VL_WRITEF("Failed\n");
            VL_WRITEF("Your reg : %10d, Golden reg : %10d\n",
                      32,vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R
                      [0x1cU],32,vlTOPp->decode_tb__DOT__golden_R
                      [0x1cU]);
        } else {
            VL_WRITEF("Pass\n");
        }
        vlTOPp->decode_tb__DOT__tmp = VL_FSCANF_IX(vlTOPp->decode_tb__DOT__reg_pattern,"%#",
                                                   32,
                                                   &(vlTOPp->decode_tb__DOT__golden_reg)) ;
        vlTOPp->decode_tb__DOT__golden_R[0x1dU] = vlTOPp->decode_tb__DOT__golden_reg;
        VL_WRITEF("Check reg[29] : ");
        if (VL_UNLIKELY((vlTOPp->decode_tb__DOT__golden_R
                         [0x1dU] != vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R
                         [0x1dU]))) {
            VL_WRITEF("Failed\n");
            VL_WRITEF("Your reg : %10d, Golden reg : %10d\n",
                      32,vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R
                      [0x1dU],32,vlTOPp->decode_tb__DOT__golden_R
                      [0x1dU]);
        } else {
            VL_WRITEF("Pass\n");
        }
        vlTOPp->decode_tb__DOT__tmp = VL_FSCANF_IX(vlTOPp->decode_tb__DOT__reg_pattern,"%#",
                                                   32,
                                                   &(vlTOPp->decode_tb__DOT__golden_reg)) ;
        vlTOPp->decode_tb__DOT__golden_R[0x1eU] = vlTOPp->decode_tb__DOT__golden_reg;
        VL_WRITEF("Check reg[30] : ");
        if (VL_UNLIKELY((vlTOPp->decode_tb__DOT__golden_R
                         [0x1eU] != vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R
                         [0x1eU]))) {
            VL_WRITEF("Failed\n");
            VL_WRITEF("Your reg : %10d, Golden reg : %10d\n",
                      32,vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R
                      [0x1eU],32,vlTOPp->decode_tb__DOT__golden_R
                      [0x1eU]);
        } else {
            VL_WRITEF("Pass\n");
        }
        vlTOPp->decode_tb__DOT__tmp = VL_FSCANF_IX(vlTOPp->decode_tb__DOT__reg_pattern,"%#",
                                                   32,
                                                   &(vlTOPp->decode_tb__DOT__golden_reg)) ;
        vlTOPp->decode_tb__DOT__golden_R[0x1fU] = vlTOPp->decode_tb__DOT__golden_reg;
        VL_WRITEF("Check reg[31] : ");
        if (VL_UNLIKELY((vlTOPp->decode_tb__DOT__golden_R
                         [0x1fU] != vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R
                         [0x1fU]))) {
            VL_WRITEF("Failed\n");
            VL_WRITEF("Your reg : %10d, Golden reg : %10d\n",
                      32,vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R
                      [0x1fU],32,vlTOPp->decode_tb__DOT__golden_R
                      [0x1fU]);
        } else {
            VL_WRITEF("Pass\n");
        }
    }
}

void Vdecode_tb::_eval(Vdecode_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecode_tb::_eval\n"); );
    Vdecode_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->rst) & (~ (IData)(vlTOPp->__Vclklast__TOP__rst)))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
        vlTOPp->__Vm_traceActivity[1U] = 1U;
    }
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
        vlTOPp->__Vm_traceActivity[2U] = 1U;
    }
    if (((~ (IData)(vlTOPp->clk)) & (IData)(vlTOPp->__Vclklast__TOP__clk))) {
        vlTOPp->_sequent__TOP__3(vlSymsp);
        vlTOPp->__Vm_traceActivity[3U] = 1U;
    }
    // Final
    vlTOPp->__Vclklast__TOP__rst = vlTOPp->rst;
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

VL_INLINE_OPT QData Vdecode_tb::_change_request(Vdecode_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecode_tb::_change_request\n"); );
    Vdecode_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vdecode_tb::_change_request_1(Vdecode_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecode_tb::_change_request_1\n"); );
    Vdecode_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vdecode_tb::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecode_tb::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
}
#endif  // VL_DEBUG
