標籤: #電工學 

---

[TOC]

---

# Basic Logic Circuits Concepts

## Advantage of the Digital Approach

Analog signals are usually impossible to determine the precise amplitude of the original signal. On the other hand, after noise is added to a digital signal, we can still determine the logic values.

![[digital signal vs analog signal when noice is added.png]]

## Positive vs Negative Logic

- Positive Logic: 高電壓當 1 ，低電壓當 0
- Negative Logic: 低電壓當 1 ，高電壓當 0

通常訊號的變數（logic variables）用大寫字母表示 ($A, B, C$)

## Logic Ranges and Noise Margins

![[logic ranges.png]]

No meaning is assigned to voltages between $V_{IL}$ and $V_{IH}$, which normally occur only during transitions.

The circuits are designed so that the output voltages fall into narrower ranges than the inputs. Because noise can be added to a logic signal in the interconnections between outputs and inputs, it is important that the outputs have narrower ranges than the acceptable inputs.

noice margins:

$$NM_L = V_{IL} - V_{OL}$$

$$NM_H = V_{OH} - V_{IH}$$

Ideally, noise margins are as large as possible.

## Digital Words

- bit: single binary digit
- byte: a word consist of 8 bits
- nibble: 4-bit word

## Transmission of Digital Information

- parallel transmission: an $n$-bit word is transferred on $n + 1$ wires
- serial transmission: the successive bits of the word are transferred one after the other with a single pair of wires

# Representation of Numerical Data in Binary Form

## Binary Numbers

二進位

### Example

#### Converting a Decimal Integer to Binary

> Convert the decimal integer $343_{10}$ to binary

$$
\begin{array}{}
	        &   & \text{Quotient} & \text{Remainder} \\
	343 / 2 & = & 171 & 1 \\
	171 / 2 & = & 85 & 1 \\
	85 / 2 & = & 42 & 1 \\
	42 / 2 & = & 21 & 0 \\
	21 / 2 & = & 10 & 1 \\
	10 / 2 & = & 5 & 0 \\
	5 / 2 & = & 2 & 1 \\
	2 / 2 & = & 1 & 0 \\
	1 / 2 & = & 0 & 1
\end{array}
$$

with the remainder, we find the binary form of $343_{10}$

$$343_{10} = 101010111_2$$

#### Converting a Decimal Fraction to Binary

> Convert $0.392_{10}$ to its closest six-bit binary equivalent

$$
\begin{array}{}
	2 \times 0.392 & = & 0 & + & 0.784 \\
	2 \times 0.784 & = & 1 & + & 0.568 \\
	2 \times 0.568 & = & 1 & + & 0.136 \\
	2 \times 0.136 & = & 0 & + & 0.272 \\
	2 \times 0.272 & = & 0 & + & 0.544 \\
	2 \times 0.544 & = & 1 & + & 0.088 
\end{array}
$$

$$\therefore 0.392_{10} \cong 0.011001_2$$

#### Converting Decimal Values to Binary

> Convert $343.392_{10}$ to binary

from above examples, 

$$343_{10} = 101010111_2$$

$$0.392_{10} \cong 0.011001_2$$

$$\therefore 343.392_{10} = 101010111.011001_2$$

## Hexadecimal and Octal Numbers

- Hexadecimal: 十六進位
- Octal: 八進位

### Example

#### Converting Octal and Hexadecimal Numbers to Binary

> Convert the numbers $317.2_8$ and $\rm F3A.2_{16}$ to binary

一個八進位可以變成三位二進位，

$$317.2_8 = 011\; 001\; 111.010_2$$

一個十六進位可以變成四位二進位，

$$\rm F3A.2_{16} = 1111 \; 0011 \; 1010.0010_2$$

#### Converting Binary Numbers to Octal or Hexadecimal

> Convert $11110110.1_2$ to octal and to hexadecimal

把三個二進位湊在一起變成八進位，

$$11110110.1_2 = 011 \; 110 \; 110.100 = 366.4_8$$

把四個二進位湊在一起變成十六進位，

$$11110110.1_2 = 1111\;0110.1000 = \rm F6.8_{16}$$

## Binary-Coded Decimal Format

有的時候，二進位的表示方法是用 binary-coded decimal (簡稱BCD) ，就只是把十進位的每一個位數用四位的二進位表示，例如：

$$93.2 = 1001\;0011.0010_{BCD}$$

可以看出每四個二進位表示了一個十進位的位數

## Gray Code

![[binary code and gray code.png|400]]

在某些用途，譬如給馬達訊號時，用 binary code 來給訊號不太適合。

假設我們希望馬達從位置 $0011$ 移動到 $0100$ ，理想情況是馬達只移動一格，但是負責給訊號的那一端沒辦法一次改變三個 bit ，因此 $0011$ 會先變成 $0010$ ，再到 $0000$ ，再到 $0100$ 。這個過程中的數字都距離我們的目標 $0100$ 很遠，因此馬達收到的訊號會很雜亂。

這時我們就會需要 gray code ，他的編碼方式如上圖，每一個數字之間都只差一個 bit 的變化，比較方便。

