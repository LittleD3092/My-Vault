// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vdecode_tb__Syms.h"


//======================

void Vdecode_tb::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vdecode_tb::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vdecode_tb__Syms* __restrict vlSymsp = static_cast<Vdecode_tb__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vdecode_tb::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vdecode_tb::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vdecode_tb__Syms* __restrict vlSymsp = static_cast<Vdecode_tb__Syms*>(userp);
    Vdecode_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vdecode_tb::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vdecode_tb__Syms* __restrict vlSymsp = static_cast<Vdecode_tb__Syms*>(userp);
    Vdecode_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+90,"clk", false,-1);
        tracep->declBit(c+91,"rst", false,-1);
        tracep->declBit(c+92,"finish", false,-1);
        tracep->declBit(c+90,"decode_tb clk", false,-1);
        tracep->declBit(c+91,"decode_tb rst", false,-1);
        tracep->declBit(c+92,"decode_tb finish", false,-1);
        tracep->declBus(c+95,"decode_tb DWIDTH", false,-1, 31,0);
        tracep->declBus(c+33,"decode_tb instr", false,-1, 31,0);
        tracep->declBus(c+34,"decode_tb op", false,-1, 3,0);
        tracep->declBit(c+35,"decode_tb ssel", false,-1);
        tracep->declBus(c+36,"decode_tb imm", false,-1, 31,0);
        tracep->declBus(c+37,"decode_tb rs1_id", false,-1, 4,0);
        tracep->declBus(c+38,"decode_tb rs2_id", false,-1, 4,0);
        tracep->declBus(c+39,"decode_tb rdst_id", false,-1, 4,0);
        tracep->declBit(c+96,"decode_tb we", false,-1);
        tracep->declBus(c+40,"decode_tb rs2_reg_file_out", false,-1, 31,0);
        tracep->declBus(c+41,"decode_tb rd", false,-1, 31,0);
        tracep->declBus(c+42,"decode_tb rs1", false,-1, 31,0);
        tracep->declBus(c+43,"decode_tb rs2", false,-1, 31,0);
        tracep->declBit(c+44,"decode_tb zero", false,-1);
        tracep->declBit(c+45,"decode_tb overflow", false,-1);
        tracep->declBus(c+46,"decode_tb golden_op", false,-1, 3,0);
        tracep->declBit(c+47,"decode_tb golden_ssel", false,-1);
        tracep->declBus(c+48,"decode_tb golden_imm", false,-1, 31,0);
        tracep->declBus(c+49,"decode_tb golden_rs1_id", false,-1, 4,0);
        tracep->declBus(c+50,"decode_tb golden_rs2_id", false,-1, 4,0);
        tracep->declBus(c+51,"decode_tb golden_rdst_id", false,-1, 4,0);
        tracep->declBit(c+52,"decode_tb rt_dont_care", false,-1);
        tracep->declBit(c+47,"decode_tb imm_dont_care", false,-1);
        {int i; for (i=0; i<32; i++) {
                tracep->declBus(c+54+i*1,"decode_tb golden_R", true,(i+0), 31,0);}}
        tracep->declBus(c+86,"decode_tb golden_reg", false,-1, 31,0);
        tracep->declBus(c+87,"decode_tb i", false,-1, 31,0);
        tracep->declBus(c+88,"decode_tb pat_num", false,-1, 31,0);
        tracep->declBus(c+53,"decode_tb pattern", false,-1, 31,0);
        tracep->declBus(c+93,"decode_tb tmp", false,-1, 31,0);
        tracep->declBus(c+89,"decode_tb reg_pattern", false,-1, 31,0);
        tracep->declBus(c+95,"decode_tb decode_inst DWIDTH", false,-1, 31,0);
        tracep->declBus(c+33,"decode_tb decode_inst instr", false,-1, 31,0);
        tracep->declBus(c+34,"decode_tb decode_inst op", false,-1, 3,0);
        tracep->declBit(c+35,"decode_tb decode_inst ssel", false,-1);
        tracep->declBus(c+36,"decode_tb decode_inst imm", false,-1, 31,0);
        tracep->declBus(c+37,"decode_tb decode_inst rs1_id", false,-1, 4,0);
        tracep->declBus(c+38,"decode_tb decode_inst rs2_id", false,-1, 4,0);
        tracep->declBus(c+39,"decode_tb decode_inst rdst_id", false,-1, 4,0);
        tracep->declBus(c+97,"decode_tb decode_inst OP_AND", false,-1, 3,0);
        tracep->declBus(c+98,"decode_tb decode_inst OP_OR", false,-1, 3,0);
        tracep->declBus(c+99,"decode_tb decode_inst OP_ADD", false,-1, 3,0);
        tracep->declBus(c+100,"decode_tb decode_inst OP_SUB", false,-1, 3,0);
        tracep->declBus(c+101,"decode_tb decode_inst OP_NOR", false,-1, 3,0);
        tracep->declBus(c+102,"decode_tb decode_inst OP_SLT", false,-1, 3,0);
        tracep->declBus(c+103,"decode_tb decode_inst OP_NOT_DEFINED", false,-1, 3,0);
        tracep->declBus(c+95,"decode_tb reg_file_inst DWIDTH", false,-1, 31,0);
        tracep->declBit(c+90,"decode_tb reg_file_inst clk", false,-1);
        tracep->declBit(c+91,"decode_tb reg_file_inst rst", false,-1);
        tracep->declBus(c+37,"decode_tb reg_file_inst rs1_id", false,-1, 4,0);
        tracep->declBus(c+38,"decode_tb reg_file_inst rs2_id", false,-1, 4,0);
        tracep->declBit(c+96,"decode_tb reg_file_inst we", false,-1);
        tracep->declBus(c+39,"decode_tb reg_file_inst rdst_id", false,-1, 4,0);
        tracep->declBus(c+41,"decode_tb reg_file_inst rdst", false,-1, 31,0);
        tracep->declBus(c+42,"decode_tb reg_file_inst rs1", false,-1, 31,0);
        tracep->declBus(c+40,"decode_tb reg_file_inst rs2", false,-1, 31,0);
        {int i; for (i=0; i<32; i++) {
                tracep->declBus(c+1+i*1,"decode_tb reg_file_inst R", true,(i+0), 31,0);}}
        tracep->declBus(c+94,"decode_tb reg_file_inst unnamedblk1 i", false,-1, 31,0);
        tracep->declBus(c+95,"decode_tb alu_inst DWIDTH", false,-1, 31,0);
        tracep->declBus(c+34,"decode_tb alu_inst op", false,-1, 3,0);
        tracep->declBus(c+42,"decode_tb alu_inst rs1", false,-1, 31,0);
        tracep->declBus(c+43,"decode_tb alu_inst rs2", false,-1, 31,0);
        tracep->declBus(c+41,"decode_tb alu_inst rd", false,-1, 31,0);
        tracep->declBit(c+44,"decode_tb alu_inst zero", false,-1);
        tracep->declBit(c+45,"decode_tb alu_inst overflow", false,-1);
    }
}

