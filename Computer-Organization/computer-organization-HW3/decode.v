/*
 *    Author : Che-Yu Wu @ EISL
 *    Date   : 2022-03-30
 */
// 109611066 吳典謀

/*

| instructions     | jump_type | jump_addr | we_dmem | we_regfile | op         | ssel                | imm               | rs1_id            | rs2_id            | rdst_id           | reg_data_sel   |
| ---------------- | --------- | --------- | ------- | ---------- | ---------- | ------------------- | ----------------- | ----------------- | ----------------- | ----------------- | -------------- |
| add  rd, rs, rt  | NOP (11)  | None (0)  | No (0)  | Yes (1)    | add (0010) | from register (01)  | Not used (0)      | rs (instr[25:21]) | rt (instr[20:16]) | rd (instr[15:11]) | alu result (0) |
| addi rt, rs, imm | NOP (11)  | None (0)  | No (0)  | Yes (1)    | add (0010) | from immediate (11) | imm (instr[15:0]) | rs (instr[25:21]) | None (0)          | rt (instr[20:16]) | alu result (0) |
| sub  rd, rs, rt  | NOP (11)  | None (0)  | No (0)  | Yes (1)    | sub (0110) | from register (01)  | Not used (0)      | rs (instr[25:21]) | rt (instr[20:16]) | rd (instr[15:11]) | alu result (0) |
| and  rd, rs, rt  | NOP (11)  | None (0)  | No (0)  | Yes (1)    | and (0000) | from register (01)  | Not used (0)      | rs (instr[25:21]) | rt (instr[20:16]) | rd (instr[15:11]) | alu result (0) |
| or   rd, rs, rt  | NOP (11)  | None (0)  | No (0)  | Yes (1)    | or (0001)  | from register (01)  | Not used (0)      | rs (instr[25:21]) | rt (instr[20:16]) | rd (instr[15:11]) | alu result (0) |

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
                    
                    // add rd, rs, rt
                    6'b100000: begin
                        
                        jump_type = 2'b00; // not used
                        jump_addr = 32'b0; // not used
                        we_dmem = 1'b0;    // not used
                        we_regfile = 1'b1;

                        op = OP_ADD;
                        ssel = 2'b01;
                        
                        imm = 32'b0; // not used
                        rs1_id = instr[25:21];
                        rs2_id = instr[20:16];
                        rdst_id = instr[15:11];

                    end

                    // sub rd, rs, rt
                    6'b100010: begin
                        
                        jump_type = 2'b00; // not used
                        jump_addr = 32'b0; // not used
                        we_dmem = 1'b0;    // not used
                        we_regfile = 1'b1;

                        op = OP_SUB;
                        ssel = 2'b01;
                        
                        imm = 32'b0; // not used
                        rs1_id = instr[25:21];
                        rs2_id = instr[20:16];
                        rdst_id = instr[15:11];

                    end

                    // and rd, rs, rt
                    6'b100100: begin
                        
                        jump_type = 2'b00; // not used
                        jump_addr = 32'b0; // not used
                        we_dmem = 1'b0;    // not used
                        we_regfile = 1'b1;

                        op = OP_AND;
                        ssel = 2'b01;
                        
                        imm = 32'b0; // not used
                        rs1_id = instr[25:21];
                        rs2_id = instr[20:16];
                        rdst_id = instr[15:11];

                    end

                    // or rd, rs, rt
                    6'b100101: begin
                        
                        jump_type = 2'b00; // not used
                        jump_addr = 32'b0; // not used
                        we_dmem = 1'b0;    // not used
                        we_regfile = 1'b1;

                        op = OP_OR;
                        ssel = 2'b01;
                        
                        imm = 32'b0; // not used
                        rs1_id = instr[25:21];
                        rs2_id = instr[20:16];
                        rdst_id = instr[15:11];

                    end

                    // nor rd, rs, rt
                    6'b100111: begin
                        
                        jump_type = 2'b00; // not used
                        jump_addr = 32'b0; // not used
                        we_dmem = 1'b0;    // not used
                        we_regfile = 1'b1;

                        op = OP_NOR;
                        ssel = 2'b01;
                        
                        imm = 32'b0; // not used
                        rs1_id = instr[25:21];
                        rs2_id = instr[20:16];
                        rdst_id = instr[15:11];

                    end

                    // slt rd, rs, rt
                    6'b101010: begin
                        
                        jump_type = 2'b00; // not used
                        jump_addr = 32'b0; // not used
                        we_dmem = 1'b0;    // not used
                        we_regfile = 1'b1;

                        op = OP_SLT;
                        ssel = 2'b01;
                        
                        imm = 32'b0; // not used
                        rs1_id = instr[25:21];
                        rs2_id = instr[20:16];
                        rdst_id = instr[15:11];

                    end

                    // jr rs
                    6'b001000: begin

                        jump_type = 2'b00; // jump to address in rs
                        jump_addr = 32'b0; // not used
                        we_dmem = 1'b0;    // not used
                        we_regfile = 1'b0; // not used

                        op = OP_NOT_DEFINED;
                        ssel = 2'b00;

                        imm = 32'b0; // not used
                        rs1_id = instr[25:21];
                        rs2_id = 5'b0; // not used
                        rdst_id = 5'b0; // not used

                    end

                    // default, not defined
                    default: begin
                        
                        jump_type = 2'b00; // not used
                        jump_addr = 32'b0; // not used
                        we_dmem = 1'b0;    // not used
                        we_regfile = 1'b0; // not defined

                        op = OP_NOT_DEFINED;
                        ssel = 2'b00;
                        
                        imm = 32'b0; // not used
                        rs1_id = 5'b0; // not used
                        rs2_id = 5'b0; // not used
                        rdst_id = 5'b0; // not used

                    end

                endcase

            end

            // I-type addi rt, rs, imm
            6'b001000: begin
                
                jump_type = 2'b00; // not used
                jump_addr = 32'b0; // not used
                we_dmem = 1'b0;    // not used
                we_regfile = 1'b1;

                op = OP_ADD;
                ssel = 2'b11;

                imm = $signed(instr[15:0]);
                rs1_id = instr[25:21];
                rs2_id = 5'b0; // not used
                rdst_id = instr[20:16];

            end

            // I-type slti rt, rs, imm
            6'b001010: begin
                
                jump_type = 2'b00; // not used
                jump_addr = 32'b0; // not used
                we_dmem = 1'b0;    // not used
                we_regfile = 1'b1;

                op = OP_SLT;
                ssel = 2'b11;

                imm = $signed(instr[15:0]);
                rs1_id = instr[25:21];
                rs2_id = 5'b0; // not used
                rdst_id = instr[20:16];

            end

            // I-type lw rt, imm(rs)
            6'b100011: begin
                
                jump_type = 2'b00; // not used
                jump_addr = 32'b0; // not used
                we_dmem = 1'b0;
                we_regfile = 1'b1;

                op = OP_ADD;
                ssel = 2'b00;

                imm = $signed(instr[15:0]);
                rs1_id = instr[25:21];
                rs2_id = 5'b0; // not used
                rdst_id = instr[20:16];

            end

            // I-type sw rt, imm(rs)
            6'b101011: begin
                
                jump_type = 2'b00; // not used
                jump_addr = 32'b0; // not used
                we_dmem = 1'b1;
                we_regfile = 1'b0;

                op = OP_ADD;
                ssel = 2'b00;

                imm = $signed(instr[15:0]);
                rs1_id = instr[25:21];
                rs2_id = instr[20:16];
                rdst_id = 5'b0; // not used

            end

            // I-type beq rs, rt, imm
            6'b000100: begin
                
                jump_type = 2'b01;
                jump_addr = 32'b0; // not used
                we_dmem = 1'b0;    // not used
                we_regfile = 1'b0; // not defined

                op = OP_SUB;
                ssel = 2'b00;

                imm = $signed(instr[15:0]);
                rs1_id = instr[25:21];
                rs2_id = instr[20:16];
                rdst_id = 5'b0; // not used

            end

            // J-type jal target_pc
            6'b000011: begin

                jump_type = 2'b10;
                jump_addr = instr[25:0];
                we_dmem = 1'b0;    // not used
                we_regfile = 1'b1;

                op = OP_ADD;
                ssel = 2'b00;

                imm = 32'b0; // not used
                rs1_id = 5'b0; // not used
                rs2_id = 5'b0; // not used
                rdst_id = instr[20:16];

            end

            // J-type j target_pc
            6'b000010: begin

                jump_type = 2'b10;
                jump_addr = instr[25:0];
                we_dmem = 1'b0;    // not used
                we_regfile = 1'b0; // not defined

                op = OP_NOT_DEFINED;
                ssel = 2'b00;

                imm = 32'b0; // not used
                rs1_id = 5'b0; // not used
                rs2_id = 5'b0; // not used
                rdst_id = 5'b0; // not used

            end

            // default, not defined
            default: begin
                
                jump_type = 2'b00; // not used
                jump_addr = 32'b0; // not used
                we_dmem = 1'b0;    // not used
                we_regfile = 1'b0; // not defined

                op = OP_NOT_DEFINED;
                ssel = 2'b00;
                
                imm = 32'b0; // not used
                rs1_id = 5'b0; // not used
                rs2_id = 5'b0; // not used
                rdst_id = 5'b0; // not used

            end

        endcase

    end

endmodule