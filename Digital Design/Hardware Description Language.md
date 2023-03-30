Tag: #digital-design 
Previous: [[Digital Design]]
Link: 

[TOC]

---

- Describe a circuit is textual form.
- Comment:
	- One line: `//`
	- Multiple line: `/* */`

# Example 1: Basic Circuit

![[Pasted image 20230329213559.png|400]]

The circuit above can be represented by

```verilog
module Simple_Circuit(A, B, C, D, E);
	output D, E;
	input  A, B, C;
	wire   w1;

	and    G1(w1, A, B); // Optional gate instance name.
	not    G2(E, C);
	or     G3(D, w1, E);
endmodule
```

# Example 2: Component with Delay

To specify the delay of operation, we use `#`.

```verilog
// Verilog model of simple circuit with propagation delay
module Simple_Circuit_prop_delay(A, B, C, D, E);
	output D, E;
	input  A, B, C;
	wire   w1;

	and    #(30) G1(w1, A, B); // Optional gate instance name.
	not    #(10) G2(E, C);
	or     #(20) G3(D, w1, E);
endmodule
```

The code above will output the chart below:

|         | Time Units (ns) | Input (A,B,C) | Output (E,w1,D) |
| ------- | --------------- | ------------- | --------------- |
| Initial | -               | 000           | 101             |
| Change  | -               | 111           | 101             |
|         | 10              | 111           | 001             |
|         | 20              | 111           | 001             |
|         | 30              | 111           | 010             |
|         | 40              | 111           | 010             |
|         | 50              | 111           | 011             | 

# Example 3: Test Bench

- To test the circuit, we append the test bench module after the circuit module.
- It is a convention to use `t_` prefix to specify that this module is a test bench.

```verilog
// Test bench for Simple_Circuit_prop_delay
module t_Simple_Circuit_prop_delay;
    wire D, E;
    reg  A, B, C;

	Simple_Circuit_prop_delay M1(A, B, C, D, E); // Instance name required
	
	initial
		begin
			A = 1'b0; B = 1'b0; C = 1'b0;
			#100 A = 1'b1; B = 1'b1; C = 1'b1;
		end
	initial #200 $finish;
endmodule
```

The code above generates the chart below:

![[Pasted image 20230329214809.png]]

# Example 4: Boolean Expression

- In verilog, you can also use Boolean expression to model a circuit.
- For a circuit with the following Boolean expression:

$$
\begin{array}{l}
	E &=& A + BC + B'D \\
	F &=& B'C + BC'D'
\end{array}
$$

We can write the following code:

```verilog
// Verilog model: Circuit with Boolean expressions

module Circuit_Boolean_CA(E, F, A, B, C, D);
	output E, F;
	input  A, B, C, D;

	assign E = A || (B && C) || ((!B) && D);
	assign F = ((!B) && C) || (B && (!C) && (!D));
endmodule
```

# Example 5: Customized Component

Users can use truth table to define their own components:

```verilog
// Verilog model: User_defined Primitive

primitive UDP_02467(D, A, B, C);
	output D;
	input  A, B, C;

	// Truth table for D = f(A, B, C) = sum(0, 2, 4, 6, 7);
	table
	// A B C : D // Column header comment
	   0 0 0 : 1;
	   0 0 1 : 0;
	   0 1 0 : 1;
	   0 1 1 : 0;
	   1 0 0 : 1;
	   1 0 1 : 0;
	   1 1 0 : 1;
	   1 1 1 : 1;
	endtable
endprimitive

// Instantiate primitive

// Verilog model: Circuit instantiation of Circuit_UDP_02467

module Circuit_with_UDP_02467(e, f, a, b, c, d);
	output e, f;
	input  a, b, c, d;

	UDP_02467 (e, a, b, c);
	and       (f, e, d); // Option gate instance name omitted
endmodule
```

The circuit above will look like this:

![[Pasted image 20230329215837.png|350]]

---

# Reference

Digital Design, 6th edition

---

# Note

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.