void Vdecode_tb::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vdecode_tb::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vdecode_tb__Syms* __restrict vlSymsp = static_cast<Vdecode_tb__Syms*>(userp);
    Vdecode_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vdecode_tb::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vdecode_tb__Syms* __restrict vlSymsp = static_cast<Vdecode_tb__Syms*>(userp);
    Vdecode_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullIData(oldp+1,(vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[0]),32);
        tracep->fullIData(oldp+2,(vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[1]),32);
        tracep->fullIData(oldp+3,(vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[2]),32);
        tracep->fullIData(oldp+4,(vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[3]),32);
        tracep->fullIData(oldp+5,(vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[4]),32);
        tracep->fullIData(oldp+6,(vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[5]),32);
        tracep->fullIData(oldp+7,(vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[6]),32);
        tracep->fullIData(oldp+8,(vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[7]),32);
        tracep->fullIData(oldp+9,(vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[8]),32);
        tracep->fullIData(oldp+10,(vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[9]),32);
        tracep->fullIData(oldp+11,(vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[10]),32);
        tracep->fullIData(oldp+12,(vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[11]),32);
        tracep->fullIData(oldp+13,(vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[12]),32);
        tracep->fullIData(oldp+14,(vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[13]),32);
        tracep->fullIData(oldp+15,(vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[14]),32);
        tracep->fullIData(oldp+16,(vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[15]),32);
        tracep->fullIData(oldp+17,(vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[16]),32);
        tracep->fullIData(oldp+18,(vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[17]),32);
        tracep->fullIData(oldp+19,(vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[18]),32);
        tracep->fullIData(oldp+20,(vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[19]),32);
        tracep->fullIData(oldp+21,(vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[20]),32);
        tracep->fullIData(oldp+22,(vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[21]),32);
        tracep->fullIData(oldp+23,(vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[22]),32);
        tracep->fullIData(oldp+24,(vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[23]),32);
        tracep->fullIData(oldp+25,(vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[24]),32);
        tracep->fullIData(oldp+26,(vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[25]),32);
        tracep->fullIData(oldp+27,(vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[26]),32);
        tracep->fullIData(oldp+28,(vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[27]),32);
        tracep->fullIData(oldp+29,(vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[28]),32);
        tracep->fullIData(oldp+30,(vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[29]),32);
        tracep->fullIData(oldp+31,(vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[30]),32);
        tracep->fullIData(oldp+32,(vlTOPp->decode_tb__DOT__reg_file_inst__DOT__R[31]),32);
        tracep->fullIData(oldp+33,(vlTOPp->decode_tb__DOT__instr),32);
        tracep->fullCData(oldp+34,(vlTOPp->decode_tb__DOT__op),4);
        tracep->fullBit(oldp+35,(vlTOPp->decode_tb__DOT__ssel));
        tracep->fullIData(oldp+36,(vlTOPp->decode_tb__DOT__imm),32);
        tracep->fullCData(oldp+37,(vlTOPp->decode_tb__DOT__rs1_id),5);
        tracep->fullCData(oldp+38,(vlTOPp->decode_tb__DOT__rs2_id),5);
        tracep->fullCData(oldp+39,(vlTOPp->decode_tb__DOT__rdst_id),5);
        tracep->fullIData(oldp+40,(vlTOPp->decode_tb__DOT__rs2_reg_file_out),32);
        tracep->fullIData(oldp+41,(vlTOPp->decode_tb__DOT__rd),32);
        tracep->fullIData(oldp+42,(vlTOPp->decode_tb__DOT__rs1),32);
        tracep->fullIData(oldp+43,(vlTOPp->decode_tb__DOT__rs2),32);
        tracep->fullBit(oldp+44,(vlTOPp->decode_tb__DOT__zero));
        tracep->fullBit(oldp+45,(vlTOPp->decode_tb__DOT__overflow));
        tracep->fullCData(oldp+46,(vlTOPp->decode_tb__DOT__golden_op),4);
        tracep->fullBit(oldp+47,(vlTOPp->decode_tb__DOT__golden_ssel));
        tracep->fullIData(oldp+48,(vlTOPp->decode_tb__DOT__golden_imm),32);
        tracep->fullCData(oldp+49,(vlTOPp->decode_tb__DOT__golden_rs1_id),5);
        tracep->fullCData(oldp+50,(vlTOPp->decode_tb__DOT__golden_rs2_id),5);
        tracep->fullCData(oldp+51,(vlTOPp->decode_tb__DOT__golden_rdst_id),5);
        tracep->fullBit(oldp+52,((1U & (~ (IData)(vlTOPp->decode_tb__DOT__golden_ssel)))));
        tracep->fullIData(oldp+53,(vlTOPp->decode_tb__DOT__pattern),32);
        tracep->fullIData(oldp+54,(vlTOPp->decode_tb__DOT__golden_R[0]),32);
        tracep->fullIData(oldp+55,(vlTOPp->decode_tb__DOT__golden_R[1]),32);
        tracep->fullIData(oldp+56,(vlTOPp->decode_tb__DOT__golden_R[2]),32);
        tracep->fullIData(oldp+57,(vlTOPp->decode_tb__DOT__golden_R[3]),32);
        tracep->fullIData(oldp+58,(vlTOPp->decode_tb__DOT__golden_R[4]),32);
        tracep->fullIData(oldp+59,(vlTOPp->decode_tb__DOT__golden_R[5]),32);
        tracep->fullIData(oldp+60,(vlTOPp->decode_tb__DOT__golden_R[6]),32);
        tracep->fullIData(oldp+61,(vlTOPp->decode_tb__DOT__golden_R[7]),32);
        tracep->fullIData(oldp+62,(vlTOPp->decode_tb__DOT__golden_R[8]),32);
        tracep->fullIData(oldp+63,(vlTOPp->decode_tb__DOT__golden_R[9]),32);
        tracep->fullIData(oldp+64,(vlTOPp->decode_tb__DOT__golden_R[10]),32);
        tracep->fullIData(oldp+65,(vlTOPp->decode_tb__DOT__golden_R[11]),32);
        tracep->fullIData(oldp+66,(vlTOPp->decode_tb__DOT__golden_R[12]),32);
        tracep->fullIData(oldp+67,(vlTOPp->decode_tb__DOT__golden_R[13]),32);
        tracep->fullIData(oldp+68,(vlTOPp->decode_tb__DOT__golden_R[14]),32);
        tracep->fullIData(oldp+69,(vlTOPp->decode_tb__DOT__golden_R[15]),32);
        tracep->fullIData(oldp+70,(vlTOPp->decode_tb__DOT__golden_R[16]),32);
        tracep->fullIData(oldp+71,(vlTOPp->decode_tb__DOT__golden_R[17]),32);
        tracep->fullIData(oldp+72,(vlTOPp->decode_tb__DOT__golden_R[18]),32);
        tracep->fullIData(oldp+73,(vlTOPp->decode_tb__DOT__golden_R[19]),32);
        tracep->fullIData(oldp+74,(vlTOPp->decode_tb__DOT__golden_R[20]),32);
        tracep->fullIData(oldp+75,(vlTOPp->decode_tb__DOT__golden_R[21]),32);
        tracep->fullIData(oldp+76,(vlTOPp->decode_tb__DOT__golden_R[22]),32);
        tracep->fullIData(oldp+77,(vlTOPp->decode_tb__DOT__golden_R[23]),32);
        tracep->fullIData(oldp+78,(vlTOPp->decode_tb__DOT__golden_R[24]),32);
        tracep->fullIData(oldp+79,(vlTOPp->decode_tb__DOT__golden_R[25]),32);
        tracep->fullIData(oldp+80,(vlTOPp->decode_tb__DOT__golden_R[26]),32);
        tracep->fullIData(oldp+81,(vlTOPp->decode_tb__DOT__golden_R[27]),32);
        tracep->fullIData(oldp+82,(vlTOPp->decode_tb__DOT__golden_R[28]),32);
        tracep->fullIData(oldp+83,(vlTOPp->decode_tb__DOT__golden_R[29]),32);
        tracep->fullIData(oldp+84,(vlTOPp->decode_tb__DOT__golden_R[30]),32);
        tracep->fullIData(oldp+85,(vlTOPp->decode_tb__DOT__golden_R[31]),32);
        tracep->fullIData(oldp+86,(vlTOPp->decode_tb__DOT__golden_reg),32);
        tracep->fullIData(oldp+87,(vlTOPp->decode_tb__DOT__i),32);
        tracep->fullIData(oldp+88,(vlTOPp->decode_tb__DOT__pat_num),32);
        tracep->fullIData(oldp+89,(vlTOPp->decode_tb__DOT__reg_pattern),32);
        tracep->fullBit(oldp+90,(vlTOPp->clk));
        tracep->fullBit(oldp+91,(vlTOPp->rst));
        tracep->fullBit(oldp+92,(vlTOPp->finish));
        tracep->fullIData(oldp+93,(vlTOPp->decode_tb__DOT__tmp),32);
        tracep->fullIData(oldp+94,(vlTOPp->decode_tb__DOT__reg_file_inst__DOT__unnamedblk1__DOT__i),32);
        tracep->fullIData(oldp+95,(0x20U),32);
        tracep->fullBit(oldp+96,(1U));
        tracep->fullCData(oldp+97,(0U),4);
        tracep->fullCData(oldp+98,(1U),4);
        tracep->fullCData(oldp+99,(2U),4);
        tracep->fullCData(oldp+100,(6U),4);
        tracep->fullCData(oldp+101,(0xcU),4);
        tracep->fullCData(oldp+102,(7U),4);
        tracep->fullCData(oldp+103,(0xfU),4);
    }
}
