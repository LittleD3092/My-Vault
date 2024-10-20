標籤: #automatic-control #list 

---

[TOC]

---

In [[Mathematical Modeling of Control Systems]], we learnt how to model a system.
In this note, we will learn how to analyze the system to various input.

In practice, the input signal to a control system is not known ahead of time but random. Because of this, we have some **typical test signals**:

- Step functions
- Ramp functions
- Acceleration functions
- Impulse functions
- Sinusoidal functions
- White noise

# Keywords

- **Transient response** $c_{\rm tr}$: The response which goes from the initial state to the final state.
- **Steady-state response** $c_{\rm ss}$: The response which the system output behaves as $t$ approaches infinity.

The **system response** $c(t)$ may be written as

$$c(t) = c_{\rm tr} + c_{\rm ss}(t)$$

- **Absolute stability**: Whether the system is stable or unstable.
- **Equilibrium**: When the system is not subjected to any disturbance or input, the output stays at the same state.
- **Stable**: If the output eventually comes back to its equilibrium state when subjected to an initial condition.
- **Critically stable**: The oscillation continues forever.
- **Unstable**: The output diverges without bound from its equilibrium state.

# First-Order Systems

![[Pasted image 20221128152511.png]]

The input-output relationship is

$$\frac{C(s)}{R(s)} = \frac{1}{Ts + 1}$$

| Input        | Output $\displaystyle C(s)$                                      | Output $c(t)$                          | Error $e(t)$      | Steady state error $e(\infty)$ |
| ------------ | ---------------------------------------------------------------- | -------------------------------------- | ----------------- | ------------------------------ |
| Unit-step    | $\displaystyle \frac{1}{s} - \frac{1}{s+(1/T)}$                  | $\displaystyle 1 - e^{-t / T}$         | $e^{-t / T}$      | $0$                            |
| Unit-ramp    | $\displaystyle \frac{1}{s^2} - \frac{T}{s} + \frac{T^2}{Ts + 1}$ | $t - T + Te^{-t / T}$                  | $T(1 - e^{-t/T})$ | $T$                            |
| Unit-impulse | $\displaystyle \frac{1}{Ts + 1}$                                 | $\displaystyle \frac{1}{T} e^{-t / T}$ |                   |                                |

## Unit-Step Response

For unit-step response, the [[Laplace Transform]] of it is $1/s$, 

$$C(s) = \frac{1}{Ts + 1}\frac 1 s = \frac 1 s - \frac{1}{s + (1/T)}$$

Using [[Inverse Laplace Transform]],

$$c(s) = 1 - e^{-t/T}$$

According to the output, we can draw the diagram:

![[Pasted image 20221129210856.png|400]]

## Unit-Ramp Response

The [[Laplace Transform]] of unit-ramp function is $1/s^2$, therefore

$$C(s) = \frac{1}{Ts+1}\frac{1}{s^2}$$

Expanding into partial fractions:

$$C(s) = \frac{1}{s^2} - \frac{T}{s} + \frac{T^2}{Ts + 1}$$

Taking [[Inverse Laplace Transform]]:

$$c(t) = t - T + Te^{-t / T}$$

The error $e(t)$ is:

$$e(t) = r(t) - c(t) = T(1 - e^{-t/T})$$

The steady state error $e(\infty)$:

$$e(\infty) = T$$

![[Pasted image 20221129213039.png|400]]

## Unit-Impulse Response

For unit-impulse ([[Dirac Delta Function]]) input, the [[Laplace Transform]] of it is $1$, and the output is

$$C(s) = \frac{1}{Ts + 1}$$

The [[Inverse Laplace Transform]]:

$$c(s) = \frac{1}{T} e^{-t / T}$$

![[Pasted image 20221129213058.png|400]]

# Second-Order Systems

A second-order system has a transfer function:

$$\frac{C(s)}{R(s)} = \frac{K}{Js^2 + Bs + K}$$

