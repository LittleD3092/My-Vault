Tag: #computer-networks 
Previous: [[Data Plane]]
Link: 

---

[TOC]

---

- SDN stands for software defined network.
- It uses a **flow table** for forwarding.

![[Pasted image 20221217162715.png]]

Each entry in the flow table includes:

- *A set of header field values* to which an incoming packet will be matched.
	- Hardware-based matching is most rapidly performed.
	- A packet that does not match can be dropped or sent to the remote controller for further processing.
	- May be implemented using multiple flow table.
- *A set of counters* that are updated as packets are matched to flow table entries.
	- The counter includes 
		- The number of packets that have been matched by the table entry.
		- The time since the table entry was last updated.
- *A set of actions to be taken* when a packet matches a flow table entry.
	- Example:
		- Forward the packet to a given output port.
		- Drop the packet.
		- Make copies of the packet and sent then to multiple output ports.
		- Rewrite selected header fields.

As we can see, the process contains two steps:

1. [[#Match]]
2. [[#Action]]

# Match

- OpenFlow 1.0 allows for a match to be made on selected fields from *three* layers.
	- Link layer
	- Network layer
	- Transport layer
	- ![[Pasted image 20221218134009.png]]
- OpenFlow-enabled device can perform as a router ([[Networks]] Layer) and as a switch (Link layer).
- Flow table entries may have wild cards.
	- For example, `128.119.*.*` will match the corresponding address field of any datagram that has `128.119`.
	- If a packet matches multiple entries, the highest priority entry will be used.

# Action

- Each flow table entry has a list of zero or more actions.
- If there are multiple actions, they are performed in the order specified in the list.

Among the most important possible actions are:

- *Forwarding*.
	- Forward a packet to a particular port.
	- Broadcast a packet over all ports.
	- Multicast a packet over a selected set of ports.
- *Dropping*.
- *Modify-field*.
	- The values in 10 packet-header can be modified before forwarding.

# Example

The following examples are based on the figure below.

![[Pasted image 20221218134230.png]]

## 1. Simple Forwarding

For a simple forwarding purpose, the flow table of `s1`, `s2` and `s3` is

- `s1` Flow Table:

| Match                                                    | Action      |
| -------------------------------------------------------- | ----------- |
| `Ingress Port = 1; IP Src = 10.3.*,*; IP Dst = 10.2.*.*` | Forward (4) |
- `s3` Flow Table:

| Match                                  | Action      |
| -------------------------------------- | ----------- |
| `IP Src = 10.3.*.*; IP Dst = 10.2.*.*` | Forward (3) |
- `s2` Flow Table:

| Match                                 | Action      |
| ------------------------------------- | ----------- |
| `Ingress Port = 2; IP Dst = 10.2.0.3` | Forward (3) |
| `Ingress Port = 2; IP Dst = 10.2.0.4` | Forward (4) | 

## 2. Load Balancing

For load balancing, the datagrams from different ingress port should be forwarded to different link:

`s2` Flow Table:

| Match                                 | Action      |
| ------------------------------------- | ----------- |
| `Ingress port = 3; IP Dst = 10.1.*.*` | Forward (2) |
| `Ingress port = 4; IP Dst = 10.1.*.*` | Forward (1) | 

## 3. Firewalling

For a scenario that `s2` wants only to receive traffic sent from hosts attached to `s3`:

`s2` Flow Table:

| Match                                  | Action      |
| -------------------------------------- | ----------- |
| `IP Src = 10.3.*.*; IP Dst = 10.2.0.3` | Forward (3) |
| `IP Src = 10.3.*.*; IP Dst = 10.2.0.4` | Forward (4) | 

---

參考資料:

Computer Networking, A Top-Down Approach, 8th edition

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.