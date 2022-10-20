標籤: 

---

[TOC]

---


Transfer function is a property of a [[#Linear System]] that decribe the relationship between input and output.

$$\text{Transfer Function} \triangleq G(s) = 
\left.\frac{ \mathcal{L}(\text{output}) }{ \mathcal{L}(\text{input}) }\right\vert_{\text{zero initial condition}}$$

The $\mathcal L$ represent [[Laplace Transform]].

- Order: The highest power of $s$ in the denominator of the transfer function is called the ==order== of the system.
$$\text{e.g. }G(s) = \frac{5s + 6}{s^2 + 2s + 3}, \text{ order } = 2$$

- Note that transfer function is limited to systems that are described by linear time-invariant [[Differential Equation]]s.
- Note that transfer function is independent of the magnitude & nature of the input function.
- Transfer function can be obtained from differential equations or established experimentally.

# Impulse Response Function

We may do a [[Inverse Laplace Transform]] to the transfer function. What we get is called ==implulse response function==, represented as $g(t)$. 

$$\mathcal{L}^{-1}(G(s)) = g(t)$$

The impulse response function is the response of a linear time-invariant system to a unit impulse input when the initial conditions are zero. This is used as a characteristic of a system.

Let's see why $\mathcal L^{-1}(G(s)) = g(t)$ is a impulse response:

When $x(t)$ is an impulse function


$$s(t) \overset \Delta =
\left\{
	\begin{array}{}
		0 & t \neq 0 \\
		\infty & t = 0
	\end{array}
\right.
\quad\& \quad 
\int_{-\infty}^\infty s(t)dt = 1
$$

Do laplace transform:

$$x(s) = \mathcal L (s(t))$$

$$ = \int_{0^-}^\infty e^{-st}s(t)dt$$

$$ = \int_{0^-}^\infty\delta(t)dt = 1$$

---

$$G(s) = \frac{Y(s)}{X(s)}$$

$$Y(s) = G(s) \cdot X(s)$$

when $x(t) = s(t)$

$$\implies x(s) = 1$$

$$\implies Y(s) = G(s)$$

$$y(t) = \mathcal L^{-1}(Y(s)) = \mathcal L^{-1}(G(s)) = g(t)$$

$\implies g(t)$ is the impulse reponse of the system

# Convolution

In a linear time invariant system, the output response is a convolution of input function and impulse responce of the system.

$$y(t) = \int_0^t g(\tau)x(t - \tau)d\tau$$

---

We can prove the above equation by using [[Inverse Laplace Transform]]:

Because the following is true:

$$
\left\{
\begin{array}{}
	Y(s) & = & G(s) \cdot X(s) \\
	Y(s) & = & \mathcal L(y(t)) \\
	X(s) & = & \mathcal L(x(t)) \\
	G(s) & = & \mathcal L(g(t))
\end{array}
\right.
$$

Therefore we can do a [[Inverse Laplace Transform]] to the first equation and get the following result:

$$y(t) = \int_0^t x(\tau) \cdot g(t - \tau)d\tau$$

$$ = \int_0^t g(\tau) x(t - \tau)d\tau$$

where $g(t), x(t) = 0$ for $t < 0$

$\implies$ In a LTI system, the output response is a convolution of input function and impulse response of the system.

---

參考資料:

Automatic Control class
Modern Control Engineering, 5th edition

---

link:

[[Laplace Transform]]

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.