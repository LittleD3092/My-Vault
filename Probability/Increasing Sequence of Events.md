Tag: #probability 
Previous: [[Continuity of Probability Function]]
Link: 

---

We say that a sequence of events $E_1, E_2, \dots$ is increasing if:

$$
E_1 \subseteq E_2 \subseteq \dots \subseteq E_n \subseteq E_{n + 1} \subseteq \dots
$$

# Proof that Probability Function is Continuous

We want to prove the following:

> For any **increasing** sequence of events $E_1, E_2, \dots$, we have:
> $$\lim_{n \rightarrow \infty} P(E_n) = P(\lim_{n \rightarrow \infty} E_n)$$

---

We are trying to use [[Probability Axioms]] number 3, so we want mutually exclusive events to start with:

$$
\begin{array}{rl}
	G_1 &=& E_1 \\
	G_2 &=& E_2 - E_1 \\
	G_3 &=& E_3 - E_2 \\
	& \vdots 
\end{array}
$$

We can prove that right hand side can be derived into left hand side:

$$
\begin{array}{rrl}
	RHS &=& \displaystyle P(\lim_{n \rightarrow \infty} E_n) \\
	&=& \displaystyle P(\bigcup_{i = 1}^\infty G_i) \\
	& \implies & \text{using axiom 3} \\
	&=& \displaystyle \sum_{i = 1}^\infty P(G_i) \\
	&=& \displaystyle \lim_{n \rightarrow \infty} \sum_{i = 1}^n P(G_i) \\
	&\implies& \text{using finite additivity} \\
	&=& \displaystyle \lim_{n \rightarrow \infty} P(\bigcup_{i = 1}^n G_i) \\
	&=& \displaystyle \lim_{n \rightarrow \infty} P(E_n)
\end{array}
$$

> We can see from the above proof that **"continuity" is a natural consequence of axiom 3**.

---

# Reference

1. Hsieh, Ping-Chun. “515512: Probability Lecture 3 - Continuity of Probability Function and Conditional Probability.” NYCU EC016, September 11, 2024.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.