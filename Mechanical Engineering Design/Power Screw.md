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

---

參考資料:

Mechanical Engineering Design, 11th edition

---

link:


---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.