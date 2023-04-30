module shift_left
(
    input [31 : 0] in1,
    input [31 : 0] in2,
    output reg [31 : 0] out
);

always @(*) begin
    out = in1 << in2;
end

endmodule