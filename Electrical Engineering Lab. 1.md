標籤: #electrical-engineering-lab

---

[TOC]

---

# Solderless Breadboard

The breadboard provide an easy way to connect circuits. The holes are connected with a specific pattern, as below graph.

![[breadboard.png|200]]

The breadboard has two major area.

- Power rail: Illustrated in red lines. Usually connected to power source.
- Terminal strip: Illustrated in blue lines. Usually plugged by devices.

# Resistor

There are two types of resistor:

- Fixed resistor
	- Carbon film resistor
	![[conbon film resistor.png|150]]
	- Metal film resistor
	![[metal film resistor.png|150]]
	- Wire wound resistor
	![[wire wound resistor.png|150]]
- Adjustable resistor
![[adjustable resistor.png|150]]

The fixed resistor has color codes, from which you can get the resistance value. The chart below can help you evaluate the resistance value.

![[resistor color code.png]]

# Multi-meter

![[multi-meter.png|150]]

A multimeter can measure the following values:

- DC/AC voltage
- DC current
- Resistance

You should select the right mode, and measure from the largest scale to the smallest. Otherwise the multi-meter will break.

You should measure these values in the right way, or you might break the multi-meter or the values will not be accurate. The correct way is demonstrated in the following way:

| Measure voltage                                                                  | Measure current                                                                | Measure resistance                                                 |
| -------------------------------------------------------------------------------- | ------------------------------------------------------------------------------ | ------------------------------------------------------------------ |
| Connect a multimeter in parallel to measure the voltage drop across a light bulb | Connect a multimeter in series to measure the current flow through a lightbulb | Disconnect the power supply to measure the resistance of an object | 
| ![[muti-meter measure voltage.png]]                                              | ![[multi-meter measuring current.png]]                                         | ![[multi-meter measuring resistance.png]]                          |

# Experiment 1

Meausre the following resistor with and without human body. Record the nominal, measured value and calculate tolerance.

1. $1 \Omega$, $1k\Omega$, $1M\Omega$ without human body

|                                      | $1\Omega\qquad$ | $1k\Omega \qquad$ | $1M\Omega\qquad$ |
| ------------------------------------ | --------------- | ----------------- | ---------------- |
| Ideal Tolerance ($\%$)               | <br>            |                   |                  |
| Measured resistance value ($\Omega$) |                 |                   |                  |

2. Human body only

| Human body |
| ---------- |
| <br>           | 

3. $1\Omega$, $1k\Omega$, $1M\Omega$ with human body

|                                      | $1\Omega\qquad$ | $1k\Omega \qquad$ | $1M\Omega\qquad$ |
| ------------------------------------ | --------------- | ----------------- | ---------------- |
| Ideal Tolerance ($\%$)               | <br>            |                   |                  |
| Measured resistance value ($\Omega$) |                 |                   |                  |

# DC power supply

![[dc power supply.png|400]]

DC power supply has a dial that can set current limiting. You should set dc power supply following the steps:

1. Estimate the current you need.
2. Open the power source, set voltage and current to $0$.
3. Short circuit the positive and negative port, output the voltage.
4. Add the voltage until the led light indicates the C.C. mode.
5. Adjust the current to your estimate value.
6. Remove the short circuit between $+$ and $-$.
7. Set the voltage value.

> Why do we need current limiting?
>
> To protect the circuit from harmful effects due to a short-circuit or a similar problem.

Note that signal ground and earth ground are different.

![[signal ground and earth ground of dc power supply.png]]

Note that every device has internal resistance.

# Experiment 2

1. Set the following conditions in independent mode.
	1. Output 1: $5\text V$ DC voltage & $0.5\text A$ current limit value
	2. Output 2: $3.3\text V$ DC voltage & $0.3\text A$ current limit value

> The steps are as follows:
> 1. Open the power source.
> 2. Set both channels' voltage and current to $0$.
> 3. Short circuit both channel's positive and negative, output the voltage.
> 4. Add the voltage on both channels until the corresponding led light indicates the C.C. mode.
> 5. Adjust channel 1 to $0.5\text A$, adjust channel 2 to $0.3\text A$.
> 6. Remove the short circuit of channel 1 and 2.
> 7. Set channel 1 to $5\text V$, channel 2 to $3.3\text V$
> 8. Measure and finish the following chart.

| Channel 1 voltage | Channel 1 current | Channel 2 voltage | Channel 2 current |
| ----------------- | ----------------- | ----------------- | ----------------- |
| <br>                  |                   |                   |                   |

