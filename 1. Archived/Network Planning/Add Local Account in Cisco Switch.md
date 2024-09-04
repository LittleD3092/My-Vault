Tag: #network-planning 
Previous: [[Network Planning]]
Link: 

---

To add a local account with MD5 hash function, first [[Enter Configure Terminal in Cisco Switch|enter configure terminal]]. Then: (<u>1</u>)

```
Switch(config)# username <username> secret <password>
```

This account will be prompted when trying to [[Enter Privileged EXEC Level in Cisco Switch|enter privileged mode]]. (<u>2</u>)

---

# Reference

1. 施羿廷. “Lab 3: Internetwork Operating System (IOS) and Packet Tracer.” NYCU EC324, February 23, 2024.
2. ChatGPT. “When Will the Switch Prompt to Use This Account?,” March 30, 2024.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.