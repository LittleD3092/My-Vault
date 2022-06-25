標籤: #工程數學 

check singular point

[[Bernoulli's Equations Substitution | Bernoulli's Equation]]:
$$\frac{dy}{dx}+\frac{a_0(x)}{a_1(x)}y=\frac{g(x)}{a_1(x)}y^n$$
$$\frac{dy}{dx} + P(x)y = f(x)y^n$$
singular points: the locations where $a_1(x) = 0$
$$\text{i.e., }P(x)\rightarrow\infty$$

More generally, even if $a_1(x)=0$ but $P(x)\rightarrow\infty$ or $f(x)\rightarrow\infty$, then the location is also treated as a singular point.

(a) Sometimes, the solution may not be defined on the interval including the singular points.

(b) Sometimes the solution can be defined at the singular points.

### example

$$(x^2-9)\frac{dy}{dx}+xy=0$$
$$\overset{\text{step 1}}{\implies}\frac{dy}{dx}+\frac{x}{x^2-9}y=0$$
$$\implies P(x)=\frac{x}{x^2-9}$$
$$\overset{\text{step 2}}{\implies}e^{\int\frac{x}{x^2-9}dx}=e^{\frac{1}{2}ln\vert x^2-9\vert}=\sqrt{\vert x^2-9\vert}$$
$$\overset{ \text{step3} }{ \implies }\frac{ d }{ dx }( \sqrt{ \vert x^2 - 9 \vert } * y ) = 0$$
$$\implies \sqrt{ \vert x^2 - 9 \vert } * y = c$$
$$\implies y = \frac{ c }{ \sqrt{ \vert x^2 - 9 \vert } }\text{, not includes the points of }x = -3, 3$$