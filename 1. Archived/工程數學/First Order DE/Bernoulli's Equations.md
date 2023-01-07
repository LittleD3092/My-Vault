標籤: #工程數學 #fluid-mechanics 
Previous: [[Euler's Equation]]

# 工程數學

Bernoulli's equation:
$$\frac{dy}{dx} + P(x)y = f(x)y^n$$
$$\text{We can set}\quad u = y^{1-n},\; \frac{dy}{dx} = \frac{1}{1 - n}u^{\frac{n}{1-n}}\frac{du}{dx}$$

代入後
$$\frac{1}{1-n}u^{\frac{n}{1-n}}\frac{du}{dx} + P(x)u^{\frac{1}{1-n}} = f(x)u^{\frac{n}{1 - n}}$$
$$\overset{\text{乘}\;(1-n)u^{\frac{-n}{1-n}}}{\implies}\frac{du}{dx} + P(x)(1-n)u = (1-n)f(x)$$

接著可以用 [[Linear Equations]] 解

最後記得代回$u = y^{1-n}$

還有算[[singular point]]

---

# Fluid Mechanics

## Restrictions

1. Steady flow.
2. Incompressible flow.
3. Frictionless flow.
4. Flow along a streamline.

> You should keep the restrictions in mind whenever you consider using the Bernoulli equation!
> 
> The Bernoulli's equation cannot be used *through*:
> 1. Propeller.
> 2. Pump.
> 3. Turbine.
> 4. Windmill.

## Derivation

The Bernoulli's equation for fluid mechanics is derived using [[Euler's Equation]].

> Recall that [[Euler's Equation]] for steady flow along a streamline:
> $$-\frac 1 \rho \frac{\partial p}{\partial s} - g\frac{\partial z}{\partial s} = V\frac{\partial V}{\partial s}$$

> If a fluid particle moves a distance $ds$ along a streamline, 
> $$\left\{ \begin{array}{} \displaystyle \frac{\partial p}{\partial s}ds & = & dp  & \text{(the change in pressure along }s) \\ \displaystyle \frac{\partial z}{\partial s}ds & = & dz & \text{(the change in elevation along }s) \\ \displaystyle \frac{\partial V}{\partial s}ds & = & dV & \text{(the change in speed along }s) \end{array} \right.$$

By multiplying [[Euler's Equation]] by $s$:

$$-\frac{dp}{\rho} - gdz = VdV \qquad \text{(along }s)$$

$$\implies \frac{dp}{\rho} + V dV + g dz = 0 \qquad (\text{along }s)$$

Integrating the equation, we get:

$$\int \frac{dp}{\rho} + \frac{V^2}{2} + gz = \text{constant}$$

For incompressible flow, $\rho = \text{constant}$:

$$\underline{ \frac p \rho + \frac{V^2}{2} + gz = \text{constant} }_\#$$

## Example

A pitot tube is inserted in an air flow (at STP) to measure the flow speed. The tube is inserted so that it points upstream into the flow and the pressure sensed by the tube is the stagnation pressure. The static pressure is measured at the same location in the flow, using a wall pressure tap. If the pressure difference is $30{\ \rm mm}$ of mercury, determine the flow speed.

![[Pasted image 20230107160726.png|250]]

---

The Bernoulli's equation is given by:

$$\frac p \rho + \frac{V^2}{2} + gz = \text{constant}$$

Since they are measured in the same location, 

$$\frac{p}{\rho} + \frac{V^2}{2} = \text{constant}$$

The flow speed in the pitot tube $V_0 = 0$:

$$\implies \frac{p_0}{\rho} = \frac{p}{\rho} + \frac{V^2}{2}$$

- $p_0$: The stagnation pressure at the tube opening.

Solve for $V$:

$$V = \sqrt{\frac{2(p_0 - p)}{\rho_{\rm air}}}$$

$$\implies V = \sqrt{\frac{2 \rho_{\rm H_2O}gh \cdot  {\rm SG}_{\rm Hg}}{\rho_{\rm air}}}$$

Substitute the values:

$$\implies V = \sqrt{2 \times 1000 \frac{\rm kg}{\rm m^3} \times 9.81 \frac{\rm m}{\rm s^2} \times 30 {\rm \ mm} \times 13.6 \times \frac{\rm m^3}{1.23 \rm \ kg} \times \frac{1\rm \ m}{1000 \rm \ mm}} = \underline{80.8 {\rm \ m/s}}_\#$$

## Energy Grade Line and Hydraulic Grade Line

For convenience, we define some value using Bernoulli's equation:

*Energy grade line (EGL)*:

$$\underline{EGL = \frac{p}{\rho g} + \frac{V^2}{2g} + z}_\#$$

*Hydraulic grade line (HGL)*:

$$\underline{HGL = \frac{p}{\rho g} + z}_\#$$

The difference between EGL and HGL is always the dynamic pressure term:

$$EGL - HGL = \frac{V^2}{2g}$$

The physical meaning:

- EGL:
	- Can be measured by pitot tube.
	- Is constant for incompressuble, inviscid flow in the absence of work devices.
- HGL:
	- Can be measured by static pressure tap.



---

參考資料：

Introduction to Fluid Mechanics, 10th edition