---

他的編碼方式是疊加上去的，如下

$$
\begin{array}{}
	\text{One-bit code} & \text{Two-bit code} & \text{Three-bit code} \\
	0 & 00 & 000 \\
	1 & 01 & 001 \\
	& 11 & 011 \\
	& 10 & 010 \\
	& & 110 \\
	& & 111 \\
	& & 101 \\
	& & 100
\end{array}
$$

Two-bit code 首先將 One-bit code 寫兩次，第一次順著寫，第二次倒著寫

$$
\begin{array}{}
	\text{One-bit code} & \text{Two-bit code} \\
	0 & 0\\
	1 & 1\\
	& 1\\
	& 0
\end{array}
$$

接著將前面一半加上 $0$ ，後面一半加上 $1$

$$
\begin{array}{}
	\text{One-bit code} & \text{Two-bit code} \\
	0 & 00\\
	1 & 01\\
	& 11\\
	& 10
\end{array}
$$

Three-bit code 也是一樣，先將 Two-bit code 寫兩次，一次順著寫，一次倒著寫

$$
\begin{array}{}
	\text{One-bit code} & \text{Two-bit code} & \text{Three-bit code} \\
	0 & 00 & 00 \\
	1 & 01 & 01 \\
	& 11 & 11 \\
	& 10 & 10 \\
	& & 10 \\
	& & 11 \\
	& & 01 \\
	& & 00
\end{array}
$$

接著在前面一半加上 $0$ ，後面一半加上 $1$

$$
\begin{array}{}
	\text{One-bit code} & \text{Two-bit code} & \text{Three-bit code} \\
	0 & 00 & 000 \\
	1 & 01 & 001 \\
	& 11 & 011 \\
	& 10 & 010 \\
	& & 110 \\
	& & 111 \\
	& & 101 \\
	& & 100
\end{array}
$$

以此類推，就可以得到更多位數的編碼方式

## Complement Arithmetic

one's complement: 一補數
two's complement: 二補數，一補數 $+1$

