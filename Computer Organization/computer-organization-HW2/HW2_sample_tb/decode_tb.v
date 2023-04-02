/*
 *    Author : Che-Yu Wu @ EISL
 *    Date   : 2022-03-30
 */

`timescale 1ns/1ps

module decode_tb (
    input         clk,
    input         rst,
    output reg    finish
);

    localparam DWIDTH = 32;

    reg [DWIDTH-1:0]  instr;
    wire [3:0]        op;
    wire              ssel;
    wire [DWIDTH-1:0] imm;
    wire [4:0]        rs1_id;
    wire [4:0]        rs2_id;
    wire [4:0]        rdst_id;

    wire              we;
    wire [DWIDTH-1:0] rs2_reg_file_out;

    wire [DWIDTH-1:0] rd;
    wire [DWIDTH-1:0] rs1;
    wire [DWIDTH-1:0] rs2;
    wire              zero;
    wire              overflow;


    decode decode_inst (
        // input
        .instr(instr),

        // output  
        .op(op),
        .ssel(ssel),
        .imm(imm),
        .rs1_id(rs1_id),
        .rs2_id(rs2_id),
        .rdst_id(rdst_id)
    );
    reg_file reg_file_inst (
        // input
        .clk(clk),
        .rst(rst),

        .rs1_id(rs1_id),
        .rs2_id(rs2_id),

        .we(we),
        .rdst_id(rdst_id),
        .rdst(rd),

        // output 
        .rs1(rs1),
        .rs2(rs2_reg_file_out)
    );

    alu alu_inst (
        // input
        .op(op),
        .rs1(rs1),
        .rs2(rs2),

        // output
        .rd(rd),
        .zero(zero),
        .overflow(overflow)
    );
    
    assign we = 1;
    assign rs2 = (ssel)? rs2_reg_file_out: imm;


    reg [3:0] golden_op;
    reg golden_ssel;
    reg [DWIDTH-1:0] golden_imm;
    reg [4:0] golden_rs1_id;
    reg [4:0] golden_rs2_id;
    reg [4:0] golden_rdst_id;

    wire rt_dont_care = !golden_ssel;
    wire imm_dont_care = golden_ssel;

    reg [DWIDTH-1:0] golden_R[0:31];
    integer golden_reg;
    integer i, pat_num, pattern, tmp, reg_pattern;

    initial begin

        $display("HIHI I'm testbench of HW2 ^u^ <3");
        pat_num = 0;
        pattern = $fopen("input.txt", "r");
        reg_pattern = $fopen("reg_file.txt", "r");

        finish = 0;
    end

    // Feed input signals to design @ positive edge of clock
    always @(posedge clk) begin

        if ($feof(pattern)) begin
            finish <= 1;
        end else if (!rst) begin
            tmp = $fscanf(pattern, "%d %d %d %d %d %d %d\n", instr, golden_op, golden_ssel, golden_imm, golden_rs1_id, golden_rs2_id,
                          golden_rdst_id);
        end

    end

    always @(negedge clk) begin

        if (!rst) begin
            if ((op !== golden_op) || (ssel !== golden_ssel) || (imm !== golden_imm && !imm_dont_care) || (rs1_id !== golden_rs1_id) ||
                (rs2_id !== golden_rs2_id && !rt_dont_care) || (rdst_id !== golden_rdst_id)) begin
                $display("Fail Pattern %d", pat_num);
                $display("Your op      : %10d,  Golden op      : %10d", op, golden_op);
                $display("Your ssel    : %10d,  Golden ssel    : %10d", ssel, golden_ssel);
                $display("Your imm     : %10d,  Golden imm     : %10d", $signed(imm), $signed(golden_imm));
                $display("Your rs1_id  : %10d,  Golden rs1_id  : %10d", rs1_id, golden_rs1_id);
                $display("Your rs2_id  : %10d,  Golden rs2_id  : %10d", rs2_id, golden_rs2_id);
                $display("Your rdst_id : %10d,  Golden rdst_id : %10d", rdst_id, golden_rdst_id);
                $finish;
                $finish;
            end
            else begin
                $display("Pass Pattern %d", pat_num);
            end
            pat_num = pat_num + 1;
        end
    end

    always @(negedge clk) begin
        if (finish) begin
            //print_reg;
            check_reg;
        end
    end

    task print_reg; begin
        integer idx;
        for (idx = 0; idx < 32; idx = idx + 1) begin
            // $display("R[%2d] = %d", idx, $signed(reg_file_inst.R[idx]));
        end
    end endtask

    task check_reg; begin
        for (i = 0; i < 32; i = i + 1) begin
            tmp = $fscanf(reg_pattern, "%d", golden_reg);
            golden_R[i] = golden_reg;
            $write("Check reg[%2d] : ", i);
            if (golden_R[i] !== reg_file_inst.R[i]) begin
                $display("Failed");
                $display("Your reg : %10d, Golden reg : %10d", $signed(reg_file_inst.R[i]), $signed(golden_R[i]));
            end
            else
                $display("Pass");
        end
        
    end endtask
endmodule