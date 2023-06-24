Tag: #digital-design 
Previous: [[Logic Gates]]
Link: 

[TOC]

---

- NAND gate is a *universal gate*: Every circuit can be implemented using only NAND gate.

Note that inverter can be implemented by NAND:

![[Pasted image 20230312175941.png|300]]

Other logic gates can also be implemented by NAND:

![[Pasted image 20230312180030.png|400]]

# Two-Level Implementation

To implement using only NAND gate, it requires [[Sum of Products]] form.

1. Process of implement a circuit with only NAND gates (two level):
	1. Simplify function in [[Sum of Products]] form.
	2. Draw a NAND gate for each product terms. This is the first layer.
	3. Draw a single NAND gate as the second layer.
	4. A term with single literal requires an inverter in the first level.
2. Process of implement a multiple layer circuit with only NAND gates:
	1. Convert all [[AND]] to NAND.
	2. Convert all [[OR]] to NAND (but in inverter-OR symbols).
	3. Check all bubbles, for all bubbles that have no bubble to compensate, add an [[Inverter]].

> Note that NAND and inverter-OR are equivalent.

## Example 1

$$F = AB + CD$$

Implement using only NAND gate.

---

![[Pasted image 20230312180231.png|500]]

## Example 2

$$F(x, y, z) = \sum(1, 2, 3, 4, 5, 7)$$

Implement circuit using only NAND gate.

![[Pasted image 20230312180337.png]]

## Example 3

Implement the circuit

$$F = A(CD + B) + BC'$$

![[Pasted image 20230312180828.png]]

## Example 4

Implement the circuit

$$F = (AB' + A' B)(C + D')$$

![[Pasted image 20230312180914.png]]

---

# Reference

Digital Design, 6th edition

---

# Note

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.