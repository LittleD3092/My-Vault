Tag: #discrete-mathematics 
Previous: [[Proposition]]
Link: 

[TOC]

---

- Formed from logical operators
	- Negation
		- $\neg p$
		- $\bar p$
	- Confunction
		- $p\wedge q$
		- "p and q"
	- Disjuction
		- $p \vee q$
		- "p or q"
		- also called "inclusive or"
	- [[Exclusive OR]]
		- $p \oplus q$
		- "p xor q"
	- Conditional Statement
		- $p \rightarrow q$
		- "if p then q"
		- $p$ is called hypothesis
		- $q$ is called conclusion
		- [[#Conditional Statement]]
	- Biconditional Statement
		- $p \leftrightarrow q$
		- "if and only if"
		- [[#Biconditional Statement]]

# Conditional Statement

| p   | q   | p $\rightarrow$ q |
| --- | --- | ----------------- |
| 1   | 1   | 1                 |
| 1   | 0   | 0                 |
| 0   | 1   | 1                 |
| 0   | 0   | 1                 | 

- Converse: $q \rightarrow p$ is the converse of $p \rightarrow q$
- Contrapositive: The contrapositive of $p \rightarrow q$ is $\neg q \rightarrow \neg p$
	- Contrapositive $\neg q \rightarrow \neg p$ has the same truth value of $p \rightarrow q$
	- Meaning they are **equivalent**
- Inverse: $\neg p \rightarrow \neg q$ is the inverse of $p \rightarrow q$

> When two propositions have the same truth value, they are equivalent.

# Biconditional Statement

Truth table:

| p   | q   | $p \leftrightarrow q$ |
| --- | --- | --------------------- |
| 0   | 0   | 1                     |
| 0   | 1   | 0                     |
| 1   | 0   | 0                     |
| 1   | 1   | 1                     | 

---

參考資料:

Discrete Mathematics and Its Applications, 8th edition

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.