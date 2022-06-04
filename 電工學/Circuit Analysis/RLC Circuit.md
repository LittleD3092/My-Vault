標籤: #電工學 

---

# RL Circuit

## [[Differential Equation]]

![[RL Circuit.png]]

$$\text{ KVL: } \qquad v_L - i_L R = 0$$

$$v_L = -L\frac{ di_L }{ dt }$$

$$\implies L\frac{ di_L }{ dt } + R i_L = 0$$

$$i_L = i_L(0) e^{ -\frac{ t }{ T } } \qquad \text{ where } T = \frac{ L }{ R }$$

## [[Laplace Transform]]

![[RL Circuit Laplace.png]]

$$I_R = \frac{ I_{ L0 } }{ s } \cdot \frac{ sL }{ sL + R }$$

$$ = I_{ L0 } \cdot \frac{ 1 }{ s + \frac{ 1 }{ T } } \qquad , T = \frac{ L }{ R }$$

# RC Circuit

## [[Differential Equation]]

![[Differential Equations in RLC circuit.png|400]]

$$i_c = i_R \qquad t \geq t_0$$

$$i_c = \underbrace{ - }_{ \text{ direction } }C \frac{ dv_c }{ dt }$$

$$\underbrace{ C \frac{ dv_c }{ dt } }_{ -i_c } + \underbrace{ \frac{ 
v_c }{ R } }_{ i_R } = 0$$

---

$$v_c = v_c(0) e^{ -\frac{ t }{ RC } } \qquad \text{ Let } T = RC \quad \text{ time constant }$$

## [[Laplace Transform]]

![[Laplace RC Circuit.png]]

$$v_c(s) = \frac{ v_{ c0 } }{ s }\frac{ R }{ \frac{ 1 }{sC} + R } = \frac{ RC }{ RCs + 1 }v_{ c0 }$$

$$ = \frac{ v_{ c0 } }{ s + \frac{ 1 }{ T } }$$

$$v_c(t) = \mathcal{ L }^{ -1 }\left[ \frac{ 1 }{ s + \frac{ 1 }{ T } } \right] \cdot v_{ c0 }$$

$$ = v_{ c0 }e^{ -\frac{ t }{ T } }$$

## [[Impedance]]

$$Z(s) = \frac{ V(s) }{ I(s) }$$

$$I(s) = scV(s) - \underbrace{ cv(0) }_{ \text{ source } }$$

$$V(s) = \frac{ 1 }{ sc }I(s) + \underbrace{ \frac{ 1 }{ 
s }v(0) }_{ \text{ source } }$$

# RLC Circuit (串連)

## [[Differential Equation]]

![[rlc circuit differential equation.png]]

