Tag: #communications-and-wireless-networks 
Previous: [[Rate Adaption Algorithm]]
Link: 

---

RRAA (Robust Rate Adaption Algorithm) is a rate adaption algorithm that changes speed based on measuring the **packet loss rate**. (<u>1</u>)

The lost ratio is defined by: (<u>1</u>)

$$
P = \frac{\text{Number of Lost Frames}}{\text{Number of Transmitted Frame}}
$$

Also, two threshold $P_{\rm max}, P_{\rm min}$ is compared to $P$. (<u>1</u>)

- If $P > P_{\rm max}$: The rate is switched to a lower one.
- If $P < P_{\rm min}$: The rate is switched to a higher one.

$$
\begin{array}{l}
	P_{\rm max}^r &=& \displaystyle 1 - \frac{T_{rx}(r, n, l)}{T_{rx}(r - 1, n = 1, l)} \\
	P_{\rm min} &=& \displaystyle \frac{P_{\rm max}^{r + 1}}{\beta} & \text{(Heuristic Equation)}
\end{array}
$$

- $T_{rx}(r, n, l)$: The time of transferring a packet (current).
- $T_{rx}(r - 1, n = 1, l)$: The time of transferring a packet assuming using a lower rate $r - 1$, and no retransmissions happen.
- $\beta$: A constant, heuristic value is $2$.

---

# Reference

1. Lin, Ching-Ju. “Communications and Wireless Networks, Lecture 5: Rate Adaption.” n.d. Accessed April 16, 2024.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.