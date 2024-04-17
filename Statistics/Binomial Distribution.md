Tag: #statistics 
Previous: [[Statistics]]
Link: 

---

Assume that $X$ is the number of [[Bernoulli Trials|Bernoulli trials]] that result in a success. $X$ will have a binomial distribution. (<u>1</u>)

The [[Probability Mass Function|probability mass function]] of binomial distribution is the following: (<u>1</u>)

$$
f(x) = \left(
	\begin{array}{}
		n \\ x
	\end{array}
\right)p^x (1 - p)^{n - x}
$$

- $n$: The total number of trials.
- $x$: The number of successes.
- $p$: The probability of a success.
- $n - x$: The number of fails.
- $(1 - p)$: The probability of a fail.

The mean and the variance of binomial distribution is: (<u>1</u>)

$$
\begin{array}{}
	\mu &=& np \\
	\sigma^2 &=& np(1 - p)
\end{array}
$$

Normal approximation of the binomial distribution can be useful, for the $n$ might not be included in the table. (<u>1</u>)

$$
Z = \frac{X - np}{\sqrt{np(1 - p)}}
$$

# Example

> There are $n = 50$ bits to be transmitted, and the probability of an error $p = 0.1$. The probability that $2$ or fewer errors occur is?

$$
\begin{array}{l}
	P(X \leq 2) &=& P\left(
		\displaystyle
		\frac{X - 5}{\sqrt{50(0.1)(0.9)}} <
		\frac{2.5 - 5}{\sqrt{50 (0.1) (0.9)}}
	\right) \\
	&=& P(Z < -1.18) \\
	&=& 0.12
\end{array}
$$

---

# Reference

1. Tseng, Yi-Ju. “Statistics, Chapter 3: Random Variables and Probability Distributions.” n.d. Accessed April 16, 2024.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.