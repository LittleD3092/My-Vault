Tag: #Database 
Previous: [[Decomposition Of Unnormalized Table]]
Link: 

[TOC]

---

If we decompose an unnormalized table, there might be data loss. For example: (<u>1</u>)

$$
\begin{array}{rl}
	\rm unnormalized\ table:& \rm employee(\underline{ID}, name, street, city, salary) \\
	\rm decomposed\ table: & 
	\left\{
		\begin{array}{l}
			\rm employee1(\underline{ID}, name) \\
			\rm employee2(name, street, city, salary)
		\end{array}
	\right.
\end{array}
$$

In the above example, if we have employees that have the same name, problems appear: (<u>1</u>)

![[Pasted image 20231103151040.png]]

---

# Reference

1. Tseng, Yi-Ju. “Introduction to Database Systems, Chapter 7: Normalization.” NYCU ED117[GF], November 2, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.