$$
\begin{array}{}
	01001101 \\
	10110010 & \text{(one's complement)} \\
	10110011 & \text{(two's complement)}
\end{array}
$$

求一補數只需要將每個 bit flip 就可以了

求二補數有兩種求法，以 $10110011$ 為例

| Way 1                                                                                                                                              | Way 2                                                                                                                                                                                |
| -------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| $$\begin{array}{r} 10110011 & \text{ One's complement } \\ \underline{ \ \ \ \ \ \ \ \ \ +1 } \\ 10110100 & \text{ Two's complement }\end{array}$$ | $$\begin{array}{} \underbrace{01001}_{\text{ Invert }}\underbrace{100}_{\text{ Copy }} & \text{Number} \\ \overbrace{10110}\overbrace{100} & \text{ Two's complement } \end{array}$$ |
| First find the one's complement, then add $1$ <br> Neglect the carry (if it occurs) out ot the most significant bit                                | Working from right to left, copy bits until after the first $1$ is copied <br> Then invert the remaining bits                                                                        | 

---

- overflow: 加太多加到上限以上
- underflow: 減太多減到下限以下

# Logic Gates

[[Logic Gates]]

# Canonical Forms and Standard Forms

- [[Canonical Forms]]
- [[Standard Forms]]

# Minimization of Logic Circuits

## Karnaugh Maps

我們可以利用 Karnaugh maps 來化簡運算式

1. 根據輸入端的個數畫一個正方形或長方形
2. 在旁邊標上輸入端的字母與輸入訊號，輸入訊號使用 gray signal
3. 將輸出訊號填到格子裡
4. 用大括號將 $A, B, C, D$ 為 1 的地方括起來
5. 嘗試用 $A, B, C, D$ 表示運算式

![[karnaugh maps.png]]

### SOP Example

> A logic circuit has inputs $A, B, C, D$. The output of the circuit is given by
> $$E = \sum m(1, 3, 4, 5, 7, 10, 12, 13)$$
> Find the minimum SOP form for $E$

convert the numbers of the minterms to binary numbers

$$
\begin{array}{}
	\text{ number } & \text{ binary } \\
	1 & 0001 \\
	3 & 0011 \\
	4 & 0100 \\
	5 & 0101 \\
	7 & 0111 \\
	10 & 1010 \\
	12 & 1100 \\
	13 & 1101
\end{array}
$$

Construct Karnaugh maps

![[Karnaugh maps SOP example.png|300]]

draw squares on the map and get SOP expression

$$E = \overline A D + B \overline C + A \overline B C \overline D$$

### POS Example

> Find the minimum POS for the logic variable $E$ of last example

draw Karnaugh maps

![[Karnaugh maps for POS example.png|300]]

obtain expression

$$\overline E = ABC + A \overline B D + \overline A C \overline D + \overline B\, \overline C\, \overline D$$

apply De Morgan's laws

$$E = (\overline A + \overline B + \overline C)(\overline A + B + \overline D)(A + \overline C + D)(B + C + D)$$

# Sequential Logic Circuits

Sequencial logic circuits mean that the outputs depend on past as well as present inputs.

We say that such circuits have memory because they "remember" past input values.

Often, the operation of a sequential circuit is synchronized by a clock signal that consists of periodic logic-1 pulses.

## Flip-Flops

### Simple Flip-Flop

可以用兩個 inverter 達成

![[simple flip-flop.png|250]]

$Q$ 與 $\overline Q$ 的關係如下

| $Q$ | $\overline Q$ |
| --- | ------------- |
| 1   | 0             |
| 0   | 1             | 

### SR Flip-Flop

Simple two-inverter circuit is not very useful because no provision exists for controlling its state.

A more useful circuit is the set-reset(SR) flip-flop, consisting of two NOR gates.

![[SR flip-flop.png|300]]

In normal operation, $R$ and $S$ are not allowed to be high at the same time. 

> 如果 $R$ 跟 $S$ 都是 high ， $Q$ 與 $\overline Q$ 會是 low 。但是如果下一瞬間， $R$ 與 $S$ 變成 low ， $Q$ 與 $\overline Q$ 會在 high 與 low 之間一直跳動，因此我們不允許 $R$ 和 $S$ 同時為 high
> $$\begin{array}{} & R & S & Q & \overline Q \\ & 1 & 1 & 0 & 0 \\ \overset{\text{ change to reset state }}{\implies} & 0 & 0 & 1 & 1 \\ \implies & 0 & 0 & 0 & 0 \\ & & \vdots \end{array}$$

With $R$ and $S$ are both low (reset state) , the SR flip-flop remembers which input ($R$ or $S$) was high most recently.

#### Using an SR Flip-Flop to Debounce a Switch

![[using an sr flip-flop to debounce a switch.png]]

在撥開關時（例如鍵盤），開關會跳動，導致只按一下卻有很多個方波形成。這時如果使用 SR flip-flop ，就可以抵銷這個效果。

### Clocked SR Flip-Flop

Often, it is advantageous to control the point in time that a flip-flop responds to its inputs.

We say that a high clock level enables the inputs to the flip-flop. On the other hand, the low clock level disables the inputs.

![[clocked SR flip-flop.png]]

Sometimes, a clocked SR fip-flop is needed, but it is also necessary to be able to set or clear the flip-flop state independent of the clock.

![[clocked SR flip-flop with asynchronous preset and clear inputs.png]]

### Edge-Triggered D Flip-Flop

We have considered circuits for which the level of the clock signal enables or disables other input signals. On the other hand, edge-triggered circuits respond to their inputs only at a transition in the clock signal.

Positive-edge-triggered circuits respond when the clock signal switches from low to high.

Negative-edge-triggered circuits respond on the transition from high to low.

![[positive-edge-triggered D flip-flop.png]]

### JK Flip-Flop

JK flip-flop has very similar operation to that of an SR fip-flop except that when both $J$ and $K$ are high, the output of the flip-flop toggles on each cycle of the clock. 

> <font face = "roman">switching from high to low on one negative-going clock transition, back to high on the next negative transition, and so on</font>

![[JK flip-flop.png]]

## Register

A register is an array of flip-flops that is used to store or manipulate the bits of a digital word.

### Serial-In Parallel-Out Shift Register

![[serial-in parallel-out shift register.png|400]]

> <font face = "roman">The input data are applied to the input of the first state serially (one bit after another).
> 
On the leading edge of the first clock pulse, the first data bit is transferred into the first stage. 
> 
On the second clock pulse, the first bit is transferred to the second stage, and the second bit is transferred into the first stage.
> 
After four clock pulses, four bits of input data have been transferred into the shift register.
> 
Thus, serial data applied to the input are converted to parallel form available at the outputs of the stages of the shift register.</font>

### Parallel-In Serial-Out Shift Register

![[parallel-in serial-out shift register.png]]

> <font face = "roman">First, the register is cleared by applying a high pulse to the clear input.
> 
> Parallel data are applied to the $A, B, C, D$ inputs.
> 
> Then, a high pulse is applied to the parallel enable (PE) input.
> 
> The result is to set each flip-flop for which the corresponding data line is high.
> 
> Thus, four parallel bits are loaded into the stages of the register.
> 
> Then, application of clock pulses produces the data inserial form at the output of the last stage.</font>

### Counters

Counters are used to count the pulses of an input signal.

![[ripple counter.png]]

> <font face = "roman">With the $J$ and $K$ inputs high, the $Q$-output of the flip-flop toggles on each falling edge of the clock input.
> 
> The input pulses to be counted are connected to the clock input of the second stage.
> 
> ---
> 
> Assume that the flip-flops are initially all in the reset state $Q = 0$.
> 
> When the falling edge of the first input pulse occurs, $Q_0$ changes to logic 1.
> 
> On the falling edge of the second pulse, $Q_0$ toggles back to logic 0, and the resulting falling input to the second stage causes $Q_1$ to become high.</font>

---

參考資料:

電工學課本

---

link:

