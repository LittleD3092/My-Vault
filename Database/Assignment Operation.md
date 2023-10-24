Tag: #Database 
Previous: [[Relational Algebra]]
Link: 

[TOC]

---

Assignment operation is used to create temporary relations. It can make the code readable.

# Example

To find all instructor in the "**Physics**" and "Music" **department**, we can write:

$$
\begin{array}{l}
	\text{Physics} \leftarrow 
	\sigma_{
		\text{dept\_name} = \text{"Physics"}
	}(\text{instructor}) \\
	\text{Music} \leftarrow
	\sigma_{
		\text{dept\_name} = \text{"Music"}
	}(\text{instructor}) \\
	\text{Physics} \cup \text{Music}
\end{array}
$$

---

# Reference

- Tseng, Yi-Ju. “Chapter 2: Introduction to Relational Model.” NYCU ED117[GF], October 12, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.