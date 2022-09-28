標籤: #fluid-mechanics 

---

In fluid dynamics, drag is a force acting opposite to the relative motion of any object moving with respect to a surrounding fluid.

Types of drag are generally divided into the following categories:

- form drag or pressure drag due to the size and shape of a body
- skin friction drag or vicous drag due to the friction between the fluid and the surface

| Shape and flow                              | Form Drag       | Skin Friction   |
| ------------------------------------------- | --------------- | --------------- |
| ![[188px-Flow_plate.svg.jpg]]               | $\approx 0\%$   | $\approx 100\%$ |
| ![[188px-Flow_foil.svg.jpg]]                | $\approx 10\%$  | $\approx 90\%$  |
| ![[188px-Flow_sphere.svg.jpg]]              | $\approx 90\%$  | $\approx 10\%$  |
| ![[188px-Flow_plate_perpendicular.svg.jpg]] | $\approx 100\%$ | $\approx 0\%$   | 

# Equation

Drag is expressed by means of the drag equation:

$$\underline{ F_D = \frac 1 2 \rho v^2 C_D A }_\#$$

- $F_D$: Drag force
- $\rho$: density of the fluid.
- $v$: speed of the object relative to the fluid
- $A$: cross sectional area
- $C_D$: the drag coefficient

## Drag Coefficient

The drag coefficient depends on the shape of the object and on the [[Reynolds Number]], which is:

$$R_e = \frac{vD}{\nu} = \frac{\rho vD}{\mu}$$

- $D$: characteristic diameter. for a sphere, $D$ is the $D$ of the sphere itself. for a rectangle cross-section, 
$$D = 1.30 \cdot \frac{(a\cdot b)^{0.625}}{(a + b)^{0.25}}$$
where $a$ and $b$ are rectangle edges.
- $\nu$: kinematic viscosity of the fluid. (equal to dynamic viscosity $\mu$ divided by the density $\rho$)

At low $R_e$, $C_D$ is aymptotically proportional to $R_e^{-1}$. Which means, the drag is linearly proportional to speed.

At high $R_e$, $C_D$ is approximately constant and drag will vary as the square of the speed.

### Low Reynolds Number (Low Velocity)

Drag force can be expressed as a function of a dimensionless number $C_D$, which is dimensionally identical to the [[Bejan Number]]. Consequently, drag force and drag coefficient can be a function of [[Bejan Number]]. In fact, from the expression of drag force it has been obtained:

$$D = \Delta_p A_w = \frac 1 2 C_DA_f\frac{\nu \mu}{l^2}R_{eL}^2$$

$$\implies \underline{ C_D = 2\frac{A_w}{A_f}\frac{B_e}{R_{eL}^2} }_\#$$

- $A_w$: wet area
- $A_f$: front area

### High Reynolds Number (High Velocity)

This section is about high reynolds number, which is bigger than about $1000$.

---

參考資料:

[Drag - wiki](https://en.wikipedia.org/wiki/Drag_(physics))

---

link:

[[Reynolds Number]]
[[Bejan Number]]