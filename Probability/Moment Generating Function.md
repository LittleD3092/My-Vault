Tag: #probability 
Previous: [[Probability]]
Link: 

---

# 1. Definition

For a random variable $X$, define

$$M_X(t) = E[e^{tX}], \qquad t \in \mathbb R$$

If there exists $\delta > 0$ such that $M_X(t) < \infty$ for all $t \in (-\delta, \delta)$, then $M_X(t)$ is called the moment generating function $X$. (<u>1</u>)

# 2. Useful properties

Moment generating function is useful because of the three properties it has: (<u>2</u>)

- **Uniqueness Theorem**: Let $X_1$, $X_2$ be two random variables. If $M_{X_1}(t) = M_{X_2}(t)$, then $X_1$ and $X_2$ follow the same distribution. $$P(X_1 \leq u) = P(X_2 \leq u), \qquad \text{for all }u \in \mathbb R$$
- **Sum of 2 Independent Random Variables to Product**: Given two **independent** random variables $X_1, X_2$ with MGFs $M_{X_1}(t), M_{X_2}(t)$, then the MGF of $X_1 + X_2$ is $$M_{X_1 + X_2}(t) = M_{X_1}(t) \cdot M_{X_2}(t)$$
- **Find Moments**: Let $X$ be a random variable with MGF $M_X(t)$. Then, for every $n \in \mathbb N$, we can calculate the moment of $X$ as $$E[X^n] = \left.\frac{d^n}{dt^n} M_X(t)\right\vert_{t = 0}$$

# 3. MGF chart

The following chart shows some common distributions and their corresponding MGF: (<u>2</u>)

| Distribution                                                                              | Moment-generating function \( M_X(t) \)                   |
| ----------------------------------------------------------------------------------------- | --------------------------------------------------------- |
| Discrete $$ \delta_a $$where $a$ is a possible value, and $p$ is the probability of $X=a$ | $$ pe^{ta} $$                                             |
| Bernoulli $$ P(X = 1) = p $$                                                              | $$ 1 - p + p e^t $$                                       |
| Geometric $$ (1 - p)^{k-1} p $$                                                           | $$ \frac{pe^t}{1 - (1-p)e^t}, \; \forall t < -\ln(1-p) $$ |
| Binomial $$ B(n, p) $$                                                                    | $$ (1 - p + pe^t)^n $$                                    |
| Negative Binomial $$ NB(r, p) $$                                                          | $$ \frac{(1 - p)^r}{(1 - pe^t)^r} $$                      |
| Poisson $$ Poisson(\lambda) $$                                                            | $$ e^{\lambda(e^t - 1)} $$                                |
| Uniform (continuous) $$ U(a, b) $$                                                        | $$ \frac{e^{tb} - e^{ta}}{t(b - a)} $$                    |
| Uniform (discrete) $$ DU(a, b) $$                                                         | $$ \frac{e^{at} - e^{(b+1)t}}{(b - a + 1)(1 - e^t)} $$    |
| Laplace $$ L(\mu, b) $$                                                                   | $$ \frac{e^{t\mu}}{1 - b^2t^2}, \; \vert t \vert < 1/b $$ |
| Normal $$ N(\mu, \sigma^2) $$                                                             | $$ e^{t\mu + \frac{1}{2}\sigma^2t^2} $$                   |

# Examples

## 1. Moment generating function of PMF and PDF

1. If $X$ is a discrete random variable with PMF $p_X(x)$, then what is the moment generating function $M_X(t)$?
2. If $X$ is a continuous random variable with PDF $f_X(x)$, then what is the moment generating function $M_X(t)$? (<u>1</u>)

---

By [[Law of the Unconscious Statistician|LOTUS]]:

For discrete random variable:

$$M_X(t) = \sum_x P_X(x) \cdot e^{tx}$$

For continuous random variable:

$$
M_X(t) = \int_{-\infty}^\infty f_X(x)\cdot e^{tx}dx
$$

## 2. MGF of normal random variables

Let random variable $Z \sim \mathcal N (\mu, \sigma^2)$. What is the MGF of $Z$, which is $M_Z(t)$? (<u>1</u>)

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

## 3. Proof of useful properties

