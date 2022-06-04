標籤: #工程數學 

---

# Engineering Mathematics Project 1

> Group: iTron
> Members: 
> 趙珈毅 109611010
> 陳柏文 109611030
> 張瀚元 109611004
> 吳典謀 109611066

## Section 1

> $$\text{Bernoulli: }\; y' + P(x)y = r(x)y^\alpha$$
> $$\text{Logistics equation: }\; y' = Ay - By^2$$

---

$$\text{1. }\; \frac{dy}{dt} = Ay - By^2$$
$$\implies \frac{1}{Ay - By^2}dy = dt$$
$$\implies \frac{1}{Ay(1 - \frac{B}{A}y)}dy = dt$$
$$\implies \frac{1}{A}\left[ \int\frac{1}{y}dy + \int \frac{\frac{B}{A}}{(1 - \frac{B}{A}y)}dy \right] = \int dt$$
$$\implies \frac{1}{A}\left[ \ln y - \ln(1 - \frac{B}{A}y) \right] = t + c_1$$
$$\implies\ln\frac{y}{1 - \frac{B}{A}y} = At + c_2$$
$$\implies\frac{y}{1 - \frac{B}{A}y} = c_3e^{At}$$
$$\implies y(1 + \frac{B}{A}ce^{At}) = c_3e^{At}$$
$$\implies y = \frac{c_3e^{At}}{1 + \frac{B}{A}c_3e^{At} } = \underline{\frac{1}{ce^{-At} + \frac{B}{A}}}_{\#}$$

---

$$\text{2. }\; B = 0$$
$$\implies y' = Ay$$
$$\implies \frac{dy}{dt} = Ay$$
$$\implies \frac{dy}{y} = Adt$$
$$\implies \ln y = At + c_1$$
$$\implies y = e^{At + c_1} = \underline{ce^{At}}_{\#}$$
$$\implies \text{They are the same.}$$

---

$$\text{3.}\; y(t) = \frac{1}{ce^{-At} + \frac{B}{A}}$$
$$\text{when }\; B = 0$$
$$\implies y(t) = \frac{1}{ce^{-At}} = ce^{At}$$
$$\implies \text{They are the same}$$

---

$$\text{4. }\; y = Ay - By^2$$
$$y(t) = \frac{1}{ce^{-At} + \frac{B}{A}}$$
$$\lim_{t\rightarrow\infty}y(t) = \frac{A}{B}$$
$$\text{so when }\; t \rightarrow \infty , \; y(t) \;\text{ will converge to }\frac{A}{B}$$
$$y(t) \text{ will brake to } \frac{A}{B}, \; \text{so }-By^2 \text{ is called braking term}$$



---

$$\text{5. }\; y(t_0) = y_0 = \frac{1}{ce^{-At_0}+\frac{B}{A}}$$
$$\implies \frac{1}{y_0} = ce^{-At_0} + \frac{B}{A}$$
$$\implies \frac{1}{y_0} - \frac{B}{A} = ce^{-At_0}$$
$$\implies (\frac{1}{y_0} - \frac{B}{A})e^{At_0} = \underline{c}_{\#}$$

---

$$\text{6. }$$
> ![[y=1000e^{0.5x}.png|500]]
> $$y = 1000e^{0.5t}$$

---

$$\text{7. }$$
![[compare chart 1.7.png|500]]

---

$$\text{8. }\lim_{t \rightarrow \infty}ce^{-At}=0$$
$$\lim_{t \rightarrow\infty}y(t) = \lim_{t \rightarrow \infty}\frac{1}{0 + \frac{1}{4}} = \underline{4}_{\#}$$
$$\text{when }\; t \; \text{ approach }\infty \text{ , }\;y\;\text{ converge to }\frac{A}{B}$$
![[1.8 compare.png|500]]

---

$$\text{9.\ \ \ (3).}$$
![[positive.png|500]]

---

$$\text{9.\ \ \ (4).}$$
![[model compare.png|500]]
$$\text{Verhulst Model is more appropriate.}$$
$$\text{Because the model converges when the cases reach 30 millions.}$$

---

$$\text{9.\ \ \ (5).}$$
$$y(t) = \frac{1}{ce^{-At} + \frac{B}{A}} \quad \text{---(1)}$$
$$y(t_f) \approx \frac{A}{B} = 2.9 \times 10^7$$
$$\implies y(0) = \frac{1}{c + \frac{B}{A}} = 1$$
$$\implies c = 1 - 2.9 \times 10^{-7} \doteqdot 1$$
$$c = 1 \;\text{substitude into (1)}$$
$$\implies y(t) = \frac{1}{e^{-At} + \frac{B}{A}}$$
$$t = 347 \implies y(347) = 2 \times 10^7 = \frac{1}{e^{-A \times 347} + \frac{1}{2.9 \times 10^{-7}}}$$
$$\implies A = \underline{0.0518}_{\#}$$
$$\implies B = \underline{1.79 \times 10^{-9}}_{\#}$$

---

$$9. \ \ \  (6)$$
$$\text{The curve we simulated rise relatively slow at first,}$$
$$\text{but our latter part is very similar to real cases.}$$

---

$$9. \ \ \ (7)$$
$$\text{Because new types of virus appears, the cases are rising again.}$$

---

## Section 2

$$1.$$
$$-ky = my'$$

---

$$2.\; F_{\text{damper}} = cy'$$
$$my'' = -ky-cy'$$
$$\implies y'' + \frac{c}{m}y' + \frac{k}{m}y = 0$$

---

$$3. \ \ \ (\text{i})$$
$$my'' + ky = 0$$
$$\implies y'' + \frac{k}{m}y = 0$$
$$\text{find}\;
\left\{
\begin{array}{}
y_1 = e^{i\sqrt{\frac{k}{m}}x} \\
y_1' = i\sqrt{\frac{k}{m}}e^{i\sqrt{\frac{k}{m}}x} \\
y_1'' = -\frac{k}{m}e^{i\sqrt{\frac{k}{m}}x}
\end{array}
\right.$$
$$\text{Let}
\left\{
	\begin{array}{}
		y_2 = uy_1 \\
		y_2' = u'y_1 + uy_1' \\
		y_2'' = u''y_1 + 2u'y_1' + uy_1''
	\end{array}
\right.$$
$$\text{substitude into ODE}$$
$$m(u''y_1 + 2u'y_1' + uy_1'') + kuy_1 = 0$$
$$u''(my_1) + u'(2my_1') + u\underbrace{(my_1'' + ky_1)}_{ = 0} = 0$$
$$\implies u''(my_1) + u'(2my_1') = 0$$
$$\text{Let}
\left\{
	\begin{array}{}
		u' = U \\
		u'' = U'
	\end{array}
\right.$$
$$\implies U'\bcancel{m}y_1 + 2U\bcancel{m}y_1' = 0$$
$$\implies U' + (\frac{2y_1'}{y_1})U = 0$$
$$\implies \frac{dU}{U} = -(\frac{2y_1'}{y_1})dx$$
$$\implies \ln U = -2\ln\vert y_1\vert$$
$$\implies U = \frac{1}{y_1^2}$$
$$u = \int Udx$$
$$y_2 = y_1u = y_1\int Udx = y_1\int \frac{1}{y_1^2}dx$$
$$ = e^{-i\sqrt{\frac{k}{m}}x}$$
$$y_1 = e^{i\sqrt{\frac{k}{m}}x} = \cos\sqrt{\frac{k}{m}}x + i\sin\sqrt{\frac{k}{m}}x$$
$$y_2 = e^{-i\sqrt{\frac{k}{m}}x} = \cos\sqrt{\frac{k}{m}}x - i\sin\sqrt{\frac{k}{m}}x$$
$$\text{Let}\; y_3 = \frac{1}{2}(y_1 + y_2)$$
$$ = \frac{1}{2}(\cos\sqrt{\frac{k}{m}}x + i\sin\sqrt{\frac{k}{m}}x + \cos\sqrt{\frac{k}{m}}x - i\sin\sqrt{\frac{k}{m}}x)$$
$$ = \cos\sqrt{\frac{k}{m}}x$$
$$y_4 = \frac{1}{2i}(y_1 - y_2)$$
$$ = \frac{1}{2i}(\cos\sqrt{\frac{k}{m}}x + i\sin\sqrt{\frac{k}{m}}x - \cos\sqrt{\frac{k}{m}}x + i\sin\sqrt{\frac{k}{m}}x)$$
$$\text{general solution}$$
$$y(x) = Ay_3 + By_4 = A\cos\sqrt{\frac{k}{m}}x + B\sin\sqrt{\frac{k}{m}}x \quad (\sqrt{\frac{k}{m}}) = \omega_0$$

---

$$3. \ \ \ (\text{iii})$$
$$y(t) = A\cos(\omega t) + B\sin(\omega t)$$
$$\underline{y(0) = A\cos 0 + B\sin0 = A}_{\#}$$
$$y'(0) = -A\omega\sin(0) + B\omega\cos(0)$$
$$= B\omega = \underline{B\sqrt{\frac{k}{m}}}_{\#}$$

---

$$3. \ \ \ (\text{iv})$$
$$m = 1\text{kg}, \quad k = 10\,\frac{N}{m}$$
$$\omega = \sqrt{\frac{k}{m}} = \sqrt{10}$$
$$\underline{y(0) = A}_{\#}\qquad 
\begin{array}{}
y'(0) & = & B\omega = 0 \\
& \implies & B = 0
\end{array}$$
$$\implies y(t) = A\cos(\sqrt{10}t)$$
$$\implies 
\left\{
	\begin{array}{}
		1: & y(t) = 0.5\cos(\sqrt{10}t) \\
		2: & y(t) = 1\cdot \cos(\sqrt{10}t) \\
		3: & y(t) = 2\cdot \cos(\sqrt{10}t) \\
		4: & y(t) = 4\cdot \cos(\sqrt{10}t)
	\end{array}
\right.$$
.

> ![[y=0.5cos(sqrt{10}t).png|500]]
> $$y(t) = 0.5\cdot \cos(\sqrt{10}t)$$

.

> ![[y=1cos(sqrt{10}t).png|500]]
> $$y(t) = 1\cdot \cos(\sqrt{10}t)$$

.

> ![[y=2cos(sqrt{10}t).png|500]]
> $$y(t) = 2\cdot \cos(\sqrt{10}t)$$

.

> ![[y=4cos(sqrt{10}t).png|500]]
> $$y(t) = 4\cdot \cos(\sqrt{10}t)$$

$$\text{The period of oscillation on plot matches}\; \omega_0 = \sqrt{\frac{k}{m}}$$

---

$$3. \ \ \ (\text{v})$$
$$y(0) = 0.5 = A, \quad \omega = \sqrt{\frac{k}{m}} = \sqrt{10}$$
$$y'(0) = B\omega 
\left\{
	\begin{array}{}
		 = -0.5 \implies B = -\frac{0.5}{\sqrt{10}} \\
		 = 0.5 \implies B = \frac{0.5}{\sqrt{10}} \\
		 = 1 \implies B = \frac{1}{\sqrt{10}} \\
		 = 2 \implies B = \frac{2}{\sqrt{10}}
	\end{array}
\right.$$
$$\implies
\left.
	\begin{array}{}
		y(t) = 0.5\cos\omega t - \frac{0.5}{\sqrt{10}}\sin\omega t \\
		y(t) = 0.5\cos\omega t + \frac{0.5}{\sqrt{10}}\sin\omega t \\
		y(t) = 0.5\cos\omega t + \frac{1}{\sqrt{10}}\sin\omega t \\
		y(t) = 0.5\cos\omega t + \frac{2}{\sqrt{10}}\sin\omega t \\
	\end{array}
\right\}0\leq t\leq 10$$
$$\text{Does oscillation frequency change? \quad no}$$

> ![[y=0.5cos omega t-frac{0.5}{sqrt{10}}sin omega t.png|500]]
> $$y(t) = 0.5\cos\omega t - \frac{0.5}{\sqrt{10}}\sin\omega t$$

> ![[y=0.5cos omega t+frac{0.5}{sqrt{10}}sin omega t.png|500]]
> $$y(t) = 0.5\cos\omega t + \frac{0.5}{\sqrt{10}}\sin\omega t$$

> ![[y=0.5cos omega t+frac{1}{sqrt{10}}sin omega.png|500]]
> $$y(t) = 0.5\cos\omega t + \frac{1}{\sqrt{10}}\sin\omega$$

> ![[y=0.5cos omega t+frac{2}{sqrt{10}}sin omega t.png|500]]
> $$y(t) = 0.5\cos\omega t + \frac{2}{\sqrt{10}}\sin\omega t$$

---

$$3. \ \ \ (\text{vi})$$
$$y(0) = 0.5, \quad y'(0) = 0\implies y(t) = 0.5\cos\omega t$$
$$k = 10\frac{N}{M}$$
$$\left\{
\begin{array}{l}
	m = 1 \implies \omega = \sqrt{10} \\
	m = 2 \implies \omega = \sqrt{5} \\
	m = 4 \implies \omega = \sqrt{\frac{5}{2}} \\
	m = 8 \implies \omega = \sqrt{\frac{5}{4}} = \frac{\sqrt{5}}{2}
\end{array}
\right.$$
$$\left\{
	\begin{array}{}
		y(t) = 0.5\cos\sqrt{10}t \\
		y(t) = 0.5\cos\sqrt{5}t \\
		y(t) = 0.5\cos\sqrt{\frac{5}{2}}t \\
		y(t) = 0.5\cos\frac{\sqrt{5}}{2}t
	\end{array}
\right.
\quad,\; 0\leq t\leq 10$$
$$\text{Does the graph's frequencies match}\; \omega_0 = \sqrt{\frac{k}{m}}$$

> ![[y=0.5cos sqrt{10}t.png|500]]
> $$y(t) = 0.5\cos\sqrt{10}t$$

> ![[y=0.5cos sqrt{5}t.png|500]]
> $$y(t) = 0.5\cos\sqrt{5}t$$

> ![[y=0.5cos sqrt{frac{5}{2}}t.png|500]]
> $$y(t) = 0.5\cos\sqrt{\frac{5}{2}}t$$

> ![[y=0.5cos frac{sqrt{5}}{2}t.png|500]]
> $$y(t) = 0.5\cos\frac{\sqrt{5}}{2}t$$

---

$$3. \ \ \ (\text{vii})$$
$$y(t) = 0.5\cos \omega t$$
$$m = 1$$
$$k = 
\begin{array}{}
	10 \\
	20 \\
	40 \\
	80
\end{array}
\implies
\begin{array}{}
	\omega = \sqrt{10} \\
	\omega = \sqrt{20} \\
	\omega = \sqrt{40} \\
	\omega = \sqrt{80}
\end{array}
\implies
\left\{
	\begin{array}{}
		y(t) = 0.5\cos\sqrt{10}t \\
		y(t) = 0.5\cos\sqrt{20}t \\
		y(t) = 0.5\cos\sqrt{40}t \\
		y(t) = 0.5\cos\sqrt{80}t
	\end{array}
\right.$$

> ![[y=0.5cos sqrt{10}t.png|500]]
> $$y(t) = 0.5\cos\sqrt{10}t$$

> ![[y=0.5cos sqrt{20}t.png|500]]
> $$y(t) = 0.5\cos\sqrt{20}t$$

> ![[y=0.5cos sqrt{40}t.png|500]]
> $$y(t) = 0.5\cos\sqrt{40}t$$

> ![[y=0.5cos sqrt{80}t.png|500]]
> $$y(t) = 0.5\cos\sqrt{80}t$$

$$\text{The frequence match}\; \omega_0 = \sqrt{\frac{k}{m}}$$

---

$$4.\ \ \ (1)$$
$$2^{\text{nd}},\; \text{linear, homogeneous ODE:}\; y'' + \frac{c}{m}y' + \frac{k}{m}y = 0$$
$$\implies \lambda^2 + \frac{c}{m}\lambda + \frac{k}{m} = 0$$
$$\lambda = \frac{-\frac{c}{m}\pm\sqrt{\frac{c^2}{m^2} - \frac{4k}{m}}}{2}$$
$$ = \frac{-c\pm\sqrt{c^2 - 4mk}}{2m}$$
$$\implies
\left\{
	\begin{array}{l}
		c^2 > 4mk \implies \lambda = \frac{-c\pm \sqrt{c^2 - 4mk}}{2m} \\
		c^2 < 4mk \implies \lambda = -\frac{c}{2m} \pm \sqrt{4mk - c^2}i \\
		c^2 = 4mk \implies \lambda_1 = \lambda_2 = \frac{-c}{2m}
	\end{array}
\right.$$

---

$$4.\ \ \ (2)$$
$$\implies
\begin{array}{l}
	c^2 > 4mk & \implies & y(t) = c_1e^{(\frac{-c + \sqrt{c^2 - 4mk}}{2m}t)} + c_2e^{(\frac{-c - \sqrt{c^2 - 4mk}}{2m})t} \\
	c^2 < 4mk & \implies & y(t) = e^{\frac{-c}{2m}t}[c_1\cos(\sqrt{4mk - c^2}t) + c_2\sin(\sqrt{4mk - c^2}t)] \\
	c^2 = 4mk & \implies & y(t) = (c_0 + c_1t)e^{\frac{-c}{2m}t}
\end{array}$$

---

$$4.\ \ \ (3)$$
$$m = 1\text{kg}, \; k = 10\; N/m$$
$$\text{repeat roots}\implies c^2 = 4mk \implies c^2 = 400 \implies \underline{c = 20}_{\#}$$

---

$$4.\ \ \ (4)$$
$$y(0) = 0.5\text{m},\; y'(0) = 0\;\text{m/s},\; c = c_{\text{critical}},\; \text{plot} \; y(t) \; \text{for} \; 0\leq t\leq 20 \;\text{s}$$
$$\implies y(t) = (c_0 + c_1t)e^{\frac{-c}{2m}t},\quad c = \sqrt{4mk} \quad\text{substitude}$$
$$\implies
\left\{
	\begin{array}{l}
		y(t) = (c_0 + c_1t)e^{-\sqrt{\frac{k}{m}}t} \\
		y'(t) = -\sqrt{\frac{k}{m}}c_0e^{-\sqrt{\frac{k}{m}}t} - c_1\sqrt{\frac{k}{m}}te^{-\sqrt{\frac{k}{m}}t} + c_1e^{-\sqrt{\frac{k}{m}}t}
	\end{array}
\right.$$
$$\implies 
\left\{
	\begin{array}{}
		y(0) = c_0 = 0.5 \\
		y'(0) = c_1 = 0
	\end{array}
\right.$$
$$\implies y(t) = 0.5e^{-\sqrt{\frac{k}{m}}t},\quad m = 1\text{kg}, \quad k = 10 \;\text{N/m}$$
$$y(t) = 0.5e^{-\sqrt{10}t} \qquad (0 \leq t \leq 20)$$

> ![[y=0.5e^{-sqrt{10}x}.png|500]]
> $$y(t) = 0.5e^{-\sqrt{10}t} \qquad (0 \leq t \leq 20)$$

---

$$4. \ \ \ (5)$$
$$c = 0.25C_{\text{critical}}, \; 0.5 C_{\text{critical}}, \; 2C_{\text{critical}},\; 4C_{\text{critical}}$$
$$\implies
\left\{
	\begin{array}{}
		y_{0.25(+)} = 0.5e^{-\frac{\sqrt{10}}{4}t} \\
		y_{0.5(+)} = 0.5e^{-\frac{\sqrt{10}}{2}t} \\
		y_{2(+)} = 0.5e^{-2\sqrt{10}t} \\
		y_{4(+)} = 0.5e^{-4\sqrt{10}t}
	\end{array}
\right.$$
.

> ![[y=0.5e^{-frac{sqrt{10}}{4}t}.png|500]]
> $$y_{0.25(+)} = 0.5e^{-\frac{\sqrt{10}}{4}t}$$

.

> ![[y=0.5e^{-frac{sqrt{10}}{2}t}.png|500]]
> $$y_{0.5(+)} = 0.5e^{-\frac{\sqrt{10}}{2}t}$$

.

> ![[y=0.5e^{-2sqrt{10}t}.png|500]]
> $$y_{2(+)} = 0.5e^{-2\sqrt{10}t}$$

.

> ![[y=0.5e^{-4sqrt{10}t}.png|500]]
> $$y_{4(+)} = 0.5e^{-4\sqrt{10}t}$$

---

$$4.\ \ \ (6)$$
$$\text{Overdamping: 振動幅度會緩慢下降}$$
$$\text{Critical damping: 振動幅度會成指數型快速下降}$$
$$\text{Overdamping: 振動衰減會隨指數變化來回波動下降}$$

---

$$4. \ \ \ (7)$$
$$\text{stiffer spring} \implies k \uparrow \qquad \text{we know}\; C_{\text{critical}} = \sqrt{4km}$$
$$\implies k\uparrow \implies C\uparrow \implies \text{we need more damper force to maintain}$$

---

$$4. \ \ \ (8)$$
$$\text{heavier mass}\implies m\uparrow \qquad C_{\text{critical}} = \sqrt{4km}$$
$$\implies m \uparrow \implies C \uparrow \implies \text{we need more damper force to maintain}$$

---

$$5.$$
$$y(t) = A\cos\omega t\; (\text{initial speed} = 0, \; A = \text{constant})$$
$$\omega = \sqrt{\frac{k}{m}}\qquad m_t > m_c$$
$$\text{let}\; k = \text{constant} \implies \omega_c > \omega_t$$
$$\implies \text{車子振動較多}$$
$$\implies m_c = \text{constant},\; w_t \downarrow \implies k_c \downarrow$$
$$k_c < k_t$$

---

$$6.$$
$$\text{A sports car need a stiffer spring because it needs stiff springs to}$$
$$\text{make car steady at high speed. }$$
$$\text{However, it will become uncomfortable.}$$

---

links:

[[Bernoulli's Equations Substitution]]
[[Separable Variables]]
[[First Order Differential Equation]]