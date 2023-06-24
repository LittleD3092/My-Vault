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
        tracep->declBit(c+152,"clk", false,-1);
        tracep->declBit(c+153,"rst", false,-1);
        tracep->declBit(c+154,"finish", false,-1);
        tracep->declBit(c+152,"hw3_tb clk", false,-1);
        tracep->declBit(c+153,"hw3_tb rst", false,-1);
        tracep->declBit(c+2,"hw3_tb finish", false,-1);
        tracep->declBus(c+190,"hw3_tb DWIDTH", false,-1, 31,0);
        tracep->declBus(c+3,"hw3_tb i", false,-1, 31,0);
        tracep->declBus(c+191,"hw3_tb tmp", false,-1, 31,0);
        tracep->declBus(c+4,"hw3_tb cycle_count", false,-1, 31,0);
        tracep->declBus(c+192,"hw3_tb cycle_for_ans", false,-1, 31,0);
        {int i; for (i=0; i<32; i++) {
                tracep->declBus(c+5+i*1,"hw3_tb golden_reg", true,(i+0), 31,0);}}
        {int i; for (i=0; i<16; i++) {
                tracep->declBus(c+37+i*1,"hw3_tb golden_dmem", true,(i+0), 31,0);}}
        tracep->declBit(c+53,"hw3_tb start", false,-1);
        tracep->declBus(c+190,"hw3_tb core_top_inst DWIDTH", false,-1, 31,0);
        tracep->declBit(c+152,"hw3_tb core_top_inst clk", false,-1);
        tracep->declBit(c+153,"hw3_tb core_top_inst rst", false,-1);
        tracep->declBus(c+193,"hw3_tb core_top_inst J_TYPE_NOP", false,-1, 2,0);
        tracep->declBus(c+194,"hw3_tb core_top_inst J_TYPE_BEQ", false,-1, 2,0);
        tracep->declBus(c+195,"hw3_tb core_top_inst J_TYPE_JAL", false,-1, 2,0);
        tracep->declBus(c+196,"hw3_tb core_top_inst J_TYPE_JR", false,-1, 2,0);
        tracep->declBus(c+197,"hw3_tb core_top_inst J_TYPE_J", false,-1, 2,0);
        tracep->declBus(c+54,"hw3_tb core_top_inst pc", false,-1, 31,0);
        tracep->declBus(c+55,"hw3_tb core_top_inst pc_increment", false,-1, 31,0);
        tracep->declBit(c+56,"hw3_tb core_top_inst pc_write", false,-1);
        tracep->declBus(c+155,"hw3_tb core_top_inst instr", false,-1, 31,0);
        tracep->declBus(c+57,"hw3_tb core_top_inst op", false,-1, 3,0);
        tracep->declBit(c+58,"hw3_tb core_top_inst ssel", false,-1);
        tracep->declBus(c+59,"hw3_tb core_top_inst wbsel", false,-1, 1,0);
        tracep->declBit(c+60,"hw3_tb core_top_inst we_regfile", false,-1);
        tracep->declBit(c+61,"hw3_tb core_top_inst we_dmem", false,-1);
        tracep->declBus(c+62,"hw3_tb core_top_inst jump_type", false,-1, 2,0);
        tracep->declBus(c+63,"hw3_tb core_top_inst jump_addr", false,-1, 25,0);
        tracep->declBus(c+64,"hw3_tb core_top_inst imm", false,-1, 31,0);
        tracep->declBus(c+65,"hw3_tb core_top_inst rs1_id", false,-1, 4,0);
        tracep->declBus(c+66,"hw3_tb core_top_inst rs2_id", false,-1, 4,0);
        tracep->declBus(c+67,"hw3_tb core_top_inst rdst_id", false,-1, 4,0);
        tracep->declBus(c+156,"hw3_tb core_top_inst rd", false,-1, 31,0);
        tracep->declBus(c+68,"hw3_tb core_top_inst rs1_out", false,-1, 31,0);
        tracep->declBus(c+69,"hw3_tb core_top_inst rs2_out", false,-1, 31,0);
        tracep->declBus(c+70,"hw3_tb core_top_inst alu_rs1", false,-1, 31,0);
        tracep->declBus(c+71,"hw3_tb core_top_inst alu_rs2", false,-1, 31,0);
        tracep->declBus(c+72,"hw3_tb core_top_inst alu_out", false,-1, 31,0);
        tracep->declBit(c+73,"hw3_tb core_top_inst zero", false,-1);
        tracep->declBit(c+74,"hw3_tb core_top_inst overflow", false,-1);
        tracep->declBus(c+157,"hw3_tb core_top_inst dmem_out", false,-1, 31,0);
        tracep->declBus(c+75,"hw3_tb core_top_inst if_id_addr", false,-1, 31,0);
        tracep->declBus(c+76,"hw3_tb core_top_inst if_id_instr", false,-1, 31,0);
        tracep->declBus(c+77,"hw3_tb core_top_inst id_ex_addr", false,-1, 31,0);
        tracep->declBus(c+78,"hw3_tb core_top_inst id_ex_jump_type", false,-1, 31,0);
        tracep->declBus(c+79,"hw3_tb core_top_inst id_ex_jump_addr", false,-1, 31,0);
        tracep->declBus(c+80,"hw3_tb core_top_inst id_ex_op", false,-1, 31,0);
        tracep->declBus(c+81,"hw3_tb core_top_inst id_ex_imm", false,-1, 31,0);
        tracep->declBus(c+70,"hw3_tb core_top_inst id_ex_rs1_out", false,-1, 31,0);
        tracep->declBus(c+82,"hw3_tb core_top_inst id_ex_rs2_out", false,-1, 31,0);
        tracep->declBus(c+83,"hw3_tb core_top_inst id_ex_rdst_id", false,-1, 31,0);
        tracep->declBit(c+84,"hw3_tb core_top_inst id_ex_we_regfile", false,-1);
        tracep->declBit(c+85,"hw3_tb core_top_inst id_ex_we_dmem", false,-1);
        tracep->declBus(c+86,"hw3_tb core_top_inst id_ex_wbsel", false,-1, 1,0);
        tracep->declBit(c+87,"hw3_tb core_top_inst id_ex_ssel", false,-1);
        tracep->declBus(c+88,"hw3_tb core_top_inst ex_mem_addr", false,-1, 31,0);
        tracep->declBus(c+89,"hw3_tb core_top_inst ex_mem_alu_out", false,-1, 31,0);
        tracep->declBus(c+90,"hw3_tb core_top_inst ex_mem_rs2_out", false,-1, 31,0);
        tracep->declBus(c+91,"hw3_tb core_top_inst ex_mem_rdst_id", false,-1, 31,0);
        tracep->declBit(c+92,"hw3_tb core_top_inst ex_mem_we_regfile", false,-1);
        tracep->declBit(c+93,"hw3_tb core_top_inst ex_mem_we_dmem", false,-1);
        tracep->declBus(c+94,"hw3_tb core_top_inst ex_mem_wbsel", false,-1, 1,0);
        tracep->declBus(c+95,"hw3_tb core_top_inst mem_wb_addr", false,-1, 31,0);
        tracep->declBus(c+96,"hw3_tb core_top_inst mem_wb_rd", false,-1, 31,0);
        tracep->declBus(c+97,"hw3_tb core_top_inst mem_wb_rdst_id", false,-1, 31,0);
        tracep->declBit(c+98,"hw3_tb core_top_inst mem_wb_we_regfile", false,-1);
        tracep->declBit(c+99,"hw3_tb core_top_inst data_hazard", false,-1);
        tracep->declBit(c+100,"hw3_tb core_top_inst control_hazard", false,-1);
        tracep->declBus(c+190,"hw3_tb core_top_inst decode_inst DWIDTH", false,-1, 31,0);
        tracep->declBus(c+76,"hw3_tb core_top_inst decode_inst instr", false,-1, 31,0);
        tracep->declBus(c+57,"hw3_tb core_top_inst decode_inst op", false,-1, 3,0);
        tracep->declBit(c+58,"hw3_tb core_top_inst decode_inst ssel", false,-1);
        tracep->declBus(c+59,"hw3_tb core_top_inst decode_inst wbsel", false,-1, 1,0);
        tracep->declBit(c+60,"hw3_tb core_top_inst decode_inst we_regfile", false,-1);
        tracep->declBit(c+61,"hw3_tb core_top_inst decode_inst we_dmem", false,-1);
        tracep->declBus(c+62,"hw3_tb core_top_inst decode_inst jump_type", false,-1, 2,0);
        tracep->declBus(c+63,"hw3_tb core_top_inst decode_inst jump_addr", false,-1, 25,0);
        tracep->declBus(c+64,"hw3_tb core_top_inst decode_inst imm", false,-1, 31,0);
        tracep->declBus(c+65,"hw3_tb core_top_inst decode_inst rs1_id", false,-1, 4,0);
        tracep->declBus(c+66,"hw3_tb core_top_inst decode_inst rs2_id", false,-1, 4,0);
        tracep->declBus(c+67,"hw3_tb core_top_inst decode_inst rdst_id", false,-1, 4,0);
        tracep->declBus(c+198,"hw3_tb core_top_inst decode_inst OP_R_TYPE", false,-1, 5,0);
        tracep->declBus(c+199,"hw3_tb core_top_inst decode_inst OP_ADDI", false,-1, 5,0);
        tracep->declBus(c+200,"hw3_tb core_top_inst decode_inst OP_SLTI", false,-1, 5,0);
        tracep->declBus(c+201,"hw3_tb core_top_inst decode_inst OP_LW", false,-1, 5,0);
        tracep->declBus(c+202,"hw3_tb core_top_inst decode_inst OP_SW", false,-1, 5,0);
        tracep->declBus(c+203,"hw3_tb core_top_inst decode_inst OP_BEQ", false,-1, 5,0);
        tracep->declBus(c+204,"hw3_tb core_top_inst decode_inst OP_JAL", false,-1, 5,0);
        tracep->declBus(c+205,"hw3_tb core_top_inst decode_inst OP_J", false,-1, 5,0);
        tracep->declBus(c+206,"hw3_tb core_top_inst decode_inst FUNCT_ADD", false,-1, 5,0);
        tracep->declBus(c+207,"hw3_tb core_top_inst decode_inst FUNCT_SUB", false,-1, 5,0);
        tracep->declBus(c+208,"hw3_tb core_top_inst decode_inst FUNCT_AND", false,-1, 5,0);
        tracep->declBus(c+209,"hw3_tb core_top_inst decode_inst FUNCT_OR", false,-1, 5,0);
        tracep->declBus(c+210,"hw3_tb core_top_inst decode_inst FUNCT_NOR", false,-1, 5,0);
        tracep->declBus(c+211,"hw3_tb core_top_inst decode_inst FUNCT_SLT", false,-1, 5,0);
        tracep->declBus(c+199,"hw3_tb core_top_inst decode_inst FUNCT_JR", false,-1, 5,0);
        tracep->declBus(c+212,"hw3_tb core_top_inst decode_inst ALU_OP_AND", false,-1, 3,0);
        tracep->declBus(c+213,"hw3_tb core_top_inst decode_inst ALU_OP_OR", false,-1, 3,0);
        tracep->declBus(c+214,"hw3_tb core_top_inst decode_inst ALU_OP_ADD", false,-1, 3,0);
        tracep->declBus(c+215,"hw3_tb core_top_inst decode_inst ALU_OP_SUB", false,-1, 3,0);
        tracep->declBus(c+216,"hw3_tb core_top_inst decode_inst ALU_OP_NOR", false,-1, 3,0);
        tracep->declBus(c+217,"hw3_tb core_top_inst decode_inst ALU_OP_SLT", false,-1, 3,0);
        tracep->declBus(c+218,"hw3_tb core_top_inst decode_inst ALU_OP_NOP", false,-1, 3,0);
        tracep->declBus(c+193,"hw3_tb core_top_inst decode_inst J_TYPE_NOP", false,-1, 2,0);
        tracep->declBus(c+194,"hw3_tb core_top_inst decode_inst J_TYPE_BEQ", false,-1, 2,0);
        tracep->declBus(c+195,"hw3_tb core_top_inst decode_inst J_TYPE_JAL", false,-1, 2,0);
        tracep->declBus(c+196,"hw3_tb core_top_inst decode_inst J_TYPE_JR", false,-1, 2,0);
        tracep->declBus(c+197,"hw3_tb core_top_inst decode_inst J_TYPE_J", false,-1, 2,0);
        tracep->declBus(c+101,"hw3_tb core_top_inst decode_inst opcode", false,-1, 5,0);
        tracep->declBus(c+65,"hw3_tb core_top_inst decode_inst rs", false,-1, 4,0);
        tracep->declBus(c+66,"hw3_tb core_top_inst decode_inst rt", false,-1, 4,0);
        tracep->declBus(c+102,"hw3_tb core_top_inst decode_inst rd", false,-1, 4,0);
        tracep->declBus(c+103,"hw3_tb core_top_inst decode_inst shamt", false,-1, 4,0);
        tracep->declBus(c+104,"hw3_tb core_top_inst decode_inst funct", false,-1, 5,0);
        tracep->declBus(c+105,"hw3_tb core_top_inst decode_inst immediate", false,-1, 15,0);
        tracep->declBus(c+63,"hw3_tb core_top_inst decode_inst address", false,-1, 25,0);
        tracep->declBit(c+106,"hw3_tb core_top_inst decode_inst is_r_type", false,-1);
        tracep->declBit(c+107,"hw3_tb core_top_inst decode_inst is_addi", false,-1);
        tracep->declBit(c+108,"hw3_tb core_top_inst decode_inst is_slti", false,-1);
        tracep->declBit(c+109,"hw3_tb core_top_inst decode_inst is_lw", false,-1);
        tracep->declBit(c+61,"hw3_tb core_top_inst decode_inst is_sw", false,-1);
        tracep->declBit(c+110,"hw3_tb core_top_inst decode_inst is_beq", false,-1);
        tracep->declBit(c+111,"hw3_tb core_top_inst decode_inst is_jal", false,-1);
        tracep->declBit(c+112,"hw3_tb core_top_inst decode_inst is_j", false,-1);
        tracep->declBus(c+190,"hw3_tb core_top_inst reg_file_inst DWIDTH", false,-1, 31,0);
        tracep->declBit(c+152,"hw3_tb core_top_inst reg_file_inst clk", false,-1);
        tracep->declBit(c+153,"hw3_tb core_top_inst reg_file_inst rst", false,-1);
        tracep->declBus(c+65,"hw3_tb core_top_inst reg_file_inst rs1_id", false,-1, 4,0);
        tracep->declBus(c+66,"hw3_tb core_top_inst reg_file_inst rs2_id", false,-1, 4,0);
        tracep->declBit(c+98,"hw3_tb core_top_inst reg_file_inst we", false,-1);
        tracep->declBus(c+113,"hw3_tb core_top_inst reg_file_inst rdst_id", false,-1, 4,0);
        tracep->declBus(c+96,"hw3_tb core_top_inst reg_file_inst rdst", false,-1, 31,0);
        tracep->declBus(c+68,"hw3_tb core_top_inst reg_file_inst rs1", false,-1, 31,0);
        tracep->declBus(c+69,"hw3_tb core_top_inst reg_file_inst rs2", false,-1, 31,0);
        {int i; for (i=0; i<32; i++) {
                tracep->declBus(c+114+i*1,"hw3_tb core_top_inst reg_file_inst R", true,(i+0), 31,0);}}
        tracep->declBus(c+146,"hw3_tb core_top_inst reg_file_inst i", false,-1, 31,0);
        tracep->declBus(c+190,"hw3_tb core_top_inst alu_inst DWIDTH", false,-1, 31,0);
        tracep->declBus(c+147,"hw3_tb core_top_inst alu_inst op", false,-1, 3,0);
        tracep->declBus(c+70,"hw3_tb core_top_inst alu_inst rs1", false,-1, 31,0);
        tracep->declBus(c+71,"hw3_tb core_top_inst alu_inst rs2", false,-1, 31,0);
        tracep->declBus(c+72,"hw3_tb core_top_inst alu_inst rd", false,-1, 31,0);
        tracep->declBit(c+73,"hw3_tb core_top_inst alu_inst zero", false,-1);
        tracep->declBit(c+74,"hw3_tb core_top_inst alu_inst overflow", false,-1);
        tracep->declBus(c+212,"hw3_tb core_top_inst alu_inst OP_AND", false,-1, 3,0);
        tracep->declBus(c+213,"hw3_tb core_top_inst alu_inst OP_OR", false,-1, 3,0);
        tracep->declBus(c+214,"hw3_tb core_top_inst alu_inst OP_ADD", false,-1, 3,0);
        tracep->declBus(c+215,"hw3_tb core_top_inst alu_inst OP_SUB", false,-1, 3,0);
        tracep->declBus(c+216,"hw3_tb core_top_inst alu_inst OP_NOR", false,-1, 3,0);
        tracep->declBus(c+217,"hw3_tb core_top_inst alu_inst OP_SLT", false,-1, 3,0);
        tracep->declBus(c+219,"hw3_tb core_top_inst alu_inst OP_SLL", false,-1, 3,0);
        tracep->declBus(c+220,"hw3_tb core_top_inst alu_inst OP_SRL", false,-1, 3,0);
        tracep->declBus(c+221,"hw3_tb core_top_inst alu_inst OP_SRA", false,-1, 3,0);
        tracep->declBus(c+222,"hw3_tb core_top_inst alu_inst OP_LUI", false,-1, 3,0);
        tracep->declQuad(c+148,"hw3_tb core_top_inst alu_inst result", false,-1, 32,0);
        tracep->declBit(c+152,"hw3_tb core_top_inst dmem_inst clk", false,-1);
        tracep->declBus(c+150,"hw3_tb core_top_inst dmem_inst addr", false,-1, 5,0);
        tracep->declBit(c+93,"hw3_tb core_top_inst dmem_inst we", false,-1);
        tracep->declBus(c+90,"hw3_tb core_top_inst dmem_inst wdata", false,-1, 31,0);
        tracep->declBus(c+157,"hw3_tb core_top_inst dmem_inst rdata", false,-1, 31,0);
        {int i; for (i=0; i<16; i++) {
                tracep->declBus(c+158+i*1,"hw3_tb core_top_inst dmem_inst RAM", true,(i+0), 31,0);}}
        tracep->declBus(c+1,"hw3_tb core_top_inst dmem_inst idx", false,-1, 31,0);
        tracep->declBus(c+151,"hw3_tb core_top_inst imem_inst addr", false,-1, 5,0);
        tracep->declBus(c+155,"hw3_tb core_top_inst imem_inst rdata", false,-1, 31,0);
        {int i; for (i=0; i<16; i++) {
                tracep->declBus(c+174+i*1,"hw3_tb core_top_inst imem_inst RAM", true,(i+0), 31,0);}}
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
        tracep->fullIData(oldp+1,(vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.__PVT__idx),32);
        tracep->fullBit(oldp+2,(vlSymsp->TOP__hw3_tb.finish));
        tracep->fullIData(oldp+3,(vlSymsp->TOP__hw3_tb.__PVT__i),32);
        tracep->fullIData(oldp+4,(vlSymsp->TOP__hw3_tb.__PVT__cycle_count),32);
        tracep->fullIData(oldp+5,(vlSymsp->TOP__hw3_tb.__PVT__golden_reg[0]),32);
        tracep->fullIData(oldp+6,(vlSymsp->TOP__hw3_tb.__PVT__golden_reg[1]),32);
        tracep->fullIData(oldp+7,(vlSymsp->TOP__hw3_tb.__PVT__golden_reg[2]),32);
        tracep->fullIData(oldp+8,(vlSymsp->TOP__hw3_tb.__PVT__golden_reg[3]),32);
        tracep->fullIData(oldp+9,(vlSymsp->TOP__hw3_tb.__PVT__golden_reg[4]),32);
        tracep->fullIData(oldp+10,(vlSymsp->TOP__hw3_tb.__PVT__golden_reg[5]),32);
        tracep->fullIData(oldp+11,(vlSymsp->TOP__hw3_tb.__PVT__golden_reg[6]),32);
        tracep->fullIData(oldp+12,(vlSymsp->TOP__hw3_tb.__PVT__golden_reg[7]),32);
        tracep->fullIData(oldp+13,(vlSymsp->TOP__hw3_tb.__PVT__golden_reg[8]),32);
        tracep->fullIData(oldp+14,(vlSymsp->TOP__hw3_tb.__PVT__golden_reg[9]),32);
        tracep->fullIData(oldp+15,(vlSymsp->TOP__hw3_tb.__PVT__golden_reg[10]),32);
        tracep->fullIData(oldp+16,(vlSymsp->TOP__hw3_tb.__PVT__golden_reg[11]),32);
        tracep->fullIData(oldp+17,(vlSymsp->TOP__hw3_tb.__PVT__golden_reg[12]),32);
        tracep->fullIData(oldp+18,(vlSymsp->TOP__hw3_tb.__PVT__golden_reg[13]),32);
        tracep->fullIData(oldp+19,(vlSymsp->TOP__hw3_tb.__PVT__golden_reg[14]),32);
        tracep->fullIData(oldp+20,(vlSymsp->TOP__hw3_tb.__PVT__golden_reg[15]),32);
        tracep->fullIData(oldp+21,(vlSymsp->TOP__hw3_tb.__PVT__golden_reg[16]),32);
        tracep->fullIData(oldp+22,(vlSymsp->TOP__hw3_tb.__PVT__golden_reg[17]),32);
        tracep->fullIData(oldp+23,(vlSymsp->TOP__hw3_tb.__PVT__golden_reg[18]),32);
        tracep->fullIData(oldp+24,(vlSymsp->TOP__hw3_tb.__PVT__golden_reg[19]),32);
        tracep->fullIData(oldp+25,(vlSymsp->TOP__hw3_tb.__PVT__golden_reg[20]),32);
        tracep->fullIData(oldp+26,(vlSymsp->TOP__hw3_tb.__PVT__golden_reg[21]),32);
        tracep->fullIData(oldp+27,(vlSymsp->TOP__hw3_tb.__PVT__golden_reg[22]),32);
        tracep->fullIData(oldp+28,(vlSymsp->TOP__hw3_tb.__PVT__golden_reg[23]),32);
        tracep->fullIData(oldp+29,(vlSymsp->TOP__hw3_tb.__PVT__golden_reg[24]),32);
        tracep->fullIData(oldp+30,(vlSymsp->TOP__hw3_tb.__PVT__golden_reg[25]),32);
        tracep->fullIData(oldp+31,(vlSymsp->TOP__hw3_tb.__PVT__golden_reg[26]),32);
        tracep->fullIData(oldp+32,(vlSymsp->TOP__hw3_tb.__PVT__golden_reg[27]),32);
        tracep->fullIData(oldp+33,(vlSymsp->TOP__hw3_tb.__PVT__golden_reg[28]),32);
        tracep->fullIData(oldp+34,(vlSymsp->TOP__hw3_tb.__PVT__golden_reg[29]),32);
        tracep->fullIData(oldp+35,(vlSymsp->TOP__hw3_tb.__PVT__golden_reg[30]),32);
        tracep->fullIData(oldp+36,(vlSymsp->TOP__hw3_tb.__PVT__golden_reg[31]),32);
        tracep->fullIData(oldp+37,(vlSymsp->TOP__hw3_tb.__PVT__golden_dmem[0]),32);
        tracep->fullIData(oldp+38,(vlSymsp->TOP__hw3_tb.__PVT__golden_dmem[1]),32);
        tracep->fullIData(oldp+39,(vlSymsp->TOP__hw3_tb.__PVT__golden_dmem[2]),32);
        tracep->fullIData(oldp+40,(vlSymsp->TOP__hw3_tb.__PVT__golden_dmem[3]),32);
        tracep->fullIData(oldp+41,(vlSymsp->TOP__hw3_tb.__PVT__golden_dmem[4]),32);
        tracep->fullIData(oldp+42,(vlSymsp->TOP__hw3_tb.__PVT__golden_dmem[5]),32);
        tracep->fullIData(oldp+43,(vlSymsp->TOP__hw3_tb.__PVT__golden_dmem[6]),32);
        tracep->fullIData(oldp+44,(vlSymsp->TOP__hw3_tb.__PVT__golden_dmem[7]),32);
        tracep->fullIData(oldp+45,(vlSymsp->TOP__hw3_tb.__PVT__golden_dmem[8]),32);
        tracep->fullIData(oldp+46,(vlSymsp->TOP__hw3_tb.__PVT__golden_dmem[9]),32);
        tracep->fullIData(oldp+47,(vlSymsp->TOP__hw3_tb.__PVT__golden_dmem[10]),32);
        tracep->fullIData(oldp+48,(vlSymsp->TOP__hw3_tb.__PVT__golden_dmem[11]),32);
        tracep->fullIData(oldp+49,(vlSymsp->TOP__hw3_tb.__PVT__golden_dmem[12]),32);
        tracep->fullIData(oldp+50,(vlSymsp->TOP__hw3_tb.__PVT__golden_dmem[13]),32);
        tracep->fullIData(oldp+51,(vlSymsp->TOP__hw3_tb.__PVT__golden_dmem[14]),32);
        tracep->fullIData(oldp+52,(vlSymsp->TOP__hw3_tb.__PVT__golden_dmem[15]),32);
        tracep->fullBit(oldp+53,(vlSymsp->TOP__hw3_tb.__PVT__start));
        tracep->fullIData(oldp+54,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__pc),32);
        tracep->fullIData(oldp+55,(((IData)(4U) + vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__pc)),32);
        tracep->fullBit(oldp+56,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__pc_write));
        tracep->fullCData(oldp+57,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__op),4);
        tracep->fullBit(oldp+58,(((0U == (0x3fU & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                                   >> 0x1aU))) 
                                  | (4U == (0x3fU & 
                                            (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                             >> 0x1aU))))));
        tracep->fullCData(oldp+59,(((0x23U == (0x3fU 
                                               & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                                  >> 0x1aU)))
                                     ? 1U : ((3U == 
                                              (0x3fU 
                                               & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                                  >> 0x1aU)))
                                              ? 2U : 0U))),2);
        tracep->fullBit(oldp+60,((1U & ((0U == (0x3fU 
                                                & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                                   >> 0x1aU)))
                                         ? ((8U == 
                                             (0x3fU 
                                              & vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr))
                                             ? 0U : 1U)
                                         : ((((8U == 
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
                                            | (3U == 
                                               (0x3fU 
                                                & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                                   >> 0x1aU))))))));
        tracep->fullBit(oldp+61,((0x2bU == (0x3fU & 
                                            (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                             >> 0x1aU)))));
        tracep->fullCData(oldp+62,(((0x80000000U & vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr)
                                     ? 0U : ((0x40000000U 
                                              & vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr)
                                              ? 0U : 
                                             ((0x20000000U 
                                               & vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr)
                                               ? 0U
                                               : ((0x10000000U 
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
        tracep->fullIData(oldp+63,((0x3ffffffU & vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr)),26);
        tracep->fullIData(oldp+64,(((0xffff0000U & 
                                     ((- (IData)((1U 
                                                  & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                                     >> 0xfU)))) 
                                      << 0x10U)) | 
                                    (0xffffU & vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr))),32);
        tracep->fullCData(oldp+65,((0x1fU & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                             >> 0x15U))),5);
        tracep->fullCData(oldp+66,((0x1fU & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                             >> 0x10U))),5);
        tracep->fullCData(oldp+67,((0x1fU & ((0U == 
                                              (0x3fU 
                                               & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                                  >> 0x1aU)))
                                              ? (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                                 >> 0xbU)
                                              : (((
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
                                                   : 0U))))),5);
        tracep->fullIData(oldp+68,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R
                                   [(0x1fU & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                              >> 0x15U))]),32);
        tracep->fullIData(oldp+69,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R
                                   [(0x1fU & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                              >> 0x10U))]),32);
        tracep->fullIData(oldp+70,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_rs1_out),32);
        tracep->fullIData(oldp+71,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__alu_rs2),32);
        tracep->fullIData(oldp+72,((IData)(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__alu_inst__DOT__result)),32);
        tracep->fullBit(oldp+73,((0U == (IData)(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__alu_inst__DOT__result))));
        tracep->fullBit(oldp+74,((1U & ((2U == (0xfU 
                                                & vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_op))
                                         ? ((~ ((vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_rs1_out 
                                                 ^ vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__alu_rs2) 
                                                >> 0x1fU)) 
                                            & ((vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_rs1_out 
                                                >> 0x1fU) 
                                               ^ (IData)(
                                                         (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__alu_inst__DOT__result 
                                                          >> 0x1fU))))
                                         : ((6U == 
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
        tracep->fullIData(oldp+75,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_addr),32);
        tracep->fullIData(oldp+76,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr),32);
        tracep->fullIData(oldp+77,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_addr),32);
        tracep->fullIData(oldp+78,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_jump_type),32);
        tracep->fullIData(oldp+79,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_jump_addr),32);
        tracep->fullIData(oldp+80,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_op),32);
        tracep->fullIData(oldp+81,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_imm),32);
        tracep->fullIData(oldp+82,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_rs2_out),32);
        tracep->fullIData(oldp+83,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_rdst_id),32);
        tracep->fullBit(oldp+84,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_we_regfile));
        tracep->fullBit(oldp+85,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_we_dmem));
        tracep->fullCData(oldp+86,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_wbsel),2);
        tracep->fullBit(oldp+87,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_ssel));
        tracep->fullIData(oldp+88,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__ex_mem_addr),32);
        tracep->fullIData(oldp+89,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__ex_mem_alu_out),32);
        tracep->fullIData(oldp+90,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__ex_mem_rs2_out),32);
        tracep->fullIData(oldp+91,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__ex_mem_rdst_id),32);
        tracep->fullBit(oldp+92,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__ex_mem_we_regfile));
        tracep->fullBit(oldp+93,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__ex_mem_we_dmem));
        tracep->fullCData(oldp+94,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__ex_mem_wbsel),2);
        tracep->fullIData(oldp+95,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__mem_wb_addr),32);
        tracep->fullIData(oldp+96,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__mem_wb_rd),32);
        tracep->fullIData(oldp+97,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__mem_wb_rdst_id),32);
        tracep->fullBit(oldp+98,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__mem_wb_we_regfile));
        tracep->fullBit(oldp+99,((((((IData)(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_we_regfile) 
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
                                             == (0x1fU 
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
        tracep->fullBit(oldp+100,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__control_hazard));
        tracep->fullCData(oldp+101,((0x3fU & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                              >> 0x1aU))),6);
        tracep->fullCData(oldp+102,((0x1fU & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                              >> 0xbU))),5);
        tracep->fullCData(oldp+103,((0x1fU & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                              >> 6U))),5);
        tracep->fullCData(oldp+104,((0x3fU & vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr)),6);
        tracep->fullSData(oldp+105,((0xffffU & vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr)),16);
        tracep->fullBit(oldp+106,((0U == (0x3fU & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                                   >> 0x1aU)))));
        tracep->fullBit(oldp+107,((8U == (0x3fU & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                                   >> 0x1aU)))));
        tracep->fullBit(oldp+108,((0xaU == (0x3fU & 
                                            (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                             >> 0x1aU)))));
        tracep->fullBit(oldp+109,((0x23U == (0x3fU 
                                             & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                                >> 0x1aU)))));
        tracep->fullBit(oldp+110,((4U == (0x3fU & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                                   >> 0x1aU)))));
        tracep->fullBit(oldp+111,((3U == (0x3fU & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                                   >> 0x1aU)))));
        tracep->fullBit(oldp+112,((2U == (0x3fU & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__if_id_instr 
                                                   >> 0x1aU)))));
        tracep->fullCData(oldp+113,((0x1fU & vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__mem_wb_rdst_id)),5);
        tracep->fullIData(oldp+114,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[0]),32);
        tracep->fullIData(oldp+115,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[1]),32);
        tracep->fullIData(oldp+116,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[2]),32);
        tracep->fullIData(oldp+117,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[3]),32);
        tracep->fullIData(oldp+118,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[4]),32);
        tracep->fullIData(oldp+119,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[5]),32);
        tracep->fullIData(oldp+120,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[6]),32);
        tracep->fullIData(oldp+121,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[7]),32);
        tracep->fullIData(oldp+122,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[8]),32);
        tracep->fullIData(oldp+123,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[9]),32);
        tracep->fullIData(oldp+124,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[10]),32);
        tracep->fullIData(oldp+125,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[11]),32);
        tracep->fullIData(oldp+126,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[12]),32);
        tracep->fullIData(oldp+127,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[13]),32);
        tracep->fullIData(oldp+128,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[14]),32);
        tracep->fullIData(oldp+129,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[15]),32);
        tracep->fullIData(oldp+130,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[16]),32);
        tracep->fullIData(oldp+131,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[17]),32);
        tracep->fullIData(oldp+132,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[18]),32);
        tracep->fullIData(oldp+133,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[19]),32);
        tracep->fullIData(oldp+134,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[20]),32);
        tracep->fullIData(oldp+135,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[21]),32);
        tracep->fullIData(oldp+136,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[22]),32);
        tracep->fullIData(oldp+137,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[23]),32);
        tracep->fullIData(oldp+138,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[24]),32);
        tracep->fullIData(oldp+139,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[25]),32);
        tracep->fullIData(oldp+140,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[26]),32);
        tracep->fullIData(oldp+141,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[27]),32);
        tracep->fullIData(oldp+142,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[28]),32);
        tracep->fullIData(oldp+143,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[29]),32);
        tracep->fullIData(oldp+144,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[30]),32);
        tracep->fullIData(oldp+145,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R[31]),32);
        tracep->fullIData(oldp+146,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__i),32);
        tracep->fullCData(oldp+147,((0xfU & vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__id_ex_op)),4);
        tracep->fullQData(oldp+148,(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__alu_inst__DOT__result),33);
        tracep->fullCData(oldp+150,((0x3fU & vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__ex_mem_alu_out)),6);
        tracep->fullCData(oldp+151,((0x3fU & vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__pc)),6);
        tracep->fullBit(oldp+152,(vlTOPp->clk));
        tracep->fullBit(oldp+153,(vlTOPp->rst));
        tracep->fullBit(oldp+154,(vlTOPp->finish));
        tracep->fullIData(oldp+155,(vlSymsp->TOP__hw3_tb__core_top_inst__imem_inst.RAM
                                    [(0xfU & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__pc 
                                              >> 2U))]),32);
        tracep->fullIData(oldp+156,(((0U == (IData)(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__ex_mem_wbsel))
                                      ? vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__ex_mem_alu_out
                                      : ((1U == (IData)(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__ex_mem_wbsel))
                                          ? vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM
                                         [(0xfU & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__ex_mem_alu_out 
                                                   >> 2U))]
                                          : ((2U == (IData)(vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__ex_mem_wbsel))
                                              ? ((IData)(4U) 
                                                 + vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__ex_mem_addr)
                                              : 0U)))),32);
        tracep->fullIData(oldp+157,(vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM
                                    [(0xfU & (vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__ex_mem_alu_out 
                                              >> 2U))]),32);
        tracep->fullIData(oldp+158,(vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM[0]),32);
        tracep->fullIData(oldp+159,(vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM[1]),32);
        tracep->fullIData(oldp+160,(vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM[2]),32);
        tracep->fullIData(oldp+161,(vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM[3]),32);
        tracep->fullIData(oldp+162,(vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM[4]),32);
        tracep->fullIData(oldp+163,(vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM[5]),32);
        tracep->fullIData(oldp+164,(vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM[6]),32);
        tracep->fullIData(oldp+165,(vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM[7]),32);
        tracep->fullIData(oldp+166,(vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM[8]),32);
        tracep->fullIData(oldp+167,(vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM[9]),32);
        tracep->fullIData(oldp+168,(vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM[10]),32);
        tracep->fullIData(oldp+169,(vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM[11]),32);
        tracep->fullIData(oldp+170,(vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM[12]),32);
        tracep->fullIData(oldp+171,(vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM[13]),32);
        tracep->fullIData(oldp+172,(vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM[14]),32);
        tracep->fullIData(oldp+173,(vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM[15]),32);
        tracep->fullIData(oldp+174,(vlSymsp->TOP__hw3_tb__core_top_inst__imem_inst.RAM[0]),32);
        tracep->fullIData(oldp+175,(vlSymsp->TOP__hw3_tb__core_top_inst__imem_inst.RAM[1]),32);
        tracep->fullIData(oldp+176,(vlSymsp->TOP__hw3_tb__core_top_inst__imem_inst.RAM[2]),32);
        tracep->fullIData(oldp+177,(vlSymsp->TOP__hw3_tb__core_top_inst__imem_inst.RAM[3]),32);
        tracep->fullIData(oldp+178,(vlSymsp->TOP__hw3_tb__core_top_inst__imem_inst.RAM[4]),32);
        tracep->fullIData(oldp+179,(vlSymsp->TOP__hw3_tb__core_top_inst__imem_inst.RAM[5]),32);
        tracep->fullIData(oldp+180,(vlSymsp->TOP__hw3_tb__core_top_inst__imem_inst.RAM[6]),32);
        tracep->fullIData(oldp+181,(vlSymsp->TOP__hw3_tb__core_top_inst__imem_inst.RAM[7]),32);
        tracep->fullIData(oldp+182,(vlSymsp->TOP__hw3_tb__core_top_inst__imem_inst.RAM[8]),32);
        tracep->fullIData(oldp+183,(vlSymsp->TOP__hw3_tb__core_top_inst__imem_inst.RAM[9]),32);
        tracep->fullIData(oldp+184,(vlSymsp->TOP__hw3_tb__core_top_inst__imem_inst.RAM[10]),32);
        tracep->fullIData(oldp+185,(vlSymsp->TOP__hw3_tb__core_top_inst__imem_inst.RAM[11]),32);
        tracep->fullIData(oldp+186,(vlSymsp->TOP__hw3_tb__core_top_inst__imem_inst.RAM[12]),32);
        tracep->fullIData(oldp+187,(vlSymsp->TOP__hw3_tb__core_top_inst__imem_inst.RAM[13]),32);
        tracep->fullIData(oldp+188,(vlSymsp->TOP__hw3_tb__core_top_inst__imem_inst.RAM[14]),32);
        tracep->fullIData(oldp+189,(vlSymsp->TOP__hw3_tb__core_top_inst__imem_inst.RAM[15]),32);
        tracep->fullIData(oldp+190,(0x20U),32);
        tracep->fullIData(oldp+191,(vlSymsp->TOP__hw3_tb.__PVT__tmp),32);
        tracep->fullIData(oldp+192,(0x40U),32);
        tracep->fullCData(oldp+193,(0U),3);
        tracep->fullCData(oldp+194,(1U),3);
        tracep->fullCData(oldp+195,(2U),3);
        tracep->fullCData(oldp+196,(3U),3);
        tracep->fullCData(oldp+197,(4U),3);
        tracep->fullCData(oldp+198,(0U),6);
        tracep->fullCData(oldp+199,(8U),6);
        tracep->fullCData(oldp+200,(0xaU),6);
        tracep->fullCData(oldp+201,(0x23U),6);
        tracep->fullCData(oldp+202,(0x2bU),6);
        tracep->fullCData(oldp+203,(4U),6);
        tracep->fullCData(oldp+204,(3U),6);
        tracep->fullCData(oldp+205,(2U),6);
        tracep->fullCData(oldp+206,(0x20U),6);
        tracep->fullCData(oldp+207,(0x22U),6);
        tracep->fullCData(oldp+208,(0x24U),6);
        tracep->fullCData(oldp+209,(0x25U),6);
        tracep->fullCData(oldp+210,(0x27U),6);
        tracep->fullCData(oldp+211,(0x2aU),6);
        tracep->fullCData(oldp+212,(0U),4);
        tracep->fullCData(oldp+213,(1U),4);
        tracep->fullCData(oldp+214,(2U),4);
        tracep->fullCData(oldp+215,(6U),4);
        tracep->fullCData(oldp+216,(0xcU),4);
        tracep->fullCData(oldp+217,(7U),4);
        tracep->fullCData(oldp+218,(0xfU),4);
        tracep->fullCData(oldp+219,(9U),4);
        tracep->fullCData(oldp+220,(0xaU),4);
        tracep->fullCData(oldp+221,(0xdU),4);
        tracep->fullCData(oldp+222,(0xeU),4);
    }
}
