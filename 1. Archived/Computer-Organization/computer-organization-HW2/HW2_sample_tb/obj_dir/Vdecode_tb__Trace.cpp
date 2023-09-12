// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vdecode_tb__Syms.h"


void Vdecode_tb::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Vdecode_tb__Syms* __restrict vlSymsp = static_cast<Vdecode_tb__Syms*>(userp);
    Vdecode_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vdecode_tb::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Vdecode_tb__Syms* __restrict vlSymsp = static_cast<Vdecode_tb__Syms*>(userp);
    Vdecode_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY((vlTOPp->__Vm_traceActivity
                         [1U] | vlTOPp->__Vm_traceActivity
                         [2U]))) {
            tracep->chgIData(oldp+0,(vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[0]),32);
            tracep->chgIData(oldp+1,(vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[1]),32);
            tracep->chgIData(oldp+2,(vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[2]),32);
            tracep->chgIData(oldp+3,(vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[3]),32);
            tracep->chgIData(oldp+4,(vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[4]),32);
            tracep->chgIData(oldp+5,(vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[5]),32);
            tracep->chgIData(oldp+6,(vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[6]),32);
            tracep->chgIData(oldp+7,(vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[7]),32);
            tracep->chgIData(oldp+8,(vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[8]),32);
            tracep->chgIData(oldp+9,(vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[9]),32);
            tracep->chgIData(oldp+10,(vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[10]),32);
            tracep->chgIData(oldp+11,(vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[11]),32);
            tracep->chgIData(oldp+12,(vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[12]),32);
            tracep->chgIData(oldp+13,(vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[13]),32);
            tracep->chgIData(oldp+14,(vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[14]),32);
            tracep->chgIData(oldp+15,(vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[15]),32);
            tracep->chgIData(oldp+16,(vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[16]),32);
            tracep->chgIData(oldp+17,(vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[17]),32);
            tracep->chgIData(oldp+18,(vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[18]),32);
            tracep->chgIData(oldp+19,(vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[19]),32);
            tracep->chgIData(oldp+20,(vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[20]),32);
            tracep->chgIData(oldp+21,(vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[21]),32);
            tracep->chgIData(oldp+22,(vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[22]),32);
            tracep->chgIData(oldp+23,(vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[23]),32);
            tracep->chgIData(oldp+24,(vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[24]),32);
            tracep->chgIData(oldp+25,(vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[25]),32);
            tracep->chgIData(oldp+26,(vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[26]),32);
            tracep->chgIData(oldp+27,(vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[27]),32);
            tracep->chgIData(oldp+28,(vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[28]),32);
            tracep->chgIData(oldp+29,(vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[29]),32);
            tracep->chgIData(oldp+30,(vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[30]),32);
            tracep->chgIData(oldp+31,(vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[31]),32);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[2U])) {
            tracep->chgIData(oldp+32,(vlTOPp->decode_tb__DOT__instr),32);
            tracep->chgCData(oldp+33,(vlTOPp->decode_tb__DOT__op),4);
            tracep->chgBit(oldp+34,(vlTOPp->decode_tb__DOT__ssel));
            tracep->chgIData(oldp+35,(vlTOPp->decode_tb__DOT__imm),32);
            tracep->chgCData(oldp+36,(vlTOPp->decode_tb__DOT__rs1_id),5);
            tracep->chgCData(oldp+37,(vlTOPp->decode_tb__DOT__rs2_id),5);
            tracep->chgCData(oldp+38,(vlTOPp->decode_tb__DOT__rdst_id),5);
            tracep->chgIData(oldp+39,(vlTOPp->decode_tb__DOT__rs2_reg_file_out),32);
            tracep->chgIData(oldp+40,(vlTOPp->decode_tb__DOT__rd),32);
            tracep->chgIData(oldp+41,(vlTOPp->decode_tb__DOT__rs1),32);
            tracep->chgIData(oldp+42,(vlTOPp->decode_tb__DOT__rs2),32);
            tracep->chgBit(oldp+43,(vlTOPp->decode_tb__DOT__zero));
            tracep->chgBit(oldp+44,(vlTOPp->decode_tb__DOT__overflow));
            tracep->chgCData(oldp+45,(vlTOPp->decode_tb__DOT__golden_op),4);
            tracep->chgBit(oldp+46,(vlTOPp->decode_tb__DOT__golden_ssel));
            tracep->chgIData(oldp+47,(vlTOPp->decode_tb__DOT__golden_imm),32);
            tracep->chgCData(oldp+48,(vlTOPp->decode_tb__DOT__golden_rs1_id),5);
            tracep->chgCData(oldp+49,(vlTOPp->decode_tb__DOT__golden_rs2_id),5);
            tracep->chgCData(oldp+50,(vlTOPp->decode_tb__DOT__golden_rdst_id),5);
            tracep->chgBit(oldp+51,((1U & (~ (IData)(vlTOPp->decode_tb__DOT__golden_ssel)))));
            tracep->chgIData(oldp+52,(vlTOPp->decode_tb__DOT__pattern),32);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[3U])) {
            tracep->chgIData(oldp+53,(vlTOPp->decode_tb__DOT__golden_R[0]),32);
            tracep->chgIData(oldp+54,(vlTOPp->decode_tb__DOT__golden_R[1]),32);
            tracep->chgIData(oldp+55,(vlTOPp->decode_tb__DOT__golden_R[2]),32);
            tracep->chgIData(oldp+56,(vlTOPp->decode_tb__DOT__golden_R[3]),32);
            tracep->chgIData(oldp+57,(vlTOPp->decode_tb__DOT__golden_R[4]),32);
            tracep->chgIData(oldp+58,(vlTOPp->decode_tb__DOT__golden_R[5]),32);
            tracep->chgIData(oldp+59,(vlTOPp->decode_tb__DOT__golden_R[6]),32);
            tracep->chgIData(oldp+60,(vlTOPp->decode_tb__DOT__golden_R[7]),32);
            tracep->chgIData(oldp+61,(vlTOPp->decode_tb__DOT__golden_R[8]),32);
            tracep->chgIData(oldp+62,(vlTOPp->decode_tb__DOT__golden_R[9]),32);
            tracep->chgIData(oldp+63,(vlTOPp->decode_tb__DOT__golden_R[10]),32);
            tracep->chgIData(oldp+64,(vlTOPp->decode_tb__DOT__golden_R[11]),32);
            tracep->chgIData(oldp+65,(vlTOPp->decode_tb__DOT__golden_R[12]),32);
            tracep->chgIData(oldp+66,(vlTOPp->decode_tb__DOT__golden_R[13]),32);
            tracep->chgIData(oldp+67,(vlTOPp->decode_tb__DOT__golden_R[14]),32);
            tracep->chgIData(oldp+68,(vlTOPp->decode_tb__DOT__golden_R[15]),32);
            tracep->chgIData(oldp+69,(vlTOPp->decode_tb__DOT__golden_R[16]),32);
            tracep->chgIData(oldp+70,(vlTOPp->decode_tb__DOT__golden_R[17]),32);
            tracep->chgIData(oldp+71,(vlTOPp->decode_tb__DOT__golden_R[18]),32);
            tracep->chgIData(oldp+72,(vlTOPp->decode_tb__DOT__golden_R[19]),32);
            tracep->chgIData(oldp+73,(vlTOPp->decode_tb__DOT__golden_R[20]),32);
            tracep->chgIData(oldp+74,(vlTOPp->decode_tb__DOT__golden_R[21]),32);
            tracep->chgIData(oldp+75,(vlTOPp->decode_tb__DOT__golden_R[22]),32);
            tracep->chgIData(oldp+76,(vlTOPp->decode_tb__DOT__golden_R[23]),32);
            tracep->chgIData(oldp+77,(vlTOPp->decode_tb__DOT__golden_R[24]),32);
            tracep->chgIData(oldp+78,(vlTOPp->decode_tb__DOT__golden_R[25]),32);
            tracep->chgIData(oldp+79,(vlTOPp->decode_tb__DOT__golden_R[26]),32);
            tracep->chgIData(oldp+80,(vlTOPp->decode_tb__DOT__golden_R[27]),32);
            tracep->chgIData(oldp+81,(vlTOPp->decode_tb__DOT__golden_R[28]),32);
            tracep->chgIData(oldp+82,(vlTOPp->decode_tb__DOT__golden_R[29]),32);
            tracep->chgIData(oldp+83,(vlTOPp->decode_tb__DOT__golden_R[30]),32);
            tracep->chgIData(oldp+84,(vlTOPp->decode_tb__DOT__golden_R[31]),32);
            tracep->chgIData(oldp+85,(vlTOPp->decode_tb__DOT__golden_reg),32);
            tracep->chgIData(oldp+86,(vlTOPp->decode_tb__DOT__i),32);
            tracep->chgIData(oldp+87,(vlTOPp->decode_tb__DOT__pat_num),32);
            tracep->chgIData(oldp+88,(vlTOPp->decode_tb__DOT__reg_pattern),32);
        }
        tracep->chgBit(oldp+89,(vlTOPp->clk));
        tracep->chgBit(oldp+90,(vlTOPp->rst));
        tracep->chgBit(oldp+91,(vlTOPp->finish));
        tracep->chgIData(oldp+92,(vlTOPp->decode_tb__DOT__tmp),32);
        tracep->chgIData(oldp+93,(vlTOPp->decode_tb__DOT__reg_file_inst__DOT__unnamedblk1__DOT__i),32);
    }
}

void Vdecode_tb::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vdecode_tb__Syms* __restrict vlSymsp = static_cast<Vdecode_tb__Syms*>(userp);
    Vdecode_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
        vlTOPp->__Vm_traceActivity[2U] = 0U;
        vlTOPp->__Vm_traceActivity[3U] = 0U;
    }
}
