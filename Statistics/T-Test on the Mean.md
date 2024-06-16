Tag: #statistics 
Previous: [[Hypothesis Testing on the Mean]]
Link: 

---

# Null Hypothesis

The null hypothesis of T-test is: (<u>1</u>)

$$
H_0: \mu = \mu_0
$$

# Test Statistic

The test statistic of T-test is: (<u>1</u>)

$$
T_0 = \frac{\bar X - \mu_0}{\displaystyle\frac{S}{\sqrt n}}
$$

- $\bar X$: The mean obtained from experiment.
- $\mu_0$: The mean from the null hypothesis.
- $S$: Standard deviation from experiment.
- $n$: Sample size of the experiment.

# Rejection Criteria

We can decide whether to reject the null hypothesis by the test statistics: (<u>1</u>)

| Alternative Hypotheses  | Rejection Criterion                                                      |
| ----------------------- | ------------------------------------------------------------------------ |
| $$H_1: \mu \neq \mu_0$$ | $$t_0 > t_{\alpha / 2, n - 1} \text{ or } t_0 < -t_{\alpha / 2, n - 1}$$ |
| $$H_1: \mu > \mu_0$$    | $$t_0 > t_{\alpha, n - 1}$$                                              |
| $$H_1: \mu < \mu_0$$    | $$t_0 < -t_{\alpha, n - 1}$$                                             |

---

# Reference

1. Tseng, Yi-Ju. “Statistics, Chapter 4: Decision Making for a Single Sample.” n.d. Accessed April 17, 2024.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.