// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vhw3_tb.h for the primary calling header

#ifndef _VHW3_TB_CORE_TOP_H_
#define _VHW3_TB_CORE_TOP_H_  // guard

#include "verilated_heavy.h"
#include "Vhw3_tb__Dpi.h"

//==========

class Vhw3_tb__Syms;
class Vhw3_tb_VerilatedVcd;
class Vhw3_tb_imem;
class Vhw3_tb_dmem;


//----------

VL_MODULE(Vhw3_tb_core_top) {
  public:
    // CELLS
    Vhw3_tb_imem* imem_inst;
    Vhw3_tb_dmem* dmem_inst;
    
    // PORTS
    VL_IN8(__PVT__clk,0,0);
    VL_IN8(__PVT__rst,0,0);
    
    // LOCAL SIGNALS
    CData/*0:0*/ __PVT__pc_write;
    CData/*3:0*/ __PVT__op;
    CData/*0:0*/ __PVT__id_ex_we_regfile;
    CData/*0:0*/ __PVT__id_ex_we_dmem;
    CData/*1:0*/ __PVT__id_ex_wbsel;
    CData/*0:0*/ __PVT__id_ex_ssel;
    CData/*0:0*/ __PVT__ex_mem_we_regfile;
    CData/*0:0*/ __PVT__ex_mem_we_dmem;
    CData/*1:0*/ __PVT__ex_mem_wbsel;
    CData/*0:0*/ __PVT__mem_wb_we_regfile;
    CData/*0:0*/ __PVT__control_hazard;
    IData/*31:0*/ __PVT__pc;
    IData/*31:0*/ __PVT__pc_increment;
    IData/*31:0*/ __PVT__alu_rs2;
    IData/*31:0*/ __PVT__if_id_addr;
    IData/*31:0*/ __PVT__if_id_instr;
    IData/*31:0*/ __PVT__id_ex_addr;
    IData/*31:0*/ __PVT__id_ex_jump_type;
    IData/*31:0*/ __PVT__id_ex_jump_addr;
    IData/*31:0*/ __PVT__id_ex_op;
    IData/*31:0*/ __PVT__id_ex_imm;
    IData/*31:0*/ __PVT__id_ex_rs1_out;
    IData/*31:0*/ __PVT__id_ex_rs2_out;
    IData/*31:0*/ __PVT__id_ex_rdst_id;
    IData/*31:0*/ __PVT__ex_mem_addr;
    IData/*31:0*/ __PVT__ex_mem_alu_out;
    IData/*31:0*/ __PVT__ex_mem_rs2_out;
    IData/*31:0*/ __PVT__ex_mem_rdst_id;
    IData/*31:0*/ __PVT__mem_wb_addr;
    IData/*31:0*/ __PVT__mem_wb_rd;
    IData/*31:0*/ __PVT__mem_wb_rdst_id;
    IData/*31:0*/ __PVT__reg_file_inst__DOT__i;
    QData/*32:0*/ __PVT__alu_inst__DOT__result;
    IData/*31:0*/ __PVT__reg_file_inst__DOT__R[32];
    
    // LOCAL VARIABLES
    CData/*0:0*/ __Vdlyvset__reg_file_inst__DOT__R__v0;
    CData/*4:0*/ __Vdlyvdim0__reg_file_inst__DOT__R__v32;
    CData/*0:0*/ __Vdlyvset__reg_file_inst__DOT__R__v32;
    IData/*31:0*/ __Vdly__pc;
    IData/*31:0*/ __Vdlyvval__reg_file_inst__DOT__R__v32;
    
    // INTERNAL VARIABLES
  private:
    Vhw3_tb__Syms* __VlSymsp;  // Symbol table
  public:
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vhw3_tb_core_top);  ///< Copying not allowed
  public:
    Vhw3_tb_core_top(const char* name = "TOP");
    ~Vhw3_tb_core_top();
    
    // INTERNAL METHODS
    void __Vconfigure(Vhw3_tb__Syms* symsp, bool first);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _sequent__TOP__hw3_tb__core_top_inst__1(Vhw3_tb__Syms* __restrict vlSymsp);
    static void _sequent__TOP__hw3_tb__core_top_inst__2(Vhw3_tb__Syms* __restrict vlSymsp);
    static void _settle__TOP__hw3_tb__core_top_inst__3(Vhw3_tb__Syms* __restrict vlSymsp) VL_ATTR_COLD;
  private:
    static void traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
