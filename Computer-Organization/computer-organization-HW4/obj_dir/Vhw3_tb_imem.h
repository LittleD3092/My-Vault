// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vhw3_tb.h for the primary calling header

#ifndef _VHW3_TB_IMEM_H_
#define _VHW3_TB_IMEM_H_  // guard

#include "verilated_heavy.h"
#include "Vhw3_tb__Dpi.h"

//==========

class Vhw3_tb__Syms;
class Vhw3_tb_VerilatedVcd;


//----------

VL_MODULE(Vhw3_tb_imem) {
  public:
    
    // PORTS
    VL_IN8(__PVT__addr,5,0);
    VL_OUT(__PVT__rdata,31,0);
    
    // LOCAL SIGNALS
    IData/*31:0*/ RAM[16];
    
    // INTERNAL VARIABLES
  private:
    Vhw3_tb__Syms* __VlSymsp;  // Symbol table
  public:
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vhw3_tb_imem);  ///< Copying not allowed
  public:
    Vhw3_tb_imem(const char* name = "TOP");
    ~Vhw3_tb_imem();
    
    // INTERNAL METHODS
    void __Vconfigure(Vhw3_tb__Syms* symsp, bool first);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _initial__TOP__hw3_tb__core_top_inst__imem_inst__1(Vhw3_tb__Syms* __restrict vlSymsp) VL_ATTR_COLD;
  private:
    static void traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
