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
        tracep->declBit(c+146,"clk", false,-1);
        tracep->declBit(c+147,"rst", false,-1);
        tracep->declBit(c+148,"finish", false,-1);
        tracep->declBit(c+146,"hw3_tb clk", false,-1);
        tracep->declBit(c+147,"hw3_tb rst", false,-1);
        tracep->declBit(c+148,"hw3_tb finish", false,-1);
        tracep->declBus(c+150,"hw3_tb DWIDTH", false,-1, 31,0);
        tracep->declBus(c+18,"hw3_tb i", false,-1, 31,0);
        tracep->declBus(c+151,"hw3_tb tmp", false,-1, 31,0);
        tracep->declBus(c+19,"hw3_tb cycle_count", false,-1, 31,0);
        tracep->declBus(c+152,"hw3_tb cycle_for_ans", false,-1, 31,0);
        {int i; for (i=0; i<32; i++) {
                tracep->declBus(c+20+i*1,"hw3_tb golden_reg", true,(i+0), 31,0);}}
        {int i; for (i=0; i<16; i++) {
                tracep->declBus(c+52+i*1,"hw3_tb golden_dmem", true,(i+0), 31,0);}}
        tracep->declBit(c+68,"hw3_tb start", false,-1);
        tracep->declBus(c+150,"hw3_tb core_top_inst DWIDTH", false,-1, 31,0);
        tracep->declBit(c+146,"hw3_tb core_top_inst clk", false,-1);
        tracep->declBit(c+147,"hw3_tb core_top_inst rst", false,-1);
        tracep->declBus(c+153,"hw3_tb core_top_inst J_TYPE_NOP", false,-1, 2,0);
        tracep->declBus(c+154,"hw3_tb core_top_inst J_TYPE_BEQ", false,-1, 2,0);
        tracep->declBus(c+155,"hw3_tb core_top_inst J_TYPE_JAL", false,-1, 2,0);
        tracep->declBus(c+156,"hw3_tb core_top_inst J_TYPE_JR", false,-1, 2,0);
        tracep->declBus(c+157,"hw3_tb core_top_inst J_TYPE_J", false,-1, 2,0);
        tracep->declBus(c+134,"hw3_tb core_top_inst pc_in", false,-1, 31,0);
        tracep->declBus(c+69,"hw3_tb core_top_inst instr_o", false,-1, 31,0);
        tracep->declBus(c+70,"hw3_tb core_top_inst adder_inst1_out", false,-1, 31,0);
        tracep->declBus(c+71,"hw3_tb core_top_inst jump_type", false,-1, 1,0);
        tracep->declBus(c+72,"hw3_tb core_top_inst jump_addr", false,-1, 31,0);
        tracep->declBit(c+73,"hw3_tb core_top_inst we_dmem", false,-1);
        tracep->declBit(c+74,"hw3_tb core_top_inst we_regfile", false,-1);
        tracep->declBus(c+75,"hw3_tb core_top_inst op", false,-1, 4,0);
        tracep->declBus(c+76,"hw3_tb core_top_inst ssel", false,-1, 1,0);
        tracep->declBus(c+77,"hw3_tb core_top_inst imm", false,-1, 31,0);
        tracep->declBus(c+78,"hw3_tb core_top_inst rs1_id", false,-1, 4,0);
        tracep->declBus(c+79,"hw3_tb core_top_inst rs2_id", false,-1, 4,0);
        tracep->declBus(c+80,"hw3_tb core_top_inst rdst_id", false,-1, 4,0);
        tracep->declBit(c+81,"hw3_tb core_top_inst reg_data_sel", false,-1);
        tracep->declBus(c+82,"hw3_tb core_top_inst imm_shift_left_twice", false,-1, 31,0);
        tracep->declBus(c+135,"hw3_tb core_top_inst branch_offset_checked_eq", false,-1, 31,0);
        tracep->declBus(c+136,"hw3_tb core_top_inst rdst", false,-1, 31,0);
        tracep->declBus(c+139,"hw3_tb core_top_inst rs1", false,-1, 31,0);
        tracep->declBus(c+140,"hw3_tb core_top_inst reg_rs2", false,-1, 31,0);
        tracep->declBus(c+137,"hw3_tb core_top_inst branch_addr", false,-1, 31,0);
        tracep->declBus(c+141,"hw3_tb core_top_inst alu_rs2", false,-1, 31,0);
        tracep->declBit(c+142,"hw3_tb core_top_inst zero", false,-1);
        tracep->declBus(c+143,"hw3_tb core_top_inst dmem_addr", false,-1, 31,0);
        tracep->declBus(c+138,"hw3_tb core_top_inst dmem_rdata", false,-1, 31,0);
        tracep->declBus(c+83,"hw3_tb core_top_inst pc", false,-1, 31,0);
        tracep->declBus(c+83,"hw3_tb core_top_inst adder_inst1 in0", false,-1, 31,0);
        tracep->declBus(c+158,"hw3_tb core_top_inst adder_inst1 in1", false,-1, 31,0);
        tracep->declBus(c+70,"hw3_tb core_top_inst adder_inst1 out", false,-1, 31,0);
        tracep->declBus(c+84,"hw3_tb core_top_inst imem_inst addr", false,-1, 5,0);
        tracep->declBus(c+69,"hw3_tb core_top_inst imem_inst rdata", false,-1, 31,0);
        {int i; for (i=0; i<16; i++) {
                tracep->declBus(c+1+i*1,"hw3_tb core_top_inst imem_inst RAM", true,(i+0), 31,0);}}
        tracep->declBus(c+150,"hw3_tb core_top_inst decode_inst DWIDTH", false,-1, 31,0);
        tracep->declBus(c+69,"hw3_tb core_top_inst decode_inst instr", false,-1, 31,0);
        tracep->declBus(c+71,"hw3_tb core_top_inst decode_inst jump_type", false,-1, 1,0);
        tracep->declBus(c+72,"hw3_tb core_top_inst decode_inst jump_addr", false,-1, 31,0);
        tracep->declBit(c+73,"hw3_tb core_top_inst decode_inst we_dmem", false,-1);
        tracep->declBit(c+74,"hw3_tb core_top_inst decode_inst we_regfile", false,-1);
        tracep->declBus(c+85,"hw3_tb core_top_inst decode_inst op", false,-1, 3,0);
        tracep->declBus(c+76,"hw3_tb core_top_inst decode_inst ssel", false,-1, 1,0);
        tracep->declBus(c+77,"hw3_tb core_top_inst decode_inst imm", false,-1, 31,0);
        tracep->declBus(c+78,"hw3_tb core_top_inst decode_inst rs1_id", false,-1, 4,0);
        tracep->declBus(c+79,"hw3_tb core_top_inst decode_inst rs2_id", false,-1, 4,0);
        tracep->declBus(c+80,"hw3_tb core_top_inst decode_inst rdst_id", false,-1, 4,0);
        tracep->declBit(c+81,"hw3_tb core_top_inst decode_inst reg_data_sel", false,-1);
        tracep->declBus(c+159,"hw3_tb core_top_inst decode_inst OP_AND", false,-1, 3,0);
        tracep->declBus(c+160,"hw3_tb core_top_inst decode_inst OP_OR", false,-1, 3,0);
        tracep->declBus(c+161,"hw3_tb core_top_inst decode_inst OP_ADD", false,-1, 3,0);
        tracep->declBus(c+162,"hw3_tb core_top_inst decode_inst OP_SUB", false,-1, 3,0);
        tracep->declBus(c+163,"hw3_tb core_top_inst decode_inst OP_NOR", false,-1, 3,0);
        tracep->declBus(c+164,"hw3_tb core_top_inst decode_inst OP_SLT", false,-1, 3,0);
        tracep->declBus(c+165,"hw3_tb core_top_inst decode_inst OP_NOT_DEFINED", false,-1, 3,0);
        tracep->declBus(c+150,"hw3_tb core_top_inst reg_file_inst DWIDTH", false,-1, 31,0);
        tracep->declBit(c+146,"hw3_tb core_top_inst reg_file_inst clk", false,-1);
        tracep->declBit(c+147,"hw3_tb core_top_inst reg_file_inst rst", false,-1);
        tracep->declBus(c+78,"hw3_tb core_top_inst reg_file_inst rs1_id", false,-1, 4,0);
        tracep->declBus(c+79,"hw3_tb core_top_inst reg_file_inst rs2_id", false,-1, 4,0);
        tracep->declBit(c+74,"hw3_tb core_top_inst reg_file_inst we", false,-1);
        tracep->declBus(c+80,"hw3_tb core_top_inst reg_file_inst rdst_id", false,-1, 4,0);
        tracep->declBus(c+136,"hw3_tb core_top_inst reg_file_inst rdst", false,-1, 31,0);
        tracep->declBus(c+139,"hw3_tb core_top_inst reg_file_inst rs1", false,-1, 31,0);
        tracep->declBus(c+140,"hw3_tb core_top_inst reg_file_inst rs2", false,-1, 31,0);
        {int i; for (i=0; i<32; i++) {
                tracep->declBus(c+102+i*1,"hw3_tb core_top_inst reg_file_inst R", true,(i+0), 31,0);}}
        tracep->declBus(c+149,"hw3_tb core_top_inst reg_file_inst unnamedblk1 i", false,-1, 31,0);
        tracep->declBus(c+77,"hw3_tb core_top_inst shift_left_inst in1", false,-1, 31,0);
        tracep->declBus(c+166,"hw3_tb core_top_inst shift_left_inst in2", false,-1, 31,0);
        tracep->declBus(c+82,"hw3_tb core_top_inst shift_left_inst out", false,-1, 31,0);
        tracep->declBit(c+142,"hw3_tb core_top_inst mux_2to1_inst_check_beq sel", false,-1);
        tracep->declBus(c+167,"hw3_tb core_top_inst mux_2to1_inst_check_beq in0", false,-1, 31,0);
        tracep->declBus(c+82,"hw3_tb core_top_inst mux_2to1_inst_check_beq in1", false,-1, 31,0);
        tracep->declBus(c+135,"hw3_tb core_top_inst mux_2to1_inst_check_beq out", false,-1, 31,0);
        tracep->declBus(c+70,"hw3_tb core_top_inst adder_inst2 in0", false,-1, 31,0);
        tracep->declBus(c+135,"hw3_tb core_top_inst adder_inst2 in1", false,-1, 31,0);
        tracep->declBus(c+137,"hw3_tb core_top_inst adder_inst2 out", false,-1, 31,0);
        tracep->declBus(c+71,"hw3_tb core_top_inst mux_4to1_inst1 sel", false,-1, 1,0);
        tracep->declBus(c+139,"hw3_tb core_top_inst mux_4to1_inst1 in0", false,-1, 31,0);
        tracep->declBus(c+137,"hw3_tb core_top_inst mux_4to1_inst1 in1", false,-1, 31,0);
        tracep->declBus(c+72,"hw3_tb core_top_inst mux_4to1_inst1 in2", false,-1, 31,0);
        tracep->declBus(c+70,"hw3_tb core_top_inst mux_4to1_inst1 in3", false,-1, 31,0);
        tracep->declBus(c+134,"hw3_tb core_top_inst mux_4to1_inst1 out", false,-1, 31,0);
        tracep->declBus(c+76,"hw3_tb core_top_inst mux_4to1_inst2 sel", false,-1, 1,0);
        tracep->declBus(c+167,"hw3_tb core_top_inst mux_4to1_inst2 in0", false,-1, 31,0);
        tracep->declBus(c+140,"hw3_tb core_top_inst mux_4to1_inst2 in1", false,-1, 31,0);
        tracep->declBus(c+70,"hw3_tb core_top_inst mux_4to1_inst2 in2", false,-1, 31,0);
        tracep->declBus(c+77,"hw3_tb core_top_inst mux_4to1_inst2 in3", false,-1, 31,0);
        tracep->declBus(c+141,"hw3_tb core_top_inst mux_4to1_inst2 out", false,-1, 31,0);
        tracep->declBus(c+150,"hw3_tb core_top_inst alu_inst DWIDTH", false,-1, 31,0);
        tracep->declBus(c+85,"hw3_tb core_top_inst alu_inst op", false,-1, 3,0);
        tracep->declBus(c+139,"hw3_tb core_top_inst alu_inst rs1", false,-1, 31,0);
        tracep->declBus(c+141,"hw3_tb core_top_inst alu_inst rs2", false,-1, 31,0);
        tracep->declBus(c+143,"hw3_tb core_top_inst alu_inst rd", false,-1, 31,0);
        tracep->declBit(c+142,"hw3_tb core_top_inst alu_inst zero", false,-1);
        tracep->declBit(c+144,"hw3_tb core_top_inst alu_inst overflow", false,-1);
        tracep->declBit(c+146,"hw3_tb core_top_inst dmem_inst clk", false,-1);
        tracep->declBus(c+145,"hw3_tb core_top_inst dmem_inst addr", false,-1, 5,0);
        tracep->declBit(c+73,"hw3_tb core_top_inst dmem_inst we", false,-1);
        tracep->declBus(c+140,"hw3_tb core_top_inst dmem_inst wdata", false,-1, 31,0);
        tracep->declBus(c+138,"hw3_tb core_top_inst dmem_inst rdata", false,-1, 31,0);
        {int i; for (i=0; i<16; i++) {
                tracep->declBus(c+86+i*1,"hw3_tb core_top_inst dmem_inst RAM", true,(i+0), 31,0);}}
        tracep->declBus(c+17,"hw3_tb core_top_inst dmem_inst idx", false,-1, 31,0);
        tracep->declBit(c+81,"hw3_tb core_top_inst mux_2to1_inst sel", false,-1);
        tracep->declBus(c+143,"hw3_tb core_top_inst mux_2to1_inst in0", false,-1, 31,0);
        tracep->declBus(c+138,"hw3_tb core_top_inst mux_2to1_inst in1", false,-1, 31,0);
        tracep->declBus(c+136,"hw3_tb core_top_inst mux_2to1_inst out", false,-1, 31,0);
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
        tracep->fullIData(oldp+1,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imem_inst__DOT__RAM[0]),32);
        tracep->fullIData(oldp+2,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imem_inst__DOT__RAM[1]),32);
        tracep->fullIData(oldp+3,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imem_inst__DOT__RAM[2]),32);
        tracep->fullIData(oldp+4,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imem_inst__DOT__RAM[3]),32);
        tracep->fullIData(oldp+5,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imem_inst__DOT__RAM[4]),32);
        tracep->fullIData(oldp+6,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imem_inst__DOT__RAM[5]),32);
        tracep->fullIData(oldp+7,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imem_inst__DOT__RAM[6]),32);
        tracep->fullIData(oldp+8,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imem_inst__DOT__RAM[7]),32);
        tracep->fullIData(oldp+9,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imem_inst__DOT__RAM[8]),32);
        tracep->fullIData(oldp+10,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imem_inst__DOT__RAM[9]),32);
        tracep->fullIData(oldp+11,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imem_inst__DOT__RAM[10]),32);
        tracep->fullIData(oldp+12,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imem_inst__DOT__RAM[11]),32);
        tracep->fullIData(oldp+13,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imem_inst__DOT__RAM[12]),32);
        tracep->fullIData(oldp+14,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imem_inst__DOT__RAM[13]),32);
        tracep->fullIData(oldp+15,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imem_inst__DOT__RAM[14]),32);
        tracep->fullIData(oldp+16,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imem_inst__DOT__RAM[15]),32);
        tracep->fullIData(oldp+17,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__idx),32);
        tracep->fullIData(oldp+18,(vlTOPp->hw3_tb__DOT__i),32);
        tracep->fullIData(oldp+19,(vlTOPp->hw3_tb__DOT__cycle_count),32);
        tracep->fullIData(oldp+20,(vlTOPp->hw3_tb__DOT__golden_reg[0]),32);
        tracep->fullIData(oldp+21,(vlTOPp->hw3_tb__DOT__golden_reg[1]),32);
        tracep->fullIData(oldp+22,(vlTOPp->hw3_tb__DOT__golden_reg[2]),32);
        tracep->fullIData(oldp+23,(vlTOPp->hw3_tb__DOT__golden_reg[3]),32);
        tracep->fullIData(oldp+24,(vlTOPp->hw3_tb__DOT__golden_reg[4]),32);
        tracep->fullIData(oldp+25,(vlTOPp->hw3_tb__DOT__golden_reg[5]),32);
        tracep->fullIData(oldp+26,(vlTOPp->hw3_tb__DOT__golden_reg[6]),32);
        tracep->fullIData(oldp+27,(vlTOPp->hw3_tb__DOT__golden_reg[7]),32);
        tracep->fullIData(oldp+28,(vlTOPp->hw3_tb__DOT__golden_reg[8]),32);
        tracep->fullIData(oldp+29,(vlTOPp->hw3_tb__DOT__golden_reg[9]),32);
        tracep->fullIData(oldp+30,(vlTOPp->hw3_tb__DOT__golden_reg[10]),32);
        tracep->fullIData(oldp+31,(vlTOPp->hw3_tb__DOT__golden_reg[11]),32);
        tracep->fullIData(oldp+32,(vlTOPp->hw3_tb__DOT__golden_reg[12]),32);
        tracep->fullIData(oldp+33,(vlTOPp->hw3_tb__DOT__golden_reg[13]),32);
        tracep->fullIData(oldp+34,(vlTOPp->hw3_tb__DOT__golden_reg[14]),32);
        tracep->fullIData(oldp+35,(vlTOPp->hw3_tb__DOT__golden_reg[15]),32);
        tracep->fullIData(oldp+36,(vlTOPp->hw3_tb__DOT__golden_reg[16]),32);
        tracep->fullIData(oldp+37,(vlTOPp->hw3_tb__DOT__golden_reg[17]),32);
        tracep->fullIData(oldp+38,(vlTOPp->hw3_tb__DOT__golden_reg[18]),32);
        tracep->fullIData(oldp+39,(vlTOPp->hw3_tb__DOT__golden_reg[19]),32);
        tracep->fullIData(oldp+40,(vlTOPp->hw3_tb__DOT__golden_reg[20]),32);
        tracep->fullIData(oldp+41,(vlTOPp->hw3_tb__DOT__golden_reg[21]),32);
        tracep->fullIData(oldp+42,(vlTOPp->hw3_tb__DOT__golden_reg[22]),32);
        tracep->fullIData(oldp+43,(vlTOPp->hw3_tb__DOT__golden_reg[23]),32);
        tracep->fullIData(oldp+44,(vlTOPp->hw3_tb__DOT__golden_reg[24]),32);
        tracep->fullIData(oldp+45,(vlTOPp->hw3_tb__DOT__golden_reg[25]),32);
        tracep->fullIData(oldp+46,(vlTOPp->hw3_tb__DOT__golden_reg[26]),32);
        tracep->fullIData(oldp+47,(vlTOPp->hw3_tb__DOT__golden_reg[27]),32);
        tracep->fullIData(oldp+48,(vlTOPp->hw3_tb__DOT__golden_reg[28]),32);
        tracep->fullIData(oldp+49,(vlTOPp->hw3_tb__DOT__golden_reg[29]),32);
        tracep->fullIData(oldp+50,(vlTOPp->hw3_tb__DOT__golden_reg[30]),32);
        tracep->fullIData(oldp+51,(vlTOPp->hw3_tb__DOT__golden_reg[31]),32);
        tracep->fullIData(oldp+52,(vlTOPp->hw3_tb__DOT__golden_dmem[0]),32);
        tracep->fullIData(oldp+53,(vlTOPp->hw3_tb__DOT__golden_dmem[1]),32);
        tracep->fullIData(oldp+54,(vlTOPp->hw3_tb__DOT__golden_dmem[2]),32);
        tracep->fullIData(oldp+55,(vlTOPp->hw3_tb__DOT__golden_dmem[3]),32);
        tracep->fullIData(oldp+56,(vlTOPp->hw3_tb__DOT__golden_dmem[4]),32);
        tracep->fullIData(oldp+57,(vlTOPp->hw3_tb__DOT__golden_dmem[5]),32);
        tracep->fullIData(oldp+58,(vlTOPp->hw3_tb__DOT__golden_dmem[6]),32);
        tracep->fullIData(oldp+59,(vlTOPp->hw3_tb__DOT__golden_dmem[7]),32);
        tracep->fullIData(oldp+60,(vlTOPp->hw3_tb__DOT__golden_dmem[8]),32);
        tracep->fullIData(oldp+61,(vlTOPp->hw3_tb__DOT__golden_dmem[9]),32);
        tracep->fullIData(oldp+62,(vlTOPp->hw3_tb__DOT__golden_dmem[10]),32);
        tracep->fullIData(oldp+63,(vlTOPp->hw3_tb__DOT__golden_dmem[11]),32);
        tracep->fullIData(oldp+64,(vlTOPp->hw3_tb__DOT__golden_dmem[12]),32);
        tracep->fullIData(oldp+65,(vlTOPp->hw3_tb__DOT__golden_dmem[13]),32);
        tracep->fullIData(oldp+66,(vlTOPp->hw3_tb__DOT__golden_dmem[14]),32);
        tracep->fullIData(oldp+67,(vlTOPp->hw3_tb__DOT__golden_dmem[15]),32);
        tracep->fullBit(oldp+68,(vlTOPp->hw3_tb__DOT__start));
        tracep->fullIData(oldp+69,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__instr_o),32);
        tracep->fullIData(oldp+70,(((IData)(4U) + vlTOPp->hw3_tb__DOT__core_top_inst__DOT__pc)),32);
        tracep->fullCData(oldp+71,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__jump_type),2);
        tracep->fullIData(oldp+72,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__jump_addr),32);
        tracep->fullBit(oldp+73,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__we_dmem));
        tracep->fullBit(oldp+74,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__we_regfile));
        tracep->fullCData(oldp+75,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT____Vcellout__decode_inst__op),5);
        tracep->fullCData(oldp+76,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__ssel),2);
        tracep->fullIData(oldp+77,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imm),32);
        tracep->fullCData(oldp+78,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__rs1_id),5);
        tracep->fullCData(oldp+79,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__rs2_id),5);
        tracep->fullCData(oldp+80,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__rdst_id),5);
        tracep->fullBit(oldp+81,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_data_sel));
        tracep->fullIData(oldp+82,((vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imm 
                                    << 2U)),32);
        tracep->fullIData(oldp+83,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__pc),32);
        tracep->fullCData(oldp+84,((0x3fU & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__pc)),6);
        tracep->fullCData(oldp+85,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT____Vcellout__decode_inst__op),4);
        tracep->fullIData(oldp+86,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM[0]),32);
        tracep->fullIData(oldp+87,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM[1]),32);
        tracep->fullIData(oldp+88,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM[2]),32);
        tracep->fullIData(oldp+89,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM[3]),32);
        tracep->fullIData(oldp+90,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM[4]),32);
        tracep->fullIData(oldp+91,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM[5]),32);
        tracep->fullIData(oldp+92,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM[6]),32);
        tracep->fullIData(oldp+93,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM[7]),32);
        tracep->fullIData(oldp+94,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM[8]),32);
        tracep->fullIData(oldp+95,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM[9]),32);
        tracep->fullIData(oldp+96,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM[10]),32);
        tracep->fullIData(oldp+97,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM[11]),32);
        tracep->fullIData(oldp+98,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM[12]),32);
        tracep->fullIData(oldp+99,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM[13]),32);
        tracep->fullIData(oldp+100,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM[14]),32);
        tracep->fullIData(oldp+101,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM[15]),32);
        tracep->fullIData(oldp+102,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[0]),32);
        tracep->fullIData(oldp+103,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[1]),32);
        tracep->fullIData(oldp+104,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[2]),32);
        tracep->fullIData(oldp+105,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[3]),32);
        tracep->fullIData(oldp+106,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[4]),32);
        tracep->fullIData(oldp+107,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[5]),32);
        tracep->fullIData(oldp+108,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[6]),32);
        tracep->fullIData(oldp+109,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[7]),32);
        tracep->fullIData(oldp+110,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[8]),32);
        tracep->fullIData(oldp+111,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[9]),32);
        tracep->fullIData(oldp+112,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[10]),32);
        tracep->fullIData(oldp+113,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[11]),32);
        tracep->fullIData(oldp+114,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[12]),32);
        tracep->fullIData(oldp+115,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[13]),32);
        tracep->fullIData(oldp+116,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[14]),32);
        tracep->fullIData(oldp+117,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[15]),32);
        tracep->fullIData(oldp+118,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[16]),32);
        tracep->fullIData(oldp+119,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[17]),32);
        tracep->fullIData(oldp+120,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[18]),32);
        tracep->fullIData(oldp+121,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[19]),32);
        tracep->fullIData(oldp+122,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[20]),32);
        tracep->fullIData(oldp+123,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[21]),32);
        tracep->fullIData(oldp+124,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[22]),32);
        tracep->fullIData(oldp+125,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[23]),32);
        tracep->fullIData(oldp+126,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[24]),32);
        tracep->fullIData(oldp+127,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[25]),32);
        tracep->fullIData(oldp+128,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[26]),32);
        tracep->fullIData(oldp+129,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[27]),32);
        tracep->fullIData(oldp+130,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[28]),32);
        tracep->fullIData(oldp+131,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[29]),32);
        tracep->fullIData(oldp+132,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[30]),32);
        tracep->fullIData(oldp+133,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[31]),32);
        tracep->fullIData(oldp+134,(((2U & (IData)(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__jump_type))
                                      ? ((1U & (IData)(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__jump_type))
                                          ? ((IData)(4U) 
                                             + vlTOPp->hw3_tb__DOT__core_top_inst__DOT__pc)
                                          : vlTOPp->hw3_tb__DOT__core_top_inst__DOT__jump_addr)
                                      : ((1U & (IData)(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__jump_type))
                                          ? ((IData)(4U) 
                                             + (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__pc 
                                                + ((IData)(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__zero)
                                                    ? 
                                                   ((IData)(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__zero)
                                                     ? 
                                                    (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imm 
                                                     << 2U)
                                                     : 0U)
                                                    : 0U)))
                                          : vlTOPp->hw3_tb__DOT__core_top_inst__DOT__rs1))),32);
        tracep->fullIData(oldp+135,(((IData)(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__zero)
                                      ? ((IData)(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__zero)
                                          ? (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imm 
                                             << 2U)
                                          : 0U) : 0U)),32);
        tracep->fullIData(oldp+136,(((IData)(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_data_sel)
                                      ? ((IData)(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_data_sel)
                                          ? vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM
                                         [(0xfU & (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_addr 
                                                   >> 2U))]
                                          : 0U) : vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_addr)),32);
        tracep->fullIData(oldp+137,(((IData)(4U) + 
                                     (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__pc 
                                      + ((IData)(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__zero)
                                          ? ((IData)(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__zero)
                                              ? (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__imm 
                                                 << 2U)
                                              : 0U)
                                          : 0U)))),32);
        tracep->fullIData(oldp+138,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM
                                    [(0xfU & (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_addr 
                                              >> 2U))]),32);
        tracep->fullIData(oldp+139,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__rs1),32);
        tracep->fullIData(oldp+140,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_rs2),32);
        tracep->fullIData(oldp+141,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__alu_rs2),32);
        tracep->fullBit(oldp+142,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__zero));
        tracep->fullIData(oldp+143,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_addr),32);
        tracep->fullBit(oldp+144,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__alu_inst__DOT__overflow));
        tracep->fullCData(oldp+145,((0x3fU & vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_addr)),6);
        tracep->fullBit(oldp+146,(vlTOPp->clk));
        tracep->fullBit(oldp+147,(vlTOPp->rst));
        tracep->fullBit(oldp+148,(vlTOPp->finish));
        tracep->fullIData(oldp+149,(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__unnamedblk1__DOT__i),32);
        tracep->fullIData(oldp+150,(0x20U),32);
        tracep->fullIData(oldp+151,(vlTOPp->hw3_tb__DOT__tmp),32);
        tracep->fullIData(oldp+152,(8U),32);
        tracep->fullCData(oldp+153,(0U),3);
        tracep->fullCData(oldp+154,(1U),3);
        tracep->fullCData(oldp+155,(2U),3);
        tracep->fullCData(oldp+156,(3U),3);
        tracep->fullCData(oldp+157,(4U),3);
        tracep->fullIData(oldp+158,(4U),32);
        tracep->fullCData(oldp+159,(0U),4);
        tracep->fullCData(oldp+160,(1U),4);
        tracep->fullCData(oldp+161,(2U),4);
        tracep->fullCData(oldp+162,(6U),4);
        tracep->fullCData(oldp+163,(0xcU),4);
        tracep->fullCData(oldp+164,(7U),4);
        tracep->fullCData(oldp+165,(0xfU),4);
        tracep->fullIData(oldp+166,(2U),32);
        tracep->fullIData(oldp+167,(0U),32);
    }
}
