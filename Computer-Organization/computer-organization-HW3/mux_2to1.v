module mux_2to1(
    input             sel,
    input [31:0]      in0,
    input [31:0]      in1,
    output reg [31:0] out
);

    always @(*) begin
        case (sel)
            0: out = in0;
            1: out = in1;
            default: out = 32'h0;
        endcase
    end
);
    
endmodule