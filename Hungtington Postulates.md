Tag: #digital-design
Previous: 
Link: 

---

[TOC]

---

- Defines the formal definition of boolean algebra.

# Hungtington Postulates

Boolean algebra is an algebraic structure defined by a set of elements $B$ with two binary operators $+$ and $\cdot$.

1. *Closure*.
	1. The structure is closed with respect to the operator $+$.
	2. The structure is closed with respect to the operator $\cdot$.
2. *Identity element*.
	1. The element $0$ is an identity element with respect to $+$. $$x + 0 = 0 + x = x$$
	2. The element $1$ is an identity element with respect to $\cdot$. $$x\cdot 1 = 1 \cdot x = x$$
3. *Commutative law*.
	1. The structure is commutative with respect to $+$. $$x + y = y + x$$
	2. The structure is commutative with respect to $\cdot$. $$x \cdot y = y \cdot x$$
4. *Distributive law*.
	1. The operator $\cdot$ is distributive over $+$. $$x \cdot (y + z) = (x \cdot y) + (x \cdot z)$$
	2. The operator $+$ is distributive over $\cdot$. $$x+(y \cdot z) = (x + y) \cdot (x + z)$$
5. *Complement*. For every element $x \in B$, there exists an element $x' \in B$ such that
	1. $x + x' = 1$
	2. $x \cdot x' = 0$
6. There exist at least two elements $x, y \in B$ such that $x \neq y$.

---

參考資料:

Digital Design, 6th edition

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.