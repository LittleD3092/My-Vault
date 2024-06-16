# VM

1. Install 3 vms
2. Vm network configurations
   1. playground: NAT
   2. nuclear: Internal network, name: internal
   3. entry: 
      1. Interface 1: bridged, MAC address match on router's DHCP, should be `0800279A34A2`.
      2. Interface 2: Internal network, name: internal

# entry setup

```sh
sudo ip address add 192.168.131.1/24 dev enp0s8
sudo ip link set dev enp0s8 up
sudo sysctl -w net.ipv4.ip_forward=1
sudo iptables -t nat -A POSTROUTING -o enp0s3 -j MASQUERADE
ssh 192.168.131.2 -L 0.0.0.0:2222:localhost:22 -Nf
```

# nuclear setup

```sh
sudo ip address add 192.168.131.2/24 dev enp0s3
sudo ip link set dev enp0s3 up
sudo ip route add default via 192.168.131.1
```

# Requirement - SSH

## WAN to entry:

```sh
ssh ccna@<router-ip>
```

## host to playground:

```sh
ssh ccna@localhost
```

## host to nuclear:

```sh
ssh -J ccna@<router-ip> ccna@192.168.131.2
```

## WAN to playground:

Set on host first:

```sh
ssh ccna@localhost -L 0.0.0.0:2222:localhost:22 -Nf
```

Then on WAN, connect to the VPN and use the following command to connect to the playground:

```sh
ssh ccna@192.168.87.10 -p 2222
```

## WAN to nuclear:

```sh
ssh ccna@<router-ip> -p 2222
```