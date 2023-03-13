Tag: #digital-design 
Previous: 
Link: [[Canonical Forms]]

---

[TOC]

---

- [[Canonical Forms]] are basic forms, but not convenient.
	- [[Canonical Forms]] must contain all the variables.
	- These forms are seldom used.
- There are two types of standard forms:
	- Sum of Products
	- Products of Sum

| Sum of Products                      | Products of Sum                  |
| ------------------------------------ | -------------------------------- |
| Contains AND terms                   | Contains OR terms                |
| The terms are OR together            | The terms are AND together       |
| Example: $F_1 = y' + xy + x'yz'$     | Example: $x(y' + z)(x' + y + z)$ |
| Two-level implementation             | Two-level implementation         |
| ![[Pasted image 20230226232200.png]] | ![[Pasted image 20230226232207.png]]                                 |

# Other Two-Level Implementation

Beside [[Sum of Products]], [[Product of Sums]] and all [[NAND]] implementations, there are other kind of implementation. They can be categorized into two categories:

1. [[AND-OR-INVERT Implementation]]
2. [[OR-AND-INVERT Implementation]]

Here is a cheat sheet for these implementations:

![[Pasted image 20230313221025.png]]

---

參考資料:

Digital Design, 6th edition

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.