標籤: #電工學 

---

# Power Calculations for a General Load

對於任何 [[RLC Circuit]] ，我們有以下三條式子

$$
\begin{array}{}
	v(t) & = & V_m \cos(\omega t) \\
	i(t) & = & I_m \cos(\omega t - \theta) \\
	p(t) & = & 
	V_m I_m \cos(\omega t) \cos(\omega t - \theta)
\end{array}
$$

> [[Trigonometric Function]]:
> $$\cos(\alpha \pm \beta) = \cos\alpha\cos\beta\mp\sin\alpha\sin\beta$$
> $$\implies \cos(\omega t - \theta) = \cos(\theta) \cos(\omega t) + \sin(\theta)\sin(\omega t)$$

$$\implies p(t) = 
V_mI_m\cos(\theta)\cos^2(\omega t) + 
V_m I_m \sin (\theta)\cos(\omega t)\sin(\omega t)$$

> [[Trigonometric Function]]:
> $$\cos^2(\omega t) = \frac 1 2 + \frac 1 2 \cos(2\omega t)$$
> $$\cos(\omega t)\sin(\omega t) = \frac 1 2 \sin(2\omega t)$$

$$p(t) = \frac{ V_m I_m }{ 2 }\cos(\theta)[1 + \cos(2\omega t)] + \frac{ V_m I_m }{ 2 }\sin(\theta)\sin(2\omega t)$$

$$P = \frac{ V_m I_m }{ 2 } \cos (\theta)$$

$$P = \underline{ V_{ rms } I_{ rms }\cos(\theta) }_{ \# }$$

$P$: average power

## Power Factor

$${ \bf PF } = \cos(\theta)$$

$$\theta = \theta_v - \theta_i$$

$\theta_v$: phase of voltage
$\theta_i$: phase of current

## Reactive Power

$$Q = V_{ rms }I_{ rms }\sin(\theta)$$

## Apparent Power

$$\text{ apparent power } = 
V_{ rms }I_{ rms }$$

$$\text{ apparent power }^2 = P^2 + Q^2$$

## Power Triangle

![[Power Triangle.png]]

用來描述 [[#Power Calculations for a General Load|real power]], [[#Reactive Power]], [[#Apparent Power]] 之間的關係

## Additional Power Relationship

### Reactance

$$Z = R + jX$$

其中 $R$ 是 resistance ， $X$ 是 reactance

因此 real power 還可以表示成

$$P = I_{ rms }^2 R$$

$$P = \frac{ V_{ Rrms }^2 }{ R }$$

[[#Reactive Power]] 也可以表示成

$$Q = I^2_{ rms } R$$

$$Q = \frac{ V^2_{ Xrms } }{ X }$$

---

參考資料:

課本

---

link:

[[AC Circuit]]
[[RLC Circuit]]