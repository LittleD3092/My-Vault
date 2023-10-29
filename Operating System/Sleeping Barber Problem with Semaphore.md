Tag: #operating-system 
Previous: [[Semaphores for Process Synchronization]]
Link: 

[TOC]

---

There is a barber, and multiple customers. There are limited seats for customers to wait, and customers without a seat have to leave (<u>1</u>). How to solve this problem using semaphores?

The solution is the code below (<u>1</u>):

```cpp
// customer's process
while (1) {
	// mutex protect the number of available seats
	wait (accessSeats);

	// if any free seats
	if (NumberOfFreeSeats > 0) {
		// sitting down on a chair
		NumberOfFreeSeats--;

		// notify the barber
		signal(Customers);

		// release the lock
		signal(accessSeats);

		// wait if the barber is busy
		wait(Barber);

		// being cut hair...
	}
}

// barber's process
while (1) {
	// wait for customer and sleep
	wait (Customers);

	// mutex protect the number of available seats
	wait (accessSeats);

	// one chair gets free
	NumberOfFreeSeats++;

	// bring in a customer for haircut
	signal (Barber);

	// release the mutex on the chairs
	signal (accessSeats);

	// barber cutting hair...
}
```

---

# Reference

1. 張立平. “Introduction to Operating Systems, Chapter 6: Synchronization, Part 4.” NYCU EC122[GF], October 25, 2023.

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.