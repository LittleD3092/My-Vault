Tag: #automatic-control 
Previous: [[Frequency Response Method]]
Link: 

---

[TOC]

---

- Bode diagram consists of two graphs:
	- Plot of magnitude of a sinusoidal transfer function in logarithmic scale.
	- Plot of the phase angle.
- Representation of logarithmic magnitude: $20\log\vert G(j\omega) \vert$
	- Which is decibels, $\rm dB$.

# Basic Factors

The curve of bode diagrams consists of basic factors:

1. [[#Gain]] $K$
2. [[#Integral and Derivative]] $1/(j\omega), \quad j\omega$
3. [[#First-Order Factors]] $(1 + j\omega T)^{\pm 1}$
4. [[#Quadratic Factors]] $(1 + 2\zeta(j\omega / \omega_n) + (j\omega/\omega_n)^2)^{\pm 1}$

You may factorize the [[Transfer Function]] to the elements above, and plot the diagram by adding all elements.

## Gain

For simple transfer function $K$,

- Magnitude is $20\log \vert K\vert$.
- Phase:
	- If $K>0$, phase is $0\degree$.
	- If $K < 0$, phase is $-180\degree$.

## Integral and Derivative

For integral,

$$G(j\omega) = \frac{1}{j\omega} = -\frac{j}{\omega}$$

Magnitude:

$$\vert G(j\omega) \vert = \frac{1}{\omega}$$

$$\text{Magnitude} = 20\log\frac 1 \omega = -20\log\omega$$

Phase is $-90\degree$.

---

For Derivative,

$$G(j\omega) = j\omega$$

$$\text{Magnitude} = 20\log\omega$$

Phase is $90\degree$.

---

The bode diagram should look like this:

![[Pasted image 20230104195434.png]]

## First-Order Factors

For first order factors in denominator,

$$G(j\omega) = \frac{1}{1 + j\omega T}$$

$$\text{Magnitude} = 20\log\left\vert \frac{1}{1 + j\omega T} \right\vert = -20\log\left\vert 1 + j\omega T \right\vert = -20\sqrt{1 + \omega^2 T^2}$$

> Note that for low frequencies
> $$\omega << \frac 1 T$$
> The log magnitude may be approximated
> $$-20\log\sqrt{1 + \omega^2T^2} = -20\log 1 = 0$$
> For high frequencies
> $$\omega >> \frac 1 T$$
> The log magnitude may be approximated to a straight line
> $$-20\log\sqrt{1 + \omega^2T^2} = -20\log\omega T$$

$$\text{Phase } \phi = -\tan^{-1}\omega T$$

![[Pasted image 20230104214549.png]]

## Quadratic Factors

---

參考資料:

Modern Control Engineering, 5th edition

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.