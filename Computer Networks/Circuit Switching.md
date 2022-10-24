標籤: #computer-networks 

---

[TOC]

---

![[Pasted image 20221024192032.png|500]]

In circuit-switched networks, the resources needed along a path (buffers, link transmission rate) are reserved for the duration of the communication session. Note that in this way, a queue is not needed.

> In [[Packet Switching]], we need a queue for the packets, and the end systems wait in line to be served. However, in circuit switching, we don't need to wait for the message to be sent to the destination. Instead, we reserve the path.

- Traditional telephone networks are examples of this approach.
- The sender can transfer the data to the receiver at the guaranteed constant rate.
- When two hosts want to communicate, an ==end-to-end communication== is established.

# Multiplexing

There are two ways of implementing a circuit in a link:

- [[#Frequency-Division Multiplexing (FDM)]]
- [[#Time-Division Multiplexing (TDM)]]

## Frequency-Division Multiplexing (FDM)

The frequency spectrum of a link is divided up among the connections established across the link. The width of the band is called ==bandwidth==.

## Time-Division Multiplexing (TDM)

- The time is divided into frames of fixed duration, and each frame is divided into a fixed number of time slots. 
- When the network establishes a connection across the link, the network dedicate a time slot of each frame.

# Problems

People say that the circuit switching approach is wasteful because the dedicated circuits are idle during ==silent periods==. Consider one person in a telephone call stops calling. The idle network resources cannot be used by other ongoing connections.

---

參考資料:

Computer Networking, A Top-Down Approach, 8th edition

---

link:


---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.