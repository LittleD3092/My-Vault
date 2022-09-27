標籤: #automatic-control 

---

[TOC]

---

It appears that frequently used controller has a block diagram like below:

![[block diagram for frequently used controller.jpeg]]

This note shows some useful controller models.

# On-off Controller

The on-off controller has a equation like this:

$$u(t) = 
\left\{
	\begin{array}{}
		u_1 & \text{for} & e(t) > 0 \\
		u_2 & \text{for} & e(t) < 0
	\end{array}
\right.$$

There are only two values, on ($u_1$) and off ($u_2$). If you draw the above equation in a diagram, you will get something like this:

![[diagram of on-off controller.jpeg]]

# Proportional Control ($P$-control)

Proportional control means that the input and the output have a linear relationship.

$$u(t) = K_p \cdot e(t)$$

After taking the [[Laplace Transform]], you get the following equation.

$$U(s) = K_p \cdot E(s)$$

$$\implies \frac{U(s)}{E(s)} = K_p$$

The [[Block Diagram]] of p controller:

![[block diagram of p controller.jpeg|200]]

# Integral Control ($I$-control)

The integral control means that the input is integrated, Like the equation below.

$$u(t) = K_i \int_0^t e(t)dt$$

You may use [[Laplace Transform]] to simplify the formula above.

$$U(s) = K_i \cdot \frac 1 s \cdot E(s)$$

$$\frac{U(s)}{E(s)} = \frac{K_i}{s}$$

# Proportional-Integral Control ($PI$-control)

Proportional-integral control conbines [[#Proportional Control P -control]] and [[#Integral Control I -control]], use superposition to get the output.

$$u(t) = K_pe(t) + \frac{K_p}{T_i}\int_0^t e(\tau)d\tau$$

Using [[Laplace Transform]], the equation above is simplified into:

$$U(s) = K_pE(s) + \frac{K_p}{T_i} \frac{1}{s}E(s)$$

$$\implies \frac{U(s)}{E(s)} = K_p(1 + \frac{1}{T_i s})$$

# Proportional Derivative Control ($PD$-control)

Proportional derivative control uses [[#Proportional Control P -control]] combined with derivative using superposition. The derivative part acts as a prediction mechanism.

$$u(t) = K_p \cdot e(t) + K_p \cdot T_d \cdot \frac{de(t)}{dt}$$

Using [[Laplace Transform]], we can simplify the above equation to the equation below. Note that we assume the initial condition is zero when getting the equation below.

> In real life scenario, the initial condition is likely zero.

$$U(s) = K_p \cdot E(s) + K_p \cdot T_d \cdot s \cdot E(s)$$

$$\implies \frac{U(s)}{E(s)} = K_p(1 + T_d \cdot s)$$

# Proportional Integral Derivate control ($PID$-control)

PID control is very useful, it combines all the advantages of proportional, integral and derivative.

$$u(t) = K_pe(t) + \frac{K_p}{T_i}\int_0^te(\tau)d\tau + K_p T_d \cdot \frac{de(t)}{dt}$$

Using [[Laplace Transform]], we get the below simplified equation:

$$U(s) = K_pE(s) + \frac{K_p}{T_i}\frac 1 s E(s) + K_pT_d \cdot s \cdot E(s)$$

$$\frac{U(s)}{E(s)} = K_p(1 + \frac{1}{T_is} + T_d \cdot s)$$

# Close-loop system subjected to an external disturbance

![[close-loop system subjected to an external disturbance.jpeg]]

The system take external disturbance $D(s)$ into account. See the above graph, the $D(s)$ comes in and effect plant directly.

This system has two inputs, $R(s)$ and $D(s)$. To analyze a system that has two inputs, we analyze the inputs seperately, then add them together.

1. We assume there is no disturbance, $D(s) = 0$, $R(s) \neq 0$.

Using [[Block Diagram#In Series]] and [[Block Diagram#In Parallel]]:

$$\frac{Y(s)}{R(s)} = \frac{G_1(s)G_2(s)}{1 + G_1(s)G_2(s)}$$

2. Now we assume there is no $R(s)$, only $D(s)$ is present.

$$\frac{Y(s)}{D(s)} = \frac{G_2}{1 + G_1G_2}$$

3. Now we have analyzed the seperating input, we add it together. When both $D(s)$, $R(s)$ exist:

$$Y(s) = \frac{G_1(s)G_2(s)}{1 + G_1(s)G_2(s)} \cdot R(s) + \frac{G_2(s)}{1 + G_1(s)G_2(s)}D(s)$$

Conceptually, we can design a controller $G_1(s)$ such that $G_1(s)G_2(s) >> 1$. This can further simplify the above equation:

$$Y(s) = R(s) + \cancel{\frac{D(s)}{G_1(s)}}^{0}$$

From this, we find out that if we design a controller $G_1(s)$ that is big enough, ==disturbance will not affect the close-loop response==.

---

參考資料:

automatic control class

---

link:

[[Block Diagram]]
[[Mathematical Modeling of Control Systems]]

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.