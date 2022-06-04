標籤: #工程數學 

---

用來解 complementary

跟 [[Auxiliary Function]] 類似

# 方法

## 2nd order

$$a_2x^2y''(x) + a_1xy'(x) + a_0y = 0$$
.
[[Auxiliary Function]]:
$$a_2m(m - 1) + a_1m + a_0 = 0 \qquad
  a_2m^2 + (a_1 - a_2)m + a_0 = 0$$
.
roots
$$m_1 = \frac{a_2 - a_1 + \sqrt{(a_1 - a_2)^2 - 4a_2a_0}}
             {2a_2} \qquad
  m_2 = \frac{a_2 - a_1 - \sqrt{(a_1 - a_2)^2 - 4a_2a_0}}
             {2a_2}$$
.
### \[Case 1\]: $m_1 \neq m_2$ and $m_1$, $m_2$ are real
.
two independent solution of the homogeneous part:
$$x^{m_1} \;\text{and}\; x^{m_2}$$
$$y_c = c_1x^{m_1} + c_2x^{m_2}$$
.
### \[Case 2\]: $m_1 = m_2$
.
Use the method of [[Reduction of Order]]
$$y_1 = x^{m_1}$$
.
$$y_2(x) = y_1(x)\int\frac{e^{-\int P(x)dx}}{y_1^2(x)}dx
         = x^{m_1}\int\frac{e^{-\int\frac{a_1}{a_2x}dx}}
		                   {x^{2m_1}} dx$$
$$\text{Note 1: 原式}\rightarrow y''(x) + 
                                \frac{a_1}{a_2x}y'(x) + 
								\frac{a_0}{a_2x^2}y = 0,\quad
				     P(x) = \frac{a_1}{a_2x}$$
$$\text{Note 2: 此時}\; m_1 = m_2 
                           = \frac{a_2 - a_1}{2a_2}$$
.
$$y_2(x) = x^{m_1}\int\frac{e^{-\int\frac{a_1}{a_2x}dx}}
                           {x^{2m_1}}dx
		 = x^{m_1}\int\frac{e^{-\frac{a_1}{a_2}\ln\vert x\vert}}
		                   {x^{2m_1}}dx
		 = x^{m_1}\int\frac{\vert x\vert^{-\frac{a_1}
		                                        {a_2}}}
		                   {x^{2m_1}}dx$$
$$= \cancel{(-1)^{-\frac{a_1}
                {a_2}}}x^{m_1}\int x^{-\frac{a_1}
				                           {a_2}}x^{\frac{a_1 - a_2}
										                 {a_2}}dx
  = x^{m_1}\int x^{-1}dx
  = x^{m_1}\ln\vert x\vert$$
If $y_2(x)$ is a solution of a homogeneous DE
then $cy_2(x)$ is also a solution of the homogeneous DE
.
If we constrain that $x > 0$, then $y_2 = x^{m_1}\ln x$
$$y_c = c_1x^{m_1} + c_2x^{m_1}\ln x$$
.
### \[Case 3\]: $m_1 \neq m_2$ and $m_1$, $m_2$ are the form of
$$m_1 = \alpha + j\beta \qquad m_2 = \alpha - j\beta$$
two independent solution of the homogeneous part:
$$x^{\alpha + j\beta} \;\text{and}\; x^{\alpha - j\beta}$$
.
$$y_c = C_1x^{\alpha + j\beta} + C_2x^{\alpha - j\beta}$$
$$x^{\alpha + j\beta} = (e^{\ln x})^{\alpha + j\beta} 
                      = e^{(\alpha + j\beta)\ln x}
					  = e^{\alpha \ln x}e^{j\beta \ln x}$$
$$ = x^\alpha (\cos(\beta \ln x) + 
               j\sin(\beta \ln x))$$
$$\text{同理}\; x^{\alpha - j\beta} = x^\alpha(\cos(\beta\ln x)
                                              - j\sin(\beta \ln x))$$
.
$$y_c = x^\alpha [
                     (C_1 + C_2)\cos(\beta\ln x) +
					 (C_1 - C_2)\sin(\beta\ln x)
                 ]$$
.
$$y_c = x^\alpha [
                     c_1\cos(\beta\ln x) +
					 c_2\sin(\beta\ln x)
                 ]$$

## higher order

### case 1

若 [[Auxiliary Function]] 在 $m_0$ 的地方只有一個根
$$x^{m_0}$$

### case 2
若 [[Auxiliary Function]] 在 $m_0$ 的地方有 $k$ 個重根
$$x^{m_0},\; 
  x^{m_0}\ln x,\; 
  x^{m_0}(\ln x)^2,\; ... , \;
  x^{m_0}(\ln x)^{k - 1}$$

### case 3

若 [[Auxiliary Function]] 在 $\alpha + j\beta$ 和 $\alpha - j\beta$ 的地方各有一個根(未出現重根)
$$x^\alpha\cos(\beta\ln x), \; x^\alpha\sin(\beta\ln x)$$

### case 4

若 [[Auxiliary Function]] 在 $\alpha + j\beta$ 和 $\alpha - j\beta$ 的地方皆有 $k$ 個重根
$$x^\alpha\cos(\beta\ln x),\;
  x^\alpha\cos(\beta\ln x)\ln x,\;
  x^\alpha\cos(\beta\ln x)(\ln x)^2,\; ..., \;
  x^\alpha\cos(\beta\ln x)(\ln x)^{k - 1}$$
$$x^\alpha\sin(\beta\ln x),\;
  x^\alpha\sin(\beta\ln x)\ln x,\;
  x^\alpha\sin(\beta\ln x)(\ln x)^2,\; ...,\;
  x^\alpha\sin(\beta\ln x)(\ln x)^{k - 1}$$

---

參考資料:

[Class 12 - Variation of Parameters and Cauchy-Euler Equation](https://youtu.be/TWnudCfwofE)