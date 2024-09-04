Tag: #communications-and-wireless-networks 
Previous: [[BSS]]
Link: 

---

DCF (Distributed Coordination Function) let stations to contend for transmission opportunities in a distributed way. (<u>1</u>)

- This mode rely on [[CSMA-CA]].

In this mode, each station follow the steps below: (<u>1</u>)

![[Pasted image 20240416000723.png]]

1. Wait for [[DIFS]].
2. Avoid collisions using [[Exponential Random Backoff|random backoff]].
3. Sends the [[PPDU]].
4. If the [[Access Point]] responds with an ACK, the transmission completes.
5. Retransmit until the retry limit is reached.

---

# Reference

1. Lin, Ching-Ju. “Communications and Wireless Networks, Lecture 2: Medium Access Control.” n.d. Accessed April 15, 2024.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.