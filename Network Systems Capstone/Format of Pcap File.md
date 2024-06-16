Tag: #network-systems-capstone 
Previous: [[Pcap File]]
Link: 

---

The format of pcap file is as follows: (<u>1</u>)

![[format of pcap file.png|400]]

# Global Header

The format of the global header is as follows:

![[pcap file global header.png]]

- Magic Number:
	- `0xA1B2C3D4`: The timestamp in each packet header is in seconds and microseconds.
	- `0xA1B23C4D`: The timestamp in each packet header is in seconds and nanoseconds.
- SnapLen: The maximum number of bytes captured from each packet.
- FCS: Frame Check Sequence. If `F` is set to true, FCS field provide the FCS that is added to the end of each packet.
- LinkType: The type of link he packets were captured.

# Packet Header

The packet header represents individual packet's information captured: (<u>1</u>)

![[pcap file packet header.png]]

- Timestamp (seconds): The number of seconds since 1970-01-01 00:00:00 UTC

---

# Reference

1. Wang Shie-Yuan. “Network Systems Capstone: Chapter 1: Tcpdump, Wireshark, tcpreplay, libpcap, and BPF.” NYCU ED202, February 27, 2024.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.