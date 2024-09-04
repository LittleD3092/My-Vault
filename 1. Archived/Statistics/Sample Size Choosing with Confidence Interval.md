Tag: #statistics 
Previous: [[Statistics]]
Link: 

---

To choose a sample size such that we have a confidence level of $100(1 - \alpha)$ that the error $\vert (\bar x_1 - \bar x_2) - (\mu_1 - \mu_2) \vert$ will not exceed a specified amount $E$:

$$
n = \left(
	\frac{z_{\alpha / 2}}{E}
\right)^2 (\sigma_1^2 + \sigma_2^2)
$$

> Recall that the confidence interval for two samples is:
> $$\bar x_1 - \bar x_2 - z_{\alpha / 2} \sqrt{ \frac{\sigma_1^2}{n_1} + \frac{\sigma_2^2}{n_2}} \leq \mu_1 - \mu_2 \leq \bar x_1 - \bar x_2 + z_{\alpha / 2} \sqrt{\frac{\sigma_1^2}{n_1} + \frac{\sigma_2^2}{n_2}}$$
> And the error $E$ on the above equation is:
> $$E = z_{\alpha / 2} \sqrt{\frac{\sigma^2_1}{n_1} + \frac{\sigma^2_2}{n_2}}$$

---

# Reference

1. Tseng, Yi-Ju. “Statistics, Chapter 5: Decision Making for Two Samples.” n.d. Accessed June 5, 2024.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.