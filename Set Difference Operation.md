Tag: #Database 
Previous: [[Relational Algebra]]
Link: 

[TOC]

---

Set difference operation lets us find tuples that are **in one relation, but not in the other**.

$$r - s$$

- $r, s$: Relations that have same **arity** and compatible.

# Example

To find all courses taught in the **Fall 2017 semester**, but not in the **Spring 2018 semester**, we can write:

$$
\begin{array}{}
	\Pi_{
		\text{course\_id}
	}(\sigma_{
		\text{semester} = \text{"Fall"} \cup
		\text{year} = \text{2017}
	}(\text{section})) - \\
	\Pi_{
		\text{course\_id}
	}(\sigma_{
		\text{semester} = \text{"Spring"} \cup
		\text{year} = \text{2018}
	}(\text{section}))
\end{array}
$$

---

# Reference

- Tseng, Yi-Ju. “Chapter 2: Introduction to Relational Model.” NYCU ED117[GF], October 12, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.