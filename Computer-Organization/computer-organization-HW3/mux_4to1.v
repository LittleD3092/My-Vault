module mux_4to1
(
    input [1 : 0] sel,
    input [31 : 0] in0,
    input [31 : 0] in1,
    input [31 : 0] in2,
    input [31 : 0] in3,
    output reg [31 : 0] out
);

always @(*) begin
    case (sel)
        2'b00: out = in0;
        2'b01: out = in1;
        2'b10: out = in2;
        2'b11: out = in3;
        default: out = 32'h0;
    endcase
end

endmodule