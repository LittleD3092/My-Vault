標籤: #Thermodynamics #fluid-mechanics #list 

---

Control volume means a volume that is in space of interiest. There will be in and out flow.

This note shows one of the ways of examining a flowing fluid, which is control volume method.

# Basic Laws

We start by deriving the basic equations that we might need. These equations are called ==rate equations== because the equations are expressed in terms of the rates of flow in and out.

## Conservation of Mass

For a system, we have the simple result that $M = \text{ constant}$ for steady flow. Therefore, we write:

$$\left.
	\frac{dM}{dt}
\right)_{\text{system}} = 0$$

where

$$M_{\text{system}} = \int_{M(\text{system})}dm = \int_{V(\text{system})} \rho dV$$

## Newton's Second Law

Newton's Second law states that the sum of all external forces acting on the system is equal to the time rate of change of linear momentum of the system.

$$\vec F = \left.
	\frac{d\vec P}{dt}
\right)_{\text{system}}$$

where the linear momentum of the system is given by

$$\vec P_{\text{system}} = \int_{M(\text{system})}\vec Vdm = 
\int_{V(\text{system})}\vec V \rho dV$$

## Angular-Momentum Principle

The angular-momentum priciple states that the rate of change of angular momentum is equal to the sum of all torques acting on the system.

$$\vec T = \left.
	\frac{d\vec H}{dt}
\right)_{\text{system}}$$

where the angular momentum of the system is given by

$$\vec H_{\text{system}} = 
\int_{M(\text{system})} \vec r \times \vec V dm = 
\int_{V(\text{system})} \vec r \times \vec V \rho dV$$

Torque can be produced by surface and body forces (gravity only in here) and also by shafts that cross the system boundary,

$$\vec T = 
\vec r \times \vec F_S + 
\int_{M(\text{system})} \vec r \times \vec g dm + 
\vec T_{\text{shaft}}$$

## First Law of Thermodynamics

> [[First Law of Thermodynamics]]

The first law of thermodynamics is a statement of conservation of energy for a system,

$$\delta Q - \delta W = dE$$

The equation can be written in rate form

$$\dot Q - \dot W = \left.
	\frac{dE}{dt}
\right)_{\text{system}}$$

where the total energy $E$ is

$$E_{\text{system}} = 
\int_{M(\text{system})}edm = 
\int_{V(\text{system})}e\rho dV$$

and specific energy $e$ is

$$e = u + \frac{V^2}{2} + gz$$

## Second Law of Thermodynamics

> [[Second Law of Thermodynamics]]

The second law of thermodynamics states that the change in entropy, $dS$, of the system satisfies

$$dS \geq \frac{\delta Q}{T}$$

We can write the above equation on rate basis

$$\left.
	\frac{dS}{dt}
\right)_{\text{system}} \geq \frac 1 T \dot Q$$

where the total entropy of the system is given by

$$S_{\text{system}} = 
\int_{M(\text{system})}sdm = 
\int_{V(\text{system})}s\rho dV$$

# Control Volume Equations

We have the basic rates of change equations in [[#Basic Laws]], and what we should do next is to derive the general expression control volume equations.

We have five equations evaluating $M, \vec P, \vec H, E$, and $S$. One by one, we let all of them be represented by the symbol $N$. Corresponding to this extensive property, we will also need the intensive property $\eta$.

$$N_{\text{system}} = \int_{M(\text{system})} \eta dm = 
\int_{V(\text{system})}\eta \rho dV$$

---

參考資料:

熱力學 Ch3 OCW
Introduction to Fluid Mechanics, 10th edition

---

link:

[[Thermodynamic System]]
[[First Law of Thermodynamics]]
[[Second Law of Thermodynamics]]