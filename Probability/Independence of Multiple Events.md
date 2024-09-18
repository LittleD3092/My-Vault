Tag: #probability 
Previous: [[Pairwise Independence of Events]]
Link: 

---

For events that is more than two, they can still be independent.

Events $A_1, A_2, \dots, A_n$ are said to be independent if:

$$
P(\bigcap_{i \in S} A_i) = \prod_{i \in S} P(A_i), \ \text{for every } S \subseteq \{1, 2, \dots, n\}
$$

For example, when $n = 3$, for $A_1, A_2, A_3$ to be independent, we have this:

$$
\left\{
	\begin{array}{rl}
		P(A_1 \cap A_2) &=& P(A_1)P(A_2) \\
		P(A_2 \cap A_3) &=& P(A_2)P(A_3) \\
		P(A_1 \cap A_3) &=& P(A_1)P(A_3) \\
		P(A_1 \cap A_2 \cap A_3) &=& P(A_1) P(A_2) P(A_3)
	\end{array}
\right.
$$

# Example

## 1. Pairwise Independence and Independence

There are pairwise independence and multiple events independence. If there are pairwise independence, it does not mean that there are multiple events independence.

We assign events:

$$
\begin{array}{rl}
	T_1 &=& \{\text{1st toss is a tail}\} \\
	T_2 &=& \{\text{2nd toss is a tail}\} \\
	D &=& \{\text{2 tosses have different results}\}
\end{array}
$$

Calculate the probability specified below:

1. $P(T_1 \cap T_2) = \displaystyle \frac 1 4$
2. $P(D\cap T_1) = \displaystyle \frac 1 4$
3. $P(D \cap T_2) = \displaystyle \frac 1 4$
4. $P(D \cap T_1 \cap T_2) = 0$
5. $P(D \vert T_1 \cap T_2) = 0$

---

# Reference

1. Hsieh, Ping-Chun. “515512: Probability Lecture 5 - Conditional Probability, Combinatorics, and Random Variables.” NYCU EC016, September 18, 2024.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.