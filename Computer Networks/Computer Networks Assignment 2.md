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

## a.

| Prefix              | Link Interface |
| ------------------- | -------------- |
| `11100000 00000000` | `0`            |
| `11100000 00000001` | `1`            |
| `1110000`  | `2`            |
| Otherwise           | `3`            |

## b.

- `11111000 10010001 01010001 01010101`: Since it does not match any of the prefix, it goes to link interface `3`.
- `11100000 00000000 11000011 00111100`: It matches 1st and 3rd entry. The longest prefix is the 1st one, therefore it goes to link interface `0`.
- `11100001 10000000 00010001 01110111`: It matches 3rd entry, so it goes to link interface `2`.

# P16

The subnet has the beginning 26 bits fixed, meaning that the last 8 bits must be `10xxxxxx`. Therefore the range of the addresses is `192.168.56.128` to `192.168.56.192`.

==One example is `192.168.56.128`.==

For the block of addresses `192.168.56.32/27`, the last 8 bits must be `001xxxxx`. Therefore the range of the addresses is `192.168.56.32` to `192.168.56.63`, having a total of `32` addresses.

Dividing the `32` addresses for 4 subnets, each can get `8` addresses. The addresses of the 4 subnets are:

- Subnet 1: `192.168.56.32` to `192.168.56.39`
- Subnet 2: `192.168.56.40` to `192.168.56.47`
- Subnet 3: `192.168.56.48` to `192.168.56.55`
- Subnet 4: `192.168.56.56` to `192.168.56.63`

Therefore the prefixes are

- ==Subnet 1: `192.168.56.32/29`==
- ==Subnet 2: `192.168.56.40/29`==
- ==Subnet 3: `192.168.56.48/29`==
- ==Subnet 4: `192.168.56.56/29`==

# P19

For a 1600-byte datagram, we have actual data of 1580 bytes. 

The link has an MTU of 500 bytes, so the maximum data size that is permissible to be sent is 480 bytes.

So, there would be ==4 fragments==:

1. data size = 480 bytes, ==offset = 0==, and MF ==flag = 1==
2. data size = 480 bytes, ==offset = 60==, and MF ==flag = 1==
3. data size = 480 bytes, ==offset = 120==, and MF ==flag = 1==
4. data size = 140 bytes, ==offset = 180==, and MF ==flag = 0==

The identification number will be the same which is ==291==.

The fields listed below is also changed:

- The ==total length== is changed to the size of the fragment (==500, 500, 500, 160==).
- The ==header checksum== is re-calculated.

# P28

| k   | u        | v   | x   | y        | z   |
| --- | -------- | --- | --- | -------- | --- |
| 1   | $\infty$ | 6   | 2   | $\infty$ | 0   |
| 2   | 7        |     |     |          |     |
| 3   |          |     |     |          |     |
| 4   |          |     |     |          |     |

# P29

