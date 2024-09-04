Tag: #statistics 
Previous: [[Statistics]]
Link: 

---

# Z-test (sample size >= 30)

The confidence interval for two samples can be written as: (<u>1</u>)

$$
\bar x_1 - \bar x_2 - z_{\alpha / 2} \sqrt{
	\frac{\sigma_1^2}{n_1} + \frac{\sigma_2^2}{n_2}
} \leq \mu_1 - \mu_2 \leq 
\bar x_1 - \bar x_2 + z_{\alpha / 2} \sqrt{
	\frac{\sigma_1^2}{n_1} + \frac{\sigma_2^2}{n_2}
}
$$

# T-test (sample size < 30, same popular standard deviation)

The confidence interval when the sample size is less than 30:

$$
\begin{array}{l}
	\displaystyle
	\bar x_1 - \bar x_2 - t_{\alpha / 2, n_1 + n_2 - 2} s_p\sqrt{
		\frac{1}{n_1} + \frac{1}{n_2}
	} \\
	\displaystyle
	\leq \mu_1 - \mu_2 \leq 
	\bar x_1 - \bar x_2 + t_{\alpha / 2, n_1 + n_2 - 2} s_p\sqrt{
		\frac{1}{n_1} + \frac{1}{n_2}
	}
\end{array}
$$

where the pooled estimate $s_p$:

$$
S_p^2 = \frac{(n_1 - 1)S_1^2 + (n_2 - 1)S_2^2}{n_1 + n_2 - 2}
$$

- $S_p^2$: Pooled estimator.
- $n_1, n_2$: Sample sizes of two samples.
- $S_1, S_2$: Standard deviation of two samples.

# T-test (sample size < 30, different popular standard deviation)

The confidence interval when the sample size is less than 30, and the popular standard deviation is different:

$$
\bar x_1 - \bar x_2 - t_{\alpha / 2, \nu} \sqrt{\frac{s_1^2}{n_1} + \frac{s_2^2}{n_2}} \leq \mu_1 - \mu_2 \leq \bar x_1 - \bar x_2 + t_{\alpha / 2, \nu} \sqrt{\frac{s_1^2}{n_1} + \frac{s_2^2}{n_2}}
$$

where $\nu$ is derived from Welsh equation:

$$
\nu = \frac{
	\displaystyle\left(
		\frac{S_1^2}{n_1} + \frac{S_2^2}{n_2}
	\right)^2
}{
	\displaystyle
	\frac{
		\left(
			\displaystyle
			\frac{S_1^2}{n_1}
		\right)^2
	}{n_1 - 1} + 
	\displaystyle
	\frac{
		\left(
			\displaystyle
			\frac{S_2^2}{n_2}
		\right)^2
	}{n_2 - 1}
}
$$

> If $\nu$ is not an integer, round down.

# Paired T-test (observations are paired)

The confidence interval for paired t-test is:

$$
\bar d - t_{\alpha / 2, n - 1} \frac{s_d}{\sqrt n} \leq \mu_D \leq \bar d + t_{\alpha / 2, n - 1} \frac{s_d}{\sqrt n}
$$

---

# Reference

1. Tseng, Yi-Ju. “Statistics, Chapter 5: Decision Making for Two Samples.” n.d. Accessed June 5, 2024.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.