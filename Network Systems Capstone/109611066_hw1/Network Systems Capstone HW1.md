![[Pasted image 20240227221730.png]]

Above screenshot is the result of replaying `custom-packets.pcap`.

# 1. original packet - MAC and IP addresses: 20%

![[first-q.png]]

The above figure shows that the IP address of original packet is the same.

![[first-q-2.png]]

The above figure shows that the MAC address of original packet is the same.

# 2. modified packet - src MAC address: 15%

![[second-q.png]]

The above figure shows that the source MAC address is modified to `08:00:12:34:56:78`.

# 3. modified packet - dst MAC address: 15%

![[second-q.png]]

The above figure shows that the destination MAC address is modified to `08:00:12:34:ac:c2`.

# 4. modified packet - src IP address: 15%

![[fourth-q.png]]

The above figure shows that the source IP address is modified to `10.1.1.3`.

# 5. modified packet - dst IP address: 15%

![[fourth-q.png]]

The above figure shows that the destination IP address is modified to `10.1.1.4`.

# 6. time difference between modified packets: 20%

![[sixth-q.png]]

The times of the modified packets are `[41, 44, 49]`, which has time intervals `[3, 5]`.