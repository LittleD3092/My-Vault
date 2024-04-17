Tag: #statistics 
Previous: [[Point Estimation]]
Link: 

---

The mean square error of a [[Point Estimation]] is defined as the following: (<u>1</u>)

$$
\begin{array}{l}
	{\rm MSE}(\hat\theta) &=& E[(\hat\theta - \theta)^2] \\
	&=& {\rm Var}(\hat\theta) + [{\rm Bias}(\hat \theta)]^2
\end{array}
$$

# Example

> Suppose there are 3 estimators $\hat\Theta_1, \hat\Theta_2, \hat\Theta_3$. We know that $E(\hat\Theta_1) = E(\hat\Theta_2) = \theta$, $E(\hat\Theta_3) \neq \theta$. Also $V(\hat \Theta_1) = 16, V(\hat \Theta_2) = 11, E(\hat\Theta_3 - \theta)^2 = 6$. Compare those estimators and determine which one is the best.

$$
\begin{array}{l}
	{\rm MSE}(\hat \Theta_1) &=& {\rm Var(\hat\Theta_1)} + [{\rm Bias}(\hat \Theta_1)^2] &=& 16 + 0 &=& 16 \\
	{\rm MSE}(\hat \Theta_2) &=& {\rm Var(\hat\Theta_2)} + [{\rm Bias}(\hat \Theta_2)^2] &=& 11 + 0 &=& 11 \\
	{\rm MSE(\hat\Theta_3)} &=& E[(\hat\Theta_3 - \Theta)^2] &=& 6
\end{array}
$$

Therefore the best estimator is the third one based on the mean square error.

---

# Reference

1. Tseng, Yi-Ju. “Statistics, Chapter 4: Decision Making for a Single Sample.” n.d. Accessed April 17, 2024.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.