標籤: #電工學 

---

# Laws

## Faraday's Law

$\phi_B$: 磁力線

$$v_L = N\frac{ d\phi_B }{ dt }$$

## Maxwell Circuit Law

$H$: 磁場強度

$$\oint Hdl = Ni$$

$B$: flux density
$\mu$: magnectic permenbility

$$H = \frac{ B }{ \mu }$$

$$B = \frac{ \phi_B }{ A\text{rea } }$$

$$\implies v_L = L\frac{ di }{ dt }$$

$$L = \frac{ N^2\mu A }{ l }$$

# Properties

$$v_L = L\frac{ di_L }{ dt }$$

## Current in Terms of Voltage

$$di = \frac 1 L v(t) dt$$

$$\implies\int_{ i(t_0) }^{ i(t) } di = 
\frac 1 L \int_{ t_0 }^t v(t)dt$$

$$\implies 
\underline{ 
	i(t) = 
	\frac 1 L \int_{ t_0 }^{ t }v(t)dt + 
	i(t_0) 
}_{ \# }$$

## Energy Storage

$$E = \int Pdt = \int i_L v_L dt$$

$$ = \int_0^t i_L \cdot L \frac{ di_L }{ \cancel{ dt } } \cancel{ dt }$$

$$ = \frac{ 1 }{ 2 } L i_L^2 \qquad , i_L = i_L(t)$$

## Series Connection

$$L = L_1 + L_2$$

## Parallel Connection

$$L = \frac{ L_1 L_2 }{ L_1 + L_2 }$$

# [[Laplace Transform]]

![[Inductor Laplace Transform.png]]

$$\mathcal{ L }[v_L] = L\mathcal{ L }\left[\frac{ di_L }{ 
dt }\right]$$

$$v_L = sLI_L - Li_L(0)$$

---

參考資料:

電工學上課

---

link:

