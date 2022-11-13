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

There is a simple solution to this. If an ACK is not received within this time, the packet is retransmitted.
However, this introduces the possibility of ==duplicate data packets==. [[#rdt2.2]] already has enough functionality to handle the case of duplicate packets.

Using a ==countdown timer==, the sender will thus need to be able to

1. Start the timer each time a packet is sent.
2. Respond to a timer interrupt.
3. Stop the timer.

![[Pasted image 20221113154339.png]]

Because packet sequence numbers alternate between 0 and 1, protocol rdt3.0 is sometimes known as the ==alternating-bit protocol==.

# Pipelined RDT

Protocol [[#rdt3.0]] is a functionally correct protocol, but it is a stop-and-wait protocol. The flaws of a stop-and-wait protocol is illustrated in the figure below.

![[Pasted image 20221113154724.png]]

As you can see, the ==utilization== of the channel is small.

The solution to this is simple. Rather than operate in a stop-and-wait manner, the sender is allowed to send multiple packets without waiting for acknowledgments. This technique is known as ==pipelining==.

There are two basic approaches toward pipelined error recovery:

1. [[#Go-Back-N]]
2. [[#Selective Repeat]]

## Go-Back-N

Go-back-n is simple. 

1. There is a window. The sender can send all packets in the window.
2. If there is an ACK with a sequence number, the window moves to the right of the corresponding packet.
3. If timeout, sender send all packets in the window again.
4. The receiver only receive the packet that equals to the `expectedseqnum`. Other packets that skipped some number will be ignored.
5. The ACK sent from the receiver is a ==cumulative acknowledgement==, meaning that all packets with a sequence number up to and including $n$ have been correctly received at the receiver.

![[Pasted image 20221113160720.png]]

## Selective Repeat

In [[#Go-Back-N]], a single packet error can cause it to retransmit a large number of packets, many unnecessarily.

As the name suggests, selective-repeat protocols avoid unnecessary transmissions by having te sender retransmit only those packets that it suspects were received in error at the receiver.

![[Pasted image 20221113172049.png]]

The SR receiver wil acknowledge a correctly received packet whether or not it is in order. Out-of-order packets are buffered until any missing packets are received.

| SR sender events and actions | SR receiver events and actions |
| ---------------------------- | ------------------------------ |
| <ol><li>Data received from above. The SR sender checks the next available sequence number for the packet. If the sequence number is within the sender's window, the data is packetized and sent. Otherwise, it is either buffered or returned to the upper layer for later transmission.<li>Timeout. Each packet must now have its own logical timer, since only a single packet will be transmitted on timeout. A single hardware timer can be used to mimic the operation of multiple logical timers.<li>ACK received. The sender marks the packet as received. If the packet's sequence number is equal to the first packet in the window, the window base is moved forward to the unacknowledged packet with the smallest sequence number.</ol>                             | <ol><li>Packet with sequence number is correctly received. A selective ACK is returned to the sender. If the packet was not previously received, it is buffered. If this packet has a sequence number equal to the base of the receive window, then this packet and any previously buffered and consecutively numbered packets are delivered to the upper layer, and the window is moved forward.<li>Packet with sequence number less than base is received. An ACK must be generated.<li>Otherwise, ignore the packet.</ol>                               |

---

參考資料:

Computer Networks, A Top-Down Approach, 8th edition.

---

link:


---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.