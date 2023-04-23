Tag: #digital-design #電工學 
Previous: 
Link: 

[TOC]

---

There are several kinds of flip-flops:

- [[#Simple Flip-Flop]]
- [[#SR Flip-Flop]]
- [[#Clocked SR Flip-Flop]]
- [[#Edge-Triggered D Flip-Flop]]
- [[#JK Flip-Flop]]

# Simple Flip-Flop

可以用兩個 inverter 達成

![[simple flip-flop.png|250]]

$Q$ 與 $\overline Q$ 的關係如下

| $Q$ | $\overline Q$ |
| --- | ------------- |
| 1   | 0             |
| 0   | 1             | 

# SR Flip-Flop

Simple two-inverter circuit is not very useful because no provision exists for controlling its state.

A more useful circuit is the set-reset(SR) flip-flop, consisting of two NOR gates.

![[SR flip-flop.png|300]]

In normal operation, $R$ and $S$ are not allowed to be high at the same time. 

> 如果 $R$ 跟 $S$ 都是 high ， $Q$ 與 $\overline Q$ 會是 low 。但是如果下一瞬間， $R$ 與 $S$ 變成 low ， $Q$ 與 $\overline Q$ 會在 high 與 low 之間一直跳動，因此我們不允許 $R$ 和 $S$ 同時為 high
> $$\begin{array}{} & R & S & Q & \overline Q \\ & 1 & 1 & 0 & 0 \\ \overset{\text{ change to reset state }}{\implies} & 0 & 0 & 1 & 1 \\ \implies & 0 & 0 & 0 & 0 \\ & & \vdots \end{array}$$

With $R$ and $S$ are both low (reset state) , the SR flip-flop remembers which input ($R$ or $S$) was high most recently.

## Using an SR Flip-Flop to Debounce a Switch

![[using an sr flip-flop to debounce a switch.png]]

在撥開關時（例如鍵盤），開關會跳動，導致只按一下卻有很多個方波形成。這時如果使用 SR flip-flop ，就可以抵銷這個效果。

# Clocked SR Flip-Flop

Often, it is advantageous to control the point in time that a flip-flop responds to its inputs.

We say that a high clock level enables the inputs to the flip-flop. On the other hand, the low clock level disables the inputs.

![[clocked SR flip-flop.png]]

Sometimes, a clocked SR fip-flop is needed, but it is also necessary to be able to set or clear the flip-flop state independent of the clock.

![[clocked SR flip-flop with asynchronous preset and clear inputs.png]]

# Edge-Triggered D Flip-Flop

We have considered circuits for which the level of the clock signal enables or disables other input signals. On the other hand, edge-triggered circuits respond to their inputs only at a transition in the clock signal.

Positive-edge-triggered circuits respond when the clock signal switches from low to high.

Negative-edge-triggered circuits respond on the transition from high to low.

![[positive-edge-triggered D flip-flop.png]]

# JK Flip-Flop

JK flip-flop has very similar operation to that of an SR fip-flop except that when both $J$ and $K$ are high, the output of the flip-flop toggles on each cycle of the clock. 

> <font face = "roman">switching from high to low on one negative-going clock transition, back to high on the next negative transition, and so on</font>

Truth table:

![[JK flip-flop.png]]

Conversion table:

| $J$ | $K$ | $Q_n$ | $Q_{n + 1}$ |
| --- | --- | ----- | ----------- |
| 0   | 0   | 0     | 0           |
| 0   | 0   | 1     | 1           |
| 0   | 1   | 0     | 0           |
| 0   | 1   | 1     | 0           |
| 1   | 0   | 0     | 1           |
| 1   | 0   | 1     | 1           |
| 1   | 1   | 0     | 1           |
| 1   | 1   | 1     | 0           | 

[[Karnaugh Maps]]:

| $\bcancel{\begin{array}{} & KQ_n \\ J \end{array}}$ | 00  | 01  | 11  | 10  |
| --------------------------------------------------- | --- | --- | --- | --- |
| 0                                                   | 0   | 1   | 0   | 0   |
| 1                                                   | 1   | 1   | 0   | 1    |

## Construct JK flip flop using D flip flop

From the [[Karnaugh Maps|karnaugh map]] above, we find out the [[Boolean Function]] of the output:

$$Q_{n + 1} = \bar K Q_n + J \bar Q_n$$

Therefore, using [[AND]] gates and [[OR]] gates, the logic diagram is:

![[Pasted image 20230420141246.png|400]]

---

# Reference

電工學課本
[D Flip Flop Conversion Techniques - blog](https://electrosome.com/d-flip-flop-conversion-techniques/)

---

# Note

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.