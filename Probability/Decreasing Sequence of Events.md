Tag: #probability 
Previous: [[Continuity of Probability Function]]
Link: 

---

We say that a sequence of events $E_1, E_2, \dots$ is decreasing if:

$$
E_1 \supseteq E_2 \supseteq \dots \supseteq E_n \supseteq E_{n + 1} \supseteq \dots
$$

# Proof that Probability Function is Continuous

We want to prove the following:

> For any **decreasing** sequence of events $E_1, E_2, \dots$, we have:
> $$\lim_{n \rightarrow \infty} P(E_n) = P(\lim_{n \rightarrow \infty} E_n)$$

---

Proof of decreasing sequence of events is a little bit different than the [[Increasing Sequence of Events]]. We use complement to help us use axiom 3.

$$E_1^c \subseteq E_2^c \subseteq \dots \subseteq E_n^c \subseteq E_{n + 1}^c \subseteq \dots$$

And by the proof of [[Increasing Sequence of Events]], we can write:

$$
\begin{array}{rrl}
	& \displaystyle \lim_{n \rightarrow \infty} P(E_n^c) &=& \displaystyle P(\lim_{n \rightarrow \infty} E_n^c) \\
	\implies & \displaystyle \lim_{n_\rightarrow \infty} (1 - P(E_n)) &=& \displaystyle 1 - P(\lim_{n \rightarrow \infty} E_n) \\
	\implies & \displaystyle \lim_{n \rightarrow \infty} P(E_n) &=& \displaystyle P(\lim_{n \rightarrow \infty} E_n)
\end{array}
$$

---

# Reference

1. Hsieh, Ping-Chun. “515512: Probability Lecture 3 - Continuity of Probability Function and Conditional Probability.” NYCU EC016, September 11, 2024.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.