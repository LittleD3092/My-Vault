# 1. Save configuration

This section is for reminding the saving process. Following section will not contain the saving process, but it is recommended to save the configuration after making any changes.

To save configuration to startup configuration: (<u>1</u>)

```
write memory
```

# 2. Switch Basic Setting

This section applies to all six switches listed below:

- CSCC-PCRoom-Sw
- CSCC-Lab1-Sw
- CSCC-Lab2-Sw
- CSCC-intranet-Sw
- CS-Core
- EC321-Sw

## 2.1. Set the hostname to the name of the tag

To set the hostname of a switch: (<u>2</u>)

```
switch(config)# hostname <new-hostname>
```

## 2.2. Add a local account

The local account has the following requirements: (<u>3</u>)

- Account: `ccna`
- Passworkd: `ccna`
- Use md5 to save the credentials
- Set login console for `CS-Core`

To add a local account: (<u>4</u>)

```
switch(config)# username <username> secret <password>
```

To set login for `console 0` on `CS-Core`: (<u>5</u>)

```
CS-Core(config)# line console 0
CS-Core(config-line)# login local
CS-Core(config-line)#
```

## 2.3. Set Enable Password

This section requires us to set the enable password `project2` with MD5 encryption. (<u>3</u>)

To set the enable password: (<u>6</u>)

```
switch(config)# enable secret <password>
```

## 2.4. Set SSH

Requirements: (<u>3</u>)

- Use `cs.nycu.edu.tw` as domain name
- Modulus length: `2048`
- Version: `2`
- Use ssh only, disable telnet for all vtys

```
switch(config)# ip domain-name cs.nycu.edu.tw

switch(config)# crypto key generate rsa general-keys modulus 2048

switch(config)# ip ssh version 2

switch(config)# line vty 0 15
switch(config-line)# transport input ssh
switch(config-line)# login local

switch(config-line)# exit
switch(config)# exit
switch# write memory
```

## 2.5. Disable unused interface

Do the following for each unused interface:

```
switch(config)# interface <port-type> <port-number>
switch(config-if)# shutdown
switch(config-if)# exit
switch(config)# exit
switch# write memory
```

More specifically:

- For `CSCC-PCRoom-Sw`:

```
switch(config)# interface range Fa 0/3 - 10 , Fa 0/13 - 19 , Fa 0/21 - 24 , Gi 0/2
switch(config-if-range)# shutdown
switch(config-if-range)# exit
switch(config)# exit
switch# write memory
```

- For `CSCC-Lab1-Sw`:

```
switch(config)# interface range Fa 0/3 - 24 , Gi 0/2
switch(config-if-range)# shutdown
switch(config-if-range)# exit
switch(config)# exit
switch# write memory
```

- For `CSCC-Lab2-Sw`:

```
switch(config)# interface range Fa 0/2 - 24
switch(config-if-range)# shutdown
switch(config-if-range)# exit
switch(config)# exit
switch# write memory
```

- For `CSCC-intranet-Sw`:

```
switch(config)# interface range Fa 0/3 - 24
switch(config-if-range)# shutdown
switch(config-if-range)# exit
switch(config)# exit
switch# write memory
```

- For `CS-Core`:

```
switch(config)# interface range Gi 1/0/5 - 23 , Gi 1/1/1 - 4
switch(config-if-range)# shutdown
switch(config-if-range)# exit
switch(config)# exit
switch# write memory
```

- For `EC321-Sw`:

```
switch(config)# interface range Fa 0/3 - 24 , Gi 0/1 - 2
switch(config-if-range)# shutdown
switch(config-if-range)# exit
switch(config)# exit
switch# write memory
```

## 2.6. Disable cdp for edge devices

- Only set no cdp for downward devices. Do not set as default.
- To NYCU IT is NOT an edge device, since it is a upward device.

Commands:

- For `CSCC-PCRoom-Sw`:

```
CSCC-PCRoom-Sw(config)# interface range Fa 0/1 - 2 , Fa 0/11 - 12 , Fa 0/20
CSCC-PCRoom-Sw(config-if-range)# no cdp enable
CSCC-PCRoom-Sw(config-if-range)# exit
CSCC-PCRoom-Sw(config)# exit
CSCC-PCRoom-Sw# write memory
```

- For `CSCC-Lab1-Sw`:

```
CSCC-Lab1-Sw(config)# interface range Fa 0/1 - 2
CSCC-Lab1-Sw(config-if-range)# no cdp enable
CSCC-Lab1-Sw(config-if-range)# exit
CSCC-Lab1-Sw(config)# exit
CSCC-Lab1-Sw# write memory
```

