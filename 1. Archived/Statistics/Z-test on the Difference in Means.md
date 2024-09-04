Tag: #statistics 
Previous: [[Hypothesis Testing]]
Link: 

---

# Null Hypothesis

The null hypothesis for the z-test on the difference in means is: (<u>1</u>)

$$
H_0: \mu_1 - \mu_2 = \Delta_0
$$

> $\Delta_0$ is often zero, if we want to assume that two distributions are the same.

# Test Statistic

The test statistic for the z-test on the difference in means is: (<u>1</u>)

$$
Z_0 = \frac{\bar X_1 - \bar X_2 - \Delta_0}{
	\displaystyle \sqrt{
		\frac{\sigma_1^2}{n_1} + \frac{\sigma_2^2}{n_2}
	}
}
$$

# Rejection Criterion

We can decide whether to reject the null hypothesis using the rejection criteria below: (<u>1</u>)

| Alternative Hypotheses               | Rejection Criterion                                        |
| ------------------------------------ | ---------------------------------------------------------- |
| $$H_1: \mu_1 - \mu_2 \neq \Delta_0$$ | $$z_0 > z_{\alpha / 2} \text{ or } z_0 < -z_{\alpha / 2}$$ |
| $$H_1: \mu_1 - \mu_2 > \Delta_0$$    | $$z_0 > z_\alpha$$                                         |
| $$H_1: \mu_1 - \mu_2 < \Delta_0$$    | $$z_0 < -z_\alpha$$                                        |

---

# Reference

1. Tseng, Yi-Ju. “Statistics, Chapter 5: Decision Making for Two Samples.” n.d. Accessed June 5, 2024.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.