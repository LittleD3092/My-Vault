Tag: #digital-design 
Previous: [[Digital Design]]
Link: 

[TOC]

---

The definition of registers are as follows:

- A group of flip-flops, each of them shares a common clock and is capable of storing one bit.
- An $n$-bit register consists of a group of $n$ flip-flops storing $n$ bits.
- May consider gates that affect their operation.

# Four-bit Register

![[Pasted image 20230509155644.png|300]]

- Consists with four [[D Flip-Flop]].
- The value $(I_3, I_2, I_1, I_0)$ determines the output $(A_0, A_1, A_2, A_3)$ after clock triggers.
- The input $Clear\_b$ is an active-low signal that clears the register.

# Four-bit Parallel Load Register

- In a digital system, the master clock supplies a continuous clock pulses.
- A separate control signal *load* must be used to decide whether *loading* should be performed.

![[Pasted image 20230509160809.png|400]]

- We use a two-bit [[Multiplexer|multiplexer]] with *Load* as selecting.
- One input is from the original output of flip-flop.
- The other is from the input $I$.

# Four-bit Shift Register

- Shift registers are registers that are capable of shifting the binary information to its neighboring cell.
- Consists of a chain of [[Flip-Flop|flip-flops]] in cascade.
- All [[Flip-Flop|flip-flops]] receive common clock pulses.

![[Pasted image 20230509161251.png]]

- **Note**: In practice, a reset signal is required.

## Serial Transfer

- The datapath of a digital system is said to be in *serial mode* when information is transferred and manipulated one bit at a time.

![[Pasted image 20230509162022.png|500]]

| Timing pulse  | Shift Register A | Shift Register B |
| ------------- | ---------------- | ---------------- |
| Initial value | `1011`           | `0010`           |
| After $T_1$   | `1101`           | `1001`           |
| After $T_2$   | `1110`           | `1100`           |
| After $T_3$   | `0111`           | `0110`           |
| After $T_4$   | `1011`           | `1011`           | 

- The output of register A is connected to the input of register B, to provide serial transfer.
- The output of register A is connected to the input of itself, so data will not be lost.
- The `Shift control` input can control whether the bits are shifted.

## Serial Addition

| Parallel Addition                                             | Serial Addition                   |
| ------------------------------------------------------------- | --------------------------------- |
| Operations in digital computers are usually done in parallel. |                                   |
| This is faster.                                               | This is slower.                   |
| Require more hardware components.                             | Require less hardware components. | 

![[Pasted image 20230509162756.png|500]]

---

# Reference

Digital Design, 6th edition

---

# Note

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.