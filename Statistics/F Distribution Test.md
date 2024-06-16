Tag: #statistics 
Previous: [[Hypothesis Testing]]
Link: 

---

# Null Hypothesis

To test whether the standard deviation is equal, we have the following null hypothesis:

$$
H_0: \sigma_1^2 = \sigma_2^2
$$

# Test Statistic

The test statistic is:

$$
F_0 = \frac{S_1^2}{S_2^2}
$$

# Alternative Hypotheses

| Alternative Hypotheses              | Rejection Criterion                                                                          |
| ----------------------------------- | -------------------------------------------------------------------------------------------- |
| $$H_1: \sigma_1^2 \neq \sigma_2^2$$ | $$f_0 > f_{\alpha / 2, n_1 - 1, n_2 - 1}$$ or $$f_0 < f_{1 - \alpha / 2, n_1 - 1, n_2 - 1}$$ |
| $$H_1: \sigma_1^2 > \sigma_2^2$$    | $$f_0 > f_{\alpha / 2, n_1 - 1, n_2 - 1}$$                                                   |
| $$H_1: \sigma_1^2 < \sigma_2^2$$    | $$f_0 < f_{1 - \alpha / 2, n_1 - 1, n_2 - 1}$$                                               |

---

# Reference

1. Tseng, Yi-Ju. “Statistics, Chapter 5: Decision Making for Two Samples.” n.d. Accessed June 5, 2024.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.