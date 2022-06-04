標籤: #電工學 

---

![[Power Transfer.png]]

What is the $R_2$ in order to obtain the maximum power from the power supply?

# [[Impedance]] Matching

To prove $R_L = R_{ eq }$

$$P_L = i_L \cdot v_L$$

$$ = \frac{ v_L^2 }{ R_L }$$

$$ = i^2_L \cdot R_L$$

$$P_L = \left( \frac{ v_{ oc } }{ R_{ eq } + R_L } \right)^2 \cdot R_L \qquad \frac{ d }{ dR_L } P_L = 0 \quad \text{ stationary condition }$$

$$\implies \frac{ (R_{ eq } + R_L)^2 - 2(R_{ eq } + R_{ L }) \cdot R_L }{ (R_{ eq } + R_L)^4 } = 0$$

$$\implies \underline{ R_L = R_{ eq } }_{ \# }$$

## 在[[AC Circuit]] 中的 Impedance Matching

$$Z_{ load } = Z^*_{ t }$$

$Z_t$: [[Kirchhoff's Law#Thevenin Norton-Equivalent-Circuit Analysis|thevinin equivalent impedance]]

### 證明

假設上述成立

$$Z_{ t } = R_t + jX_t$$

$$\implies Z_{ load } = Z_t^* = R_t - jX_t$$

$$\implies Z_{ total } = Z_t + Z_{ load } = 2R_t$$

我們發現在 voltage source 不變的情況下， load 會得到最大的電流，因此 load 得到的 power 會最大

---

參考資料:

電工學上課 2022-03-07

---

link:

[[Thevenin Circuit]]
[[Power]]