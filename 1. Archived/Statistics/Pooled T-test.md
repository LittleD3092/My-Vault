Tag: #statistics 
Previous: [[Hypothesis Testing]]
Link: 

---

# Pooled Estimator

Before we calculate pooled t-test, we must first calculate the pooled estimator. This is the weighted average of the two sample variances: (<u>1</u>)

$$
S_p^2 = \frac{(n_1 - 1)S_1^2 + (n_2 - 1)S_2^2}{n_1 + n_2 - 2}
$$

- $S_p^2$: Pooled estimator.
- $n_1, n_2$: Sample sizes of two samples.
- $S_1, S_2$: Standard deviation of two samples.

# Null Hypothesis

The null hypothesis is the difference between the means. We often use $\Delta_0 = 0$. (<u>1</u>)

$$
H_0: \mu_1 - \mu_2 = \Delta_0
$$

# Test Statistic

The test statistic below has a $t$ distribution with $n_1 + n_2 - 2$ DOF (degrees of freedom). Make sure you look the right table entry of the right DOF.

$$
T = \frac{\bar X_1 - \bar X_2 - (\mu_1 - \mu_2)}{S_p \sqrt{\displaystyle \frac{1}{n_1} + \frac{1}{n_2}}}
$$

You can memorize it like this:

$$
T = \frac{(\text{sample difference}) - (\text{population difference})}{\text{standard error}}
$$

# Rejection Criterion

The rejection criteria:

| Alternative Hypothesis              | Rejection Criteria                                                                                             |
| ----------------------------------- | -------------------------------------------------------------------------------------------------------------- |
| $$H_1: \mu_1 - \mu_2\neq \Delta_0$$ | $$t_0 > t_{\displaystyle\alpha / 2, n_1 + n_2 - 2}$$ or $$t_0 < -t_{\displaystyle \alpha / 2, n_1 + n_2 - 2}$$ |
| $$H_1: \mu_1 - \mu_2 > \Delta_0$$   | $$t_0 > t_{\displaystyle\alpha, n_1 + n_2 - 2}$$                                                               |
| $$H_1: \mu_1 - \mu_2 < \Delta_0$$   | $$t_0 < -t_{\displaystyle\alpha, n_1 + n_2 - 2}$$                                                              |

---

# Reference

1. Tseng, Yi-Ju. “Statistics, Chapter 5: Decision Making for Two Samples.” n.d. Accessed June 5, 2024.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.