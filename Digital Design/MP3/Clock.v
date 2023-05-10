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

wire [3:0] h0 ;
wire [2:0] h1 ;

wire       clr_andtimeup ;
reg        timeup;

assign clr_andtimeup = clr_ & timeup ;

BCD_counter M0 (m0,m0_tc,clr_andtimeup, Vdd, clk) ;
Hex_counter M1 (m1,m1_tc,clr_andtimeup, m0_tc, clk) ;

BCD_counter H0 (h0,h0_tc,clr_andtimeup, m1_tc, clk) ;
Hex_counter H1 (h1,h1_tc,clr_andtimeup, h0_tc, clk) ;

always @(posedge clk)
	if (h1 == 2 && h0 == 3 && m1 == 5 && m0 == 9)
		timeup = 0;

always @(negedge clk)
	timeup = 1;

//Stimulus
initial
begin
	clk = 1'b0 ;
	repeat(4000) // 100ms * #5 * timerepeat
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
	timeup = 1;
end

initial
begin
$dumpfile("Clock.vcd");
$dumpvars;
end

endmodule