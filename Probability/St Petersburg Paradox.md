Tag: #probability 
Previous: [[Expected Value]]
Link: 

---

St. Petersburg Paradox is a game that the expected value is infinite, but actually winning the game is hard.

# Example

We are asked to pay 10000 dollars to play a game.

- We can keep flipping a fair coin until a head is observed.
- If the 1st head occurs at $n$-th toss, then we get a prize of $2^n$ dollars and the game is over.
- Shall we play this game?

---

$X:=$ the prize that we win

The possible values of $X$ are $2^1, 2^2, 2^3, \ldots$, we assume this as a set $S$.

So the PMF of $X$ is:

$$
P(X = k) = \left\{
    \begin{array}{ll}
        \displaystyle\left(\frac 1 2 \right)^k, \text{ if } k = 2^1, 2^2, 2^3, \ldots \\
        0, \text{ otherwise}
    \end{array}
\right.
$$

And the expected value is:

$$
\begin{array}{ll}
    E[X] &=& \displaystyle \sum_{k \in S} k \cdot P(X = k) \\
    &=& \displaystyle \sum_{n = 1}^{\infty} 2^n \cdot \left(\frac 1 2 \right)^n \\
    &=& \displaystyle \sum_{n = 1}^{\infty} 1 \\
    &=& \infty
\end{array}
$$

We can see that the expected value is infinite, but winning the game is hard.

---

# Reference

1. P.-C. Hsieh, “515512: Probability Lecture 9 - Discrete Random Variables, Entropy, and Expected Value,” NYCU EC016, Oct. 09, 2024.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.