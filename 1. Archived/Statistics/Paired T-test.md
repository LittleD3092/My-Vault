Tag: #statistics 
Previous: [[Hypothesis Testing]]
Link: 

---

# Null Hypothesis

The null hypothesis of paired t-test is:

$$
H_0: \mu_D = \Delta_0
$$

# Test Statistic

The test statistic is:

$$
T_0 = \frac{\bar D - \Delta_0}{\displaystyle \frac{S_D}{\sqrt{n}}}
$$

- $\bar D$: Mean of differences.
- $S_D$: Standard deviation of differences.
- $n$: Sample size.

# Rejection Region

The rejection region is as follows: (<u>1</u>)

| Alternative Hypothesis       | Rejection Region                                                   |
| ---------------------------- | ------------------------------------------------------------------ |
| $$H_1: \mu_D \neq \Delta_0$$ | $$t_0 > t_{\alpha / 2, n - 1}$$or $$t_0 < -t_{\alpha / 2, n - 1}$$ |
| $$H_1: \mu_D > \Delta_0$$    | $$t_0 > t_{\alpha, n - 1}$$                                        |
| $$H_1: \mu_D < \Delta_0$$    | $$t_0 < -t_{\alpha, n - 1}$$                                       |

---

# Reference

1. Tseng, Yi-Ju. “Statistics, Chapter 5: Decision Making for Two Samples.” n.d. Accessed June 5, 2024.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.