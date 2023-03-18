Tag: #digital-design #list 
Previous: [[Logic Circuits]]
Link: [[Logic Operations]]

[TOC]

---

| Name           | Representation          | Gate                                 |
| -------------- | ----------------------- | ------------------------------------ |
| AND Gate       | $A \text{ and } B = AB$ | ![[and gate.png]]                    |
| Logic Inverter | $\bar A$                | ![[logic inverter.png]]              |
| OR Gate        | $A + B$                 | ![[or gate.png]]                     |
| [[NAND]] Gate      | $\overline{AB}$         | ![[Pasted image 20230312174902.png]] |
| [[NOR]] Gate       | $\overline{(A + B)}$    | ![[Pasted image 20230312174948.png]] |
| XOR Gate       | $A \oplus B$            | ![[Pasted image 20230312175029.png]] |
| Buffer         | $A$                     | ![[Pasted image 20230312175054.png]]                                     |

# De Morgan's Laws

$$\overline{AB} = \overline A + \overline B$$

$$\overline{A + B} = \bar A \bar B$$

De Morgan's laws can be extended to three variables as follows:

$$\overline{ABC} = \overline A + \overline B + \overline C$$

$$\overline{A + B + C} = \overline A \, \overline B \, \overline C$$

---

參考資料:

Digital Design, 6th edition

---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.