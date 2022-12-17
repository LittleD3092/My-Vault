Tag: #computer-networks 
Previous: [[Internet Protocol]]
Link: 

---

[TOC]

---

- The [[IPv4]] addresses would be completely allocated, and hence no new networks could attach to the Internet.
- [[IPv6]] is for solving this problem.

# Datagram Format

![[Pasted image 20221217144949.png]]

The IPv6 introduces some important changes:

- *Expanded addressing capabilities*.
	- IPv6 increase the size of the IP address from 32 to 128 bits.
	- **Anycast address**: Allows a datagram to be delivered to any one of a group of hosts.
		- Example: It can be used to send an [[HTTP]] GET to the nearest of a number of mirror sites that contain a given document.
- *A streamlined 40-byte header*.
	- The fixed-length header allows for faster processing.
	- Some [[IPv4]] fields are made dropped or optional.
- *Flow labeling*.
	- A new term is invented: **flow**.
	- This feature allows "*labeling of packets belonging to particular flows for which the sender requests special handling, such as a non-default quality of service or real-time service*".
		- Audio and video transmition may be treated as a flow.
		- High-priority user might be treated as a flow.
		- The exact meaning of a flow had yet to be determined.

|                                        | [[IPv4]]                                                                    | [[IPv6]]                                                                                                                                                                                                                       |
| -------------------------------------- | --------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| Datagram Format                        | ![[Pasted image 20221217150604.png]]                                        | ![[Pasted image 20221217144949.png]]                                                                                                                                                                                           |
| New field introduced:                  |                                                                             |                                                                                                                                                                                                                                |
| Version                                | Note that putting a 4 in this field does not create a valid IPv4 datagram.  | Identifies the IP version number. IPv6 carries a value of 6 in this field.                                                                                                                                                     |
| Traffic Class                          | Like the TOS field in [[IPv4]].                                             | An 8-bit field, used to give priority to certain datagrams within a flow. <br> Or it can be used to give priority to datagrams from certain applications (voice-over IP) over datagrams from other applications (SMTP e-mail). |
| Flow Label                             |                                                                             | A 20-bit field. Used to identify a flow of datagrams.                                                                                                                                                                          |
| Payload Length                         | Like the `Datagram Length`.                                                 | A 16-bit value, an unsigned integer. Specify the number of bytes after 40-byte datagram header.                                                                                                                                |
| Next Header                            | Uses the same value as the `Upper-layer protocol` field.                    | Identifies the protocol to which the contents (data field) of this datagram will be delivered ([[TCP]] or [[UDP]]).                                                                                                            |
| Hop Limit                              | Act the same as field `Time-to-live`.                                       | Decremented by one by each router.                                                                                                                                                                                             |
| Source and Destination Addresses       |                                                                             | The formats are described in RFC 4291.                                                                                                                                                                                         |
| Data                                   | Same as field `Data`.                                                       | The payload.                                                                                                                                                                                                                   |
|                                        |                                                                             |                                                                                                                                                                                                                                |
| Fields that no longer present in IPv6: |                                                                             |                                                                                                                                                                                                                                |
| Fragmentation / reassembly             | The fields `Identifier`, `Flags`, `Fragmentation Offset` for fragmentation. | Does not allow fragmentation.                                                                                                                                                                                                  |
| Header Checksum                        |                                                                             |                                                                                                                                                                                                                                |

---

參考資料:

Computer Networking, A Top-Down Approach, 8th edition

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.