使用 [[Kirchhoff's Law#Kirchhoff Law|KVL]]

$$L\frac{ di(t) }{ dt } + 
Ri(t) + 
\frac{ 1 }{ C }\int_0^t i(t)dt + 
v_C(0) = v_s(t)$$

對 t 微分

$$\implies L \frac{ d^2 i(t) }{ dt^2 } + 
R \frac{ di(t) }{ dt } + 
\frac 1 C i(t) = \frac{ dv_s(t) }{ dt }$$

除以 $L$

$$\implies \frac{ d^2 i(t) }{ dt^2 } + 
\frac R L \frac{ di(t) }{ dt } + 
\frac 1 { LC } i(t) = 
\frac 1 L \frac{ dv_s(t) }{ dt }$$

> define damping coefficient as
> $$\alpha = \frac{ R }{ 2L }$$
> define undamped resonant frequency as
> $$\omega_0 = \frac 1 { \sqrt{ LC } }$$
> define force function
> $$f(t) = \frac 1 L \frac{ dv_s(t) }{ dt }$$

$$\implies 
\frac{ d^2i(t) }{ dt^2 } + 
2 \alpha \frac{ di(t) }{ dt } + 
\omega_0^2 i(t) = 
f(t)$$

### Solution of the [[Differential Equation]]

我們可以把任何 equation 變成 [[Higher Order DE解法|2nd order differential equation]] ，因此我們來考慮以下等式的解。$x(t)$ 可以是 voltage ，也可以是 current

$$\frac{d^2x(t)}{ dt^2 } + 
2\alpha \frac{ dx(t) }{ dt } + 
\omega_0^2x(t) = f(t)$$

$x(t)$ 的解含有 complementary solution 和 particular solution

$$x(t) = x_p(t) + x_c(t)$$

complementary solution 可以用 [[Auxiliary Function]] 來解，產生的下式稱為 characteristic equation

$$s^2 + 2\alpha s + \omega_0^2 = 0$$

並且 damping ratio 的定義如下

$$\zeta = \frac{ \alpha }{ \omega_0 }$$

根據 damping ratio 的值，會有幾種情況：

1. Overdamped case ($\zeta > 1$)

$$x_c(t) = K_1e^{ s_1t } + K_2e^{ s_2t }$$

2. Critically damped

$$x_c(t) = K_1e^{ s_1t } + K_2te^{ s_2t }$$

3. Underdamped

$$x_c(t) = 
K_1 e^{ -\alpha t }\cos(\omega_n t) + 
K_2 e^{ -\alpha t }\sin(\omega_n t)$$

在 underdamped 的情況下，我們定義 natural frequency

$$\omega_n = \sqrt{ \omega_0^2 - \alpha^2 }$$

## [[Impedance]]

![[RLC Circuit Impedance.png]]

$$\frac{ V(s) }{ I(s) }
= \underbrace{ Z(s) }_{ \text{ 阻抗 (Impedance) } } = 
R + sL + \frac{ 1 }{ sC }$$

$$\implies Z(s) = \frac{ RCs + LCs^2 + 1 }{ sC }$$

求 $s$ when $Z(s) = 0$

$$\implies LCs^2 + RCs + 1 = 0$$

$s$ 稱為 zeroes

---

求 $s$ when $sC = 0$

$$sC = 0$$

$s$ 稱為 poles

## 虛數與實數

若 $s$ 以 $j\omega$ 代入

$$Z(j\omega) = \left.Z(s)\right\vert_{ s = j\omega } = \frac{ 1 - LC\omega^2 + j\omega RC }{ j\omega C }$$

[[Fourier Transform]]
$$\mathcal{ F }(\omega) = 
\int_0^\infty f(t)\cdot e^{ -j\omega t }dt$$
.
$$Z(j\omega) = 
R(\omega) + jX(\omega)$$

| $$R(\omega)$$   | $$jX(\omega)$$ |
| --------------- | -------------- |
| 實數部份        | 虛數部份       |
| 電阻 Resistance | 電抗 Reactance |

這兩個合起來叫做阻抗

# RLC Circuit (並聯)

![[RLC circuit(並聯).png]]

## 推導過程

[[Impedance]] $Z(s)$
(Resistance in $S$-domain)

$$Z(s) = \frac{ 1 }{ \frac{ 1 }{ 1 / sc } + \frac{ 1 }{ R } + \frac{ 1 }{ sL } }$$

Solve $V(s)$

$$V(s) = Z(s) \cdot \frac{ I_{ dc } }{ s }$$

Solve $I_L(s)$

$$I_L(s) = \frac{ V(s) }{ sL }$$

$$ = \frac{ 1 }{ sL } \cdot \frac{ I_{ dc } }{ s } \cdot \frac{ s/c }{ s^2 + \frac{ 1 }{ Rc }s + \frac{ 1 }{ Lc } }$$

$$ = I_{ dc }\underbrace{ \left( \frac{ 1 }{ s } \cdot \frac{ \omega_n^2 }{ s^2 + 2\xi \omega_n s + \omega_n^2 } \right) }_{ G(s) }$$

where $\xi = \frac{ 1 }{ 2R }\sqrt{ \frac{ L }{ c } }$

$$\omega_n = \sqrt{ \frac{ 1 }{ Lc } }$$

by Partial Fraction: 

$$G(s) = \underbrace{ \frac{ A_1 }{ s } }_{ u_s(t) } + \underbrace{ \frac{ A_2 (s + \sigma) }{ (s + \sigma)^2 + \omega_d^2 } }_{ \cos } + \underbrace{ \frac{ A_3 \cdot \omega_d }{ (s + \sigma)^2 + \omega_d } }_{ \sin }$$

where $\sigma = \xi \cdot \omega_n\; ,\;\omega_d = \sqrt{ 1 - \xi^2 }\cdot \omega_n$

$$A_1 = (G(s)\cdot s)\vert_{s = 0}$$

$$ = 1$$

移項

$$G(s) - \frac{ 1 }{ s } = \frac{ 1 }{ s }\left( \frac{s(s + 2\xi\omega_d)}{ s^2 + 2\xi\omega_n s + \omega_n^2 } \right)$$

$$ = \frac{(s + \sigma)}{ (s + \sigma)^2 + \omega_d^2 } + \frac{ \xi\omega_n }{ (s + \sigma)^2 + \omega_d }$$
.
$$A_2 = -1$$
.
$$A_3 = \frac{ -\xi }{ \sqrt{ 1 - \xi^2 } }$$
.
$$i_L(t) = I_{ dc }( \underbrace{ 1 }_{ \mathcal{ L }^{ -1 }\{ \frac{ 1 }{ s } \} \quad \text{ steady state } } - \underbrace{ e^{ -\sigma t }\cos\omega t - A_3 e^{ -\sigma t }\sin \omega dt }_{ \text{ transient Response } })$$

$$i_L = I_{ dc }\left(1 - \underbrace{ \sqrt{ 1 + A_3^2 } }_{  = \frac{ 1 }{ \sqrt{ 1 - \xi^2 } }  } \cdot e^{ -\sigma t }\sin(\omega dt + \beta)\right)$$
.
$$\beta = \tan^{ -1 }\frac{ \sqrt{ 1 - \xi^2 } }{ \xi } = \tan^{ -1 }\frac{ 1 }{ A_3 }$$

## 代值進去

$$\left\{
\begin{array}{}
	R = 625 \Omega \\
	c = 25nF \\
	L = 25 mH
\end{array}
\right.$$

$$\xi = \frac{ 1 }{ 2R }\sqrt{ \frac{ L }{ c } }$$

$$ = \frac{ 1 }{ 2 \cdot 625 }\cdot \sqrt{ \frac{ 25m }{ 25n } }$$

$$ = 0.8$$
.
$$\omega_n = \sqrt{ \frac{ 1 }{ Lc } } = \frac{ 1 }{ 25m \cdot 25n }$$

$$ = 40krad/s$$

$$ = 6kHz$$
.
$$\sigma = \xi \omega_n = 32krad/s$$
.
$$\omega_d = \sqrt{ 1 - \xi^2 }\omega_n = 24krad/s$$
.
$$i_L = 24\left(1 - \frac{ 1 }{ 0.6 }e^{ -32kt }\sin(24kt + \beta)\right)$$
.
$$\beta = \tan^{ -1 }\frac{ 0.6 }{ 0.8 } = 37\degree$$

## 交流電的情況

![[RLC circuit (並聯AC).png]]

$$i_s(t) = I_{ max }\cdot\sin(\omega t)$$
.
$$I_s(t) = \mathcal{ L }\{I_{ max }\sin\omega t\} = I_{ max }\cdot \frac{ \omega }{ s^2 + \omega^2 }$$
.
$$I_L(s) = \frac{ I_{ max }\cdot \omega }{ s^2 + \omega^2 }\cdot \left( \frac{ \omega_n^2 }{ s^2 + 2\xi\omega_n s + \omega_n^2 } \right)$$

Partial Function yields that

$$I_L(s) = \underbrace{ \frac{ A_1 }{ s - j\omega } + \frac{ \bar{ A }_1 }{ s + j\omega } }_{ \text{ steady state } } + \underbrace{ \frac{ A_2 }{ (s + \sigma) + j\omega_d } + \frac{ \bar{ A }_2 }{ (s + \sigma) - j\omega_d } }_{ \text{ trasient Response } }$$

1. $A_2$, $\bar{ A }_2$ are associated with the transient response which can die away fast
2. $A_1 = G(s) \cdot (s - j\omega)\vert_{ s = j\omega }$
$= \frac{ 1 }{ 2j }G(j\omega)$
3. Steady [[state]] Response

$$I_L(t) = \mathcal{ L }^{ -1 }\left\{ \frac{ Ae^{ j\theta } }{ 2j } \cdot \frac{ 1 }{ s - j\omega } + \frac{ Ae^{ -j\theta } }{ 2j } \cdot \frac{ 1 }{ s + j\omega } \right\}$$

$$A = \vert G(j\omega) \vert$$

$$\theta = \angle G(j\omega)$$

$$I_L(t) = I_{ max }A\frac{ e^{ j(\omega t + \theta) } - e^{ -j(\omega t + \theta) } }{ 2j }$$

[[Euler Formula]]
$$ = I_{ max } A \cdot \sin(\omega t + \theta)$$

# 交流電

![[RLC circuit 交流電.png]]

$$\vec{ I }_{ 1 } = 0.2 \angle 37 \degree$$

$$i_1 = 0.2\sin(\underbrace{ 1000 }_{ \omega }t + 27 \degree)$$
.
$$I_2 = \frac{ -j400 }{ -j400 + 800 }\cdot I_1$$

$$ = \frac{ 400 \angle -90\degree }{ \sqrt{ 5 } \times 400 \angle -26\degree } \cdot 0.2 \angle 37\degree$$

$$ = 0.09\angle -27\degree$$
.
$$I_3 = \frac{ 800 }{ -j400 + 800 } I_1$$

$$ = 0.18 \angle 63\degree$$

## Instantaneous [[Power]] and Average [[Power]]

![[Instantaneous Power and Average Power.png]]

$$V_i = \vert V_i \vert\angle 0\degree$$

$$I_1 = I_i = 0.2 \angle 37\degree$$

[[Power#Power Factor|Power factor]]: $V$ & $I$ 的角度差異 $\cos\theta_z$

$$Z(\omega) = \frac{ V(\omega) }{ I(\omega) } = \frac{ V }{ I }\angle\theta_z$$

Instant [[Power]]:

$$P(t) = v(t) \cdot i(t)$$

> $$v(t) = V\cos(\omega t +\theta_v) \qquad (V < \theta_v)$$
> $$i(t) = I\sin(\omega t + \theta_i) \qquad (I < \theta_i)$$

$$ = \frac{ V \cdot I }{ 2 }
\left(
\cos(\theta_v - \theta_i) +
\cos(2\omega t + \theta_v + \theta_i)
\right)$$

Average Pow:

$$P_{ avg } = \frac{ VI }{ 2 }\cos\theta_z$$

# Resonance

## Series

### Resonant Frequency

![[series resonance.png|350]]

$$Z_s(f) = 
j2\pi fL + R - j\frac{ 1 }{ 2\pi fC }$$

the resonant frequency $f_0$ is defined to be the frequency at which the [[impedance]] is purely resistive (the reactance is zero)

$$\implies 2\pi f_0 L = \frac{ 1 }{ 2\pi f_0 C }$$

$$\implies \underline{ 
	f_0 = \frac{ 1 }{ 2\pi \sqrt{ LC } }
}_{ \# }$$

### Quality Factor

Quality Factor $Q_s$:

$$\underline{ Q_s = \frac{ 2\pi f_0 L }{ R } }_{ \# }$$

$$\text{ or }$$

$$\underline{ Q_s = \frac{ 1 }{ 2\pi f_0CR } }_{ \# }$$

### [[Impedance]]

可以使用 Quality Factor 與 Resonant Frequency 簡化 [[Impedance]]

$$\underline{ Z_s(f) = R\left[ 1 + jQ_s\left( \frac{ f }{ f_0 } - \frac{ f_0 }{ f } \right) \right] }_{ \# }$$

## Parallel

A circuit containing both types of Energy Storage elements
i.e. [[inductor]] and [[capacitor]], exhibits a distinct behavior owing to the joint effect at a specific frequency

很像單擺的動能和位能（[[inductor]] 的磁場和 [[capacitor]] 的電場）有週期性的轉換

![[parallel resonant circuit.png|550]]

### [[Impedance]]

The [[impedance]] of the parallel resonance circuit is

$$\underline{ Z_p = \frac{ 1 }{ \frac 1 R + j2\pi fC - j\frac 1 {2\pi fL} } }_{ \# }$$

### Resonant Frequency

共振頻率發生在 pure [[resistive circuit]] ，所以

$$2\pi f_0C = \frac 1 { 2\pi f_0L }$$

$$\implies \underline{ f_0 = \frac 1 { 2\pi\sqrt{ LC } } }_{ \# }$$

At this frequency the [[inductor]] and the [[capacitor]] shuffle energy with each other.

### Quality Factor

$$\underline{ Q_p = \frac{ R }{ 2\pi f_0L } }_{ \# }$$

注意和 series 的情況差了一個倒數

也可以用 $C$ 表示（用共振頻率公式將 $L$ 替換為 $C$）

$$\implies \underline{ Q_p = 2\pi f_0CR }_{ \# }$$

並且可以用 quality factor 表示其共振頻率

$$\implies \underline{ Z_p = \frac{ R }{ 1 + jQ_p(f / f_0 - f_0 / f) } }_{ \# }$$

### Bandwidth

$$B = \frac{ f_0 }{ Q_p }$$

## Quality Factor

We define the Quality factor of parallel resonant circuit as follows.

$$I_L = QI_{ sc }$$

$$\underbrace{ Q }_{ \text{ current divider } } = \frac{ R\vert\vert \frac{ 1 }{ j\omega C } }{ (R \vert\vert \frac{ 1 }{ j\omega C }) + j\omega L } = \frac{ R }{ R(1 - \omega^2LC) + j\omega L }$$

$$\text{ since } \omega = \frac{ 1 }{ \sqrt{ LC } } \quad \text{ (resonant frequency) }$$

$$\vert Q\vert = \left\vert \frac{ R }{ j\omega L } \right\vert = \frac{ R }{ \omega L } = R\sqrt{ \frac{ C }{ L } }$$

$Q$ is much larger than one when $R$ is large and $C / L$ is large.

# AC Superposition

![[AC superposition scenario.png]]

Suppress $10V$

![[AC superposition suppressed 10V.png]]

$$I_1 = \frac{ 12\angle 0\degree }{ 2,4k - j1,2k }$$

$$ = 4.47 \angle 63\degree mA$$

Suppress $12V$

![[AC superposition suppressed 12V.png]]

$$I_2 = \frac{ 10\angle 90\degree }{ 2.4k + j8.8k } = 1.1\angle 90\degree - 65\degree$$

$$ = 1.1\angle 25\degree (mA)$$
.
$$I = I_1 + I_2$$

$$\implies i(t) = 4.47\sin(10kt + 63\degree) + 1.1\sin(40kt + 25\degree) (mA)$$

When $\omega = \frac{ 1 }{ \sqrt{ LC } } = 12.25krad/s$, the series resonance occurs and the $I$ is in phase with the input voltage.

# Frequency Response

## Signal

> Fourier Expansion:
> $$v(t) = v_0 + \sum_{ n = 1 }^\infty a_n \cos(\omega_n t) + b_n\sin(\omega_n t)$$
> $$\omega_n = n\cdot \underbrace{ \omega_0 }_{ \text{ base frequency } }$$

![[frequency response.png]]

## [[Filter]]

![[Filter]]

---

參考資料:

電工學上課

---

link:

[[Inverse Laplace Transform#方法二 Decomposition of Fractions]]
[[Capacitor]]
[[Inductor]]
[[Resistor]]
[[Differential Equation]]