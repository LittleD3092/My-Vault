/*
 *    Author : Che-Yu Wu @ EISL
 *    Date   : 2022-03-30
 */
// 109611066 吳典謀

/*

| instructions     | instruction type | jump_type | jump_addr               | we_dmem | we_regfile | op          | ssel                | imm               | rs1_id            | rs2_id            | rdst_id           | reg_data_sel   |
| ---------------- | ---------------- | --------- | ----------------------- | ------- | ---------- | ----------- | ------------------- | ----------------- | ----------------- | ----------------- | ----------------- | -------------- |
| add  rd, rs, rt  | R                | NOP (11)  | None (0)                | No (0)  | Yes (1)    | add (0010)  | from register (01)  | Not used (0)      | rs (instr[25:21]) | rt (instr[20:16]) | rd (instr[15:11]) | alu result (0) |
| addi rt, rs, imm | I                | NOP (11)  | None (0)                | No (0)  | Yes (1)    | add (0010)  | from immediate (11) | imm (instr[15:0]) | rs (instr[25:21]) | None (0)          | rt (instr[20:16]) | alu result (0) |
| sub  rd, rs, rt  | R                | NOP (11)  | None (0)                | No (0)  | Yes (1)    | sub (0110)  | from register (01)  | Not used (0)      | rs (instr[25:21]) | rt (instr[20:16]) | rd (instr[15:11]) | alu result (0) |
| and  rd, rs, rt  | R                | NOP (11)  | None (0)                | No (0)  | Yes (1)    | and (0000)  | from register (01)  | Not used (0)      | rs (instr[25:21]) | rt (instr[20:16]) | rd (instr[15:11]) | alu result (0) |
| or   rd, rs, rt  | R                | NOP (11)  | None (0)                | No (0)  | Yes (1)    | or (0001)   | from register (01)  | Not used (0)      | rs (instr[25:21]) | rt (instr[20:16]) | rd (instr[15:11]) | alu result (0) |
| nor  rd, rs, rt  | R                | NOP (11)  | None (0)                | No (0)  | Yes (1)    | nor (1100)  | from register (01)  | Not used (0)      | rs (instr[25:21]) | rt (instr[20:16]) | rd (instr[15:11]) | alu result (0) |
| slt  rd, rs, rt  | R                | NOP (11)  | None (0)                | No (0)  | Yes (1)    | slt (0111)  | from register (01)  | Not used (0)      | rs (instr[25:21]) | rt (instr[20:16]) | rd (instr[15:11]) | alu result (0) |
| slti rt, rs, imm | I                | NOP (11)  | None (0)                | No (0)  | Yes (1)    | slt (0111)  | from immediate (11) | imm (instr[15:0]) | rs (instr[25:21]) | None (0)          | rt (instr[20:16]) | alu result (0) |
| lw   rt, imm(rs) | I                | NOP (11)  | None (0)                | No (0)  | Yes (1)    | add (0010)  | from immediate (11) | imm (instr[15:0]) | rs (instr[25:21]) | None (0)          | rt (instr[20:16]) | dmem (1)       |
| sw   rt, imm(rs) | I                | NOP (11)  | None (0)                | Yes (1) | No (0)     | add (0010)  | from immediate (11) | imm (instr[15:0]) | rs (instr[25:21]) | rt (instr[20:16]) | None (0)          | None (0)       |
| beq  rs, rt, imm | I                | beq (01)  | imm (instr[15:0])       | No (0)  | No (0)     | sub (0110)  | from register (01)  | Not used (0)      | rs (instr[25:21]) | rt (instr[20:16]) | None (0)          | None (0)       |
| jal  target_pc   | J                | j   (10)  | target_pc (instr[25:0]) | No (0)  | Yes (1)    | add (0010)  | from pc (10)        | Not used (0)      | $zero (0)         | None (0)          | $ra (31)          | alu result (0) |
| jr   rs          | R                | jr  (00)  | None (0)                | No (0)  | No (0)     | None (0000) | not used (00)       | Not used (0)      | rs (instr[25:21]) | None (0)          | None (0)          | None (0)       | 
| j    target_pc   | J                | j   (10)  | target_pc (instr[25:0]) | No (0)  | No (0)     | None (0000) | not used (00)       | Not used (0)      | None (0)          | None (0)          | None (0)          | None (0)       |

*/

