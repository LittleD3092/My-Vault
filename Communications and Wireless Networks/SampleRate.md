Tag: #communications-and-wireless-networks 
Previous: [[Rate Adaption Algorithm]]
Link: 

---

SampleRate is a [[Rate Adaption Algorithm]] that is the default algorithm in Linux. (<u>1</u>)

It periodically sends packets at a randomly-sampled bit rate, and estimate the achievable throughput: (<u>1</u>)

![[Pasted image 20240416185815.png]]

- To speed up the "probing" process, this algorithm will not sample the rates that **have failed four successive times**.

---

# Reference

1. Lin, Ching-Ju. “Communications and Wireless Networks, Lecture 5: Rate Adaption.” n.d. Accessed April 16, 2024.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.