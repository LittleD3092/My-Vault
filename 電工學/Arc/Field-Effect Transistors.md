標籤: #電工學 

---

FET 可以分成兩類

- JFET
- MOSFET

# MOSFET

MOSFET 依照 channel 的極性不同，可以分成 [[#NMOS and PMOS Transistors]]

並且也可以分成 Depletion Type 和 Enhancement Type

## NMOS and PMOS Transistors

### NMOS Transistors

![[n channel mosfet.png]]

$D$: drain
$G$: gate
$S$: source
$B$: body (substrate)

When a sufficiently large (positive) voltage is applied to the gate relative to the source, electrons are attracted to the region under the gate, and a channel of *n*-type material is induced between the drain and the source.

Drain current is controlled by the voltage applied to the gate.

#### Circuit Symbol

![[circuit symbol of nmos transistor.png|250]]

#### Operation

根據給 gate 與 drain 的電壓不同，通過 nmos 的電流可以分成以下三種情況

- cutoff region
- triode region
- saturation region

##### Cutoff Region

當給 gate 的電壓 $v_{ GS }$ 不夠大的時候會發生，這時 drain 和 source 會是斷路狀態

$$\text{ when } v_{ GS } \leq V_{ to } \qquad i_D = 0$$

我們稱 $V_{ to }$ 為 threshold voltage

![[mosfet operation in cutoff region.png]]

##### Triode Region

當給 gate 的電壓 $v_{ GS }$ 足夠大時 drain 和 source 就會導通，此時如果在 drain 和 source 之間給一個小的電壓 $v_{ DS }$ (必須足夠小)，會開始產生電流通過。

$$
\begin{array}{}
	\text{ when } & v_{ DS } < v_{ GS } - V_{ to }\\
	& v_{ GS } \geq V_{ to }
\end{array}
$$

$$i_D = K[\ 2(V_{ GS } - V_{ to })v_{ DS } - v^2_{ DS } \ ]$$

$$K = \left( \frac W L \right) \frac{ KP }{ 2 }$$

- $W$: width of channel
- $L$: length of channel
- $KP$: device parameter, depends on the thickness of the oxide layer and certain properties of the channel material. a typical value is $50\mu\text A / \text V^2$

![[mosfet operation in the triode region.png]]

##### Saturation Region

當進入了 triode region 並且逐漸加大 drain 與 source 間的電壓 $v_{ DS }$ 大過一定程度就會進入 saturaion region，此時的電流 $i_D$ 不論 $v_{ DS }$ 如何改變都是固定的

$$i_D = K(v_{ GS } - V_{ to })^2$$

![[mosfet operation in saturation region.png]]

![[characteristic curves of nmos.png]]

##### Boundary Between Triode and Saturation Regions

At this boundary, the channel thickness at the drain is zero, which occurs when $v_{ GD } = V_{ to }$

$$v_{ GD } = V_{ to }$$

$$\implies v_{ GS } - v_{ DS } = V_{ to }$$

$$\implies v_{ GS } - V_{ to } = v_{ DS }$$

substitude into equation of saturation region

> equation of saturation region
> $$i_D = K(v_{ GS } - V_{ to })^2$$

$$\implies \underline{ 
	i_D = Kv^2_{ DS }
}_\#$$

Notice that the boundary between the triode region and the saturation region is a parabola

##### Equivalent Resistance

$$R_D = 
\left.
	\frac{ \partial v_{ DS } }{ \partial i_D }
\right\vert_{ v_{ GS } \text{ const } }$$

$R_D$ is preferred to be very small ($100 \text m \Omega \sim 10\text m \Omega$)

我們會取 $v_{DS} = 0$ 附近的等效電阻

$$ = \left.
	\frac{ 1 }{ \frac{ \partial i_D }{ \partial v_{ DS } } }
\right\vert_{ v_{ DS } = 0 }$$

$$ = \underline{\frac{ 1 }{ 2K(v_{ GS } - v_{ to }) }}_\#$$

### PMOS Transistors

MOSFETs can also be constructed by interchanging the $n$ and $p$ regions of $n$-channel devices, resulting in $p$-channel devices.

![[circuit symbol for pmos transistor.png|300]]

As indicated in the figure, we usually orient the $p$-channel FETs with the source at the top and reference the current out of the drain.

### Summary

|                            | NMOS                                                                                                                                      | PMOS                                                                                                                                      |
| -------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------- |
| Circuit Symbol             | ![[circuit symbol of nmos transistor.png]]                                                                                                | ![[circuit symbol for pmos transistor.png]]                                                                                               |
| $KP$ (typical value)       | $$50 \mu \text A / \text V^2$$                                                                                                            | $$25 \mu \text A / \text V^2$$                                                                                                            |
| $K$                        | $$\left( \frac 1 2 \right)KP \left(\frac W L\right)$$                                                                                     | $$\left( \frac 1 2 \right)KP \left(\frac W L\right)$$                                                                                     |
| $V_{ to }$ (typical value) | $$+1 \text V$$                                                                                                                            | $$-1 \text V$$                                                                                                                            |
| Cutoff region              | $$v_{ GS } \leq V_{ to }$$ $$i_D = 0$$                                                                                                    | $$v_{ GS } \geq V_{ to }$$ $$i_D = 0$$                                                                                                    |
| Triode region              | $$v_{ GS } \geq V_{ to } \text{ and } 0 \leq v_{ DS } \leq v_{ GS } - V_{ to }$$ $$i_D = K[2(v_{ GS } - V_{ to })v_{ DS } - v_{ DS }^2]$$ | $$v_{ GS } \leq V_{ to } \text{ and } 0 \geq v_{ DS } \geq v_{ GS } - V_{ to }$$ $$i_D = K[2(v_{ GS } - V_{ to })v_{ DS } - v_{ DS }^2]$$ |
| Saturation region          | $$v_{ GS } \geq V_{ to } \text{ and } v_{ DS } \geq v_{ GS } - V_{ to }$$ $$i_D = K(v_{ GS } - V_{ to })^2$$                              | $$v_{ GS } \leq V_{ to } \text{ and } v_{ DS } \leq v_{ GS } - V_{ to }$$ $$i_D = K(v_{ GS } - V_{ to })^2$$                              |
| $v_{ DS }$ and $v_{ GS }$  | Normally assume positive values                                                                                                           | Normally assume negative values                                                                                                           | 

## Depletion Type and Enhancement Type

| Depletion Type                                                                                                                                                                                         | Enhancement Type                                                                                                                                                                                  |
| ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| equivalent to "normal close" switch <br> require gate source voltage $v_{gs}$ to switch OFF device                                                                                                     | <ul><li>equivalent to "normal open" switch <li> require gete source voltage $v_{gs}$ to switch ON device </ul>                                                                                    |
| ![[depletion mode MOSFET.png]]                                                                                                                                                                         | ![[enhance mode MOSFET.png]]                                                                                                                                                                      |
| <ul><li>base is connected to source terminal <li>continuous thick line between drain and source indicates that it is "depletion type" mosfet <li>the arrow indicates it is p-channel or n-channel</ul> | <ul> <li> base is connected to source terminal <li> break line berween drain and source indicates that it is "enhancement type" mosfet <li>the arrow indicates it is p-channel or n-channel </ul> |
| ![[voltage and current of depletion mode mosfet.png]]                                                                                                                                                  | ![[voltage and current of enhancement mode mosfet.png]]                                                                                                                                           |
| ![[depletion structure of n-channel mosfet.png]]                                                                                                                                                       | ![[structure of enhancement mode mosfet.png]]                                                                                                                                                     |

## Load-Line Analysis

![[load-line analysis.png]]

對於上圖的兩個 loop 分別列出 KVL

$$
\left\{
	\begin{array}{}
		v_{ GS }(t) = v_{ in }(t) + V_{ GG } \\
		\underline{V_{ DD } = R_D i_D(t) + v_{ DS }(t)}_\#
	\end{array}
\right.$$

我們將第二條式子畫出的線稱為 load-line ，並且我們會把他畫在圖上。

譬如上圖的情況，我們會將 $R_D = 1\text k\Omega, V_{DD} = 20 \text V$ 代入

$$\implies 20 = i_D(t) + v_{ DS }$$

注意 $i_D$ 的單位是 $\text{mA}$ ，並且我們可以根據這個方程式在圖表上畫出 load line

> ## Quiescent Operating Point
> 
> 我們把 $v_{ in } = 0$ 的點稱為 quiescent operating point ，或者 Q point
> 
> 譬如上圖中，如果 $v_{in}(t) = 0$ ，$v_{GS} = v_{DD} = 4\text V$ 。我們可以在圖表上看到 $v_{ GS } = 4 \text V$ 的線與 load line 就是 Q point

接著我們把 $v_{ in }(t) = \sin(2000\pi t)$ 加入，並且看看 $v_{ GS }$ 與 $v_{ DS }$ 的關係。我們可以使用 load line 來幫助我們看出來。結果如下：

![[inverting amplifier using mos.png]]

我們發現這是一個 inverting amplifier ，但是注意結果其實並不是 $\sin$ 波。從 field line 可以發現，高點、低點與中間點的電壓如下

| 點              | $$v_{ GS }$$  | $$v_{ DS }$$   |
| --------------- | ------------- | -------------- |
| $v_{ DS }$ 高點 | $$3 \text V$$ | $16 \text V$   |
| 中間點          | $$4 \text V$$ | $$11 \text V$$ |
| $v_{ DS }$ 低點 | $$5 \text V$$ | $$4 \text V$$  | 

對於 $v_{DS}$ ，高點與中間點相差 $5 \text V$ ，中間點與低點相差 $7 \text V$ ，因此這個 amplifier 做的是非線性的放大。

## Bias Circuits

上面提到的 Amplifier Circuit 有許多缺點，譬如需要兩個電池、 Q point 不會在中間等問題，並且選擇的元件（如電阻）必須要非常精準，因此有了改良的版本。 bias circuit 容許不是很精準的零件。

### The Fixed- plus Self-Bias Circuit

The fixed- plus self-bias circuit shown in Figure(a) is a good circuit for establishing Q points that are relatively independent of device parameters

![[fixed- plus self-bias circuit.png|400]]

為了分析，我們把 (a) 做 Thevenin Equivalent Circuit 變成 (b) ，其中

$$V_G = V_{ DD } \frac{ R_2 }{ R_1 + R_2 }$$

$$R_G = R_1 \vert \vert R_2$$

對於 (b) 的 loop 寫出 KVL (we assume that voltage drop across $R_G$ is zero since the gate current is extremely small)

$$V_G = v_{ GS } + R_Si_D$$

並且使用 transistor 的 saturation region （我們通常會希望使用 saturation region）

$$i_D = K(v_{ GS } - V_{ to })^2$$

根據上面兩條式子，畫出 $i_D$ 對 $v_{GS}$ 的圖，可以得出 Q point

![[graphical solution of fixed plus self bias circuit.png|450]]

最後，還有 drain loop 的 equation 來求出 $v_{DS}$

$$v_{DS} = V_{DD} - (R_D + R_S) i_D$$

## Small-Signal Equivalent Circuits

我們常常會需要計算 Q Point 附近的電壓與電流關係，而在一些特殊情況（訊號很小），電壓與電流距離 Q Point 不遠，而我們可以在這個情況下將 FET 等價於 voltage-controlled current source

因為訊號很小，我們將 $i_D(t)$ 與 $v_{GS}(t)$ 這樣表示

$$i_D(t) = I_{DQ} + i_d(t)$$
$$v_{GS}(t) = V_{GSQ} + v_{gs}(t)$$

> $i_D(t)$ 、 $I_{DQ}$ 與 $i_d(t)$ 關係如下
> ![[Illustration of small-signal.png]]

我們使用 saturation region 的公式

> $$i_D = K(v_{ GS } - V_{to})^2$$

$$\implies I_{DQ} + i_d(t) = K[ V_{GSQ} + v_{gs}(t) - V_{to} ]^2$$

平方炸開

$$\implies I_{DQ} + i_d(t) = K(V_{GSQ} - V_{to})^2 + 2K(V_{GSQ} - V_{to})v_{gs}(t) + K v_{gs}^2$$

我們利用 Q point 的 $I_{DQ}$ 代入，並且因為訊號很小，因此省略 $v_{gs}^2$

> Q point 的 $I_{DQ}$ ：
> $$I_{DQ} = K(V_{GSQ} - V_{to})^2$$

$$\implies i_d(t) = 2K(V_{GSQ} - V_{to})v_{gs}(t)$$

我們定義 transconductance of FET:

$$\underline{g_m = 2K(V_{GSQ} - V_{to})}_\#$$

$$\underline{i_d(t) = g_m v_{gs}(t)}_\#$$

$$\underline{i_g(t) = 0}_\#$$

上面的結果可以得出 Small-signal equivalent circuit 是 voltage controlled current source

![[FET small-signal equivalent circuit.png|400]]

### Transconductance

$$\underline{g_m = 2K(V_{GSQ} - V_{to})}_\#$$

$g_m$ 除了上面的表示方式，還有以下的表示方式：

> 利用 Q point 的特性
> $$I_{DQ} = K(V_{GSQ} - V_{to})^2$$
> $$\implies V_{GSQ} - V_{to} = \sqrt{\frac{I_{DQ}}{K}}$$

$$\implies\underline{g_m = 2\sqrt{ KI_{DQ} }}_\#$$

> 利用 $K$ 與 device parameter $KP$ 的關係
> $$K = \left( \frac W L \right) \frac{ KP }{ 2 }$$

$$\implies g_m = \sqrt{\frac{W}{L} \cdot 2 KP \cdot I_{DQ}}$$

### More Accurate Circuits

The first-order equations we have used to obtain the equivalent circuit for the FET did not account for the effect of $v_{DS}$ on the drain current

If we wish to account for the effect of $v_{DS}$ in the small-signal equivalent circuit, we must add a resistance $r_d$ called the **drain resistance** between drain and source

$$i_d = g_mv_{gs} + \frac{ v_{ds} }{ r_d }$$

![[FET small-signal equivalent circuit that accounts for the dependence of iD on vDS.png|400]]

### Transconductance and Drain Resistance as Partial Derivatives

> from $$i_d = g_mv_{gs} + \frac{v_{ds}}{ r_d }$$
> 我們得到 $g_m$ 與 $r_d$ 用 partial derivatives 的表示方法

$$\implies
\left\{
	\begin{array}{}
		\underline{g_m = \left.\frac{ \partial i_D }{ \partial v_{GS} }\right\vert_{\text{Q point}}}_\# \\
		\underline{\left.\frac{1}{r_d} \cong \frac{\partial i_D}{\partial v_{DS}}\right\vert_{\text{Q point}}}_\#
	\end{array}
\right.	
$$

## Common-Source Amplifier

下面的 circuit 稱為 common-source amplifier

![[common-source amplifier.png]]

中間的部份（$R_1, R_2, R_D, R_S$）形成 bias circuit ，左邊為輸入端，右邊為輸出端。

裡面的 capacitor 的 impedance 相對於交流輸入 $v(t)$ 會非常小，可以當作 short circuit

### Small-Signal Equivalent Circuit of Common-Source Amplifier

我們將 FET 視為 small-signal equivalent circuit ，並且將 capacitor short ，得出以下 circuit

![[small-signal equivalent circuit of common-source amplifier.png]]

輸出的電阻 $R_L'$ ：

$$\underline{R_L' = \frac{ 1 }{ \frac{ 1 }{ r_d } + \frac 1 {R_D} + \frac 1 {R_L} }}_\#$$

$v_o$ 與 $v_{gs}$ 的關係：

$$v_o = -(g_mv_{gs})R_L'$$

$v_{in}$ 與 $v_{gs}$ 的關係：

$$v_{in} = v_{gs}$$

由以上兩個式子可以得出 amplitude ：

$$\underline{A_v = \frac{v_o}{v_{in}} = -g_mR_L'}_\#$$

### Input Resistance

$$\underline{R_{in} = \frac{v_{in}}{ i_{in} } = R_G = R_1 \vert\vert R_2}_\#$$

### Output Resistance

我們將 $R_L$ 拔掉，求出 output terminals 的 equivalent resistance

$$\underline{
	R_o = \frac 1 {\frac{ 1 }{ R_D } + \frac{ 1 }{ r_d }}
}_\#$$

## Source Follower

![[source follower using fet.png]]

### Small-Signal Equivalent Circuit of Source Follower

我們將 FET 視為 small-signal equivalent circuit ，並且將 capacitor short ，得出以下 circuit

![[small-signal ac equivalent circuit for the source follower.png]]

### Voltage Gain

by parallel combination of $r_d, R_s, R_L$

$$\underline{
	R_L' = \frac{ 1 }{ \frac{ 1 }{ r_d } + \frac{ 1 }{ R_s } + \frac{ 1 }{ R_L } }
}_\#$$

the output voltage is given by

$$v_o = g_mv_{gs}R_L'$$

furthermore, we can write the following voltage equation:

$$v_{in} = v_{gs} + v_o$$

將 $v_o$ 代入

$$\implies v_{in} = v_{gs} + g_mv_{gs}R_L'$$

用 $v_o$ 與 $v_in$ 得出 $A_v$

$$\underline{
	A_v = \frac{ v_o }{ v_{in} } = \frac{ g_mR_L' }{ 1 + g_mR_L' }
}_\#
$$

### Input Resistance

$$
\underline{
R_{in} = \frac{ v_{in} }{ i_{in} } = 
R_G = R_1 \vert\vert R_2
}_\#
$$

### Output Resistance

$$\underline{R_o = \frac{ v_x }{ i_x } = \frac{ 1 }{ g_m + \frac{ 1 }{ R_S } + \frac{ 1 }{ r_d } }}_\#$$

## CMOS Logic Gates

In **complementary metal-oxide-semiconductor** technology, both NMOS and PMOS transistors are fabricated on the same chip. Using CMOS technology, we may construct the basic building blocks of digital systems, such as NAND gates and NOR gates.

### CMOS Inverter

![[cmos inverter.png]]

| $$V_{in}$$                           | PMOS                                 | NMOS                                 | $$V_{out}$$                |
| ------------------------------------ | ------------------------------------ | ------------------------------------ | -------------------------- |
| <font color = "fuchsia">HIGH </font> | <font color = "#E76F51">open</font>  | <font color = "#2A9D8F">short</font> | $$0\text{ (LOW) }$$        | 
| <font color = "fuchsia">LOW </font>  | <font color = "#2A9D8F">short</font> | <font color = "#E76F51">open</font>  | $$V_{DD} \text{ (HIGH) }$$ |

### CMOS NAND Gate

![[two-input cmos nand gate.png]]

| $A$                                 | $B$                                 | $M_1$                                | $M_2$                                | $M_3$                                | $M_4$                                | $V_{out}$                           |
| ----------------------------------- | ----------------------------------- | ------------------------------------ | ------------------------------------ | ------------------------------------ | ------------------------------------ | ----------------------------------- |
| <font color = "fuchsia">HIGH</font> | <font color = "fuchsia">HIGH</font> | <font color = "#E76F51">open</font>  | <font color = "#E76F51">open</font>  | <font color = "#2A9D8F">close</font> | <font color = "#2A9D8F">close</font> | <font color = "fuchsia">LOW</font>  |
| <font color = "fuchsia">HIGH</font> | <font color = "fuchsia">LOW</font>  | <font color = "#E76F51">open</font>  | <font color = "#2A9D8F">close</font> | <font color = "#2A9D8F">close</font> | <font color = "#E76F51">open</font>  | <font color = "fuchsia">HIGH</font> |
| <font color = "fuchsia">LOW</font>  | <font color = "fuchsia">HIGH</font> | <font color = "#2A9D8F">close</font> | <font color = "#E76F51">open</font>  | <font color = "#E76F51">open</font>  | <font color = "#2A9D8F">close</font> | <font color = "fuchsia">HIGH</font> |
| <font color = "fuchsia">LOW</font>  | <font color = "fuchsia">LOW</font>  | <font color = "#2A9D8F">close</font> | <font color = "#2A9D8F">close</font> | <font color = "#E76F51">open</font>  | <font color = "#E76F51">open</font>  | <font color = "fuchsia">LOW</font>  |


### CMOS NOR Gate

![[cmos nor gate.png|400]]

| $A$                                 | $B$                                 | $M_1$                                | $M_2$                                | $M_3$                                | $M_4$                                | $V_{out}$                           |
| ----------------------------------- | ----------------------------------- | ------------------------------------ | ------------------------------------ | ------------------------------------ | ------------------------------------ | ----------------------------------- |
| <font color = "fuchsia">HIGH</font> | <font color = "fuchsia">HIGH</font> | <font color = "#E76F51">open</font>  | <font color = "#E76F51">open</font>  | <font color = "#2A9D8F">close</font> | <font color = "#2A9D8F">close</font> | <font color = "fuchsia">LOW</font>  |
| <font color = "fuchsia">HIGH</font> | <font color = "fuchsia">LOW</font>  | <font color = "#E76F51">open</font>  | <font color = "#2A9D8F">close</font> | <font color = "#2A9D8F">close</font> | <font color = "#E76F51">open</font>  | <font color = "fuchsia">LOW</font>  |
| <font color = "fuchsia">LOW</font>  | <font color = "fuchsia">HIGH</font> | <font color = "#2A9D8F">close</font> | <font color = "#E76F51">open</font>  | <font color = "#E76F51">open</font>  | <font color = "#2A9D8F">close</font> | <font color = "fuchsia">LOW</font>  |
| <font color = "fuchsia">LOW</font>  | <font color = "fuchsia">LOW</font>  | <font color = "#2A9D8F">close</font> | <font color = "#2A9D8F">close</font> | <font color = "#E76F51">open</font>  | <font color = "#E76F51">open</font>  | <font color = "fuchsia">HIGH</font> | 

---

參考資料:

課本
[Introduction to MOSFET - blog](https://www.electronicshub.org/mosfet/)

---

link:

