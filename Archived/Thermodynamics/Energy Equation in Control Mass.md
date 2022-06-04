標籤: #Thermodynamics #list 

---

這章會講到有物質進出的情況

# Mass, $\dot{ V }$, $\dot{ m }$

## Mass

$$\frac{ dm_{ cv } }{ dt } = \sum \dot{ m_{ i } } - \sum \dot{ m_e } = \Delta \dot{ m_{ cv } }$$

$\dot{ m_i }$: mass in
$\dot{ m_e }$: mass exit

![[Volume Flow Rate.png]]

## $\dot{ V }$

$$\dot{ V } = v_{ avg }\cdot A = \int vdA$$

or

$$v_{ avg } = \frac{ 1 }{ A }\int VdA$$

## $\dot{ m }$

$$\dot{ m } = \rho \dot{ V }$$
$$ = \rho_{ avg } \cdot v_{ avg } \cdot A$$
$$ = \int \rho v dA$$
$$ = \int ( \frac{ v }{ \nu } )dA$$

# Energy Equation

## flow [[work]]

The [[work]] been done by fluid entering or leaving the control volume

$$\dot{ W }_{ i } = P_{ i }\nu_{ i }\dot{ m }_{ i }$$
$$\dot{ W }_{ e } = P_{ e }\nu_{ e }\dot{ m }_{ e }$$

## Total Energy Equation

把 Flow [[Work]] 加上 energy in the system

For the energy in the system:
$$E = U + \frac{ 1 }{ 2 }mv^2 + mgz$$
$$e = u + \frac{ 1 }{ 2 }v^2 + gz$$

For the total energy:
$$e + P \nu = u + P\nu + \frac{ 1 }{ 2 }v^2 + gz$$
$$ = h + \frac{ 1 }{ 2 }v^2 + gz$$
$h$: [[Enthalpy]]

For the [[Control Volume]]:
$$\frac{ dE{ cv } }{ dt } = \dot{ Q }_{ cv } - \dot{ W }_{ cv } + \dot{ m }_{ i } e_{ i } - \dot{ m }_{ e } e_e + \dot{ w }_{ \text{ flow in } } - \dot{ w }_{ \text{ flow out } }$$
$$ = \dot{ Q }_{ cv } - \dot{ W }_{ cv } + \dot{ m }_{ i }(e_i + P_i \nu_i) - \dot{ m }_e (e_e + P_e \nu_e)$$
$$ = \dot{ Q }_{ cv } - \dot{ W }_{ cv } + \dot{ m }_{ i }(h_i + \frac{ 1 }{ 2 }v_i^2 + gz_i) - \dot{ m }_{ e }( h_e + \frac{ 1 }{ 2 }v_e^2 + gz_e )$$

$\therefore$ Final form of $1^{ \text{ st } }$ law of Thermodynamics

$$\underline{ \frac{ dE_{ cv } }{ dt } = \dot{ Q }_{ cv } - \dot{ W }_{ cv } + \sum \dot{ m }_{ i }(h_i + \frac{ v_i^2 }{2} + gz_i) - \sum \dot{ m }_e (h_e + \frac{ 1 }{ 2 }v_e^2 + gz_e) }_{ \# }$$

> [[Heat]]
> [[Archived/Thermodynamics/Work]]

## Total [[Enthalpy]] $h_{ tot }$

$$h_{ tot } = h + \frac{ v^2 }{ 2 } + gz$$

# Steady State Process

Steady State: will not change with time (Steady-flow process)

Steady <-> unsteady (transient)

- During a steady-flow process fluid properties within a control volume may / may not change with position but ==not with time==
- The mass and energy of a control volume under steady state remain constant

## The fluid properties

$$
\left\{
	\begin{array}{}
		\text{ at inlet / exit } \\
		\text{ cross boundary }
	\end{array}
\right.
\text{ remain constant }
$$

$$\implies \frac{ dm_{ cv } }{ dt } = 0 \qquad \frac{ dE_{ cv } }{ dt } = 0$$

$$\therefore \sum \dot{ m }_{ i } = \sum \dot{ m }_e$$

$$\implies \underline{ \dot{ Q }_{ cv } + \sum \dot{ m }_{ i }(h_i + \frac{ v_i^2 }{ 2 } + gz_i) = \sum \dot{ m }_e(h_e + \frac{ v_e^2 }{ 2 } + gz_e) + \dot{ W }_{ cv } }_{ \# }$$

## Steady flow devices

- [[Heat Exchanger]]
- [[Nozzle and Diffuser]] 噴嘴和升壓器
- [[Throttle]]
- [[Mixing Chamber]]
- [[Turbine]]
- [[Compressor and Pump]]

# [[Transient Process]] (Unsteady)

## For Mass Balance

$$m_{ in } - m_{ out } = \Delta m_{ system }$$
$$(m_2 - m_1)_{ cv } + \sum m_e - \sum m_i = 0$$

## For Energy Equation

$$\dot{ Q }_{ cv } + \sum \dot{ m }_i (h_i + \frac{ v_i^2 }{ 2 } + gz_i) = \underbrace{ \frac{ dE_{ cv } }{ dt } }_{ \text{ unsteady } } + \sum \dot{ m }_e(h_e + \frac{ v_e^2 }{ 2 } + gz_e) + \dot{ W }_{ cv }$$

$$\text{ where } E_{ cv } = m(u + \frac{ v^2 }{ 2 } + gz)$$

.

> $$\int_0^t \frac{ dE_{ cv } }{ dt } = E_2 - E_1$$
> 
> $$ = m_2(u_2 + \frac{ v_2^2 }{ 2 } + gz_2) - m_1( u_1 + \frac{ v_1^2 }{ 2 } + gz_1 )$$

$$\implies \underline{ Q_{ cv } + \sum m_i (h_i + \frac{ v_i^2 }{ 2 } + gz_i) = \sum m_e (h_e + \frac{ v_e^2 }{ 2 } + gz_e) + \left[ m_2(u_2 + \frac{ v_2^2 }{ 2 } + gz_2) - m_1(u_1 + \frac{ v_1^2 }{ 2 } + gz_1) \right] + W_{ cv } }_{ \# }$$

## Assumption

1. The state within the control volume may change with time, but is uniform throughout the entire control volume at any instant time
2. The fluid flow at inlet / exit is uniform and steady

---

參考資料:

熱力學 Ch4 OCW

---

link:

[[First Law of Thermodynamics]]