2. Set the following conditions in independent mode and connect the ground terminal carefully.
	1. Output 1: $+5 \text V$ DC voltage & $0.5 \text A$ current limit value.
	2. Output 2: $-5\text V$ DC voltage & $0.5 \text A$ current limit value.

> The steps are as follows:
> 1. Set both channels' voltage and current to $0$.
> 2. Short circuit both channel's positive and negative, output the voltage.
> 3. Add the voltage on both channels until the corresponding led light indicates the C.C. mode.
> 4. Adjust both channel to $0.5 \text A$.
> 5. Remove the short circuit of channel 1 and 2.
> 6. Connect the ground of channel 1 and channel 2.
> 7. Set channel 1 to $5\text V$, channel 2 to $-5\text V$.
> 8. Measure and finish the following chart.

| Channel 1 voltage | Channel 1 current | Channel 2 voltage | Channel 2 current |
| ----------------- | ----------------- | ----------------- | ----------------- |
| <br>                  |                   |                   |                   |

# Experiment 3

![[electrical engineering lab 1 experiment 3.png|200]]

1. Set $R_1$ and $R_2$ both equal to $100\Omega$. Measure the voltage across $R_1$ and $R_2$, check if the voltage sum up to $10\text V$.

> The steps are as follows:
> 1. Set the power source.
> 	1. Set channel 1's voltage and current to $0$.
> 	2. Short circuit both channel's positive and negative, output the voltage.
> 	3. Add the voltage on both channels until the corresponding led light indicates the C.C. mode.
> 	4. Adjust the current of channel 1 to higher than $0.05 \text A$.
> 	5. Remove the short circuit of channel 1.
> 	6. Set channel 1 to $10\text V$.
> 	7. Measure and record the `Source voltage`.
> 2. Attach the circuit like above.
> 3. Attach the power source.
> 4. Measure the voltage and record `voltage of R1` and `voltage of R2`.
> 5. Evaluate `Evaluate the voltage of R1+R2` and `error`.

$$\text{error} = \frac{\vert V_S - (V_{R_1} + V_{R_2}) \vert}{V_S} \times 100 \%$$

| Source voltage | voltage of $R_1$ | voltage of $R_2$ | Evaluate the voltage of $R_1$ $+$ the voltage of $R_2$ | Error ($\%$) |
| -------------- | ---------------- | ---------------- | ------------------------------------------------------ | ----------- |
|                | <br>             |                  |                                                        |             |

2. Set $R_1$ and $R_2$ both equal to $1\text M\Omega$. Measure the voltage across $R_1$ and $R_2$, check if the voltage sum up to $10\text V$.

> The steps are as follows:
> 1. Measure and record the `Source voltage`.
> 2. Attach the circuit like above.
> 3. Attach the power source.
> 4. Measure the voltage and record `voltage of R1` and `voltage of R2`.
> 5. Evaluate `Evaluate the voltage of R1+R2` and `error`.

$$\text{error} = \frac{\vert V_S - (V_{R_1} + V_{R_2}) \vert}{V_S} \times 100 \%$$

| Source voltage | voltage of $R_1$ | voltage of $R_2$ | Evaluate the voltage of $R_1$ $+$ the voltage of $R_2$ | Error ($\%$) | 
| -------------- | ---------------- | ---------------- | ------------------------------------------------------ | ------------ |
|                | <br>             |                  |                                                        |              |

Look at the error, is it the same? Why?

A: 

# Experiment 4

> 1. Set the power source.
> 	1. Set channel 1's voltage and current to $0$.
> 	2. Short circuit both channel's positive and negative, output the voltage.
> 	3. Add the voltage on both channels until the corresponding led light indicates the C.C. mode.
> 	4. Adjust the current of channel 1 to lower than $0.2 \text A$.
> 	5. Remove the short circuit of channel 1.
> 	6. Set channel 1 to $10\text V$.
> 2. Measure and record the four voltages `Number 1~4`.

![[electrical engineering lab 1 experiment 4.png]]

| Number 1 | Number 2 | Number 3 | Number 4 (GND and $-$) | Number 4 (GND and $+$) | 
| -------- | -------- | -------- | ---------------------- | ---------------------- |
|          |          |          | <br>                   |                        |

---

參考資料:

Electrical Engineering Lab. 1 ppt, word

---

link:


---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.