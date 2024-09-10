Tag: #probability 
Previous: [[Probability]]
Link: 

---

A probability assignment is valid if:

1. **Non-negativity**: $P(A) \geq 0$, for any event $A$.
2. **Total probability** $=1$: $P(\Omega) = 1$
3. If $A_1, A_2, \dots$ is an infinite sequence of mutually exclusive events, then $$P(\bigcup_{i = 1}^\infty A_i) = \sum_{i = 1}^\infty P(A_i)$$

# Some Properties Derived from Axioms

## 1. $P(\varnothing) = 0$

We can assume an infinite sequence:

$$
\begin{array}{}
	A_1 = \Omega \\
	A_2 = \varnothing \\
	A_3 = \varnothing \\
	\vdots
\end{array}
$$

Then by axiom 3:

$$
\begin{array}{l}
	&\displaystyle P(\bigcup_{i = 1}^\infty A_i) &=& \displaystyle \sum_{i = 1}^\infty P(A_i) \\
	&&=& \displaystyle
	P(\Omega) + \sum_{i = 2}^\infty P(\varnothing) \\
	\implies & P(\varnothing) &=& 0
\end{array}
$$

## 2. $A_1, \dots, A_n$ are disjoint events, then $\displaystyle P(\bigcup_{i = 1}^n A_i) = \sum_{i = 1}^n P(A_i)$

We first construct an infinite sequence of events denoted $A'_1, A'_2, \dots$ like this:

$$
\begin{array}{}
A_1' &=& A_1 \\
A_2' &=& A_2 \\
& \vdots \\
A_n' &=& A_n \\
A_{n + 1}' &=& \varnothing \\
A_{n + 2}' &=& \varnothing \\
& \vdots
\end{array}
$$

Then, by axiom 3, we can write:

$$
\begin{array}{rl}
	\displaystyle P(\bigcup_{i = 1}^\infty A_i') &=& \displaystyle \sum_{i = 1}^\infty P(A_i') \\
	&=& \displaystyle \sum_{i = 1}^n P(A_i) + \sum_{i = n+1}^\infty P(A_i') \\
	&=& \displaystyle\sum_{i = 1}^n P(A_i) + P(\varnothing) \\
	&=& \displaystyle \sum_{i = 1}^n P(A_i)
\end{array}
$$

## 3. $P(A) \leq 1$ for any event $A$

We know that $A$ and $A^c$ are distinct and:

$$A \cup A^c = \Omega$$

And by rule 2 we proved, we can know that:

$$\begin{array}{rrl}
	&A \cup A^c &=& P(A) + P(A^c) \\
	&&=& P(\Omega) \\
	\implies & P(A) + P(A^c) &=& 1
\end{array}$$

Because both $P(A)$ and $P(A^c)$ are $\geq 0$, they must be $\leq 1$.

## 4. $P(A^c) = 1 - P(A)$

We first construct an infinite sequence:

$$
\begin{array}{}
	A_1 &=& A \\
	A_2 &=& A^c \\
	A_3 &=& \varnothing \\
	A_4 &=& \varnothing \\
	&\vdots
\end{array}
$$

By axiom 3, we can get:

$$
\begin{array}{rrl}
	&\displaystyle P(\bigcup_{i = 1}^\infty A_i) &=& \displaystyle \sum_{i = 1}^\infty P(A_i) \\
	\implies & P(\Omega) &=& P(A) + P(A^c) \\
	\implies & P(A) + P(A^c) &=& 1 \\
	\implies & P(A^c) &=& 1 - P(A)
\end{array}
$$

## 5. Union Bound

For any events $A_1, A_2, \dots, A_N$, we have:

$$
P(\bigcup_{n = 1}^N A_n) \leq \sum_{n = 1}^N P(A_n)
$$

---

We can prove it using induction.

**First Step**: We can show that $P(A_1 \cup A_2) \leq P(A_1) + P(A_2)$. By using Venn's diagram, we can see that:

$$
\begin{array}{l}
	&P(A_1) + P(A_2) = P(A_1 \cup A_2) + P(A_1 \cap A_2) \\
	\implies &P(A_1) + P(A_2) \geq P(A_1 \cup A_2)
\end{array}$$

**Second Step**: We assume that $\displaystyle P(\bigcup_{n = 1}^N A_n) \leq \sum_{n = 1}^N P(A_n)$ is true for $N = k$.

**Third Step**: We show that $\displaystyle P(\bigcup_{n = 1}^N A_n) \leq \sum_{n = 1}^N P(A_n)$ holds for $N = k + 1$.

$$
\begin{array}{l}
	\displaystyle P(\bigcup_{n = 1}^{k + 1} A_n) &=& \displaystyle P(\bigcup_{n = 1}^k A_n) \cup P(A_{k + 1}) \\
	&\leq& \displaystyle P(\bigcup_{n = 1}^k A_n) + P(A_{k + 1}) & \text{(by first step)}\\
	&\leq& \displaystyle \sum_{n = 1}^{k} P(A_n) + P(A_{k + 1}) & \text{(by second step)} \\
	&=& \displaystyle \sum_{n = 1}^{k + 1} P(A_n)
\end{array}
$$

---

# Reference

1. P.-C. Hsieh, “515512: Probability Lecture 2 - Probability Axioms and Continuity of Probability Function,” NYCU EC016, Sep. 06, 2024.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.