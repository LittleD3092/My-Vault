Tag: #operating-system 
Previous: [[Interprocess Communication]]
Link: 

[TOC]

---

- A **producer** sends data.
- A **consumer** consumes data.
- The shared memory is a buffer for sending and receiving data.
- Note that the producer and the consumer must be synchronized.

# Example Code

The definition:

```cpp
#define BUFFER_SIZE 10
typedef struct
{
    ...
} item;

item buffer[BUFFER_SIZE];
int in = 0;
int out = 0;
```

The producer process using shared memory:

```cpp
item next_produced;

while(true)
{
    /* produce an item in next_produced */

	while(((in + 1) % BUFFER_SIZE) == out)
		; // do nothing

	buffer[in] = next_produced;
	in = (in + 1) % BUFFER_SIZE;
}
```

The consumer process using shared memory:

```cpp
item next_consumed;

while(true)
{
    while(in == out)
	    ; // do nothing

	next_consumed = buffer[out];
	out = (out + 1) % BUFFER_SIZE;

	/* consume the item in next_consumed */
}
```

---

# Reference

Operating System Concepts, 9th edition

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.