module decode #(parameter DWIDTH = 32)
(
    input      [DWIDTH-1 : 0] instr,   // Input instruction.

    output reg [1        : 0] jump_type,
    output reg [31       : 0] jump_addr,
    output reg                we_dmem,
    output reg                we_regfile,

    output reg [3        : 0] op,          // Operation code for the ALU.
    output reg [1        : 0] ssel,        // Select the signal for either the immediate value or rs2.
    output reg [DWIDTH-1 : 0] imm,         // The immediate value (if used).
    output reg [4        : 0] rs1_id,      // register ID for rs.
    output reg [4        : 0] rs2_id,      // register ID for rt (if used).
    output reg [4        : 0] rdst_id,     // register ID for rd or rt (if used).

    output reg                reg_data_sel // select alu result or dmem to write to regfile
);

/***************************************************************************************
    ---------------------------------------------------------------------------------
    | R_type |    |   opcode   |   rs   |   rt   |   rd   |   shamt   |    funct    |
    ---------------------------------------------------------------------------------
    | I_type |    |   opcode   |   rs   |   rt   |             immediate            |
    ---------------------------------------------------------------------------------
    | J_type |    |   opcode   |                     address                        |
    ---------------------------------------------------------------------------------
                   31        26 25    21 20    16 15    11 10        6 5           0
 ***************************************************************************************/

    localparam [3:0] OP_AND = 4'b0000,
                     OP_OR  = 4'b0001,
                     OP_ADD = 4'b0010,
                     OP_SUB = 4'b0110,
                     OP_NOR = 4'b1100,
                     OP_SLT = 4'b0111,
                     OP_NOT_DEFINED = 4'b1111;

    always @(instr) begin
        // case handling using opcode
        case(instr[31:26])
            // R-type
            6'b000000: begin
                // handle funct
                case(instr[5:0])
                    // add
                    6'b100000: begin
                        jump_type    = 2'b11;        // NOP
                        jump_addr    = 32'b0;        // None
                        we_dmem      = 1'b0;         // No
                        we_regfile   = 1'b1;         // Yes
                        op           = OP_ADD;       // add
                        ssel         = 2'b01;        // from register
                        imm          = 32'b0;        // Not used
                        rs1_id       = instr[25:21]; // rs
                        rs2_id       = instr[20:16]; // rt
                        rdst_id      = instr[15:11]; // rd
                        reg_data_sel = 1'b0;         // alu result
                    end
                    // sub
                    6'b100010: begin
                        jump_type    = 2'b11;        // NOP
                        jump_addr    = 32'b0;        // None
                        we_dmem      = 1'b0;         // No
                        we_regfile   = 1'b1;         // Yes
                        op           = OP_SUB;       // sub
                        ssel         = 2'b01;        // from register
                        imm          = 32'b0;        // Not used
                        rs1_id       = instr[25:21]; // rs
                        rs2_id       = instr[20:16]; // rt
                        rdst_id      = instr[15:11]; // rd
                        reg_data_sel = 1'b0;         // alu result
                    end
                    // and
                    6'b100100: begin
                        jump_type    = 2'b11;        // NOP
                        jump_addr    = 32'b0;        // None
                        we_dmem      = 1'b0;         // No
                        we_regfile   = 1'b1;         // Yes
                        op           = OP_AND;       // and
                        ssel         = 2'b01;        // from register
                        imm          = 32'b0;        // Not used
                        rs1_id       = instr[25:21]; // rs
                        rs2_id       = instr[20:16]; // rt
                        rdst_id      = instr[15:11]; // rd
                        reg_data_sel = 1'b0;         // alu result
                    end
                    // or
                    6'b100101: begin
                        jump_type    = 2'b11;        // NOP
                        jump_addr    = 32'b0;        // None
                        we_dmem      = 1'b0;         // No
                        we_regfile   = 1'b1;         // Yes
                        op           = OP_OR;        // or
                        ssel         = 2'b01;        // from register
                        imm          = 32'b0;        // Not used
                        rs1_id       = instr[25:21]; // rs
                        rs2_id       = instr[20:16]; // rt
                        rdst_id      = instr[15:11]; // rd
                        reg_data_sel = 1'b0;         // alu result
                    end
                    // nor
                    6'b100111: begin
                        jump_type    = 2'b11;        // NOP
                        jump_addr    = 32'b0;        // None
                        we_dmem      = 1'b0;         // No
                        we_regfile   = 1'b1;         // Yes
                        op           = OP_NOR;       // nor
                        ssel         = 2'b01;        // from register
                        imm          = 32'b0;        // Not used
                        rs1_id       = instr[25:21]; // rs
                        rs2_id       = instr[20:16]; // rt
                        rdst_id      = instr[15:11]; // rd
                        reg_data_sel = 1'b0;         // alu result
                    end
                    // slt
                    6'b101010: begin
                        jump_type    = 2'b11;        // NOP
                        jump_addr    = 32'b0;        // None
                        we_dmem      = 1'b0;         // No
                        we_regfile   = 1'b1;         // Yes
                        op           = OP_SLT;       // slt
                        ssel         = 2'b01;        // from register
                        imm          = 32'b0;        // Not used
                        rs1_id       = instr[25:21]; // rs
                        rs2_id       = instr[20:16]; // rt
                        rdst_id      = instr[15:11]; // rd
                        reg_data_sel = 1'b0;         // alu result
                    end
                    // jr
                    6'b001000: begin
                        jump_type    = 2'b00;        // jr
                        jump_addr    = 32'b0;        // None
                        we_dmem      = 1'b0;         // No
                        we_regfile   = 1'b0;         // No
                        op           = OP_NOT_DEFINED; // Not defined
                        ssel         = 2'b00;        // Not used
                        imm          = 32'b0;        // Not used
                        rs1_id       = instr[25:21]; // rs
                        rs2_id       = 5'b0;         // None
                        rdst_id      = 5'b0;         // None
                        reg_data_sel = 1'b0;         // None
                    end
                    // default
                    default: begin
                        jump_type    = 2'b11;        // NOP
                        jump_addr    = 32'b0;        // None
                        we_dmem      = 1'b0;         // No
                        we_regfile   = 1'b0;         // No
                        op           = OP_NOT_DEFINED; // Not defined
                        ssel         = 2'b00;        // Not used
                        imm          = 32'b0;        // Not used
                        rs1_id       = 5'b0;         // None
                        rs2_id       = 5'b0;         // None
                        rdst_id      = 5'b0;         // None
                        reg_data_sel = 1'b0;         // None
                    end
                endcase
            end
            // addi
            6'b001000: begin
                jump_type    = 2'b11;        // NOP
                jump_addr    = 32'b0;        // None
                we_dmem      = 1'b0;         // No
                we_regfile   = 1'b1;         // Yes
                op           = OP_ADD;       // add
                ssel         = 2'b11;        // from immediate
                imm          = $signed(instr[15:0]);  // imm
                rs1_id       = instr[25:21]; // rs
                rs2_id       = 5'b0;         // None
                rdst_id      = instr[20:16]; // rt
                reg_data_sel = 1'b0;         // alu result
            end
            // slti
            6'b001010: begin
                jump_type    = 2'b11;        // NOP
                jump_addr    = 32'b0;        // None
                we_dmem      = 1'b0;         // No
                we_regfile   = 1'b1;         // Yes
                op           = OP_SLT;       // slt
                ssel         = 2'b11;        // from immediate
                imm          = $signed(instr[15:0]);  // imm
                rs1_id       = instr[25:21]; // rs
                rs2_id       = 5'b0;         // None
                rdst_id      = instr[20:16]; // rt
                reg_data_sel = 1'b0;         // alu result
            end
            // lw
            6'b100011: begin
                jump_type    = 2'b11;        // NOP
                jump_addr    = 32'b0;        // None
                we_dmem      = 1'b0;         // No
                we_regfile   = 1'b1;         // Yes
                op           = OP_ADD;       // add
                ssel         = 2'b11;        // from immediate
                imm          = $signed(instr[15:0]);  // imm
                rs1_id       = instr[25:21]; // rs
                rs2_id       = 5'b0;         // None
                rdst_id      = instr[20:16]; // rt
                reg_data_sel = 1'b1;         // memory result
            end
            // sw
            6'b101011: begin
                jump_type    = 2'b11;        // NOP
                jump_addr    = 32'b0;        // None
                we_dmem      = 1'b1;         // Yes
                we_regfile   = 1'b0;         // No
                op           = OP_ADD;       // add
                ssel         = 2'b11;        // from immediate
                imm          = $signed(instr[15:0]);  // imm
                rs1_id       = instr[25:21]; // rs
                rs2_id       = instr[20:16]; // rt
                rdst_id      = 5'b0;         // None
                reg_data_sel = 1'b0;         // None
            end
            // beq
            6'b000100: begin
                jump_type    = 2'b01;        // branch
                jump_addr    = 32'b0;        // Not used
                we_dmem      = 1'b0;         // No
                we_regfile   = 1'b0;         // No
                op           = OP_SUB;       // sub
                ssel         = 2'b01;        // from register
                imm          = $signed(instr[15:0]); // Not used
                rs1_id       = instr[25:21]; // rs
                rs2_id       = instr[20:16]; // rt
                rdst_id      = 5'b0;         // None
                reg_data_sel = 1'b0;         // None
            end
            // jal
            6'b000011: begin
                jump_type    = 2'b10;        // jump
                jump_addr    = instr[25:0];  // target_pc
                we_dmem      = 1'b0;         // No
                we_regfile   = 1'b1;         // Yes
                op           = OP_ADD;       // add
                ssel         = 2'b10;        // from pc
                imm          = 32'b0;        // Not used
                rs1_id       = 5'b0;         // $zero
                rs2_id       = 5'b0;         // None
                rdst_id      = 5'b11111;     // $ra
                reg_data_sel = 1'b0;         // alu result
            end
            // j
            6'b000010: begin
                jump_type    = 2'b10;        // jump
                jump_addr    = instr[25:0];  // target_pc
                we_dmem      = 1'b0;         // No
                we_regfile   = 1'b0;         // No
                op           = OP_NOT_DEFINED; // Not defined
                ssel         = 2'b00;        // Not used
                imm          = 32'b0;        // Not used
                rs1_id       = 5'b0;         // None
                rs2_id       = 5'b0;         // None
                rdst_id      = 5'b0;         // None
                reg_data_sel = 1'b0;         // None
            end
            // default
            default: begin
                jump_type    = 2'b11;        // NOP
                jump_addr    = 32'b0;        // None
                we_dmem      = 1'b0;         // No
                we_regfile   = 1'b0;         // No
                op           = OP_NOT_DEFINED; // Not defined
                ssel         = 2'b00;        // Not used
                imm          = 32'b0;        // Not used
                rs1_id       = 5'b0;         // None
                rs2_id       = 5'b0;         // None
                rdst_id      = 5'b0;         // None
                reg_data_sel = 1'b0;         // None
            end
        endcase
    end
endmodule