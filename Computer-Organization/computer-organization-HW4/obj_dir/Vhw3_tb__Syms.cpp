// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vhw3_tb__Syms.h"
#include "Vhw3_tb.h"
#include "Vhw3_tb_hw3_tb.h"
#include "Vhw3_tb_core_top.h"
#include "Vhw3_tb_dmem.h"
#include "Vhw3_tb_imem.h"



// FUNCTIONS
Vhw3_tb__Syms::Vhw3_tb__Syms(Vhw3_tb* topp, const char* namep)
    // Setup locals
    : __Vm_namep(namep)
    , __Vm_activity(false)
    , __Vm_baseCode(0)
    , __Vm_didInit(false)
    // Setup submodule names
    , TOP__hw3_tb(Verilated::catName(topp->name(), "hw3_tb"))
    , TOP__hw3_tb__core_top_inst(Verilated::catName(topp->name(), "hw3_tb.core_top_inst"))
    , TOP__hw3_tb__core_top_inst__dmem_inst(Verilated::catName(topp->name(), "hw3_tb.core_top_inst.dmem_inst"))
    , TOP__hw3_tb__core_top_inst__imem_inst(Verilated::catName(topp->name(), "hw3_tb.core_top_inst.imem_inst"))
{
    // Pointer to top level
    TOPp = topp;
    // Setup each module's pointers to their submodules
    TOPp->hw3_tb = &TOP__hw3_tb;
    TOPp->hw3_tb->core_top_inst = &TOP__hw3_tb__core_top_inst;
    TOPp->hw3_tb->core_top_inst->dmem_inst = &TOP__hw3_tb__core_top_inst__dmem_inst;
    TOPp->hw3_tb->core_top_inst->imem_inst = &TOP__hw3_tb__core_top_inst__imem_inst;
    // Setup each module's pointer back to symbol table (for public functions)
    TOPp->__Vconfigure(this, true);
    TOP__hw3_tb.__Vconfigure(this, true);
    TOP__hw3_tb__core_top_inst.__Vconfigure(this, true);
    TOP__hw3_tb__core_top_inst__dmem_inst.__Vconfigure(this, true);
    TOP__hw3_tb__core_top_inst__imem_inst.__Vconfigure(this, true);
    // Setup scopes
    __Vscope_hw3_tb__core_top_inst__dmem_inst.configure(this, name(), "hw3_tb.core_top_inst.dmem_inst", "dmem_inst", 0, VerilatedScope::SCOPE_OTHER);
    __Vscope_hw3_tb__core_top_inst__imem_inst.configure(this, name(), "hw3_tb.core_top_inst.imem_inst", "imem_inst", 0, VerilatedScope::SCOPE_OTHER);
    // Setup export functions
    for (int __Vfinal=0; __Vfinal<2; __Vfinal++) {
        __Vscope_hw3_tb__core_top_inst__dmem_inst.varInsert(__Vfinal,"RAM", &(TOP__hw3_tb__core_top_inst__dmem_inst.RAM), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,2 ,31,0 ,15,0);
        __Vscope_hw3_tb__core_top_inst__imem_inst.varInsert(__Vfinal,"RAM", &(TOP__hw3_tb__core_top_inst__imem_inst.RAM), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,2 ,31,0 ,15,0);
    }
}
