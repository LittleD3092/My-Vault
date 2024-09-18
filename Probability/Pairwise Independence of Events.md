Tag: #probability 
Previous: [[Probability]]
Link: 

---

Two events are independent if:

$$
P(A\cap B) = P(A)P(B)
$$

Also, the above can be written as:

$$
P(A \vert B) = P(A)
$$

- [[Independence of Multiple Events]]
- [[Conditional Independence]]

# Example

## 1. A and complement B are independent

If $A$ and $B$ are independent, then are $A$ and $B^c$ also independent?

---

Using a Venn diagram, we can see that:

![[Pasted image 20240918150709.png|300]]

$$
\begin{array}{l}
	P(A \cap B^c) &=& P(A) - P(A \cap B) \\
	&=& P(A) - P(A)P(B) \\
	&=& P(A)(1 - P(B)) \\
	&=& P(A) P(B^c)
\end{array}
$$

And therefore $A$ and $B^c$ are independent too.

---

# Reference

1. Hsieh, Ping-Chun. “515512: Probability Lecture 5 - Conditional Probability, Combinatorics, and Random Variables.” NYCU EC016, September 18, 2024.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.