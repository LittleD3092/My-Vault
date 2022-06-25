標籤: #電工學 

---

# Angles

## Transient Response

![[Transient Responce.png]]

$$\overset{ \mathcal{ L } }{ \implies } \frac{ I_{ dc } }{ s } = \frac{ V }{ 1/sC } + \frac{ V }{ R } + \frac{ V }{ sL }$$

> $$V(s) = (sC + \frac{ 1 }{ R } + \frac{ 1 }{ sL })^{ -1 } \cdot \frac{ I_{ dc } }{ s }$$

$$\implies I_L = \frac{ V(s) }{ sL } = \frac{ I_{dc} / s }{ s^2LC + \frac{ L }{ R }s + 1 }$$

使用 [[Inverse Laplace Transform]] 中的 [[Inverse Laplace Transform#方法二 Decomposition of Fractions|Decomposition of Fractions]]

$$I_L = \frac{ A_1 \cdot 1 }{ s } + \frac{ A_2 (s + \sigma) }{ (s + \sigma)^2 + \omega^2 } + \frac{ A_3 \omega }{ (s + \sigma)^2 + \omega^2 }$$

計算後發現後面兩項太小，因此只需要第一項

$$A_1 = 24\text{mA}$$

# Steady State Analysis

$$i_{ \theta, p } = I_{ imax }\vert G(j\omega) \vert \sin(\omega t + \theta_i + \angle G(j\omega))$$

$p$: particular solution

![[AC steady state analysis.png]]

$$V_i = V_{ imax } \cdot \angle \theta_{ vi }$$

$$I = \vert I(\omega) \vert \angle I(\omega)$$

$$Z = \vert Z(\omega) \vert \angle Z(\omega)$$

## Example

![[Example of AC circuit analysis.png]]

![[Example of AC circuit analysis after Laplace Transform.png]]

$$I_1 = \frac{ 60 }{ 80 + j140 + (- j400 \vert\vert 800) }$$

> $$-j400\vert\vert 800 = \frac{ j320k }{ 800 - j400 }$$
> $$ = \frac{ j320k(800 + j400) }{ 800k }$$
> $$ = -160 + j320$$

$$ = \frac{ 60 }{ 240 - j180 } = 0.2 \angle 37 \degree$$

---

參考資料:

電工學上課

---

link:

