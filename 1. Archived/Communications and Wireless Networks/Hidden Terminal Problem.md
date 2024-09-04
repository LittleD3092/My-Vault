Tag: #communications-and-wireless-networks 
Previous: [[Communications and Wireless Networks]]
Link: 

---

![[Pasted image 20240416002157.png|300]]

The two nodes transmit at the same time, causing a collision. Also, the two nodes are not able to detect it because they can't hear each other due to the range. (<u>1</u>)

A solution to this (802.11) is: (<u>1</u>)

1. The sender sends a [[RTS]] to request transmission.
2. The [[Access Point]] replies with [[CTS]], granting the transmission and also tell other hosts about this.
3. Other hosts that receives the CTS can use [[Network Allocation Vector]] to keep track of the state of [[Access Point]]. However this is usually disabled due to the overhead.

![[Pasted image 20240416002515.png|400]]

![[Pasted image 20240416002741.png]]

---

# Reference

1. Lin, Ching-Ju. “Communications and Wireless Networks, Lecture 2: Medium Access Control.” n.d. Accessed April 15, 2024.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.