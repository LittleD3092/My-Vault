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

# Reference

1. [[Save Cisco Switch Configuration]]
2. [[Set Hostname of a Cisco Switch]]
3. HackMD. “112 CCNA Project 2.” Accessed March 30, 2024. https://hackmd.io/@SiriusKoan/HJrjl4l1R.
4. [[Add Local Account in Cisco Switch]]
5. [[Set Console Login in Cisco Switch]]
6. [[Set Enable Password on Cisco Switch]]