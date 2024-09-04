Tag: #statistics 
Previous: [[Normal Distribution]]
Link: 

---

Standard normal random variable $Z$ is useful for looking up the chart. Therefore, we often convert any normal random variable $X$ to $Z$. (<u>1</u>)

If $X$ is a normal random variable with $E(X) = \mu$ and $V(X) = \sigma^2$, we can convert it using: (<u>1</u>)

$$
Z = \frac{X - \mu}{\sigma}
$$

# Example

## Example 1

> What is $P(X \leq x)$? (<u>1</u>)

The probability can be looked up using a chart. However, the chart only includes standard normal random variable $Z$.

$$
\begin{array}{l}
	P(X \leq x) &=& \displaystyle P\left(
		\frac{X - \mu}{\sigma} \leq \frac{x - \mu}{\sigma}
	\right) \\
	&=& P(Z\leq z)
\end{array}
$$

By using the above process, we can now check on the chart with calculated $z$.

## Example 2

> The diameter of a shaft in a storage drive is normally distributed with mean $0.2508$ inch and standard deviation $0.0005$ inch. The specifications on the shaft are $0.2500\pm 0.0015 \ \text{inch}$. What proportion of shafts conforms to specifications? (<u>1</u>)

Let $X$ denote the shaft diameter in inches.

$$X \sim N(0.2508, 0.0005^2)$$

The request probability $P$ is:

$$\begin{array}{l}
P(0.2485 < X < 0.2515) &=& \displaystyle
P\left(
	\frac{0.2485 - 0.2508}{0.0005} < Z <
	\frac{0.2515 - 0.2508}{0.0005}
\right) \\
&=& P(-4.6 < Z < 1.4) \\
&=& P(Z < 1.4) - P(Z < -4.6)
\end{array}$$

We can look up the chart for $P(Z < 1.4)$ and $P(Z < -4.6)$ to calculate the answer.

---

# Reference

1. Tseng, Yi-Ju. “Statistics, Chapter 3: Random Variables and Probability Distributions.” n.d. Accessed April 16, 2024.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.