Tag: #statistics 
Previous: [[Statistical Hypotheses]]
Link: 

---

The sample size formula can help us to determine the sample size based on three things:

- [[Type I Error]] $\alpha$
- [[Type II Error]] $\beta$
- The difference we want to detect $\delta$.

For [[Two-sided Hypotheses]], the formula is defined as: (<u>1</u>)

$$
n = \frac{(z_{\alpha / 2} + z_\beta)^2 \sigma^2}{\delta^2}
$$

- $n$: Sample size.
- $z_{\alpha/2}$: The $z$ value of $\alpha / 2$.
- $z_\beta$: The $z$ value of $\beta$.
- $\sigma$: The standard deviation.
- $\delta$: The difference between the mean of the null hypotheses $\mu_0$ and the mean that we want to detect $\mu$. In short, $\delta = \mu - \mu_0$.

For [[One-sided Hypotheses]], the formula is defined as: (<u>1</u>)

$$
n = \frac{(z_{\alpha} + z_\beta)^2 \sigma^2}{\delta^2}
$$

- $n$: Sample size.
- $z_{\alpha}$: The $z$ value of $\alpha$.
- $z_\beta$: The $z$ value of $\beta$.
- $\sigma$: The standard deviation.
- $\delta$: The difference between the mean of the null hypotheses $\mu_0$ and the mean that we want to detect $\mu$. In short, $\delta = \mu - \mu_0$.

---

# Reference

1. Tseng, Yi-Ju. “Statistics, Chapter 4: Decision Making for a Single Sample.” n.d. Accessed April 17, 2024.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.