Prove the following useful properties: (<u>2</u>)

- **Uniqueness Theorem**: Let $X_1$, $X_2$ be two random variables. If $M_{X_1}(t) = M_{X_2}(t)$, then $X_1$ and $X_2$ follow the same distribution. $$P(X_1 \leq u) = P(X_2 \leq u), \qquad \text{for all }u \in \mathbb R$$
- **Sum of 2 Independent Random Variables to Product**: Given two **independent** random variables $X_1, X_2$ with MGFs $M_{X_1}(t), M_{X_2}(t)$, then the MGF of $X_1 + X_2$ is $$M_{X_1 + X_2}(t) = M_{X_1}(t) \cdot M_{X_2}(t)$$
- **Find Moments**: Let $X$ be a random variable with MGF $M_X(t)$. Then, for every $n \in \mathbb N$, we can calculate the moment of $X$ as $$E[X^n] = \left.\frac{d^n}{dt^n} M_X(t)\right\vert_{t = 0}$$
---

### 3.1. Proof of uniqueness theorem

Proof of **uniqueness theorem**:

First, we expand the MGF of $X_1$ using [[Taylor Series]]:

> [[Taylor Series]]:
> $$e^x = 1 + \frac 1 {1!}x^1 + \frac{1}{2!}x^2 + \dots$$

$$
\begin{array}{rl}
	M_{X_1}(t) &=& E[e^{tX_1}] \\
	&=& E[e^{tX_1(\omega)}] \\
	&=& \displaystyle
	E\left[
		1 + \frac{1}{1!}(t X_1(\omega))^1 +
		\frac{1}{2!}(t X_1(\omega))^2 + \dots
	\right] \\
	&=& \displaystyle
	1 + 
	\underbrace{\frac{t^1}{1!} E[X_1(\omega)]}_{\text{1st moment}} + 
	\underbrace{\frac{t^2}{2!} E[X_1(\omega)^2]}_{\text{2nd moment}} + 
	\underbrace{\frac{t^3}{3!} E[X_1(\omega)^3]}_{\text{3rd moment}} + 
	\dots
\end{array}
$$

Similarly, the MGF of $X_2$ can be expanded too:

$$
M_{X_2}(t) = 1 + \frac{t^1}{1!} E[X_2(\omega)] + \frac{t^2}{2!}E[X_2(\omega)^2] + \dots
$$

For $M_{X_1}(t) = M_{X_2}(t)$, all infinitely many moments must match, meaning that $X_1 = X_2$ because infinitely many constraints are given.

### 3.2. Proof of sum to product

$$
\begin{array}{l}
	M_{X_1 + X_2}(t) &=& E[e^{t(X_1 + X_2)}] \\
	&=& E[e^{tX_1} \cdot e^{tX_2}] \\
	&& \text{By lotus} \\
	&=& \displaystyle
	\sum_{x_1, x_2} P_{X_1X_2}(x_1, x_2) \cdot e^{tX_1} \cdot e^{tX_2} \\
	&& \text{By independence} \\
	&=& \displaystyle
	\sum_{x_1, x_2} P_{X_1}(x_1) P_{X_2}(x_2) e^{tX_1} e^{tX_2} \\
	&=& \displaystyle
	\left(
		\sum_{x_1} P_{X_1}(x_1)e^{tX_1}
	\right)
	\left(
		\sum_{x_2} P_{X_2}(x_2)e^{tX_2}
	\right)
\end{array}
$$

By induction, for any number of random variables, $X_1, X_2, \dots, X_n$, the MGF of sum $X_1 + X_2 + \dots + X_n$ is

$$M_{X_1 + X_2 + \dots + X_n}(t) = \prod_{i = 1}^n M_{X_i}(t)$$

### 3.3. Proof of finding moments

Assume that $X$ is discrete. By writing both the expression of expected value and MGF:

$$
\begin{array}{rl}
	E[X^n] &=& \displaystyle \sum_{\text{all }x} P_X(x) \cdot x^n \\
	M_X(t) &=& E[e^{tX}] \\
	&& \displaystyle \sum_x P_X(x) \cdot e^{tx}
\end{array}
$$

By doing the derivative of MGF:

