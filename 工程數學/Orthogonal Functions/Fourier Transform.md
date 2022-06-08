標籤: #工程數學 #電工學 

---

| Fourier Transform                                                                                                                                                                                              | Discrete Fourier Transform |
| -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | -------------------------- |
| Fourier Inverse Transform: $$f(x) = \frac{1}{\sqrt{2\pi}}\int_{-\infty}^{\infty}\hat f(w)e^{iwx}dw$$ <br> Fourier Transform of $f$: $$\hat f(w) = \frac 1 {\sqrt{2\pi}}\int_{-\infty}^{\infty}f(x)e^{-iwx}dx$$ |                            |

- $\mathcal F\{f(x)\}$ is the symbol of Fourier Transform 
- $\mathcal F^{-1}\{\hat f(w)\}$ is the symbol of Fourier Inverse Tranform

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
	\right]dw
}_{\text{even function}}$$

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



---

參考資料:

電工學

---

link:

[[Fourier Series]]
[[Convolution]]