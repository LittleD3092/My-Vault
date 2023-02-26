Tag: #digital-design 
Previous: [[Logic Circuits]]
Link: [[Logic Operations]]

[TOC]

---

## AND Gate

$A$ AND $B$ 寫作 $AB$

![[and gate.png|200]]

## Logic Inverter

作 NOT 運算， $A$ 的 NOT 寫作 $\overline A$

![[logic inverter.png|200]]

## OR Gate

$A$ OR $B$ 寫作 $A + B$

![[or gate.png|200]]

## De Morgan's Laws

$$\overline{AB} = \overline A + \overline B$$

$$\overline{A + B} = \bar A \bar B$$

De Morgan's laws can be extended to three variables as follows:

$$\overline{ABC} = \overline A + \overline B + \overline C$$

$$\overline{A + B + C} = \overline A \, \overline B \, \overline C$$

## Additional Logic Gate

![[nand, nor, xor, buffer, equivalence gate symbols.png]]

### XOR Gate

$$0 \oplus 0 = 0$$
$$1 \oplus 0 = 1$$
$$0 \oplus 1 = 1$$
$$1 \oplus 1 = 0$$

XOR operation is also known as modulo-two addition

### Buffer

A buffer has a single input and produces an output with the same value as the input.

Buffers are commonly used to provide large currents when a logic signal must be applied to a low-impedance load.

---

參考資料:

Digital Design, 6th edition

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.