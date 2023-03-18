標籤: #automatic-control 

---

[TOC]

---

The control systems is often modelled as a mathematical model, therefore this note shows how to model the system dynamics in mathematical format.

> # Causality
> 
> Before we begin, we first need to know what causality is. Causality is a rule that says "current output of the system depends on the past input but does not depend on the future input".
>
> For example, an output $@ t = 0$ depends on the input for $t \leq 0$, but does not depend on the input for $t > 0$.
>
> This rule may be simple, but it is important.

# Format

The mathematical model of a control system is usually [[Differential Equation]] or difference equation. We give those model names:

1. State-space representation (differential equation): suitable for optimal control, nonlinear systems.
2. Tranfer funcction representation (difference equation): suitable for transient response, single-input-single-output, linear time-invariant system.

The course of automatic control (I) focus on the second one.

## Linear System

A system is called linear if the principle of superposition applies.

$$u_1 \rightarrow y_1$$

$$u_2 \rightarrow y_2$$

Superposition:
$$u_1 + u_2 \rightarrow y_1 + y_2$$

Multiply by a constant:
$$cu_1 \rightarrow cy_1$$

## Linear Time-Invariant System (LTI)

A differential equation is linear and time-invariant if the coefficients are constnat. The coefficients should not depend on time.

ex.

$$
\begin{array}{}
	\dot x = ax + bu & \implies & LTI \\
	\dot x = a(t)x + b(t)u & \implies & time-variant
\end{array}
$$

The system often uses differential equation to analysis.

There are two ways of analysis:

- [[#Transfer Function]]
- [[#State Space]]

### Transfer Function

![[Transfer Function]]

### State Space

See the below note for more:

![[State Space]]

# Problems

This section shows the essential problems for this topic. You should master all these problems.

## Simplify Block Diagram

### Question

Simplify the block diagram shown in figure below. Then obtain the closed-loop transfer function $C(s) / R(s)$.

![[Pasted image 20221019212454.png]]

### Answer

Move $H_3$:

![[Pasted image 20221019220645.png]]

> Recall for feedback:
> ![[Block Diagram#Feedback]]

Using [[Block Diagram#Feedback]]:

![[Pasted image 20221019220834.png]]

Using another [[Block Diagram#Feedback]], we can get the transfer function:

$$\frac{C(s)}{R(s)} = \frac{
\frac{G_1G_2}{1 + H_1G_1G_2} \times \frac{G_3G_4}{1 + G_3G_4H_2}
}{
1 - \frac{G_1G_2}{1 + H_1G_1G_2} \times
\frac{G_3G_4}{1 + G_3G_4H_2} \times
\frac{H_3}{G_1G_4}
}$$

After organizing:

$$\underline{
	\frac{C(s)}{R(s)} = 
	\frac{
		G_1G_2G_3G_4
	}{
		(1 + H_1G_1G_2)
		(1 + G_3G_4H_2) - 
		G_2G_3H_3
	}
}$$

## Transfer Function with Disturbance

### Question

Obtain transfer functions $C(s) / R(s)$ and $C(s) / D(s)$ of the system shown in figure below.

![[Pasted image 20221019223738.png]]

### Answer

From the above diagram, you can get the following relationship:

$$
\left\{
	\begin{array}{l}
		E(s) & = & R(s) & - & HC(s) \\
		U(s) & = & G_fR(s) & + & G_cE(s) \\
		C(s) & = & (G_1U(s) & + & D(s)) & \times & G_p
	\end{array}
\right.
$$

Substitude $E(s)$ and $U(s)$ for the last equation, we can get:

$$C(s) = G_1G_fG_pR(s) + G_1G_cG_pR(s) - HG_1G_cG_pC(s) + G_pD(s)$$

We may organize this a little, and get a cleaner $C(s)$, $R(s)$, and $D(s)$ relationship:

$$(1 + HG_1G_cG_p)C(s) = (G_1G_fG_p + G_1G_cG_p)R(s) + G_pD(s)$$

To find transfer function $C(s) / R(s)$, we let $D(s) = 0$:

$$\underline{
	\frac{C(s)}{R(s)} = 
	\frac{
		G_1G_p(G_f + G_c)
	}{
		1 + HG_1G_cG_p
	}
}_\#$$

To find transfer function $C(s) / D(s)$, we let $R(s) = 0$:

$$
\underline{
	\frac{C(s)}{D(s)} = 
	\frac{G_p}{
		1 + HG_1G_cG_p
	}
}_\#
$$

---

參考資料:

Automatic Control class
Modern Control Engineering, 5th edition

---

link:

[[Laplace Transform]]