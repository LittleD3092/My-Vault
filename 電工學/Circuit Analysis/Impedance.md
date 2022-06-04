標籤: #電工學 

---

# [[Inductor]]

Consider an inductance in which the current is a sinusoid given by

$$i_L(t) = I_m\sin(\omega t + \theta)$$

Recall that the voltage across an inductance is 

$$v_L(t) = L\frac{ di_L(t) }{ dt }$$

代入

$$\implies 
v_L(t) = 
\omega L I_m \cos(\omega t + \theta)$$

則 [[Phasor]] 為

$$
\left\{
	\begin{array}{}
		{ \bf I }_L & = & 
		I_m \angle \theta - 90\degree \\
		{ \bf V }_L & = & \omega L I_m \angle \theta
	\end{array}
\right.
$$

${ \bf V }_L$ 可以被寫為

$$\implies { \bf V }_L = 
(\omega L \angle 90\degree) \times 
I_m \angle \theta - 90\degree$$

我們可以用 ${ \bf I }_L$ 替換得到

$${ \bf V }_L = 
(\omega L \angle 90\degree) \times
{ \bf I }_L$$

因此 [[Inductor]] 的 Impedance 為

$$Z_L = 
j\omega L = \omega L \angle 90\degree$$

$${\bf V}_L = Z_L { \bf I }_L$$

# [[Capacitor]]

by 

$${ \bf V }_C = Z_C { \bf I }_C$$

$$\implies Z_C = -j\frac 1 { \omega C } = 
\frac{ 1 }{ j\omega C } = 
\frac{ 1 }{ \omega C } \angle -90\degree$$

# [[Resistor]]

$$Z_R = R$$

---

參考資料:

課本

---

link:

