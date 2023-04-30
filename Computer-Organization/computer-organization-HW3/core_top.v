module core_top #(
    parameter DWIDTH = 32
)(
    input                 clk,
    input                 rst
);

    // Jump type
    localparam [2:0] J_TYPE_NOP = 3'b000,
                     J_TYPE_BEQ = 3'b001,
                     J_TYPE_JAL = 3'b010,
                     J_TYPE_JR  = 3'b011,
                     J_TYPE_J   = 3'b100;

    // Internal wire
    // input of program counter
    wire [31:0] pc_in;

    // output of imem
    wire [31:0] instr_o;
    
    // output of adder
    wire [31:0] adder_inst1_out;
    
    // output of decode
    wire [1 :0] jump_type;
    wire [31:0] jump_addr;
    wire        we_dmem;
    wire        we_regfile;
    wire [4 :0] op;
    wire [1 :0] ssel;
    wire [31:0] imm;
    wire [4 :0] rs1_id;
    wire [4 :0] rs2_id;
    wire [4 :0] rdst_id;
    wire        reg_data_sel;

    // output of decode (modified)
    wire [31:0] imm_shift_left_twice;

    // input of reg_file
    wire [31:0] rdst;

    // output of reg_file
    wire [31:0] rs1;
    wire [31:0] reg_rs2;

    // input of address mux
    wire [31:0] branch_addr;

    // input of alu
    wire [31:0] alu_rs2;

    // input of dmem
    wire [31:0] dmem_addr;

    // output of dmem
    wire [31:0] dmem_rdata;

    // Program Counter signals
    reg  [DWIDTH-1:0] pc;
    always @(posedge clk) begin
        if (rst)
            pc <= 0;
        else
            pc <= pc_in;
    end

    adder adder_inst1 (
        // input
        .in0(pc),
        .in1(4),

        // output
        .out(adder_inst1_out)
    );
    
    imem imem_inst(
        // input
        .addr(pc),

        // output
        .rdata(instr_o)
    );

    decode decode_inst (
        // input
        .instr(instr_o),

        // output  
        .jump_type(jump_type),
        .jump_addr(jump_addr),
        .we_regfile(we_regfile),
        .we_dmem(we_dmem),

        .op(op),
        .ssel(ssel),
        .imm(imm),
        .rs1_id(rs1_id),
        .rs2_id(rs2_id),
        .rdst_id(rdst_id)

        .reg_data_sel(reg_data_sel)
    );

    reg_file reg_file_inst (
        // input
        .clk(clk),
        .rst(rst),

        .rs1_id(rs1_id),
        .rs2_id(rs2_id),

        .we(we_regfile),
        .rdst_id(rdst_id),
        .rdst(rdst),

        // output 
        .rs1(rs1),     // rs
        .rs2(reg_rs2)  // rt
    );

    shift_left shift_left_inst (
        // input
        .in1(imm),
        .in2(2),

        // output
        .out(imm_shift_left_twice)
    );

    adder adder_inst2 ( // branch adder
        // input
        .in0(adder_inst1_out),
        .in1(imm_shift_left_twice),

        // output
        .out(branch_addr)
    );

    mux_4to1 mux_4to1_inst1 ( // choose jump address
        // input
        .sel(jump_type),
        .in0(rs1),             // 00: jr
        .in1(branch_addr),     // 01: beq
        .in2(jump_addr),       // 10: j and jal
        .in3(adder_inst1_out), // 11: nop

        // output
        .out(pc_in)
    );

    mux_4to1 mux_4to1_inst2 ( // choose rs2
        // input
        .sel(ssel),
        .in0(0),               // 00: zero
        .in1(reg_rs2),         // 01: from register
        .in2(adder_inst1_out), // 10: from pc
        .in3(imm),             // 11: from immediate

        // output
        .out(alu_rs2)
    );

    alu alu_inst (
        // input
        .op(op),
        .rs1(rs1),
        .rs2(alu_rs2),

        // output
        .rd(dmem_addr),
        .zero(),
        .overflow()
    );

    // Dmem
    dmem dmem_inst (
        // input
        .clk(clk),
        .addr(dmem_addr),
        .we(we_dmem),
        .wdata(reg_rs2),

        // output
        .rdata(dmem_rdata)
    );

    // choost rdst of reg_file
    mux_2to1 mux_2to1_inst (
        // input
        .sel(reg_data_sel),
        .in0(dmem_addr),
        .in1(dmem_rdata),

        // output
        .out(rdst)
    );

endmodule