- For `CSCC-Lab2-Sw`:

```
CSCC-Lab2-Sw(config)# interface range Fa 0/1
CSCC-Lab2-Sw(config-if-range)# no cdp enable
CSCC-Lab2-Sw(config-if-range)# exit
CSCC-Lab2-Sw(config)# exit
CSCC-Lab2-Sw# write memory
```

- For `CSCC-intranet-Sw`:

```
CSCC-intranet-Sw(config)# interface range Fa 0/1 - 2
CSCC-intranet-Sw(config-if-range)# no cdp enable
CSCC-intranet-Sw(config-if-range)# exit
CSCC-intranet-Sw(config)# exit
CSCC-intranet-Sw# write memory
```

- For `EC321-Sw`:

```
EC321-Sw(config)# interface Fa 0/2
EC321-Sw(config-if)# no cdp enable
EC321-Sw(config-if)# exit
EC321-Sw(config)# exit
EC321-Sw# write memory
```

# 3. VLAN setting

Requirements:

- Naming:
	- Lab1: `VLAN101`
	- Lab2-1 & Lab2-2: `VLAN102`
	- Management: `VLAN30`
	- 324: `VLAN324`
	- 316: `VLAN316`
	- 321: `VLAN321`
- Links between switches are trunk.
- For each trunk, only allow minimum VLAN.

Commands:

- For `CSCC-PCRoom-Sw`:

```
CSCC-PCRoom-Sw(config)# vlan 324
CSCC-PCRoom-Sw(config-vlan)# name VLAN324
CSCC-PCRoom-Sw(config-vlan)# exit
CSCC-PCRoom-Sw(config)# interface range Fa 0/1 - 2
CSCC-PCRoom-Sw(config-if-range)# switchport mode access
CSCC-PCRoom-Sw(config-if-range)# switchport access vlan 324
CSCC-PCRoom-Sw(config-if-range)# exit

CSCC-PCRoom-Sw(config)# vlan 316
CSCC-PCRoom-Sw(config-vlan)# name VLAN316
CSCC-PCRoom-Sw(config-vlan)# exit
CSCC-PCRoom-Sw(config)# interface range Fa 0/11 - 12
CSCC-PCRoom-Sw(config-if-range)# switchport mode access
CSCC-PCRoom-Sw(config-if-range)# switchport access vlan 316
CSCC-PCRoom-Sw(config-if-range)# exit

CSCC-PCRoom-Sw(config)# vlan 30
CSCC-PCRoom-Sw(config-vlan)# name VLAN30
CSCC-PCRoom-Sw(config-vlan)# exit
CSCC-PCRoom-Sw(config)# vlan 321
CSCC-PCRoom-Sw(config-vlan)# name VLAN321
CSCC-PCRoom-Sw(config-vlan)# exit
CSCC-PCRoom-Sw(config)# interface Fa 0/20
CSCC-PCRoom-Sw(config-if)# switchport trunk native vlan 321
CSCC-PCRoom-Sw(config-if)# switchport trunk allowed vlan 30,321
CSCC-PCRoom-Sw(config-if)# switchport mode trunk
CSCC-PCRoom-Sw(config-if)# exit

CSCC-PCRoom-Sw(config)# interface Gi 0/1
CSCC-PCRoom-Sw(config-if)# switchport trunk allowed vlan 324,316,321,30
CSCC-PCRoom-Sw(config-if)# switchport mode trunk
CSCC-PCRoom-Sw(config-if)# exit
CSCC-PCRoom-Sw(config)# exit

CSCC-PCRoom-Sw# write memory
```

- `CSCC-Lab1-Sw`:

```
CSCC-Lab1-Sw(config)# vlan 101
CSCC-Lab1-Sw(config-vlan)# name VLAN101
CSCC-Lab1-Sw(config-vlan)# exit
CSCC-Lab1-Sw(config)# interface Fa 0/1
CSCC-Lab1-Sw(config-if)# switchport mode access
CSCC-Lab1-Sw(config-if)# switchport access vlan 101
CSCC-Lab1-Sw(config-if)# exit

CSCC-Lab1-Sw(config)# vlan 102
CSCC-Lab1-Sw(config-vlan)# name VLAN102
CSCC-Lab1-Sw(config-vlan)# exit
CSCC-Lab1-Sw(config)# interface Fa 0/2
CSCC-Lab1-Sw(config-if)# switchport mode access
CSCC-Lab1-Sw(config-if)# switchport access vlan 102
CSCC-Lab1-Sw(config-if)# exit

CSCC-Lab1-Sw(config)# vlan 30
CSCC-Lab1-Sw(config-vlan)# name VLAN30
CSCC-Lab1-Sw(config-vlan)# exit
CSCC-Lab1-Sw(config)# interface Gi 0/1
CSCC-Lab1-Sw(config-if)# switchport trunk allowed vlan 101,102,30
CSCC-Lab1-Sw(config-if)# switchport mode trunk
CSCC-Lab1-Sw(config-if)# exit
CSCC-Lab1-Sw(config)# exit

CSCC-Lab1-Sw# write memory
```

