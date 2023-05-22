# Report

I added an option to `A_sel`:

```verilog
parameter A_sel_In= 3'b000, A_sel_B=3'b001, A_sel_Sub=3'b010, A_sel_NegSub=3'b011, A_sel_X=3'bxxx;
```

And expanded the bits of `A_sel` to 3 bits. I then modified the code according to the python code. 

The difference between the original design and the new design is the case where `A < B`, so the control signals need to be modified:

```verilog
always @(*)
//Default control signals
begin
	A_sel = A_sel_X;
	A_en = 1'b0;
	B_sel = B_sel_X;
	B_en = 1'b0;
	idle = 1'b1;
	result_rdy = 1'b0;
	case ( state )
	WAIT: begin
		A_sel = A_sel_In;
		A_en = 1'b1;
		B_sel = B_sel_In;
		B_en = 1'b1;
		idle = 1'b1;
		end
	CALC: if ( A_lt_B ) begin
			A_sel = A_sel_NegSub;
			A_en = 1'b1;
			B_sel = B_sel_A;
			B_en = 1'b1;
			idle = 1'b0;
			end
		else if ( !B_zero ) begin
			A_sel = A_sel_Sub;
			A_en = 1'b1;
			idle = 1'b0;
			end
	DONE: begin
		result_rdy = 1'b1;
		end
	endcase
end
```

Also, the case `A_sel_NegSub` need to be implemented:

```verilog
always @(*)
	case (A_sel)
	A_sel_In: A_out = operand_A ;
	A_sel_B: A_out = B ;
	A_sel_Sub: A_out = sub_out;
	A_sel_NegSub: A_out = negative_sub_out;
	default: A_out = 16'bx ;
	endcase
```

Where `negative_sub_out` is a customized `wire` with the following assignment:

```verilog
assign negative_sub_out = ~sub_out + 1;
```