標籤: #Mechanical-Engineering-Design 

---

[TOC]

---

Sometimes we encounter a situation that stress on one surface are zero. In this case, we may simplify the stress components to plane stress, and draw diagram like the following.

![[from 3D stress to plane stress - plane stress.png|500]]

The graph on the left side is the stress diagram for 3D objects. If $\tau_{yz}$, $\tau_{xz}$ and $\sigma_{z}$ are all zero, we may simplify it to the diagram on the right side.

# Solving Stress on an Inclined Plane

It is crucial to know the stress of an inclined plane. 

For example, you use tape to combine two pieces together, and the tape endures less stress. Therefore you may want to know how much stress will be added on the tape, in order to know whether the tape will snap or not.

> ![[stress on an inclined plane - plane stress.png|200]]
> We know $\sigma_x$, $\sigma_y$ and $\theta$. Represent $\tau'_{xy}$ and $\sigma'_{x}$ in these variables.

We use the force equilibrium on $x'$ and $y'$ axis.

$$\left\{
    \begin{array}{}
	    \sum F_x' = 0 \\
	    \sum F_y' = 0
    \end{array}
\right.$$

$$\implies 
\left\{
	\begin{array}{}
		\underbrace{-\sigma_x \cdot A \cos \theta \cdot \cos \theta}_{\sigma_x \text{ on the }x' \text{ axis}} \ 
		\underbrace{-\ \sigma_y \cdot A \sin \theta \cdot \sin \theta}_{\sigma_y \text{ on the }x' \text{ axis}} + \sigma'_x = 0 \\
		\underbrace{\sigma_x \cdot A \cos \theta \cdot \sin\theta}_{\sigma_x \text{ on the } y' \text{ axis}} \ \underbrace{\ -\sigma_y \cdot A \sin \theta \cdot \cos \theta}_{\sigma_y \text{ on the } y' \text{ axis}} + \tau'_{xy} = 0
	\end{array}
\right.$$

Solving the equation above, we get:

$$\implies \underline{
	\left\{
		\begin{array}{}
			\sigma_x' & = & \frac{\sigma_x + \sigma_y}{2} + \frac{\sigma_x - \sigma_y}{2}\cos 2\theta + \tau_{xy}\sin2 \theta \\
			\tau'_{xy} & = & -\frac{\sigma_x - \sigma_y}{2} \sin 2\theta + \tau_{xy} \cos 2 \theta
		\end{array}
	\right.
}_\#$$

## Principal Stress

After we get a stress on any angle, we want to find the principal stress.

![[Principal Stress]]

## [[Mohr's Circle]]

We can solve plane stress and [[#Principal Stress]] using another approach: [[Mohr's Circle]]. This is much easier than the math method above.

![[Mohr's Circle]]

---

參考資料:

Mechanical Engineering Design class

---

link:

