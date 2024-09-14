Tag: #probability 
Previous: [[Conditional Probability]]
Link: 

---

If $A_1, A_2, \dots, A_n$ are mutually exclusive events that form a **partition** of $\Omega$, and $P(A_i) > 0$, for all $i$. Then, for any event $B$, we can write $P(B)$ as the sum of each piece in each partition $A_i$:

$$
\begin{array}{l}
	P(B) & = & P(A_1\cap B) + \dots + P(A_n \cap B) \\
	&=& P(A_1) P(B \vert A_1) + \dots + P(A_n) P(B\vert A_n)
\end{array}
$$

> The **partitions** mentioned are defined as:
> $$\left\{ \begin{array}{l} 1. & A_1, A_2, \dots, A_n \text{ are mutually exclusive.} \\ 2. & A_1\cup A_2 \cup \dots \cup A_n = \Omega \end{array} \right.$$

# Example

Suppose we have a image classifier,

- Each input image is either a dog/cat/bird with probability $$P(\text{dog}) = P(\text{cat}) = 2\cdot P(\text{bird})$$
- The probability that a dog is misclassified is $0.1$.
- The probability that a cat is misclassified is $0.05$.
- The probability that a bird is misclassified is $0.15$.
- Then what is the probability that an image is correctly classified?

---

Assume that the event of an image being correctly classified is denoted as $E$.\

$$
\begin{array}{l}
	P(E) &=& P(\text{dog} \cap E) + P(\text{cat} \cap E) + P(\text{bird} \cap E) \\
	&=& P(\text{dog}) \cdot P(E \vert \text{dog}) + P(\text{cat}) \cdot P(E \vert \text{cat}) + P(\text{bird}) \cdot P(E \vert \text{bird}) \\
	&=& 0.4 \cdot 0.9 + 0.4 \cdot 0.95 + 0.2 \cdot 0.85 \\
	&=& 0.36 + 0.38 + 0.17 \\
	&=& 0.91
\end{array}
$$

---

# Reference

1. Hsieh, Ping-Chun. “515512: Probability Lecture 4 - Conditional Probability.” NYCU EC016, September 13, 2024.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.