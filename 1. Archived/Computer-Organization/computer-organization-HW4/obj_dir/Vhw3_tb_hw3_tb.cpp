// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vhw3_tb.h for the primary calling header

#include "Vhw3_tb_hw3_tb.h"
#include "Vhw3_tb__Syms.h"

#include "verilated_dpi.h"

//==========

VL_INLINE_OPT void Vhw3_tb_hw3_tb::_sequent__TOP__hw3_tb__1(Vhw3_tb__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vhw3_tb_hw3_tb::_sequent__TOP__hw3_tb__1\n"); );
    Vhw3_tb* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    IData/*31:0*/ __Vdly__cycle_count;
    // Body
    __Vdly__cycle_count = vlSymsp->TOP__hw3_tb.__PVT__cycle_count;
    if (VL_UNLIKELY(vlSymsp->TOP__hw3_tb.__PVT__start)) {
        VL_WRITEF("\033[0;38;5;111m[Pattern]\033[m\n");
        vlSymsp->TOP__hw3_tb.__PVT__start = 0U;
        __Vdly__cycle_count = 0U;
    } else {
        if (VL_UNLIKELY((0x40U == vlSymsp->TOP__hw3_tb.__PVT__cycle_count))) {
            vlSymsp->TOP__hw3_tb.__PVT__golden_reg[0U] = 0U;
            vlSymsp->TOP__hw3_tb.__PVT__i = 0x10U;
            vlSymsp->TOP__hw3_tb.finish = 1U;
            vlSymsp->TOP__hw3_tb.__PVT__golden_reg[1U] = 0U;
            vlSymsp->TOP__hw3_tb.__PVT__golden_reg[2U] = 0U;
            vlSymsp->TOP__hw3_tb.__PVT__golden_reg[3U] = 0U;
            vlSymsp->TOP__hw3_tb.__PVT__golden_reg[4U] = 0U;
            vlSymsp->TOP__hw3_tb.__PVT__golden_reg[5U] = 0U;
            vlSymsp->TOP__hw3_tb.__PVT__golden_reg[6U] = 0U;
            vlSymsp->TOP__hw3_tb.__PVT__golden_reg[7U] = 0U;
            vlSymsp->TOP__hw3_tb.__PVT__golden_reg[8U] = 0x17U;
            vlSymsp->TOP__hw3_tb.__PVT__golden_reg[9U] = 0x44U;
            vlSymsp->TOP__hw3_tb.__PVT__golden_reg[0xaU] = 0x44U;
            vlSymsp->TOP__hw3_tb.__PVT__golden_reg[0xbU] = 0x17U;
            vlSymsp->TOP__hw3_tb.__PVT__golden_reg[0xcU] = 0U;
            vlSymsp->TOP__hw3_tb.__PVT__golden_reg[0xdU] = 0U;
            vlSymsp->TOP__hw3_tb.__PVT__golden_reg[0xeU] = 0U;
            vlSymsp->TOP__hw3_tb.__PVT__golden_reg[0xfU] = 0U;
            vlSymsp->TOP__hw3_tb.__PVT__golden_reg[0x10U] = 0U;
            vlSymsp->TOP__hw3_tb.__PVT__golden_reg[0x11U] = 0U;
            vlSymsp->TOP__hw3_tb.__PVT__golden_reg[0x12U] = 0U;
            vlSymsp->TOP__hw3_tb.__PVT__golden_reg[0x13U] = 0U;
            vlSymsp->TOP__hw3_tb.__PVT__golden_reg[0x14U] = 0U;
            vlSymsp->TOP__hw3_tb.__PVT__golden_reg[0x15U] = 0U;
            vlSymsp->TOP__hw3_tb.__PVT__golden_reg[0x16U] = 0U;
            vlSymsp->TOP__hw3_tb.__PVT__golden_reg[0x17U] = 0U;
            vlSymsp->TOP__hw3_tb.__PVT__golden_reg[0x18U] = 0U;
            vlSymsp->TOP__hw3_tb.__PVT__golden_reg[0x19U] = 0U;
            vlSymsp->TOP__hw3_tb.__PVT__golden_reg[0x1aU] = 0U;
            vlSymsp->TOP__hw3_tb.__PVT__golden_reg[0x1bU] = 0U;
            vlSymsp->TOP__hw3_tb.__PVT__golden_reg[0x1cU] = 0U;
            vlSymsp->TOP__hw3_tb.__PVT__golden_reg[0x1dU] = 0U;
            vlSymsp->TOP__hw3_tb.__PVT__golden_reg[0x1eU] = 0U;
            vlSymsp->TOP__hw3_tb.__PVT__golden_reg[0x1fU] = 0U;
            vlSymsp->TOP__hw3_tb.__PVT__golden_dmem[0U] = 0U;
            vlSymsp->TOP__hw3_tb.__PVT__golden_dmem[1U] = 0U;
            vlSymsp->TOP__hw3_tb.__PVT__golden_dmem[2U] = 0x44U;
            vlSymsp->TOP__hw3_tb.__PVT__golden_dmem[3U] = 0U;
            vlSymsp->TOP__hw3_tb.__PVT__golden_dmem[4U] = 0U;
            vlSymsp->TOP__hw3_tb.__PVT__golden_dmem[5U] = 0U;
            vlSymsp->TOP__hw3_tb.__PVT__golden_dmem[6U] = 0U;
            vlSymsp->TOP__hw3_tb.__PVT__golden_dmem[7U] = 0U;
            vlSymsp->TOP__hw3_tb.__PVT__golden_dmem[8U] = 0U;
            vlSymsp->TOP__hw3_tb.__PVT__golden_dmem[9U] = 0U;
            vlSymsp->TOP__hw3_tb.__PVT__golden_dmem[0xaU] = 0U;
            vlSymsp->TOP__hw3_tb.__PVT__golden_dmem[0xbU] = 0U;
            vlSymsp->TOP__hw3_tb.__PVT__golden_dmem[0xcU] = 0U;
            vlSymsp->TOP__hw3_tb.__PVT__golden_dmem[0xdU] = 0U;
            vlSymsp->TOP__hw3_tb.__PVT__golden_dmem[0xeU] = 0U;
            vlSymsp->TOP__hw3_tb.__PVT__golden_dmem[0xfU] = 0U;
            VL_WRITEF("Check reg[ 0] : ");
            if (VL_UNLIKELY((vlSymsp->TOP__hw3_tb.__PVT__golden_reg
                             [0U] != vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R
                             [0U]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your reg : %10#, Golden reg : %10#\n",
                          32,vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R
                          [0U],32,vlSymsp->TOP__hw3_tb.__PVT__golden_reg
                          [0U]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check reg[ 1] : ");
            if (VL_UNLIKELY((vlSymsp->TOP__hw3_tb.__PVT__golden_reg
                             [1U] != vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R
                             [1U]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your reg : %10#, Golden reg : %10#\n",
                          32,vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R
                          [1U],32,vlSymsp->TOP__hw3_tb.__PVT__golden_reg
                          [1U]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check reg[ 2] : ");
            if (VL_UNLIKELY((vlSymsp->TOP__hw3_tb.__PVT__golden_reg
                             [2U] != vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R
                             [2U]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your reg : %10#, Golden reg : %10#\n",
                          32,vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R
                          [2U],32,vlSymsp->TOP__hw3_tb.__PVT__golden_reg
                          [2U]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check reg[ 3] : ");
            if (VL_UNLIKELY((vlSymsp->TOP__hw3_tb.__PVT__golden_reg
                             [3U] != vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R
                             [3U]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your reg : %10#, Golden reg : %10#\n",
                          32,vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R
                          [3U],32,vlSymsp->TOP__hw3_tb.__PVT__golden_reg
                          [3U]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check reg[ 4] : ");
            if (VL_UNLIKELY((vlSymsp->TOP__hw3_tb.__PVT__golden_reg
                             [4U] != vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R
                             [4U]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your reg : %10#, Golden reg : %10#\n",
                          32,vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R
                          [4U],32,vlSymsp->TOP__hw3_tb.__PVT__golden_reg
                          [4U]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check reg[ 5] : ");
            if (VL_UNLIKELY((vlSymsp->TOP__hw3_tb.__PVT__golden_reg
                             [5U] != vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R
                             [5U]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your reg : %10#, Golden reg : %10#\n",
                          32,vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R
                          [5U],32,vlSymsp->TOP__hw3_tb.__PVT__golden_reg
                          [5U]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check reg[ 6] : ");
            if (VL_UNLIKELY((vlSymsp->TOP__hw3_tb.__PVT__golden_reg
                             [6U] != vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R
                             [6U]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your reg : %10#, Golden reg : %10#\n",
                          32,vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R
                          [6U],32,vlSymsp->TOP__hw3_tb.__PVT__golden_reg
                          [6U]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check reg[ 7] : ");
            if (VL_UNLIKELY((vlSymsp->TOP__hw3_tb.__PVT__golden_reg
                             [7U] != vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R
                             [7U]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your reg : %10#, Golden reg : %10#\n",
                          32,vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R
                          [7U],32,vlSymsp->TOP__hw3_tb.__PVT__golden_reg
                          [7U]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check reg[ 8] : ");
            if (VL_UNLIKELY((vlSymsp->TOP__hw3_tb.__PVT__golden_reg
                             [8U] != vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R
                             [8U]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your reg : %10#, Golden reg : %10#\n",
                          32,vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R
                          [8U],32,vlSymsp->TOP__hw3_tb.__PVT__golden_reg
                          [8U]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check reg[ 9] : ");
            if (VL_UNLIKELY((vlSymsp->TOP__hw3_tb.__PVT__golden_reg
                             [9U] != vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R
                             [9U]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your reg : %10#, Golden reg : %10#\n",
                          32,vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R
                          [9U],32,vlSymsp->TOP__hw3_tb.__PVT__golden_reg
                          [9U]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check reg[10] : ");
            if (VL_UNLIKELY((vlSymsp->TOP__hw3_tb.__PVT__golden_reg
                             [0xaU] != vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R
                             [0xaU]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your reg : %10#, Golden reg : %10#\n",
                          32,vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R
                          [0xaU],32,vlSymsp->TOP__hw3_tb.__PVT__golden_reg
                          [0xaU]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check reg[11] : ");
            if (VL_UNLIKELY((vlSymsp->TOP__hw3_tb.__PVT__golden_reg
                             [0xbU] != vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R
                             [0xbU]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your reg : %10#, Golden reg : %10#\n",
                          32,vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R
                          [0xbU],32,vlSymsp->TOP__hw3_tb.__PVT__golden_reg
                          [0xbU]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check reg[12] : ");
            if (VL_UNLIKELY((vlSymsp->TOP__hw3_tb.__PVT__golden_reg
                             [0xcU] != vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R
                             [0xcU]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your reg : %10#, Golden reg : %10#\n",
                          32,vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R
                          [0xcU],32,vlSymsp->TOP__hw3_tb.__PVT__golden_reg
                          [0xcU]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check reg[13] : ");
            if (VL_UNLIKELY((vlSymsp->TOP__hw3_tb.__PVT__golden_reg
                             [0xdU] != vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R
                             [0xdU]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your reg : %10#, Golden reg : %10#\n",
                          32,vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R
                          [0xdU],32,vlSymsp->TOP__hw3_tb.__PVT__golden_reg
                          [0xdU]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check reg[14] : ");
            if (VL_UNLIKELY((vlSymsp->TOP__hw3_tb.__PVT__golden_reg
                             [0xeU] != vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R
                             [0xeU]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your reg : %10#, Golden reg : %10#\n",
                          32,vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R
                          [0xeU],32,vlSymsp->TOP__hw3_tb.__PVT__golden_reg
                          [0xeU]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check reg[15] : ");
            if (VL_UNLIKELY((vlSymsp->TOP__hw3_tb.__PVT__golden_reg
                             [0xfU] != vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R
                             [0xfU]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your reg : %10#, Golden reg : %10#\n",
                          32,vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R
                          [0xfU],32,vlSymsp->TOP__hw3_tb.__PVT__golden_reg
                          [0xfU]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check reg[16] : ");
            if (VL_UNLIKELY((vlSymsp->TOP__hw3_tb.__PVT__golden_reg
                             [0x10U] != vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R
                             [0x10U]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your reg : %10#, Golden reg : %10#\n",
                          32,vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R
                          [0x10U],32,vlSymsp->TOP__hw3_tb.__PVT__golden_reg
                          [0x10U]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check reg[17] : ");
            if (VL_UNLIKELY((vlSymsp->TOP__hw3_tb.__PVT__golden_reg
                             [0x11U] != vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R
                             [0x11U]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your reg : %10#, Golden reg : %10#\n",
                          32,vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R
                          [0x11U],32,vlSymsp->TOP__hw3_tb.__PVT__golden_reg
                          [0x11U]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check reg[18] : ");
            if (VL_UNLIKELY((vlSymsp->TOP__hw3_tb.__PVT__golden_reg
                             [0x12U] != vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R
                             [0x12U]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your reg : %10#, Golden reg : %10#\n",
                          32,vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R
                          [0x12U],32,vlSymsp->TOP__hw3_tb.__PVT__golden_reg
                          [0x12U]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check reg[19] : ");
            if (VL_UNLIKELY((vlSymsp->TOP__hw3_tb.__PVT__golden_reg
                             [0x13U] != vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R
                             [0x13U]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your reg : %10#, Golden reg : %10#\n",
                          32,vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R
                          [0x13U],32,vlSymsp->TOP__hw3_tb.__PVT__golden_reg
                          [0x13U]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check reg[20] : ");
            if (VL_UNLIKELY((vlSymsp->TOP__hw3_tb.__PVT__golden_reg
                             [0x14U] != vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R
                             [0x14U]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your reg : %10#, Golden reg : %10#\n",
                          32,vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R
                          [0x14U],32,vlSymsp->TOP__hw3_tb.__PVT__golden_reg
                          [0x14U]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check reg[21] : ");
            if (VL_UNLIKELY((vlSymsp->TOP__hw3_tb.__PVT__golden_reg
                             [0x15U] != vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R
                             [0x15U]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your reg : %10#, Golden reg : %10#\n",
                          32,vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R
                          [0x15U],32,vlSymsp->TOP__hw3_tb.__PVT__golden_reg
                          [0x15U]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check reg[22] : ");
            if (VL_UNLIKELY((vlSymsp->TOP__hw3_tb.__PVT__golden_reg
                             [0x16U] != vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R
                             [0x16U]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your reg : %10#, Golden reg : %10#\n",
                          32,vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R
                          [0x16U],32,vlSymsp->TOP__hw3_tb.__PVT__golden_reg
                          [0x16U]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check reg[23] : ");
            if (VL_UNLIKELY((vlSymsp->TOP__hw3_tb.__PVT__golden_reg
                             [0x17U] != vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R
                             [0x17U]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your reg : %10#, Golden reg : %10#\n",
                          32,vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R
                          [0x17U],32,vlSymsp->TOP__hw3_tb.__PVT__golden_reg
                          [0x17U]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check reg[24] : ");
            if (VL_UNLIKELY((vlSymsp->TOP__hw3_tb.__PVT__golden_reg
                             [0x18U] != vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R
                             [0x18U]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your reg : %10#, Golden reg : %10#\n",
                          32,vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R
                          [0x18U],32,vlSymsp->TOP__hw3_tb.__PVT__golden_reg
                          [0x18U]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check reg[25] : ");
            if (VL_UNLIKELY((vlSymsp->TOP__hw3_tb.__PVT__golden_reg
                             [0x19U] != vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R
                             [0x19U]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your reg : %10#, Golden reg : %10#\n",
                          32,vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R
                          [0x19U],32,vlSymsp->TOP__hw3_tb.__PVT__golden_reg
                          [0x19U]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check reg[26] : ");
            if (VL_UNLIKELY((vlSymsp->TOP__hw3_tb.__PVT__golden_reg
                             [0x1aU] != vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R
                             [0x1aU]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your reg : %10#, Golden reg : %10#\n",
                          32,vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R
                          [0x1aU],32,vlSymsp->TOP__hw3_tb.__PVT__golden_reg
                          [0x1aU]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check reg[27] : ");
            if (VL_UNLIKELY((vlSymsp->TOP__hw3_tb.__PVT__golden_reg
                             [0x1bU] != vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R
                             [0x1bU]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your reg : %10#, Golden reg : %10#\n",
                          32,vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R
                          [0x1bU],32,vlSymsp->TOP__hw3_tb.__PVT__golden_reg
                          [0x1bU]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check reg[28] : ");
            if (VL_UNLIKELY((vlSymsp->TOP__hw3_tb.__PVT__golden_reg
                             [0x1cU] != vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R
                             [0x1cU]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your reg : %10#, Golden reg : %10#\n",
                          32,vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R
                          [0x1cU],32,vlSymsp->TOP__hw3_tb.__PVT__golden_reg
                          [0x1cU]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check reg[29] : ");
            if (VL_UNLIKELY((vlSymsp->TOP__hw3_tb.__PVT__golden_reg
                             [0x1dU] != vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R
                             [0x1dU]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your reg : %10#, Golden reg : %10#\n",
                          32,vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R
                          [0x1dU],32,vlSymsp->TOP__hw3_tb.__PVT__golden_reg
                          [0x1dU]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check reg[30] : ");
            if (VL_UNLIKELY((vlSymsp->TOP__hw3_tb.__PVT__golden_reg
                             [0x1eU] != vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R
                             [0x1eU]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your reg : %10#, Golden reg : %10#\n",
                          32,vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R
                          [0x1eU],32,vlSymsp->TOP__hw3_tb.__PVT__golden_reg
                          [0x1eU]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check reg[31] : ");
            if (VL_UNLIKELY((vlSymsp->TOP__hw3_tb.__PVT__golden_reg
                             [0x1fU] != vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R
                             [0x1fU]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your reg : %10#, Golden reg : %10#\n",
                          32,vlSymsp->TOP__hw3_tb__core_top_inst.__PVT__reg_file_inst__DOT__R
                          [0x1fU],32,vlSymsp->TOP__hw3_tb.__PVT__golden_reg
                          [0x1fU]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check dmem[ 0] : ");
            if (VL_UNLIKELY((vlSymsp->TOP__hw3_tb.__PVT__golden_dmem
                             [0U] != vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM
                             [0U]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your dmem : %10#, Golden dmem : %10#\n",
                          32,vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM
                          [0U],32,vlSymsp->TOP__hw3_tb.__PVT__golden_dmem
                          [0U]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check dmem[ 1] : ");
            if (VL_UNLIKELY((vlSymsp->TOP__hw3_tb.__PVT__golden_dmem
                             [1U] != vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM
                             [1U]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your dmem : %10#, Golden dmem : %10#\n",
                          32,vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM
                          [1U],32,vlSymsp->TOP__hw3_tb.__PVT__golden_dmem
                          [1U]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check dmem[ 2] : ");
            if (VL_UNLIKELY((vlSymsp->TOP__hw3_tb.__PVT__golden_dmem
                             [2U] != vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM
                             [2U]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your dmem : %10#, Golden dmem : %10#\n",
                          32,vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM
                          [2U],32,vlSymsp->TOP__hw3_tb.__PVT__golden_dmem
                          [2U]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check dmem[ 3] : ");
            if (VL_UNLIKELY((vlSymsp->TOP__hw3_tb.__PVT__golden_dmem
                             [3U] != vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM
                             [3U]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your dmem : %10#, Golden dmem : %10#\n",
                          32,vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM
                          [3U],32,vlSymsp->TOP__hw3_tb.__PVT__golden_dmem
                          [3U]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check dmem[ 4] : ");
            if (VL_UNLIKELY((vlSymsp->TOP__hw3_tb.__PVT__golden_dmem
                             [4U] != vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM
                             [4U]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your dmem : %10#, Golden dmem : %10#\n",
                          32,vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM
                          [4U],32,vlSymsp->TOP__hw3_tb.__PVT__golden_dmem
                          [4U]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check dmem[ 5] : ");
            if (VL_UNLIKELY((vlSymsp->TOP__hw3_tb.__PVT__golden_dmem
                             [5U] != vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM
                             [5U]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your dmem : %10#, Golden dmem : %10#\n",
                          32,vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM
                          [5U],32,vlSymsp->TOP__hw3_tb.__PVT__golden_dmem
                          [5U]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check dmem[ 6] : ");
            if (VL_UNLIKELY((vlSymsp->TOP__hw3_tb.__PVT__golden_dmem
                             [6U] != vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM
                             [6U]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your dmem : %10#, Golden dmem : %10#\n",
                          32,vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM
                          [6U],32,vlSymsp->TOP__hw3_tb.__PVT__golden_dmem
                          [6U]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check dmem[ 7] : ");
            if (VL_UNLIKELY((vlSymsp->TOP__hw3_tb.__PVT__golden_dmem
                             [7U] != vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM
                             [7U]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your dmem : %10#, Golden dmem : %10#\n",
                          32,vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM
                          [7U],32,vlSymsp->TOP__hw3_tb.__PVT__golden_dmem
                          [7U]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check dmem[ 8] : ");
            if (VL_UNLIKELY((vlSymsp->TOP__hw3_tb.__PVT__golden_dmem
                             [8U] != vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM
                             [8U]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your dmem : %10#, Golden dmem : %10#\n",
                          32,vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM
                          [8U],32,vlSymsp->TOP__hw3_tb.__PVT__golden_dmem
                          [8U]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check dmem[ 9] : ");
            if (VL_UNLIKELY((vlSymsp->TOP__hw3_tb.__PVT__golden_dmem
                             [9U] != vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM
                             [9U]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your dmem : %10#, Golden dmem : %10#\n",
                          32,vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM
                          [9U],32,vlSymsp->TOP__hw3_tb.__PVT__golden_dmem
                          [9U]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check dmem[10] : ");
            if (VL_UNLIKELY((vlSymsp->TOP__hw3_tb.__PVT__golden_dmem
                             [0xaU] != vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM
                             [0xaU]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your dmem : %10#, Golden dmem : %10#\n",
                          32,vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM
                          [0xaU],32,vlSymsp->TOP__hw3_tb.__PVT__golden_dmem
                          [0xaU]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check dmem[11] : ");
            if (VL_UNLIKELY((vlSymsp->TOP__hw3_tb.__PVT__golden_dmem
                             [0xbU] != vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM
                             [0xbU]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your dmem : %10#, Golden dmem : %10#\n",
                          32,vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM
                          [0xbU],32,vlSymsp->TOP__hw3_tb.__PVT__golden_dmem
                          [0xbU]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check dmem[12] : ");
            if (VL_UNLIKELY((vlSymsp->TOP__hw3_tb.__PVT__golden_dmem
                             [0xcU] != vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM
                             [0xcU]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your dmem : %10#, Golden dmem : %10#\n",
                          32,vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM
                          [0xcU],32,vlSymsp->TOP__hw3_tb.__PVT__golden_dmem
                          [0xcU]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check dmem[13] : ");
            if (VL_UNLIKELY((vlSymsp->TOP__hw3_tb.__PVT__golden_dmem
                             [0xdU] != vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM
                             [0xdU]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your dmem : %10#, Golden dmem : %10#\n",
                          32,vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM
                          [0xdU],32,vlSymsp->TOP__hw3_tb.__PVT__golden_dmem
                          [0xdU]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check dmem[14] : ");
            if (VL_UNLIKELY((vlSymsp->TOP__hw3_tb.__PVT__golden_dmem
                             [0xeU] != vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM
                             [0xeU]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your dmem : %10#, Golden dmem : %10#\n",
                          32,vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM
                          [0xeU],32,vlSymsp->TOP__hw3_tb.__PVT__golden_dmem
                          [0xeU]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_WRITEF("Check dmem[15] : ");
            if (VL_UNLIKELY((vlSymsp->TOP__hw3_tb.__PVT__golden_dmem
                             [0xfU] != vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM
                             [0xfU]))) {
                VL_WRITEF("Failed\n");
                VL_WRITEF("  Your dmem : %10#, Golden dmem : %10#\n",
                          32,vlSymsp->TOP__hw3_tb__core_top_inst__dmem_inst.RAM
                          [0xfU],32,vlSymsp->TOP__hw3_tb.__PVT__golden_dmem
                          [0xfU]);
            } else {
                VL_WRITEF("Pass\n");
            }
            VL_FINISH_MT("hw3_tb.v", 43, "");
            VL_FINISH_MT("hw3_tb.v", 44, "");
        } else {
            __Vdly__cycle_count = ((IData)(1U) + vlSymsp->TOP__hw3_tb.__PVT__cycle_count);
        }
    }
    vlSymsp->TOP__hw3_tb.__PVT__cycle_count = __Vdly__cycle_count;
}
