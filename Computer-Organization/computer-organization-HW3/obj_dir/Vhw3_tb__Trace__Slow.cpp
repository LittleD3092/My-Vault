// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vhw3_tb__Syms.h"


//======================

void Vhw3_tb::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vhw3_tb::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vhw3_tb__Syms* __restrict vlSymsp = static_cast<Vhw3_tb__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vhw3_tb::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vhw3_tb::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vhw3_tb__Syms* __restrict vlSymsp = static_cast<Vhw3_tb__Syms*>(userp);
    Vhw3_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vhw3_tb::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vhw3_tb__Syms* __restrict vlSymsp = static_cast<Vhw3_tb__Syms*>(userp);
    Vhw3_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+132,"clk", false,-1);
        tracep->declBit(c+133,"rst", false,-1);
        tracep->declBit(c+134,"finish", false,-1);
        tracep->declBit(c+132,"hw3_tb clk", false,-1);
        tracep->declBit(c+133,"hw3_tb rst", false,-1);
        tracep->declBit(c+134,"hw3_tb finish", false,-1);
        tracep->declBus(c+139,"hw3_tb DWIDTH", false,-1, 31,0);
        tracep->declBus(c+64,"hw3_tb i", false,-1, 31,0);
        tracep->declBus(c+140,"hw3_tb tmp", false,-1, 31,0);
        tracep->declBus(c+65,"hw3_tb cycle_count", false,-1, 31,0);
        tracep->declBus(c+141,"hw3_tb cycle_for_ans", false,-1, 31,0);
        {int i; for (i=0; i<32; i++) {
                tracep->declBus(c+66+i*1,"hw3_tb golden_reg", true,(i+0), 31,0);}}
        {int i; for (i=0; i<16; i++) {
                tracep->declBus(c+98+i*1,"hw3_tb golden_dmem", true,(i+0), 31,0);}}
        tracep->declBit(c+114,"hw3_tb start", false,-1);
        tracep->declBus(c+139,"hw3_tb core_top_inst DWIDTH", false,-1, 31,0);
        tracep->declBit(c+132,"hw3_tb core_top_inst clk", false,-1);
        tracep->declBit(c+133,"hw3_tb core_top_inst rst", false,-1);
        tracep->declBus(c+142,"hw3_tb core_top_inst J_TYPE_NOP", false,-1, 2,0);
        tracep->declBus(c+143,"hw3_tb core_top_inst J_TYPE_BEQ", false,-1, 2,0);
        tracep->declBus(c+144,"hw3_tb core_top_inst J_TYPE_JAL", false,-1, 2,0);
        tracep->declBus(c+145,"hw3_tb core_top_inst J_TYPE_JR", false,-1, 2,0);
        tracep->declBus(c+146,"hw3_tb core_top_inst J_TYPE_J", false,-1, 2,0);
        tracep->declBus(c+135,"hw3_tb core_top_inst pc", false,-1, 31,0);
        tracep->declBus(c+147,"hw3_tb core_top_inst imem_inst addr", false,-1, 5,0);
        tracep->declBus(c+1,"hw3_tb core_top_inst imem_inst rdata", false,-1, 31,0);
        {int i; for (i=0; i<16; i++) {
                tracep->declBus(c+2+i*1,"hw3_tb core_top_inst imem_inst RAM", true,(i+0), 31,0);}}
        tracep->declBus(c+139,"hw3_tb core_top_inst decode_inst DWIDTH", false,-1, 31,0);
        tracep->declBus(c+148,"hw3_tb core_top_inst decode_inst instr", false,-1, 31,0);
        tracep->declBus(c+18,"hw3_tb core_top_inst decode_inst jump_type", false,-1, 1,0);
        tracep->declBus(c+19,"hw3_tb core_top_inst decode_inst jump_addr", false,-1, 31,0);
        tracep->declBit(c+20,"hw3_tb core_top_inst decode_inst we_dmem", false,-1);
        tracep->declBit(c+21,"hw3_tb core_top_inst decode_inst we_regfile", false,-1);
        tracep->declBus(c+22,"hw3_tb core_top_inst decode_inst op", false,-1, 3,0);
        tracep->declBus(c+23,"hw3_tb core_top_inst decode_inst ssel", false,-1, 1,0);
        tracep->declBus(c+24,"hw3_tb core_top_inst decode_inst imm", false,-1, 31,0);
        tracep->declBus(c+25,"hw3_tb core_top_inst decode_inst rs1_id", false,-1, 4,0);
        tracep->declBus(c+26,"hw3_tb core_top_inst decode_inst rs2_id", false,-1, 4,0);
        tracep->declBus(c+27,"hw3_tb core_top_inst decode_inst rdst_id", false,-1, 4,0);
        tracep->declBus(c+149,"hw3_tb core_top_inst decode_inst OP_AND", false,-1, 3,0);
        tracep->declBus(c+150,"hw3_tb core_top_inst decode_inst OP_OR", false,-1, 3,0);
        tracep->declBus(c+151,"hw3_tb core_top_inst decode_inst OP_ADD", false,-1, 3,0);
        tracep->declBus(c+152,"hw3_tb core_top_inst decode_inst OP_SUB", false,-1, 3,0);
        tracep->declBus(c+153,"hw3_tb core_top_inst decode_inst OP_NOR", false,-1, 3,0);
        tracep->declBus(c+154,"hw3_tb core_top_inst decode_inst OP_SLT", false,-1, 3,0);
        tracep->declBus(c+155,"hw3_tb core_top_inst decode_inst OP_NOT_DEFINED", false,-1, 3,0);
        tracep->declBus(c+139,"hw3_tb core_top_inst reg_file_inst DWIDTH", false,-1, 31,0);
        tracep->declBit(c+156,"hw3_tb core_top_inst reg_file_inst clk", false,-1);
        tracep->declBit(c+157,"hw3_tb core_top_inst reg_file_inst rst", false,-1);
        tracep->declBus(c+158,"hw3_tb core_top_inst reg_file_inst rs1_id", false,-1, 4,0);
        tracep->declBus(c+159,"hw3_tb core_top_inst reg_file_inst rs2_id", false,-1, 4,0);
        tracep->declBit(c+160,"hw3_tb core_top_inst reg_file_inst we", false,-1);
        tracep->declBus(c+161,"hw3_tb core_top_inst reg_file_inst rdst_id", false,-1, 4,0);
        tracep->declBus(c+162,"hw3_tb core_top_inst reg_file_inst rdst", false,-1, 31,0);
        tracep->declBus(c+136,"hw3_tb core_top_inst reg_file_inst rs1", false,-1, 31,0);
        tracep->declBus(c+137,"hw3_tb core_top_inst reg_file_inst rs2", false,-1, 31,0);
        {int i; for (i=0; i<32; i++) {
                tracep->declBus(c+32+i*1,"hw3_tb core_top_inst reg_file_inst R", true,(i+0), 31,0);}}
        tracep->declBus(c+138,"hw3_tb core_top_inst reg_file_inst unnamedblk1 i", false,-1, 31,0);
        tracep->declBus(c+139,"hw3_tb core_top_inst alu_inst DWIDTH", false,-1, 31,0);
        tracep->declBus(c+163,"hw3_tb core_top_inst alu_inst op", false,-1, 3,0);
        tracep->declBus(c+164,"hw3_tb core_top_inst alu_inst rs1", false,-1, 31,0);
        tracep->declBus(c+165,"hw3_tb core_top_inst alu_inst rs2", false,-1, 31,0);
        tracep->declBus(c+28,"hw3_tb core_top_inst alu_inst rd", false,-1, 31,0);
        tracep->declBit(c+29,"hw3_tb core_top_inst alu_inst zero", false,-1);
        tracep->declBit(c+30,"hw3_tb core_top_inst alu_inst overflow", false,-1);
        tracep->declBit(c+166,"hw3_tb core_top_inst dmem_inst clk", false,-1);
        tracep->declBus(c+167,"hw3_tb core_top_inst dmem_inst addr", false,-1, 5,0);
        tracep->declBit(c+168,"hw3_tb core_top_inst dmem_inst we", false,-1);
        tracep->declBus(c+169,"hw3_tb core_top_inst dmem_inst wdata", false,-1, 31,0);
        tracep->declBus(c+115,"hw3_tb core_top_inst dmem_inst rdata", false,-1, 31,0);
        {int i; for (i=0; i<16; i++) {
                tracep->declBus(c+116+i*1,"hw3_tb core_top_inst dmem_inst RAM", true,(i+0), 31,0);}}
        tracep->declBus(c+31,"hw3_tb core_top_inst dmem_inst idx", false,-1, 31,0);
    }
}

