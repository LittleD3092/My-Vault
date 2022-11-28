標籤: #automatic-control 

---

[TOC]

---

In [[Mathematical Modeling of Control Systems]], we learnt how to model a system.
In this note, we will learn how to analyze the system to various input.

In practice, the input signal to a control system is not known ahead of time but random. Because of this, we have some **typical test signals**:

- Step functions
- Ramp functions
- Acceleration functions
- Impulse functions
- Sinusoidal functions
- White noise

# Keywords

- **Transient response** $c_{\rm tr}$: The response which goes from the initial state to the final state.
- **Steady-state response** $c_{\rm ss}$: The response which the system output behaves as $t$ approaches infinity.

The **system response** $c(t)$ may be written as

$$c(t) = c_{\rm tr} + c_{\rm ss}(t)$$

- **Absolute stability**: Whether the system is stable or unstable.
- **Equilibrium**: When the system is not subjected to any disturbance or input, the output stays at the same state.
- **Stable**: If the output eventually comes back to its equilibrium state when subjected to an initial condition.
- **Critically stable**: The oscillation continues forever.
- **Unstable**: The output diverges without bound from its equilibrium state.

# First-Order Systems

![[Pasted image 20221128152511.png]]

The input-output relationship is

$$\frac{C(s)}{R(s)} = \frac{1}{Ts + 1}$$



---

參考資料:

Modern Control Engineering, 5th edition

---

link:


---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.