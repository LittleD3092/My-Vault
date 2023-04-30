module imem (
    input  [ 5 : 0] addr,  // byte address
    output [31 : 0] rdata  // read data
);

    reg [31 : 0] RAM [15 : 0];

    initial // put the machine code of the program here.
    begin
        RAM[0]  = 32'h20080017; RAM[1]  = 32'h2109002d;
        RAM[2]  = 32'hac090008; RAM[3]  = 32'h8c0a0008;
        RAM[4]  = 32'h214bffd3; RAM[5]  = 32'h110b0001;
        RAM[6]  = 32'hac080000; RAM[7]  = 32'h08100007;
        RAM[8]  = 32'h00000000; RAM[9]  = 32'h00000000; 
        RAM[10] = 32'h00000000; RAM[11] = 32'h00000000; 
        RAM[12] = 32'h00000000; RAM[13] = 32'h00000000;
        RAM[14] = 32'h00000000; RAM[15] = 32'h00000000;
    end

    assign rdata = RAM[addr[5:2]];

endmodule