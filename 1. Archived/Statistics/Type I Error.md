Tag: #statistics 
Previous: [[Statistical Hypotheses]]
Link: 

---

| Decision                | $H_0$ is True    | $H_0$ is False                                  |
| ----------------------- | ---------------- | ----------------------------------------------- |
| Accept $H_0$ by default | No error         | [[Type II Error]]                               |
| Reject $H_0$            | [[Type I Error]] | No error ([[Power of Statistical Test\|Power]]) |

Type I error is the error when reject the default hypotheses $H_0$ but it is true. (<u>1</u>)

- Type I error is denoted by $\alpha$.

# Example

> The heat evolved in calories per gram of a cement mixture is approximately normally distributed. The standard deviation $\sigma = 2$.
> We with to test $H_0: \mu = 80$ and $H_a: \mu \neq 80$ with a sample of $n = 9$ specimens.
> If the rejection region is defined as $\bar x < 78.5$ or $\bar x > 81.5$, find the type I error probability $\alpha$.

$$\begin{array}{l}
	\alpha &=& P(\bar X < 78.5 \text{ when } \mu = 80) + P(\bar X > 81.5 \text{ when } \mu = 80) \\
	&=& \displaystyle P\left(
		Z < \frac{78.5 - 80}{\sigma / \sqrt n}
	\right) + P\left(
		Z > \frac{81.5 - 80}{\sigma / \sqrt n} \\
	\right) \\
	&=& P(Z < -2.25) + P(Z > 2.25)
\end{array}$$

- Note that $\sigma / \sqrt n$ is the [[Standard Error]].
- The exact value can be obtained using a normal distribution table.

---

# Reference

1. Tseng, Yi-Ju. “Statistics, Chapter 4: Decision Making for a Single Sample.” n.d. Accessed April 17, 2024.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.