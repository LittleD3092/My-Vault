標籤: #電工學 

---

![[diode.png|300]]

只能讓電流單方向（上圖中往左）流動

> <font face = "serif">Allow only the current flows in one direction</font>

# Depletion Region

![[depletion region.png|200]]

電子流動的範圍

# Reverse/Right Position

![[Diode in Reverse Bias.png|200]]

External Electric [[Field]] increases the blocking force of electron flow through diffusion. Depletion Region is then enlarged and there is only little current flow.

The leaking current is known as the reverse saturation current due to "generation". ($I_{ ss }$)

---

![[Diode in right position.png|200]]

External Electric [[Field]] weakened the built-in Electric [[Field]]. The diffusion is again activated and thus the current flows from $P$ to $N$.

## Shockley Equation

![[general diode characteristic.png|500]]

$$i_D = 
I_{ s }\left( 
	\exp\left(
		\frac{ v_D }{ nv_T }
	\right) - 1 
\right)$$

This is known as the Shockley Equation.

- $I_s$: saturation current, $10^{-14}\text A$ for small-signal junction diodes at $300\text K$. $I_s$ depends on temperature, Doubling for each $5\text K$ increase in temperature for silicon devices.
- $n$: emission coefficient, has value between $1$ and $2$

$v_T$ is given by:

$$v_T = \frac{ kT }{ q } \quad 
\text{ (thermal voltage, 26mV@room temp) }$$

- $T$: temperature in $\text K$
- $k$: $1.38 \times 10^{-23} \text{J/K}$, Boltzmann's constant
- $q$: $1.60 \times 10^{-19}\text C$, the magnitude of electrical charge of an electron

when $v_D >> v_T$

$$i_D \cong I_{ s } \exp\left(
	\frac{ v_D }{ nv_T }
\right)$$

# Diode Model

## Ideal Diode

![[ideal diode.png|250]]

## Practical Diode (Piecewise-Linear Diode Models)

![[practical diode.png|250]]

$v_{ th }$: Threshold Voltage, $0.7V$

# Rectifier Circuit

## Half-Wave Rectifier Circuits

![[half-rectifier with resistive load.png]]

在理想情況下，所有從反方向的電壓會被移除，因此只剩下正方向的電壓。

但是在實際情況下，正方向的電壓會受到 threshold voltage 影響，而 threshold voltage 一般為 $0.7\text V$

### Half-Wave Rectifier Circuit with Smoothing Capacitor

因為我們希望輸入到 load 裡面的電壓盡量是一樣的，不希望像是上圖中扇形一樣，因此會加上一個 capacitor。這樣當 diode 阻止電流通過時， capacitor 可以持續供給電壓給 load

![[half-wave rectifier circuit with smoothing capacitor.png]]

儘管電壓已經平穩許多，在 diode 重新讓電流通過的地方會有一個突起（圖中的 $V_r$），我們把這個現象叫做 ripple

如果挑選的 capacitor 太小的話，ripple 會很大，因此為了將 ripple 降到最小，我們會計算 capacitor 的容量需求

capacitor discharges for nearly the entire cycle, and the charge removed from the capacitor during one discharge cycle is

$$Q \cong I_LT$$

$T$: 週期

the charge removed from the capacitor is the product of the change in voltage and the capacitance

$$Q = V_r C$$

$$\implies \underline{ 
	C = \frac{ I_L T }{ V_r }
}_{ \# }$$

## Full-Wave Rectifier Circuits

full-wave rectifier 多提供了 half-wave rectifier 零電壓的部份，如下圖

並且有兩種 circuit 可以達到這種效果

![[full-wave rectifier circuit.png]]

![[diode-bridge full-wave rectifier.png]]

第一張圖使用了兩個 diode ，當兩個 source 的電壓都為正時會給 $A$ 左邊正電壓和 $B$ 的左邊負電壓，因此只有正電壓會通過 load 。反之也是一樣。

第二張圖利用了類似 whitestone bridge 的設計，並且將 $R_L$ 放在電橋的中間。如圖中綠色箭頭，電壓為正時會經過 $A, B$ ，而電壓為負時會經過 $C, D$

這兩種 circuit 也可以使用 capacitor 並聯 load 讓電壓平整。這時需要的 capacitor 為

$$\underline{ C = \frac{ I_L T }{ 2V_r } }_{ \# }$$

- $T$: 週期

# Reverse Breakdown

在負方向的電壓高過一定程度時，diode 無法阻止電流，就會 breakdown

![[reverse breakdown region.png|450]]

包含兩種

1. Zenner Breakdown
2. Avalanche Breakdown (irrecoverable)

## Zenner Breakdown

這類的 breakdown 會拿來當作一種應用，並且 diode 會加上類似閃電的符號（注意方向）

![[zener-diode symbol.png|250]]

# Wave-Shaping Circuits

## Clipper Circuits

a portion of an input signal waveform is "clipped" off

如下圖大於 $6\text V$ 和小於 $-9\text V$ 的會被切掉

![[clipper circuit.png]]

並且也可以用 Zenner Diode 做到一樣的效果，這樣就不需要使用會沒電的電池

![[clipper circuit with zenner diode.png]]

上面圖中的電阻必須要足夠大才可以避免太大的電流流入 diode，通常會設計只讓幾毫安培的電流通過

---

也有調整斜率的 clipper circuit，這種 circuit 會在 diode 旁邊串連一個電阻

![[clipper circuit with different slope.png|350]]

如果缺少那個電阻，他就是個普通的 clipper circuit ，但是因為加上了電阻，因此 $v_{in}$ 的一部分會反應在 $v_o$

$$
\begin{array}{lcl}
	\text{ when } & v_{ in } > 5\text V & v_o & = & 4.4 + 0.6 + \frac{ 1k\Omega }{ 1k \Omega + 1k\Omega } \times v_{ in } \\
	\text{ when } & -5\text V < v_{ in } < 5 \text V & v_o  & = & v_{ in } \\
	\text{ when } & v_{ in } < -5 \text V & v_o & = & -4.4-0.6+\frac{ 1k\Omega }{ 1k\Omega + 1k\Omega } \times v_{ in }
\end{array}
$$

他的波形圖如下

![[curve of clipper circuit with modified slope.png]]

## Clamp Circuit

可以把電壓抬高或降低

### Positive Clamp Circuit

![[Positive Clamp Circuit.png|350]]

$$v_{ out } = v_{ in } + v_{ m }$$

### Negative Clamp Circuit

![[Negative Clamp Circuit.png|350]]

$$v_{ out } = v_{ in } - v_{ m }$$

### Biased Clamp Circuit

為上面的 [[#Positive Clamp Circuit]] 與 [[#Negative Clamp Circuit]] 加上一個 offset 得到的 circuit

那個 offset 可以是電池，也可以是 zener diode

如下是一個 [[#Positive Clamp Circuit]] 加上一個正的 offset

![[biased clamp circuit.png|350]]

要注意只有當 $v_m > v_B$ 時才有機會導通，因此若是 $v_m < v_B$ ， $v_{ out } = v_{ in }$ 

$$
\begin{array}{l}
	\text{ when } v_{ in } < v_B & v_{ out } = v_{ in } \\
	\text{ when } v_{ in } > v_B & v_{ out } = v_{ in } - v_m + v_B
\end{array}
$$

---

當然我們並不會使用電池，因此以下是改良版

![[zener diode clamper.png|350]]

---

參考資料:

電工學上課

---

link:

