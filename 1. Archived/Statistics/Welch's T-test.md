Tag: #statistics 
Previous: [[Hypothesis Testing]]
Link: 

---

# Test Statistics

The test statistic:

$$
T_0^* = 
\frac{\bar X_1 - \bar X_2 - \Delta_0}{\sqrt{\displaystyle\frac{S_1^2}{n_1} + \frac{S_2^2}{n_2}}}
$$

has a $t$ distribution with the degrees of freedom:

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

> The above representation is called Welsh equation.

---

# Reference

1. Tseng, Yi-Ju. “Statistics, Chapter 5: Decision Making for Two Samples.” n.d. Accessed June 5, 2024.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.