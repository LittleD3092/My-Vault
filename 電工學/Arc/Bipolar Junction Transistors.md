標籤: #電工學 

---

![[npn bjt.png|500]]

# Current and Voltage Relationships

BJT 就像個閥門，Base 可以控制 Emitter 和 Collector 之間的電流。

> ![[Diode#Shockley Equation]]

![[npn bjt.png|500]]

Shockley equation for BJT:

$$\underline{
	i_E = I_{ES}\left[
		\exp\left(
			\frac{v_{BE}}{V_T}
		\right) - 1
	\right]
}_\#$$

The equation above is exactly the same equation as Shockley equation for diodes, except for changes in notation. 

We have let the emission coefficient $n$ equal unity since that is the appropriate value for most junction transistors.

- $I_{ES}$: saturation current, $10^{-12} \sim 10^{-16}\text A$
- $v_T$: thermal voltage, $26\text{mV@300K}$

By Kirchhoff's current law

$$\underline{
	i_E = i_C + i_B
}_\#$$

> We define $\alpha$ as the ratio of the collector current to the emitter current
> $$\underline{\alpha = \frac{i_C}{i_E}}_\#$$

Substitude Shockley equation into the ratio $\alpha$

$$\implies i_C = 
\alpha I_{ES} \left[
	\exp\left(
		\frac{v_{BE}}{V_T}
	\right) - 1
\right]$$

For $v_{BE}\gg V_T$

$$\implies 
	\underline{
		i_C \cong I_s \exp\left(
			\frac{v_{BE}}{V_T}
		\right)
	}_\#
$$

where $i_s$ is scale current

$$I_s = \alpha I_{ES}$$

---

> ratio $\alpha$:
> $$\alpha = \frac{i_C}{i_E}$$
> Kirchhoff's current law:
> $$i_E = i_C + i_B$$

From these two equations we get

$$\implies 
\left\{
	\begin{array}{l}
		i_B = (1 - \alpha)i_E \\
		i_C = \alpha i_E
	\end{array}
\right.$$

We define $\beta$ as the ratio of the collector current to the base current.

$$\underline{
	\beta = \frac{i_C}{i_B} = \frac{\alpha}{1 - \alpha}
}_\#$$

# Common-Emitter Characteristics

Common-Emitter Characteristics means the plots of "$i_B$ $\text{vs}$ $v_{BE}$" and "$i_C$ $\text{vs}$ $v_{CE}$"

![[common-emitter circuit and characteristics.png]]

(a) input characteristic

左邊的圖的公式為

$$i_B = (1 - \alpha)I_{ES}
\left[
	\exp\left(
		\frac{v_{BE}}{V_T}
	\right)
\right]$$

Notice that for appreciable current to flow at room temperature, $v_{BE}$ must be approximately $0.6 \sim 0.7 \text V$

---

(b) output characteristics

The transistor illustrated has $\beta = 100$

As long as the collector-base junction is reverse biased ($v_{BC} < 0$, $v_{CE} > v_{BE}$), we have

$$i_C = \beta i_B = 100 i_B$$

If the collector-base junction is foward biased, the collector current falls as shown at the left-hand edge of the output characteristics.

The BJT can amplify a signal applied to the base-emitter junction.

# Load-Line Analysis of a Common-Emitter Amplifier

A simple BJT amplifier circuit is shown in the figure

![[common-emitter amplifier.png|400]]

$V_{BB}$ and $v_{CC}$ "bias" the device at an operating point for which amplification of the ac input signal $v_{in}(t)$ is possible.

## Analysis of the Input Circuit

Applying Kirchhoff's voltage law to the left loop

$$V_{BB} + v_{in}(t) = R_Bi_B(t) + v_{BE}(t)$$

This is the "load line" of the transistor. To establish the load line, we need two points.

|           | $v_{BE}$          | $i_B$                           |
| --------- | ----------------- | ------------------------------- |
| 1st point | $V_{BB} + v_{in}$ | $0$                             |
| 2nd point | $0$               | $$\frac{V_{BB} + v_{in}}{R_B}$$ | 

![[input load line plot.png|400]]

隨著 $v_{in}$ 的變動，load line 也會上下平移

![[load line example of input.png]]

## Analysis of the Output Circuit

用右邊的 loop 來寫 Kirchhoff's current law

$$V_{CC} = R_C i_C + v_{CE}$$

這就是 output circuit 的 load line

![[output circuit loadline.png|450]]

我們可以從 [[#Analysis of the Input Circuit]] 得出 $i_B$ 的範圍，並且用上表得出 $i_C$ 與 $v_{CE}$ ，並且我們發現 common-emitter amplifier 是一種 inverting amplifier

> 當 $v_{in}$ 增加時， $i_B$ 也會增加
> $$\because i_B = \frac{V_{BB} + v_{in}}{R_B}$$
> 由上圖得知，若 $i_B$ 增加，$v_{CE}$ 會變小
> 因此此 amplifier 是 inverting amplifier

![[load line output circuit analysis example.png]]

---

從圖中看不出來，但是 output 不是準確的 sine wave。因為 transistor 有一個 curvature ，如下圖綠線

![[input load line plot.png|300]]

我們可以增加 $v_{in}$ 的振幅來較明顯看到這個現象，下圖是 $v_{in} = 1.2\sin(2000\pi t)$ 的 output plot

![[output plot of the amplifier for vin=1.2.png|400]]

在高點有被切掉，我們稱作 cutoff
在低點也有被切掉，我們稱作 saturation
在中間的反應較正常，我們稱作 active region

可以從 [[#Analysis of the Output Circuit]] 的圖看出以上三個 region 的 $v_{CE}$

![[amplification occurs only in active region.png|450]]

# pnp Bipolar Junction Transistors

前面的情況都是 npn BJT ，不過 pnp BJT 也一樣好用

![[pnp BJT.png]]

注意畫在上面的箭頭指向，pnp 和 npn 的方向相反

與 npn 一樣，我們可以寫下以下公式

$$
\left\{
	\begin{array}{}
		i_C & = & \alpha i_E \\
		i_B & = & (1 - \alpha)i_E \\
		i_C & = & \beta i_B \\
		i_E & = & i_C + i_B
	\end{array}
\right.
$$

前三個式子只有在

1. base-emitter junction 是 forward biased ($v_{BE} < 0$) 和 
2. collecter-base junction 是 reverse biased ($v_{BC} > 0$)

才會成立

對於一般的 pnp transistor, $\alpha \cong 0.99$, $\beta \cong 100$

For pnp transistor in the active region, 

$$
\left\{
	\begin{array}{}
		i_E & = & I_{ES}\left[
			\exp\left(
				\frac{-v_{BE}}{V_T}
			\right) - 1
		\right] \\
		i_B & = & (1 - \alpha)I_{ES}\left[
			\exp\left(
				\frac{-v_{BE}}{V_T}
			\right) - 1
		\right]
	\end{array}
\right.
$$

這個公式與 [[#Current and Voltage Relationships]] 相似，只是 $v_{BE}$ 用 $-v_{BE}$ 代替

- $I_{ES}$: $10^{-12} \sim 10^{-16}\text A$
- $V_T$: $\cong0.026 \text V @300 \text K$

The common-emitter characteristics of a pnp transistor are exactly the same as for the npn transistor, except that the values on the voltage axes are negative.

![[common-emitter characteristics for a pnp BJT.png]]

# Large-Signal DC Circuit

## Models

active region:

![[BJT large-signal models active region.png|500]]

saturation region:

![[BJT large-signal models saturation region.png|500]]

cutoff region:

![[BJT large-signal models cutoff region.png|500]]

## Analysis for Basic Bias Circuit

The step-by-step procedure is as follows:

1. Choose one of the three BJT operating regions: saturation, cutoff, or active
2. Analyze the circuit to determine $I_C, I_B, V_{BE}, V_{CE}$ by using the transistor model for the region chosen
3. Check to see if the constraints for the chosen region are met. If so, the analysis is completed. If not, return to Step 1, and choose a different region.

### Example

> <font face = "roman">The dc bias circuit shown in figure has $R_B = 200\text k\Omega$, $R_{C} = 1\text k\Omega$, and $V_{CC} = 15\text V$. The transistor has $\beta = 100$. Solve for $I_C$ and $V_{CE}$.</font>
> ![[bias circuit BJT example.png|200]]

![[equivalent circuit for BJT bias circuit example.png]]

Assume cutoff:

$$V_{BE} = 15 \text V$$

$$V_{CE} = 15 \text V$$

However, cutoff region requires

$$V_{BE} < 0.5 \text{V}$$

$$V_{CE} < 0.5 \text V$$

Assume saturation:

$$I_C = \frac{V_{CC} - 0.2}{R_C} = 14.8 \text{mA}$$

$$I_B = \frac{V_{CC} - 0.7}{R_B} = 71.5\mu \text A$$

$$\beta = 100$$

However, saturation region requires

$$I_B > 0$$

$$\beta I_B > I_C > 0$$

Assume active region:

$$I_B = \frac{V_{CC} - 0.7}{R_B} = 71.5 \mu \text A$$

$$I_C = \beta I_B = 7.15 \text{mA}$$

$$V_{CE} = V_{CC} - R_C I_C = 7.85 \text V$$

Active region requires

$$I_B > 0$$

$$V_{CE} > 0.2 \text V$$

Therefore the transistor operates in active region with

$$
\underline{
	\left\{
		\begin{array}{}
			I_C = 7.15 \text{mA} \\
			V_{CE} = 7.85 \text V
		\end{array}
	\right.
}_\#
$$

## Analysis of Separate Source Bias Circuit

我們希望 Q point 永遠在 active region ，這樣才可以把 bias circuit 當作 amplifier 來用。經過上面的 [[#Example]] 我們已經知道 active region 的條件與 $\beta$ 息息相關，因此在實際應用上我們會使用適合的 $\beta$ 。

但是這樣在大量製造時必須考慮到不同 $\beta$ ，因此我們想到了將電源分開的方法。底下的題目分析了這種 circuit ，注意 $\beta$ 在計算過程中的影響變小了

> <font face = "roman">Solve for $I_C$ and $V_{CE}$ in the circuit of figure given that $V_{CC} = 15\text V$, $V_{BB} = 5 \text V$, $R_C = 2\text k \Omega$, $R_E = 2\text k \Omega$, and $\beta = 100$. Repeat for $\beta = 300$.</font>
> ![[separate source bias circuit.png|300]]

Assume that the transistor is in the active region

![[separate source bias circuit equivalent circuit assuming in active region.png|400]]

Writing a voltage equation through $V_{BB}$, the base-emitter junction, and $R_E$

$$V_{BB} = 0.7 + I_E R_E$$

This can be solved for the emitter current

$$I_E = \frac{V_{BB} - 0.7}{R_E} = 2.15 \text{mA}$$

==Notice that the emitter current does not depend on the value of $\beta$==

Next, we compute the base current and collector current

$$\underline{I_C = \beta I_B}$$

$$I_E = I_B + I_C$$

Substitude $I_C$ into second equation

$$I_E = (\beta + 1)I_B$$

Solve for base current

$$\implies \underline{I_B = \frac{I_E}{(\beta + 1)}}$$

Write a voltage equation around the collector loop

$$V_{CC} = R_CI_C + V_{CE} + R_EI_E$$
.
$$\implies V_{CE} = V_{CC} - R_CI_C - R_EI_E$$
.
$$\implies V_{CE} = V_{CC} - R_C\beta I_B - R_EI_E$$
.
$$\implies V_{CE} = V_{CC} - R_C\cdot \frac{\beta I_E}{\beta + 1} - R_E I_E$$

According to the equation above, $V_{CC}$, $R_C$, $I_E$ are independent to $\beta$. Also we find out that $\beta$ has small influence when $\beta \gg 1$.

Substituting values found previously,

| $\beta$ | $I_B(\mu \text A)$ | $I_C(\text{mA})$ | $V_{CE}(\text V)$ |
| ------- | ------------------ | ---------------- | ----------------- |
| $100$   | $21.3$             | $2.13$           | $6.44$            |
| $300$   | $7.14$             | $2.14$           | $6.42$            |

## Analysis of the Four-Resistor Bias Circuit

經過 [[#Analysis of Separate Source Bias Circuit]] ，我們發現將 source 分為兩個部份很有幫助，但是在一個電路板裡塞入兩個 source 是不太可能的事情。

因此我們利用 voltage divider 創造第二個 source 。

![[original four-resistor bias circuit.png|250]]

可以看出 $R_1$ 與 $R_2$ 形成的 voltage divider 將輸入 base 的電壓固定了，相比之前的 bias circuit 較不會受到 $\beta$ 影響

將 $V_{CC}$ 拆開

![[equivalent circuit of four-resistor bias circuit.png|300]]

將虛線左邊用 Thevenin Equivalent Circuit 改寫

![[thevenin equivalent four-resistor bias circuit.png|300]]

$$\underline{R_B = \frac{1}{1 / R_1 + 1 / R_2} = R_1 \vert\vert R_2}_\#$$

$$\underline{V_B = V_{CC}\frac{R_2}{R_1 + R_2}}_\#$$

最後用 active region transistor model 替換

![[active region transistor model four resistor bias circuit.png|400]]

寫 voltage equation

$$V_B = R_BI_B + V_{BE} + R_EI_E$$

Use $I_E = (\beta + 1)I_B$ substitude and solve to find that

$$\underline{
	I_B = \frac{V_B - V_{BE}}{R_B + (\beta + 1)R_E}
}_\#$$

Once $I_B$ is known, $I_C$ and $I_E$ can easily be found. Then, we can write a voltage equation around the collector loop and solve for $V_{CE}$

$$\underline{
	V_{CE} = V_{CC} - R_CI_C - R_EI_E
}_\#$$

# Small-Signal Equivalent Circuits

在小訊號的變數寫法有一定規則

$$i_B(t) = I_{BQ} + i_b(t)$$

- $i_B(t)$: We use lower case symbols with uppercase subscripts for total currents and voltages
- $I_{BQ}$: DC Q-point currents and voltages are denoted by uppercase symbols with uppercase subscripts
- $i_b(t)$: We denote the changes in currents and voltages from the Q point by lowercase symbols with lowercase subscripts.

![[small signal notation.png|400]]

Similarly, 

$$v_{BE}(t) = V_{BEQ} + v_{be}(t)$$

Now we consider how the small signal components are related in the BJT. The total base current is given in terms of the total base-to-emitter voltage:

$$i_B = (1 - \alpha)I_{ES}\left[
	\exp\left(
		\frac{v_{BE}}{V_T}
	\right) - 1
\right]$$

We are concerned with operation in the active region, for which the $1$ inside the brackets is negligible and can be dropped

$$\implies I_{BQ} + i_b(t) = (1 - \alpha)I_{ES}\exp\left[
	\frac{V_{BEQ} + v_{be}(t)}{V_T}
\right]$$

$$\implies I_{BQ} + i_b(t) = (1 - \alpha)I_{ES}\exp\left(
	\frac{V_{BEQ}}{V_T}
\right)\exp\left[
	\frac{v_{be}(t)}{V_T}
\right]$$

Also, at the Q point, 

$$I_{BQ} = (1 - \alpha)I_{ES}\exp\left(
	\frac{V_{BEQ}}{V_T}
\right)$$

Substituting Q point equation into equation above, we have

$$I_{BQ} + i_b(t) = I_{BQ}\exp\left(
	\frac{v_{be}(t)}{V_T}
\right)$$

> For $\vert x\vert < 1$, the following approximation holds
> $$\exp(x) \cong 1 + x$$

$$\implies I_{BQ} + i_b(t) \cong I_{BQ}
\left[
	1 + \frac{v_{be}(t)}{V_T}
\right]$$

We subtract $I_{BQ}$ from both sides and define $r_{\pi} = V_T / I_{BQ}$

$$\underline{
	i_b(t) = \frac{v_{be}(t)}{r_\pi}
}_\#$$

For $r_\pi$, we substitude $I_{BQ} = I_{CQ} / \beta$

$$\underline{
	r_\pi = \frac{\beta V_T}{I_{CQ}}
}_\#$$

> At room temperature, $V_T \cong 0.026 \text V$. A typical value of $\beta$ is $100$, and a typical bias current for a small-signal amplifier is $I_{CQ} = 1 \text{mA}$.
> 
> These values yield $r_\pi = 2600\Omega$.

The signal components are related by

$$\underline{
	i_c(t) = \beta i_b(t)
}_\#$$

---

參考資料:

電工學課本

---

link:

[[Kirchhoff's Law]]
[[Amplifier]]