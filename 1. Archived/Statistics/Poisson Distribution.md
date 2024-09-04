Tag: #statistics 
Previous: [[Poisson Process]]
Link: 

---

Poisson distribution describes the number of events $x$ in the [[Poisson Process]] interval (the whole unit). It said that the probability $p(x)$ of $x$ events happening in the unit is: (<u>1</u>)

$$
p(x) = \frac{
	\lambda^x e^{-\lambda}
}{
 x!
}
$$

- $p(x)$: The probability of $x$ events happening in an unit.
- $\lambda$: The expected number of events in the unit.

Some examples: (<u>1</u>)

![[Pasted image 20240417204539.png]]

The normal approximation to the Poisson random variable: (<u>1</u>)

$$Z = \frac{X - \lambda}{\sqrt{\lambda}}$$

# Example

> Customers arrive at a rate of $72$ per hour. What is the probability of $4$ customers arriving in $3$ minutes?

$72$ per hour means that there are $1.2$ per hour, and $3.6$ per $3$ minutes.

$$
\begin{array}{l}
	p(x) &=& \displaystyle
	\frac{\lambda^x e^{-\lambda}}{x!} \\
	&=& \displaystyle \frac{
		(3.6)^4 e^{-3.6}
	}{4!} \\
	&=& 0.1912
\end{array}
$$

---

# Reference

1. Tseng, Yi-Ju. “Statistics, Chapter 3: Random Variables and Probability Distributions.” n.d. Accessed April 16, 2024.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.