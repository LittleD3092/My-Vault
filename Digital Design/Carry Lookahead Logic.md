Tag: #digital-design 
Previous: [[Carry Propagation]]
Link: [[Adder]]

[TOC]

---

![[Pasted image 20230424180846.png]]

To get the expression and implementation of carry lookahead logic, we follow the steps below:

1. As the graph above shows, we define two variables:

$$
\begin{array}{l}
	P_i &=& A_i \oplus B_i & \text{(carry propagate)} \\
	G_i &=& A_i B_i & \text{(carry generate)}
\end{array}
$$

We call $P_i$ carry propagate, $G_i$ carry generate.

2. The output sum $S_i$ and $C_{i + 1}$ is

$$\begin{array}{l}
	S_i &=& P_i \oplus C_i \\
C_{i + 1} &=& G_i + P_iC_i
\end{array}$$

3. We now write carry outputs for each stage and substitute the value of $C_i$:

$$\begin{array}{l}
	C_0 &=& \text{input carry} \\
	C_1 &=& G_0 + P_0C_0 \\
	C_2 &=& G_1 + P_1C_1 \\
	    &=& G_1 + P_1(G_0 + P_0 C_0) \\
	C_3 &=& G_2 + P_2C_2 \\
	    &=& G_2 + P_2(G_1 + P_1G_0 + P_1P_0C_0) \\
	    &=& G_2 + P_2G_1 + P_2P_1G_0 + P_2 P_1 P_0C_0
\end{array}$$

4. The boolean function can be implemented as below:

![[Pasted image 20230424182644.png]]

Note that the $P_i, G_i$ can be computed in parallel, and the carries are propagated in parallel.
This speed is achieved at the expense of additional complexity.

5. We can use the carry lookahead module to implement 4-bit [[Full Adder]] like so:

![[Pasted image 20230424183039.png]]

---

# Reference

Digital Design, 6th edition

---

# Note

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.