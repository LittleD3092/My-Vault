// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef _VHW3_TB__SYMS_H_
#define _VHW3_TB__SYMS_H_  // guard

#include "verilated_heavy.h"

// INCLUDE MODULE CLASSES
#include "Vhw3_tb.h"
#include "Vhw3_tb_hw3_tb.h"
#include "Vhw3_tb_core_top.h"
#include "Vhw3_tb_dmem.h"
#include "Vhw3_tb_imem.h"

// DPI TYPES for DPI Export callbacks (Internal use)

// SYMS CLASS
class Vhw3_tb__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_activity;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode;  ///< Used by trace routines when tracing multiple models
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vhw3_tb*                       TOPp;
    Vhw3_tb_hw3_tb                 TOP__hw3_tb;
    Vhw3_tb_core_top               TOP__hw3_tb__core_top_inst;
    Vhw3_tb_dmem                   TOP__hw3_tb__core_top_inst__dmem_inst;
    Vhw3_tb_imem                   TOP__hw3_tb__core_top_inst__imem_inst;
    
    // SCOPE NAMES
    VerilatedScope __Vscope_hw3_tb__core_top_inst__dmem_inst;
    VerilatedScope __Vscope_hw3_tb__core_top_inst__imem_inst;
    
    // CREATORS
    Vhw3_tb__Syms(Vhw3_tb* topp, const char* namep);
    ~Vhw3_tb__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
