Tag: #digital-design 
Previous: 
Link: [[Boolean Algebra]] [[Standard Forms]]

---

[TOC]

---

- Used to represent a boolean function.
- We use [[Standard Forms]] more.
- Include two ways of representation:
	- [[#Minterms]]
	- [[#Maxterms]]

# By Term

![[Pasted image 20230226223035.png]]

$$f_1 = x'y'z + xy'z' + xyz$$

Consulting the table we have the minterms:

$$f_1 = m_1 + m_3 + m_7$$

Note that maxterms is the product of the terms whose number is not included in the minterms:

$$f_1 = M_0M_2M_4M_5M_6$$

---

$$f_2 = x'yz + xy'z + xyz' + xyz$$

Consulting the table we have

$$f_2 = m_3 + m_5 + m_6 + m_7$$

Note that maxterms is the product of the terms whose number is not included in the minterms:

$$f_2 = M_0M_1M_2M_4$$

# By Truth Table

$$f_1 = x'y'z + xy'z' + xyz$$
$$f_2 = x'yz + xy'z + xyz' + xyz$$

Construct the truth table:

| x   | y   | z   | Function $f_1$ | Function $f_2$ |
| --- | --- | --- | -------------- | -------------- |
| 0   | 0   | 0   | 0              | 0              |
| 0   | 0   | 1   | 1              | 0              |
| 0   | 1   | 0   | 0              | 0              |
| 0   | 1   | 1   | 0              | 1              |
| 1   | 0   | 0   | 1              | 0              |
| 1   | 0   | 1   | 0              | 1              |
| 1   | 1   | 0   | 0              | 1              |
| 1   | 1   | 1   | 1              | 1              | 

From the truth table:

- The 0s in the result column represent the maxterms.
- The 1s in the result column represent the minterms.

$$
\begin{array}{l}
	f_1 & = & m_1 + m_4 + m_7 \\
	& = & M_0M_2M_3M_5M_6 \\
	f_2 & = & m_3 + m_5 + m_6 + m_7 \\
	& = & M_0M_1M_2M_4
\end{array}
$$

# Example for Minterms

> Express the Boolean function $F = A + B' C$ as a sum of minterms.

The minterms can be easily derived directly from the truth table:

| A   | B   | C   | F   |
| --- | --- | --- | --- |
| 0   | 0   | 0   | 0   |
| 0   | 0   | 1   | 1   |
| 0   | 1   | 0   | 0   |
| 0   | 1   | 1   | 0   |
| 1   | 0   | 0   | 1   |
| 1   | 0   | 1   | 1   |
| 1   | 1   | 0   | 1   |
| 1   | 1   | 1   | 1   | 

$$F = m_1 + m_4 + m_5 + m_6 + m_7$$

An alternative way is to add the mixing terms:

$$\begin{array}{l}
	A & = & A(B + B')(C + C') \\
	& = & ABC + ABC' + AB'C + AB'C' \\
	B'C & = & (A + A')B'C \\
	& = & AB'C + A'B' C
\end{array}$$

$$\implies A + B'C = ABC + ABC' + AB'C + AB'C' + A'B'C$$

$$\implies F = m_7 + m_6 + m_5 + m_4 + m_1$$

Note that the minterms can also be written using $\sum$.

$$F = \sum(1, 4, 5, 6, 7)$$

# Example for Maxterms

> Express the Boolean function $F = xy + x'z$ as a product of maxterms.

Convert the function into OR terms:

$$
\begin{array}{l}
	F &=& (xy + x')(xy + z) \\
	&=& (x + x')(x' + y)(x + z)(y + z) \\
	&=& (x' + y)(x + z)(y + z) \\
	&=& (x' + y + zz')(x + yy' + z)(xx' + y + z) \\
	&=& (x' + y + z)(x' + y + z')(x + y + z)(x + y' + z)(x + y + z)(x' + y + z) \\
	&=& (x' + y + z)(x' + y + z')(x + y + z)(x + y' + z)
	\end{array}
$$

Convert to maxterms:

$$F = M_4M_5M_0M_2$$

Note that we can use $\prod$ to represent maxterms in a convenient way:

$$F = \prod(0, 2, 4, 5)$$

---

參考資料:

Digital Design, 6th edition

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.