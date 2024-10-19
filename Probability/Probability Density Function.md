Tag: #statistics #probability 
Previous: [[Continuous Random Variables]], [[Probability]]
Link: 

---

A probability density function can show the probability distribution of a [[Continuous Random Variables|continuous random variable]]. (<u>1</u>)

![[Pasted image 20240303161734.png|300]]

To calculate the probability of an interval, we can use integral: (<u>1</u>)

$$P(a < X < b) = \int_a^b f(x)dx$$

# Examples

## 1. Axioms of probability for PDF

How do we verify the following in PDF: (<u>2</u>)

1. $P(X \in \mathbb{R}) = 1$.
2. $P(X \in A) \geq 0$, for all $A$.
3. Let $A_1, A_2, \ldots$ be mutually exclusive sets of real numbers, then $\displaystyle P\left(X \in \bigcup_{i\geq 1} A_i\right) = \sum_{i\geq 1} P(X \in A_i)$.

---

The first axiom:

$$P(X \in \mathbb{R}) = \int_{-\infty}^{\infty} f(x)dx = 1$$

The second axiom:

$$P(X \in A) = \int_A f(x)dx \geq 0$$

The third axiom:

$$P\left(X \in \bigcup_{i\geq 1} A_i\right) = \int_{\bigcup_{i\geq 1} A_i} f(x)dx = \sum_{i\geq 1} \int_{A_i} f(x)dx$$

## 2. Example of verifying a PDF

Consider the following PDF: (<u>2</u>)

$$f(x) = \left\{
    \begin{array}{l}
        \displaystyle 
        \frac{1}{2\sqrt{x}}, & \text{if } 0 < x \leq 1, \\
        0, & \text{otherwise}.
    \end{array}
\right.$$

Is $f(x)$ a valid PDF?

---

The first axiom:

$$\begin{array}{rl}
    \displaystyle \int_{-\infty}^{\infty} f(x)dx &=& \displaystyle \int_0^1 \frac{1}{2\sqrt{x}}dx \\
    &=& \left. \sqrt{x} \right|_0^1 \\
    &=& 1.
\end{array}$$

The second axiom:

$$\begin{array}{rl}
    \displaystyle \int_A f(x)dx &=& \displaystyle \int_A \frac{1}{2\sqrt{x}}dx \\
    &\geq& 0.
\end{array}$$

for all $A$.

The third axiom holds automatically by the additivity of integral.

---

# Reference

1. Y.-J. Tseng, “Statistics, Chapter 1: The Role of Statistics,” NYCU ED302, Feb. 29, 2024.
2. Hsieh, Ping-Chun. “515512: Probability Lecture 11 - Moments and Continuous Random Variables.” NYCU EC016, October 16, 2024.


---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.