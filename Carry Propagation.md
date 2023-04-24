Tag: #digital-design 
Previous: [[Adder]]
Link: 

[TOC]

---

- The [[Full Adder]] of the more significant bit has to wait for the carry from less significant bits. This time is called carry propagation.
- As graph below, in order for $C_i$ to propagate to $C_{i + 1}$, it takes 2 gate propagation time.

![[Pasted image 20230424180846.png]]

- The above graph means that it takes $2n$ gate propagation time for n-bit numbers.

We can use [[Carry Lookahead Logic]] to speedup the carry propagation.

---

# Reference

Digital Design, 6th edition

---

# Note

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.