$$\implies \frac{C(s)}{R(s)} = 
\frac{
	\displaystyle \frac{K}{J}
}
{
	\displaystyle 
	\left[
		s + \frac{B}{2J} + 
		\sqrt{
			\left(
				\frac{B}{2J}
			\right)^2 - \frac K J
		}
	\right]
	\left[
		s +
		\frac B {2J} - 
		\sqrt{
			\left(
				\frac B {2J}
			\right)^2 - \frac K J
		}
	\right]
}$$

We can simplify the above equation by

- $\omega_n$: undamped natural frequency
- $\sigma$: attenuation
- $\zeta$: damping ratio
	- $B$: actual damping
	- $B_c$: critical damping
- $\displaystyle \frac K J = \omega_n^2$
- $\displaystyle \frac B J = 2\zeta \omega_n = 2\sigma$
- $\displaystyle \zeta = \frac B {B_c} = \frac B {2 \sqrt{JK}}$

$$\implies \frac{C(s)}{R(s)} = \frac{\omega_n^2}{s^2 + 2\zeta \omega_n s + \omega_n^2}$$

This form of second-order systems is called the **standard form**.

According to the damping ratio $\zeta$, there are several dynamic behavior:

1. $0 < \zeta < 1$: Underdamped. The transient response is oscillatory.
2. $\zeta = 0$: The transient response does not die out.
3. $\zeta = 1$: Critically damped.
4. $\zeta > 1$: Overdamped.

## Step Response

To solve the step response, we shall consider 3 cases.

