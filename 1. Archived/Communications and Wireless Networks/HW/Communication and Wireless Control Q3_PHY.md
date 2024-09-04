1. What are the two units of the signal strength?

- Decibel-Milliwatts ($\rm dBm$)
- Milliwatts ($\rm mW$)

---

2. Consider the Gaussian distribution $Z\sim\mathcal N(0, 1)$. What is the mean of $Z$? What is the variance of $Z$?

The standard normal deviate $Z$ is a Gaussian distribution with mean $\mu = 0$ and standard deviation $\sigma = 1$. The variance $\sigma^2$ is therefore $\sigma^2 = 1$.

---

3. Consider a complex random variable $a+bi$ with both $a$ and $b$ following the complex Gaussian normal distribution $\mathcal N(0,1)$. What is the average power of $a+bi$?

Signal average power is calculated by:

1. Square the amplitude of a complex signal.
2. Average it.
3. Take square root.

$$\text{Signal average power} = 
\sqrt{
	E[\vert \text{Signal} \vert^2]
}$$

Therefore, the average power can be calculated using the equation:

$$
\begin{array}{l}
	\sqrt{
		E\left[
			\left\vert 
				a + bi 
			\right\vert^2
		\right]
	} &=& 
	\sqrt{
		E\left[
			a^2 + b^2
		\right]
	} \\
	&=& 
	\sqrt{
		E[a^2] + E[b^2]
	} \\
	&=& \sqrt{
		Var(a) + Var(b)
	} \\
	&=& \sqrt{1 + 1} \\
	&=& \underline{\sqrt 2}_\#
\end{array}
$$

---

4. What is path loss? What are the factors that could determine the amount of path loss?

Path loss is the power density loss of an electromagnetic wave when propagating through air.

Some effects that may cause path loss:

- Free-space loss.
- Refraction.
- Diffraction.
- Reflection.
- Aperture-medium coupling loss.
- Absorption.

The effects above can be categorized into three factors:

- **Propagation losses**: The loss when propagating in air (free-space loss).
- **Absorption losses**: The loss when penetrating media that are not transparent (refraction, reflection, aperture-medium coupling loss, absorption).
- **Diffraction losses**: The loss when the signal is blocked by opaque obstacles (diffraction).

---

5. What is the propagation delay of a link of 300m? Considering a 2.4GHz band traveling along a 300m link, what is the received phase angle? (assume the initial phase from the transmitter is 0)

For wireless, the propagation speed $s$ is the speed of light $c$.

$$s = c$$

Therefore, the propagation delay $t$ can be calculated using distance $d = 300 \ \rm m$ and speed $s = 3 \cdot 10^8 \ \rm m/s$:

$$
\begin{array}{l}
	t &=& \displaystyle\frac{d}{s} \\
	&=& \displaystyle \frac{300 \,\rm m}{3\cdot 10^8 \, \rm m/s} \\
	&=& \underline{1\rm \ \mu s}_\#
\end{array}
$$

Using the wavelength formula, the speed $v = 3\cdot 10^8$, and the frequency $f = 2.4\rm GHz$:

$$
\begin{array}{rrl}
	& v &=& f\lambda \\
	\implies & 3\cdot 10^8 &=& 2.4\cdot 10^9 \cdot \lambda \\
	\implies & \lambda &=& 0.125\,\rm m
\end{array}
$$

Dividing the distance $d$ with wavelength $\lambda$ will give us the number of waves:

$$\frac{d}{\lambda} = \frac{300}{0.125} = 2400$$

Since the number of waves is a whole number, the received phase angle is $\underline{0}_\#$.

---

6. What is the wavelength of the 2.4GHz band? What is the wavelength of the 60GHz band?

Using the wavelength formula, the speed $v = 3\cdot 10^8$, and the frequency $f = 2.4\rm GHz$:

$$
\begin{array}{rrl}
	& v &=& f\lambda \\
	\implies & 3\cdot 10^8 &=& 2.4\cdot 10^9 \cdot \lambda \\
	\implies & \lambda &=& \underline{0.125\,\rm m}_\#
\end{array}
$$

Using the wavelength formula, the speed $v = 3\cdot 10^8$, and the frequency $f = 60\rm GHz$:

$$
\begin{array}{rrl}
	& v &=& f\lambda \\
	\implies & 3\cdot 10^8 &=& 60\cdot 10^9 \cdot \lambda \\
	\implies & \lambda &=& \underline{0.005\,\rm m}_\#
\end{array}
$$

---

7. What is the multipath effect? What does LoS mean?

Multipath effect happens when a signal is received by the receiver by two or more paths. This may cause phase shifting and interference that may cause the signal to become too weak.

Line-of-sight multipath error is caused by both direct and indirect signals:

![[LoS Multipath and NLoS Multipath.png]]

---

8. Explain why a cosine wave and a sine wave are orthogonal to each other?

For two functions $f_1, f_2$ to be orthogonal, the following equation must be satisfied:

$$\int_{-L}^L f_1(x) f_2(x) dx = 0$$

Therefore, we should try to calculate the result of $f_1(x) = \sin(x), f_2(x) = \cos(x)$:

$$
\begin{array}{l}
	\int_{-L}^L \sin(x) \cos(x)dx & 
	\begin{array}{l}
		u = \sin x & dv = \cos x dx \\
		du = \cos x dx & v = \sin x
	\end{array} \\
	\displaystyle
	= \left.
		\sin^2x 
	\right\vert_{x = -L}^L - 
	\int_{-L}^L \sin x \cos x dx
\end{array}
$$

Moving the integrals to one side, we get:

$$
\begin{array}{l}
	\implies \displaystyle
	\int_{-L}^L \sin x \cos x dx &=&
	\displaystyle
	\left.\frac 1 2 \sin^2 x \right\vert_{x = -L}^L \\
	&=& 
	\displaystyle
	\frac 1 2\left(
		\sin^2 L - \sin^2(-L)
	\right) \\
	&=& \displaystyle
	\frac 1 2 (\sin^2L - \sin^2 L) \\
	&=& 0
\end{array}
$$

Therefore, $\sin(x)$ and $\cos(x)$ are orthogonal.