- `CSCC-Lab2-Sw`:

```
CSCC-Lab2-Sw(config)# vlan 102
CSCC-Lab2-Sw(config-vlan)# name VLAN102
CSCC-Lab2-Sw(config-vlan)# exit
CSCC-Lab2-Sw(config)# interface Fa 0/1
CSCC-Lab2-Sw(config-if)# switchport mode access
CSCC-Lab2-Sw(config-if)# switchport access vlan 102
CSCC-Lab2-Sw(config-if)# exit

CSCC-Lab2-Sw(config)# vlan 30
CSCC-Lab2-Sw(config-vlan)# name VLAN30
CSCC-Lab2-Sw(config-vlan)# exit
CSCC-Lab2-Sw(config)# interface range Gi 0/1 - 2
CSCC-Lab2-Sw(config-if-range)# switchport trunk allowed vlan 102,30
CSCC-Lab2-Sw(config-if-range)# switchport mode trunk
CSCC-Lab2-Sw(config-if-range)# exit

CSCC-Lab2-Sw# write memory
```

- `CSCC-intranet-Sw`:

```
CSCC-intranet-Sw(config)# vlan 102
CSCC-intranet-Sw(config-vlan)# name VLAN102
CSCC-intranet-Sw(config-vlan)# exit
CSCC-intranet-Sw(config)# interface Fa 0/1
CSCC-intranet-Sw(config-if)# switchport mode access
CSCC-intranet-Sw(config-if)# switchport access vlan 102
CSCC-intranet-Sw(config-if)# exit

CSCC-intranet-Sw(config)# vlan 30
CSCC-intranet-Sw(config-vlan)# name VLAN30
CSCC-intranet-Sw(config-vlan)# exit
CSCC-intranet-Sw(config)# interface Fa 0/2
CSCC-intranet-Sw(config-if)# switchport mode access
CSCC-intranet-Sw(config-if)# switchport access vlan 30
CSCC-intranet-Sw(config-if)# exit

CSCC-Lab2-Sw(config)# interface Gi 0/1
CSCC-Lab2-Sw(config-if)# switchport trunk allowed vlan 102,30
CSCC-Lab2-Sw(config-if)# switchport mode trunk
CSCC-Lab2-Sw(config-if)# exit

CSCC-Lab2-Sw(config)# interface Gi 0/2
CSCC-Lab2-Sw(config-if)# switchport trunk allowed vlan 102,30
CSCC-Lab2-Sw(config-if)# switchport mode trunk
CSCC-Lab2-Sw(config-if)# exit
CSCC-Lab2-Sw(config)# exit

CSCC-intranet-Sw# write memory
```

- `EC321-Sw`:

```
EC321-Sw(config)# vlan 321
EC321-Sw(config-vlan)# name VLAN321
EC321-Sw(config-vlan)# exit
EC321-Sw(config)# vlan 30
EC321-Sw(config-vlan)# name VLAN30
EC321-Sw(config-vlan)# exit

EC321-Sw(config)# interface Fa 0/2
EC321-Sw(config-if)# switchport access vlan 321
EC321-Sw(config-if)# switchport mode access
EC321-Sw(config-if)# exit

EC321-Sw(config)# interface Fa 0/1
EC321-Sw(config-if)# switchport trunk native vlan 321
EC321-Sw(config-if)# switchport trunk allowed vlan 30,321
EC321-Sw(config-if)# switchport mode trunk
EC321-Sw(config-if)# exit
EC321-Sw(config)# exit

EC321-Sw# write memory
```

- `CS-Core`:

