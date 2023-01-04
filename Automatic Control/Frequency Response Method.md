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

Substituting $X(s)$:

$$\implies Y(s) = G(s)X(s) = G(s)\frac{\omega X}{s^2 + \omega^2}$$

Substituting $G(s)$:

$$\implies Y(s) = \frac{p(s)\cdot \omega X}{(s + s_1)(s + s_2) \dots (s + s_n) \cdot (s^2 + \omega^2)}$$

Partial fraction expansion:

$$\implies Y(s) = \frac{a}{s + j\omega} + \frac{\bar a}{s - j\omega} + \frac{b_1}{s + s_1} + \frac{b_2}{s + s_2} + \dots + \frac{b_n}{s + s_n}$$

> We use $a$, $\bar a$ and $b_i$ for convenience. $b_i$ will be eliminated in the following steps.

Doing [[Inverse Laplace Transform]]:

$$\implies y(t) = ae^{-j\omega t} + \bar a e^{j\omega t} + b_1 e^{-s_1 t} + b_2 e^{-s_2 t} + \dots + b_n e^{-s_n t}$$

For steady state response, $t \rightarrow \infty$:

$$\implies y_{\rm ss}(t) = ae^{-j\omega t} + \bar a e^{j\omega t}$$

> The constant $a$ and $\bar a$ can be evaluated as follows:
> $$a = \left. G(s)\frac{\omega X}{s^2 + \omega^2}(s + j\omega)\right\vert_{s = -j\omega} = -\frac{XG(-j\omega)}{2j}$$
> $$\bar a = \left. G(s)\frac{\omega X}{s^2 + \omega^2}(s - j\omega) \right\vert_{s = j\omega} = \frac{XG(j\omega)}{2j}$$
> > We want to seperate the complex quantity from $G(j\omega)$, therefore:
> > $$G(j\omega) = \vert G(j\omega) \vert e^{j\phi}$$
> > where $\vert G(j\omega) \vert$ is the magnitude and $\phi$ is the angle. Note that the angle is
> > $$\phi = \angle G(j\omega) = \tan^{-1}\left[ \frac{\text{imaginary part of } G(j\omega)}{\text{real part of }G(j\omega)} \right]$$
> > Similarly, $G(-j\omega)$ is:
> > $$G(-j\omega) = \vert G(-j\omega) \vert e^{-j\phi} = \vert G(j\omega) \vert e^{-j\phi}$$
> Seperating the complex quentity from $G(j\omega)$:
> $$a = -\frac{X\vert G(j\omega) \vert e^{-j\phi}}{2j}, \quad \bar a = \frac{X\vert G(j\omega) \vert e^{j\phi}}{2j}$$

Substitute $a$ and $\bar a$ with the value in the box above:

$$\implies y_{\rm ss}(t) = X\vert G(j\omega) \vert\frac{e^{j(\omega t + \phi)} - e^{-j(\omega t + \phi)}}{2j}$$

By [[Euler Formula]]:

$$\implies \underline{y_{\rm ss}(t) = X\vert G(j\omega) \vert \sin(\omega t + \phi)}_\#$$

which is equivalent to:

$$\implies \underline{
	y_{\rm ss}(t) = Y\sin(\omega t + \phi)
}_\#$$

![[321955019_1200947804189875_190573821288069323_n.jpg]]

---

參考資料:

Modern Control Engineering, 5th edition

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.