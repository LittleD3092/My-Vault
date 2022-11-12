標籤: #computer-networks 

---

[TOC]

---

UDP is a no-frills, lightweight transport protocol, providing minimal services. This provides developers more freedom to implement the features in [[Application]] layer.

- There is no handshaking. Because of this, UDP is said to be ==connecitonless==.
- Finer application-level control over what data is sent, and when.
- Small packet header overhead. (The TCP segment has 20 bytes of header overhead in every segment, while UDP has only 8.)

# Segment Structure

![[Pasted image 20221113005059.png|450]]

- Source port, Dest. port: allow [[Transport#Multiplexing and Demultiplexing|demultiplexing]].
- Length: specifies the number of bytes in the UDP segment (header + data).
- [[#Checksum]]: check whether the package is corrupted. Discussed in the following section. 

## Checksum

1. Assume we have three 16-bit words
$$
\begin{array}{}
	0110011001100000 \\
	0101010101010101 \\
	1000111100001100
\end{array}
$$
2. We sum all the three words to a single 16-bit words. We will ignore the overflow.
$$
sum = 0100101011000010
$$
3. Take 1s complement of $sum$.
$$checksum = 1011010100111101$$
4. If no errors are introduced into the packet, then the sum at the receiver will be $1111111111111111$. If one of the bits is a $0$, then we know that errors have been introduced into the packet.

Note that UDP does not do anything to recover from an error.

> Although many link-layer protocols provide error checking, some of them don't. 
> Also, it's possible that bit errors could be introduced when a segment  is stored in a router's memory.
> Thus, UDP have to provide error detection.
> 
> This is an example of ==end-end principle==, which states that certain functionality must be implemented on an end-end basis.

---

參考資料:

Computer Networking, A Top-Down Approach, 8th edition

---

link:


---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.