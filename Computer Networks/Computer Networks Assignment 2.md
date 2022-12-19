Tag: #computer-networks 

---

# P6

The DHCP servers have no secure mechanism for the authentication of the client. Unauthorized clients can be given IP address and IP address depletion can happen.

# P7

## a.

No. For a shared bus, only one packet can cross the bus at the same time.

## b.

Yes, multiple packets can be forwarded at the same time if their output ports are different.

## c.

No. If two packets from two different input has the same output port, then one will have to wait.

# P10

#TODO

| Prefix              | Link Interface |
| ------------------- | -------------- |
| `11100000 00000000` | `0`            |
| `11100000 00000001` | `1`            |
| `1110000`  | `2`            |
| Otherwise           | `3`            |

# P16

The subnet has the beginning 26 bits fixed, meaning that the last 8 bits must be `10xxxxxx`. Therefore the range of the addresses is `192.168.56.128` to `192.168.56.192`.

==One example is `192.168.56.128`.==

