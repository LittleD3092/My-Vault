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

---

參考資料：

Introduction to Fluid Mechanics, 10th edition