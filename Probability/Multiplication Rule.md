Tag: #probability 
Previous: [[Conditional Probability]]
Link: 

---

Assuming that all conditioning events have positive probability, we have multiplication rule:

$$
P(\bigcap_{i = 1}^n A_i) = P(A_1) P(A_2 \vert A_1) \dots P(A_n \vert A_1 \cap A_2\cap \dots \cap A_{n - 1})
$$

# Example

Suppose that 7 good and 2 defective fuses are mixed up. To find the defective ones, we test them one by one. What is the probability that we find both defective fuses in exactly 3 tests?

---

There are two scenarios for finding defective fuses in exactly 3 turns:

$$
\begin{array}{l}
	& P(G,D,D) + P(D,G,D) \\
	= & P(G) P(D\vert G) P(D\vert G,D) + P(D) P(G \vert D) P(D \vert D, G) \\
	= & \displaystyle \frac 7 9 \cdot \frac 2 8 \cdot \frac 1 7 + \frac 2 9 \cdot \frac 7 8 \cdot \frac 1 7 \\
	= & \displaystyle \frac{1}{36} + \frac{1}{36} \\
	= & \displaystyle \frac{1}{18}
\end{array}
$$

---

# Reference

1. Hsieh, Ping-Chun. “515512: Probability Lecture 4 - Conditional Probability.” NYCU EC016, September 13, 2024.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.