```
CS-Core(config)# vlan 30
CS-Core(config-vlan)# name VLAN30
CS-Core(config-vlan)# exit

CS-Core(config)# vlan 324
CS-Core(config-vlan)# name VLAN324
CS-Core(config-vlan)# exit
CS-Core(config)# vlan 316
CS-Core(config-vlan)# name VLAN316
CS-Core(config-vlan)# exit
CS-Core(config)# vlan 321
CS-Core(config-vlan)# name VLAN321
CS-Core(config-vlan)# exit
CS-Core(config)# interface Gi 1/0/4
CS-Core(config-if)# switchport trunk allowed vlan 324,316,321,30
CS-Core(config-if)# switchport mode trunk
CS-Core(config-if)# exit

CS-Core(config)# vlan 101
CS-Core(config-vlan)# name VLAN101
CS-Core(config-vlan)# exit
CS-Core(config)# vlan 102
CS-Core(config-vlan)# name VLAN102
CS-Core(config-vlan)# exit
CS-Core(config)# interface Gi 1/0/1
CS-Core(config-if)# switchport trunk allowed vlan 101,102,30
CS-Core(config-if)# switchport mode trunk
CS-Core(config-if)# exit

CS-Core(config)# interface Gi 1/0/2
CS-Core(config-if)# switchport trunk allowed vlan 102,30
CS-Core(config-if)# switchport mode trunk
CS-Core(config-if)# exit

CS-Core(config)# interface Gi 1/0/3
CS-Core(config-if)# switchport trunk allowed vlan 102,30
CS-Core(config-if)# switchport mode trunk
CS-Core(config-if)# exit

CS-Core(config)# interface Gi 1/0/24
CS-Core(config-if)# switchport trunk allowed vlan 324,316,321,101,102,30
CS-Core(config-if)# switchport mode trunk
CS-Core(config-if)# exit
CS-Core(config)# exit

CS-Core# write memory
```

# 4. Switch IP Address & Gateway

Commands:

- For `CSCC-PCRoom-Sw`:

```
CSCC-PCRoom-Sw(config)# vlan 30
CSCC-PCRoom-Sw(config-vlan)# name VLAN30
CSCC-PCRoom-Sw(config-vlan)# exit
CSCC-PCRoom-Sw(config)# interface vlan 30
CSCC-PCRoom-Sw(config-if)# ip address 140.113.10.10 255.255.255.0
CSCC-PCRoom-Sw(config-if)# no shutdown
CSCC-PCRoom-Sw(config-if)# exit
CSCC-PCRoom-Sw(config)# ip default-gateway 140.113.10.254
CSCC-PCRoom-Sw(config)# exit
CSCC-PCRoom-Sw# write memory
```

- For `CSCC-intranet-Sw`:

```
CSCC-intranet-Sw(config)# vlan 30
CSCC-intranet-Sw(config-vlan)# name VLAN30
CSCC-intranet-Sw(config-vlan)# exit
CSCC-intranet-Sw(config)# interface vlan 30
CSCC-intranet-Sw(config-if)# ip address 140.113.10.11 255.255.255.0
CSCC-intranet-Sw(config-if)# no shutdown
CSCC-intranet-Sw(config-if)# exit
CSCC-intranet-Sw(config)# ip default-gateway 140.113.10.254
CSCC-intranet-Sw(config)# exit
CSCC-intranet-Sw# write memory
```

- For `CSCC-Lab1-Sw`:

```
CSCC-Lab1-Sw(config)# vlan 30
CSCC-Lab1-Sw(config-vlan)# name VLAN30
CSCC-Lab1-Sw(config-vlan)# exit
CSCC-Lab1-Sw(config)# interface vlan 30
CSCC-Lab1-Sw(config-if)# ip address 140.113.10.12 255.255.255.0
CSCC-Lab1-Sw(config-if)# no shutdown
CSCC-Lab1-Sw(config-if)# exit
CSCC-Lab1-Sw(config)# ip default-gateway 140.113.10.254
CSCC-Lab1-Sw(config)# exit
CSCC-Lab1-Sw# write memory
```

- For `CSCC-Lab2-Sw`:

```
CSCC-Lab2-Sw(config)# vlan 30
CSCC-Lab2-Sw(config-vlan)# name VLAN30
CSCC-Lab2-Sw(config-vlan)# exit
CSCC-Lab2-Sw(config)# interface vlan 30
CSCC-Lab2-Sw(config-if)# ip address 140.113.10.13 255.255.255.0
CSCC-Lab2-Sw(config-if)# no shutdown
CSCC-Lab2-Sw(config-if)# exit
CSCC-Lab2-Sw(config)# ip default-gateway 140.113.10.254
CSCC-Lab2-Sw(config)# exit
CSCC-Lab2-Sw# write memory
```

