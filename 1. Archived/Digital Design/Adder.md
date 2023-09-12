Tag: #digital-design #list 
Previous: [[Digital Design]]
Link: 

[TOC]

---

# Bit Adder

- A combinational circuit that performs the addition of two bits is called [[Half Adder]].
- A combinational circuit that performs the addition of 3 bits (including previous carry) is called a [[Full Adder]].

# Binary Adder

- Can be constructed by [[Full Adder|full adders]] in cascade.
- Addition of n-bit number requires a chain of $n$ [[Full Adder]] or $1$ [[Half Adder]] and $n - 1$ [[Full Adder]].

![[Pasted image 20230424180415.png]]

## Carry Propagation

[[Carry Propagation]]

# Decimal Adder

- Input: Total 9 bits.
	- 4 bits for operand 1 in BCD code.
	- 4 bits for operand 2 in BCD code.
	- 1 bit for input carry.
- Output: Total 5 bits.
	- 4 bits for result in BCD code.
	- 1 bit for carry.

Let's first examine the table of different sums:

| Binary Sum | $K$ | $Z_8$ | $Z_4$ | $Z_2$ | $Z_1$ | BCD Sum | $C$ | $S_8$ | $S_4$ | $S_2$ | $S_1$ | Decimal |
| ---------- | --- | ----- | ----- | ----- | ----- | ------- | --- | ----- | ----- | ----- | ----- | ------- |
|            | 0   | 0     | 0     | 0     | 0     |         | 0   | 0     | 0     | 0     | 0     | 0       |
|            | 0   | 0     | 0     | 0     | 1     |         | 0   | 0     | 0     | 0     | 1     | 1       |
|            | 0   | 0     | 0     | 1     | 0     |         | 0   | 0     | 0     | 1     | 0     | 2       |
|            | 0   | 0     | 0     | 1     | 1     |         | 0   | 0     | 0     | 1     | 1     | 3       |
|            | 0   | 0     | 1     | 0     | 0     |         | 0   | 0     | 1     | 0     | 0     | 4       |
|            | 0   | 0     | 1     | 0     | 1     |         | 0   | 0     | 1     | 0     | 1     | 5       |
|            | 0   | 0     | 1     | 1     | 0     |         | 0   | 0     | 1     | 1     | 0     | 6       |
|            | 0   | 0     | 1     | 1     | 1     |         | 0   | 0     | 1     | 1     | 1     | 7       |
|            | 0   | 1     | 0     | 0     | 0     |         | 0   | 1     | 0     | 0     | 0     | 8       |
|            | 0   | 1     | 0     | 0     | 1     |         | 0   | 1     | 0     | 0     | 1     | 9       |
|            |     |       |       |       |       |         |     |       |       |       |       |         |
|            | 0   | 1     | 0     | 1     | 0     |         | 1   | 0     | 0     | 0     | 0     | 10      |
|            | 0   | 1     | 0     | 1     | 1     |         | 1   | 0     | 0     | 0     | 1     | 11      |
|            | 0   | 1     | 1     | 0     | 0     |         | 1   | 0     | 0     | 1     | 0     | 12      |
|            | 0   | 1     | 1     | 0     | 1     |         | 1   | 0     | 0     | 1     | 1     | 13      |
|            | 0   | 1     | 1     | 1     | 0     |         | 1   | 0     | 1     | 0     | 0     | 14      |
|            | 0   | 1     | 1     | 1     | 1     |         | 1   | 0     | 1     | 0     | 1     | 15      |
|            | 1   | 0     | 0     | 0     | 0     |         | 1   | 0     | 1     | 1     | 0     | 16      |
|            | 1   | 0     | 0     | 0     | 1     |         | 1   | 0     | 1     | 1     | 1     | 17      |
|            | 1   | 0     | 0     | 1     | 0     |         | 1   | 1     | 0     | 0     | 0     | 18      |
|            | 1   | 0     | 0     | 1     | 1     |         | 1   | 1     | 0     | 0     | 1     | 19      | 



---

# Reference

Digital Design, 6th edition

---

# Note

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.