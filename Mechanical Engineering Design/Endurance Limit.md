標籤: #Mechanical-Engineering-Design 

---

[TOC]

---

# Endurance Limit Modifying Factors

We estimated the endurance limit $S_e'$ by the lab results. But it is unrealistic to expect the endurance limit to match the values obtained in the laboratory.

Some factors that will change the endurance limit $S_e$ includes:

- **Material**: composition, basis of failure, variability
- **Manufacturing**: method, heat treatment, fretting corrosion, surface condition, stress concentration
- **Environment**: corrosion, temperature, stress state, relaxation times
- **Design**: size, shape, life, stress state, speed, fretting, galling

Marin proposed that correction factors for each effect be applied as multipliers to adjust the endurance limit. Marin's equation is written as

$$S_e = k_ak_bk_ck_dk_eS_e'$$

- $k_a$: [[#Surface Factor]]
- $k_b$: [[#Size Factor]]
- $k_c$: [[#Load Factor]]
- $k_d$: [[#Temperature Factor]]
- $k_e$: [[#Reliability Factor]]
- $S_e'$: Rotary-beam test specimen endurance limit.
- $S_e$: Endurance limit at the critical location of a machine part in the geometry and condition of use.

## Surface Factor

Represented by $k_a$.

In laboratory, the specimen is polished. In practical situation, the parts have surface roughness, which cause localized stress concentration. This creates an environment that is prone to crack initiation.

> It is significant to note that this is not entirely a factor of the surface roughness, but also includes metallurgical conditions.

Lipson and Noll collected data from studies and organize them into several common commercial surface finishes. An example is the diagram below.

![[Pasted image 20221117153316.png]]

For convenience, the curves of figure above are fitted with a power curve equation

$$k_a = aS_{ut}^b$$

Where $a$ and $b$ are given in the table below.

| Surface Finish         | Factor $a$, with $S_{ut}$ in $\text{kpsi}$ | Factor $a$, with $S_{ut}$ in $\text{MPa}$ | Exponent $b$ |
| ---------------------- | ------------------------------------------ | ----------------------------------------- | ------------ |
| Ground                 | $1.21$                                     | $1.38$                                    | $-0.067$     |
| Machined or cold-drawn | $2.00$                                     | $3.04$                                    | $-0.217$     |
| Hot-rolled             | $11.0$                                     | $38.6$                                    | $-0.650$     |
| As-forged              | $12.7$                                     | $54.9$                                    | $-0.758$     | 

## Size Factor

Represented by $k_b$.

The endurance limit of specimens loaded in bending and torsion has been observed to decrease slightly as the specimen size increases.

### Round Rotating Bars

The factor can be evaluated using a compilation of data from several sources. The curve-fit equations for round rotating bars in bending and torsion can be given by

$$
k_b = 
\left\{
	\begin{array}{l}
		\displaystyle\left(\frac{d}{0.3}\right)^{-0.107}=0.879d^{-0.107} &
		0.3 \leq d \leq 2 \text{ in} \\
		0.91d^{-0.157} &
		2 < d \leq 10 \text{ in} \\
		\displaystyle\left(\frac{d}{7.62}\right)^{-0.107} = 1.24d^{-0.107} & 7.62 \leq d \leq 51 \text{ mm} \\
		1.51d^{-0.157} & 51 < d \leq 254 \text{ mm}
	\end{array}
\right.
$$

> For $d$ less than $3\text{ in}$, the data is scattered. Unless more specific data is available to warrant a higher value, $k_b = 1$ is recommended.

For axial loading there is no size effect, so

$$k_b = 1$$

### Other Shapes and Non Rotating

The section [[#Round Rotating Bars]] is for rotating and round bars only. For non-rotating and other shapes, the load is applied at the same area again and again, therefore the endurance limit is smaller than round rotating bars.

Thus, we substitude $d$ of the equation in [[#Round Rotating Bars]] to equivalent diameter $d_e$ based on different shapes.

> Kuguel introduced a critical volume theory in which the volume of material experiencing a stress above $95\%$ of the maximum stress is considered to be critical.
> 
> Let's illustrate it by calculating $d_e$ for nonrotating bar:
> 
> The method employs an *equivalent diameter* $d_e$ obtained by equating **the volume of material** stressed at and above $95\%$ of the maximum stress
> $$A_{0.95\sigma} = 0.01046d^2 \qquad \text{for non-rotating bar}$$
> to the same volume in the **rotating-beam specimen**.
> $$A_{0.95\sigma} = \frac \pi 4 [d^2 - (0.95d)^2] = 0.0766d^2 \qquad \text{for rotating bar}$$
> $$\implies 0.01046d^2 = 0.0766d_e^2$$
> $$\implies d_e = 0.370d \qquad \text{for non-rotating bar}$$

The below chart shows common nonrotating structural shapes and its corresponding $A_{0.95\sigma}$.

| Shapes                                    | Area $A_{0.95\sigma}$                                                                                                                 |
| ----------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------- |
| ![[Pasted image 20221117162038.png\|200]] | $$\begin{array}{l} A_{0.95\sigma} & = & 0.01046d^2 \\ d_e & = & 0.370d \end{array}$$                                                  |
| ![[Pasted image 20221117162203.png\|200]] | $$\begin{array}{l}A_{0.95\sigma} & = & 0.05hb \\ d_e & = & 0.808\sqrt{hb}\end{array}$$                                                |
| ![[Pasted image 20221117162341.png\|200]] | $$A_{0.95\sigma} = \left\{\begin{array}{l}0.10at_f & & \text{axis 1-1} \\ 0.05ba & t_f > 0.025a & \text{axis 2-2}\end{array}\right.$$ |
| ![[Pasted image 20221117162626.png\|300]] | $$A_{0.95\sigma} = \left\{ \begin{array}{l} 0.05ab & \text{axis 1-1} \\ 0.052xa + 0.1t_f(b - x) & \text{axis 2-2} \end{array} \right.$$                                                                                                                                      |

## Load Factor

Represented by $k_c$.

Estimates of endurance limit in [[#Other Shapes and Non Rotating]] are obtained from completely reversed bending.

For other loading types, a load factor is used.

$$k_c = 
\left\{
	\begin{array}{l}
		1 & \text{bending} \\
		0.85 & \text{axial} \\
		0.59 & \text{torsion}
	\end{array}
\right.$$

## Temperature Factor

Represented by $k_d$.

$$k_d = S_T / S_{RT} = 
\left\{
	\begin{array}{l}
		0.98 & + & 3.5(10^{-4})T_F & - & 6.3(10^{-7})T_F^2 \\
		0.99 & + & 5.9(10^{-4})T_C & - & 2.1(10^{-6})T_C^2
	\end{array}
\right.$$

- $k_d$: Temperature factor. If the endurance limit for the desired operation temperature is available, you should set $k_d$ to $1$ instead of using the formula above.
- $S_T$: Ultimate strength at the operating temperature.
- $S_{UT}$: Ultimate strength at the room temperature.
- $T_F$: The operating temperature in degrees Fahrenheit.
- $T_C$: The operating temperature in degrees Celsius.

## Reliability Factor

Represented by $k_e$.

Sometimes you find out that the tested data scattered a lot. In this case, you may use a reliability factor to be more conservative.

Based on the reliability, you can get **transformation variate** $z_a$ using the chart. Then using the below formula, you can obtain reliability factor $k_e$.

$$k_e = 1 - 0.08z_a$$

The chart for transformation variate $z_a$ can be found in a full and complete table. The table below shows some of the useful rows.

| Reliability, $\%$ | Transformation Variate $z_a$ | Reliability Factor $k_e$ |
| ----------------- | ---------------------------- | ------------------------ |
| $50$              | $0$                          | $1.000$                  |
| $90$              | $1.288$                      | $0.897$                  |
| $95$              | $1.645$                      | $0.868$                  |
| $99$              | $2.326$                      | $0.814$                  |
| $99.9$            | $3.091$                      | $0.753$                  |
| $99.99$           | $3.719$                      | $0.702$                  | 

---

參考資料:

Mechanical Engineering Design, 11th edition

---

link:


---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.