Tag: #digital-design 
Previous: [[Adder]]
Link: 

[TOC]

---

- Input: $x, y, z$
- Output: $S, C$ (sum and carry)

We use truth table to derive the expression of output:

| $x$ | $y$ | $z$ | $S$ | $C$ |
| --- | --- | --- | --- | --- |
| 0   | 0   | 0   | 0   | 0   |
| 0   | 0   | 1   | 1   | 0   |
| 0   | 1   | 0   | 1   | 0   |
| 0   | 1   | 1   | 0   | 1   |
| 1   | 0   | 0   | 1   | 0   |
| 1   | 0   | 1   | 0   | 1   |
| 1   | 1   | 0   | 0   | 1   |
| 1   | 1   | 1   | 1   | 1   | 

$$\therefore \begin{array}{l}
	S = x'y'z + x'yz' + xy'z' + xyz \\
	C = xy + xz + yz
\end{array}$$

Note that the full adder can be implemented with two half adders, so one of the possible implementation is:

![[Pasted image 20230424175748.png]]

Another possible implementation is using the sum-of-products.

![[Pasted image 20230424175905.png]]

---

# Reference

Digital Design, 6th edition

---

# Note

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.