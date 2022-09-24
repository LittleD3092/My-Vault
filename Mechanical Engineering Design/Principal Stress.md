標籤: #Mechanical-Engineering-Design 

---

[TOC]

---

Principal stress indicates on what angle does the plane have maximum normal stress. On this angle, the shear stress is $0$.

# Solve

![[stress on an inclined plane - plane stress.png|250]]

We need to solve the maximum value of $\sigma'_x(\theta)$, so we derive it.

$$\frac{d\sigma_x'(\theta)}{d\theta} = 0$$

> In section [[Plane Stress#Solving Stress on an Inclined Plane]], we have the following:
> $$\implies
> 	\left\{
> 		\begin{array}{}
> 			\sigma_x' & = & \frac{\sigma_x + \sigma_y}{2} + \frac{\sigma_x - \sigma_y}{2}\cos 2\theta + \tau_{xy}\sin2 \theta \\
> 			\tau'_{xy} & = & -\frac{\sigma_x - \sigma_y}{2} \sin 2\theta + \tau_{xy} \cos 2 \theta
> 		\end{array}
> 	\right.
> $$

$$\implies -(\sigma_x - \sigma_y)\sin 2\theta + 2 \tau_{xy}\cos2 \theta = 0$$

$$\implies \tan 2\theta = \frac{2\tau_{xy}}{\sigma_x - \sigma_y}$$

Therefore we get the angle of principal stress:

$$\implies \theta = \underline{\frac 1 2 \tan^{-1}\left(\frac{2\tau_{xy}}{\sigma_x - \sigma_y}\right)}_\#$$

---

參考資料:

Mechanical Engineering Design class

---

link:

