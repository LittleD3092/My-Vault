/*
 *    Author : Che-Yu Wu @ EISL
 *    Date   : 2022-03-30
 */

module decode #(parameter DWIDTH = 32)
(
    input [DWIDTH-1:0]  instr,   // Input instruction.

    output reg [3 : 0]      op,      // Operation code for the ALU.
    output reg              ssel,    // Select the signal for either the immediate value or rs2.

    output reg [DWIDTH-1:0] imm,     // The immediate value (if used).
    output reg [4 : 0]      rs1_id,  // register ID for rs.
    output reg [4 : 0]      rs2_id,  // register ID for rt (if used).
    output reg [4 : 0]      rdst_id // register ID for rd or rt (if used).
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
                        
                        op = OP_ADD;
                        ssel = 1'b1;
                        
                        imm = 32'b0; // not used
                        rs1_id = instr[25:21];
                        rs2_id = instr[20:16];
                        rdst_id = instr[15:11];

                    end

                    // sub rd, rs, rt
                    6'b100010: begin
                        
                        op = OP_SUB;
                        ssel = 1'b1;
                        
                        imm = 32'b0; // not used
                        rs1_id = instr[25:21];
                        rs2_id = instr[20:16];
                        rdst_id = instr[15:11];

                    end

                    // and rd, rs, rt
                    6'b100100: begin
                        
                        op = OP_AND;
                        ssel = 1'b1;
                        
                        imm = 32'b0; // not used
                        rs1_id = instr[25:21];
                        rs2_id = instr[20:16];
                        rdst_id = instr[15:11];

                    end

                    // or rd, rs, rt
                    6'b100101: begin
                        
                        op = OP_OR;
                        ssel = 1'b1;
                        
                        imm = 32'b0; // not used
                        rs1_id = instr[25:21];
                        rs2_id = instr[20:16];
                        rdst_id = instr[15:11];

                    end

                    // nor rd, rs, rt
                    6'b100111: begin
                        
                        op = OP_NOR;
                        ssel = 1'b1;
                        
                        imm = 32'b0; // not used
                        rs1_id = instr[25:21];
                        rs2_id = instr[20:16];
                        rdst_id = instr[15:11];

                    end

                    // slt rd, rs, rt
                    6'b101010: begin
                        
                        op = OP_SLT;
                        ssel = 1'b1;
                        
                        imm = 32'b0; // not used
                        rs1_id = instr[25:21];
                        rs2_id = instr[20:16];
                        rdst_id = instr[15:11];

                    end

                    // default, not defined
                    default: begin
                        
                        op = OP_NOT_DEFINED;
                        ssel = 1'b0;
                        
                        imm = 32'b0; // not used
                        rs1_id = 5'b0; // not used
                        rs2_id = 5'b0; // not used
                        rdst_id = 5'b0; // not used

                    end

                endcase

            end

            // I-type addi rt, rs, imm
            6'b001000: begin
                
                op = OP_ADD;
                ssel = 1'b0;

                imm = $signed(instr[15:0]);
                rs1_id = instr[25:21];
                rs2_id = 5'b0; // not used
                rdst_id = instr[20:16];

            end

            // I-type slti rt, rs, imm
            6'b001010: begin
                
                op = OP_SLT;
                ssel = 1'b0;

                imm = $signed(instr[15:0]);
                rs1_id = instr[25:21];
                rs2_id = 5'b0; // not used
                rdst_id = instr[20:16];

            end

            // default, not defined
            default: begin
                
                op = OP_NOT_DEFINED;
                ssel = 1'b0;
                
                imm = 32'b0; // not used
                rs1_id = 5'b0; // not used
                rs2_id = 5'b0; // not used
                rdst_id = 5'b0; // not used

            end

        endcase

    end

endmodule