Tag: #operating-system 
Previous: [[Interprocess Communication]]
Link: 

[TOC]

---

- If two processes are willing to communicate, a **communication link** is required.
- The link can be implemented in a variety of ways, listed below.

# Different Implementations

## Direct Communication

Each process must explicitly name the recipient or sender of the communication.

- `send(P, message)`: send a message to process `P`.
- `receive(Q, message)`: receive a message from process `Q`.

## Indirect Communication

The messages are sent and received from **ports** and **mailboxes** instead of naming recipient or sender.

- `send(A, message)`: send a message to mailbox `A`.
- `receive(A, message)`: receive a message from mailbox `A`.

## Symmetry Communication

Both sender and receiver must specify each other to communicate.

- The example shown in [[#Direct Communication]] is symmetry communication.
- Symmetry Communication is [[#Direct Communication]].

## Asymmetry Communication

Only the sender must name the recipient.

- `send(P, message)`: send a message to process `P`.
- `receive(id, message)`: receive a message from any process. Variable `id` is set to the name of the process with which communication has taken place.

[[#Symmetry Communication]] and Asymmetry Communication schemes are both **hard-coding**.

- The identifiers must be explicitly stated, which is less desirable.
- Both symmetry and asymmetry schemes are [[#Direct Communication]].

## Synchronous / Asynchronous Communication

- **Synchronous**: **Blocking** message passing.
- **Asynchronous**: **Nonblocking** message passing.
- **Blocking send**: The sending process is blocked until the message is received by a receiving process or by the mailbox.
- **Nonblocking send**: The sending process sends and continues operation.
- **Blocking receive**: The receiver blocks until a message is available.
- **Nonblocking receive**: The receiver retrieves either a valid message or a null.

## Buffering Queues

- **Zero capacity**: The queue has a maximum size of zero. The sender must block until the recipient receives the message.
- **Bounded capacity**: The queue has finite length $n$. If the link is full, the sender must block until space is available in queue.
- **Unbounded capacity**: The queue's length is infinite. The sender is never blocked.

---

# Reference

Operating System Concepts, 9th edition

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.