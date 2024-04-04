Tag: #network-planning 
Previous: [[Network Planning]]
Link: 

---

To set an enable password on Cisco switch, first [[Enter Configure Terminal in Cisco Switch|enter config mode]]. Then: (<u>1</u>)

```
switch(config)# enable secret <password>
```

This will use MD5 encryption on the password. (<u>1</u>)

---

# Reference

1. 施羿廷. “Lab 3: Internetwork Operating System (IOS) and Packet Tracer.” NYCU EC324, February 23, 2024.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.