標籤: #Mechanical-Engineering-Design 

---

[TOC]

---

- Used in machinery to change angular motion into linear motion and to transmit power.

# Force Analysis

Analyzing the forces acting on the power screw, we have the free body diagram for lifting and lowering the load:

![[Pasted image 20221210202538.png]]

For rising the load, we have

$$
\begin{array}{}
	\displaystyle
	\sum F_x & = & P_R - N \sin \lambda -fN\cos\lambda & = & 0 \\
	\displaystyle
	\sum F_y & = & -F - fN\sin\lambda + N \cos \lambda & = & 0
\end{array}
$$
to reach equilibrium.
For lowering the load, we have

$$
\begin{array}{}
	\displaystyle
	\sum F_x & = & -P_L - N\sin \lambda + fN \cos\lambda & = & 0 \\
	\displaystyle
	\sum F_y & = & -F + fN\sin \lambda + N \cos\lambda & = & 0
\end{array}
$$

to reach equilibrium.

Since we are not interested in the normal force $N$, we eliminate it.

$$\implies 
\left\{
	\begin{array}{}
		P_R & = & 
		\displaystyle
		\frac{F(\sin\lambda + f\cos\lambda)}{\cos\lambda - f\sin\lambda} \\
		P_L & = & 
		\displaystyle
		\frac{F(f\cos\lambda - \sin\lambda)}{\cos\lambda + f\sin\lambda}
	\end{array}
\right.$$

Divide by $\cos\lambda$, and use the relation $\tan \lambda = l / \pi d_m$:

$$\implies \left\{
	\begin{array}{}
		P_R & = &
		\displaystyle
		\frac{F\left( 
			\displaystyle
			\frac{l}{\pi d_m} + f
		\right)}{1 - 
		\displaystyle
		\frac{fl}{\pi d_m}} \\
		P_L & = & 
		\displaystyle
		\frac{
			\displaystyle
			F\left(
				f - \frac{l}{\pi d_m}
			\right)
		}{1 + 
			\displaystyle
			\frac{fl}{\pi d_m}
		}
	\end{array}
\right.$$

The torque is the product of the force $P$ and the mean radius $d_m / 2$.

$$
\left\{
	\begin{array}{}
		T_R & = & 
		\displaystyle
		\frac{Fd_m}{2}
		\left(
			\frac{l + \pi f d_m}{\pi d_m - fl}
		\right) \\
		T_L & = & 
		\displaystyle
		\frac{F d_m}{2}
		\left(
			\frac{\pi f d_m - l}{\pi d_m + fl}
		\right)
	\end{array}
\right.
$$

- When a positive torque is obtained from the equation, the screw is said to be **self-locking**.
	- The condition to this is $\pi f d_m > 1$.
	- The condition is also $f > \tan \lambda$.
- Otherwise, the screw may spin without any external effort.

## Thread Efficiency

If we let $f = 0$ for the equation of $T_R$, we get

$$T_0 = \frac{Fl}{2\pi}$$

The thread efficiency is defined as

$$e = \frac{T_0}{T_R} = \frac{Fl}{2\pi T_R}$$

## For Square Threads

![[Pasted image 20221210221936.png]]

For square threads, thread angle $2\alpha$ is considered, but the lead angle $\lambda$ is small and neglected. The effect of the angle $\alpha$ is to increase the frictional force by the wedging action of the threads.

Therefore the frictional terms in equation $T_R$ must be divided by $\cos \alpha$.

$$T_R = \frac{F d_m}{2}
\left(
	\frac{l + \pi f d_m \sec \alpha}{\pi d_m - fl \sec \alpha}
\right)$$

> Note that this is an approximation because the effect of the lead angle has been neglected.

When the screw is loaded axially like the right of the figure, the torque required is

$$T_c = \frac{F f_c d_c}{2}$$

- $f_c$: The coefficient of collar friction.
- $d_c$: The frictional diameter of thrust collar.

The maximum nominal shear stress $\tau$ is

$$\tau = \frac{16T}{\pi d_r^3}$$

The compressive axial stress $\sigma$ in the body of the screw due to load $F$ is

$$\sigma = -\frac F A = -\frac{4F}{\pi d_r^2}$$

![[Pasted image 20221210223315.png]]

The stress element at the outer radius of the screw body is

$$
\begin{array}{l}
	\displaystyle
	\sigma_x = \frac{6F}{\pi d_r n_t p} &
	\tau_{xy} = 0 \\
	\displaystyle
	\sigma_y = -\frac{4F}{\pi d_r^2} &
	\displaystyle
	\tau_{yz} = \frac{16T}{\pi d_r^3} \\
	\sigma_z = 0 &
	\displaystyle
	\tau_{zx} = \frac{4T}{\pi d_r^2 n_t p}
\end{array}
$$

The von Mises stress $\sigma'$ (used in [[Distortion Energy]]) is found by substituting these stresses into equation.

- The equations above assume all engaged threads are equally sharing the load, which actually is not true.
	- A power screw lifting a load is in compression and its thread pitch is *shortened*.
	- Its engaging nut is in tension and its thread pitch is *lengthened*.
- Experiments show that
	- The first engaged thread carries 0.38 of the load.
	- The second carries 0.25.
	- The third 0.18.
	- The seventh is free of load.
- In estimating thread stresses, we should substitute $0.38F$ for $F$ and setting $n_t$ to $1$ to give the largest level of stresses in the *thread-nut combination*.

---

參考資料:

Mechanical Engineering Design, 11th edition

---

link:


---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.