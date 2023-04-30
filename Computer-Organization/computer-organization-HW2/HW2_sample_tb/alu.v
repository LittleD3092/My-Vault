module alu #(parameter DWIDTH = 32)
(
    input [3:0] op,         // Operation to perform
    input [DWIDTH-1:0] rs1, // Input data #1.
    input [DWIDTH-1:0] rs2, // Input data #2.

    output reg [DWIDTH-1:0] rd, // Result of computation.
    output reg zero,            // zero = 1 if rd is 0, 0 otherwise.
    output reg overflow         // overflow = 1 if overflow happens.
);

    always@(op or rs1 or rs2) begin
        // default value
        overflow = 0;
        zero = 0;

        case (op)
            // and operation
            4'b0000: rd = rs1 & rs2;

            // or operation
            4'b0001: rd = rs1 | rs2;

            // add operation
            4'b0010: 
            begin
                rd = rs1 + rs2;
                overflow = (rs1[31] == rs2[31]) && (rs1[31] != rd[31]);
            end

            // subtract operation
            4'b0110: 
            begin
                rd = rs1 - rs2;
                overflow = (rs1[31] != rs2[31]) && (rs1[31] != rd[31]);
            end

            // nor operation
            4'b1100: rd = ~(rs1 | rs2);

            // slt operation
            4'b0111: rd = ($signed(rs1) < $signed(rs2)) ? 32'h1 : 32'h0;

            // default: do nothing
            default: rd = 32'h0;
        endcase

        // check if rd is 0
        zero = (rd == 32'h0) ? 1 : 0;
    end

endmodule