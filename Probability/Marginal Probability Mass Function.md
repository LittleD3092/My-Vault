Tag: #probability 
Previous: [[Joint Probability Mass Function]]
Link: 

---

Let $X$ and $Y$ be two discrete random variables defined on the same sample space $\Omega$, and the joint PMF is $p_{XY(x, y)}$. The marginal PMF of $X$ and $Y$ are:

$$
\begin{array}{rl}
	P(X=x) &=& \displaystyle \sum_{y \in S_Y}p_{XY}(x, y) \\
	P(Y=y) &=& \displaystyle \sum_{x \in S_X} p_{XY}(x, y)
\end{array}
$$

where $S_X$ and $S_Y$ are the sets of possible values of $X$ and $Y$.

# Examples

## 1. Calculate Marginal PMF from joint PMF

Let the joint PMF of $X$ and $Y$ be

$$
p_{XY}(x, y) = \left\{
	\begin{array}{rl}
		\displaystyle \frac 1 {25} (x^2 + y^2), & \text{if } x=1, 2, y=0, 1, 2 \\
		0, & \text{otherwise}
	\end{array}
\right.
$$

What is the marginal PMF of $X$ and $Y$?

---

$$
\begin{array}{rl}
	P(X=x) &=& \displaystyle \sum_{y \in S_Y} p_{XY}(x, y) \\
	&=& \displaystyle \frac 1 {25} x^2 + \frac 1 {25} (x^2 + 1) + \frac 1 {25} (x^2 + 4) \\
	&=& \left\{
		\begin{array}{rl}
			\displaystyle \frac{3}{25} x^2 + \frac 1 5 , & \text{if } x=1 \text{ or }2 \\
			0, & \text{otherwise}
		\end{array}
	\right.
\end{array}
$$

Similarly, for $Y$:

$$
\begin{array}{rl}
	P(Y = y) &=& \displaystyle \sum_{x \in S_X} p_{XY}(x, y) \\
	&=& \displaystyle \frac{1}{25}(1+y^2) + \frac{1}{25}(4+y^2) \\
	&=& \left\{
		\begin{array}{rl}
			\displaystyle \frac{2}{25} y^2 + \frac 1 5, & 
			\text{if } y=0, 1, 2 \\
			0, & \text{otherwise}
		\end{array}
	\right.
\end{array}
$$

---

# Reference

1. Hsieh, Ping-Chun. “515512: Probability Lecture 14 - Joint Distributions.” NYCU EC016, November 1, 2024.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.