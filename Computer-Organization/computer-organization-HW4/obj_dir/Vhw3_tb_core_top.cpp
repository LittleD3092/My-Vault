// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vhw3_tb.h for the primary calling header

#include "Vhw3_tb_core_top.h"
#include "Vhw3_tb__Syms.h"

#include "verilated_dpi.h"

//==========

VL_INLINE_OPT void Vhw3_tb_core_top::_sequent__TOP__hw3_tb__core_top_inst__1(Vhw3_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vhw3_tb_core_top::_sequent__TOP__hw3_tb__core_top_inst__1\n"); );
    Vhw3_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__hw3_tb__core_top_inst.__Vdly__pc 
        = vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__pc;
    vlSymsp->TOP__hw3_tb__core_top_inst.__Vdlyvset__reg_file_inst__DOT__R__v0 = 0U;
    vlSymsp->TOP__hw3_tb__core_top_inst.__Vdlyvset__reg_file_inst__DOT__R__v32 = 0U;
    if (vlTOPp->rst) {
        vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__i = 0x20U;
    }
    if (vlTOPp->rst) {
        vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_op = 0U;
        vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__mem_wb_addr = 0U;
    } else {
        vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_op 
            = ((IData)(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__control_hazard)
                ? 0U : (IData)(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__op));
        vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__mem_wb_addr 
            = vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__ex_mem_addr;
    }
    vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_ssel 
        = ((~ (IData)(vlTOPp->rst)) & ((~ (IData)(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__control_hazard)) 
                                       & ((0U == (0x3fU 
                                                  & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                                     >> 0x1aU))) 
                                          | (4U == 
                                             (0x3fU 
                                              & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                                 >> 0x1aU))))));
    if (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__pc_write) {
        vlSymsp->TOP__hw3_tb__core_top_inst.__Vdly__pc 
            = ((IData)(vlTOPp->rst) ? 0U : (((1U == vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_jump_type) 
                                             & (0U 
                                                == (IData)(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__alu_inst__DOT__result)))
                                             ? (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__pc 
                                                + (0xfffffffcU 
                                                   & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_imm 
                                                      << 2U)))
                                             : ((3U 
                                                 == vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_jump_type)
                                                 ? vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_rs1_out
                                                 : 
                                                (((2U 
                                                   == vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_jump_type) 
                                                  | (4U 
                                                     == vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_jump_type))
                                                  ? 
                                                 (0xfffffffcU 
                                                  & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_jump_addr 
                                                     << 2U))
                                                  : vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__pc_increment))));
    }
    if (vlTOPp->rst) {
        vlSymsp->TOP__hw3_tb__core_top_inst.__Vdlyvset__reg_file_inst__DOT__R__v0 = 1U;
    } else {
        if (((IData)(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__mem_wb_we_regfile) 
             & (0U != (0x1fU & vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__mem_wb_rdst_id)))) {
            vlSymsp->TOP__hw3_tb__core_top_inst.__Vdlyvval__reg_file_inst__DOT__R__v32 
                = vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__mem_wb_rd;
            vlSymsp->TOP__hw3_tb__core_top_inst.__Vdlyvset__reg_file_inst__DOT__R__v32 = 1U;
            vlSymsp->TOP__hw3_tb__core_top_inst.__Vdlyvdim0__reg_file_inst__DOT__R__v32 
                = (0x1fU & vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__mem_wb_rdst_id);
        }
    }
    if (vlTOPp->rst) {
        vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_jump_addr = 0U;
        vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_jump_type = 0U;
        vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_rs1_out = 0U;
        vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_imm = 0U;
    } else {
        vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_jump_addr 
            = ((IData)(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__control_hazard)
                ? 0U : (0x3ffffffU & vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr));
        vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_jump_type 
            = ((IData)(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__control_hazard)
                ? 0U : ((0x80000000U & vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr)
                         ? 0U : ((0x40000000U & vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr)
                                  ? 0U : ((0x20000000U 
                                           & vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr)
                                           ? 0U : (
                                                   (0x10000000U 
                                                    & vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr)
                                                    ? 
                                                   ((0x8000000U 
                                                     & vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr)
                                                     ? 0U
                                                     : 
                                                    ((0x4000000U 
                                                      & vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr)
                                                      ? 0U
                                                      : 1U))
                                                    : 
                                                   ((0x8000000U 
                                                     & vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr)
                                                     ? 
                                                    ((0x4000000U 
                                                      & vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr)
                                                      ? 2U
                                                      : 4U)
                                                     : 
                                                    ((0x4000000U 
                                                      & vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr)
                                                      ? 0U
                                                      : 
                                                     ((8U 
                                                       == 
                                                       (0x3fU 
                                                        & vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr))
                                                       ? 3U
                                                       : 0U))))))));
        vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_rs1_out 
            = ((IData)(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__control_hazard)
                ? 0U : vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R
               [(0x1fU & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                          >> 0x15U))]);
        vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_imm 
            = ((IData)(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__control_hazard)
                ? 0U : ((0xffff0000U & ((- (IData)(
                                                   (1U 
                                                    & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                                       >> 0xfU)))) 
                                        << 0x10U)) 
                        | (0xffffU & vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr)));
    }
    vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__mem_wb_we_regfile 
        = ((~ (IData)(vlTOPp->rst)) & (IData)(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__ex_mem_we_regfile));
    if (vlTOPp->rst) {
        vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__mem_wb_rdst_id = 0U;
        vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__mem_wb_rd = 0U;
    } else {
        vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__mem_wb_rdst_id 
            = vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__ex_mem_rdst_id;
        vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__mem_wb_rd 
            = ((0U == (IData)(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__ex_mem_wbsel))
                ? vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__ex_mem_alu_out
                : ((1U == (IData)(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__ex_mem_wbsel))
                    ? vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM
                   [(0xfU & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__ex_mem_alu_out 
                             >> 2U))] : ((2U == (IData)(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__ex_mem_wbsel))
                                          ? ((IData)(4U) 
                                             + vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__ex_mem_addr)
                                          : 0U)));
    }
    vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__ex_mem_we_regfile 
        = ((~ (IData)(vlTOPp->rst)) & (IData)(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_we_regfile));
    if (vlTOPp->rst) {
        vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__ex_mem_rdst_id = 0U;
        vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__ex_mem_wbsel = 0U;
        vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__ex_mem_addr = 0U;
    } else {
        vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__ex_mem_rdst_id 
            = vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_rdst_id;
        vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__ex_mem_wbsel 
            = vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_wbsel;
        vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__ex_mem_addr 
            = vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_addr;
    }
    vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_we_regfile 
        = (1U & ((~ (IData)(vlTOPp->rst)) & ((~ (IData)(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__control_hazard)) 
                                             & ((0U 
                                                 == 
                                                 (0x3fU 
                                                  & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                                     >> 0x1aU)))
                                                 ? 
                                                ((8U 
                                                  == 
                                                  (0x3fU 
                                                   & vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr))
                                                  ? 0U
                                                  : 1U)
                                                 : 
                                                ((((8U 
                                                    == 
                                                    (0x3fU 
                                                     & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                                        >> 0x1aU))) 
                                                   | (0xaU 
                                                      == 
                                                      (0x3fU 
                                                       & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                                          >> 0x1aU)))) 
                                                  | (0x23U 
                                                     == 
                                                     (0x3fU 
                                                      & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                                         >> 0x1aU)))) 
                                                 | (3U 
                                                    == 
                                                    (0x3fU 
                                                     & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                                        >> 0x1aU))))))));
    if (vlTOPp->rst) {
        vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_rdst_id = 0U;
        vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_wbsel = 0U;
        vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_addr = 0U;
    } else {
        vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_rdst_id 
            = ((IData)(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__control_hazard)
                ? 0U : (0x1fU & ((0U == (0x3fU & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                                  >> 0x1aU)))
                                  ? (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                     >> 0xbU) : (((
                                                   (8U 
                                                    == 
                                                    (0x3fU 
                                                     & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                                        >> 0x1aU))) 
                                                   | (0xaU 
                                                      == 
                                                      (0x3fU 
                                                       & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                                          >> 0x1aU)))) 
                                                  | (0x23U 
                                                     == 
                                                     (0x3fU 
                                                      & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                                         >> 0x1aU))))
                                                  ? 
                                                 (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                                  >> 0x10U)
                                                  : 
                                                 ((3U 
                                                   == 
                                                   (0x3fU 
                                                    & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                                       >> 0x1aU)))
                                                   ? 0x1fU
                                                   : 0U)))));
        vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_wbsel 
            = ((IData)(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__control_hazard)
                ? 0U : ((0x23U == (0x3fU & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                            >> 0x1aU)))
                         ? 1U : ((3U == (0x3fU & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                                  >> 0x1aU)))
                                  ? 2U : 0U)));
        vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_addr 
            = ((IData)(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__control_hazard)
                ? 0U : vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_addr);
    }
    if (vlTOPp->rst) {
        vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_addr = 0U;
    } else {
        if (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__pc_write) {
            vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_addr 
                = vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__pc;
        } else {
            if (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__control_hazard) {
                vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_addr = 0U;
            }
        }
    }
}

