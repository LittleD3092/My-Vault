Tag: #digital-design 
Previous: [[Digital Design]]
Link: 

[TOC]

---

- Subtraction $A - B$ can be computed by taking [[2's Complement]] of $B$ and use [[Adder]] to add it.
- Recall that to convert a number to [[2's Complement]]:
	1. Take [[1's Complement]] (by inverter).
	2. Adding 1 to the least significant bit.

The implementation below combines [[Adder]] and subtractor.

- $M$: Mode input. The circuit act as subtractor if $M$ is 1, and act as [[Adder]] if $M$ is 0.
- [[Exclusive OR]] gate: Act as inverter if $M = 1$, and act as a buffer if $M = 0$.
- $C_0$: When subtracting, $C_0$ requires a 1 to produce [[2's Complement]]. Its value comes from $M$.
- $V$: For detecting overflow. If $V = 1$, the result contains $n + 1$ bits ($n$ bits + carry).
- Note that the circuit works for both **signed** and **unsigned** numbers.

![[Pasted image 20230424182949.png]]

---

# Reference

Digital Design, 6th edition

---

# Note

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.