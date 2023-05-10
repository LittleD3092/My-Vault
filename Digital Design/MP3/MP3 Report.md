```verilog
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
```

我更改了`Testfixture` module 中的wiring。

1. 增加了兩個零件 `BCD_counter H0` 和 `BCD_counter H1`，還有相對應的輸出 `wire [3:0] h0` 與 `wire [2:0] h1`。
2. 更改了`clk` 跳動的次數（`repeat` 中 `160` 改為 `4000`）
3. 為了得到23:59時變回00:00的效果，我使用了counter的reset腳位。本來是將 `clr_` 接入counter來重置，我將 `clr_` 與自訂的 register `timeup` 做 AND，將結果以 `wire clr_andtimeup` 輸入進每個counter。
	- 一開始的時候 `timeup` 為 `1`。
	- 當時間為23:59，在下個 `clk` 的 `posedge` 時，`timeup` 會變成 `0` 將所有 counter 重置。
	- 為了不影響下一次 `posedge clk` 時 counter的運作，`timeup` 會在 `negedge clk` 時改回 `1`。

Wave 截圖如下：

![[Pasted image 20230510175840.png]]