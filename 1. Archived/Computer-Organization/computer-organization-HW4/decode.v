module decode #(
    parameter DWIDTH = 32
)(
    input [DWIDTH-1:0]      instr,

    output reg [3 : 0]      op,
    output reg              ssel,
    output reg [1 : 0]      wbsel,
    output reg              we_regfile,
    output reg              we_dmem,
    output reg [2 : 0]      jump_type,
    output reg [25 : 0]     jump_addr,

    output reg [DWIDTH-1:0] imm,
    output reg [4 : 0]      rs1_id,
    output reg [4 : 0]      rs2_id,
    output reg [4 : 0]      rdst_id
);

    // Opcode
    localparam [5:0] OP_R_TYPE = 6'b00_0000,
                     OP_ADDI   = 6'b00_1000,
                     OP_SLTI   = 6'b00_1010,
                     OP_LW     = 6'b10_0011,
                     OP_SW     = 6'b10_1011,
                     OP_BEQ    = 6'b00_0100,
                     OP_JAL    = 6'b00_0011,
                     OP_J      = 6'b00_0010;
    
    // Funct of R TYPE Instructions
    localparam [5:0] FUNCT_ADD = 6'b10_0000,
                     FUNCT_SUB = 6'b10_0010,
                     FUNCT_AND = 6'b10_0100,
                     FUNCT_OR  = 6'b10_0101,
                     FUNCT_NOR = 6'b10_0111,
                     FUNCT_SLT = 6'b10_1010,
                     FUNCT_JR  = 6'b00_1000;

    // ALU Opcode
    localparam [3:0] ALU_OP_AND = 4'b0000,
                     ALU_OP_OR  = 4'b0001,
                     ALU_OP_ADD = 4'b0010,
                     ALU_OP_SUB = 4'b0110,
                     ALU_OP_NOR = 4'b1100,
                     ALU_OP_SLT = 4'b0111,
                     ALU_OP_NOP = 4'b1111;

    // Jump type
    localparam [2:0] J_TYPE_NOP = 3'b000,
                     J_TYPE_BEQ = 3'b001,
                     J_TYPE_JAL = 3'b010,
                     J_TYPE_JR  = 3'b011,
                     J_TYPE_J   = 3'b100;

    wire [ 5:0] opcode;
    wire [ 4:0] rs;
    wire [ 4:0] rt;
    wire [ 4:0] rd;
    wire [ 4:0] shamt;
    wire [ 5:0] funct;
    wire [15:0] immediate;
    wire [25:0] address;

    wire        is_r_type;
    wire        is_addi;
    wire        is_slti;
    wire        is_lw;
    wire        is_sw;
    wire        is_beq;
    wire        is_jal;
    wire        is_j;

    assign opcode    = instr[31:26];
    assign rs        = instr[25:21];
    assign rt        = instr[20:16];
    assign rd        = instr[15:11];
    assign shamt     = instr[10: 6];
    assign funct     = instr[ 5: 0];
    assign immediate = instr[15: 0];
    assign address   = instr[25: 0];

    assign is_r_type = (opcode == OP_R_TYPE);
    assign is_addi   = (opcode == OP_ADDI);
    assign is_slti   = (opcode == OP_SLTI);
    assign is_lw     = (opcode == OP_LW);
    assign is_sw     = (opcode == OP_SW);
    assign is_beq    = (opcode == OP_BEQ);
    assign is_jal    = (opcode == OP_JAL);
    assign is_j      = (opcode == OP_J);
    
    // output signal 
    always @(*) begin
        if (is_r_type) begin
            case (funct)
                FUNCT_ADD: op = ALU_OP_ADD;
                FUNCT_SUB: op = ALU_OP_SUB;
                FUNCT_AND: op = ALU_OP_AND;
                FUNCT_OR:  op = ALU_OP_OR;
                FUNCT_NOR: op = ALU_OP_NOR;
                FUNCT_SLT: op = ALU_OP_SLT;
                default:   op = ALU_OP_NOP;
            endcase
        end else if (is_beq) begin
            op = ALU_OP_SUB;
        end else if (is_addi || is_lw || is_sw) begin
            op = ALU_OP_ADD;
        end else if (is_slti) begin
            op = ALU_OP_SLT;
        end else begin
            op = ALU_OP_NOP;
        end
    end

    always @(*) begin
        if (is_r_type || is_beq)
            ssel = 1; // select rs2
        else
            ssel = 0; // select imm
    end

    always @(*) begin
        if (is_lw)
            wbsel = 1; // select dmem out
        else if (is_jal)
            wbsel = 2; // select pc + 4
        else
            wbsel = 0; // select alu output
    end

    always @(*) begin
        if (is_r_type)
            we_regfile = (funct == FUNCT_JR) ? 0 : 1;
        else if (is_addi || is_slti || is_lw || is_jal)
            we_regfile = 1;
        else
            we_regfile = 0;
    end

    always @(*) begin
        we_dmem = is_sw;
    end

    always @(*) begin
        case (opcode)
            OP_R_TYPE: jump_type = (funct == FUNCT_JR) ? J_TYPE_JR : J_TYPE_NOP;
            OP_J:      jump_type = J_TYPE_J;
            OP_JAL:    jump_type = J_TYPE_JAL;
            OP_BEQ:    jump_type = J_TYPE_BEQ;
            default:   jump_type = J_TYPE_NOP;
        endcase
    end

    always @(*) begin
        jump_addr = address;
    end

    always @(*) begin
        imm = {{16{immediate[15]}}, immediate};
    end
    
    always @(*) begin
        rs1_id = rs;
    end

    always @(*) begin
        rs2_id = rt;
    end

    always @(*) begin
        if (is_r_type)
            rdst_id = rd;
        else if (is_addi || is_slti || is_lw)
            rdst_id = rt;
        else if (is_jal)
            rdst_id = 31;
        else
            rdst_id = 0;
    end

endmodule