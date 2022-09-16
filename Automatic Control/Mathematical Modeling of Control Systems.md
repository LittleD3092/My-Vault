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

### Transfer Function

Transfer function is a property of a [[#Linear System]] that decribe the relationship between input and output.

$$\text{Transfer Function} \triangleq G(s) = 
\left.\frac{ \mathcal{L}(\text{output}) }{ \mathcal{L}(\text{input}) }\right\vert_{\text{zero initial condition}}$$

The $\mathcal L$ represent [[Laplace Transform]].

- Order: The highest power of $s$ in the denominator of the transfer function is called the "order" of the system.
$$\text{e.g. }G(s) = \frac{5s + 6}{s^2 + 2s + 3}, \text{ order } = 2$$

- Note that transfer function is limited to systems that are described by linear time-invariant [[Differential Equation]]s.
- Note that transfer function is independent of the magnitude & nature of the input function.
- Transfer function can be obtained from differential equations or established experimentally.

---

參考資料:

Automatic Control class

---

link:

[[Laplace Transform]]