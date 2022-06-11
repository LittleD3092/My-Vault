標籤: #工程數學 
Team members:
- 109611066 吳典謀
- 109611030 陳柏文
- 109611004 張瀚元

---

# Part 1: Synthetic Signals

## 1. Simple cosine signal

<font color = #3a86ff>a. Given a cosine signal of amplitude $= 1$ and frequency $= 10\text{Hz}$. Write a function $g(t)$ for this signal. What assumptions did you make to ensure the units are correct?</font>

A cosine signal looks like this:

$$g(t) = \cos (\omega t + \theta)$$

Where $\omega$ is angular velocity, $\theta$ is offset. We assume offset $\theta = 0$ and 

$$\omega = 2\pi f$$

Where $f = 10 \text{Hz}$, therefore

$$\omega = 20\pi$$

And $g(t)$ is

$$\underline{
	g(t) = \cos 20\pi t
}_\#$$

<font color = "#3a86ff">b. Solve the Fourier Transform of $g(t)$ by hand, getting $\hat g(f)$, where $f$ denotes frequency. Show step-by-step derivation.</font>

$$\hat g(f) = \frac 1 {\sqrt{2\pi}}\int_{-\infty}^\infty 
g(t)e^{-i2\pi ft}dt$$

$$\implies \hat g(f) = \frac{1}{\sqrt{2\pi}}\int_{-\infty}^\infty \cos (20\pi t)e^{-i2\pi ft}dt$$

Convert cosine function using euler formula

$$\implies \hat g(f) = \frac 1 {\sqrt{2\pi}}\int_{-\infty}^\infty
\frac{e^{i20\pi t} + e^{-i20\pi t}}{2} \cdot e^{-i2\pi ft}dt$$

$$\implies \hat g(f) = \frac{1}{2\sqrt{2\pi}}
\left(
	\int_{-\infty}^\infty e^{i20\pi t} e^{-i2\pi f t}dt + \int_{-\infty}^\infty e^{-i20\pi t} e^{-i2\pi ft}dt
\right)$$

> Because [[Dirac Delta Function#Sifting|sifting property of dirac delta function]]
> $$\mathcal F\{\delta(t - a)\} = \frac{1}{\sqrt{2\pi}}\int_{-\infty}^\infty \delta(t - a)e^{-i2\pi ft}dt$$ 
> $$= \frac{1}{\sqrt{2\pi}}e^{-i2\pi fa}$$
> Then we do fourier inverse transform
> $$\mathcal F^{-1}\left\{\frac{1}{\sqrt {2\pi}}e^{-i2\pi fa}\right\}$$
> $$= \frac{1}{\sqrt{2\pi}}\int_{-\infty}^\infty \frac{1}{\sqrt{2\pi}}e^{-i2\pi fa} e^{i2\pi ft}df = \delta(t - a)$$
> $$\implies \int_{-\infty}^\infty e^{-i2\pi fa}e^{i2\pi ft}df = 2\pi \delta(t - a)$$
> We change the notation with $f \rightarrow t, t \rightarrow -f$ to fit our notation of $\hat g(f)$ above
> $$\implies \underline{\int_{-\infty}^\infty e^{-i2\pi at}e^{-i2\pi ft}dt = 2\pi \delta(-f-a)}$$
> Therefore the first integration
> $$\int_{-\infty}^\infty e^{i20\pi t} e^{-i2\pi ft}dt = 2\pi\delta(-f + 10)$$
> And the second integration
> $$\int_{-\infty}^\infty e^{-i20\pi t} e^{-i2\pi ft}dt = 2\pi\delta(-f - 10)$$

$$\implies \hat g(f) = \frac{1}{2\sqrt{2\pi}}(2\pi\delta(-f + 10) + 2\pi\delta(-f - 10))$$

$$\implies \underline{ \hat g(f) = \frac{\sqrt{2\pi}}{2}(\delta(f - 10) + \delta(f + 10))}_\#$$

<font color = "#3a86ff">c. Plot magnitude spectrum of $\hat g(f)$ as a function of $f$ in Matlab. Does the plot correctly show a peak at $10\text{Hz}$?</font>

![[Pasted image 20220611172407.png]]

```matlab
function [x,n]=delta_me(n0,n1,n2)
n=n1:n2;
x=[(n-n0)==0];
```

```matlab
clc;clear all;clf; 
n=[-20:20]; xn=delta_me(-10,-20,20)+delta_me(10,-20,20); stem(n,xn);
```

<font color = "#3a86ff">d. From the attached example Matlab code, generate a discrete cosine signal of the same amplitude and frequency as (a). Take the DFT of the signal. Plot both the signal and its magnitude spectrum. Does it agree with your hand-derived solution?</font>

![[Pasted image 20220611174856.png]]
![[Pasted image 20220611175105.png]]

Yes, it agrees with our hand-derived solution.

## 2. Phasing signal

<font color = "#3a86ff">a. Add a sine signal of identical amplitude and frequency to the signal in (1a). Plot its spectrum in Matlab.</font>

![[Pasted image 20220611175831.png]]

<font color = "#3a86ff">b. Did the spectrum's peak change in frequency? Why?</font>

No, because the frequency did not change.

<font color = "#3a86ff">c. How about amplitude? Why?</font>

Yes, because the sine and cosine sum together, so the amplitude is larger.

<font color = "#3a86ff">d. Plot the signal-vs-time for $g(t) = \cos(\dots t)$ and the new $g(t) = \cos(\dots t) + \sin(\dots t)$. How are they different? How does this difference show up in the phase plots?</font>

signal-vs-time for $g(t) = \cos(\dots t)$:
![[Pasted image 20220611174856.png]]

signal-vs-time for $g(t) = \cos(\dots t) + \sin(\dots t)$
![[Pasted image 20220611175840.png]]

The second signal has different amplitude and same frequency, and has an offset compared to the first signal.

# Part 2: Audio Manipulation:

## 3. Application

<font color = "#3a86ff">a. Two audio files from [fisheries](https://www.fisheries.noaa.gov/national/science-data/sounds-ocean) have been included: (i) Dolphin, (ii) Whale + ocean noise.</font>

<font color = "#3a86ff">b. Write Matlab code that reads both audio and plot their signals.</font>

```matlab
[y, fs]=audioread('Audio_bottlenose-dolphin.mp3');	
time=(1:length(y))/fs;	
plot(time, y);	
xlabel('time')
ylabel('amplitude')
title('dolphon')
```
![[Pasted image 20220611181341.png]]

---

```matlab
[y, fs]=audioread('Audio_humpback-whale and ocean-noise.mp3');	
time=(1:length(y))/fs;	
plot(time, y);	
xlabel('time')
ylabel('amplitude')
title('dolphon')
```

![[Pasted image 20220611181743.png]]

<font color = "#3a86ff">c. Plot the spectrum of these audio signals. Observe any differences (Dolphin should be higher freq).</font>



<font color = "#3a86ff">d. To simulate a situation where both Dolphin and Whale are recorded simultaneously, add the two signals together (note: since the audios are different length, you may need to repeat the shorter signal). Plot this new signal and its spectrum. Compare to (3b).</font>



<font color = "#3a86ff">e. Can you identify which region of the frequency-domain belong to the Dolphin, the Whale and the ocean background noise, respectively?</font>


<font color = "#3a86ff">f. Try to separate the signal in (5d-e) into Dolphin vs. Whale vs. Background in the frequency domain, then use inverse-FFT to reconstruct the time-domain audio files. Save these files and play. Was the audio manipulation successful? (I.e. did you clearly isolate Dolphin, Whale and Background sounds using FFT?)</font>