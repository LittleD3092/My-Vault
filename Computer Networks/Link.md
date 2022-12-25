Tag: #computer-networks 
Previous: [[Layers]]
Link: 

---

[TOC]

---

# Introduction

## Terminology

- **Node**: Any device that runs a link-layer protocol.
- **Links**: The channels that connect adjacent nodes.
- **Link-layer frame**: The encapsulated **datagram**.

## Services

- *Framing*: Encapsulate the datagram into a frame.
- *Link access*: MAC (medium access control) protocol specifies the rules by which a frame is transmitted onto the link.
- *Reliable delivery*: Guarantees to move datagram without error.
	- Some low error links like fiber often does not provide reliable delivery.
	- Wireless link need this service.
- [[#Error Detection and Correction]]: Find bit errors and correct them.

## Implementation

![[Pasted image 20221225150520.png]]

- The link layer is implemented on a chip called **network adapter**, also known as a **network interface controller (NIC)**.

# Error Detection and Correction

![[Pasted image 20221225152105.png]]

- The receiver can sometimes, *but not always* detect the bit errors.
	- There may be **undetected bit errors**.
- The ability of the receiver to both detect and correct errors is known as **forward error correction (FEC)**.

## Parity Checks

- The simplest form of error detection is a single **parity bit**.
- Choose the parity bit value that the number of total 1s is even.

![[Pasted image 20221225152710.png]]

The above is not good enough. We have a better version, **two-dimensional parity**:

![[Pasted image 20221225153248.png]]

- Each column and row must have even numbers of 1s.
- Can detect and correct single error.
- Can also detect two errors (but *not correct*).

---

參考資料:

Computer Networking, A Top-Down Approach, 8th edition

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.