Tag: #operating-system 
Previous: [[Process]]
Link: 

[TOC]

---

As a process executes, it changes **state**.

A process may be in one of the following states:

- **New**: The process is being created.
- **Running**: Instructions are being executed.
- **Waiting**: The process is waiting for some event to occur.
- **Ready**: The process is waiting to be assigned to a processor.
- **Terminated**: The process has finished execution.

> Note: The names of states vary between systems, but these states are common.

The [[State Diagram|state diagram]] corresponding to the states:

```mermaid
flowchart TD

new["new"]
ready["ready"]
waiting["waiting"]
running["running"]
terminated["terminated"]

new --"admitted"--> ready
ready --"scheduler dispatch"-->running
running --"exit"--> terminated
running --"interrupt"--> ready
running --"I/O or event wait" --> waiting
waiting --"I/O or event completion"--> ready
```

---

# Reference

1. 

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.