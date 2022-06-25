標籤: #電工學 

---

# Generation and Recombination

半導體本身在低溫時不導電，在受到熱時（或者任何能量）就會有電子躍遷變成 Free Electron ，並且產生 [[#Hole]] ，稱為 [[#Generation]] ，而電子回到電洞稱為 [[#Recombination]]

## Generation

$$\text{ valent } \rightarrow \text{ conduction }$$

產生電子，讓半導體導電。

當溫度升高時

$$n_i\text{ (free electron density, electrons} / m^3 \text{) } \text{ increase }$$

在純 Si 中，自由電子跟電洞的數量相等

$$p_i = n_i$$

$P_i$: hole density
$i$: intrinsic, 無雜質

## Recombination

$$\text{ conduction } \rightarrow \text{ valent }$$

自由電子變成結構電子

# P-doping and N-doping

在半導體中，我們會故意加入第三族 (B, Al, Ga, In, Tl, [[#P-doping]]) 或第五族 (N, P, As, Sb, Bi, [[#N-doping]]) 到 Si 之中，形成少電子 ([[#Hole]]) 或多出電子 ([[#Impurity]]) 的半導體

因此在實際情況下

$$n \cdot p = n_i\cdot p_i$$

等號左邊代表包含 external injection 的電子數量，相乘會相等於純矽情況下的 $p$ 與 $n$ 相乘。

$n$ (自由電子) 與 $p$ (holes) 成反比，因此加入額外的電子會使 $p$ 變小

## Hole

圖中圈起的地方少了一個電子，叫做 Hole

![[Semiconductor Hole.png|300]]

## Impurity

圖中圈起的地方多了一個電子，叫做 Impurity

![[Semiconductor Impurity.png|300]]

## N-doping

加入第五族的元素到 Si single crystal ，造成

$$\because n \cdot p = n_i\cdot p_i$$

$$n > n_i$$

$$p < p_i$$

## P-doping

加入第三族的元素到 Si single crystal ，造成

$$p > p_i$$

$$n < n_i$$

## Heavily doping

如果加太多第三族或第五族元素就叫做 heavily doping

$$n >> n_i \;\text{ or }\; p >> p_i$$

# 製造過程

先使用微波加熱泥土，並且使用一片 Cold Plate ，上面有晶種，讓矽結晶在上面，慢慢的將 Cold Plate 旋轉往上

![[Semiconductor 製造方式 heating.png]]

矽最後會結晶在 Cold Plate 上形成晶柱，此時可以將它切片

![[Semiconductor 製造方式 切片.png]]

之後上面有殘留應力，因此須要 annealing process 讓晶體重新生長，去除殘留應力。只需要約表面 $10\mu m$ 的厚度處理就可以了

最後將圓盤切割成許多方格 (dicing) ，其中一格就是一個 IC ，可以封裝並出貨

# pn Junction

由兩片 [[#Heavily doping]] 的半導體組成，兩片之間會有電壓

![[pn junction.png]]

![[pn junction 2.png]]

電子會有一個向右的力，稱為 diffusion

並且電子會補到 [[#hole]] 裡面，稱為 recombination

> <font face = "serif">Diffusive motive force brings the free electron from n-type region to the p-type region 
> 
> The electrical [[Field]] is built in the interface between the n-type and p-type region.
> 
> The depletion region is formed under the balance of the diffusive motive force and the drift force due to the electrical [[Field]]</font>

這樣的東西我們將它叫做 [[Diode]]

---

參考資料:

電工學上課

---

link:

