標籤: #動力學 

---

# 2D Motion

## Planar Motion

包含了三種情況

1. [[#Translation]]: 平移
2. [[#Rotation about a fixed axis]]: 旋轉
3. [[#General plane motion Relative-Motion Analysis|General plane motion]]: 邊旋轉邊平移

最重要的是 3. ，因為它最泛用

### Translation

假設 $A, B$ 點為一個 rigid body 上的兩個參考點

#### Position

$$r_B = r_A + r_{ B / A }$$

#### Velocity

$$v_B = v_A + \frac{ d r_{ B / A } }
{ dt }$$

$$\because dr_{ B / A } / dt = 0 \quad (A, B\text{ 點間沒有相對運動，因為是 translation})$$

$$\therefore \underline{
v_B = v_A }_{ \# }$$

#### [[Acceleration]]

$$a_B = a_A$$

### Rotation about a fixed axis

#### Angular [[Acceleration]]

$$\alpha d\theta = \omega d\omega$$

> 跟 [[Acceleration]] 相似:
> $$ads = vdv$$

#### Velocity

$$\vec v = \omega \times \vec r_p$$

$\vec v$: rigid body 上一個點 $P$ 的速度
$\vec r_p$: rigid body 上一個點 $P$ 的位置

#### [[Acceleration]]

$$a_t = \alpha r$$

$$a_n = \omega^2 r$$

$\alpha$: 角加速度

對於 rigid body 其中一點 $P$ ，角加速度可以用 [[Cross Product]] 表示

$$\vec a = \alpha \times \vec r_p + \omega \times (\omega \times \vec r_p)$$

$$\vec a = \vec a_t + \vec a_n = 
\alpha \times \vec r - \omega^2 \vec r$$

### General plane motion (Relative-Motion Analysis)

需要使用 Relative-Motion Analysis 分析

#### Position

$$\underline{ 
	\vec r_B = \vec r_A + \vec r_{ B / A }
}_\#$$

#### Displacement

$A$ and $B$ undergo displacements $dr_A$ and $dr_B$

$$\implies d\vec r_B = 
d\vec r_A + d\vec r_{ B / A }$$

#### Velocity

$$\frac{ d\vec r_B }{ dt } = 
\frac{ d\vec r_A }{ dt } + 
\frac{ d\vec r_{ B / A } }{ dt }$$

$$\implies \underline{ 
\vec v_B = 
\vec v_A + \vec v_{ B / A } }_{ \# }$$

$\because \vec v_{ B / A }$ 是相對運動，因此可以用 [[Cross Product]] 表示

$$\implies \underline{ \vec v_B = 
\vec v_A + 
\omega \times \vec r_{ B / A } }_{ \# }$$

#### [[Acceleration]]

在上面我們知道 velocity 的關係

$${ \bf v }_B = 
{ \bf v }_A + { \bf v }_{ B / A }$$

$$\implies 
\frac{ d{ \bf v }_B }{ dt } = 
\frac{ d{ \bf v }_A }{ dt } + 
\frac{ d{ \bf v }_{ B / A } }{ dt }$$

$$\implies \underline{ { \bf a }_B = 
{ \bf a }_A + 
( { \bf a }_{ B / A } )_t + 
( { \bf a }_{ B / A } )_n }_{ \# }$$

這個結果可以用圖片來看

![[rigid body acceleration.png]]

並且上式也可以用角加速度與角速度表示

$$\implies 
\underline{ { \bf a }_B = 
{ \bf a }_A + 
\alpha \times { \bf r }_{ B / A } +
\omega \times (
	\omega \times  { \bf r }_{ B / A } 
) }_{ \# }$$

$$\implies 
\underline{ { \bf a }_B = 
{ \bf a }_A + 
\alpha \times { \bf r }_{ B / A } - 
\omega^2 { \bf r }_{ B / A } }_{ \# }$$

$\alpha$: 角加速度

## Instantaneous Centor of Zero Velocity

![[Instantaneous Center]]

## Translating Coordinate System

Use for analyzing motions of two points on a mechanism which are not located in the same body

> example of translating coordinate system
> ![[example of translating coordinate system.png|400]]
> 譬如以上的例子，我們希望分析 $C$ 點與 $O$ 點之間的相對運動，而他們在不同的 body 上。這時我們就可以使用 translating coordinate system ，架設一個會隨著 body 轉動的 coordinate (圖中 $x, y$)。

在以下的結果中，你會發現有點類似[[#General plane motion Relative-Motion Analysis|一般 rigid body]] 的算法，但是在這裡的情況不同，座標軸是會旋轉的。因此底下結果的推導多考慮了座標軸的旋轉（類似[[極座標]]的推導），因此結果也不同。

注意以下的向量皆是使用 $x, y$ 座標軸，而不是 $X, Y$ 座標軸。

### Position 

$$ { \bf r }_B = 
{ \bf r }_A + { \bf r }_{ B / A }$$

### Velocity

$${ \bf v }_B = 
{ \bf v }_A + 
{ \bf \Omega } \times { \bf r }_{ B / A } + 
({ \bf v }_{ B / A })_{ xyz }$$

### [[Acceleration]]

$${ \bf a }_B = 
{ \bf a }_A + 
\dot{ \bf \Omega } \times 
{ \bf r }_{ B / A } + 
{\bf\Omega} \times 
({\bf \Omega } \times 
{ \bf r }_{ B / A }) +
2{ \bf \Omega } \times 
({ \bf v }_{ B / A })_{ xyz } + 
({ \bf a }_{ B / A })_{ xyz }$$

## Force and [[Acceleration]]

### Mass [[Moment]] of Inertia

根據牛頓定律

$${ \bf F } = m { \bf a }$$

而 [[Moment]] 等於

$${ \bf M } = I { \bf \alpha }$$

其中 $I$ 是 mass [[Moment]] of inertia，$\alpha$ 是角速度

mass [[Moment]] of inertia 的計算相似於 [[Area Moment of Inertia]] ，如下

$$I = \int_m r^2 dm$$

using volume elements $V$

$$I = \int_V r^2 \rho dV$$

$\rho$: 密度

#### Common Mass [[Moment]] of Inertia

[List of moment of inertia - wiki](https://en.wikipedia.org/wiki/List_of_moments_of_inertia)

| Figure                                       | [[Moment]] of Inertia                                   |
| -------------------------------------------- | ------------------------------------------------------- |
| ![[rod moment of inertia.png]]               | $$I = \frac 1 { 12 } mL^2$$                             |
| ![[plate moment of inertia.png]]             | $$I_z = \frac 1 2 mr^2$$ $$I_x = I_y = \frac 1 4 mr^2$$ |
| ![[solid sphere of radius r and mass m.png]] | $$I = \frac 2 5 mr^2$$                                  |
| ![[thin ring of radius r and mass m.png]]    | $$I_z = mr^2$$ $$I_x = I_y = \frac 1 2 mr^2$$           | 

#### Parallel-Axis Theorem

![[parallel axis theorem.png|300]]

$$I_2 = I_1 + md^2$$

$m$: 總質量
$I_1$: 相對軸 1 的 inertia
$I_2$: 相對軸 2 的 inertia
$d$: 軸 1 和軸 2 的距離

#### Radius of Gyration

The [[Moment]] of inertia of a body about a specified axis can be expressed using the radius of gyration, $k$

$$I = mk^2$$

$$\text{ or }$$

$$k = \sqrt{ \frac{ I }{ m } }$$

### Planar Kinetic Equations of Motion

$$\sum { \bf F } = m { \bf a }_G$$

$$\sum { \bf M }_P = -\bar y m(a_G)_x + 
\bar x m(a_G)_y + I_G \alpha$$

![[planar kinetic equations of motion.png|350]]

$$
\implies
\left\{
	\begin{array}{}
		\sum F_x & = & m(a_G)_x \\
		\sum F_y & = & m(a_G)_y \\
		\sum M_G & = & I_G \alpha \\
		& \text{ or } \\
		\sum M_P & = & -\bar ym(a_G)_x & 
		+ & \bar xm(a_G)_y & + I_G \alpha
	\end{array}
\right.
$$

#### Rotation about a Fixed Axis

![[force and acceleration rotation around a fixed axis.png|350]]

$$\left\{
	\begin{array}{}
		\sum F_n & = & m(a_G)_n & = & m\omega^2 r_G \\
		\sum F_t & = & m(a_G)_t & = & m \alpha r_G \\
		\sum M_G & = & I_G \alpha
	\end{array}
\right.$$

也可以對 $O$ 點取 [[Moment]]

$$\left\{
	\begin{array}{}
		\sum F_n & = & m(a_G)_n & = & m\omega^2 r_G \\
		\sum F_t & = & m(a_G)_t & = & m \alpha r_G \\
		\sum M_O & = & I_O \alpha
	\end{array}
\right.$$

#### [[Moment]] Equation about the Instantaneous Centor

也可以對 Instantaneous Centor 取 [[Moment]]

$$\underline{ \sum M_{ IC } = I_{ IC } \alpha }_{ \# }$$

## [[Work]] and Energy

### Kinetic Energy

![[kinetic energy of rigid body.png|350]]

The kinetic energy of the entire body is 

$$T = \frac 1 2 \int_m dm v_i^2$$

if the body has an angular velocity $\omega$

$${\bf v}_i = {\bf v}_p + {\bf v}_{ i / p }$$

$$ = (v_p)_x \hat i + 
(v_p)_y \hat j + 
\omega \hat k \times (x\hat i + y\hat j)$$

$$ = [(v_p)_x - \omega y]\hat i + 
[(v_p)_y + \omega x]\hat j$$

$$\implies {\bf v}_i \cdot {\bf v}_i = v_i^2$$

$$ = [(v_p)_x - \omega y]^2 + [(v_p)_y + \omega x]^2$$

$$ = (v_p)_x^2 - 2(v_p)_x\omega y + \omega^2y^2 + (v_p)_y^2 + 2(v_p)_y\omega x + \omega^2x^2$$

$$ = v_p^2 - 2(v_p)_x \omega y + 2(v_p)_y\omega x + \omega^2 r^2$$

$$\implies T = \frac 1 2(\int_m dm)v_p^2 - (v_p)_x\omega(\int_mydm) + (v_p)_x\omega(\int_mxdm) + \frac 1 2 \omega^2(\int_m r^2dm)$$

> Since 
> $$\bar ym = \int ydm$$
> $$\bar xm = \int xdm$$
> they represent the location of the body's center of mass $G$ with respect to $P$
> 
> $$\int_m r^2dm = I_p$$

As a special case, if $P$ coincides with $G$, $\bar y = \bar x = 0$

$$\implies \underline{ T = \frac 1 2 mv_G^2 + \frac 1 2 I_G \omega^2 }_\#$$

#### Rotation about a Fixed Axis

![[kinetic energy rotation about a fixed axis.png|250]]

$$T = \frac 1 2 m v_G^2 + \frac 1 2 I_G \omega^2$$

$$ = \frac 1 2 m r_G^2 \omega^2 + \frac 1 2 I_G \omega^2$$

$$ = \frac 1 2(I_G + mr_G^2)\omega^2$$

$$ = \underline{ \frac 1 2 I_o \omega^2 }_\#$$

#### General Plane Motion

$$T = \frac 1 2 m v_G^2 + \frac 1 2 I_G \omega^2$$

$$ = \underline{ \frac 1 2 I_{ IC } \omega^2 }_\#$$

similar to rotation about a fixed axis

### The [[Work]] of a Force

#### [[Work]] of a Variable Force

$$\underline{ U_F = \int{ \bf F } \cdot d{\bf r} = \int_s F\cos \theta ds }_\#$$

#### The [[Work]] of a Couple [[Moment]]

$$\underline{ U_M = \int_{ \theta_1 }^{ \theta_2 } Md\theta }_\#$$

if ${\bf M}$ has constant magnitude

$$\underline{ U_M = M(\theta_2 - \theta_1) }_\#$$

#### Principle of [[Work]] and Energy

$$\underline{ T_1 + \sum U_{ 1 - 2 } = T_2 }_\#$$

## Linear and Angular Momentum

### Linear Momentum

$${\bf L} = m {\bf v}_G$$

### Angular Momentum

angular momentum of $i$th particle is

$$({\bf M}_P)_i = {\bf r} \times m_i{\bf v}_i$$

using cartesian vectors

$$\implies (H_P)_i \hat k = m_i(x \hat i + y\hat j) \times [(v_P)_x \hat i + (v_P)_y \hat j + \omega \hat k \times(x \hat i + y \hat j)]$$

$$\implies (H_P)_i = -m_iy(v_P)_x + m_i x (v_P)_y + m_i \omega r^2$$

$$\implies H_P = -\left(\int_m ydm\right)(v_P)_x + \left(\int_m xdm\right)(v_P)_y + \left( \int_m r^2dm \right)\omega$$

$$\implies H_P = -\bar y m (v_P)_x + \bar x m(v_P)_y + I_P \omega$$

$$\implies \underline{ H_G = I_G \omega }_\#$$

### Momentum of Motions

#### Translation

$$
\underline{
	\begin{array}{}
		L & = & mv_G \\
		H_G & = & 0
	\end{array}
}_\#
$$

#### Rotation About a Fixed Axis

$$
\underline{
	\begin{array}{}
		L & = & mv_G \\
		H_G & = & I_G \omega
	\end{array}
}_\#
$$

$$\implies \underline{ H_O = I_O \omega }_\#$$

#### General Plane Motion

$$
\underline{
	\begin{array}{}
		L & = & mv_G \\
		H_G & = & I_G \omega
	\end{array}
}_\#
$$

$$\implies \underline{ H_{IC} = I_{ IC }\omega }_\#$$

### Principle of Impulse and Momentum

if motion occurs in the $x-y$ plane:

$$
\underline{
	\left\{
		\begin{array}{}
			m(v_{ Gx })_1 & + & \sum\int_{ t_1 }^{ t_2 } F_xdt & = & m(v_{ Gx })_2 \\
			m(v_{ Gy })_1 & + & \sum \int_{ t_1 }^{ t_2 }F_y dt & = & m(v_{ Gy })_2 \\
			I_G\omega_1 & + & \sum\int_{ t_1 }^{ t_2 }M_G dt & = & I_G \omega_2 
		\end{array}
	\right.
}_\#
$$

# 3D Motion

## Motion

### Rotation About a Fixed Point

> #### Euler's Theorem
> two "component" rotations about different axis passing through a point are equivalent to a single resultant rotation about an axis passing through the point
> 
> $\implies$ If more than two rotations are applied, they can be combined into pairs, and each pair can be further reduced to combine into one rotation

#### Finite Rotations

If component rotations used in Euler's theorem are finite, it is important that the order in which they are applied be maintained.

![[why finite rotations order matters.png]]

如上圖，如果先轉 $\theta_2$ 再轉 $\theta_1$ 結果會完全不同

#### Infinitesimal Rotations

與 Finite Rotations 相反

When defining the 3D angular motions, only rotations which are infinitesimally small will be considered and they can be classified as vector, so they can be added easilly.

#### Velocity for Rotation

$$\vec v = \vec \omega \times \vec r$$

#### Acceleration for Rotation

$$\vec a = \vec \alpha \times \vec r + \vec \omega \times ( \vec \omega \times \vec r )$$

### The Time Derivative of a Vector

> 這個常用在計算 angular velocity $\Omega$ 和 angular acceleration $\dot\Omega$
> $$\Omega = \sum \omega_i$$
> $$\dot\Omega = \sum \dot\omega_i$$
> 其中一個 $\dot \omega_i$ 我們會用 time derivative of a vector 的公式求出
> $$\dot\omega = (\dot\omega)_{xyz} + \underbrace{\Omega}_{\text{ 前面的角速度加總 }} \times \omega$$

當在空間中架設一個會隨時間轉動的座標軸 $xyz$ ，並且有一個以此座標軸表示的向量 $\vec A$ ， $\dot { \vec A }$ 會使用接下來的公式算

![[time derivative of a vector.png|300]]

$$\vec A = A_x \hat i + A_y \hat j + A_z \hat k$$

因為 $\hat i, \hat j, \hat k$ 相對於 $xyz$ 座標軸沒有轉動

$$\implies (\dot {\vec A})_{ xyz } = 
\dot A_x \hat i + 
\dot A_y \hat j + 
\dot A_z \hat k$$

但 $\hat i, \hat j, \hat k$ 對 $XYZ$ 有轉動，因此

$$\implies \dot { \vec A } = \dot A_x \hat i +
\dot A_y \hat j +
\dot A_z \hat k +
A_x \dot {\hat i} +
A_y \dot {\hat j} +
A_z \dot {\hat k}
$$

並且 $\dot{ \hat i }, \dot{ \hat j }, \dot{ \hat k }$ 可以用 $\vec \Omega$ 與外積算出

$$
\left\{
	\begin{array}{}
		\dot {\hat i} = \vec \Omega \times \hat i \\
		\dot {\hat j} = \vec \Omega \times \hat j \\
		\dot {\hat k} = \vec \Omega \times \hat k 
	\end{array}
\right.
$$

$$\implies \underline{\dot{ \vec A } = (\dot {\vec A})_{xyz} + \vec \Omega \times \vec A}_\#$$

如果使用相對的平面來表示公式

$$\implies \underline{
	\dot\Omega_2 = 
	\underbrace{ \dot\Omega_1 }_\text{前一個平面的角加速度} + 
	\underbrace{ 
		\underbrace{
			\dot\Omega_2
		}_\text{相對前一個平面} +
		\Omega_1 \times \Omega_2
	}_\text{這一個平面的角加速度}
}_\#$$

#### Example

> The disk shown in figure spins about its axle with a constant angular velocity $\omega_s = 3 \text{rad}/\text s$, while the horizontal platform on which the disk is mounted rotates about the vertical axis at a constant rate $\omega_p = 1 \text{rad}/\text s$. Determine the angular acceleration of the disk and the velocity and acceleration of point $A$ on the disk when it is in the position shown.
> ![[example of 3d rigid body motion.jpg]]

angular velocity measured from $XYZ$:

$$\omega = \omega_s + \omega_p = 3 \hat j - 1 \hat k \text{ rad/s}$$

the angular acceleration of the disk is 

$$\alpha = \dot \omega = \dot \omega_s + \dot \omega_p$$

therfore we calculate $\dot \omega_s$ and $\dot \omega_p$ using the equation of "time derivative of a vector"

$$\dot \omega_s = (\dot \omega_s)_{xyz} + \omega_p \times \omega_s = 0 + (-1\hat k) \times (3\hat j) = 3\hat i$$

$$\dot \omega_p = 0$$

now we can calculate angular acceleration

$$\alpha = \dot\omega_s + \dot \omega_p = \underline{3\hat i}_\#$$

velocity:

$$\vec v_A = \omega \times \vec r_A$$

$$ = (3\hat j - 1\hat k) \times (1 \hat j + 0.25 \hat k)$$

$$ = \underline{
	1.75 \hat i \text{ (m/s)}
}_\#$$

acceleration:

$$\vec a_A = \alpha \times \vec r_A + \omega \times (\omega \times \vec r_A)$$

$$ = (3\hat i) \times (1\hat j + 0.25 \hat k) + (3\hat j - 1 \hat k) \times [(3\hat j - 1 \hat k)\times (1\hat j + 0.25 \hat k)]$$

$$ = \underline{
	-2.50 \hat j - 2.25 \hat k \ \ (\text{m/s}^2)
}_\#$$

### Rigid Body General Motion

![[general motion.png]]

The general motion is defined by

$$\vec v_{ B / A } = \omega \times \vec r_{B / A}$$

$$\vec a_{ B / A } = \alpha \times \vec r_{B / A} + \omega \times (\omega \times \vec r_{B / A})$$

The absolute velocity and acceleration of point $B$ can be determined from

$$\underline{ \vec v_B = \vec v_A + \omega \times \vec r_{B / A} }_\#$$

$$\underline{\vec a_B = \vec a_A + \alpha \times \vec r_{B / A} + \omega \times (\omega \times \vec r_{B / A})}_\#$$

### Relative-Motion Analysis Using Translating and Rotating Axes

![[relative motion analysis using translating and rotating axes.png]]

#### Position

If the position of "$B$ with respect to $A$" is specified by the relative-position vector $\vec r_{B / A}$, then

$$\underline{
	\vec r_B = \vec r_A + \vec r_{B / A}
}_\#$$

#### Velocity

The velocity of point $B$ measured from $X, Y, Z$ is

$$\dot {\vec r}_B = \dot {\vec r}_A + \dot{\vec r}_{B / A}$$

$$\dot {\vec r}_{B / A} = (\dot{\vec r}_{B / A})_{xyz} + \Omega \times \vec r_{B / A}$$

$$ = (\vec v_{B / A})_{xyz} + \Omega \times \vec r_{B / A}$$

Here $(\vec v_{B / A})_{xyz}$ is the relative velocity of $B$ with respect to $A$ measured from $x, y, z$. Thus,

$$\underline{\underbrace{\vec v_B = \vec v_A + \Omega \times \vec r_{B / A}}_{\text{ for rigid body }} + \underbrace{(\vec v_{B / A})_{xyz}}_{\text{ not rigid body }}}_\#$$

> 點 $B$ 在 $xyz$ 平面上不會動，除非 relative motion

#### Acceleration

The acceleration of point $B$ measured from $X, Y, Z$ is

$$\dot{ \vec v }_B = \dot{\vec v}_A + \dot \Omega \times \vec r_{B / A} + \Omega \times \dot{\vec r}_{B / A} + \frac{d}{dt}(\vec v_{B / A})_{xyz}$$

where

$$\frac{d}{dt}(\vec v_{B / A})_{xyz} = (\dot{\vec v}_{B / A})_{xyz} + \Omega \times (\vec v_{B / A})_{xyz} $$
$$= (\vec a_{B / A})_{xyz} + \Omega \times (\vec v_{B / A})_{xyz}$$

$(\vec a_{B / A})_{xyz}$ is the relative acceleration of $B$ with respect to $A$ measured from $x, y, z$, thus

$$\underline{\vec a_B = 
\underbrace{
	\vec a_A + \dot \Omega \times \vec r_{B / A} + \Omega \times (\Omega \times \vec r_{B / A}) }_{ \text{for rigid body} } + 
\underbrace{
	2\Omega \times (\vec v_{B / A})_{xyz} + (\vec a_{B / A})_{xyz} }_\text{ for relative motion }
}_\#$$

> 點 $B$ 在 $xyz$ 平面上不會動，除非 relative motion

## Inertia

### Moment of Inertia

![[moment of inertia.png|300]]

$$
\underline{
	\left\{
		\begin{array}{}
			I_{xx} & = & \int_m r_x^2dm & = & \int_m(y^2 + z^2)dm \\ \\
			I_{yy} & = & \int_m r_y^2dm & = & \int_m(x^2 + z^2)dm \\ \\
			I_{zz} & = & \int_m r_z^2dm & = & \int_m(x^2 + y^2)dm
		\end{array}
	\right.
}_\#
$$

### Product of Inertia

The product of inertia $dI_{xy}$ for the element is

$$dI_{xy} = xydm$$

where $dI_{yx} = dI_{xy}$

$$
\underline{
	\left\{
		\begin{array}{}
			I_{xy} & = & I_{yx} & = & \int_m xydm \\ \\
			I_{yz} & = & I_{zy} & = & \int_m yzdm \\ \\
			I_{xz} & = & I_{zx} & = & \int_m xzdm
		\end{array}
	\right.
}_\#
$$

#### 性質

![[product of inertia 性質.png]]

(a) consider the $y-z$ plane of symmetry, 

$$I_{xy} = I_{xz} = 0$$

(b) consider the $x-z$ and $y-z$ being planes of symmetry

$$I_{xy} = I_{yz} = I_{xz} = 0$$

### Parallel Axis and Parallel Plane Theorems

$$
\underline{
	\left\{
		\begin{array}{}
			I_{xx} & = & (I_{x'x'})_G & + & m(y_G^2 + z_G^2) \\
			I_{yy} & = & (I_{y'y'})_G & + & m(x_G^2 + z_G^2) \\
			I_{zz} & = & (I_{z'z'})_G & + & m(x_G^2 + y_G^2) \\
		\end{array}
	\right.
}_\#
$$

$$
\underline{
	\left\{
		\begin{array}{}
			I_{xy} & = & (I_{x'y'})_G & + & mx_Gy_G \\
			I_{yz} & = & (I_{y'z'})_G & + & my_Gz_G \\
			I_{xz} & = & (I_{x'z'})_G & + & mx_Gz_G \\
		\end{array}
	\right.
}_\#
$$

### Inertia Tensor

The inertial properties of a body are completely characterized by nine terms and the set of terms can be written as

$$
\left(
	\begin{array}{}
		I_{xx} & -I_{xy} & -I_{xz} \\
		-I_{yx} & I_{yy} & -I_{yz} \\
		-I_{zx} & -I_{zy} & I_{zz}
	\end{array}
\right)
$$

### Moment of Inertia About an Arbitrary Axis

![[moment of inertia about an arbitrary axis.png|300]]

$$I_{Oa} = \int b^2dm$$

$$ = \int_m \left\vert
	\hat u_a \times \vec r
\right\vert^2 dm$$

$$ = \int_m (\hat u_a \times \vec r) \cdot (\hat u_a \times \vec r)dm$$

Provided

$$\left\{
	\begin{array}{}
		\hat u_a & = & u_x \hat i & + & u_y \hat j & + & u_z \hat k \\
		\vec r & = & x\hat i & + & y\hat j & + & z\hat k
	\end{array}
\right.$$

Then 

$$\hat u_a \times \vec r = (u_yz - u_zy) \hat i + (u_zx - u_xz) \hat j + (u_xy - u_yx) \hat k$$

The moment of inertia is

$$I_{Oa} = \int_m\left[
	(u_yz - u_zy)^2 + (u_zx - u_xz)^2 + (u_xy - u_yx)^2
\right]dm$$

.

$$ = u_x^2\int_m(y^2 + z^2)dm + u_y^2 \int_m(z^2 + x^2)dm + u_z^2\int_m(x^2 + y^2)dm$$

$$ - 2u_xu_y\int_m xydm - 2u_yu_z\int_m yzdm - 2u_zu_x\int_mzxdm$$

.

$$\implies \underline{
	I_{Oa} = I_{xx}u_x^2 + I_{yy}u_y^2 + I_{zz}u_z^2 - 2I_{xy}u_xu_y - 2I_{yz}u_yu_z - 2I_{zx}u_zu_x
}_\#$$

## Angular Momentum

![[angular momentum 3D.png|350]]

If the particle's mass is $m_i$, the angular momentum about point $A$ is 

$$(\vec H_A)_i = \vec \rho_A \times m_i \vec v_i$$

If the body has an angular velocity $\omega$

$$\vec v_i = \vec v_A + \omega \times \vec \rho_A$$

Thus,

$$\implies (\vec H_A)_i = \vec \rho_A \times m_i(\vec v_A + \omega \times \vec \rho_A)$$

$$ = (\vec \rho_A m_i) \times \vec v_A + \vec \rho_A \times (\omega \times \vec\rho_A)m_i$$

Summing all the particles of the body, 

$$\vec H_A = \left(\int\vec\rho_Adm\right) \times \vec v_A + \int_m \vec \rho_A \times (\omega \times \vec \rho_A)dm$$

### About Fixed Point $O$

![[angular momentum about fixed point O.png|350]]

$$\underline{
	\vec H_O = \int_m \vec\rho_O \times(\omega \times \vec\rho_O)dm
}_\#$$

### About Center of Mass $G$

![[angular momentum about center of mass G.png|350]]

$$
\underline{
	\vec H_G = \int_m \vec\rho_G \times (\omega \times \vec \rho_G)dm
}_\#
$$

### About Arbitrary Point $A$

![[angular momentum about arbitrary point A.png|350]]

$$\underline{
	\vec H_A = \vec \rho_{G / A} \times m \vec v_G + \vec H_G
}_\#$$

這個是最重要的，因為通常 point $G$ 的 angular momentum 最好求 (通常會對稱，可以省去計算 [[#Product of Inertia]])

之後只要計算出質心速度就可以求出任意一點的角動量

### Rectangular Components of Angular Momentum

Choosing a second set of $x, y, z$ axes having an arbitrary orientation relative to the $X, Y, Z$ axes,

$$\vec H = \int_m \vec \rho \times (\omega \times \vec \rho)dm$$

.

$$\implies H_x \hat i + H_y \hat j + H_z \hat k = $$

$$\int_m(x \hat i + y\hat j + z\hat k)\times \left[
	(\omega_x \hat i + \omega y \hat j + \omega z \hat k) \times (x \hat i + y \hat j + z \hat k)
\right]dm$$

.

$$\implies H_x \hat i + H_y \hat j + H_z \hat k = $$

$$\left[
	\omega_x \int_m(y^2 + z^2)dm - \omega_y\int_mxydm - \omega_z \int_mxzdm
\right]\hat i +$$

$$\left[
	-\omega_x \int_mxydm + \omega_y \int_m(x^2 + z^2)dm - \omega_z\int_myzdm
\right] \hat j +$$

$$\left[
	-\omega_x \int_mzxdm - \omega_y \int_m yzdm + \omega_z \int_m (x^2 + y^2)dm
\right]\hat k$$

.

$$\implies
\underline{
	\left\{
		\begin{array}{}
			H_x & = & I_{xx}\omega_x & - & I_{xy}\omega_y & - & I_{xz} \omega_z \\
			H_y & = & -I_{yx} \omega_x & + & I_{yy} \omega_y & - & I_{yz}\omega_z \\
			H_z & = & -I_{zx} \omega_x & - & I_{zy} \omega_y & + & I_{zz}\omega_z 
		\end{array}
	\right.
}_\#
$$

$$\implies 
\underline{
	\left[
		\begin{array}{}
			H_x \\
			H_y \\
			H_z
		\end{array}
	\right] = 
	\underbrace{
		\left[
			\begin{array}{}
				I_{xx} & -I_{xy} & -I_{xz} \\
				-I_{yx} & I_{yy} & -I_{yz} \\
				-I_{zx} & -I_{zy} & I_{zz}
			\end{array}
		\right]
	}_{\text{ Inertia Tensor }}
	\left[
		\begin{array}{}
			\omega_x \\
			\omega_y \\
			\omega_z
		\end{array}
	\right]
}_\#
$$

如果 product of inertia 是 0

$$
\implies 
\underline{
	\left\{
		\begin{array}{}
			H_x & = & I_{xx}\omega_x \\
			H_y & = & I_{yy}\omega_y \\
			H_z & = & I_{zz}\omega_z
		\end{array}
	\right.
}_\#
$$

### Principle of Impulse and Momentum

$$\underline{
	m(\vec v_G)_1 + \sum \int_{t_1}^{t_2}\vec Fdt = m(\vec v_G)_2
}_\#$$

$$\underline{
	(\vec H_O)_1 + \sum \int_{t_1}^{t_2} \vec M_O dt = (\vec H_O)_2
}_\#$$

## Kinetic Energy

![[kinetic energy of rigid body.jpg|350]]

The kinetic energy of $i$th particle:

$$T_i = \frac 1 2 m_i v_i^2 = \frac 1 2 m_i (\vec v_i \cdot \vec v_i)$$

provided the velocity of arbitrary point $A$ is known, we have

$$\vec v_i = \vec v_A + \omega \times \vec \rho_A$$

the kinetic energy of the particle can be written as

$$T_i = \frac 1 2 m_i (\vec v_A + \omega \times \vec \rho_A)\cdot (\vec v_A + \omega \times \vec \rho_A)$$

$$ = \frac 1 2 (\vec v_A \cdot \vec v_A)m_i + \vec v_A \cdot (\omega \times \vec \rho_A)m_i + \frac 1 2 (\omega \times \vec \rho_A)\cdot (\omega \times \vec \rho_A)m_i$$

summing the kinetic energies of the body

$$T = \frac 1 2 m (\vec v_A \cdot \vec v_A) + \vec v_A \cdot (\omega \times \int_m \rho_A dm) + \frac 1 2 \int_m (\omega \times \rho_A)\cdot (\omega \times \rho_A)dm$$

the last term on the right can be re-written as

$$T = \frac 1 2 m(\vec v_A \cdot \vec v_A) + \vec v_A \cdot (\omega \times \int_m \rho_Adm) + \frac 1 2 \omega \cdot \int_m \rho_A \times (\omega \times \rho_A)dm$$

### Fixed Point $O$

$$T = \frac 1 2 \omega \cdot H_O$$

$$\implies \underline{
	T = \frac 1 2 I_x \omega_x^2 + \frac 1 2 I_y \omega_y^2 + \frac 1 2 I_z \omega_z^2
}_\#$$

### Center of Mass $G$

$$T = \frac 1 2 mv_G^2 + \frac 1 2 \omega \cdot \vec H_G$$

$$\implies \underline{
	T = \frac 1 2 mv_G^2 + \frac 1 2 I_x \omega_x^2 + \frac 1 2 I_y \omega_y^2 + \frac 1 2 I_z \omega_z^2
}_\#$$

### Principle of Work and Energy

$$\underline{T_1 + \sum U_{1-2} = T_2}_\#$$

## Equations of Motion

### Translation Motion

$$\sum \vec F = m\vec a_G$$

$$\implies 
\underline{
	\left\{
		\begin{array}{}
			\sum F_x = m(a_G)_x \\
			\sum F_y = m(a_G)_y \\
			\sum F_z = m(a_G)_z
		\end{array}
	\right.
}_\#$$

### Rotational Motion

![[3d rigid body equation of motion rotational motion.jpg|350]]

$$\sum \vec M_O = \dot{\vec H}_O$$

在 $G$ 點也成立

$$\sum \vec M_G = \dot{\vec H}_G$$

If the components are computed about $x, y, z$ axes that are rotating with an angular velocity $\Omega$, which is different from the body's angular velocity $\omega$, then the time derivative must account for the rotation of the $x, y, z$ axes as measured from inertial $X, Y, Z$ axes.

$$\implies \left\{
	\begin{array}{}
		\sum \vec M_O = (\dot{\vec H}_O)_{xyz} + \Omega \times \vec H_O \\
		\sum \vec M_G = (\dot{\vec H}_G)_{xyz} + \Omega \times \vec H_G
	\end{array}
\right.$$

If the $x, y, z$ axes are chosen as principal axes of inertia, the products of inertia is zero.

for $\Omega = \omega$, the $x, y, z$ axes is chosen with origin at $G$ and they are fixed in and move with the body.

$$\implies
\underline{
	\left\{
		\begin{array}{}
			\sum M_x = I_x \dot \omega_x - (I_y - I_z)\omega_y\omega_z \\
			\sum M_y = I_y \dot \omega_y - (I_z - I_x)\omega_z\omega_x \\
			\sum M_z = I_z \dot \omega_z - (I_x - I_y)\omega_x\omega_y 
		\end{array}
	\right.
}_\#$$

for $\Omega \neq \omega$, we choose $x, y, z$ axes having an angular velocity $\Omega$ which is different from the angular velocity $\omega$ of the body.

$$
\implies
\underline{
	\left\{
		\begin{array}{}
			\sum M_x = I_x \dot\omega_x - I_y \Omega_z \omega_y + I_z \Omega_y \omega_z \\
			\sum M_y = I_y \dot\omega_y - I_z\Omega_x \omega_z + I_x\Omega_z \omega_x \\
			\sum M_z = I_z \dot \omega_z - I_x \Omega_y \omega_x + I_y \Omega_x \omega_y
		\end{array}
	\right.
}_\#$$

## Gyroscopic Motion

![[gyroscopic motion.jpg|300]]

Starting with the $X, Y, Z$ and the $x, y, z$ axes in coincidence, the final position of the top can be determined using following three steps.

1. Precession $\dot\phi$: Rotate about $Z$ axis through an angle $\phi$
![[gyroscopic motion precession.png|300]]
2. Nutation $\dot\theta$: Rotate about the $x$ axis through an angle $\theta$
![[gyroscopic motion nutation.jpg|300]]
3. Spin $\dot\psi$: Rotate about the $z$ axis through an angle $\psi$
![[gyroscopic motion spin.jpg|300]]

Precession, nutation and spin on one graph:

![[gyroscopic motion precession, nutation and spin.png|350]]

The angular velocity of the body is:

$$\omega = \dot \theta \hat i + (\dot \phi \sin \theta) \hat j + (\dot \phi \cos \theta + \dot \psi)\hat k$$

The angular velocity of the axes is:

$$\Omega = \dot \theta \hat i + (\dot \phi\sin \theta)\hat j + (\dot \phi \cos \theta)\hat k$$

Since $\Omega \neq \omega$, using equations of motion

$$
\left\{
	\begin{array}{}
		\sum M_x & = & I(\ddot\theta - \dot\phi^2\sin\theta\cos\theta) + I_z \dot\phi\sin\theta(\dot\phi\cos\theta + \dot \psi) \\
		\sum M_y & = & I(\ddot \phi\sin\theta + 2\dot\phi\dot\theta\cos\theta) - I_z\dot\theta(\dot\phi\cos\theta + \dot\psi) \\
		\sum M_z & = & I_z(\ddot\psi + \ddot\phi\cos\theta - \dot\phi\dot\theta\sin\theta)
	\end{array}
\right.
$$

"Steady precession" occurs when the nutation angle, precession and spin all remains constant

$$\dot\theta = \ddot\theta = 0, \quad \ddot \psi = 0, \quad \ddot\phi = 0$$

$$\underline{
	\sum M_x = -I\dot\phi^2\sin\theta\cos\theta + I_z\dot\phi\sin\theta(\dot\phi\cos\theta + \dot\psi)
}_\#$$

$$\sum M_y = 0$$

$$\sum M_z = 0$$

Further simplification,

$$\sum M_x = -I\dot\phi^2\sin\theta\cos\theta + I_z \dot\phi(\sin\theta)\omega_z$$

$$\implies \underline{
	\sum M_x = \dot\phi\sin\theta(I_z\omega_z - I\dot\phi\cos\theta)
}_\#$$

Consider the spinning rotor, when $\theta = 90\degree$

![[gyroscopic motion spinning rotor.png]]

$$\sum M_x = I_z\dot\phi \dot\psi$$

$$\implies \underline{\sum M_x = I_z\Omega_y\omega_z}_\#$$

For gyro rotor, of which $\omega_z \gg \Omega_y$

$$\underline{\sum M_x = \Omega_y \times H_O}_\#$$

---

參考資料:

動力學上課

---

link: