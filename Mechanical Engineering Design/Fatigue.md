標籤: #Mechanical-Engineering-Design #list 

---

[TOC]

---

- Fatigue failure is not a consequence of changed material properties. Actually, fatigue failure is from a crack initiating and growing when subjected to many repeated cycles of stress.

Fatigue falure is due to crack nucleation and propagation.

- This is often at a discontinuity in the material, like
	- Geometric changes in cross section.
	- Manufacturing imperfections:
		- Stamp marks.
		- Tool marks.
		- Scratches.
	- Composition of the material itself.

# Stages of Fatigue Failure

A fatigue failure is characterized by three stages.

1. ==Stage I==
	- The initiation of one or more microcracks due to cyclic plastic deformation followed by crystallographic propagation extending from three to ten grains from the origin.
	- The cracks are not normally discernible to the naked eye.
2. ==Stage 2==
	- Progresses from microcracks to macrocracks forming parallel plateau-like fracture surfaces separated by longitudinal ridges.
	- The plateaus are generally smooth and normal to the direction of maximum tensile stress.
	- The surfaces are characterized by dark and light bands referred to as beach marks.
3. ==Stage 3==
	- Occurs during the final stress cycle when the material of the remaining cross section cannot support the loads, resulting in a sudden, fast fracture.
	- A stage III fracture can be brittle, ductile, or a combination of both.

# Crack Propagation

![[Pasted image 20221106164647.png|400]]

The above figure shows a representative graph of the crack nucleation, growth, and fracture on a plot of cycling stress amplitude versus the fatigue life in number of cycles.

- At higher stress levels a crack initiates quickly, and most of the fatigue life is used in growing the crack. This is ==low-cycle fatigue==.
- At lower stress levels a large fraction of the fatigue life is spent to nucleate a crack, followed by a quick crack growth. This is ==high-cycle fatigue==.

# Methods of Predicting Fatigue Failure

- Fatigue-Life Methods
	- [[Linear-Elastic Fracture Mechanics Method]]: Focus on crack propagation (stage II).
	- [[Strain-Life Method]]: Focus on crack nucleation (stage I).
	- [[Stress-Life Method]]: Merges all three stages together.
- [[Surface Fatigue]]

# Fatigue Design

Beside the methods of predicting fatigue failure, there are some design philosophies that provides strategies for safe designs.

## Infinite-Life Design

- Oldest strategy, by Wohler. 
- He discovered that steels have a stress level, referred to as a fatigue limit or endurance limit.
- Below the endurance limit, the cracks will not grow.
- Therefore, we may design for stresses that never exceed the endurance limit, and assume that it has infinite life.

## Safe-Life Design

- Designs for a finite life, less than a million cycles.
- Use both [[Strain-Life Method]] and [[Stress-Life Method]].

## Fail-Safe Design



---

參考資料:

Mechanical Engineering Design class
Mechanical Engineering Design, 11th edition

---

link:


---

This note is included in github repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.