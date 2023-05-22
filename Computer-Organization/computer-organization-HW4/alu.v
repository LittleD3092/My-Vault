/*
 *    Author : ydlee @ EISL
 *    Date   : 2022-03-17
 */

module alu #(
    parameter DWIDTH = 32
)(
    input  wire        [3 : 0]        op,       // Operation to perform.
    input  wire        [DWIDTH-1 : 0] rs1,      // Input data #1.
    input  wire        [DWIDTH-1 : 0] rs2,      // Input data #2.

    output reg         [DWIDTH-1 : 0] rd,       // Result of computation.
    output reg                        zero,     // zero = 1 if rd is 0, 0 otherwise.
    output reg                        overflow  // overflow = 1 if overflow happens.
);

    localparam [3:0] OP_AND = 4'b0000,
                     OP_OR  = 4'b0001,
                     OP_ADD = 4'b0010,
                     OP_SUB = 4'b0110,
                     OP_NOR = 4'b1100,
                     OP_SLT = 4'b0111,
                     OP_SLL = 4'b1001,
                     OP_SRL = 4'b1010,
                     OP_SRA = 4'b1101,
                     OP_LUI = 4'b1110;

    reg signed [DWIDTH : 0] result;

    // ALU functionality
    always @(*) begin
        case (op)
            OP_AND  : result =  (rs1 & rs2);
            OP_OR   : result =  (rs1 | rs2);
            OP_ADD  : result =  (rs1 + rs2);
            OP_SUB  : result =  (rs1 - rs2);
            OP_NOR  : result = ~(rs1 | rs2);
            OP_SLT  : result =  $signed(rs1) < $signed(rs2);
            OP_SLL  : result =  (rs1 << rs2[4:0]);
            OP_SRL  : result =  (rs1 >> rs2[4:0]);
            OP_SRA  : result =  ($signed(rs1) >>> rs2[4:0]);
            OP_LUI  : result =  {rs2[15:0], 16'b0};
            default : result = 0;
        endcase
    end

    // rd logic
     always @(*) begin
        rd = result[DWIDTH-1 : 0];
    end

    // zero logic
    always @(*) begin
        zero = (rd == 0);
    end

    // overflow logic
    always @(*) begin
        case (op)
            OP_ADD  : overflow = ~(rs1[DWIDTH-1] ^ rs2 [DWIDTH-1]) & (rs1[DWIDTH-1] ^ rd[DWIDTH-1]);
            OP_SUB  : overflow =  (rs1[DWIDTH-1] ^ rs2 [DWIDTH-1]) & (rs1[DWIDTH-1] ^ rd[DWIDTH-1]);
            default : overflow = 0;
        endcase
    end

endmodule
