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

|                                    | [[IPv4]]                                                                    | [[IPv6]]                                                                                                                                                                                                                       |
| ---------------------------------- | --------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| Datagram Format                    | ![[Pasted image 20221217150604.png]]                                        | ![[Pasted image 20221217144949.png]]                                                                                                                                                                                           |
| **Field introduced:**              |                                                                             |                                                                                                                                                                                                                                |
| Version                            | Note that putting a 4 in this field does not create a valid IPv4 datagram.  | Identifies the IP version number. IPv6 carries a value of 6 in this field.                                                                                                                                                     |
| Traffic Class                      | Like the TOS field in [[IPv4]].                                             | An 8-bit field, used to give priority to certain datagrams within a flow. <br> Or it can be used to give priority to datagrams from certain applications (voice-over IP) over datagrams from other applications (SMTP e-mail). |
| Flow Label                         |                                                                             | A 20-bit field. Used to identify a flow of datagrams.                                                                                                                                                                          |
| Payload Length                     | Like the `Datagram Length`.                                                 | A 16-bit value, an unsigned integer. Specify the number of bytes after 40-byte datagram header.                                                                                                                                |
| Next Header                        | Uses the same value as the `Upper-layer protocol` field.                    | Identifies the protocol to which the contents (data field) of this datagram will be delivered ([[TCP]] or [[UDP]]).                                                                                                            |
| Hop Limit                          | Act the same as field `Time-to-live`.                                       | Decremented by one by each router.                                                                                                                                                                                             |
| Source and Destination Addresses   |                                                                             | The formats are described in RFC 4291.                                                                                                                                                                                         |
| Data                               | Same as field `Data`.                                                       | The payload.                                                                                                                                                                                                                   |
|                                    |                                                                             |                                                                                                                                                                                                                                |
| **Fields that no longer present:** |                                                                             |                                                                                                                                                                                                                                |
| Fragmentation / reassembly         | The fields `Identifier`, `Flags`, `Fragmentation Offset` for fragmentation. | Does not allow fragmentation.                                                                                                                                                                                                  |
| Header Checksum                    | Has field `Header checksum` for detect bit errors.                          | Because [[Transport]] Layer performs checksum, it is removed.                                                                                                                                                                  |
| Options                            | Has field `Option` that allow IP header to be extended.                     | No longer a part of the standard IP header. However, `Next Header` field can be used for option purpose.                                                                                                                       |

# Transitioning from IPv4 to IPv6

Although IPv6 is capable for handling IPv4 datagrams, the opposite is not true. So how do we transition to IPv6?

- *Method 1*: We can shutdown all computer and upgrade. **This is a bad idea**.
- *Method 2*: **Tunneling**.

![[Pasted image 20221217155205.png]]

- In the above figure, `C` and `D` together is a **tunnel**.
- The IPv6 node `B` encapsulates the *entire* IPv6 datagram and puts it in the payload of IPv4 datagram.
	- The `Destination` is `E`.
	- The `Protocol` is `41` (indicating an IPv6 in the payload).
- The IPv6 node `E` receives the datagram, then decapsulates it.
	- `E` is the destination of IPv4 datagram.
	- The `Protocol` specify it is an IPv6 datagram in the payload.
	- From the two reasons above, node `E` decapsulates the datagram and forward it. 

---

參考資料:

Computer Networking, A Top-Down Approach, 8th edition

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.