// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vhw3_tb.h for the primary calling header

#include "Vhw3_tb_core_top.h"
#include "Vhw3_tb__Syms.h"

#include "verilated_dpi.h"

//==========

VL_CTOR_IMP(Vhw3_tb_core_top) {
    VL_CELL(imem_inst, Vhw3_tb_imem);
    VL_CELL(dmem_inst, Vhw3_tb_dmem);
    // Reset internal values
    // Reset structure values
    _ctor_var_reset();
}

void Vhw3_tb_core_top::__Vconfigure(Vhw3_tb__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
}

Vhw3_tb_core_top::~Vhw3_tb_core_top() {
}

void Vhw3_tb_core_top::_settle__TOP__hw3_tb__core_top_inst__3(Vhw3_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vhw3_tb_core_top::_settle__TOP__hw3_tb__core_top_inst__3\n"); );
    Vhw3_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__alu_rs2 
        = ((IData)(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_ssel)
            ? vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_rs2_out
            : vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_imm);
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
    vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__control_hazard 
        = ((((3U == vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_jump_type) 
             | (2U == vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_jump_type)) 
            | (4U == vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_jump_type)) 
           | ((1U == vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_jump_type) 
              & (0U == (IData)(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__alu_inst__DOT__result))));
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

void Vhw3_tb_core_top::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vhw3_tb_core_top::_ctor_var_reset\n"); );
    // Body
    __PVT__clk = VL_RAND_RESET_I(1);
    __PVT__rst = VL_RAND_RESET_I(1);
    __PVT__pc = VL_RAND_RESET_I(32);
    __PVT__pc_increment = VL_RAND_RESET_I(32);
    __PVT__pc_write = VL_RAND_RESET_I(1);
    __PVT__op = VL_RAND_RESET_I(4);
    __PVT__alu_rs2 = VL_RAND_RESET_I(32);
    __PVT__if_id_addr = VL_RAND_RESET_I(32);
    __PVT__if_id_instr = VL_RAND_RESET_I(32);
    __PVT__id_ex_addr = VL_RAND_RESET_I(32);
    __PVT__id_ex_jump_type = VL_RAND_RESET_I(32);
    __PVT__id_ex_jump_addr = VL_RAND_RESET_I(32);
    __PVT__id_ex_op = VL_RAND_RESET_I(32);
    __PVT__id_ex_imm = VL_RAND_RESET_I(32);
    __PVT__id_ex_rs1_out = VL_RAND_RESET_I(32);
    __PVT__id_ex_rs2_out = VL_RAND_RESET_I(32);
    __PVT__id_ex_rdst_id = VL_RAND_RESET_I(32);
    __PVT__id_ex_we_regfile = VL_RAND_RESET_I(1);
    __PVT__id_ex_we_dmem = VL_RAND_RESET_I(1);
    __PVT__id_ex_wbsel = VL_RAND_RESET_I(2);
    __PVT__id_ex_ssel = VL_RAND_RESET_I(1);
    __PVT__ex_mem_addr = VL_RAND_RESET_I(32);
    __PVT__ex_mem_alu_out = VL_RAND_RESET_I(32);
    __PVT__ex_mem_rs2_out = VL_RAND_RESET_I(32);
    __PVT__ex_mem_rdst_id = VL_RAND_RESET_I(32);
    __PVT__ex_mem_we_regfile = VL_RAND_RESET_I(1);
    __PVT__ex_mem_we_dmem = VL_RAND_RESET_I(1);
    __PVT__ex_mem_wbsel = VL_RAND_RESET_I(2);
    __PVT__mem_wb_addr = VL_RAND_RESET_I(32);
    __PVT__mem_wb_rd = VL_RAND_RESET_I(32);
    __PVT__mem_wb_rdst_id = VL_RAND_RESET_I(32);
    __PVT__mem_wb_we_regfile = VL_RAND_RESET_I(1);
    __PVT__control_hazard = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<32; ++__Vi0) {
            __PVT__reg_file_inst__DOT__R[__Vi0] = VL_RAND_RESET_I(32);
    }}
    __PVT__reg_file_inst__DOT__i = VL_RAND_RESET_I(32);
    __PVT__alu_inst__DOT__result = VL_RAND_RESET_Q(33);
    __Vdly__pc = VL_RAND_RESET_I(32);
    __Vdlyvset__reg_file_inst__DOT__R__v0 = 0;
    __Vdlyvdim0__reg_file_inst__DOT__R__v32 = 0;
    __Vdlyvval__reg_file_inst__DOT__R__v32 = VL_RAND_RESET_I(32);
    __Vdlyvset__reg_file_inst__DOT__R__v32 = 0;
}
