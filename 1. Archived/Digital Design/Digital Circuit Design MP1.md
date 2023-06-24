# Digital Circuit Design MP1

## Timing Diagram

![[Screenshot from 2023-03-31 00-28-51.png]]

## mux_t.v

```verilog
`timescale 1ns/10ps
module mux2_1 (out,a,b,sel) ;
    // Port declarations
	output reg out ;
	input a,b,sel ;

    reg sel_, a1, b1 ;

    always @(a, b, sel) begin

        // The netlist
        // not (sel_, sel) ;
        // and (a1, a, sel_) ;
        // and (b1, b, sel) ;
        // or (out, a1, b1) ;
        sel_ = ~sel ;
        a1 = a & sel_ ;
        b1 = b & sel ;
        out = a1 | b1 ;

    end

endmodule

module test_mux ;

reg a, b, sel ;

//MUX instance
    mux2_1 mux (out, a, b, sel) ;

//Stimulus

    initial
    begin
 	  a=0 ; b=1 ; sel=0 ;
      #5  b=0 ;
      #5  b=1 ; sel=1 ;
      #5  a=1 ;
      #5  b=0 ;
    end

    //Display results
    initial
    begin
      $display("                time out  a   b  sel");
      $monitor($time, "  %b   %b   %b   %b", out,a,b,sel) ;
    end

	initial
	begin
    $dumpfile("mux_t.vcd");
    $dumpvars;
	end
	
endmodule
```