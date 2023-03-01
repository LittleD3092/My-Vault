Tag: #digital-design 
Previous: 
Link: [[Hungtington Postulates]]

---

[TOC]

---

# Hungtington Postulates

Hungtington postulates are basic rules that define boolean algebra.

[[Hungtington Postulates]]

# Duality

Every algebraic expression remains valid if the operators and identity elements are interchanged.

The duality property is used in [[#Basic Theorems]].

# Basic Theorems

|                                            | a                           | b                         |
| ------------------------------------------ | --------------------------- | ------------------------- |
| [[Hungtington Postulates]] 2               | $x + 0 = x$                 | $x \cdot 1 = x$           |
| [[Hungtington Postulates]] 5               | $x + x' = 1$                | $x \cdot x' = 0$          |
| [[#Theorem 1]]                             | $x + x = x$                 | $x \cdot x = x$           |
| [[#Theorem 2]]                             | $x + 1 = 1$                 | $x \cdot 0 = 0$           |
| [[#Theorem 3]], involution                 | $(x')' = x$                 |                           |
| [[Hungtington Postulates]] 3, commutative  | $x + y = y + x$             | $xy = yx$                 |
| Theorem 4, associative                     | $x + (y + z) = (x + y) + z$ | $x(yz) = (xy)z$           |
| [[Hungtington Postulates]] 4, distributive | $x(y + z) = xy + xz$        | $x + yz = (x + y)(x + z)$ |
| Theorem 5, DeMorgan                        | $(x + y)' = x'y'$           | $(xy)' = x' + y'$         |
| [[#Theorem 6]], absorption                             | $x + xy = x$                | $x(x + y) = x$            |

# Ways of Representing Function

- [[Canonical Forms]]
- [[Karnaugh Maps]]

---

參考資料:

Digital Design, 6th edition

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.