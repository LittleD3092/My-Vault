標籤: #fluid-mechanics 

---

[TOC]

---

Viscous flow causes the fluid to have [[Shear Stress]]. Look at the figure below:

![[2B98F3B2-F0F4-4564-B514-E4770C441DED.jpeg]]

# Shear Stress

When a force $F$ is applied on the upper plate, the fluid is deformed. The shear stress that is applied to the fluid is given by:

$$\tau_{yx} = \lim_{\delta A_y \rightarrow 0} \frac{\delta F_x}{\delta A_y} = \frac{dF_x}{dA_y}$$

# Deformation Rate

Now we want to know its deformation rate. Let's focus on time $t$ and the angle $\alpha$, the deformation rate can be given by:

$$\text{deformation rate} = \lim_{\delta t \rightarrow 0} \frac{\delta \alpha}{\delta t} = \frac{d\alpha}{dt}$$

We want to know the distance deformed, which is equivalent to the distance $\delta l$ between point $M$ and $M'$ on the figure above. We use the speed $\delta u$ and time $\delta t$:

$$\delta l = \delta u \delta t$$

And for small angles, $\delta l$ can be approximated to:

$$\delta l = \delta y \delta \alpha$$

Now let's combine the two equations above.

$$\delta u\delta t = \delta y \delta \alpha$$

$$\implies \frac{\delta \alpha}{\delta t} = \frac{\delta u}{\delta y}$$

Therefore we find out that the deformation rate can also be written as:

$$\text{deformation rate} = \lim_{\delta t \rightarrow 0} \frac{\delta \alpha}{\delta t} = \frac{d\alpha}{dt} = \frac{du}{dy}$$

# Newtonian and Non-Newtonian

We get the [[#Shear Stress]] and [[#Deformation Rate]]. We know that when a shear stress is applied, the fluid will deform at a deformation rate. But, what is the relationship between [[#Shear Stress]] and [[#Deformation Rate]]?

In fact, we have two categories for fluid:

- Newtonian fluid: The [[#Shear Stress]] and [[#Deformation Rate]] are proportional.
	- Most common fluids like water, air, and gasoline are Newtonian fluid.
- Non-Newtonian fluid: The [[#Shear Stress]] and [[#Deformation Rate]] are not proportional, and should be calculated using other method.

## Newtonian-Fluid

For Newtonian fluid, the [[#Shear Stress]] is proportional to [[#Deformation Rate]]. This means that we may write the relationship as the following equation:

$$\tau_{yx} = \mu \frac{du}{dy}$$

We say that $\mu$ is ==viscosity== of the fluid. Note that $\mu$ has dimensions $[F\cdot t/L^2]$.

In the British Gravitational system, the units of viscosity are $\text{lbf} \cdot \text{s}/\text{ft}^2$ or $\text{slug}/(\text{ft}\cdot \text{s})$. In the Absolute Metric system, the basic unit of viscosity is called a poise $[1 \text{poise} = 1 \text{g}/(\text{cm}\cdot \text{s})]$. In the SI system the units of viscosity are $\text{kg}/(\text{m}\cdot \text{s})$ or $\text{Pa} \cdot \text{s}$.

## Non-Newtonian Fluids

Fluids lilke toothpaste and paint exhibit non-Newtonian behavior. Numerous empirical equations have been proposed to model the observed relations between $\tau_{yx}$ and $du / dy$. They may be represented by the power law model:

$$\tau_{yx} = k\left( \frac{du}{dy} \right)^n$$

To keep $\tau_{yx}$ having the same sign as $du / dy$, also using a non-constant $\eta$ to represent non-Newtonian fluids, we modify the above equation:

$$\tau_{yx} = k \left\vert 
	\frac{du}{dy}
\right\vert^{n - 1} \frac{du}{dy} = \eta \frac{du}{dy}$$

The trick here is that the term $\eta = k\vert du / dy \vert^{n - 1}$ is dependent on the shear rate. In this way, $\eta$ does a better job than $\mu$ when it comes to non-Newtonian fluids.

# Inviscid Flow and Viscous Flow

## d'Alembert's Paradox

![[D'Alembert's Paradox]]

# Solving Density Using Viscosity

You can use viscosity to solve density. The relationship is as follow:

$$\rho = \frac \mu \nu$$

- $\rho$: density
- $\mu$: absolute viscosity
- $\nu$: kinematic viscosity

---

參考資料:

Introduction to Fluid Mechanics, 10th edition

---

link:

[[Stress Field]]
[[Velocity Field]]
[[Drag]]

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.