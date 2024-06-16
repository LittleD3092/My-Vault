Tag: #statistics 
Previous: [[Hypothesis Testing]]
Link: 

---

# Null Hypothesis

For a binomial distribution, the null hypothesis is: (<u>1</u>)

$$
H_0: p = p_0
$$

- $p$: The actual proportion of "success".
- $p_0$: The proportion that we are testing.

# Test Statistic

The test statistic can be written as: (<u>1</u>)

$$
z = \frac{\hat p - p_0}{
	\sqrt{
		\displaystyle
		\frac{p_0(1 - p_0)}{n}
	}
}
$$

- $\hat p$: The proportion obtained by experiment.
- $p_0$: The proportion from the null hypothesis.
- $n$: The sample size of the experiment performed.

> The above condition holds only if: (<u>1</u>)
> $$np_0 \geq 15 \text{ and } nq_0 \geq 15$$
> Where $n$ is sample size, $p_0$ is the proportion from the null hypothesis, and $q_0$ is $1 - p_0$.

# Rejection Criteria

Depending on the alternative hypothesis, there are different rejection criteria:

| Alternative Hypothesis | Rejection Criterion                                                                      |
| ---------------------- | ---------------------------------------------------------------------------------------- |
| $$H_1: p\neq p_0$$     | $$\begin{array}{}z_0 > z_{\alpha / 2} \\ \text{or} \\ z_0 < -z_{\alpha / 2}\end{array}$$ |
| $$H_1: p > p_0$$       | $$z_0 > z_\alpha$$                                                                       |
| $$H_1: p < p_0$$       | $$z_0 < -z_\alpha$$                                                                      |

---

# Reference

1. Tseng, Yi-Ju. “Statistics, Chapter 4: Decision Making for a Single Sample.” n.d. Accessed April 17, 2024.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.