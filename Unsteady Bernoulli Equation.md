Tag: #fluid-mechanics 
Previous: [[Bernoulli's Equations]]
Link: 

---

[TOC]

---

# Equation

SImilar to [[Bernoulli's Equations]], we start from [[Euler's Equation]]:

$$
\rho\frac{D\vec V}{Dt} = 
\rho \vec g - \nabla p
$$

$$\implies \frac{D \vec V}{Dt} = -\frac 1 \rho \nabla p - g \hat k$$

We can convert the equation above to a scalar equation by taking the dot product with $d\vec s$:

$$\frac{D \vec V}{Dt} \cdot d \vec s = \frac{DV}{Dt}ds = V\frac{\partial V}{\partial s}ds + \frac{\partial V}{\partial t}ds = -\frac 1 \rho \nabla p \cdot d\vec s - g \hat k \cdot d\vec s$$

> Note that
> $$\begin{array}{l} \displaystyle \frac{\partial V}{\partial s}ds &=& dV & (\text{the change in }V \text{ along }s) \\ \nabla p \cdot d\vec s &=& dp & (\text{the change in pressure along }s) \\ \hat j \cdot d\vec s &=& dz & (\text{the change in }z\text{ along }s)\end{array}$$

Substituting, we get

$$VdV + \frac{\partial V}{\partial t}ds = -\frac{dp}{\rho} - gdz$$



---

參考資料:

Introduction to Fluid Mechanics, 10th edition

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.