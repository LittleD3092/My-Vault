標籤: #工程數學 #電工學 

---

| Fourier Transform                                                                                                                                                                                              | Discrete Fourier Transform                                                                                                                                                                                              |
| -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Fourier Inverse Transform: $$f(x) = \frac{1}{\sqrt{2\pi}}\int_{-\infty}^{\infty}\hat f(w)e^{iwx}dw$$ <br> Fourier Transform of $f$: $$\hat f(w) = \frac 1 {\sqrt{2\pi}}\int_{-\infty}^{\infty}f(x)e^{-iwx}dx$$ | Discrete Fourier Inverse Transform: $$f_k = f(x_k) = q(x) = \sum_{n = 0}^{N - 1}c_ne^{inx_k}$$ Discrete Fourier Transform: $$\hat f_n \equiv Nc_n = \sum_{k = 0}^{N - 1}f_ke^{-inx_k} \qquad ; n = 0, 1, \dots, N - 1$$ |

- $\mathcal F\{f(x)\}$ is the symbol of Fourier Transform 
- $\mathcal F^{-1}\{\hat f(w)\}$ is the symbol of Fourier Inverse Tranform

Table of Fourier Transforms:

| $$f(x)$$                                                                                                                         | $$\hat f(w) = \mathcal F(f)$$                                                                             |
| -------------------------------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------- |
| $$\left\{ \begin{array}{} 1 & \text{if }-b < x < b \\ 0 & \text{otherwise} \end{array}\right.$$                                  | $$\sqrt{\frac 2 \pi}\frac{\sin bw}{w}$$                                                                   |
| $$\left\{ \begin{array}{} 1 & \text{if }b < x < c \\ 0 & \text{otherwise} \end{array} \right.$$                                  | $$\frac{e^{-ibw} - e^{-icw}}{iw\sqrt{2\pi}}$$                                                             |
| $$\frac{1}{x^2 + a^2} \qquad (a > 0)$$                                                                                           | $$\sqrt{\frac \pi 2}\frac{e^{-a\vert w \vert}}{a}$$                                                       |
| $$\left\{ \begin{array}{} x & \text{if }0 < x < b \\ 2x - b & \text{if }b < x < 2b \\ 0 & \text{otherwise} \end{array} \right.$$ | $$\frac{-1 + 2e^{ibw} - e^{-2ibw}}{\sqrt{2\pi}w^2}$$                                                      |
| $$\left\{ \begin{array}{} e^{-ax} & \text{if }x > 0 \\ 0 & \text{otherwise} \end{array} \right. \qquad (a > 0)$$                 | $$\frac 1 {\sqrt{2\pi}(a + iw)}$$                                                                         |
| $$\left\{ \begin{array}{} e^{ax} & \text{if }b < x < c \\ 0 & \text{otherwise} \end{array} \right.$$                             | $$\frac{e^{(a - iw)c} - e^{(a - iw)b}}{\sqrt{2\pi}(a - iw)}$$                                             |
| $$\left\{ \begin{array}{} e^{iax} & \text{if }-b < x < b \\ 0 & \text{otherwise} \end{array} \right.$$                           | $$\sqrt{\frac 2 \pi}\frac{\sin b(w - a)}{w - a}$$                                                         |
| $$\left\{ \begin{array}{} e^{iax} & \text{if }b < x < c \\ 0 & \text{otherwise} \end{array} \right.$$                            | $$\frac{i}{\sqrt{2\pi}}\frac{e^{ib(a - w)} - e^{ic(a - w)}}{a - w}$$                                      |
| $$e^{-ax^2}\qquad(a > 0)$$                                                                                                       | $$\frac 1 {\sqrt{2a}}e^{-w^2 / 4a}$$                                                                      |
| $$\frac{\sin ax}{x} \qquad (a > 0)$$                                                                                             | $$\sqrt{\frac{\pi}{2}} \qquad \text{if } \vert w \vert < a;$$ $$0 \qquad \text{if }\vert w \vert > a$$ | 

# Fourier Transform

From [[Fourier Integral]]:

$$f(x) = \int_0^\infty
[A(w)\cos wx + B(w)\sin wx]dw$$

$$A(w) = 
\frac 1 \pi \int_{-\infty}^\infty
f(v)\cos wv dv$$

$$B(w) = \frac 1 \pi
\int_{-\infty}^\infty f(v)\sin wv dv$$

Substitude $A(w), B(w)$ into the integral:

$$\implies f(x) = \frac 1 \pi
\int_0^\infty\int_{-\infty}^\infty 
f(v)[\cos wv \cos wx + \sin wv \sin wx]dvdw$$

> By [[Trigonometric Function#Trigonometric Identity|Trigonometric Identity]]:
> $$\cos (\alpha - \beta) = \cos\alpha \cos \beta + \sin \alpha \sin \beta$$

$$\implies f(x) = \frac 1 \pi 
\int_0^\infty 
\underbrace{
	\left[
		\int_{-\infty}^\infty
		f(v)\cos(wx - wv)dv
	\right]
}_{\text{even function}}dw$$

Because it is even function

$$\implies f(x) = \frac 1 {2\pi}
\int_{-\infty}^\infty\left[
	\int_{-\infty}^\infty f(v)
	\cos(wx - wv)dv
\right]dw$$

> A similar counterpart exist for sine
> $$\frac 1 {2\pi}\int_{-\infty}^\infty\left[\int_{-\infty}^\infty f(v)\sin(wx - wv)dv\right]dw = 0$$
> The result of the sine counterpart is $0$ because an odd function doing integral from $-\infty$ to $\infty$ is $0$

We add the sine function above with $i$ to our $f(x)$ as follows

$$\implies f(x) = \frac 1 {2\pi}
\int_{-\infty}^\infty\left[
	\int_{-\infty}^\infty f(v)
	\cos(wx - wv)dv + 0
\right]dw$$

$$\implies f(x) = \frac 1 {2\pi}
\int_{-\infty}^\infty\left[
	\int_{-\infty}^\infty f(v)
	\cos(wx - wv)dv + if(v)\sin(wx - wv)dv
\right]dw$$

> Using [[Euler Formula]]
> $$e^{ix} = \cos x + i\sin x$$

$$\implies f(x) = \frac 1 {2\pi}\int_{-\infty}^\infty \int_{-\infty}^\infty f(v) e^{iw(x - v)}dvdw$$

$$\implies f(x) = \frac 1 {\sqrt{2\pi}}\int_{-\infty}^\infty 
\underbrace{\left[
\frac 1 {\sqrt{2\pi}}\int_{-\infty}^\infty 
f(v) e^{-iwv}dv\right]}_{\hat f(w)}
e^{iwx}dw
$$

Writing an equation of $\hat f(w)$ and substitude $v$ using $x$

$$\underline{
\hat f(w) = \frac 1 {\sqrt{2\pi}}
\int_{-\infty}^\infty f(x)e^{-iwx}dx
}_\#$$

This is called "Fourier Transform of $f$"

Also we have Inverse Fourier Transform

$$\underline{
f(x) = \frac 1 {\sqrt{2\pi}}
\int_{-\infty}^\infty \hat f(w) e^{iwx}dw}_\#$$

## Meaning of Fourier Transform

- Fourier Transform $\hat f(w)$ is equivalent to the Fourier coefficient $A(w), B(w)$ in [[Fourier Integral]]
- $\hat f(w)$ is the amplitude of $e^{-iwx}$ that is needed to form $f(x)$ in the Exponential Fourier Series
- The "total energy" contained in the oscillation of frequency $w$ from $a$ to $b$ is
$$\int_a^b 
\left\vert
	\hat f(w)
\right\vert^2 dw$$
- The system's total energy (for all $w$) is
$$E = \int_{-\infty}^\infty
\left\vert
	\hat f(w)
\right\vert^2dw$$

## Properties of Fourier Transform

Linearity:
$$\mathcal F(af + bg) = 
a \mathcal F(f) + b \mathcal F(g)$$

Derivatives:
$$\mathcal F\{
f'(x)
\} = iw\mathcal F\{f(x)\}$$

$$\mathcal F \{f''(x)\} = -w^2 \mathcal 
F\{f(x)\}$$

[[Convolution]]:
$$h(x) \equiv (f * g)(x) = \int_{-\infty}^\infty f(p)g(x - p)dp = 
\int_{-\infty}^\infty f(x - p)g(p)dp$$

$$\mathcal F(f * g) = \sqrt{2\pi}\mathcal F(f)\mathcal F(g)$$

> Fourier Transform and Inverse Fourier Transform are fast using computers
> 
> So this property is a shortcut for convolution
> $$f * g = \mathcal F^{-1}\left(\sqrt{2\pi} \mathcal F(f)\mathcal F(g)\right)$$

# Discrete Fourier Transform

$$\hat f_n = Nc_n = \sum_{k = 0}^{N - 1}f_ke^{-inx_k} \qquad ; n = 0, 1, \dots, N - 1$$

$$c_n = \frac 1 N \sum_{k = 0}^{N - 1}f_ke^{-inx_k} \qquad ; n = 0, 1, \dots, N - 1$$

## Motivation

Previously assumed $f(x)$ is given as an equation. But realistically $f(x)$ is unknown. Instead, we measure samples of $f(x)$ at discrete points $x_1, x_2, ...$

![[discrete fourier transform motivation.png]]

Therefore, we have to perferm fourier transform based on discrete $f(x_1), f(x_2), f(x_3), ...$

## Assumption

1. $x_1, x_2, ..., x_k$ is regularly-spaced. If there are $k = N$ samples over $0 \leq x \leq 2\pi$:
$$x_k = \frac{2\pi k}{N}$$
2. If the spacing between two $x_k$ is $\Delta x = x_{k + 1} - x_k = \frac{2\pi}{N - 1}$, we cannot measure oscillation with wavelength smaller than $\Delta x$
![[discrete fourier transform limitations.png]]

Thus, we convert fourier integral to the summation fo frequency to $N - 1$:

$$f(x) = \frac 1 {\sqrt{2\pi}}
\int_{-\infty}^\infty \hat f(w)e^{iwx}dw$$

$$\implies q(x_k) = \sum_{n = 0}^{N - 1}c_n e^{inx_k} \qquad ; k = 0, 1, \dots, N - 1$$

The equation above is discrete fourier transform. $q(x_k)$ is the approximation / interpolation of an $f(x)$ which is unknown or doesn't exist.

Can also call it "$f_k$"$= f(x_k)$

---

參考資料:

電工學

---

link:

[[Fourier Series]]
[[Convolution]]