- [[#Underdamped]]
- [[#Critically Damped]]
- [[#Overdamped]]

### Underdamped

> Underdamped: $0 < \zeta < 1$.

In this case, transfer function can be written as

$$\frac{C(s)}{R(s)} = \frac{\omega_n^2}{(s + \zeta \omega_n + j \omega_d)(s + \zeta \omega_n - j\omega_d)}$$

- $\omega_d = \omega_n\sqrt{1 - \zeta^2}$. $\omega_d$ is called the **damped natural frequency**.

For a unit-step input,

$$
\begin{array}{l}
	C(s) & = & 
	\displaystyle
	\frac{\omega_n^2}
	{(s^2 + 2 \zeta \omega_n s + \omega_n^2)s} \\
	& = & 
	\displaystyle
	\frac{1}{s} - 
	\frac{s + 2 \zeta \omega_n}
	{s^2 + 2\zeta \omega_n s + \omega_n^2} \\
	& = & 
	\displaystyle
	\frac{1}{s} - 
	\frac{s + \zeta\omega_n}
	{(s + \zeta\omega_n)^2 + \omega_d^2} - 
	\frac{\zeta \omega_n}
	{(s + \zeta\omega_n)^2 + \omega_d^2}
\end{array}
$$

We use [[Inverse Laplace Transform]] to obtain $c(t)$:

$$
\begin{array}{l}
	c(t) & = & \mathcal L^{-1}[C(s)] \\
	& = & 
	\displaystyle
	1 - e^{-\zeta \omega_n t}
	\left(
		\cos \omega_d t + 
		\frac{\zeta}{\sqrt{1 - \zeta^2}}
		\sin \omega_d t
	\right) \\
	& = & 
	\displaystyle
	1 - 
	\frac{e^{-\zeta \omega_n t}}
	{\sqrt{1 - \zeta^2}}
	\sin\left(
		\omega_d t + 
		\tan^{-1}
		\frac{\sqrt{1 - \zeta^2}}{\zeta}
	\right)
\end{array}
$$

> It can be seen that the frequency of transient oscillation is the damped naturaal frequency $\omega_d$ and thus varies with the damping ratio $\zeta$.
> $$\omega_d = \omega_n\sqrt{1 - \zeta^2}$$

The error signal is

$$
\begin{array}{l}
	e(t) & = & r(t) - c(t) \\
	 & = & 
	 \displaystyle
	 e^{-\zeta \omega_n t}
	 \left(
		 \cos\omega_d t + 
		 \frac{\zeta}{\sqrt{1 - \zeta^2}}
		 \sin\omega_d t
	 \right)
\end{array}
$$

> This error signal exhibits a damped sinusoidal oscillation. At steady state $t =\infty$, no error exists between the input and output.

### Critically Damped

> Critically damped: $\zeta = 1$.

For a unit-step input, $R(s) = 1 / s$ and $C(s)$ can be written as

$$C(s) = \frac{\omega_n^2}{(s + \omega_n)^2 s}$$

Using [[Inverse Laplace Transform]]:

$$c(t) = 1 - e^{-\omega_n t}(1 + \omega_n t)$$

### Overdamped

> Overdamped: $\zeta > 1$.

For a unit-step input, $R(s) = 1 / s$ and $C(s)$ can be written:

$$C(s) = 
\frac{\omega_n^2}
{
	(
		s + 
		\zeta \omega_n + 
		\omega_n \sqrt{\zeta^2 - 1}
	)
	(
		s +
		\zeta \omega_n -
		\omega \sqrt{\zeta^2 - 1}
	)s
}$$

Use [[Inverse Laplace Transform]]:

$$
\begin{array}{l}
	c(t) & = & 
	\displaystyle
	1 + 
	\frac{1}
	{
		2 \sqrt{\zeta^2 - 1}
		(
			\zeta + \sqrt{\zeta^2 - 1}
		)
	} e^{-(\zeta + \sqrt{\zeta^2 - 1})\omega_n t} - 
	\frac{1}
	{
		2 \sqrt{\zeta^2 - 1}
		(\zeta - \sqrt{\zeta^2 - 1})
	}e^{-(\zeta - \sqrt{\zeta^2 - 1})\omega_n t} \\
	& = & 
	\displaystyle
	1 + \frac{\omega_n}{2 \sqrt{\zeta^2 - 1}}
	\left(
		\frac{e^{-s_1t}}{s_1} - 
		\frac{e^{-s_2t}}{s_2}
	\right)
\end{array}
$$

- $s_1 = (\zeta + \sqrt{\zeta^2 - 1})\omega_n$
- $s_2 = (\zeta - \sqrt{\zeta^2 - 1})\omega_n$

Consider a case which $\zeta >> 1$, $\vert s_1 \vert >> \vert s_2\vert$, $C(s) / R(s)$ may be approximated by

$$\frac{C(s)}{R(s)} = 
\frac{\zeta\omega_n - \omega_n \sqrt{\zeta^2 - 1}}{s + \zeta\omega_n - \omega_n \sqrt{\zeta^2 - 1}} = 
\frac{s_2}{s + s_2} \qquad \text{for } \zeta >> 1$$

The unit-step response of $\zeta >> 1$ is

$$C(s) = \frac{\zeta \omega_n - \omega_n \sqrt{\zeta^2 - 1}}{(s + \zeta \omega_n - \omega_n \sqrt{\zeta^2 - 1})s} \qquad \text{for } \zeta >> 1$$

The time response is then 

$$c(t) = 1 - e^{-(\zeta - \sqrt{\zeta^2 - 1})\omega_n t} \qquad \text{for } \zeta >> 1$$

## Impulse Response

For unit-impulse, $R(s) = 1$. The unit-impulse response $C(s)$ of the second-order system is

$$C(s) = \frac{\omega_n^2}{s^2 + 2\zeta\omega_n s + \omega_n^2}$$

The [[Inverse Laplace Transform]]:

$$
\begin{array}{l}
	\text{For } 0 \leq \zeta < 1 &
	\displaystyle
	c(t) = \frac{\omega_n}{\sqrt{1 - \zeta^2}} e^{-\zeta \omega_n t}\sin \omega_n \sqrt{1 - \zeta^2}t \\
	\displaystyle
	\text{For } \zeta = 1 &
	\displaystyle
	c(t) = \omega_n^2 te^{-\omega_n t} \\
	\text{For } \zeta > 1 &
	\displaystyle
	c(t) = \frac{\omega_n}{2\sqrt{\zeta^2 - 1}} e^{-(\zeta - \sqrt{\zeta^2 - 1})\omega_n t} - 
	\frac{\omega_n}{2\sqrt{\zeta^2 - 1}}
	e^{-(\zeta + \sqrt{\zeta^2 - 1})\omega_n t}
\end{array}
$$

The [[#Maximum Overshoot]] occurs at

$$t = \frac{\tan^{-1} \frac{\displaystyle\sqrt{1 - \zeta^2}}{\displaystyle \zeta}}{\omega_n \sqrt{1 - \zeta^2}} \qquad \text{where } 0 < \zeta < 1$$

And the value is

$$c(t)_{\max} = \omega_n \exp
\left(
	-\frac{\zeta}{\sqrt{1 - \zeta^2}} \tan^{-1}
	\frac{\sqrt{1 - \zeta^2}}{\zeta}
\right) \qquad \text{where } 0 < \zeta < 1$$

## Transient-Response Specifications

To specify the characteristics of a control system, it is custom to specify the following:

1. **Delay time** $t_d$: The time required to reach $50\%$ response.
2. **Rise time** $t_r$: The time required from $10\% \sim 90\%$, $5\% \sim 95\%$, or $0\% \sim 100\%$ response. 
	- For *underdamped second-order systems*, $0\% \sim 100\%$ is commonly used.
	- For *overdamped systems*, $10\% \sim 90\%$ is commonly used.
3. **Peak time** $t_p$: The time required for the response to reach the first peak.
4. **Maximum overshoot** $M_p$: Maximum peak value of the response measured from unity.
$$\text{Maximum percent overshoot} = \frac{c(t_p) - c(\infty)}{c(\infty)} \times 100 \%$$
5. **Setting time** $t_s$: The time required for the response to reach and stay within a range.

![[Pasted image 20221130202521.png]]

- For a *desirable transient response*, damping ratio $\zeta$ must be between $0.4$ and $0.8$.
- $\zeta < 0.4$ yield *excessive overshoot* in the transient response.
- System with $\zeta > 0.8$ responds sluggishly.

The sections below is the process of obtaining the specifications, and their equations are listed below:

| Specification          | Equation                                                                                                                                                                                                                 | Comments                                                                                                      |
| ---------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ | ------------------------------------------------------------------------------------------------------------- |
| [[#Rise Time]]         | $\displaystyle t_r = \frac{1}{\omega_d} \tan^{-1}\left(\frac{\omega_d}{-\sigma}\right) = \frac{\pi - \beta}{\omega_d}$                                                                                                   | ![[Pasted image 20221130205830.png\|300]] $\sigma = \zeta \omega_n$, $\omega_d = \omega_n \sqrt{1 - \zeta^2}$ | 
| [[#Peak Time]]         | $\displaystyle t_p = \frac{\pi}{\omega_d}$                                                                                                                                                                               |                                                                                                               |
| [[#Maximum Overshoot]] | $\displaystyle \begin{array}{} \\ \displaystyle e^{-(\sigma / \omega_d)\pi} \\ \\ \displaystyle e^{-(\zeta / \sqrt{1 - \zeta^2})\pi} \\ \end{array}$                                                                     |                                                                                                               |
| [[#Settling Time]]     | $\begin{array}{} \displaystyle t_s = 4T = \frac 4 \sigma = \frac{4}{\zeta \omega_n} & \text{(2\% criterion)} \\ \displaystyle t_s = 3T = \frac 3 \sigma = \frac 3 {\zeta \omega_n} & \text{(5\% criterion)} \end{array}$ |                                                                                                               |
| Delay Time             | $\displaystyle t_d = \frac{1 + 0.7\zeta}{\omega_n}$                                                                                                                                                                      |                                                                                                               |

### Rise Time

Referring to equation $c(t)$ in [[#Underdamped]], we obtain the rise time $t_r$ by letting $c(t_r) = 1$.

$$c(t_r) = 1 = 1 - e^{-\zeta\omega_n t_r}
\left(
	\cos \omega_d t_r +
	\frac{\zeta}{\sqrt{1 - \zeta^2}}
	\sin\omega_d t_r
\right)$$

Simplifying:

$$\cos\omega_d t_r +\frac{\zeta}{\sqrt{1 - \zeta^2}} \sin \omega_d t_r = 0$$

Since $\omega_n\sqrt{1 - \zeta^2} = \omega_d$ and $\zeta \omega_n = \sigma$, 

$$\tan \omega_d t_r = -\frac{\sqrt{1 - \zeta^2}}{\zeta} = -\frac{\omega_d}{\sigma}$$

Thus, the rise time $t_r$ is

$$
\underline{
t_r = \frac{1}{\omega_d} \tan^{-1}
\left(
	\frac{\omega_d}{-\sigma}
\right) = 
\frac{\pi - \beta}{\omega_d}
}_\#
$$

Where angle $\beta$ is defined as:

![[Pasted image 20221130205830.png|250]]

### Peak Time

Referring to $c(t)$ equation in section [[#Underdamped]], we may obtain the peak time by differentiating $c(t)$ and letting this derivative equal zero.

$$
\frac{dc}{dt} = 
\zeta \omega_n e^{-\zeta \omega_n t}
\left(
	\cos\omega_d t + 
	\frac{\zeta}{\sqrt{1 - \zeta^2}}
	\sin \omega_d t
\right) + 
e^{-\zeta \omega_n t}
\left(
	\omega_d \sin \omega_d t - 
	\frac{\zeta \omega_d}{\sqrt{1 - \zeta^2}}
	\cos\omega_d t
\right)
$$

Simplifying by cancelling cosine terms:

$$
\begin{array}{l}
	&
	\displaystyle
	\left.
		\frac{dc}{dt}
	\right\vert_{t = t_p} = 
	(\sin \omega_d t_p)
	\frac{\omega_n}{\sqrt{1 - \zeta^2}}
	e^{-\zeta \omega_n t_p} = 0 \\
	\implies & \sin\omega_d t_p = 0 \\
	\implies & \omega_d t_p = 0, \pi, 2\pi, 3\pi \dots
\end{array}
$$

Since the peak time corresponds to first peak, $\omega_d t_p = \pi$

$$\underline{
	t_p = \frac{\pi}{\omega_d}
}_\#$$

### Maximum Overshoot

The maximum overshoot occurs at the [[#Peak Time]] $t = t_p = \pi / \omega_d$. Referring to the $c(t)$ equation in section [[#Underdamped]]:

$$
\begin{array}{l}
	M_p & = & c(t_p) - 1 \\
	& = & 
	\displaystyle
	-e^{-\zeta \omega_n (\pi / \omega_d)}
	\left(
		\cos \pi + 
		\frac{\zeta}{\sqrt{1 - \zeta^2}}
		\sin\pi
	\right) \\
	& = & 
	\displaystyle
	\underline{ e^{-(\sigma / \omega_d) \pi} }_\# \\
	& = & \underline{e^{-(\zeta / \sqrt{1 - \zeta^2})\pi}}_\#
\end{array}
$$

**If the final value of the output is not unity**, then we need to use the following equation:

$$M_p = \frac{c(t_p) - c(\infty)}{c(\infty)}$$

### Settling Time

The settling time of a second-order system is some approximate value.

$$
\begin{array}{} \displaystyle t_s = 4T = \frac 4 \sigma = \frac{4}{\zeta \omega_n} & \text{(2\% criterion)} \\ \displaystyle t_s = 3T = \frac 3 \sigma = \frac 3 {\zeta \omega_n} & \text{(5\% criterion)} \end{array}
$$

# Routh's Stability Criterion

[[Routh's Stability Criterion]]

# Root-Locus Method

[[Root-Locus Method]]

---

參考資料:

Modern Control Engineering, 5th edition

---

link:


---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.