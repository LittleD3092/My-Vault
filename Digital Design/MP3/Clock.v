`timescale 100ms/10ms

// input:
//     clr_: clear, active low
//     enb:  enable counting
//     clk:  clock, trigger counting
// output:
//     count: 4-bit BCD counter
//     TC: 1-bit terminal count, 1 when count = 9
module BCD_counter(count,TC,clr_, enb, clk) ;
output [3:0] count ;
output TC ;
reg [3:0] count ;
input clr_, enb, clk ;
reg TC ;

always @ (*)
	if(enb && count >= 9)
		TC = 1;
	else
		TC = 0;
always @ (posedge clk or negedge clr_) // combinational+sequential
	if (~clr_)
		count = 0 ;
	else if (enb)
		if (TC)
			count = 0;
		else
			count = count + 1;
endmodule

// input: 
//     clr_: clear, active low
//     enb:  enable counting
//     clk:  clock, trigger counting
// output:
//     count: 3-bit hex counter, max = 5
//     TC: 1-bit terminal count, 1 when count = 5
module Hex_counter(count,TC,clr_, enb, clk) ;
output [2:0] count ;
output TC ;
reg [2:0] count ;
input clr_, enb, clk ;
reg TC ;

always @ (*)
	if(enb && count >= 5)
		TC = 1;
	else
		TC = 0;	


always @ (posedge clk or negedge clr_) // combinational+sequential
	if (~clr_)
		count = 0 ;
	else if (enb)
		if (TC)
			count = 0;
		else
			count = count + 1 ;
endmodule


module Testfixture ;
wire Vdd = 1'b1;
reg clk, clr_;
wire [3:0] m0 ;
wire [2:0] m1 ;

BCD_counter M0 (m0,m0_tc,clr_, Vdd, clk) ;
Hex_counter M1 (m1,m1_tc,clr_, m0_tc, clk) ;

//Stimulus
initial
begin
	clk = 1'b0 ;
	repeat(160)
		#5 clk = ~clk ;
	$finish ;
end
	
initial
begin
  clr_ = 0;
  #6  clr_ = 1'b1;  
end

initial
begin
$dumpfile("Clock.vcd");
$dumpvars;
end

endmodule