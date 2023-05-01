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
            tracep->chgIData(oldp+0,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imem_inst__DOT__RAM[0]),32);
            tracep->chgIData(oldp+1,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imem_inst__DOT__RAM[1]),32);
            tracep->chgIData(oldp+2,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imem_inst__DOT__RAM[2]),32);
            tracep->chgIData(oldp+3,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imem_inst__DOT__RAM[3]),32);
            tracep->chgIData(oldp+4,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imem_inst__DOT__RAM[4]),32);
            tracep->chgIData(oldp+5,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imem_inst__DOT__RAM[5]),32);
            tracep->chgIData(oldp+6,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imem_inst__DOT__RAM[6]),32);
            tracep->chgIData(oldp+7,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imem_inst__DOT__RAM[7]),32);
            tracep->chgIData(oldp+8,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imem_inst__DOT__RAM[8]),32);
            tracep->chgIData(oldp+9,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imem_inst__DOT__RAM[9]),32);
            tracep->chgIData(oldp+10,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imem_inst__DOT__RAM[10]),32);
            tracep->chgIData(oldp+11,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imem_inst__DOT__RAM[11]),32);
            tracep->chgIData(oldp+12,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imem_inst__DOT__RAM[12]),32);
            tracep->chgIData(oldp+13,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imem_inst__DOT__RAM[13]),32);
            tracep->chgIData(oldp+14,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imem_inst__DOT__RAM[14]),32);
            tracep->chgIData(oldp+15,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imem_inst__DOT__RAM[15]),32);
            tracep->chgIData(oldp+16,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__idx),32);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgIData(oldp+17,(vlTOPp->hw3_tb__DOT__i),32);
            tracep->chgIData(oldp+18,(vlTOPp->hw3_tb__DOT__cycle_count),32);
            tracep->chgIData(oldp+19,(vlTOPp->hw3_tb__DOT__golden_reg[0]),32);
            tracep->chgIData(oldp+20,(vlTOPp->hw3_tb__DOT__golden_reg[1]),32);
            tracep->chgIData(oldp+21,(vlTOPp->hw3_tb__DOT__golden_reg[2]),32);
            tracep->chgIData(oldp+22,(vlTOPp->hw3_tb__DOT__golden_reg[3]),32);
            tracep->chgIData(oldp+23,(vlTOPp->hw3_tb__DOT__golden_reg[4]),32);
            tracep->chgIData(oldp+24,(vlTOPp->hw3_tb__DOT__golden_reg[5]),32);
            tracep->chgIData(oldp+25,(vlTOPp->hw3_tb__DOT__golden_reg[6]),32);
            tracep->chgIData(oldp+26,(vlTOPp->hw3_tb__DOT__golden_reg[7]),32);
            tracep->chgIData(oldp+27,(vlTOPp->hw3_tb__DOT__golden_reg[8]),32);
            tracep->chgIData(oldp+28,(vlTOPp->hw3_tb__DOT__golden_reg[9]),32);
            tracep->chgIData(oldp+29,(vlTOPp->hw3_tb__DOT__golden_reg[10]),32);
            tracep->chgIData(oldp+30,(vlTOPp->hw3_tb__DOT__golden_reg[11]),32);
            tracep->chgIData(oldp+31,(vlTOPp->hw3_tb__DOT__golden_reg[12]),32);
            tracep->chgIData(oldp+32,(vlTOPp->hw3_tb__DOT__golden_reg[13]),32);
            tracep->chgIData(oldp+33,(vlTOPp->hw3_tb__DOT__golden_reg[14]),32);
            tracep->chgIData(oldp+34,(vlTOPp->hw3_tb__DOT__golden_reg[15]),32);
            tracep->chgIData(oldp+35,(vlTOPp->hw3_tb__DOT__golden_reg[16]),32);
            tracep->chgIData(oldp+36,(vlTOPp->hw3_tb__DOT__golden_reg[17]),32);
            tracep->chgIData(oldp+37,(vlTOPp->hw3_tb__DOT__golden_reg[18]),32);
            tracep->chgIData(oldp+38,(vlTOPp->hw3_tb__DOT__golden_reg[19]),32);
            tracep->chgIData(oldp+39,(vlTOPp->hw3_tb__DOT__golden_reg[20]),32);
            tracep->chgIData(oldp+40,(vlTOPp->hw3_tb__DOT__golden_reg[21]),32);
            tracep->chgIData(oldp+41,(vlTOPp->hw3_tb__DOT__golden_reg[22]),32);
            tracep->chgIData(oldp+42,(vlTOPp->hw3_tb__DOT__golden_reg[23]),32);
            tracep->chgIData(oldp+43,(vlTOPp->hw3_tb__DOT__golden_reg[24]),32);
            tracep->chgIData(oldp+44,(vlTOPp->hw3_tb__DOT__golden_reg[25]),32);
            tracep->chgIData(oldp+45,(vlTOPp->hw3_tb__DOT__golden_reg[26]),32);
            tracep->chgIData(oldp+46,(vlTOPp->hw3_tb__DOT__golden_reg[27]),32);
            tracep->chgIData(oldp+47,(vlTOPp->hw3_tb__DOT__golden_reg[28]),32);
            tracep->chgIData(oldp+48,(vlTOPp->hw3_tb__DOT__golden_reg[29]),32);
            tracep->chgIData(oldp+49,(vlTOPp->hw3_tb__DOT__golden_reg[30]),32);
            tracep->chgIData(oldp+50,(vlTOPp->hw3_tb__DOT__golden_reg[31]),32);
            tracep->chgIData(oldp+51,(vlTOPp->hw3_tb__DOT__golden_dmem[0]),32);
            tracep->chgIData(oldp+52,(vlTOPp->hw3_tb__DOT__golden_dmem[1]),32);
            tracep->chgIData(oldp+53,(vlTOPp->hw3_tb__DOT__golden_dmem[2]),32);
            tracep->chgIData(oldp+54,(vlTOPp->hw3_tb__DOT__golden_dmem[3]),32);
            tracep->chgIData(oldp+55,(vlTOPp->hw3_tb__DOT__golden_dmem[4]),32);
            tracep->chgIData(oldp+56,(vlTOPp->hw3_tb__DOT__golden_dmem[5]),32);
            tracep->chgIData(oldp+57,(vlTOPp->hw3_tb__DOT__golden_dmem[6]),32);
            tracep->chgIData(oldp+58,(vlTOPp->hw3_tb__DOT__golden_dmem[7]),32);
            tracep->chgIData(oldp+59,(vlTOPp->hw3_tb__DOT__golden_dmem[8]),32);
            tracep->chgIData(oldp+60,(vlTOPp->hw3_tb__DOT__golden_dmem[9]),32);
            tracep->chgIData(oldp+61,(vlTOPp->hw3_tb__DOT__golden_dmem[10]),32);
            tracep->chgIData(oldp+62,(vlTOPp->hw3_tb__DOT__golden_dmem[11]),32);
            tracep->chgIData(oldp+63,(vlTOPp->hw3_tb__DOT__golden_dmem[12]),32);
            tracep->chgIData(oldp+64,(vlTOPp->hw3_tb__DOT__golden_dmem[13]),32);
            tracep->chgIData(oldp+65,(vlTOPp->hw3_tb__DOT__golden_dmem[14]),32);
            tracep->chgIData(oldp+66,(vlTOPp->hw3_tb__DOT__golden_dmem[15]),32);
            tracep->chgBit(oldp+67,(vlTOPp->hw3_tb__DOT__start));
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[2U])) {
            tracep->chgIData(oldp+68,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__instr_o),32);
            tracep->chgIData(oldp+69,(((IData)(4U) 
                                       + vlTOPp->hw3_tb__DOT__core_top_inst__DOT__pc)),32);
            tracep->chgCData(oldp+70,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__jump_type),2);
            tracep->chgIData(oldp+71,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__jump_addr),32);
            tracep->chgBit(oldp+72,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__we_dmem));
            tracep->chgBit(oldp+73,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__we_regfile));
            tracep->chgCData(oldp+74,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT____Vcellout__decode_inst__op),5);
            tracep->chgCData(oldp+75,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__ssel),2);
            tracep->chgIData(oldp+76,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imm),32);
            tracep->chgCData(oldp+77,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__rs1_id),5);
            tracep->chgCData(oldp+78,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__rs2_id),5);
            tracep->chgCData(oldp+79,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__rdst_id),5);
            tracep->chgBit(oldp+80,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_data_sel));
            tracep->chgIData(oldp+81,((vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imm 
                                       << 2U)),32);
            tracep->chgIData(oldp+82,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__pc),32);
            tracep->chgCData(oldp+83,((0x3fU & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__pc)),6);
            tracep->chgCData(oldp+84,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT____Vcellout__decode_inst__op),4);
            tracep->chgIData(oldp+85,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM[0]),32);
            tracep->chgIData(oldp+86,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM[1]),32);
            tracep->chgIData(oldp+87,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM[2]),32);
            tracep->chgIData(oldp+88,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM[3]),32);
            tracep->chgIData(oldp+89,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM[4]),32);
            tracep->chgIData(oldp+90,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM[5]),32);
            tracep->chgIData(oldp+91,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM[6]),32);
            tracep->chgIData(oldp+92,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM[7]),32);
            tracep->chgIData(oldp+93,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM[8]),32);
            tracep->chgIData(oldp+94,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM[9]),32);
            tracep->chgIData(oldp+95,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM[10]),32);
            tracep->chgIData(oldp+96,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM[11]),32);
            tracep->chgIData(oldp+97,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM[12]),32);
            tracep->chgIData(oldp+98,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM[13]),32);
            tracep->chgIData(oldp+99,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM[14]),32);
            tracep->chgIData(oldp+100,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM[15]),32);
        }
        if (VL_UNLIKELY((vlTOPp->__Vm_traceActivity
                         [2U] | vlTOPp->__Vm_traceActivity
                         [3U]))) {
            tracep->chgIData(oldp+101,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[0]),32);
            tracep->chgIData(oldp+102,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[1]),32);
            tracep->chgIData(oldp+103,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[2]),32);
            tracep->chgIData(oldp+104,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[3]),32);
            tracep->chgIData(oldp+105,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[4]),32);
            tracep->chgIData(oldp+106,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[5]),32);
            tracep->chgIData(oldp+107,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[6]),32);
            tracep->chgIData(oldp+108,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[7]),32);
            tracep->chgIData(oldp+109,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[8]),32);
            tracep->chgIData(oldp+110,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[9]),32);
            tracep->chgIData(oldp+111,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[10]),32);
            tracep->chgIData(oldp+112,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[11]),32);
            tracep->chgIData(oldp+113,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[12]),32);
            tracep->chgIData(oldp+114,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[13]),32);
            tracep->chgIData(oldp+115,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[14]),32);
            tracep->chgIData(oldp+116,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[15]),32);
            tracep->chgIData(oldp+117,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[16]),32);
            tracep->chgIData(oldp+118,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[17]),32);
            tracep->chgIData(oldp+119,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[18]),32);
            tracep->chgIData(oldp+120,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[19]),32);
            tracep->chgIData(oldp+121,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[20]),32);
            tracep->chgIData(oldp+122,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[21]),32);
            tracep->chgIData(oldp+123,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[22]),32);
            tracep->chgIData(oldp+124,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[23]),32);
            tracep->chgIData(oldp+125,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[24]),32);
            tracep->chgIData(oldp+126,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[25]),32);
            tracep->chgIData(oldp+127,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[26]),32);
            tracep->chgIData(oldp+128,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[27]),32);
            tracep->chgIData(oldp+129,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[28]),32);
            tracep->chgIData(oldp+130,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[29]),32);
            tracep->chgIData(oldp+131,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[30]),32);
            tracep->chgIData(oldp+132,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[31]),32);
        }
        if (VL_UNLIKELY((vlTOPp->__Vm_traceActivity
                         [2U] | vlTOPp->__Vm_traceActivity
                         [4U]))) {
            tracep->chgIData(oldp+133,(((2U & (IData)(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__jump_type))
                                         ? ((1U & (IData)(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__jump_type))
                                             ? ((IData)(4U) 
                                                + vlTOPp->hw3_tb__DOT__core_top_inst__DOT__pc)
                                             : vlTOPp->hw3_tb__DOT__core_top_inst__DOT__jump_addr)
                                         : ((1U & (IData)(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__jump_type))
                                             ? ((IData)(4U) 
                                                + (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__pc 
                                                   + 
                                                   ((IData)(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__zero)
                                                     ? 
                                                    ((IData)(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__zero)
                                                      ? 
                                                     (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imm 
                                                      << 2U)
                                                      : 0U)
                                                     : 0U)))
                                             : vlTOPp->hw3_tb__DOT__core_top_inst__DOT__rs1))),32);
            tracep->chgIData(oldp+134,(((IData)(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__zero)
                                         ? ((IData)(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__zero)
                                             ? (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imm 
                                                << 2U)
                                             : 0U) : 0U)),32);
            tracep->chgIData(oldp+135,(((IData)(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_data_sel)
                                         ? ((IData)(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_data_sel)
                                             ? vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM
                                            [(0xfU 
                                              & (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_addr 
                                                 >> 2U))]
                                             : 0U) : vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_addr)),32);
            tracep->chgIData(oldp+136,(((IData)(4U) 
                                        + (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__pc 
                                           + ((IData)(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__zero)
                                               ? ((IData)(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__zero)
                                                   ? 
                                                  (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imm 
                                                   << 2U)
                                                   : 0U)
                                               : 0U)))),32);
            tracep->chgIData(oldp+137,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM
                                       [(0xfU & (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_addr 
                                                 >> 2U))]),32);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[4U])) {
            tracep->chgIData(oldp+138,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__rs1),32);
            tracep->chgIData(oldp+139,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_rs2),32);
            tracep->chgIData(oldp+140,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__alu_rs2),32);
            tracep->chgBit(oldp+141,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__zero));
            tracep->chgIData(oldp+142,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_addr),32);
            tracep->chgBit(oldp+143,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__alu_inst__DOT__overflow));
            tracep->chgCData(oldp+144,((0x3fU & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_addr)),6);
        }
        tracep->chgBit(oldp+145,(vlTOPp->clk));
        tracep->chgBit(oldp+146,(vlTOPp->rst));
        tracep->chgBit(oldp+147,(vlTOPp->finish));
        tracep->chgIData(oldp+148,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__unnamedblk1__DOT__i),32);
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
        vlTOPp->__Vm_traceActivity[3U] = 0U;
        vlTOPp->__Vm_traceActivity[4U] = 0U;
    }
}
