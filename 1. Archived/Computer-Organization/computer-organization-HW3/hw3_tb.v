/*
 *    Author : Che-Yu Wu @ EISL
 *    Date   : 2022-03-30
 */

module hw3_tb (
    input         clk,
    input         rst,
    output reg    finish
);

    localparam DWIDTH = 32;

    integer i, tmp, cycle_count;

    integer cycle_for_ans = 8;
    reg [31:0] golden_reg[0:31];
    reg [31:0] golden_dmem[0:15];

    reg start;

    core_top core_top_inst (
        .clk(clk),
        .rst(rst)
    );

    initial begin
        cycle_count = 0;
        finish = 0;
        start = 1;
    end

    always @(negedge clk) begin
        if (start) begin
            $display("\033[0;38;5;111m[Pattern]\033[m");
            start <= 0;
            cycle_count <= 0;
        end else if (cycle_count == cycle_for_ans) begin
            set_ans;
            check_reg;
            check_dmem;
            finish = 1;
            $finish;
            $finish;
        end 
        else begin
            cycle_count <= cycle_count + 1;
        end
    end

    task check_reg; begin
        for (i = 0; i < 32; i = i + 1) begin
            $write("Check reg[%2d] : ", i);
            if (golden_reg[i] !== core_top_inst.reg_file_inst.R[i]) begin
                $display("Failed");
                $display("  Your reg : %10d, Golden reg : %10d", core_top_inst.reg_file_inst.R[i], golden_reg[i]);
            end
            else
                $display("Pass");
        end
    end endtask

    task check_dmem; begin
        for (i = 0; i < 16; i = i + 1) begin
            $write("Check dmem[%2d] : ", i);
            if (golden_dmem[i] !== core_top_inst.dmem_inst.RAM[i]) begin
                $display("Failed");
                $display("  Your dmem : %10d, Golden dmem : %10d", core_top_inst.dmem_inst.RAM[i], golden_dmem[i]);
            end
            else
                $display("Pass");
        end
        
    end endtask

    task set_ans; begin
        golden_reg[0] = 0;
        golden_reg[1] = 0;
        golden_reg[2] = 0;
        golden_reg[3] = 0;
        golden_reg[4] = 0;
        golden_reg[5] = 0;
        golden_reg[6] = 0;
        golden_reg[7] = 0;
        golden_reg[8] = 23;
        golden_reg[9] = 68;
        golden_reg[10] = 68;
        golden_reg[11] = 23;
        golden_reg[12] = 0;
        golden_reg[13] = 0;
        golden_reg[14] = 0;
        golden_reg[15] = 0;
        golden_reg[16] = 0;
        golden_reg[17] = 0;
        golden_reg[18] = 0;
        golden_reg[19] = 0;
        golden_reg[20] = 0;
        golden_reg[21] = 0;
        golden_reg[22] = 0;
        golden_reg[23] = 0;
        golden_reg[24] = 0;
        golden_reg[25] = 0;
        golden_reg[26] = 0;
        golden_reg[27] = 0;
        golden_reg[28] = 0;
        golden_reg[29] = 0;
        golden_reg[30] = 0;
        golden_reg[31] = 0;

        golden_dmem[0] = 0;
        golden_dmem[1] = 0;
        golden_dmem[2] = 68;
        golden_dmem[3] = 0;
        golden_dmem[4] = 0;
        golden_dmem[5] = 0;
        golden_dmem[6] = 0;
        golden_dmem[7] = 0;
        golden_dmem[8] = 0;
        golden_dmem[9] = 0;
        golden_dmem[10] = 0;
        golden_dmem[11] = 0;
        golden_dmem[12] = 0;
        golden_dmem[13] = 0;
        golden_dmem[14] = 0;
        golden_dmem[15] = 0;
    end endtask

endmodule