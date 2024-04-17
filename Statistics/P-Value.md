Tag: #statistics 
Previous: [[Statistical Hypotheses]]
Link: 

---

The P-value is the probability that the observed data is consistent with the null hypotheses. (<u>1</u>)

![[Pasted image 20240417233954.png|500]]

# Example

> Does an average box of cereal contain $368 \text{ g}$ of cereal? A random sample of $25$ boxes showed $x = 372.5 \text{ g}$ and the standard deviation is $\sigma = 15 \text{ g}$. Find the p-value.

Null hypothesis $H_0$: $\mu = 368 \text{ g}$

Assume that the cereal in the boxes follows normal distribution.

$$
\begin{array}{l}
\text{p-value} &=& 2P(X < 368) \\
&=& \displaystyle
2P\left(
	Z < \frac{368 - 372.5}{15 / \sqrt{25}}
\right) \\
&=& 2P(Z < -1.5)
\end{array}
$$

---

# Reference

1. Tseng, Yi-Ju. “Statistics, Chapter 4: Decision Making for a Single Sample.” n.d. Accessed April 17, 2024.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.