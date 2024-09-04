Tag: #communications-and-wireless-networks 
Previous: [[CSMA]]
Link: 

---

Exponential random backoff is the amount of delay before transmitting the next packet when a collision happens. (<u>1</u>)

It is calculated and changed based on the steps below: (<u>1</u>)

1. A contention window $CW_{\rm min}$ is initialized to $32$.
2. The backoff $k$ is chosen randomly between $[0, CW - 1]$.
3. If backoff time reached and the channel is idle, the contention window is reset and the packet is transmitted. If the channel is busy, the backoff time is **doubled**.

---

# Reference

1. Lin, Ching-Ju. “Communications and Wireless Networks, Lecture 2: Medium Access Control.” n.d. Accessed April 15, 2024.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.