## Simulation Result

![[Microelectronics HW4 wave and schematic.png]]

## Principle Explanation

On positive half wave, the diode $D_2$ acts as open circuit, and therefore we can see that the voltage of capacitor 2 $V_2$ is $4.4\rm V$:

![[Microelectronics HW4 schematic first step.png]]

We can also see that the voltage of capacitor 3 $V_3$ is larger than the voltage of capacitor 1 $V_1$ since:

$$5 + V_1 - 0.6 = V_3$$

On the negative half wave, diode 1 will be open circuit. Also, diode 3 will be open circuit because $V_3 > V_1$. Thus, we know that capacitor 3 $C_3$ will not lose voltage on the negative cycle:

![[Microelectronics HW4 schematic step 2.png]]

From the figure above, we can also derive $V_1$:

$$
\begin{array}{l}
	& 5 + 4.4 - 0.6 - V_1 = 0 \\
	\implies & V_1 = 8.8\text V
\end{array}
$$

Substituting $V_1 = 8.8\text V$ in the positive half wave, we can derive $V_3$:

![[Pasted image 20240320160821.png]]

$$
\begin{array}{l}
	& 5 + 8.8 - 0.6 = V_3 \\
	\implies & V_3 = 13.2 \text V
\end{array}
$$

From the above derivation, we can know several things:

1. Capacitor $C_3$ will not discharge in the negative cycle.
2. The voltage of capacitor $C_3$ in steady state is $13.2\text V$.

Therefore, we have a conclusion that capacitor $C_3$ will charge to $13.2\text V$ and in its steady state, which is same as the simulation result.