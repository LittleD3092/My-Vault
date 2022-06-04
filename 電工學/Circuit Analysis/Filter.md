標籤: #電工學 

---

# Fourier Analysis

All real-world signals are sums of sinusoidal components, Fourier analysis is a mathematical technique for finding the amplitudes, frequencies, and phases of the components of a given waveform

# Filters

利用 [[capacitor]] 和 [[inductor]] 的 [[impedance]] 會隨著頻率變動，將特定頻率的波濾掉

如 [[Inductor]] 的 [[Impedance]]

$$Z_L = \omega L \angle 90\degree = 2\pi f L \angle 90\degree$$

頻率越高 [[Impedance]] 越高

---

Filter 依照功能包含四種
1. [[#Low Pass Filter]]：只有低頻率可以通過
2. [[#High Pass Filter]]：只有高頻率可以通過
3. [[#Band Pass Filter]]：只有特定頻率可以通過
4. [[#Band Rejection Filter]]：只有特定頻率以外的頻率可以通過

---

依照使用的零件包含三種
1. First-Order Filter
	- 分析時可以寫成 [[First Order Differential Equation]] 
	- 使用了 [[Capacitor]] 或 [[Inductor]] 其中之一與 [[Resistor]]
2. Second-Order Filter
	- 分析時可以寫成 Second Order Differential Equation 
	- 使用了 [[Resistor]] 、 [[Capacitor]] 和 [[Inductor]]
3. Operational Amplifier Filter
	- 使用到 [[Amplifier]]

## Transfer Function

Filter 的性質可以用 transfer function 來表示

$$H(f) = \frac{ { \bf V }_{ out } }{ { \bf V }_{ in } }$$

### Decibels

通常將 transfer function 的 magnitude 轉換成分貝，可以較好比較效率

$$\vert H(f)\vert_{ dB } = 
20\log\vert H(f) \vert$$

### Logarithmic Frequency Scales

通常在畫 transfer function 的圖時會使用 logarithmic scale ，常用的有
1. decade：十倍
2. octave：兩倍

$$
\begin{array}{}
	\text{ number of decades } & = &
	\log\left( \frac{ f_2 }{ f_1 } \right) \\
	\text{ number of octaves } & = & 
	\log_2\left( \frac{ f_2 }{ f_1 } \right)
\end{array}
$$

這樣表示頻率的優點在於可以讓 $10\sim 20Hz$ 與 $10MHz \sim 20MHz$ 的改變在圖上較清楚

## Low Pass Filter

### First-Order Lowpass Filters

#### RC Filter

![[RC Filter.png|400]]

$$
\left\{
	\begin{array}{}
		{\bf I} & = & 
		\frac{ {\bf V}_{ in } }
		{ R + \frac{ 1 }{ j2 \pi fC } } \\
		{ \bf V }_{ out } & = & 
		\frac{ 1 }{ j2\pi fC }{ \bf I }
	\end{array}
\right.
$$

$$\implies { \bf V }_{ out } = \frac 1{ j2\pi fC } \times \frac{ { \bf V }_{ in } }{ R + \frac{ 1 }{ j2\pi fC } }$$

$$\implies H(f) = \frac{ { \bf V }_{ out } }{ { \bf V }_{ in } } = \frac{ 1 }{ j2\pi fCR + 1 }$$

$$\implies H(f) = \frac{ 1 }{ 1 + j(f / f_B) } \qquad , f_B = \frac{ 1 }{ 2\pi RC }$$

$$\implies 
\left\{
	\begin{array}{}
		\vert H(f) \vert & = & 
		\frac{ 1 }
		{ \sqrt{ 1 + (f / f_B)^2 } } \\
		\angle H(f) & = & 
		-\text{arctan}\left(
			\frac{ f }{ f_B }
		\right)
	\end{array}
\right.$$

![[rc filter diagram.png]]

注意當 $f = f_B$ ，voltage 會是 $\frac{ 1 }{ \sqrt{ 2 } }$ 倍（$0.707$ 倍），power 會是 $\frac{ 1 }{ 2 }$ 倍（因為 $p$ 正比於 $v^2$）。因此我們把 $f_B$ 稱為 half-power frequency

#### LR Filter

![[lr filter schematic diagram.png]]

$$G(\omega) = \frac{ v_o(\omega) }{ v_i(\omega) } = \frac{ 1 }{ 1 + j\omega T } \qquad T = \frac{ L }{ R }$$

### Second-Order Lowpass Filters

![[lowpass filter circuits comparison.png]]

## High Pass Filter

### First-Order Highpass Filters

#### RL Filter

![[rl filter.png|350]]

$$G(\omega) = \frac{ v_o(\omega) }{ v_i(\omega) } = \frac{ j\omega T }{ 1 + j\omega T } \qquad T = \frac{ L }{ R }$$

$$G(\omega) = \frac{ \omega T }{ \sqrt{ 1 + (\omega T)^2 } } \angle90\degree - \tan^{ -1 }\omega T$$

![[high pass filter diagram.png|500]]

#### CR Filter

![[cr filter.png|350]]

$$H(f) = \frac{ { \bf V }_{ out } }{ { \bf V }_{ in } } = \frac{ j(f / f_B) }{ 1 + j(f / f_B) } \qquad , f_B = \frac{ 1 }{ 2\pi RC }$$

$$\implies 
\left\{
	\begin{array}{}
		\vert H(f) \vert = \frac{ f / f_B }{ \sqrt{ 1 + ( f / f_B )^2 } } \\
		\angle H(f) = 90\degree - \text{arctan}\left( \frac f {f_B} \right)
	\end{array}
\right.$$

### Second-Order Highpass Filters

![[second-order highpass filter.png]]

## Band Pass Filter

只留下訊號中的特定頻率

### Series

![[band pass filter series.png|500]]

We need a unit gain buffer to isolate two filters

![[band pass filter series with unit gain buffer.png]]

### RLC Series

![[RLC Circuit#Series]]

#### Transfer Function of Band Pass Series Filter

$${\bf I} = \frac{{\bf V}_s}{ Z_s(f) }$$

將 $Z_s(f)$ 代入

$${\bf I} = \frac{ {\bf V}_s / R }{ 1 + jQ_s(f / f_0 - f_0 / f) }$$

The voltage across the resistance is

$${ \bf V }_R = R {\bf I} = \frac{ {\bf V}_s }{ 1 + jQ_s(f / f_0 - f_0 / f) }$$

The transfer function

$$\underline{ \frac{ {\bf V}_R }{ { \bf V }_s } = \frac{ 1 }{ 1 + jQ_s(f / f_0 - f_0 / f) } }_{ \# }$$

#### Bandwidth

![[bandwidth.png|350]]

The bandwidth $B$ is the difference between the half-power frequencies.

$$\underline{ B = f_H - f_L }_{ \# }$$

$$\implies 
\underline{ B = \frac{ f_0 }{ Q_s } }_{ \# }$$

$$\implies \underline{ f_H \cong f_0 + \frac B 2 }_{ \# }$$

$$\implies \underline{ f_L \cong f_0 - \frac B 2 }_{ \# }$$

### Parallel

![[band pass filter parallel.png|450]]

[[#Low Pass Filter]] 和 [[#High Pass Filter]] 並聯

$$\omega_r = \frac{ 1 }{ \sqrt{ LC } }$$

$$G(\omega) = \frac{ v_o(\omega) }{ v_i(\omega) } = \frac{ -j\omega L }{ R(1 - \omega^2LC) - j\omega L } = \frac{ K\cdot j \frac{ \omega }{ \omega_l } }{ (1 + j\frac{ \omega }{ \omega_l })(1 + j\frac{ \omega }{ \omega_u }) }$$

![[band pass filter parallel diagram.png|300]]

## Band Rejection Filter

### LC Parallel

又稱為 Notch Filter，將已知的頻段部份去除

![[band rejection filter.png|500]]

$$\frac{ v_o }{ v_i } = 
G_{ BR }(j\omega) = 
\frac R 
{ j\omega L \vert\vert \frac 1 { j \omega C } + R }$$

$$G_{ BR }(\omega) = 1 - G_{ BP }(\omega)$$

$$ = 1 - \frac{ K j \frac{ \omega }{ \omega_l } }
{ (1 + j \frac \omega { \omega_l }) \cdot 
(1 + j\frac \omega { \omega_u }) }$$

![[diagram band rejection filter and band pass filter.jpg|300]]

$$B.W.\text{ (bandwidth) } = 
\frac{ \sqrt{ 1 -  4R^2 \frac{ C }{ L } } }
{ RC }$$

$$\omega_p \text{ (peak frequency) } = 
\frac 1 { \sqrt{ LC } }$$

$$\omega_u \text{ (upper frequency) } = 
\omega_p + \frac{ B.W. }{ 2 }$$

$$\omega_l \text{ (lower frequency) } = 
\omega_p - \frac{ B.W. }{ 2 }$$

### Series

![[series band-reject filter.png]]

## Operational [[Amplifier]] Filter

![[op amp filter.png]]

$$v_n = \frac{ Z_1 v_{ out } + Z_f v_{ in } }
{ Z_1 + Z_f }$$

$$\implies \frac{ v_{ out } }{ v_{ in } } = 
-\frac{ Z_f }{ Z_1 }$$

可以調整 $Z_1$ 和 $Z_f$ 來得到不同種類的 filter

Op amp filter 是一種 "Active Filter" ，也就是輸出的電流源和輸入的電流源不同，因此可以串接

### Low Pass Op Amp Filter

$$Z_1 = R$$

$$Z_f = R \vert\vert \frac 1 { j\omega C }$$

$$\implies \frac{ v_o }{ v_i } = 
\frac{ 
	-\frac{ 
		R \cdot \frac{ 1 }{ j\omega C } 
	}
	{
		R + \frac{
			1
		}
		{
			j\omega C
		}
	}
}
{ R } = 
\frac { -1 }{ 1 + j\omega RC }$$

### High Pass Op Amp Filter

$$Z_1 = R + \frac{ 1 }{ j\omega C }$$

$$Z_f = R$$

$$\implies \frac{ v_o }{ v_i } = 
-\frac{ j\omega RC }{ j\omega RC + 1 }$$

### Band Pass Op Amp Filter

$$Z_1 = R_1 + \frac{ 1 }{ j\omega C_1 }$$

$$Z_f = R_2 \vert\vert \frac{ 1 }{ j\omega C_2 } = 
\frac{ R_2 \cdot \frac{ 1 }{ j\omega C_2 } }
{ R_2 + \frac{ 1 }{ j\omega C_2 } } = 
\frac{ R_2 }{ 1 + j\omega R_2 C_2 }$$

![[band pass filter using operational amplifier filter.png]]

$$\implies \frac { v_o }{ v_i } = 
-\frac{ j\omega R_2C_1 }
{(j\omega R_1C_1 + 1)(j\omega R_2C_2 + 1)}$$

$$ = -\frac{ 
	K\cdot j\frac{ \omega }{ \omega_l } 
}{ 
	(1 + j\frac{ \omega }{ \omega_l })
	(1 + j\frac{ \omega }{ \omega_u })
}$$

$$\implies
\left\{
	\begin{array}{}
		\omega_l = \frac{ 1 }{ R_1 C_1 } \\
		\omega_u = \frac{ 1 }{ R_2 C_2 }
	\end{array}
\right.$$

---

參考資料:

電工學課本

---

link:

