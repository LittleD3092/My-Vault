Tag: #discrete-mathematics #digital-design 
Previous: [[Compound Proposition]]
Link: 

[TOC]

---

# Properties

$$
\begin{array}{l}
	x \oplus y &=& xy' + x'y \\
	x \oplus 0 &=& x \\
	x \oplus 1 &=& x' \\
	x \oplus x &=& 0 \\
	x \oplus x' &=& 1 \\
	x \oplus y' &=& x' \oplus y = (x \oplus y)'
\end{array}
$$

- Multiple-input XOR is known as [[Odd Function]].
	- Output 1 if input has odd number of 1s.

# Circuit Implementation

![[Pasted image 20230329213122.png|400]]

---

# Reference

Digital Design, 6th edition

---

# Note

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.