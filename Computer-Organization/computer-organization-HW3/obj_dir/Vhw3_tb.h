// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VHW3_TB_H_
#define _VHW3_TB_H_  // guard

#include "verilated_heavy.h"

//==========

class Vhw3_tb__Syms;
class Vhw3_tb_VerilatedVcd;


//----------

VL_MODULE(Vhw3_tb) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_OUT8(finish,0,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*0:0*/ hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__clk;
    CData/*0:0*/ hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__rst;
    CData/*0:0*/ hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__clk;
    CData/*0:0*/ hw3_tb__DOT__start;
    CData/*5:0*/ hw3_tb__DOT__core_top_inst__DOT__imem_inst__DOT__addr;
    CData/*1:0*/ hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__jump_type;
    CData/*0:0*/ hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__we_dmem;
    CData/*0:0*/ hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__we_regfile;
    CData/*3:0*/ hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__op;
    CData/*1:0*/ hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__ssel;
    CData/*4:0*/ hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__rs1_id;
    CData/*4:0*/ hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__rs2_id;
    CData/*4:0*/ hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__rdst_id;
    CData/*4:0*/ hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__rs1_id;
    CData/*4:0*/ hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__rs2_id;
    CData/*0:0*/ hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__we;
    CData/*4:0*/ hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__rdst_id;
    CData/*3:0*/ hw3_tb__DOT__core_top_inst__DOT__alu_inst__DOT__op;
    CData/*0:0*/ hw3_tb__DOT__core_top_inst__DOT__alu_inst__DOT__zero;
    CData/*0:0*/ hw3_tb__DOT__core_top_inst__DOT__alu_inst__DOT__overflow;
    CData/*5:0*/ hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__addr;
    CData/*0:0*/ hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__we;
    IData/*31:0*/ hw3_tb__DOT__i;
    IData/*31:0*/ hw3_tb__DOT__tmp;
    IData/*31:0*/ hw3_tb__DOT__cycle_count;
    IData/*31:0*/ hw3_tb__DOT__core_top_inst__DOT__pc;
    IData/*31:0*/ hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__instr;
    IData/*31:0*/ hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__jump_addr;
    IData/*31:0*/ hw3_tb__DOT__core_top_inst__DOT__decode_inst__DOT__imm;
    IData/*31:0*/ hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__rdst;
    IData/*31:0*/ hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__rs1;
    IData/*31:0*/ hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__rs2;
    IData/*31:0*/ hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__unnamedblk1__DOT__i;
    IData/*31:0*/ hw3_tb__DOT__core_top_inst__DOT__alu_inst__DOT__rs1;
    IData/*31:0*/ hw3_tb__DOT__core_top_inst__DOT__alu_inst__DOT__rs2;
    IData/*31:0*/ hw3_tb__DOT__core_top_inst__DOT__alu_inst__DOT__rd;
    IData/*31:0*/ hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__wdata;
    IData/*31:0*/ hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__idx;
    IData/*31:0*/ hw3_tb__DOT__golden_reg[32];
    IData/*31:0*/ hw3_tb__DOT__golden_dmem[16];
    IData/*31:0*/ hw3_tb__DOT__core_top_inst__DOT__imem_inst__DOT__RAM[16];
    IData/*31:0*/ hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[32];
    IData/*31:0*/ hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM[16];
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*3:0*/ __Vdlyvdim0__hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM__v0;
    CData/*0:0*/ __Vdlyvset__hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM__v0;
    CData/*0:0*/ __Vclklast__TOP__hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__rst;
    CData/*0:0*/ __Vclklast__TOP__hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__clk;
    CData/*0:0*/ __Vclklast__TOP__hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__clk;
    CData/*0:0*/ __Vclklast__TOP__clk;
    IData/*31:0*/ __Vdlyvval__hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM__v0;
    CData/*0:0*/ __Vm_traceActivity[5];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vhw3_tb__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vhw3_tb);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vhw3_tb(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vhw3_tb();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vhw3_tb__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vhw3_tb__Syms* symsp, bool first);
  private:
    static QData _change_request(Vhw3_tb__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vhw3_tb__Syms* __restrict vlSymsp);
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vhw3_tb__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vhw3_tb__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vhw3_tb__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__1(Vhw3_tb__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__3(Vhw3_tb__Syms* __restrict vlSymsp);
    static void _sequent__TOP__4(Vhw3_tb__Syms* __restrict vlSymsp);
    static void _sequent__TOP__5(Vhw3_tb__Syms* __restrict vlSymsp);
    static void _sequent__TOP__6(Vhw3_tb__Syms* __restrict vlSymsp);
    static void _sequent__TOP__7(Vhw3_tb__Syms* __restrict vlSymsp);
    static void _sequent__TOP__8(Vhw3_tb__Syms* __restrict vlSymsp);
    static void _settle__TOP__2(Vhw3_tb__Syms* __restrict vlSymsp) VL_ATTR_COLD;
  private:
    static void traceChgSub0(void* userp, VerilatedVcd* tracep);
    static void traceChgTop0(void* userp, VerilatedVcd* tracep);
    static void traceCleanup(void* userp, VerilatedVcd* /*unused*/);
    static void traceFullSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceFullTop0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitTop(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    void traceRegister(VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
