Tag: #probability 
Previous: [[Probability Function]]
Link: 

---

Conditional probability can be denoted as:

$$P(A \vert B)$$

The above can be calculated as:

$$
P(A\vert B) = \frac{P(A\cap B)}{P(B)}
$$

- Tools for conditional probability:
	- [[Multiplication Rule]]
	- [[Total Probability Theorem]]
	- [[Bayes Rule (Probability)]]

# Theorem from [[Probability Axioms]]

Conditional probability also follows [[Probability Axioms]].

1. $P(A \vert B) \geq 0$, for any event $A$.
2. $P(\Omega \vert B) = 1$
3. If $A_1, A_2, \dots$ is an infinite sequence of mutually exclusive events, then $$P(\bigcup_{i = 1}^\infty A_i\vert B) = \sum_{i = 1}^\infty P(A_i \vert B)$$

---

# Reference

1. Hsieh, Ping-Chun. “515512: Probability Lecture 3 - Continuity of Probability Function and Conditional Probability.” NYCU EC016, September 11, 2024.
2. Hsieh, Ping-Chun. “515512: Probability Lecture 4 - Conditional Probability.” NYCU EC016, September 13, 2024.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.