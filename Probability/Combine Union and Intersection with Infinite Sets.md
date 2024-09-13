Tag: #probability 
Previous: [[Probability]]
Link: 

---

When using intersection and union in different order, they have different meaning.

$$
\begin{array}{l}
	\displaystyle \bigcap_{k = 1}^\infty \bigcup_{n = k}^\infty S_n &=& \{x \in \Omega : x \text{ appears in infinitely many } S_n\}\\
	\displaystyle \bigcup_{k = 1}^\infty \bigcap_{n = k}^\infty S_n &=& \{x \in \Omega : x \text{ appears in all } S_n \\
	&&\text{ except finitely many } S_n\}
\end{array}
$$

# Proof for x Appears in All Sn Except Finitely Many Sn

$$
\begin{array}{l}
	\displaystyle \bigcup_{k = 1}^\infty \bigcap_{n = k}^\infty S_n &=& \{x \in S_k \text{, except for finitely many } k\}
\end{array}
$$

First, we assume that the right side is $A$.

We can proof that:

$$
\begin{array}{}
	\displaystyle\bigcup_{k = 1}^\infty \bigcap_{n = k}^\infty S_n \subseteq A && \text{and} \\
	\displaystyle A \subseteq \bigcup_{k = 1}^\infty \bigcap_{n = k}^\infty S_n
\end{array}
$$

to say that the left side and the right side are equal.

---

Proof:

$$\displaystyle\bigcup_{k = 1}^\infty \bigcap_{n = k}^\infty S_n \subseteq A$$

We pick any $x$ that:

$$x \in \displaystyle\bigcup_{k = 1}^\infty \bigcap_{n = k}^\infty S_n$$

For any $x$ we pick, there must exist some $k_0 \in \mathbb N$ such that

$$x\in \bigcap_{n = k_0}^\infty S_n$$

Therefore, $x \in A$.

---

Proof:

$$
\displaystyle A \subseteq \bigcup_{k = 1}^\infty \bigcap_{n = k}^\infty S_n
$$

We pick any $y\in A$, and by the definition of $A$ we can see that $y$ appears in all except finitely many $S_n$.

There must exist $m \in \mathbb N$ such that:

$$
\begin{array}{l}
	&& y \in S_m, S_{m + 1}, S_{m + 2}, \dots \\
	\implies && \displaystyle y\in \bigcup_{k = 1}^\infty \bigcap_{n = k}^\infty S_n
\end{array}$$

---

# Reference

1. P.-C. Hsieh, “Lecture 1 - Probability Model,” NYCU EC016, Sep. 05, 2024.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.