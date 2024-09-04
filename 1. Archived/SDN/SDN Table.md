Tag: #SDN #computer-networks 
Previous: [[SDN]]
Link: 

[TOC]

---

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

# Example

The following examples shows some implementation of the table, based on the figure below.

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

# Reference

- Kurose, James F., and Keith W. Ross. Computer Networking: A Top-Down Approach. Eighth Edition. Pearson, n.d.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.