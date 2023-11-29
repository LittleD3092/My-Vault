標籤: #Thermodynamics 

---

> content:
> - [[#Definition]]
> - [[#Entropy of a Pure Substance]]
> - [[#Entropy Change in Reversible Process]]
>     - [[#Carnot Cycle T-s diagram]]
>     - [[#Reversed Carnot Cycle]]
> - [[#Entropy of a Solid or Liquid]]
> - [[#Entropy Change of an Ideal gas]]
> - [[#Entropy change of a control mass during irreversible process]]
> - [[#Entropy Generation]]
> - [[#Entropy as a rate equation]]
> - [[#Entropy Equation for a Control Volume]]

- A thermodynamic property
- $T = 0K$, $s = 0$
- molecular disorder or randomness
- Entropy can be seen as molecular disorder or molecular randomness

$$\text{ Entropy }_{ \text{ gas } } > \text{ Entropy }_{ \text{ liq } } > \text{ Entropy }_{ \text{ solid } }$$

# Definition

$$ds = (\frac{ \delta Q }{ T })_{ rev }$$

$s$: Entropy

or

$$\delta Q = Tds$$

$$\Delta s = \underbrace{ s_2 - s_1 }_{ \text{ check table } } = \int_1^2\frac{ \delta Q }{ T }$$

# Entropy of a [[Pure Substance]]

Saturated:

$$s = (1 - x)s_f + xs_g$$
$$s = s_f + xs_{ fg }$$

# Entropy Change in Reversible Process

## [[Carnot Cycle]] (T-s diagram)

1. Isothermal Expansion (Heating)
2. Adiabatic Expansion
3. Isothermal Compression (Cooling)
4. Adiabatic Compression

![[Carnot Cycle T-s Diagram.png]]

$$s_2 - s_1 = \int_1^2(\frac{ \delta Q }{ T })_{ rev } = \frac{ _1Q_2 }{ T_H }$$

$$s_4 - s_3 = \int_3^4(\frac{ \delta Q }{ T })_{ rev } = \frac{_3Q_4}{ T_L }$$

$(2 \rightarrow 3), (4 \rightarrow 1)$ is reversible, adiabatic $\implies$ entropy remains constant (isentropic process)

## Reversed [[Carnot Cycle]]

Refrigerator or Heat Pump

![[Reversed Carnot Cycle T-s Diagram.png]]

$$Q_H = W + Q_L$$

- consider a reversible heat transfer process

![[Reversible Heat Transfer Process.png]]

$$s_2 - s_1 = s_{ fg }$$

$$ = \frac{ 1 }{ m }\int_1^2(\frac{ \delta Q }{ T })$$

$$ = \frac{ 1 }{ mT }\int_1^2\delta Q$$

$$ = \frac{ _1q_2 }{ T } = s_2 - s_1$$

$$ = \frac{ h_{ fg } }{ T }$$

.

$$_2q_3 = \frac{ 1 }{ m }\int_2^3\delta Q = \frac{ 1 }{ m }\int_2^3 Tds$$

- Area under T-s diagram represents the quantity of heat transfer in reversible process

# Entropy of a Solid or Liquid

for solid or liquid

$$dh = du + d(P\underbrace{ \nu }_{ \text{ const } })$$

$$\approx du + \underbrace{ \nu }_{ \text{ very small (neglect) } } dP$$

$$\approx du$$

$$\approx \underbrace{ c }_{ \text{ specific heat } }dT$$

$$\therefore dh \approx du = cdT$$

From [[Gibbs Function]]:
$$Tds = du + P\underbrace{ d\nu }_{ \approx 0 }$$

$$\therefore ds \approx \frac{ du }{ T } = \frac{ c }{ T }dT$$

$$\implies \int_1^2 ds = \int_1^2\frac{ c }{ T }dT$$

$$\implies \underline{ s_2 - s_1 = c\ln(\frac{ T_2 }{ T_1 }) }_{ \# } \qquad \text{ for solid or liquid only }$$

# Entropy Change of an Ideal gas

1. From [[Gibbs Function]]:
$$Tds = du + Pd\nu$$

$$\implies ds = \frac{ du }{ T } + \frac{ P }{ T }d\nu$$

$$
\text{ From }
\left\{
	\begin{array}{l}
		du = c_vdT \\
		\text{ ideal gas } \frac{ P }{ T } = \frac{ R }{ \nu }
	\end{array}
\right.
$$

$$\implies ds = c_v\frac{ dT }{ T } + \frac{ P }{ \nu }d\nu$$

integrate each side

$$\underline{ s_2 - s_1 = \int_1^2 c_v\frac{ dT }{ T } + R\ln\frac{ \nu_2 }{ \nu_1 } }_{ \# }$$

2. From [[Gibbs Function]]

$$Tds = dh - \nu dP$$

$$\implies ds = \frac{ dh }{ T } - \frac{ \nu }{ T }dP$$

$$
\text{ From }
\left\{
	\begin{array}{l}
		dh = c_p dT \\
		\text{ ideal gas } \frac{ \nu }{ T } = \frac{ R }{ P }
	\end{array}
\right.
$$

$$\implies ds = c_p \frac{ dT }{ T } - R\frac{ dP }{ P }$$

integrate each side

$$\implies \underline{ s_1 - s_2 = \int_1^2 c_p \frac{ dT }{ T } - R \ln (\frac{ P_2 }{ P_1 }) }_\#$$

## (a) if we assume constant $c_p$, $c_v$

$$
\implies 
\begin{array}{l}
	s_2 - s_1 = c_p \ln \frac{ T_2 }{ T_1 } - R \ln \frac{ P_2 }{ P_1 } \\
	s_2 - s_1 = c_v \ln \frac{ T_2 }{ T_1 } + R \ln \frac{ \nu_2 }{ \nu_1 }
\end{array}
$$

## (b) specific heat changes with temperature

Define standard entropy:

$$s_{ T_0 } = \int_{ T_0 }^T \frac{ T }{ c_{ P, 0 }dT }\qquad 0: \text{ reference point }$$

$$\implies s_2 - s_1 = (s_{ T_2 }^0 - s_{ T_1 }^0) - R\ln(\frac{ P_2 }{ P_1 })$$

# Entropy change of a control mass during irreversible process

Reversible: A-B

$$
\oint \frac{ \delta Q }{ T } = \int_1^2(\frac{ \delta Q }{ T })_A + \int_1^2(\frac{ \delta Q }{ T })_B = 0
$$

Irreversible: C-B

$$\oint \frac{ \delta Q }{ T } = \int_1^2(\frac{ \delta Q }{ T })_C + \int_2^1(\frac{ \delta Q }{ T })_B < 0$$

$$\implies \underbrace{ \int_1^2(\frac{ \delta Q }{ T })_A }_{ rev } > \underbrace{ \int_1^2(\frac{ \delta Q }{ T })_C }_{ irrev }$$

since path A is reversible and entropy is a property

$$\int_1^2(\frac{ \delta Q }{ T })_A = \int_1^2dS_A = \int_1^2dS_C$$

$$
\implies ds \geq \frac{ \delta Q }{ T }
\begin{array}{l}
	> : irrev \\
	= : rev
\end{array}
$$

$$s_2 - s_1 \geq \int_1^2\frac{ \delta Q }{ T }$$

# Entropy Generation

The entropy quation:

$$
ds = \frac{ \delta Q }{ T } + \delta s_{ gen }
\left\{
	\begin{array}{}
		\delta s_{ gen } > 0 \qquad irrev \\
		\delta s_{ gen } = 0 \qquad rev
	\end{array}
\right.
$$

Note: $ds = \frac{ \delta Q }{ T }$ reversible

$$\implies \underline{ s_2 - s_1 = \int_1^2\frac{ \delta Q }{ T } + _1s_{2 \text{ gen }} }_{ \text{ entropy balance equation } }$$

- The entropy always increases (irreversible) - [[Second Law of Thermodynamics]]
- $\Delta S_{ total } = \Delta S_{ system } + \Delta S_{ surrounding } \geq 0$
- From $ds = \underbrace{ \frac{ \delta Q }{ T } }_{ \text{ heat transfer } } + \underbrace{ \delta s_{ gen } }_{ \text{ irreversible } }$
$\delta Q = TdS - T\delta S_{ gen }$

From [[First Law of Thermodynamics]]

$$\delta Q_{ irrev } = dU + PdV$$

[[Gibbs Function]]
$$TdS = dU + PdV$$

$$\implies \underline{ \delta W_{ irrev } = PdV - T\delta S_{ gen } }_\#$$

$T\delta S_{ gen }$: lost [[work]], lost opportunity to extrace [[work]]

For irreversible process

$$\text{ work } \neq\int PdV $$

$$\text{ Heat transfer } \neq \int Tds$$

# Entropy as a rate equation

$$\frac{ ds }{ \delta t } = \frac{ 1 }{ T }\frac{ \delta Q }{ \delta t } + \frac{ \delta S_{ gen } }{ \delta t }$$

for a control mass

$$\underbrace{ \frac{ ds_{ \text{ control mass } } }{ dt } }_{ \text{ flux of entropy } } = \underbrace{ \sum\frac{ 1 }{ T } \dot{ Q } }_{ \text{ more than one source } } + \dot{ S }_{ gen }$$

# Entropy Equation for a Control Volume

![[Entropy equation for a control volume.png]]

From entropy balance equation

rate of change:

$$
\frac{ dS_{ \text{ control volume } } }{ dt }
= \underbrace{ \sum \dot{ m }_{ i }s_i }_{ \text{ in } } - \underbrace{ \sum\dot{ m }_{ e }s_e }_{ \text{ out } } + \underbrace{ \sum\frac{ \dot{ Q }_{ \text{ control volume } } }{ T } }_{ \text{ heat transfer } } + \underbrace{ \dot{ S }_{ \text{ gen } } }_{ \geq 0 }
$$

$$
\implies \frac{ dS_{ \text{ control volume } } }{ dt } \geq \sum \dot{ m }_{ i }s_i - \sum \dot{ m }_{ e }s_e + \sum \frac{ \dot{ Q }_{ \text{ control volume } } }{ T }
\qquad
\begin{array}{}
	> : \text{ irreversible } \\
	= : \text{ reversible }
\end{array}
$$

## Steady State Process

For steady state:

$$\frac{ dS_{ \text{ control mass } } }{ dt } = 0$$

$$\implies \sum \dot{ m }_eS_e - \sum\dot{ m }_iS_i = \sum\frac{ \dot{ Q }_{ \text{ control volume } } }{ T } + \dot{ S }_{ \text{ gen } }$$

consider only one $\dot{ m }_i$ and $\dot{ m }_e$

$$\implies \dot{ m }_eS_e - \dot{ m }_iS_i = \dot{ m }(S_e - S_i)$$

$$ = \sum\frac{ \dot{ Q }_{ \text{ control volume } } }{ T } + \dot{ S }_{ \text{ gen } }$$

divide by $\dot{ m }$

$$\implies \underline{ s_e - s_i = \sum\frac{ q }{ t } + s_{ \text{ gen } } }_{ \# }$$

if adiabatic 

$$s_e = s_i + s_{ gen }$$

## Transient Process (unsteady)

$$\frac{ d }{ dt }(m\cdot s)_{ \text{ control mass } } = \sum \dot{ m }_is_i - \sum \dot{ m }_{ e }s_e + \sum \frac{ \dot{ Q }_{ \text{ control mass } } }{ T } + \dot{ S }_{ gen }$$

$\implies$ integrate from $0$ to $t$

$$\underline{ (m_2s_2 - m_1s_1)_{ cv } = \sum m_is_i - \sum m_es_e + \int_0^t\frac{ \dot{ Q }_{ cv } }{ T }dt + _1s_{ 2\ gen} }_{ \# }$$

---

參考資料:

[劉耀先熱力學OCW](https://youtube.com/playlist?list=PLj6E8qlqmkFt83RMhWiOggy669xF9Z3aA)

---

link:

[[Saturated liquid-vapor mixture]]