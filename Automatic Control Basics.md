標籤: #automatic-control

---

[TOC]

---

# Control System

A control system has a structure like so:

![[control system - automatic control basics.png|500]]

- Plant: Physical object to be controlled.
- Control Variables: The quantity or conditions that is measured or controlled.
- Control Signal (input): The quantity or condition varied by the controller so as to affect the values of control variables.
- Disturbance: A signal that tends to adversely affect the output of a system. There are internal disturbance and external disturbance.
	- Internal disturbance: disturbance generated inside the system.
	- External disturbance: disturbance generated outside the system.

# Feedback Control

![[feed back control - automatic control basics.png|550]]

Feedback control tends to reduce the difference between the output of a system and some reference input, and does so on the basis of this difference.

# Close-loop control v.s. Open-loop control

Close-loop control is [[#Feedback Control]], and the output of close-loop control has effect on the control action. 

The output of open-loop control has NO effect on the control action.

The chart below shows the comparison between close-loop control and open-loop control:

|                    | Cost   | Stability | Sensitivity to disturbance |
| ------------------ | ------ | --------- | -------------------------- |
| Close loop control | lower  | better    | better                     |
| Open loop control  | higher | worse     | worse                      | 

# Designing a control system

A control system is usually designed following the steps:

1. Set up mathematical model of the control system.
2. Adjust the parameters of the controller and check if the performance is within the specifications.
3. Build a proto-type system to verify the open loop performance, close-loop performance, stability, and disturbance effect.

---

參考資料:

Automatic Control class

---

link:

Next: [[Mathematical Modeling of Control Systems]]