$$
\begin{array}{rl}
	\displaystyle 
	\left.
		\frac d{dt} M_X(t)
	\right\vert_{t = 0} &=& \left.
		E[e^{tX}] \right\vert_{t = 0} \\
	&=& \displaystyle
	\left.\sum_x P_X(x) \cdot \frac{d}{dt} e^{tx}
	\right\vert_{t = 0} \\
	&=& \displaystyle \left.
		\sum_x P_X(x) x \cdot e^{tx}
	\right\vert_{t = 0} \\
	&=& \displaystyle \sum_x P_X(x) x \\
	&=& E[X]
\end{array}
$$

## 4. Find CDF from MGF

Suppose the MGF of a random variable $X$ is

$$
M_X(t) = \frac 1 6 e^{-2t} + \frac 1 3 e^{-t} + \frac 1 4 e^t + \frac 1 4 e^{2t}
$$

What is $P(\vert X\vert \leq 1)$? (<u>2</u>)

---

By definition of MGF, 

$$M_X(t) = E[e^{tX}]$$

From the form of MGF, we can see that:

1. The fraction $\displaystyle \left( \frac 1 6, \frac 1 3, \frac 1 4, \frac 1 4 \right )$ is the probability.
2. The exponent $(-2, -1, 1, 2)$ are the value of $X$.

So the PMF of $X$ is:

$$
P_X(k) =
\left\{
	\begin{array}{rl}
		\displaystyle 
		\frac 1 6, & \text{if } k = -2 \\
		\displaystyle
		\frac 1 3, & \text{if } k = -1 \\
		\displaystyle
		\frac 1 4, & \text{if } k = 1 \\
		\displaystyle
		\frac 1 4, & \text{if } k = 2 \\
		0, & \text{otherwise}
	\end{array}
\right.
$$

By the uniqueness of MGF, $P_X$ is the unique PMF.

## 5. MGF of special random variables

- If $\displaystyle M_X(t) = \frac 1 2 + \frac 1 2 e^t$, then what kind of random variable is $X$? (<u>2</u>)
- If $\displaystyle M_Z(t) = e^{2t^2 - t}$, then what kind of random variable is $Z$? (<u>2</u>)

---

Using the [[#3. MGF chart]] above, we can see that:

$$
\begin{array}{l}
	\displaystyle X \sim \text{Bernoulli}(\frac 1 2) \\
	\displaystyle Z \sim \text{Normal}(-1, 4)
\end{array}
$$

Also, by the uniqueness theorem, the answer is unique.

## 6. Using sum to product property

Let two independent random variables be $X_1 \sim \mathcal N(\mu_1, \sigma_1^2)$ and $X_2 \sim \mathcal N(\mu_2, \sigma_2^2)$. (<u>2</u>)

- What is the MGF of $X_1 + X_2$? 
- And what is the PDF of $X_1 + X_2$?

---

> [[#3. MGF chart]]:
> For normal random variables,
> $$M_X(t) = e^{\displaystyle t\mu + \frac 1 2 \sigma^2 t^2}$$

Using the sum to product property:

$$
\begin{array}{l}
	\displaystyle M_{X_1 + X_2}(t) &=& M_{X_1}(t) M_{X_2}(t) \\
	&=& \displaystyle e^{\displaystyle t\mu_1 + \frac 1 2 \sigma_1^2 t^2} \cdot e^{\displaystyle t \mu_2 + \frac 1 2 \sigma^2_2 t^2} \\
	&=& e^{\displaystyle (\mu_1 + \mu_2)t + \frac 1 2 (\sigma_1^2 + \sigma_2^2)t^2}
\end{array}
$$

We can see that

$$(X_1 + X_2) \sim \mathcal N(\mu_1 + \mu_2, \sigma_1^2 + \sigma_2^2)$$

> Takeaway: We can get the PDF easily using MGF instead of calculating the convolution.

---

# Reference

1. Hsieh, Ping-Chun. “515512: Probability Lecture 15 - Joint Distributions and Sum of Independent Random Variables.” NYCU EC016, November 6, 2024.
2. Hsieh, Ping-Chun. “515512: Probability Lecture 16 - Moment Generating Functions.” NYCU EC016, November 8, 2024.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.