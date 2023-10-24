Tag: #Database 
Previous: [[Relational Algebra]]
Link: 

[TOC]

---

Union operation allow us to **combine** two relations. It can be written as:

$$r \cup s$$

- $r$: Relation 1.
- $s$: Relation 2.

Two relations $r$ and $s$ must have the same **arity** (same number of attributes). Also, the attribute domains must be compatible (they are of same type).

# Example

To find al the courses taught in the **Fall 2017 semester**, or in the **Spring 2018 semester**, or in both:

$$
\begin{array}{}
	\Pi_{
		\text{course\_id}
	}(\sigma_{
		\text{semester} = \text{"Fall"} \cup
		\text{year} = \text{2017}
	}(\text{section})) \cup \\
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