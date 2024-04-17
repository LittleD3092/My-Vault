Tag: #statistics 
Previous: [[Statistical Hypotheses]]
Link: 

---

| Decision                | $H_0$ is True    | $H_0$ is False                                  |
| ----------------------- | ---------------- | ----------------------------------------------- |
| Accept $H_0$ by default | No error         | [[Type II Error]]                               |
| Reject $H_0$            | [[Type I Error]] | No error ([[Power of Statistical Test\|Power]]) |

Type II error is the error that occurs when accept the default hypotheses $H_0$, but it is false. (<u>1</u>)

- Type II error is denoted by $\beta$.

![[Pasted image 20240418001104.png|250]]

# Example

> The heat evolved in calories per gram of a cement mixture is approximately normally distributed. The standard deviation $\sigma = 2$.
> We with to test $H_0: \mu = 80$ and $H_a: \mu \neq 80$ with a sample of $n = 9$ specimens.
> The rejection region is defined as $\bar x < 78.5$ or $\bar x > 81.5$.
> Find $\beta$ for the case where the true mean heat evolved is $83$.

$$
\begin{array}{l}
	&& P(78.5 < \bar X < 81.5 \text{ when } \mu = 83) \\
	&=& \displaystyle P\left(
		\frac{78.5 - 83}{\sigma / \sqrt n}
		< Z < \frac{81.5 - 83}{\sigma / \sqrt n}
	\right) \\
	&=& P(-6.75 < Z < -2.25) \\
	&=& P(Z < -2.25) - P(Z < -6.75)
\end{array}
$$

- Note that $\sigma / \sqrt n$ is the [[Standard Error]].
- The exact value can be obtained using a normal distribution table.

---

# Reference

1. Tseng, Yi-Ju. “Statistics, Chapter 4: Decision Making for a Single Sample.” n.d. Accessed April 17, 2024.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.