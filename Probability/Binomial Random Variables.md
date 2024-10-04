Tag: #probability 
Previous: [[Discrete Random Variables]]
Link: 

---

A random variable $X$ is Binomial with parameters $(n, p)$ if its [[Probability Mass Function]] is given by:

$$
P(X = k) = 
\left\{
	\begin{array}{l}
		C^n_k p^k (1 - p)^{n - k} & \text{if } k = 0, 1, 2, \dots, n \\
		0 & \text{otherwise}
	\end{array}
\right.
$$

# Example

## 1. PMF of Binomial Random Variable

Play the same claw machine for 5 times, and each trial is successful with probability 0.7. All trials are independent. We define a random variable $X$ which is the number of toys we get. What is the probability mass function of $X$?

---

$$
\begin{array}{l}
	& \left\{
		\begin{array}{l}
			P(X = 0) &=& (0.3)^5 \\
			P(X = 1) &=& C^5_1(0.7)(0.4)^4 \\
			P(X = 2) &=& C^5_2(0.7)^2(0.3)^3 \\
			P(X = 3) &=& C^5_3(0.7)^3(0.3)^2 \\
			P(X = 4) &=& C^5_4(0.7)^4(0.3) \\
			P(X = 5) &=& (0.7)^5
		\end{array}
	\right. \\
	\implies & P(X = k) = \left\{
		\begin{array}{l}
			C^5_k(0.7)^k(0.3)^{5 - k} & \text{if } k = 0, 1, 2, 3, 4, 5 \\
			0 & \text{otherwise}
		\end{array}
	\right.
\end{array}
$$

## 2. Maximum Probability of Binomial Random Variable

Let $p$ be the probability that a random person likes coriander. Suppose we randomly sample $N$ prople and define a random variable $X$ which is the number of people who like coriander. For a fixed integer $k$, what is the value of $p$ that maximizes $P(X = k)$?

---

We can see that $X$ is a Binomial random variable.

$$
X \sim \text{Binomial}(N, p)
$$

Therefore, the probability mass function of $X$ is:

$$
P(X = k) = C^N_k p^k (1 - p)^{N - k}
$$

If we fix an integer $k \in [0, N]$, we can treat $P(X = k)$ as a function of $p$:

$$
f(p) = C^N_k p^k (1 - p)^{N - k}
$$

By using derivative, we can find the maximum value of $f(p)$.

$$
\begin{array}{l}
	& \ln f(p) = \ln C^N_k + k \ln p + (N - k) \ln (1 - p) \\
	\implies & \displaystyle \frac{d}{dp} \ln f(p) = \frac{k}{p} - \frac{N - k}{1 - p} = 0 \\
	\implies & \displaystyle \frac{k}{p} = \frac{N - k}{1 - p} \\
	\implies & k(1 - p) = p(N - k) \\
	\implies & k - kp = pN - kp \\
	\implies & k = pN \\
	\implies & p = \displaystyle \frac{k}{N}
\end{array}
$$

---

# Reference

1. Hsieh, Ping-Chun. “515512: Probability Lecture 6 - Random Variables.” NYCU EC016, September 25, 2024.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.