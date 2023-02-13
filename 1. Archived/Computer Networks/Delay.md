標籤: #computer-networks 

---

[TOC]

---

There are many kinds of delays. The most important of these delays are

- [[#Nodal Processing Delay]]
- [[#Queuing Delay]]
- [[#Transmission Delay]]
- [[#Propagation Delay]]

These delays accumulate to give a ==total nodal delay==.

$$d_{\rm nodal} = d_{\rm proc} + d_{\rm queue} + d_{\rm trans} + d_{\rm prop}$$

# Nodal Delay

## Nodal Processing Delay

The time required to examine the packet's header and determine where to direct the packet. Also include the error checking time.

## Queuing Delay

The time that a packet wait in a queue. The length of the queuing delay will depend on the number of earlier-arriving packets that are queued and waiting for transmission onto the link.

One typically uses statistical measures, such as average queuing delay, variance of queuing delay, and the probability that the queuing delay exceeds some specified value.

### Traffic Intensity

Traffic intensity is given as

$$La / R$$

- $L$: how much bits each packet consist of
- $a$: average rate at which packets arrive at the queue ($\text{packets/sec}$)
- $La$: average rate of bits that arrive at the queue
- $R$: transmission rate (in $\text{bits/sec}$)

If $\text{traffic intensity} > 1$, the average rate at which bits arrive at the queue exceeds the rate at which the bits can be transmitted from the queue, which can cause ==packet loss==. We should never design a system that its traffic intensity is bigger than 1.

If $\text{traffic intensity} \leq 1$, and one packet arrives every $L / R$ second, the first packet has no queuing delay; the second one has $L / R$ delay; the $n$-th packet has $n - 1(L / R)$ delay. From this, we can calculate the ==average queuing delay==:

$$d_{\rm queue} = \frac LR \cdot \frac{n(0 + n - 1)}{2}$$

## Transmission Delay

Denote the length of the packet by $L$ bits, and denote the transmission rate of the link from router $\text A$ to router $\text B$ by $R \text{ bits/sec}$. The ==transmission delay== is $L / R$. This is the amount of time required to push all of the packet's bits into the link.

> Note that transmission delay has nothing to do with the distance between the two routers.

## Propagation Delay

Once a bit is pushed into the link, it needs to propagate to router $\text B$. The time required to propagate from the beginning of the link to router $\text B$ is the ==propagation delay==. 

The propagation speed depends on the physical medium of the link, and is in the range of 

$$2 \cdot 10^8 \text{ meters/sec to } 3\cdot 10^8 \text{ meters/sec}$$

The propagation delay is given by

$$
\begin{array}{l}
d / s, & d \text{ is the diatance, and } \\
&s \text{ is the propagation speed}
\end{array}
$$

# End-to-End Delay

In [[#Nodal Processing Delay]], we focused on the nodal delay, that is, the delay at a single router. Now consider the total delay from source to destination.

Suppose:

1. There are $N - 1$ routers between the source host and the destination host.
2. The [[#Nodal Processing Delay]] at each router and at the source host is $d_{\rm proc}$.
3. The transmission rate out of each router and out of the source host is $R\text{ bits/sec}$.
4. The propagation on each link is $d_{\rm prop}$.

$$d_{\rm end-end} = N(d_{\rm proc} + d_{\rm trans} + d_{\rm prop})$$

---

參考資料:

Computer Networking, A Top-Down Approach, 8th edition

---

link:


---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.