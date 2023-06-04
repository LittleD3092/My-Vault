`timescale 1ns/1ps

module stm32 (
    input  wire [11:0] pc0__analog_input,
    output wire        pc3__sevenseg_din,
    output wire        pc4__sevenseg_cs,
    output wire        pc5__sevenseg_clk
);

    reg         [7 :0] address;
    reg         [7 :0] data;
    wire        [15:0] payload;
    reg         [4 :0] counter;

    assign payload = {address[7:0], data[7:0]};

    initial begin
        pc5__sevenseg_clk = 0;
        while (1) begin
            #(125) pc5__sevenseg_clk = ~pc5__sevenseg_clk;
        end
    end

endmodule