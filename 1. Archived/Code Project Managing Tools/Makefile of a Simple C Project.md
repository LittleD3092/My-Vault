Tag: #code-project-managing-tool 
Previous: [[Makefile Utility Software]]
Link: 

[TOC]

---

A `Makefile` for a C project with `main.c` and `utils.c` can be written as (<u>1</u>):

```makefile
# Define variables
CC = gcc
CFLAGS = -Wall -Werror

# Define targets
all: program

program: main.o utils.o
	$(CC) $(CFLAGS) -o program main.o utils.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

utils.o: utils.c
	$(CC) $(CFLAGS) -c utils.c

clean:
	rm -f program *.o
```

Use `make` to compile target `all`, and `make clean` to clean compiled files (<u>1</u>).

---

# Reference

1. Github, Copilot. “What Is the Structure of a Makefile?,” October 24, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.