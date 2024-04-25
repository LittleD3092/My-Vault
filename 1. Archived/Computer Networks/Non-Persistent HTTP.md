Tag: #network-systems-capstone 
Previous: [[HTTP]]
Link: 

---

The steps of a connection of a non-persistent HTTP is as follows:

1. Initiates TCP connection.
2. Client sends request to server.
3. Server respondes with `home.index` file.
4. Server tells TCP to close the TCP connection.
5. The client receives the response message. TCP connection closed. Client found that there are 10 references in `home.index` file.
6. For each reference, do step 1~5.

![[Pasted image 20221029052044.png|500]]

The time ==RTT (round-trip time)== is illustrated in the figure above. For the steps above, we need total of 22 RTTs to get the webpage.

---

# Reference

1. 

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.