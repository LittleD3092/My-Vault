Tag: #automatic-control 
Previous: 
Link: 

---

[TOC]

---

- [[Root-Locus Method]] and frequency response method complement each other.
- Terms:
	- *Frequency Response*: The steady-state response of a system to a sinusoidal input.
- Advantage:
	- We can use the data measured without deriving the mathematical model.

# Obtaining Steady-State Outputs to Sinusoidal Inputs

Assume a stable, linear, time-invariant system:

![[322310945_721262436014921_8284414598110107962_n.jpg]]

Assume the input signal is

$$x(t) = X\sin \omega t$$

Assume the transfer function $G(s)$ is

$$G(s) = \frac{p(s)}{q(s)} = 
\frac{p(s)}{(s + s_1)(s + s_2)\dots (s + s_n)}$$

Then the output signal in [[Laplace Transform|laplace-transformed form]] is

$$\implies Y(s) = G(s)X(s) = \frac{p(s)}{q(s)}X(s)$$

> $X(s)$: The [[Laplace Transform]] of $x(t)$.
> 
> From the [[Laplace Transform|laplace transform table]], 
> $$X(s) = \frac{\omega X}{s^2 + \omega^2}$$

Substituting $X(s)$ for $Y(s)$:

$$\implies Y(s) = G(s)X(s) = G(s)\frac{\omega X}{s^2 + \omega^2}$$

---

參考資料:

Modern Control Engineering, 5th edition

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.