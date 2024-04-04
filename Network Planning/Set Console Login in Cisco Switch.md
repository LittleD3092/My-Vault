Tag: #network-planning 
Previous: [[Network Planning]]
Link: 

---

To set console login in Cisco Switch, first [[Add Local Account in Cisco Switch|add a local account]]. Then, set the local account as the login method for `console 0`: (<u>1</u>)

```
Switch(config)# line console 0
Switch(config-line)# login local
Switch(config-line)#
```

---

# Reference

1. 施羿廷. “Lab 3: Internetwork Operating System (IOS) and Packet Tracer.” NYCU EC324, February 23, 2024.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.