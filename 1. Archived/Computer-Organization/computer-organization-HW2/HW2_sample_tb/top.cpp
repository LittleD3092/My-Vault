#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vdecode_tb.h"

#define TRACE
vluint64_t sim_time = 0;

int main() {
    Verilated::traceEverOn(true);
    VerilatedVcdC *m_trace = new VerilatedVcdC;
    Vdecode_tb *dut = new Vdecode_tb;        // our DUT(Design Under Test)

#ifdef TRACE
    dut->trace(m_trace, 5);
    m_trace->open("waveform.vcd"); // open a waveform file to be write
#endif

    int reset_counter = 5;
    dut->clk = 1;
    dut->rst = 0;

    while (1) {
        dut->clk ^= 1;             // tick the clock
        if (reset_counter > 0) {
            reset_counter--;
            dut->rst = 1;
        }
        else
            dut->rst = 0;
        
        dut->eval();               // do evaluation

#ifdef TRACE
        m_trace->dump(sim_time);   // dump simulation result into vcd file.
#endif
        sim_time++;
        if(dut->finish) {
            dut->clk ^= 1;
            dut->eval();
#ifdef TRACE
        m_trace->dump(sim_time);
#endif
            break;
        }
    }


#ifdef TRACE
    m_trace->close();              // flush and close the file
#endif

    delete dut;
    exit(EXIT_SUCCESS);
}