# 1. Corresponding V_out when P_load is 2.25W~20W

$$
\begin{array}{}
	& P_{\rm load} &=& 
	\displaystyle
	\frac{
		V_{\rm out}^2
	}{
		R_{\rm load}
	} \\
	\implies & V_{\rm out} &=& \sqrt{
		P_{\rm load} \cdot R_{\rm load}
	}
\end{array}
$$

For $P_{\rm load} = 2.25\rm W$:

$$
\begin{array}{l}
	V_{\rm out} &=& \sqrt{2.25 \cdot 100} \\
	&=& 15 \ (\rm V)
\end{array}
$$

For $P_{\rm load} = 20\rm W$:

$$
\begin{array}{l}
	V_{\rm out} &=& \sqrt{20 \cdot 100} \\
	&=& 44.72 \ (\rm V)
\end{array}
$$

For $P_{\rm load}$ in range $2.25\rm W \sim 20\rm W$, the plot of $V_{\rm out}$:

![[P_load_vs_V_out.png]]

# 2. Choose L1 that Current Ripple < 0.4A

First we calculate the duty cycle for $V_{\rm out} = 30 \rm V$:

$$
\begin{array}{}
\delta &=& \displaystyle
\frac{V_o - V_i}{V_o} \\
&=& \displaystyle 
\frac{30 - 15}{15} \\
&=& 0.5
\end{array}
$$

- $\delta$: Duty cycle.
- $V_o$: $V_{\rm out}$.
- $V_{i}$: $V_{\rm in}$.

The current flowing through the inductor $i_L$ has the following pattern:

![[Pasted image 20240517145212.png|200]]

Therefore we can know that the current ripple $\Delta i_L$ is:

$$
\begin{array}{rrl}
	& \Delta i_L &=& \displaystyle 
	\frac{V_i}{L}\delta T_s \\
	\implies & L&=& \displaystyle
	\frac{V_i\delta}{\Delta i_L f_s} \\
	\implies & L &=& 
	\displaystyle
	\frac{
		15 \cdot 0.5 
	}{
		0.4 \cdot 50 \text{k}
	} \\
	\implies & L &=& 375 \text{uH}
\end{array}
$$

- $\Delta i_L$: Ripple of current through the inductor.
- $V_i$: $V_{\rm in}$, $15\rm V$.
- $L$: Inductance.
- $T_s$: Time of one cycle.
- $f_s$: Frequency of the cycle.

From the equation above, we can conclude that the inductance should be larger than $375 \text{uH}$.

# 3. Choose C1 that the voltage ripple < 1%

The current flowing through the diode:

![[Pasted image 20240517153342.png|300]]

The current flowing through the load resistor:

![[Pasted image 20240517153417.png|300]]

Therefore we can know that:

$$
\left\{
	\begin{array}{}
		\Delta Q &=& 
		\displaystyle
		\delta T_s \frac{V_o}{R} &=&
		\displaystyle
		\frac{\delta V_o}{R f_s} \\
		\Delta Q &=& C\Delta V_o
	\end{array}
\right.
$$

Combining these two equations, we can see that:

$$
\begin{array}{rrl}
	& \Delta V_o &=& 
	\displaystyle
	\frac{\delta V_o}{RCf_s} \\
	\implies & C &=& 
	\displaystyle
	\frac{\delta V_o}{R \Delta V_o f_s} \\
	&& = &
	\displaystyle
	\frac{0.5}{
		\displaystyle
		100 \frac{\Delta V_o}{V_o} f_s
	} \\
	&& = &
	\displaystyle
	\frac{0.5}{100 \cdot 1\% \cdot 50\text k} \\
	&& = & 10 \ ({\rm \mu F})
\end{array}
$$

Therefore the capacitor should be greater than $10 {\rm \mu F}$.

# 4. LTspice Plot of Duty Cycle and Pload

![[Pasted image 20240517162846.png]]

# 5. LTspice Vout=30

![[Pasted image 20240517154424.png]]

# 6. Experiment

![[Pasted image 20240517163023.png]]