VL_INLINE_OPT void Vhw3_tb_core_top::_sequent__TOP__hw3_tb__core_top_inst__2(Vhw3_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vhw3_tb_core_top::_sequent__TOP__hw3_tb__core_top_inst__2\n"); );
    Vhw3_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__ex_mem_we_dmem 
        = ((~ (IData)(vlTOPp->rst)) & (IData)(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_we_dmem));
    if (vlTOPp->rst) {
        vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__ex_mem_rs2_out = 0U;
        vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__ex_mem_alu_out = 0U;
    } else {
        vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__ex_mem_rs2_out 
            = vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_rs2_out;
        vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__ex_mem_alu_out 
            = (IData)(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__alu_inst__DOT__result);
    }
    vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_we_dmem 
        = ((~ (IData)(vlTOPp->rst)) & ((~ (IData)(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__control_hazard)) 
                                       & (0x2bU == 
                                          (0x3fU & 
                                           (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                            >> 0x1aU)))));
    vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_rs2_out 
        = ((IData)(vlTOPp->rst) ? 0U : ((IData)(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__control_hazard)
                                         ? 0U : vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R
                                        [(0x1fU & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                                   >> 0x10U))]));
    if (vlSymsp->TOP__hw3_tb__core_top_inst.__Vdlyvset__reg_file_inst__DOT__R__v0) {
        vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[0U] = 0U;
        vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[1U] = 0U;
        vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[2U] = 0U;
        vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[3U] = 0U;
        vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[4U] = 0U;
        vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[5U] = 0U;
        vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[6U] = 0U;
        vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[7U] = 0U;
        vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[8U] = 0U;
        vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[9U] = 0U;
        vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[0xaU] = 0U;
        vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[0xbU] = 0U;
        vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[0xcU] = 0U;
        vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[0xdU] = 0U;
        vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[0xeU] = 0U;
        vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[0xfU] = 0U;
        vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[0x10U] = 0U;
        vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[0x11U] = 0U;
        vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[0x12U] = 0U;
        vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[0x13U] = 0U;
        vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[0x14U] = 0U;
        vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[0x15U] = 0U;
        vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[0x16U] = 0U;
        vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[0x17U] = 0U;
        vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[0x18U] = 0U;
        vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[0x19U] = 0U;
        vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[0x1aU] = 0U;
        vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[0x1bU] = 0U;
        vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[0x1cU] = 0U;
        vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[0x1dU] = 0U;
        vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[0x1eU] = 0U;
        vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[0x1fU] = 0U;
    }
    if (vlSymsp->TOP__hw3_tb__core_top_inst.__Vdlyvset__reg_file_inst__DOT__R__v32) {
        vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[vlSymsp->TOP__hw3_tb__core_top_inst.__Vdlyvdim0__reg_file_inst__DOT__R__v32] 
            = vlSymsp->TOP__hw3_tb__core_top_inst.__Vdlyvval__reg_file_inst__DOT__R__v32;
    }
    vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__alu_rs2 
        = ((IData)(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_ssel)
            ? vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_rs2_out
            : vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_imm);
    if (vlTOPp->rst) {
        vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr = 0U;
    } else {
        if (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__pc_write) {
            vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                = vlSymsp->TOP__hw3_tb__core_top_inst__imem_inst.RAM
                [(0xfU & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__pc 
                          >> 2U))];
        } else {
            if (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__control_hazard) {
                vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr = 0U;
            }
        }
    }
    vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__alu_inst__DOT__result 
        = (0x1ffffffffULL & ((8U & vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_op)
                              ? ((4U & vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_op)
                                  ? ((2U & vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_op)
                                      ? ((1U & vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_op)
                                          ? 0ULL : (QData)((IData)(
                                                                   (0xffff0000U 
                                                                    & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__alu_rs2 
                                                                       << 0x10U)))))
                                      : ((1U & vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_op)
                                          ? VL_SHIFTRS_QQI(33,33,5, 
                                                           (0x1ffffffffULL 
                                                            & VL_EXTENDS_QI(33,32, vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_rs1_out)), 
                                                           (0x1fU 
                                                            & vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__alu_rs2))
                                          : (~ ((QData)((IData)(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_rs1_out)) 
                                                | (QData)((IData)(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__alu_rs2))))))
                                  : ((2U & vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_op)
                                      ? ((1U & vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_op)
                                          ? 0ULL : 
                                         ((QData)((IData)(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_rs1_out)) 
                                          >> (0x1fU 
                                              & vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__alu_rs2)))
                                      : ((1U & vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_op)
                                          ? ((QData)((IData)(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_rs1_out)) 
                                             << (0x1fU 
                                                 & vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__alu_rs2))
                                          : 0ULL)))
                              : ((4U & vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_op)
                                  ? ((2U & vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_op)
                                      ? ((1U & vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_op)
                                          ? (QData)((IData)(
                                                            VL_LTS_III(1,32,32, vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_rs1_out, vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__alu_rs2)))
                                          : ((QData)((IData)(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_rs1_out)) 
                                             - (QData)((IData)(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__alu_rs2))))
                                      : 0ULL) : ((2U 
                                                  & vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_op)
                                                  ? 
                                                 ((1U 
                                                   & vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_op)
                                                   ? 0ULL
                                                   : 
                                                  ((QData)((IData)(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_rs1_out)) 
                                                   + (QData)((IData)(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__alu_rs2))))
                                                  : 
                                                 ((1U 
                                                   & vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_op)
                                                   ? 
                                                  ((QData)((IData)(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_rs1_out)) 
                                                   | (QData)((IData)(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__alu_rs2)))
                                                   : 
                                                  ((QData)((IData)(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_rs1_out)) 
                                                   & (QData)((IData)(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__alu_rs2))))))));
    vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__pc = vlSymsp->TOP__hw3_tb__core_top_inst.__Vdly__pc;
    vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__control_hazard 
        = ((((3U == vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_jump_type) 
             | (2U == vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_jump_type)) 
            | (4U == vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_jump_type)) 
           | ((1U == vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_jump_type) 
              & (0U == (IData)(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__alu_inst__DOT__result))));
    vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__pc_increment 
        = ((IData)(4U) + vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__pc);
    vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__op = 
        ((0U == (0x3fU & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                          >> 0x1aU))) ? ((0x20U & vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr)
                                          ? ((0x10U 
                                              & vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr)
                                              ? 0xfU
                                              : ((8U 
                                                  & vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr)
                                                  ? 
                                                 ((4U 
                                                   & vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr)
                                                   ? 0xfU
                                                   : 
                                                  ((2U 
                                                    & vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr)
                                                    ? 
                                                   ((1U 
                                                     & vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr)
                                                     ? 0xfU
                                                     : 7U)
                                                    : 0xfU))
                                                  : 
                                                 ((4U 
                                                   & vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr)
                                                   ? 
                                                  ((2U 
                                                    & vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr)
                                                    ? 
                                                   ((1U 
                                                     & vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr)
                                                     ? 0xcU
                                                     : 0xfU)
                                                    : 
                                                   ((1U 
                                                     & vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr)
                                                     ? 1U
                                                     : 0U))
                                                   : 
                                                  ((2U 
                                                    & vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr)
                                                    ? 
                                                   ((1U 
                                                     & vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr)
                                                     ? 0xfU
                                                     : 6U)
                                                    : 
                                                   ((1U 
                                                     & vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr)
                                                     ? 0xfU
                                                     : 2U)))))
                                          : 0xfU) : 
         ((4U == (0x3fU & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                           >> 0x1aU))) ? 6U : ((((8U 
                                                  == 
                                                  (0x3fU 
                                                   & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                                      >> 0x1aU))) 
                                                 | (0x23U 
                                                    == 
                                                    (0x3fU 
                                                     & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                                        >> 0x1aU)))) 
                                                | (0x2bU 
                                                   == 
                                                   (0x3fU 
                                                    & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                                       >> 0x1aU))))
                                                ? 2U
                                                : (
                                                   (0xaU 
                                                    == 
                                                    (0x3fU 
                                                     & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                                        >> 0x1aU)))
                                                    ? 7U
                                                    : 0xfU))));
    vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__pc_write 
        = (1U & ((~ (((((IData)(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_we_regfile) 
                        & ((vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_rdst_id 
                            == (0x1fU & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                         >> 0x15U))) 
                           | (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_rdst_id 
                              == (0x1fU & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                           >> 0x10U))))) 
                       & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_addr 
                          != vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_addr)) 
                      | (((IData)(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__ex_mem_we_regfile) 
                          & ((vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__ex_mem_rdst_id 
                              == (0x1fU & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                           >> 0x15U))) 
                             | (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__ex_mem_rdst_id 
                                == (0x1fU & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                             >> 0x10U))))) 
                         & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__ex_mem_addr 
                            != vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_addr))) 
                     | (((IData)(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__mem_wb_we_regfile) 
                         & ((vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__mem_wb_rdst_id 
                             == (0x1fU & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                          >> 0x15U))) 
                            | (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__mem_wb_rdst_id 
                               == (0x1fU & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                            >> 0x10U))))) 
                        & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__mem_wb_addr 
                           != vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_addr)))) 
                 & (~ (IData)(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__control_hazard))));
}
