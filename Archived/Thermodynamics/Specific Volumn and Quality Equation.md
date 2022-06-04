標籤: #Thermodynamics 

---

在 [[Saturated liquid-vapor mixture]] 時，使用 specific volume 和 [[Quality]] 的等式

# 證明

$$\nu = \frac{V_{\text{total}}}{m_{\text{total}}} = \frac{V_{\text{vapor}} + V_{\text{liquid}}}{m_{\text{total}}}$$

$$ = \frac{ m_{\text{liq}} \cdot \nu_{\text{f}} + m_{\text{vap}} \cdot \nu_{\text{g}} }{ m_{ \text{ total } } }$$

$$ = \underbrace{ \frac{ m_{ \text{ liq } } }{ m_{ \text{ total } } } }_{ (1 - x) }\nu_{ \text{ f } } + \underbrace{ \frac{ m_{ \text{ vap } } }{ m_{ \text{total} } } }_{ x }\nu_{ \text{ g } }$$

$$ = (1 - x)\nu_{ \text{ f } } + x \nu_{ \text{ g } }$$

$$ = \nu_f + x\underbrace{ ( \nu_{ \text{g} } - \nu_{ \text{f} } ) }_{\nu_{\text{fg}}}$$

$$\nu = \frac{V_{\text{total}}}{m_{\text{total}}} = \nu_f + x \nu_{fg}$$

# 例題

$$200 \degree {\rm C} \quad \text{Saturated Water}$$
$$x = 70 \%$$
$$\nu = ?$$
.
$$\text{ from chart: }
\begin{array}{}
	\nu_f = 0.001156 \; {\rm m^3/kg} \\
	\nu_g = 0.12736 \; {\rm m^3/kg}
\end{array}
$$

$$\nu = (1 - x)\nu_f + x\nu_g$$

$$ = (1 - 0.7) \cdot 0.001156 + 0.7 \cdot 0.12736$$

$$ = \underline{ 0.0895 \; {\rm m^3/kg} }_{\#}$$

---

參考資料:

[交大熱力學ocw - youtube](https://youtube.com/playlist?list=PLj6E8qlqmkFt83RMhWiOggy669xF9Z3aA)

---

link:

[[Specific Heat and Quality Equation]]