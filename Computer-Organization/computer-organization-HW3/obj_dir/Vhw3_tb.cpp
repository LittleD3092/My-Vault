// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vhw3_tb.h for the primary calling header

#include "Vhw3_tb.h"
#include "Vhw3_tb__Syms.h"

//==========

void Vhw3_tb::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vhw3_tb::eval\n"); );
    Vhw3_tb__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vhw3_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("hw3_tb.v", 6, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vhw3_tb::_eval_initial_loop(Vhw3_tb__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("hw3_tb.v", 6, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vhw3_tb::_sequent__TOP__3(Vhw3_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhw3_tb::_sequent__TOP__3\n"); );
    Vhw3_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__unnamedblk1__DOT__i = 0x20U;
    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[0U] = 0U;
    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[1U] = 0U;
    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[2U] = 0U;
    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[3U] = 0U;
    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[4U] = 0U;
    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[5U] = 0U;
    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[6U] = 0U;
    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[7U] = 0U;
    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[8U] = 0U;
    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[9U] = 0U;
    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[0xaU] = 0U;
    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[0xbU] = 0U;
    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[0xcU] = 0U;
    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[0xdU] = 0U;
    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[0xeU] = 0U;
    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[0xfU] = 0U;
    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[0x10U] = 0U;
    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[0x11U] = 0U;
    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[0x12U] = 0U;
    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[0x13U] = 0U;
    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[0x14U] = 0U;
    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[0x15U] = 0U;
    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[0x16U] = 0U;
    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[0x17U] = 0U;
    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[0x18U] = 0U;
    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[0x19U] = 0U;
    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[0x1aU] = 0U;
    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[0x1bU] = 0U;
    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[0x1cU] = 0U;
    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[0x1dU] = 0U;
    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[0x1eU] = 0U;
    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[0x1fU] = 0U;
}

VL_INLINE_OPT void Vhw3_tb::_sequent__TOP__4(Vhw3_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhw3_tb::_sequent__TOP__4\n"); );
    Vhw3_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__we) {
        vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R[vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__rdst_id] 
            = vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__rdst;
    }
    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__rs1 
        = vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R
        [vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__rs1_id];
    vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__rs2 
        = vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R
        [vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__rs2_id];
}

VL_INLINE_OPT void Vhw3_tb::_sequent__TOP__5(Vhw3_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhw3_tb::_sequent__TOP__5\n"); );
    Vhw3_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vdlyvset__hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM__v0 = 0U;
    if (vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__we) {
        vlTOPp->__Vdlyvval__hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM__v0 
            = vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__wdata;
        vlTOPp->__Vdlyvset__hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM__v0 = 1U;
        vlTOPp->__Vdlyvdim0__hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM__v0 
            = (0xfU & ((IData)(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__addr) 
                       >> 2U));
    }
}

VL_INLINE_OPT void Vhw3_tb::_sequent__TOP__6(Vhw3_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhw3_tb::_sequent__TOP__6\n"); );
    Vhw3_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->rst) {
        vlTOPp->hw3_tb__DOT__core_top_inst__DOT__pc = 0U;
    }
}

VL_INLINE_OPT void Vhw3_tb::_sequent__TOP__7(Vhw3_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhw3_tb::_sequent__TOP__7\n"); );
    Vhw3_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    IData/*31:0*/ __Vdly__hw3_tb__DOT__cycle_count;
    // Body
    __Vdly__hw3_tb__DOT__cycle_count = vlTOPp->hw3_tb__DOT__cycle_count;
    if (VL_UNLIKELY(vlTOPp->hw3_tb__DOT__start)) {
        VL_WRITEF("\033[0;38;5;111m[Pattern]\033[m\n");
        vlTOPp->hw3_tb__DOT__start = 0U;
        __Vdly__hw3_tb__DOT__cycle_count = 0U;
    } else {
        if (VL_UNLIKELY((8U == vlTOPp->hw3_tb__DOT__cycle_count))) {
            vlTOPp->hw3_tb__DOT__golden_reg[0U] = 0U;
            vlTOPp->hw3_tb__DOT__i = 0x10U;
            vlTOPp->finish = 1U;
            vlTOPp->hw3_tb__DOT__golden_reg[1U] = 0U;
            vlTOPp->hw3_tb__DOT__golden_reg[2U] = 0U;
            vlTOPp->hw3_tb__DOT__golden_reg[3U] = 0U;
            vlTOPp->hw3_tb__DOT__golden_reg[4U] = 0U;
            vlTOPp->hw3_tb__DOT__golden_reg[5U] = 0U;
            vlTOPp->hw3_tb__DOT__golden_reg[6U] = 0U;
            vlTOPp->hw3_tb__DOT__golden_reg[7U] = 0U;
            vlTOPp->hw3_tb__DOT__golden_reg[8U] = 0x17U;
            vlTOPp->hw3_tb__DOT__golden_reg[9U] = 0x44U;
            vlTOPp->hw3_tb__DOT__golden_reg[0xaU] = 0x44U;
            vlTOPp->hw3_tb__DOT__golden_reg[0xbU] = 0x17U;
            vlTOPp->hw3_tb__DOT__golden_reg[0xcU] = 0U;
            vlTOPp->hw3_tb__DOT__golden_reg[0xdU] = 0U;
            vlTOPp->hw3_tb__DOT__golden_reg[0xeU] = 0U;
            vlTOPp->hw3_tb__DOT__golden_reg[0xfU] = 0U;
            vlTOPp->hw3_tb__DOT__golden_reg[0x10U] = 0U;
            vlTOPp->hw3_tb__DOT__golden_reg[0x11U] = 0U;
            vlTOPp->hw3_tb__DOT__golden_reg[0x12U] = 0U;
            vlTOPp->hw3_tb__DOT__golden_reg[0x13U] = 0U;
            vlTOPp->hw3_tb__DOT__golden_reg[0x14U] = 0U;
            vlTOPp->hw3_tb__DOT__golden_reg[0x15U] = 0U;
            vlTOPp->hw3_tb__DOT__golden_reg[0x16U] = 0U;
            vlTOPp->hw3_tb__DOT__golden_reg[0x17U] = 0U;
            vlTOPp->hw3_tb__DOT__golden_reg[0x18U] = 0U;
            vlTOPp->hw3_tb__DOT__golden_reg[0x19U] = 0U;
            vlTOPp->hw3_tb__DOT__golden_reg[0x1aU] = 0U;
            vlTOPp->hw3_tb__DOT__golden_reg[0x1bU] = 0U;
            vlTOPp->hw3_tb__DOT__golden_reg[0x1cU] = 0U;
            vlTOPp->hw3_tb__DOT__golden_reg[0x1dU] = 0U;
            vlTOPp->hw3_tb__DOT__golden_reg[0x1eU] = 0U;
            vlTOPp->hw3_tb__DOT__golden_reg[0x1fU] = 0U;
            vlTOPp->hw3_tb__DOT__golden_dmem[0U] = 0U;
            vlTOPp->hw3_tb__DOT__golden_dmem[1U] = 0U;
            vlTOPp->hw3_tb__DOT__golden_dmem[2U] = 0x44U;
            vlTOPp->hw3_tb__DOT__golden_dmem[3U] = 0U;
            vlTOPp->hw3_tb__DOT__golden_dmem[4U] = 0U;
            vlTOPp->hw3_tb__DOT__golden_dmem[5U] = 0U;
            vlTOPp->hw3_tb__DOT__golden_dmem[6U] = 0U;
            vlTOPp->hw3_tb__DOT__golden_dmem[7U] = 0U;
            vlTOPp->hw3_tb__DOT__golden_dmem[8U] = 0U;
            vlTOPp->hw3_tb__DOT__golden_dmem[9U] = 0U;
            vlTOPp->hw3_tb__DOT__golden_dmem[0xaU] = 0U;
            vlTOPp->hw3_tb__DOT__golden_dmem[0xbU] = 0U;
            vlTOPp->hw3_tb__DOT__golden_dmem[0xcU] = 0U;
            vlTOPp->hw3_tb__DOT__golden_dmem[0xdU] = 0U;
            vlTOPp->hw3_tb__DOT__golden_dmem[0xeU] = 0U;
            vlTOPp->hw3_tb__DOT__golden_dmem[0xfU] = 0U;
            VL_WRITEF("Check reg[ 0] : ");
            if (VL_UNLIKELY((vlTOPp->hw3_tb__DOT__golden_reg
                             [0U] != vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R
                             [0U]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your reg : %10#, Golden reg : %10#\n",
                          32,vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R
                          [0U],32,vlTOPp->hw3_tb__DOT__golden_reg
                          [0U]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check reg[ 1] : ");
            if (VL_UNLIKELY((vlTOPp->hw3_tb__DOT__golden_reg
                             [1U] != vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R
                             [1U]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your reg : %10#, Golden reg : %10#\n",
                          32,vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R
                          [1U],32,vlTOPp->hw3_tb__DOT__golden_reg
                          [1U]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check reg[ 2] : ");
            if (VL_UNLIKELY((vlTOPp->hw3_tb__DOT__golden_reg
                             [2U] != vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R
                             [2U]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your reg : %10#, Golden reg : %10#\n",
                          32,vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R
                          [2U],32,vlTOPp->hw3_tb__DOT__golden_reg
                          [2U]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check reg[ 3] : ");
            if (VL_UNLIKELY((vlTOPp->hw3_tb__DOT__golden_reg
                             [3U] != vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R
                             [3U]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your reg : %10#, Golden reg : %10#\n",
                          32,vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R
                          [3U],32,vlTOPp->hw3_tb__DOT__golden_reg
                          [3U]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check reg[ 4] : ");
            if (VL_UNLIKELY((vlTOPp->hw3_tb__DOT__golden_reg
                             [4U] != vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R
                             [4U]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your reg : %10#, Golden reg : %10#\n",
                          32,vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R
                          [4U],32,vlTOPp->hw3_tb__DOT__golden_reg
                          [4U]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check reg[ 5] : ");
            if (VL_UNLIKELY((vlTOPp->hw3_tb__DOT__golden_reg
                             [5U] != vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R
                             [5U]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your reg : %10#, Golden reg : %10#\n",
                          32,vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R
                          [5U],32,vlTOPp->hw3_tb__DOT__golden_reg
                          [5U]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check reg[ 6] : ");
            if (VL_UNLIKELY((vlTOPp->hw3_tb__DOT__golden_reg
                             [6U] != vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R
                             [6U]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your reg : %10#, Golden reg : %10#\n",
                          32,vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R
                          [6U],32,vlTOPp->hw3_tb__DOT__golden_reg
                          [6U]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check reg[ 7] : ");
            if (VL_UNLIKELY((vlTOPp->hw3_tb__DOT__golden_reg
                             [7U] != vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R
                             [7U]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your reg : %10#, Golden reg : %10#\n",
                          32,vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R
                          [7U],32,vlTOPp->hw3_tb__DOT__golden_reg
                          [7U]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check reg[ 8] : ");
            if (VL_UNLIKELY((vlTOPp->hw3_tb__DOT__golden_reg
                             [8U] != vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R
                             [8U]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your reg : %10#, Golden reg : %10#\n",
                          32,vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R
                          [8U],32,vlTOPp->hw3_tb__DOT__golden_reg
                          [8U]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check reg[ 9] : ");
            if (VL_UNLIKELY((vlTOPp->hw3_tb__DOT__golden_reg
                             [9U] != vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R
                             [9U]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your reg : %10#, Golden reg : %10#\n",
                          32,vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R
                          [9U],32,vlTOPp->hw3_tb__DOT__golden_reg
                          [9U]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check reg[10] : ");
            if (VL_UNLIKELY((vlTOPp->hw3_tb__DOT__golden_reg
                             [0xaU] != vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R
                             [0xaU]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your reg : %10#, Golden reg : %10#\n",
                          32,vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R
                          [0xaU],32,vlTOPp->hw3_tb__DOT__golden_reg
                          [0xaU]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check reg[11] : ");
            if (VL_UNLIKELY((vlTOPp->hw3_tb__DOT__golden_reg
                             [0xbU] != vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R
                             [0xbU]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your reg : %10#, Golden reg : %10#\n",
                          32,vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R
                          [0xbU],32,vlTOPp->hw3_tb__DOT__golden_reg
                          [0xbU]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check reg[12] : ");
            if (VL_UNLIKELY((vlTOPp->hw3_tb__DOT__golden_reg
                             [0xcU] != vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R
                             [0xcU]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your reg : %10#, Golden reg : %10#\n",
                          32,vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R
                          [0xcU],32,vlTOPp->hw3_tb__DOT__golden_reg
                          [0xcU]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check reg[13] : ");
            if (VL_UNLIKELY((vlTOPp->hw3_tb__DOT__golden_reg
                             [0xdU] != vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R
                             [0xdU]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your reg : %10#, Golden reg : %10#\n",
                          32,vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R
                          [0xdU],32,vlTOPp->hw3_tb__DOT__golden_reg
                          [0xdU]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check reg[14] : ");
            if (VL_UNLIKELY((vlTOPp->hw3_tb__DOT__golden_reg
                             [0xeU] != vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R
                             [0xeU]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your reg : %10#, Golden reg : %10#\n",
                          32,vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R
                          [0xeU],32,vlTOPp->hw3_tb__DOT__golden_reg
                          [0xeU]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check reg[15] : ");
            if (VL_UNLIKELY((vlTOPp->hw3_tb__DOT__golden_reg
                             [0xfU] != vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R
                             [0xfU]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your reg : %10#, Golden reg : %10#\n",
                          32,vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R
                          [0xfU],32,vlTOPp->hw3_tb__DOT__golden_reg
                          [0xfU]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check reg[16] : ");
            if (VL_UNLIKELY((vlTOPp->hw3_tb__DOT__golden_reg
                             [0x10U] != vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R
                             [0x10U]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your reg : %10#, Golden reg : %10#\n",
                          32,vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R
                          [0x10U],32,vlTOPp->hw3_tb__DOT__golden_reg
                          [0x10U]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check reg[17] : ");
            if (VL_UNLIKELY((vlTOPp->hw3_tb__DOT__golden_reg
                             [0x11U] != vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R
                             [0x11U]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your reg : %10#, Golden reg : %10#\n",
                          32,vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R
                          [0x11U],32,vlTOPp->hw3_tb__DOT__golden_reg
                          [0x11U]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check reg[18] : ");
            if (VL_UNLIKELY((vlTOPp->hw3_tb__DOT__golden_reg
                             [0x12U] != vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R
                             [0x12U]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your reg : %10#, Golden reg : %10#\n",
                          32,vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R
                          [0x12U],32,vlTOPp->hw3_tb__DOT__golden_reg
                          [0x12U]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check reg[19] : ");
            if (VL_UNLIKELY((vlTOPp->hw3_tb__DOT__golden_reg
                             [0x13U] != vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R
                             [0x13U]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your reg : %10#, Golden reg : %10#\n",
                          32,vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R
                          [0x13U],32,vlTOPp->hw3_tb__DOT__golden_reg
                          [0x13U]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check reg[20] : ");
            if (VL_UNLIKELY((vlTOPp->hw3_tb__DOT__golden_reg
                             [0x14U] != vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R
                             [0x14U]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your reg : %10#, Golden reg : %10#\n",
                          32,vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R
                          [0x14U],32,vlTOPp->hw3_tb__DOT__golden_reg
                          [0x14U]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check reg[21] : ");
            if (VL_UNLIKELY((vlTOPp->hw3_tb__DOT__golden_reg
                             [0x15U] != vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R
                             [0x15U]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your reg : %10#, Golden reg : %10#\n",
                          32,vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R
                          [0x15U],32,vlTOPp->hw3_tb__DOT__golden_reg
                          [0x15U]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check reg[22] : ");
            if (VL_UNLIKELY((vlTOPp->hw3_tb__DOT__golden_reg
                             [0x16U] != vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R
                             [0x16U]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your reg : %10#, Golden reg : %10#\n",
                          32,vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R
                          [0x16U],32,vlTOPp->hw3_tb__DOT__golden_reg
                          [0x16U]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check reg[23] : ");
            if (VL_UNLIKELY((vlTOPp->hw3_tb__DOT__golden_reg
                             [0x17U] != vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R
                             [0x17U]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your reg : %10#, Golden reg : %10#\n",
                          32,vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R
                          [0x17U],32,vlTOPp->hw3_tb__DOT__golden_reg
                          [0x17U]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check reg[24] : ");
            if (VL_UNLIKELY((vlTOPp->hw3_tb__DOT__golden_reg
                             [0x18U] != vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R
                             [0x18U]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your reg : %10#, Golden reg : %10#\n",
                          32,vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R
                          [0x18U],32,vlTOPp->hw3_tb__DOT__golden_reg
                          [0x18U]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check reg[25] : ");
            if (VL_UNLIKELY((vlTOPp->hw3_tb__DOT__golden_reg
                             [0x19U] != vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R
                             [0x19U]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your reg : %10#, Golden reg : %10#\n",
                          32,vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R
                          [0x19U],32,vlTOPp->hw3_tb__DOT__golden_reg
                          [0x19U]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check reg[26] : ");
            if (VL_UNLIKELY((vlTOPp->hw3_tb__DOT__golden_reg
                             [0x1aU] != vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R
                             [0x1aU]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your reg : %10#, Golden reg : %10#\n",
                          32,vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R
                          [0x1aU],32,vlTOPp->hw3_tb__DOT__golden_reg
                          [0x1aU]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check reg[27] : ");
            if (VL_UNLIKELY((vlTOPp->hw3_tb__DOT__golden_reg
                             [0x1bU] != vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R
                             [0x1bU]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your reg : %10#, Golden reg : %10#\n",
                          32,vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R
                          [0x1bU],32,vlTOPp->hw3_tb__DOT__golden_reg
                          [0x1bU]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check reg[28] : ");
            if (VL_UNLIKELY((vlTOPp->hw3_tb__DOT__golden_reg
                             [0x1cU] != vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R
                             [0x1cU]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your reg : %10#, Golden reg : %10#\n",
                          32,vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R
                          [0x1cU],32,vlTOPp->hw3_tb__DOT__golden_reg
                          [0x1cU]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check reg[29] : ");
            if (VL_UNLIKELY((vlTOPp->hw3_tb__DOT__golden_reg
                             [0x1dU] != vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R
                             [0x1dU]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your reg : %10#, Golden reg : %10#\n",
                          32,vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R
                          [0x1dU],32,vlTOPp->hw3_tb__DOT__golden_reg
                          [0x1dU]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check reg[30] : ");
            if (VL_UNLIKELY((vlTOPp->hw3_tb__DOT__golden_reg
                             [0x1eU] != vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R
                             [0x1eU]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your reg : %10#, Golden reg : %10#\n",
                          32,vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R
                          [0x1eU],32,vlTOPp->hw3_tb__DOT__golden_reg
                          [0x1eU]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check reg[31] : ");
            if (VL_UNLIKELY((vlTOPp->hw3_tb__DOT__golden_reg
                             [0x1fU] != vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R
                             [0x1fU]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your reg : %10#, Golden reg : %10#\n",
                          32,vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__R
                          [0x1fU],32,vlTOPp->hw3_tb__DOT__golden_reg
                          [0x1fU]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check dmem[ 0] : ");
            if (VL_UNLIKELY((vlTOPp->hw3_tb__DOT__golden_dmem
                             [0U] != vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM
                             [0U]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your dmem : %10#, Golden dmem : %10#\n",
                          32,vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM
                          [0U],32,vlTOPp->hw3_tb__DOT__golden_dmem
                          [0U]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check dmem[ 1] : ");
            if (VL_UNLIKELY((vlTOPp->hw3_tb__DOT__golden_dmem
                             [1U] != vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM
                             [1U]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your dmem : %10#, Golden dmem : %10#\n",
                          32,vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM
                          [1U],32,vlTOPp->hw3_tb__DOT__golden_dmem
                          [1U]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check dmem[ 2] : ");
            if (VL_UNLIKELY((vlTOPp->hw3_tb__DOT__golden_dmem
                             [2U] != vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM
                             [2U]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your dmem : %10#, Golden dmem : %10#\n",
                          32,vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM
                          [2U],32,vlTOPp->hw3_tb__DOT__golden_dmem
                          [2U]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check dmem[ 3] : ");
            if (VL_UNLIKELY((vlTOPp->hw3_tb__DOT__golden_dmem
                             [3U] != vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM
                             [3U]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your dmem : %10#, Golden dmem : %10#\n",
                          32,vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM
                          [3U],32,vlTOPp->hw3_tb__DOT__golden_dmem
                          [3U]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check dmem[ 4] : ");
            if (VL_UNLIKELY((vlTOPp->hw3_tb__DOT__golden_dmem
                             [4U] != vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM
                             [4U]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your dmem : %10#, Golden dmem : %10#\n",
                          32,vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM
                          [4U],32,vlTOPp->hw3_tb__DOT__golden_dmem
                          [4U]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check dmem[ 5] : ");
            if (VL_UNLIKELY((vlTOPp->hw3_tb__DOT__golden_dmem
                             [5U] != vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM
                             [5U]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your dmem : %10#, Golden dmem : %10#\n",
                          32,vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM
                          [5U],32,vlTOPp->hw3_tb__DOT__golden_dmem
                          [5U]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check dmem[ 6] : ");
            if (VL_UNLIKELY((vlTOPp->hw3_tb__DOT__golden_dmem
                             [6U] != vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM
                             [6U]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your dmem : %10#, Golden dmem : %10#\n",
                          32,vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM
                          [6U],32,vlTOPp->hw3_tb__DOT__golden_dmem
                          [6U]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check dmem[ 7] : ");
            if (VL_UNLIKELY((vlTOPp->hw3_tb__DOT__golden_dmem
                             [7U] != vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM
                             [7U]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your dmem : %10#, Golden dmem : %10#\n",
                          32,vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM
                          [7U],32,vlTOPp->hw3_tb__DOT__golden_dmem
                          [7U]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check dmem[ 8] : ");
            if (VL_UNLIKELY((vlTOPp->hw3_tb__DOT__golden_dmem
                             [8U] != vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM
                             [8U]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your dmem : %10#, Golden dmem : %10#\n",
                          32,vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM
                          [8U],32,vlTOPp->hw3_tb__DOT__golden_dmem
                          [8U]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check dmem[ 9] : ");
            if (VL_UNLIKELY((vlTOPp->hw3_tb__DOT__golden_dmem
                             [9U] != vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM
                             [9U]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your dmem : %10#, Golden dmem : %10#\n",
                          32,vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM
                          [9U],32,vlTOPp->hw3_tb__DOT__golden_dmem
                          [9U]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check dmem[10] : ");
            if (VL_UNLIKELY((vlTOPp->hw3_tb__DOT__golden_dmem
                             [0xaU] != vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM
                             [0xaU]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your dmem : %10#, Golden dmem : %10#\n",
                          32,vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM
                          [0xaU],32,vlTOPp->hw3_tb__DOT__golden_dmem
                          [0xaU]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check dmem[11] : ");
            if (VL_UNLIKELY((vlTOPp->hw3_tb__DOT__golden_dmem
                             [0xbU] != vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM
                             [0xbU]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your dmem : %10#, Golden dmem : %10#\n",
                          32,vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM
                          [0xbU],32,vlTOPp->hw3_tb__DOT__golden_dmem
                          [0xbU]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check dmem[12] : ");
            if (VL_UNLIKELY((vlTOPp->hw3_tb__DOT__golden_dmem
                             [0xcU] != vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM
                             [0xcU]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your dmem : %10#, Golden dmem : %10#\n",
                          32,vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM
                          [0xcU],32,vlTOPp->hw3_tb__DOT__golden_dmem
                          [0xcU]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check dmem[13] : ");
            if (VL_UNLIKELY((vlTOPp->hw3_tb__DOT__golden_dmem
                             [0xdU] != vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM
                             [0xdU]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your dmem : %10#, Golden dmem : %10#\n",
                          32,vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM
                          [0xdU],32,vlTOPp->hw3_tb__DOT__golden_dmem
                          [0xdU]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check dmem[14] : ");
            if (VL_UNLIKELY((vlTOPp->hw3_tb__DOT__golden_dmem
                             [0xeU] != vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM
                             [0xeU]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your dmem : %10#, Golden dmem : %10#\n",
                          32,vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM
                          [0xeU],32,vlTOPp->hw3_tb__DOT__golden_dmem
                          [0xeU]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check dmem[15] : ");
            if (VL_UNLIKELY((vlTOPp->hw3_tb__DOT__golden_dmem
                             [0xfU] != vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM
                             [0xfU]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your dmem : %10#, Golden dmem : %10#\n",
                          32,vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM
                          [0xfU],32,vlTOPp->hw3_tb__DOT__golden_dmem
                          [0xfU]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_FINISH_MT("hw3_tb.v", 43, "");
            VL_FINISH_MT("hw3_tb.v", 44, "");
        } else {
            __Vdly__hw3_tb__DOT__cycle_count = ((IData)(1U) 
                                                + vlTOPp->hw3_tb__DOT__cycle_count);
        }
    }
    vlTOPp->hw3_tb__DOT__cycle_count = __Vdly__hw3_tb__DOT__cycle_count;
}

VL_INLINE_OPT void Vhw3_tb::_sequent__TOP__8(Vhw3_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhw3_tb::_sequent__TOP__8\n"); );
    Vhw3_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->__Vdlyvset__hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM__v0) {
        vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM[vlTOPp->__Vdlyvdim0__hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM__v0] 
            = vlTOPp->__Vdlyvval__hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__RAM__v0;
    }
}

void Vhw3_tb::_eval(Vhw3_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhw3_tb::_eval\n"); );
    Vhw3_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__rst) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__rst)))) {
        vlTOPp->_sequent__TOP__3(vlSymsp);
        vlTOPp->__Vm_traceActivity[1U] = 1U;
    }
    if (((IData)(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__clk) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__clk)))) {
        vlTOPp->_sequent__TOP__4(vlSymsp);
        vlTOPp->__Vm_traceActivity[2U] = 1U;
    }
    if (((IData)(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__clk) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__clk)))) {
        vlTOPp->_sequent__TOP__5(vlSymsp);
    }
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__6(vlSymsp);
    }
    if (((~ (IData)(vlTOPp->clk)) & (IData)(vlTOPp->__Vclklast__TOP__clk))) {
        vlTOPp->_sequent__TOP__7(vlSymsp);
        vlTOPp->__Vm_traceActivity[3U] = 1U;
    }
    if (((IData)(vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__clk) 
         & (~ (IData)(vlTOPp->__Vclklast__TOP__hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__clk)))) {
        vlTOPp->_sequent__TOP__8(vlSymsp);
        vlTOPp->__Vm_traceActivity[4U] = 1U;
    }
    // Final
    vlTOPp->__Vclklast__TOP__hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__rst 
        = vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__rst;
    vlTOPp->__Vclklast__TOP__hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__clk 
        = vlTOPp->hw3_tb__DOT__core_top_inst__DOT__reg_file_inst__DOT__clk;
    vlTOPp->__Vclklast__TOP__hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__clk 
        = vlTOPp->hw3_tb__DOT__core_top_inst__DOT__dmem_inst__DOT__clk;
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

VL_INLINE_OPT QData Vhw3_tb::_change_request(Vhw3_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhw3_tb::_change_request\n"); );
    Vhw3_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vhw3_tb::_change_request_1(Vhw3_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhw3_tb::_change_request_1\n"); );
    Vhw3_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vhw3_tb::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhw3_tb::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
}
#endif  // VL_DEBUG
