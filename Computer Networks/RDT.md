標籤: #computer-networks 

---

[TOC]

---

RDT is an imaginary protocol that shows the process of designing a reliable data transfer protocol. This protocol will look similar to [[TCP]].

# Building a Reliable Data Transfer Protocol

## rdt1.0

We first consider the simplest case, in which the underlying channel is completely reliable.

With a perfectly reliable channel, there is no need to provide any feedback to the sender.

![[Pasted image 20221113011755.png]]

## rdt2.0

Now we consider if bits in a packet may be corrupted. We'll continue to assume for the moment that all transmitted packets are received in the order in which they were sent.

The protocol should use both ==positive acknowledgments== and ==negative acknowledgments==. This allow the receiver to let the sender know what has been received correctly.

The following capabilities are required:

1. Error detection.
2. Receiver feedback.
3. Retransmission.

![[Pasted image 20221113012615.png]]

Note that during "Wait for ACK or NAK" state, it cannot get more data from the upper layer. The upper layer must stop and wait for ACK and NAK. Because of this behavior, these kinds of protocols are known as ==stop-and-wait protocols==.

## rdt2.1

Unfortunately, [[#rdt2.0]] has a fatal flaw. We haven't accounted for the possibility that the ACK or NAK packet could be corrupted.

We have some ways to handle corrupted ACKs or NAKs:

1. If the ACK or NAK is corrupted, the sender sends a packet requesting the receiver to send another ACK or NAK packet. But what if the request packet is corrupted?
2. We may add enough checksum bits to allow the sender not only to detect, but also to recover from bit errors. But what if the ACK or NAK packet is completely lost?
3. If the ACK or NAK is corrupted, the sender simply resend the current data packet. However, ==duplicate packets== are introduced into the channel. The receiver doesn't know whether the ACK or NAK it last sent was received correctly at the sender. Thus, it cannot know a priori whether an arriving packet contains new data or is a retransmission.

There is a simple solution to this problem. We can add a new field ==sequence number== to the data packet.

![[Pasted image 20221113014800.png]]

![[Pasted image 20221113014820.png]]

In this way, the sender knows that a received ACK or NAK packet was generated in reponse to its most recently transmitted data packet.

## rdt2.2

We can accomplish the same effect as a NAK if, instead of sending a NAK, we send an ACK for the last correctly received packet. 

A sender that receives two ACKs for the same packet (==duplicate ACKs==) knows that the receiver did not correctly receive the packet following the packet that is being ACKed twice.

![[Pasted image 20221113015608.png]]

![[Pasted image 20221113015615.png]]

## rdt3.0

Suppose now that in addition to corrupting bits, the underlying channel can *lose* packets as well.

Two additional concers must now be addressed by the protocol

1. How to detect packet loss.
2. What to do when packet loss occurs.



---

參考資料:

Computer Networks, A Top-Down Approach, 8th edition.

---

link:


---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.