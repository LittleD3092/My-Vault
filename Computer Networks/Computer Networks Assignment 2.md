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
| 2   | 7        | 5   | 2   | 5        | 0   |
| 3   | 6        | 5   | 2   | 5        | 0   |
| 4   | 6        | 5   | 2   | 5        | 0   |

The distance table entries at node z is:

|          | u   | v   | x   | y   |
| -------- | --- | --- | --- | --- |
| distance | 6   | 5   | 2   | 5   | 

# P29

Assume that a network has $n$ nodes, the maximum number of iterations is $n - 1$.

Note that for distance-vector algorithm, only the neighbors are updated. Assume that we are finding the distance from $s$ and $d[u]$ means the distance between $u$ and $s$ after $i$ iterations. After $i$ iterations:

- If $d[u]$ is not $\infty$, then there exists a path of length $d[u]$ from $s$ to $u$.
- If there is a path from $s$ to $u$ with at most $i$ edges, then $d[u]$ is the length of the shortest path with at most $i$ edges.

Since the edges from $s$ to $u$ can only have a maximum number of $n - 1$, the two guarantees imply that after $n - 1$ iterations, the shortest path is found.

# P41

- Congestion control is used by a network to control congestion in the network, and flow control is used by sender and receiver to control the traffic between them. 
- Congestion control solves packet drops along the path, and flow control prevent receiver's buffer from overflow.
- A variable `Receive Window` is used at the sender side.

# P44

## a.

Since `cwnd` increases by 1 per RTT, it takes `6` RTT for `cwnd` to increase from 6 MSS to 12 MSS.

## b.

The average throughout is

$$\frac{0.75 \cdot 12 {\ \rm MSS}}{6\ {\rm RTT}} = \underline{\frac{1.5 {\ \rm MSS}}{{\rm RTT}}}_\#$$

# R18

The five PCs are assigned IP addresses via DHCP protocol.

1. The connecting PC uses a DHCP discover message to discover the DHCP server.
2. The DHCP servers responds the DHCP discover with a DHCP offer message.
3. The PC will request one of the servers using a DHCP request message.
4. The server will respond to the DHCP request using a DHCP ACK message.

The router is only assigned one IP address, therefore NAT is required for five PCs to connect. The IP addresses assigned to the five PCs are provided by the NAT-enabled router.