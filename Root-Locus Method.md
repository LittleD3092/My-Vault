標籤: #automatic-control 

---

[TOC]

---

- We may have a system transfer function that has an unknown value $K$:
	- $\displaystyle \frac{s^2 + s + 1}{s^3 + 4s^2 + Ks + 1}$
- We wish to find the characteristic equation.
	- Recall that characteristic equation is $\text{denominator} = 0$.
	- The characteristic equation shows the $s$ value that transfer function blows to $\infty$.
- Finding the roots of the characteristic equation of degree higher than 3 is laborious.
- **Root-locus method** is a simple way to find roots $s$ for the characteristic equation.
	- Root-locus simply pick a lot of $K$ and connect the roots $s$ together.
- The method let us solve two questions:
	1. What value $K$ should I use in my control system?
	2. What is the effect $K$ may cause?

# Meaning of Root-Locus Plot

![[Screenshot from 2022-12-14 21-59-57.png]]

---

參考資料:

Modern Control Engineering, 5th edition

---

link:


---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.