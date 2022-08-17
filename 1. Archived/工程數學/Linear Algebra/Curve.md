標籤: #工程數學 

---

# Definition

線分成三種

1. Simple Curve: that doesn't intersect itself
2. Not Sumple Curve: that intersects itself
3. "Arc": a finite curve

# Tangent Line

求切線可以用

$$\vec{ q }(w) = \vec{ r }(t) + w\vec{ r }'(t)$$

# Length Along Curve

又稱為 Arc length

要求出曲線總長度，我們可以使用 piecewise linear 的方法，也就是將曲線分成小塊並相加

$$\vec{ r }(t) = \left[
	\begin{array}{}
		f(t) \\
		g(t) \\
		h(t)
	\end{array}
\right] ; \qquad
\begin{array}{}
	x = f(t) \\
	y = g(t) \\
	z = h(t)
\end{array}$$

Length between $a$ and $b$:

$$L = \sqrt{ \left( \frac{ \Delta x }{ \Delta t } \Delta t \right)^2 + \left( \frac{ \Delta y }{ \Delta t } \Delta t \right)^2 + \left( \frac{ \Delta z }{ \Delta t } \Delta t \right)^2 }$$

$$ = \int_a^b\sqrt{ [f'(t)]^2 + [g'(t)]^2 + [h'(t)]^2 }dt$$

$$ = \int_a^b\vert\vert \vec{ r }'(t)\vert\vert dt = \int_a^b\sqrt{ \vec{ r }'\cdot \vec{ r }' }dt$$

$$\underbrace{ s(t) }_{ \text{ arc length } } = \int_a^t\vert\vert \vec{ r }'(t) \vert\vert d\tilde{ t } = \int_a^t\sqrt{ \vec{ r }'\cdot \vec{ r }' }d\tilde{ t }$$

> $r(t)$, $r(s)$ differential
> $$\left\{ \begin{array}{} \vec{ r }(t) & \implies & \frac{ d\vec{ r } }{ dt } & = & \text{ velocity [m/s] } & , & \frac{ d\vec{r} / dt }{ \vert\vert d\vec{ r } / dt \vert\vert } & = & \hat{ u } \\ \vec{ r }(s) & \implies & \frac{ d\vec{ r } }{ ds } & = & \hat{u} \; \text{ (unit length) } \end{array} \right.$$

## Calculate $ds$

since: $s(t) = \int_a^t\sqrt{ \vec{ r }'\cdot \vec{ r }' }d\tilde{ t }$

$$\frac{ ds }{ dt } = \sqrt{ \vec{ r }'\cdot\vec{ r }' }$$

$$\left(\frac{ ds }{ dt }\right)^2 = \frac{ d\vec{ r } }{ dt }\cdot\frac{ d\vec{ r } }{ dt }$$

$$ = \vert\vert\vec{ r }'(t)\vert\vert^2$$

$$ = \left(\frac{ dx }{ dt }\right)^2 + \left( \frac{ dy }{ dt } \right)^2 + \left( \frac{ dz }{ dt } \right)^2$$

$$\therefore ds^2 = dx^2 + dy^2 + dz^2$$

## Conversion: $\vec{ r }(t) \leftrightarrow \vec{ r }(s)$

### $t \rightarrow s$

$$\vec{ r }(t) = 
\left[
	\begin{array}{}
		a\cos t \\
		a\sin t \\
		ct
	\end{array}
\right]$$

$$\vec{ r }'(t) = 
\left[
	\begin{array}{}
		-a\sin t \\
		a\cos t \\
		c
	\end{array}
\right]$$

$$\vec{ r }'\cdot \vec{ r }' = a^2\sin^2 t + a^2 \cos^2 t + c^2 = a^2 + c^2 \equiv K^2$$

($K$ is a constant equals to $\sqrt{ a^2 + c^2 }$)

$$s(t) = \int_a^t\sqrt{ \vec{ r }'\cdot \vec{ r }' }d\tilde{ t } = \int_a^tKd\tilde t = Kt$$

$t = \frac{ s }{ K }$ substitude $\vec{ r }t$

$$\vec{ r }(s) = 
\left[
	\begin{array}{}
		a\cos\frac{ s }{ K } \\
		a\sin\frac{ s }{ K } \\
		c\frac{ s }{ K }
	\end{array}
\right] \quad \text{ where } K = \sqrt{ a^2 + c^2 }$$

## Engineering Application

1. Position:

$$\vec{ r }(t), \vec{ r }(s)$$

2. Velocity:
$$\vec{ v }(t)\equiv \vec{ r }'(t) \neq \vec{ r }'(s)$$Speed:
$$\vert\vert\vec{ v }(t)\vert\vert = \sqrt{ \vec r' \cdot \vec r' }$$

3. [[Acceleration]]:
$$\vec{ a } = \vec a_t + \vec a_n$$

$$\vec a (t) = \frac{ d\vec v }{ dt } = \frac d { dt } \left( \frac{ d\vec r (t) }{ dt } \right)$$

$$ = \frac d {dt} (\frac {d\vec r}{ ds }\cdot \frac{ds}{ dt })$$

$$ = \frac d{dt}(\underbrace{\hat u (s)}_{ \text{ unit tangent } } \cdot \frac{ds}{dt})$$

$$ = \frac{ d \hat u (s) }{ dt }\cdot \frac{ ds }{ dt } + \hat u (s) \cdot \frac{ d^2s }{ dt^2 }$$

$$ = \underbrace{ \frac{ d\hat u(s) }{ ds } \cdot \left(\frac{ ds }{ dt }\right)^2 }_{ \vec a_n } + \underbrace{ \hat u(s) \cdot \frac{ d^2s }{ dt^2 } }_{ \vec a_t }$$

4. Curvature

$$\kappa(s) = \vert\vec u'(s)\vert$$

$$ = \vert \vec r '' (s)\vert$$

---

參考資料:

工程數學上課

---

link:

