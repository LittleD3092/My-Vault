Tag: #digital-design 
Previous: [[Karnaugh Maps]]
Link: 

[TOC]

---

# Simplify Boolean Function

To simplify a [[Boolean Function]] into product of sums, we can use a [[Karnaugh Maps|Karnaugh Map]].

## Example

Simplify 

$$F(A, B, C, D) = \sum (0, 1, 2, 5, 8, 9, 10)$$

into product-of-sums form.

---

First we may construct [[Karnaugh Maps|Karnaugh Map]]:

![[Pasted image 20230313205002.png]]

Combining the squares of 0s, we have

$$F' = AB + CD + BD'$$

Complementing each side,

$$F = (A' + B')(C' + D')(B' + D)$$

---

# Reference

電工學課本
Digital Design, 6th edition

---

# Note

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.