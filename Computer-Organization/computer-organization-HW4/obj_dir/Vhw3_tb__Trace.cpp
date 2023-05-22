// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vhw3_tb__Syms.h"


void Vhw3_tb::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Vhw3_tb__Syms* __restrict vlSymsp = static_cast<Vhw3_tb__Syms*>(userp);
    Vhw3_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vhw3_tb::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Vhw3_tb__Syms* __restrict vlSymsp = static_cast<Vhw3_tb__Syms*>(userp);
    Vhw3_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[0U])) {
            tracep->chgIData(oldp+0,(vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.__PVT__idx),32);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgBit(oldp+1,(vlSymsp->TOP__hw3_tb.finish));
            tracep->chgIData(oldp+2,(vlSymsp->TOP__hw3_tb.__PVT__i),32);
            tracep->chgIData(oldp+3,(vlSymsp->TOP__hw3_tb.__PVT__cycle_count),32);
            tracep->chgIData(oldp+4,(vlSymsp->TOP__hw3_tb.__PVT__golden_reg[0]),32);
            tracep->chgIData(oldp+5,(vlSymsp->TOP__hw3_tb.__PVT__golden_reg[1]),32);
            tracep->chgIData(oldp+6,(vlSymsp->TOP__hw3_tb.__PVT__golden_reg[2]),32);
            tracep->chgIData(oldp+7,(vlSymsp->TOP__hw3_tb.__PVT__golden_reg[3]),32);
            tracep->chgIData(oldp+8,(vlSymsp->TOP__hw3_tb.__PVT__golden_reg[4]),32);
            tracep->chgIData(oldp+9,(vlSymsp->TOP__hw3_tb.__PVT__golden_reg[5]),32);
            tracep->chgIData(oldp+10,(vlSymsp->TOP__hw3_tb.__PVT__golden_reg[6]),32);
            tracep->chgIData(oldp+11,(vlSymsp->TOP__hw3_tb.__PVT__golden_reg[7]),32);
            tracep->chgIData(oldp+12,(vlSymsp->TOP__hw3_tb.__PVT__golden_reg[8]),32);
            tracep->chgIData(oldp+13,(vlSymsp->TOP__hw3_tb.__PVT__golden_reg[9]),32);
            tracep->chgIData(oldp+14,(vlSymsp->TOP__hw3_tb.__PVT__golden_reg[10]),32);
            tracep->chgIData(oldp+15,(vlSymsp->TOP__hw3_tb.__PVT__golden_reg[11]),32);
            tracep->chgIData(oldp+16,(vlSymsp->TOP__hw3_tb.__PVT__golden_reg[12]),32);
            tracep->chgIData(oldp+17,(vlSymsp->TOP__hw3_tb.__PVT__golden_reg[13]),32);
            tracep->chgIData(oldp+18,(vlSymsp->TOP__hw3_tb.__PVT__golden_reg[14]),32);
            tracep->chgIData(oldp+19,(vlSymsp->TOP__hw3_tb.__PVT__golden_reg[15]),32);
            tracep->chgIData(oldp+20,(vlSymsp->TOP__hw3_tb.__PVT__golden_reg[16]),32);
            tracep->chgIData(oldp+21,(vlSymsp->TOP__hw3_tb.__PVT__golden_reg[17]),32);
            tracep->chgIData(oldp+22,(vlSymsp->TOP__hw3_tb.__PVT__golden_reg[18]),32);
            tracep->chgIData(oldp+23,(vlSymsp->TOP__hw3_tb.__PVT__golden_reg[19]),32);
            tracep->chgIData(oldp+24,(vlSymsp->TOP__hw3_tb.__PVT__golden_reg[20]),32);
            tracep->chgIData(oldp+25,(vlSymsp->TOP__hw3_tb.__PVT__golden_reg[21]),32);
            tracep->chgIData(oldp+26,(vlSymsp->TOP__hw3_tb.__PVT__golden_reg[22]),32);
            tracep->chgIData(oldp+27,(vlSymsp->TOP__hw3_tb.__PVT__golden_reg[23]),32);
            tracep->chgIData(oldp+28,(vlSymsp->TOP__hw3_tb.__PVT__golden_reg[24]),32);
            tracep->chgIData(oldp+29,(vlSymsp->TOP__hw3_tb.__PVT__golden_reg[25]),32);
            tracep->chgIData(oldp+30,(vlSymsp->TOP__hw3_tb.__PVT__golden_reg[26]),32);
            tracep->chgIData(oldp+31,(vlSymsp->TOP__hw3_tb.__PVT__golden_reg[27]),32);
            tracep->chgIData(oldp+32,(vlSymsp->TOP__hw3_tb.__PVT__golden_reg[28]),32);
            tracep->chgIData(oldp+33,(vlSymsp->TOP__hw3_tb.__PVT__golden_reg[29]),32);
            tracep->chgIData(oldp+34,(vlSymsp->TOP__hw3_tb.__PVT__golden_reg[30]),32);
            tracep->chgIData(oldp+35,(vlSymsp->TOP__hw3_tb.__PVT__golden_reg[31]),32);
            tracep->chgIData(oldp+36,(vlSymsp->TOP__hw3_tb.__PVT__golden_dmem[0]),32);
            tracep->chgIData(oldp+37,(vlSymsp->TOP__hw3_tb.__PVT__golden_dmem[1]),32);
            tracep->chgIData(oldp+38,(vlSymsp->TOP__hw3_tb.__PVT__golden_dmem[2]),32);
            tracep->chgIData(oldp+39,(vlSymsp->TOP__hw3_tb.__PVT__golden_dmem[3]),32);
            tracep->chgIData(oldp+40,(vlSymsp->TOP__hw3_tb.__PVT__golden_dmem[4]),32);
            tracep->chgIData(oldp+41,(vlSymsp->TOP__hw3_tb.__PVT__golden_dmem[5]),32);
            tracep->chgIData(oldp+42,(vlSymsp->TOP__hw3_tb.__PVT__golden_dmem[6]),32);
            tracep->chgIData(oldp+43,(vlSymsp->TOP__hw3_tb.__PVT__golden_dmem[7]),32);
            tracep->chgIData(oldp+44,(vlSymsp->TOP__hw3_tb.__PVT__golden_dmem[8]),32);
            tracep->chgIData(oldp+45,(vlSymsp->TOP__hw3_tb.__PVT__golden_dmem[9]),32);
            tracep->chgIData(oldp+46,(vlSymsp->TOP__hw3_tb.__PVT__golden_dmem[10]),32);
            tracep->chgIData(oldp+47,(vlSymsp->TOP__hw3_tb.__PVT__golden_dmem[11]),32);
            tracep->chgIData(oldp+48,(vlSymsp->TOP__hw3_tb.__PVT__golden_dmem[12]),32);
            tracep->chgIData(oldp+49,(vlSymsp->TOP__hw3_tb.__PVT__golden_dmem[13]),32);
            tracep->chgIData(oldp+50,(vlSymsp->TOP__hw3_tb.__PVT__golden_dmem[14]),32);
            tracep->chgIData(oldp+51,(vlSymsp->TOP__hw3_tb.__PVT__golden_dmem[15]),32);
            tracep->chgBit(oldp+52,(vlSymsp->TOP__hw3_tb.__PVT__start));
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[2U])) {
            tracep->chgIData(oldp+53,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__pc),32);
            tracep->chgIData(oldp+54,(((IData)(4U) 
                                       + vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__pc)),32);
            tracep->chgBit(oldp+55,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__pc_write));
            tracep->chgCData(oldp+56,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__op),4);
            tracep->chgBit(oldp+57,(((0U == (0x3fU 
                                             & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                                >> 0x1aU))) 
                                     | (4U == (0x3fU 
                                               & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                                  >> 0x1aU))))));
            tracep->chgCData(oldp+58,(((0x23U == (0x3fU 
                                                  & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                                     >> 0x1aU)))
                                        ? 1U : ((3U 
                                                 == 
                                                 (0x3fU 
                                                  & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                                     >> 0x1aU)))
                                                 ? 2U
                                                 : 0U))),2);
            tracep->chgBit(oldp+59,((1U & ((0U == (0x3fU 
                                                   & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                                      >> 0x1aU)))
                                            ? ((8U 
                                                == 
                                                (0x3fU 
                                                 & vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr))
                                                ? 0U
                                                : 1U)
                                            : ((((8U 
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
            tracep->chgBit(oldp+60,((0x2bU == (0x3fU 
                                               & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                                  >> 0x1aU)))));
            tracep->chgCData(oldp+61,(((0x80000000U 
                                        & vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr)
                                        ? 0U : ((0x40000000U 
                                                 & vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr)
                                                 ? 0U
                                                 : 
                                                ((0x20000000U 
                                                  & vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr)
                                                  ? 0U
                                                  : 
                                                 ((0x10000000U 
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
                                                      : 0U)))))))),3);
            tracep->chgIData(oldp+62,((0x3ffffffU & vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr)),26);
            tracep->chgIData(oldp+63,(((0xffff0000U 
                                        & ((- (IData)(
                                                      (1U 
                                                       & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                                          >> 0xfU)))) 
                                           << 0x10U)) 
                                       | (0xffffU & vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr))),32);
            tracep->chgCData(oldp+64,((0x1fU & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                                >> 0x15U))),5);
            tracep->chgCData(oldp+65,((0x1fU & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                                >> 0x10U))),5);
            tracep->chgCData(oldp+66,((0x1fU & ((0U 
                                                 == 
                                                 (0x3fU 
                                                  & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                                     >> 0x1aU)))
                                                 ? 
                                                (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                                 >> 0xbU)
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
                                                   : 0U))))),5);
            tracep->chgIData(oldp+67,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R
                                      [(0x1fU & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                                 >> 0x15U))]),32);
            tracep->chgIData(oldp+68,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R
                                      [(0x1fU & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                                 >> 0x10U))]),32);
            tracep->chgIData(oldp+69,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_rs1_out),32);
            tracep->chgIData(oldp+70,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__alu_rs2),32);
            tracep->chgIData(oldp+71,((IData)(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__alu_inst__DOT__result)),32);
            tracep->chgBit(oldp+72,((0U == (IData)(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__alu_inst__DOT__result))));
            tracep->chgBit(oldp+73,((1U & ((2U == (0xfU 
                                                   & vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_op))
                                            ? ((~ (
                                                   (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_rs1_out 
                                                    ^ vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__alu_rs2) 
                                                   >> 0x1fU)) 
                                               & ((vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_rs1_out 
                                                   >> 0x1fU) 
                                                  ^ (IData)(
                                                            (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__alu_inst__DOT__result 
                                                             >> 0x1fU))))
                                            : ((6U 
                                                == 
                                                (0xfU 
                                                 & vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_op)) 
                                               & (((vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_rs1_out 
                                                    ^ vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__alu_rs2) 
                                                   >> 0x1fU) 
                                                  & ((vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_rs1_out 
                                                      >> 0x1fU) 
                                                     ^ (IData)(
                                                               (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__alu_inst__DOT__result 
                                                                >> 0x1fU)))))))));
            tracep->chgIData(oldp+74,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_addr),32);
            tracep->chgIData(oldp+75,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr),32);
            tracep->chgIData(oldp+76,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_addr),32);
            tracep->chgIData(oldp+77,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_jump_type),32);
            tracep->chgIData(oldp+78,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_jump_addr),32);
            tracep->chgIData(oldp+79,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_op),32);
            tracep->chgIData(oldp+80,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_imm),32);
            tracep->chgIData(oldp+81,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_rs2_out),32);
            tracep->chgIData(oldp+82,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_rdst_id),32);
            tracep->chgBit(oldp+83,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_we_regfile));
            tracep->chgBit(oldp+84,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_we_dmem));
            tracep->chgCData(oldp+85,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_wbsel),2);
            tracep->chgBit(oldp+86,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_ssel));
            tracep->chgIData(oldp+87,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__ex_mem_addr),32);
            tracep->chgIData(oldp+88,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__ex_mem_alu_out),32);
            tracep->chgIData(oldp+89,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__ex_mem_rs2_out),32);
            tracep->chgIData(oldp+90,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__ex_mem_rdst_id),32);
            tracep->chgBit(oldp+91,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__ex_mem_we_regfile));
            tracep->chgBit(oldp+92,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__ex_mem_we_dmem));
            tracep->chgCData(oldp+93,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__ex_mem_wbsel),2);
            tracep->chgIData(oldp+94,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__mem_wb_addr),32);
            tracep->chgIData(oldp+95,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__mem_wb_rd),32);
            tracep->chgIData(oldp+96,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__mem_wb_rdst_id),32);
            tracep->chgBit(oldp+97,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__mem_wb_we_regfile));
            tracep->chgBit(oldp+98,((((((IData)(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_we_regfile) 
                                        & ((vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_rdst_id 
                                            == (0x1fU 
                                                & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                                   >> 0x15U))) 
                                           | (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_rdst_id 
                                              == (0x1fU 
                                                  & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                                     >> 0x10U))))) 
                                       & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_addr 
                                          != vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_addr)) 
                                      | (((IData)(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__ex_mem_we_regfile) 
                                          & ((vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__ex_mem_rdst_id 
                                              == (0x1fU 
                                                  & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                                     >> 0x15U))) 
                                             | (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__ex_mem_rdst_id 
                                                == 
                                                (0x1fU 
                                                 & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                                    >> 0x10U))))) 
                                         & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__ex_mem_addr 
                                            != vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_addr))) 
                                     | (((IData)(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__mem_wb_we_regfile) 
                                         & ((vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__mem_wb_rdst_id 
                                             == (0x1fU 
                                                 & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                                    >> 0x15U))) 
                                            | (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__mem_wb_rdst_id 
                                               == (0x1fU 
                                                   & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                                      >> 0x10U))))) 
                                        & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__mem_wb_addr 
                                           != vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_addr)))));
            tracep->chgBit(oldp+99,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__control_hazard));
            tracep->chgCData(oldp+100,((0x3fU & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                                 >> 0x1aU))),6);
            tracep->chgCData(oldp+101,((0x1fU & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                                 >> 0xbU))),5);
            tracep->chgCData(oldp+102,((0x1fU & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                                 >> 6U))),5);
            tracep->chgCData(oldp+103,((0x3fU & vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr)),6);
            tracep->chgSData(oldp+104,((0xffffU & vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr)),16);
            tracep->chgBit(oldp+105,((0U == (0x3fU 
                                             & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                                >> 0x1aU)))));
            tracep->chgBit(oldp+106,((8U == (0x3fU 
                                             & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                                >> 0x1aU)))));
            tracep->chgBit(oldp+107,((0xaU == (0x3fU 
                                               & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                                  >> 0x1aU)))));
            tracep->chgBit(oldp+108,((0x23U == (0x3fU 
                                                & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                                   >> 0x1aU)))));
            tracep->chgBit(oldp+109,((4U == (0x3fU 
                                             & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                                >> 0x1aU)))));
            tracep->chgBit(oldp+110,((3U == (0x3fU 
                                             & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                                >> 0x1aU)))));
            tracep->chgBit(oldp+111,((2U == (0x3fU 
                                             & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                                >> 0x1aU)))));
            tracep->chgCData(oldp+112,((0x1fU & vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__mem_wb_rdst_id)),5);
            tracep->chgIData(oldp+113,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[0]),32);
            tracep->chgIData(oldp+114,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[1]),32);
            tracep->chgIData(oldp+115,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[2]),32);
            tracep->chgIData(oldp+116,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[3]),32);
            tracep->chgIData(oldp+117,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[4]),32);
            tracep->chgIData(oldp+118,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[5]),32);
            tracep->chgIData(oldp+119,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[6]),32);
            tracep->chgIData(oldp+120,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[7]),32);
            tracep->chgIData(oldp+121,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[8]),32);
            tracep->chgIData(oldp+122,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[9]),32);
            tracep->chgIData(oldp+123,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[10]),32);
            tracep->chgIData(oldp+124,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[11]),32);
            tracep->chgIData(oldp+125,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[12]),32);
            tracep->chgIData(oldp+126,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[13]),32);
            tracep->chgIData(oldp+127,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[14]),32);
            tracep->chgIData(oldp+128,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[15]),32);
            tracep->chgIData(oldp+129,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[16]),32);
            tracep->chgIData(oldp+130,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[17]),32);
            tracep->chgIData(oldp+131,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[18]),32);
            tracep->chgIData(oldp+132,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[19]),32);
            tracep->chgIData(oldp+133,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[20]),32);
            tracep->chgIData(oldp+134,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[21]),32);
            tracep->chgIData(oldp+135,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[22]),32);
            tracep->chgIData(oldp+136,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[23]),32);
            tracep->chgIData(oldp+137,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[24]),32);
            tracep->chgIData(oldp+138,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[25]),32);
            tracep->chgIData(oldp+139,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[26]),32);
            tracep->chgIData(oldp+140,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[27]),32);
            tracep->chgIData(oldp+141,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[28]),32);
            tracep->chgIData(oldp+142,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[29]),32);
            tracep->chgIData(oldp+143,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[30]),32);
            tracep->chgIData(oldp+144,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[31]),32);
            tracep->chgIData(oldp+145,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__i),32);
            tracep->chgCData(oldp+146,((0xfU & vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_op)),4);
            tracep->chgQData(oldp+147,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__alu_inst__DOT__result),33);
            tracep->chgCData(oldp+149,((0x3fU & vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__ex_mem_alu_out)),6);
            tracep->chgCData(oldp+150,((0x3fU & vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__pc)),6);
        }
        tracep->chgBit(oldp+151,(vlTOPp->clk));
        tracep->chgBit(oldp+152,(vlTOPp->rst));
        tracep->chgBit(oldp+153,(vlTOPp->finish));
        tracep->chgIData(oldp+154,(vlSymsp->TOP__hw3_tb__core_top_inst__imem_inst.RAM
                                   [(0xfU & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__pc 
                                             >> 2U))]),32);
        tracep->chgIData(oldp+155,(((0U == (IData)(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__ex_mem_wbsel))
                                     ? vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__ex_mem_alu_out
                                     : ((1U == (IData)(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__ex_mem_wbsel))
                                         ? vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM
                                        [(0xfU & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__ex_mem_alu_out 
                                                  >> 2U))]
                                         : ((2U == (IData)(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__ex_mem_wbsel))
                                             ? ((IData)(4U) 
                                                + vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__ex_mem_addr)
                                             : 0U)))),32);
        tracep->chgIData(oldp+156,(vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM
                                   [(0xfU & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__ex_mem_alu_out 
                                             >> 2U))]),32);
        tracep->chgIData(oldp+157,(vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM[0]),32);
        tracep->chgIData(oldp+158,(vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM[1]),32);
        tracep->chgIData(oldp+159,(vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM[2]),32);
        tracep->chgIData(oldp+160,(vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM[3]),32);
        tracep->chgIData(oldp+161,(vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM[4]),32);
        tracep->chgIData(oldp+162,(vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM[5]),32);
        tracep->chgIData(oldp+163,(vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM[6]),32);
        tracep->chgIData(oldp+164,(vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM[7]),32);
        tracep->chgIData(oldp+165,(vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM[8]),32);
        tracep->chgIData(oldp+166,(vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM[9]),32);
        tracep->chgIData(oldp+167,(vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM[10]),32);
        tracep->chgIData(oldp+168,(vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM[11]),32);
        tracep->chgIData(oldp+169,(vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM[12]),32);
        tracep->chgIData(oldp+170,(vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM[13]),32);
        tracep->chgIData(oldp+171,(vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM[14]),32);
        tracep->chgIData(oldp+172,(vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM[15]),32);
        tracep->chgIData(oldp+173,(vlSymsp->TOP__hw3_tb__core_top_inst__imem_inst.RAM[0]),32);
        tracep->chgIData(oldp+174,(vlSymsp->TOP__hw3_tb__core_top_inst__imem_inst.RAM[1]),32);
        tracep->chgIData(oldp+175,(vlSymsp->TOP__hw3_tb__core_top_inst__imem_inst.RAM[2]),32);
        tracep->chgIData(oldp+176,(vlSymsp->TOP__hw3_tb__core_top_inst__imem_inst.RAM[3]),32);
        tracep->chgIData(oldp+177,(vlSymsp->TOP__hw3_tb__core_top_inst__imem_inst.RAM[4]),32);
        tracep->chgIData(oldp+178,(vlSymsp->TOP__hw3_tb__core_top_inst__imem_inst.RAM[5]),32);
        tracep->chgIData(oldp+179,(vlSymsp->TOP__hw3_tb__core_top_inst__imem_inst.RAM[6]),32);
        tracep->chgIData(oldp+180,(vlSymsp->TOP__hw3_tb__core_top_inst__imem_inst.RAM[7]),32);
        tracep->chgIData(oldp+181,(vlSymsp->TOP__hw3_tb__core_top_inst__imem_inst.RAM[8]),32);
        tracep->chgIData(oldp+182,(vlSymsp->TOP__hw3_tb__core_top_inst__imem_inst.RAM[9]),32);
        tracep->chgIData(oldp+183,(vlSymsp->TOP__hw3_tb__core_top_inst__imem_inst.RAM[10]),32);
        tracep->chgIData(oldp+184,(vlSymsp->TOP__hw3_tb__core_top_inst__imem_inst.RAM[11]),32);
        tracep->chgIData(oldp+185,(vlSymsp->TOP__hw3_tb__core_top_inst__imem_inst.RAM[12]),32);
        tracep->chgIData(oldp+186,(vlSymsp->TOP__hw3_tb__core_top_inst__imem_inst.RAM[13]),32);
        tracep->chgIData(oldp+187,(vlSymsp->TOP__hw3_tb__core_top_inst__imem_inst.RAM[14]),32);
        tracep->chgIData(oldp+188,(vlSymsp->TOP__hw3_tb__core_top_inst__imem_inst.RAM[15]),32);
    }
}

void Vhw3_tb::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vhw3_tb__Syms* __restrict vlSymsp = static_cast<Vhw3_tb__Syms*>(userp);
    Vhw3_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
        vlTOPp->__Vm_traceActivity[2U] = 0U;
    }
}
