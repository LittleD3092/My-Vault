// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VDECODE_TB_H_
#define _VDECODE_TB_H_  // guard

#include "verilated_heavy.h"

//==========

class Vdecode_tb__Syms;
class Vdecode_tb_VerilatedVcd;


//----------

VL_MODULE(Vdecode_tb) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_OUT8(finish,0,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*3:0*/ decode_tb__DOT__op;
    CData/*0:0*/ decode_tb__DOT__ssel;
    CData/*4:0*/ decode_tb__DOT__rs1_id;
    CData/*4:0*/ decode_tb__DOT__rs2_id;
    CData/*4:0*/ decode_tb__DOT__rdst_id;
    CData/*0:0*/ decode_tb__DOT__zero;
    CData/*0:0*/ decode_tb__DOT__overflow;
    CData/*3:0*/ decode_tb__DOT__golden_op;
    CData/*0:0*/ decode_tb__DOT__golden_ssel;
    CData/*4:0*/ decode_tb__DOT__golden_rs1_id;
    CData/*4:0*/ decode_tb__DOT__golden_rs2_id;
    CData/*4:0*/ decode_tb__DOT__golden_rdst_id;
    IData/*31:0*/ decode_tb__DOT__instr;
    IData/*31:0*/ decode_tb__DOT__imm;
    IData/*31:0*/ decode_tb__DOT__rs2_reg_file_out;
    IData/*31:0*/ decode_tb__DOT__rd;
    IData/*31:0*/ decode_tb__DOT__rs1;
    IData/*31:0*/ decode_tb__DOT__rs2;
    IData/*31:0*/ decode_tb__DOT__golden_imm;
    IData/*31:0*/ decode_tb__DOT__golden_reg;
    IData/*31:0*/ decode_tb__DOT__i;
    IData/*31:0*/ decode_tb__DOT__pat_num;
    IData/*31:0*/ decode_tb__DOT__pattern;
    IData/*31:0*/ decode_tb__DOT__tmp;
    IData/*31:0*/ decode_tb__DOT__reg_pattern;
    IData/*31:0*/ decode_tb__DOT__reg_file_inst__DOT__unnamedblk1__DOT__i;
    IData/*31:0*/ decode_tb__DOT__golden_R[32];
    IData/*31:0*/ decode_tb__DOT__reg_file_inst__DOT__R[32];
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vclklast__TOP__rst;
    CData/*0:0*/ __Vclklast__TOP__clk;
    CData/*0:0*/ __Vm_traceActivity[4];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vdecode_tb__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vdecode_tb);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vdecode_tb(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vdecode_tb();
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
    static void _eval_initial_loop(Vdecode_tb__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vdecode_tb__Syms* symsp, bool first);
  private:
    static QData _change_request(Vdecode_tb__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vdecode_tb__Syms* __restrict vlSymsp);
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vdecode_tb__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vdecode_tb__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vdecode_tb__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__5(Vdecode_tb__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__1(Vdecode_tb__Syms* __restrict vlSymsp);
    static void _sequent__TOP__2(Vdecode_tb__Syms* __restrict vlSymsp);
    static void _sequent__TOP__3(Vdecode_tb__Syms* __restrict vlSymsp);
    static void _settle__TOP__4(Vdecode_tb__Syms* __restrict vlSymsp) VL_ATTR_COLD;
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