- For `EC321-Sw`:

```
EC321-Sw(config)# vlan 30
EC321-Sw(config-vlan)# name VLAN30
EC321-Sw(config-vlan)# exit
EC321-Sw(config)# interface vlan 30
EC321-Sw(config-if)# ip address 140.113.10.14 255.255.255.0
EC321-Sw(config-if)# no shutdown
EC321-Sw(config-if)# exit
EC321-Sw(config)# ip default-gateway 140.113.10.254
EC321-Sw(config)# exit
EC321-Sw# write memory
```

- For `CS-Core`:

```
CS-Core(config)# interface vlan 30
CS-Core(config-if)# ip address 140.113.10.254 255.255.255.0
CS-Core(config-if)# exit

CS-Core(config)# interface vlan 101
CS-Core(config-if)# ip address 140.113.20.1 255.255.255.224
CS-Core(config-if)# exit

CS-Core(config)# interface vlan 102
CS-Core(config-if)# ip address 140.113.20.33 255.255.255.224
CS-Core(config-if)# exit

CS-Core(config)# interface vlan 324
CS-Core(config-if)# ip address 140.113.24.254 255.255.255.0
CS-Core(config-if)# exit

CS-Core(config)# interface vlan 316
CS-Core(config-if)# ip address 140.113.16.254 255.255.255.0
CS-Core(config-if)# exit

CS-Core(config)# interface vlan 321
CS-Core(config-if)# ip address 140.113.21.254 255.255.255.0
CS-Core(config-if)# exit
CS-Core(config)# ip routing
CS-Core(config)# exit
CS-Core# write memory
```

# 5. STP

## 5.1. Set rapid-pvst

For each switch, use `rapid-pvst`:

```
Switch(config)# spanning-tree mode rapid-pvst
```

## 5.2. Portfast

For `CSCC-PCRoom-Sw`:

```
interface range Fa 0/1 - 2 , Fa 0/11 - 12 , Fa 0/20
spanning-tree portfast
exit
exit
write memory
```

For `CSCC-Lab1-Sw`:

```
interface range Fa 0/1 - 2
spanning-tree portfast
exit
exit
write memory
```

For `CSCC-Lab2-Sw`:

```
interface Fa 0/1
spanning-tree portfast
exit
exit
write memory
```

For `CSCC-intranet-Sw`:

```
interface range Fa 0/1 - 2
spanning-tree portfast
exit
exit
write memory
```

For `EC321-Sw`:

```
interface Fa 0/2
spanning-tree portfast
exit
exit
write memory
```

## 5.3. BPDU Guard

For `CSCC-PCRoom-Sw`:

```
interface range Fa 0/1 - 2 , Fa 0/11 - 12 , Fa 0/20
spanning-tree bpduguard enable
exit
exit
write memory
```

For `CSCC-Lab1-Sw`:

```
interface range Fa 0/1 - 2
spanning-tree bpduguard enable
exit
exit
write memory
```

For `CSCC-Lab2-Sw`:

```
interface Fa 0/1
spanning-tree bpduguard enable
exit
exit
write memory
```

For `CSCC-intranet-Sw`:

```
interface range Fa 0/1 - 2
spanning-tree bpduguard enable
exit
exit
write memory
```

For `EC321-Sw`:

```
interface range Fa 0/1 - 2
spanning-tree bpduguard enable
exit
exit
write memory
```

## 5.4. Set root

For `CS-Core`, in configure terminal:

```
spanning-tree vlan 1,30,101,102,316,321,324 root primary
```

# 6. CS-Core

## 6.1. Set default route

For `CS-Core`, in configure terminal:

```
ip route 0.0.0.0 0.0.0.0 140.113.1.1
```

## 6.2. Upstream interface

For `CS-Core`, in configure terminal:

```
interface Gi 1/0/24
no switchport
ip address 140.113.1.2 255.255.255.252
lldp transmit
lldp receive
no shutdown
exit
ip default-gateway 140.113.1.1
exit
write memory
```

# Reference

1. [[Save Cisco Switch Configuration]]
2. [[Set Hostname of a Cisco Switch]]
3. HackMD. “112 CCNA Project 2.” Accessed March 30, 2024. https://hackmd.io/@SiriusKoan/HJrjl4l1R.
4. [[Add Local Account in Cisco Switch]]
5. [[Set Console Login in Cisco Switch]]
6. [[Set Enable Password on Cisco Switch]]