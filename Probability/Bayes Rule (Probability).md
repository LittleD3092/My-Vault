Tag: #probability 
Previous: [[Conditional Probability]]
Link: 

---

If $A_1, A_2, \dots, A_n$ are mutually exclusive events that form a partition of $\Omega$, and $P(A_i) > 0$, for all $i$. Then, for any event $B$, we can say that:

$$
\begin{array}{l}
	P(A_i \vert B) &=& \displaystyle \frac{P(A_i) P(B\vert A_i)}{P(B)} \\
	&=& \displaystyle \frac{P(A_i) P(B \vert A_i)}{P(A_1)P(B \vert A_1) + \dots + P(A_n) P(B \vert A_n)}
\end{array}
$$

# Proof

$$
\begin{array}{l}
	P(A_i \vert B) &=& \displaystyle \frac{P(A_i \cap B)}{P(B)} \\
	&=& \displaystyle \frac{P(B \cap A_i)}{P(B)} \\
	&& \text{We know that } \displaystyle P(B \vert A_i) = \frac{P(B\cap A_i)}{P(A_i)} \\
	&=& \displaystyle \frac{P(B\vert A_i) P(A_i)}{P(B)} \\
	&& \text{By total probability theorem} \\
	&=& \displaystyle \frac{P(A_i) P(B \vert A_i)}{P(A_1) P(B\vert A_1) + \dots + P(A_n)P(B \vert A_n)}
\end{array}
$$

# Example

Bill has a crush on Amy, and Bill wants to ask Amy out to see whether Amy likes him or not.

- $A_1 = \{\text{Amy likes Bill}\},\ A_2 = \text{\{Amy does not like Bill\}}$
- $B = \{\text{Amy looks happy during the date}\}$
- $P(B \vert A_1) = 0.9$, and $P(B\vert A_2) = 0.3$
- Suppose $P(A_1) = 0.5$ and $P(A_2) = 0.5$ 
	- (in reality, if the sample size is big enough, this initial value does not matter)
- What are $P(A_1 \vert B)$ and $P(A_1 \vert B^c)$?

---

$$
\begin{array}{l}
	P(A_1 \vert B) &=& \displaystyle \frac{P(A_1) P(B \vert A_1)}{P(B)} \\
	&=& \displaystyle \frac{P(A_1)P(B \vert A_1)}{P(A_1) P(B \vert A_1) + P(A_2) P(B \vert A_2)} \\
	&=& \displaystyle \frac{0.5 \cdot 0.9}{0.5 \cdot 0.9 + 0.5 \cdot 0.3} \\
	&=& 0.75
\end{array}
$$

Similarly:

$$
\begin{array}{l}
	P(A_1 \vert B^c)
	&=& \displaystyle \frac{P(A_1)P(B^c \vert A_1)}{P(A_1) P(B^c \vert A_1) + P(A_2) P(B^c \vert A_2)} \\
	&=& \displaystyle \frac{0.5 \cdot 0.1}{0.5 \cdot 0.1 + 0.5 \cdot 0.7} \\
	&=& 0.125
\end{array}
$$

---

# Reference

1. Hsieh, Ping-Chun. “515512: Probability Lecture 4 - Conditional Probability.” NYCU EC016, September 13, 2024.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.