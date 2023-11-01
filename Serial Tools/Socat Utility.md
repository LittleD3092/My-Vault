Tag: #serial-tools 
Previous: [[Serial Tools]]
Link: 

[TOC]

---

Socat is a tool for opening two virtual serial ports on computer. (<u>1</u>)

To **install** `socat`, run the following bash command: (<u>1</u>)

```bash
sudo apt-get install -y socat
```

To **establish** two serial ports, run the following bash command: (<u>1</u>)

```bash
socat -d -d pty,rawer,echo=0 pty,rawer,echo=0
```

This will establish two serial ports, with the paths printed on the terminal.

---

# Reference

1. Abdullah, Sidrah. “How to Create Virtual Serial Port in Linux | Baeldung on Linux,” May 12, 2023. https://www.baeldung.com/linux/make-virtual-serial-port.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.