void Vhw3_tb::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vhw3_tb::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vhw3_tb__Syms* __restrict vlSymsp = static_cast<Vhw3_tb__Syms*>(userp);
    Vhw3_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vhw3_tb::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vhw3_tb__Syms* __restrict vlSymsp = static_cast<Vhw3_tb__Syms*>(userp);
    Vhw3_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullIData(oldp+1,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imem_inst__DOT__RAM
                                  [(0xfU & ((IData)(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imem_inst__DOT__addr) 
                                            >> 2U))]),32);
        tracep->fullIData(oldp+2,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imem_inst__DOT__RAM[0]),32);
        tracep->fullIData(oldp+3,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imem_inst__DOT__RAM[1]),32);
        tracep->fullIData(oldp+4,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imem_inst__DOT__RAM[2]),32);
        tracep->fullIData(oldp+5,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imem_inst__DOT__RAM[3]),32);
        tracep->fullIData(oldp+6,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imem_inst__DOT__RAM[4]),32);
        tracep->fullIData(oldp+7,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imem_inst__DOT__RAM[5]),32);
        tracep->fullIData(oldp+8,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imem_inst__DOT__RAM[6]),32);
        tracep->fullIData(oldp+9,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imem_inst__DOT__RAM[7]),32);
        tracep->fullIData(oldp+10,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imem_inst__DOT__RAM[8]),32);
        tracep->fullIData(oldp+11,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imem_inst__DOT__RAM[9]),32);
        tracep->fullIData(oldp+12,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imem_inst__DOT__RAM[10]),32);
        tracep->fullIData(oldp+13,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imem_inst__DOT__RAM[11]),32);
        tracep->fullIData(oldp+14,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imem_inst__DOT__RAM[12]),32);
        tracep->fullIData(oldp+15,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imem_inst__DOT__RAM[13]),32);
        tracep->fullIData(oldp+16,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imem_inst__DOT__RAM[14]),32);
        tracep->fullIData(oldp+17,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imem_inst__DOT__RAM[15]),32);
        tracep->fullCData(oldp+18,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__jump_type),2);
        tracep->fullIData(oldp+19,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__jump_addr),32);
        tracep->fullBit(oldp+20,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__we_dmem));
        tracep->fullBit(oldp+21,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__we_regfile));
        tracep->fullCData(oldp+22,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__op),4);
        tracep->fullCData(oldp+23,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__ssel),2);
        tracep->fullIData(oldp+24,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__imm),32);
        tracep->fullCData(oldp+25,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__rs1_id),5);
        tracep->fullCData(oldp+26,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__rs2_id),5);
        tracep->fullCData(oldp+27,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__rdst_id),5);
        tracep->fullIData(oldp+28,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__alu_inst__DOT__rd),32);
        tracep->fullBit(oldp+29,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__alu_inst__DOT__zero));
        tracep->fullBit(oldp+30,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__alu_inst__DOT__overflow));
        tracep->fullIData(oldp+31,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__idx),32);
        tracep->fullIData(oldp+32,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[0]),32);
        tracep->fullIData(oldp+33,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[1]),32);
        tracep->fullIData(oldp+34,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[2]),32);
        tracep->fullIData(oldp+35,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[3]),32);
        tracep->fullIData(oldp+36,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[4]),32);
        tracep->fullIData(oldp+37,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[5]),32);
        tracep->fullIData(oldp+38,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[6]),32);
        tracep->fullIData(oldp+39,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[7]),32);
        tracep->fullIData(oldp+40,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[8]),32);
        tracep->fullIData(oldp+41,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[9]),32);
        tracep->fullIData(oldp+42,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[10]),32);
        tracep->fullIData(oldp+43,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[11]),32);
        tracep->fullIData(oldp+44,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[12]),32);
        tracep->fullIData(oldp+45,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[13]),32);
        tracep->fullIData(oldp+46,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[14]),32);
        tracep->fullIData(oldp+47,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[15]),32);
        tracep->fullIData(oldp+48,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[16]),32);
        tracep->fullIData(oldp+49,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[17]),32);
        tracep->fullIData(oldp+50,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[18]),32);
        tracep->fullIData(oldp+51,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[19]),32);
        tracep->fullIData(oldp+52,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[20]),32);
        tracep->fullIData(oldp+53,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[21]),32);
        tracep->fullIData(oldp+54,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[22]),32);
        tracep->fullIData(oldp+55,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[23]),32);
        tracep->fullIData(oldp+56,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[24]),32);
        tracep->fullIData(oldp+57,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[25]),32);
        tracep->fullIData(oldp+58,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[26]),32);
        tracep->fullIData(oldp+59,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[27]),32);
        tracep->fullIData(oldp+60,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[28]),32);
        tracep->fullIData(oldp+61,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[29]),32);
        tracep->fullIData(oldp+62,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[30]),32);
        tracep->fullIData(oldp+63,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[31]),32);
        tracep->fullIData(oldp+64,(vlTOPp->hw3_tb__DOT__i),32);
        tracep->fullIData(oldp+65,(vlTOPp->hw3_tb__DOT__cycle_count),32);
        tracep->fullIData(oldp+66,(vlTOPp->hw3_tb__DOT__golden_reg[0]),32);
        tracep->fullIData(oldp+67,(vlTOPp->hw3_tb__DOT__golden_reg[1]),32);
        tracep->fullIData(oldp+68,(vlTOPp->hw3_tb__DOT__golden_reg[2]),32);
        tracep->fullIData(oldp+69,(vlTOPp->hw3_tb__DOT__golden_reg[3]),32);
        tracep->fullIData(oldp+70,(vlTOPp->hw3_tb__DOT__golden_reg[4]),32);
        tracep->fullIData(oldp+71,(vlTOPp->hw3_tb__DOT__golden_reg[5]),32);
        tracep->fullIData(oldp+72,(vlTOPp->hw3_tb__DOT__golden_reg[6]),32);
        tracep->fullIData(oldp+73,(vlTOPp->hw3_tb__DOT__golden_reg[7]),32);
        tracep->fullIData(oldp+74,(vlTOPp->hw3_tb__DOT__golden_reg[8]),32);
        tracep->fullIData(oldp+75,(vlTOPp->hw3_tb__DOT__golden_reg[9]),32);
        tracep->fullIData(oldp+76,(vlTOPp->hw3_tb__DOT__golden_reg[10]),32);
        tracep->fullIData(oldp+77,(vlTOPp->hw3_tb__DOT__golden_reg[11]),32);
        tracep->fullIData(oldp+78,(vlTOPp->hw3_tb__DOT__golden_reg[12]),32);
        tracep->fullIData(oldp+79,(vlTOPp->hw3_tb__DOT__golden_reg[13]),32);
        tracep->fullIData(oldp+80,(vlTOPp->hw3_tb__DOT__golden_reg[14]),32);
        tracep->fullIData(oldp+81,(vlTOPp->hw3_tb__DOT__golden_reg[15]),32);
        tracep->fullIData(oldp+82,(vlTOPp->hw3_tb__DOT__golden_reg[16]),32);
        tracep->fullIData(oldp+83,(vlTOPp->hw3_tb__DOT__golden_reg[17]),32);
        tracep->fullIData(oldp+84,(vlTOPp->hw3_tb__DOT__golden_reg[18]),32);
        tracep->fullIData(oldp+85,(vlTOPp->hw3_tb__DOT__golden_reg[19]),32);
        tracep->fullIData(oldp+86,(vlTOPp->hw3_tb__DOT__golden_reg[20]),32);
        tracep->fullIData(oldp+87,(vlTOPp->hw3_tb__DOT__golden_reg[21]),32);
        tracep->fullIData(oldp+88,(vlTOPp->hw3_tb__DOT__golden_reg[22]),32);
        tracep->fullIData(oldp+89,(vlTOPp->hw3_tb__DOT__golden_reg[23]),32);
        tracep->fullIData(oldp+90,(vlTOPp->hw3_tb__DOT__golden_reg[24]),32);
        tracep->fullIData(oldp+91,(vlTOPp->hw3_tb__DOT__golden_reg[25]),32);
        tracep->fullIData(oldp+92,(vlTOPp->hw3_tb__DOT__golden_reg[26]),32);
        tracep->fullIData(oldp+93,(vlTOPp->hw3_tb__DOT__golden_reg[27]),32);
        tracep->fullIData(oldp+94,(vlTOPp->hw3_tb__DOT__golden_reg[28]),32);
        tracep->fullIData(oldp+95,(vlTOPp->hw3_tb__DOT__golden_reg[29]),32);
        tracep->fullIData(oldp+96,(vlTOPp->hw3_tb__DOT__golden_reg[30]),32);
        tracep->fullIData(oldp+97,(vlTOPp->hw3_tb__DOT__golden_reg[31]),32);
        tracep->fullIData(oldp+98,(vlTOPp->hw3_tb__DOT__golden_dmem[0]),32);
        tracep->fullIData(oldp+99,(vlTOPp->hw3_tb__DOT__golden_dmem[1]),32);
        tracep->fullIData(oldp+100,(vlTOPp->hw3_tb__DOT__golden_dmem[2]),32);
        tracep->fullIData(oldp+101,(vlTOPp->hw3_tb__DOT__golden_dmem[3]),32);
        tracep->fullIData(oldp+102,(vlTOPp->hw3_tb__DOT__golden_dmem[4]),32);
        tracep->fullIData(oldp+103,(vlTOPp->hw3_tb__DOT__golden_dmem[5]),32);
        tracep->fullIData(oldp+104,(vlTOPp->hw3_tb__DOT__golden_dmem[6]),32);
        tracep->fullIData(oldp+105,(vlTOPp->hw3_tb__DOT__golden_dmem[7]),32);
        tracep->fullIData(oldp+106,(vlTOPp->hw3_tb__DOT__golden_dmem[8]),32);
        tracep->fullIData(oldp+107,(vlTOPp->hw3_tb__DOT__golden_dmem[9]),32);
        tracep->fullIData(oldp+108,(vlTOPp->hw3_tb__DOT__golden_dmem[10]),32);
        tracep->fullIData(oldp+109,(vlTOPp->hw3_tb__DOT__golden_dmem[11]),32);
        tracep->fullIData(oldp+110,(vlTOPp->hw3_tb__DOT__golden_dmem[12]),32);
        tracep->fullIData(oldp+111,(vlTOPp->hw3_tb__DOT__golden_dmem[13]),32);
        tracep->fullIData(oldp+112,(vlTOPp->hw3_tb__DOT__golden_dmem[14]),32);
        tracep->fullIData(oldp+113,(vlTOPp->hw3_tb__DOT__golden_dmem[15]),32);
        tracep->fullBit(oldp+114,(vlTOPp->hw3_tb__DOT__start));
        tracep->fullIData(oldp+115,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM
                                    [(0xfU & ((IData)(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__addr) 
                                              >> 2U))]),32);
        tracep->fullIData(oldp+116,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM[0]),32);
        tracep->fullIData(oldp+117,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM[1]),32);
        tracep->fullIData(oldp+118,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM[2]),32);
        tracep->fullIData(oldp+119,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM[3]),32);
        tracep->fullIData(oldp+120,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM[4]),32);
        tracep->fullIData(oldp+121,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM[5]),32);
        tracep->fullIData(oldp+122,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM[6]),32);
        tracep->fullIData(oldp+123,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM[7]),32);
        tracep->fullIData(oldp+124,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM[8]),32);
        tracep->fullIData(oldp+125,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM[9]),32);
        tracep->fullIData(oldp+126,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM[10]),32);
        tracep->fullIData(oldp+127,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM[11]),32);
        tracep->fullIData(oldp+128,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM[12]),32);
        tracep->fullIData(oldp+129,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM[13]),32);
        tracep->fullIData(oldp+130,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM[14]),32);
        tracep->fullIData(oldp+131,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM[15]),32);
        tracep->fullBit(oldp+132,(vlTOPp->clk));
        tracep->fullBit(oldp+133,(vlTOPp->rst));
        tracep->fullBit(oldp+134,(vlTOPp->finish));
        tracep->fullIData(oldp+135,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__pc),32);
        tracep->fullIData(oldp+136,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__rs1),32);
        tracep->fullIData(oldp+137,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__rs2),32);
        tracep->fullIData(oldp+138,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__unnamedblk1__DOT__i),32);
        tracep->fullIData(oldp+139,(0x20U),32);
        tracep->fullIData(oldp+140,(vlTOPp->hw3_tb__DOT__tmp),32);
        tracep->fullIData(oldp+141,(8U),32);
        tracep->fullCData(oldp+142,(0U),3);
        tracep->fullCData(oldp+143,(1U),3);
        tracep->fullCData(oldp+144,(2U),3);
        tracep->fullCData(oldp+145,(3U),3);
        tracep->fullCData(oldp+146,(4U),3);
        tracep->fullCData(oldp+147,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imem_inst__DOT__addr),6);
        tracep->fullIData(oldp+148,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr),32);
        tracep->fullCData(oldp+149,(0U),4);
        tracep->fullCData(oldp+150,(1U),4);
        tracep->fullCData(oldp+151,(2U),4);
        tracep->fullCData(oldp+152,(6U),4);
        tracep->fullCData(oldp+153,(0xcU),4);
        tracep->fullCData(oldp+154,(7U),4);
        tracep->fullCData(oldp+155,(0xfU),4);
        tracep->fullBit(oldp+156,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__clk));
        tracep->fullBit(oldp+157,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__rst));
        tracep->fullCData(oldp+158,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__rs1_id),5);
        tracep->fullCData(oldp+159,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__rs2_id),5);
        tracep->fullBit(oldp+160,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__we));
        tracep->fullCData(oldp+161,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__rdst_id),5);
        tracep->fullIData(oldp+162,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__rdst),32);
        tracep->fullCData(oldp+163,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__alu_inst__DOT__op),4);
        tracep->fullIData(oldp+164,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__alu_inst__DOT__rs1),32);
        tracep->fullIData(oldp+165,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__alu_inst__DOT__rs2),32);
        tracep->fullBit(oldp+166,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__clk));
        tracep->fullCData(oldp+167,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__addr),6);
        tracep->fullBit(oldp+168,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__we));
        tracep->fullIData(oldp+169,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__wdata),32);
    }
}
