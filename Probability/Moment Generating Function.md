Tag: #probability 
Previous: [[Probability]]
Link: 

---

For a random variable $X$, define

$$M_X(t) = E[e^{tX}], \qquad t \in \mathbb R$$

If there exists $\delta > 0$ such that $M_X(t) < \infty$ for all $t \in (-\delta, \delta)$, then $M_X(t)$ is called the moment generating function $X$.

# Examples

## 1. Moment generating function of PMF and PDF

1. If $X$ is a discrete random variable with PMF $p_X(x)$, then what is the moment generating function $M_X(t)$?
2. If $X$ is a continuous random variable with PDF $f_X(x)$, then what is the moment generating function $M_X(t)$?

---

By [[Law of the Unconscious Statistician|LOTUS]]:

For discrete random variable:

$$M_X(t) = \sum_x P_X(x) \cdot e^{tx}$$

For continuous random variable:

$$
M_X(t) = \int_{-\infty}^\infty f_X(x)\cdot e^{tx}dx
$$

## 2. MGF of normal random variables

Let random variable $Z \sim \mathcal N (\mu, \sigma^2)$. What is the MGF of $Z$, which is $M_Z(t)$?

---

$$
\begin{array}{rl}
	f_Z(z) &=& \displaystyle
	\frac{1}{\sqrt{2\pi \sigma^2}} \exp\left(
		- \frac{(x - \mu)^2}{2\sigma^2}
	\right) \\
	M_Z(t) &=& E[e^{tz}] \\
	&=& \displaystyle
	\int_{-\infty}^\infty e^{tz} \cdot \frac{1}{\sqrt{2\pi \sigma^2}} \cdot \exp\left(
		-\frac{(z - \mu)^2}{2\sigma^2} 
	\right)dz \\
	&=& \displaystyle
	\int_{-\infty}^\infty \frac{1}{\sqrt{2\pi \sigma^2}} \cdot \exp\left(
		-\frac{z^2 - 2zu + \mu^2 - 2\sigma^2 tz}{2\sigma^2}
	\right)dz \\
	&=& \displaystyle
	\int_{-\infty}^\infty \frac{1}{\sqrt{2\pi \sigma^2}} \cdot \exp\left(
		-\frac{z^2-(2u + 2\sigma^2 t)z + \mu^2}{2\sigma^2}
	\right)dz \\
	&=& \displaystyle 
	\int_{-\infty}^\infty \frac{1}{\sqrt{2\pi \sigma^2}} \exp\left(
		-\frac{(z - (\mu + \sigma^2 t))^2 + \mu^2 - (\mu + \sigma^2 t)^2}{2\sigma^2}
	\right)dz \\
	&=& \displaystyle
	\int_{-\infty}^\infty 
	\underbrace{
		\frac{1}{\sqrt{2\pi \sigma^2}} \cdot \exp
		\left(
			-\frac{(z - (\mu + \sigma^2 t))^2}{2\sigma^2}
		\right)
	}_{\text{PDF of } \mathcal N (\mu + \sigma^2 t, \sigma^2)}
	\exp\left(
		-\frac{\mu^2 - (\mu + \sigma^2 t)^2}{2\sigma^2}
	\right)dz \\
	&=& \displaystyle
	\exp\left(
		-\frac{\mu^2 - (\mu + \sigma^2 t)^2}{2\sigma^2}
	\right) \\
	&=& 
	\displaystyle
	\exp\left(
		-\frac{\mu^2 - (\mu^2 + 2\mu \sigma^2 t + \sigma^4 t^2)}{2\sigma^2}
	\right) \\
	&=& 
	\displaystyle
	\exp\left(
		\mu t + \frac 1 2\sigma^2 t^2
	\right)
\end{array}
$$

---

# Reference

1. Hsieh, Ping-Chun. “515512: Probability Lecture 15 - Joint Distributions and Sum of Independent Random Variables.” NYCU EC016, November 6, 2024.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.