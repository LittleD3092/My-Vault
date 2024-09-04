## 1. Accounting and Machiavellianism

### a. Population of interest

The population of interest is the alumni of a large southwestern university.

### b. Quantitative or qualitative

| Quantitative                                                              | Qualitative                      |
| ------------------------------------------------------------------------- | -------------------------------- |
| <li>Age<li>Income<li>Job satisfaction score<li>Machiavellian rating score | <li>Gender<li>Level of education |

### c. The sample

The sample consists of the 198 questionnaires.

### d. Inference made by the researcher

The researcher suggests that Machiavellian behavior is not required to achieve success in the accounting profession.

## 2. MLB statistics

### a. The third quartile

The third quartile is the value between the 5th and 6th player:

$$\frac{41 + 40}{2} = \underline{40.5}_\#$$

### b. The median

The median is the value between the 10th and 11st player:

$$\frac{37 + 36}{2} = \underline{36.5}_\#$$

### c. The interquartile range

The interquartile range $\text{IQR}$ is the difference between the third quartile $Q_3$ and the first quartile $Q_1$:

$$\text{IQR} = Q_3 - Q_1$$

The first quartile $Q_1$ is the value between the 15th and 16th player, and the third quartile $Q_3$ is already calculated in one of the previous questions:

$$
\left\{
\begin{array}{l}
	Q_1 = \displaystyle
	\frac{33 + 33}{2} = 33 \\
	Q_3 = 40.5
\end{array}
\right.$$

Using the values $Q_1$ and $Q_3$, we can get the interquartile range $\rm IQR$:

$$
\begin{array}{l}
	\rm IQR &=& Q_3 - Q_1 \\
	&=& 40.5 - 33 \\
	&=& \underline{7.5}_\#
\end{array}
$$

### d. The mode

The mode is $\underline{33}_\#$ since it appears 4 times (the most times) in the data set.

### e. Outliers

The outliers are observations that fall below $Q_1 - 1.5\rm IQR$ or above $Q_3 + 1.5 \rm IQR$:

$$
\left\{
	\begin{array}{l}
		Q_1 - 1.5\rm IQR &=& 33 - 1.5 \cdot 7.5 &=& 21.75 \\
		Q_3 + 1.5\rm IQR &=& 40.5 + 1.5 \cdot 7.5 &=& 51.75
	\end{array}
\right.
$$
Looking at the chart, there is one player above $Q_3 + 1.5 \rm IQR$ and there is no player below $Q_1 - 1.5 \rm IQR$. Therefore there is only $\underline{1}_\#$ outlier in this data set.

## 3. TW presidential election

The divisions of age ranges in the two charts are different. The intervals in the left chart are $20\sim 25, 25\sim 30, 30 \sim 35 \dots$ but the intervals in the right chart are $20\sim 24, 24 \sim 29, 30\sim 34\dots$.

## 4. Voltage sags and swells

### a. The probability that the number of sags per week is less than 400

- Mean $\mu = 353$
- Standard deviation $\sigma = 30$

$$
\begin{array}{l}
	z &=&
	\displaystyle \frac{x - \mu}{\sigma} \\
	&=& \displaystyle 
	\frac{400 - 353}{30} \\
	&=& 1.5667
\end{array}
$$

Therefore, the probability $P(X < 400)$ that the number of sags per week is less than $400$:

$$
\begin{array}{l}
P(X) &=& P(Z < 1.5667)
\end{array}$$

According to the chart, 

$$
\begin{array}{}
	P(Z < 1.56) &=& 0.940620 \\
	P(Z < 1.57) &=& 0.941792
\end{array}
$$

By interpolation:

$$
\begin{array}{l}
	P(Z < 1.5667) &=& \displaystyle
	\frac{
		(1.5667 - 1.56)\cdot 0.941792 + (1.57 - 1.5667) \cdot 0.940620 
	}{1.57 - 1.56} \\
	&=& \underline{0.9414}_\#
\end{array}
$$

### b. The probability that the number of swells per week is greater than 100

- Mean $\mu = 184$
- Standard deviation $\sigma = 25$
- $P(X > 100)$

$$
\begin{array}{}
	z &=& 
	\displaystyle
	\frac{x - \mu}{\sigma} \\
	&=& -3.36
\end{array}
$$

According to the chart, $P(Z < -3.36) = 0.000390$. Therefore, 

$$
\begin{array}{l}
P(Z > -3.36) &=& 1 - 0.000390 \\
&=& \underline{0.99961}_\#
\end{array}$$

## 5. Establishing tolerance limits

- Mean $\mu = 25$
- Standard deviation $\sigma = 2$
- Upper limit $x_{\rm upper} = 30$
- Lower limit $x_{\rm lower} = 21$
- Profit of tolerance $Pr_{\rm tolerance} = \$10$
- Profit of too low $Pr_{\rm low} = \$2$
- Profit of too high $Pr_{\rm high} = \$1$

$$
\begin{array}{l}
z_{\rm upper} &=& \displaystyle\frac{x_{\rm upper} - \mu}{\sigma} \\
&=& \displaystyle\frac{ 30  -  25 }{ 2 } \\
&=&  2.5
\end{array}
$$

$$
\begin{array}{}
z_{\rm lower} &=& \displaystyle\frac{x_{\rm lower} - \mu}{\sigma} \\
&=& \displaystyle\frac{ 21  -  25 }{ 2 } \\
&=&  -2.0
\end{array}
$$

According to the chart,

$$
\begin{array}{l}
	P(Z < -2.0) &=& 0.022750 \\
	P(Z < 2.5) &=& 0.993790
\end{array}
$$

We can derive the probability of three scenario:

$$
\begin{array}{l}
	P(Z < -2.0) &=& 0.022750 \\
	P(-2.0 < Z < 2.5) &=& 0.993790 - 0.022750 \\
	&=& 0.97104 \\
	P(Z > 2.5) &=& 1 - 0.993790 \\
	&=& 0.00621
\end{array}
$$

By using the profits of each scenario multiplied by the probabilities, we can get the expected profit per metal part produced:

$$
\begin{array}{l}
&&P(Z < -2.0) \cdot Pr_{\rm lower} + P(-2.0 < Z < 2.5)\cdot Pr_{\rm tolerance} + P(Z > 2.5) \cdot Pr_{\rm high} \\
&=& 0.022750 \cdot 2 + 0.97104 \cdot 10 + 0.00621 \cdot 1 \\
&=& \underline{11.73936}_\#
\end{array}
$$
