// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vhw3_tb.h for the primary calling header

#ifndef _VHW3_TB_HW3_TB_H_
#define _VHW3_TB_HW3_TB_H_  // guard

#include "verilated_heavy.h"
#include "Vhw3_tb__Dpi.h"

//==========

class Vhw3_tb__Syms;
class Vhw3_tb_VerilatedVcd;
class Vhw3_tb_core_top;


//----------

VL_MODULE(Vhw3_tb_hw3_tb) {
  public:
    // CELLS
    Vhw3_tb_core_top* core_top_inst;
    
    // PORTS
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_OUT8(finish,0,0);
    
    // LOCAL SIGNALS
    CData/*0:0*/ __PVT__start;
    IData/*31:0*/ __PVT__i;
    IData/*31:0*/ __PVT__tmp;
    IData/*31:0*/ __PVT__cycle_count;
    IData/*31:0*/ __PVT__golden_reg[32];
    IData/*31:0*/ __PVT__golden_dmem[16];
    
    // INTERNAL VARIABLES
  private:
    Vhw3_tb__Syms* __VlSymsp;  // Symbol table
  public:
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vhw3_tb_hw3_tb);  ///< Copying not allowed
  public:
    Vhw3_tb_hw3_tb(const char* name = "TOP");
    ~Vhw3_tb_hw3_tb();
    
    // INTERNAL METHODS
    void __Vconfigure(Vhw3_tb__Syms* symsp, bool first);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _initial__TOP__hw3_tb__2(Vhw3_tb__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__hw3_tb__1(Vhw3_tb__Syms* __restrict vlSymsp);
  private:
    static void traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
