Tag: #digital-design 
Previous: [[Digital Design]]
Link: 

[TOC]

---

Definition:

- A [[Registers|register]] that goes through a sequence of binary states.
- A special type of [[Registers|register]].

# Johnson Counter

- A $k$-bit [[Ring Counter|ring counter]].
- Circulates a single bit among the flip-flops to provide $k$ states. (Not called Johnson Counter)
- The number of states can be doubled to $2k$ if the shift [[Registers|register]] is connected as a *switch-tail* ring counter, as diagram below. (Called Johnson Counter)
- The circuit is called **Johnson counter** only if it is connected as a *switch-tail ring counter*.

![[Pasted image 20230509163840.png|500]]

The output AND gate is determined by a regular pattern:

- The all-0's state is decoded by taking the complement of leftmost and rightmost flip-flop outputs.
- The all-1's state is decoded by taking the normal outputs from leftmost and rightmost flip-flops.
- All other states are decoded from adjacent `10` or `01` pattern in the sequence. See the chart above.

---

# Reference

Digital Design, 6th edition

---

# Note

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.