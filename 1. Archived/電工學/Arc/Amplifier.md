標籤: #電工學 

---

[TOC]

---

# Concept

Amplifier 是一種將訊號放大的東西

$$\underbrace{ y(t) }_{ \text{ Output } } = \underbrace{ A }_{ \text{ Gain (fixed) } } \underbrace{ x(t) }_{ \text{ Input } }$$

一個 voltage amplifier 的 schematic diagram 會長這樣

![[schematic diagram of amplifier.png]]

$v_s$: voltage of source
$R_s$: resistance of source
$R_L$: load resistance

$v_i$: input voltage
$v_o$: output voltage
$i_o$: output current
$A_{ voc }$: 在 open circuit 的情況下，amplifier 放大 voltage 的倍數

Amplifier 包含了 3 個可分析的參數
1. [[#Voltage Gain]]
2. [[#Current Gain]]
3. [[#Power Gain]]

## Voltage Gain

Voltage 放大了幾倍

$$v_o(t) = A_v v_i(t)$$

$A_v$: Voltage Gain

## Current Gain

Current 放大了幾倍

$$A_i = \frac{ i_o }{ i_i } = \frac{ v_o / R_L }{ v_i / R_i } = A_v \frac{ R_i }{ R_L }$$

## Power Gain

$$G = \frac{ P_o }{ P_i } = \frac{ V_o I_o }{ V_i I_i } = A_v A_i = (A_v)^2 \frac{ R_i }{ R_L }$$

## Cascaded Amplifiers

可以將多個 Amplifier 串接在一起，將放大倍數乘起來

當多個 Amplifier 串接在一起

$$A_v = A_{ v1 } A_{ v2 }$$

## Power Supplies

amplifier 需要使用 power supply 協助運作，power 的流動如下圖

![[illustration of power flow in amplifier.png]]

可以看到有部份的 output signal 是 power supply 提供的

## Efficiency

這個 efficiency 是指 power supply 與輸出訊號的效率關係，可以用以下公式計算

$$\eta = \frac{ P_o }{ P_s } \times 100 \%$$

$P_o$: output power
$P_s$: supply power

# Other Amplifiers

除了上面提到的 voltage amplifier 以外，還有其他種類的 amplifier

1. [[#Current Amplifier]]

## Current Amplifier

以下是 current amplifier 的樣子

![[current amplifier.png]]

就和 [[Kirchhoff's Law#Thevenin Norton-Equivalent-Circuit Analysis|Thevenin Norton Circuit]] 一樣，current amplifier 和 voltage amplifier 也可以互相轉換，譬如以下例題

> Find the current-amplifier model of the voltage-amplifier model shown below.
> ![[example of converting a voltage amplifier to a current amplifier.png]]

為了找到 short-circuit current gain ，我們將 output terminal short ，找到以下關係

$$
\left\{
	\begin{array}{}
		i_i = \frac{ v_i }{ R_i } \\
		i_{ osc } = 
		\frac{ A_{ voc } v_i }{ R_o }
	\end{array}
\right.
$$

The short-circuit current gain is

$$A_{ isc } = \frac{ i_{ osc } }{ i_i } = 
A_{ voc } \frac{ R_i }{ R_o } = 10^3$$

## Transconductance Amplifier

類似 [[#Current Amplifier]] ，但是 dependent current source 依據的是 $v_{ in }$

![[transconductance-amplifier model.png]]

gain parameter 用 $G_{ msc }$ 表示，如下

$$G_{ msc } = \frac{ i_{ osc } }{ v_i }$$

## Transresistance Amplifier

類似 voltage amplifier ，與 [[#Transconductance Amplifier]] 相反。是一個 voltage amplifier 的接法和 current dependent voltage source

![[transresistance amplifier.png]]

$$R_{ moc } = \frac{ v_{ ooc } }{ i_i }$$

# Practical and Ideal Amplifiers

chart of ideal amplifiers:

| Amplifier Type                                          | Input Impedance | Output Impedance | Gain Parameter |
| ------------------------------------------------------- | --------------- | ---------------- | -------------- |
| [[#Ideal Voltage Amplifier\|Voltage]]                   | $$\infty$$      | $$0$$            | $$A_{ voc }$$  |
| [[#Ideal Current Amplifier\|Current]]                   | $$0$$           | $$\infty$$       | $$A_{ isc }$$  |
| [[#Ideal Transconductance Amplifier\|Transconductance]] | $$\infty$$      | $$\infty$$       | $$G_{ msc }$$  |
| [[#Ideal Transresisstance Amplifier\|Transresistance]]  | $$0$$           | $$0$$            | $$R_{ moc }$$  |

## Practical Amplifier

![[Practical Amplifier.png]]

$$y(t) = \underbrace{ A(x, t, T) }_{ \text{ Nonlinear } } \cdot (x(t) + x_{ \text{ offset } }(t, T))$$

$t$: time
$T$: temperature

## Ideal Voltage Amplifier

需要檢測 open-circuit voltage 並且產生放大後的 voltage ，因此具有無限大的 input impedance 與 0 output impedance

![[Ideal Voltage Amplifier.png]]

$A$: Voltage Gain

## Ideal Current Amplifier

需要檢測 short-circuit current 並產生放大後的 current ，因此有 0 input impedance 和無限大的 output impedance

![[Ideal Current Amplifier.png]]

## Ideal Transconductance Amplifier

[[#Transconductance Amplifier]]

檢測 $v_{ oc }$ 並產生正比於 $v_{ oc }$ 的電流，因此有無限大的 input impedance 和無限大的 output impedance

## Ideal Transresisstance Amplifier

檢測 $i_{ sc }$ 並產生正比於 $i_{ sc }$ 的電壓，因此有 0 input impedance 和 0 output impedance

## Practical Current Amplifier

![[Practical Current Amp.png]]

# Frequency Response

在交流電的情況下， gain parameter of amplifier 不會是常數，因此 gain parameter 有更廣義的定義

$$A_v = \frac{ {\bf V}_o }{ {\bf V}_i }$$

${\bf V}_o$: 輸出電壓 phasor
${\bf V}_i$: 輸入電壓 phasor
$A_v$: complex gain of amplifier

# Operational Amplifier

![[Operational Amplifier.png]]

上面的原理圖簡化後變成下面的表示方式

![[Operational Amplifier Simplified.png]]

$p$: positive (non-Inverting terminal)
$n$: negative (Inverting terminal)

## Ideal OP amp & Practical OP amp comparison

|                  | $$r_i$$      | $$r_0$$        | $$A$$              | $$v_{ ps }$$ |
| ---------------- | ------------ | -------------- | ------------------ | ------------ |
| Ideal OP amp     | $$\infty$$   | $$0$$          |                    |              |
| Practical OP amp | $$1M\Omega$$ | $$100 \Omega$$ | $$10^5 \sim 10^6$$ | $$15V$$      | 

# Amplifier Usages

## Inverting Amplifier

![[Inverting Amplifier.png|450]]

step1. negative feedback is present, $v_x = 0$

step2.

$$\frac{ v_{ in } - v_x }{ R_1 } = 
\frac{ v_x - v_o }{ R_2 } = i_1 = i_2$$

since $v_x = 0$

$$\implies \underline{ 
	\frac{ v_o }{ v_{ in } } = 
	-\frac{ R_2 }{ R_1 }
}_{ \# }$$

## Non-inverting Amplifier

![[non-inverting amplifier.png|450]]

step1. negative feedback is present, $v_i = 0$

step2. since $v_i = 0$, $v_{ in } = 1$

step3. 

$$\frac{ v_1 }{ R_1 } = 
\frac{ v_o - v_1 }{ R_2 }$$

$$\implies \frac{ v_{ in } }{ R_1 } = 
\frac{ v_o - v_{ in } }{ R_2 }$$

$$\implies v_{ in }R_2 = 
v_oR_1 - v_{ in } R_1$$

$$\implies v_{ in }(R_2 + R_1) = 
v_oR_1$$

$$\implies \frac{ v_o }{ v_{ in } } = 
\frac{ R_1 + R_2 }{ R_1 } = 
1 + \frac{ R_2 }{ R_1 }$$

## Voltage Follower (Unit Gain Buffer)

![[voltage follower.png|450]]

在 [[#Non-inverting Amplifier]] 的結果中， $R_2 = 0$, $R_1 \rightarrow \infty$

## Summing Amplifier

![[Summing Amplifier.png|500]]

$R_F$: Feedback 回授

Assuming 
$$v_d \simeq 0$$
$$i_n = 0$$
.
$$v_0 = -\left(\frac{ R_F }{ R_1 }v_1 + \frac{ R_F }{ R_2 }v_2\right)$$

## Difference Amplifier

![[difference amplifier.png|550]]

step1. negative feedback is present, $v_d = 0$

step2. $v_p = v_n$

$$\implies 
v_1 \times \frac{ R_4 }{ R_3 + R_4 } = 
(v_2 - v_o) \times 
\frac{ R_2 }{ R_1 + R_2 } + 
v_o$$

$$\implies 
v_1 \times \frac{ R_4 }{ R_3 + R_4 } = 
\frac{ R_2 }{ R_1 + R_2 }v_2 + 
\frac{ R_1 }{ R_1 + R_2 }v_o$$

$$\implies v_o = 
\left(
	\frac{ R_4 }{ R_3 + R_4 }v_1 - 
	\frac{ R_2 }{ R_1 + R_2 }v_2
\right)\times
\frac{ R_1 + R_2 }{ R_1 }$$

$$ = \frac{ R_4(R_1 + R_2)v_1 }
{ R_1(R_3 + R_4) } - 
\frac{ R_2 }{ R_1 }v_2$$

step3. replace $R_4$ with $R_3, R_1, R_2$

> $$\frac{ R_4 }{ R_3 } = \frac{ R_2 }{ R_1 }$$
> $$\implies R_4 = \frac{ R_2 }{ R_1 } R_3$$

$$\implies v_o = 
\frac{ R_2 R_3 }{ R_1 } \times 
\frac{ (R_1 + R_2)v_1 }{ 
	R_1\left(
		R_3 + \frac{ R_2 }{ R_1 }R_3
	\right) 
} - \frac{ R_2 }{ R_1 }v_2$$

$$ = 
\frac{ R_2 }{ R_1 } \times 
\frac{ (R_1 + R_2)v_1 }
{ R_1(1 + \frac{ R_2 }{ R_1 }) } - 
\frac{ R_2 }{ R_1 }v_2$$

$$ = \frac{ R_2 }{ R_1 }(v_1 - v_2)$$

## Integrators

![[integrators.png|500]]

step1. negative feedback is present, $v_n = v_p = 0$

step2.

$$i_{ in } = \frac{ v_{ in } }{ R }$$

step3.

$$v_c = \frac 1 C \int_0^t i_{ in }dt$$

$$ = \frac 1 C \int_0^t \frac{ v_{ in } }{ R }dt$$

$$ = \frac 1 {RC} \int_0^tv_{ in }dt$$

step4.

$$v_o = -v_c$$

$$ = \underline{ 
	\frac{ -1 }{ RC }\int_0^t v_{ in }dt 
}_{ \# }$$

## Differentiator

![[differentiator.png|500]]

step1. negative feedback is present, $v_n = v_p = 0$

step2. 

$$v_{ in } = \frac 1 C \int_0^t i_{ in }dt$$

$$\implies i_{ in } = C\frac{ dv_{ in } }{ dt }$$

step3.

$$v_R = RC \frac{ dv_{ in } }{ dt }$$

step4.

$$v_o = -v_R = \underline{ 
	-RC\frac{ v_{ in } }{ dt }
}_{\#}$$

---

參考資料:

電工學 2022-03-07

---

link:

