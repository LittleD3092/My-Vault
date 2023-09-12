Tag: #operating-system 
Previous: [[Threads]]
Link: 

[TOC]

---

Implicit threading is a strategy that transfer the creation and management of threading from application developers to compilers and run-time libraries.

There are three approaches to use implicit threading:

- [[#Thread Pools]]
- [[#OpenMP]]
- [[#Grand Central Dispatch]]

# Thread Pools

Unlimited threads can exhaust system resources. To prevent this, we can use an approach called thread pools.

The idea of thread pools:

1. Create a number of threads at process startup and place them into a pool.
2. When a server receives a request, it awakens a thread from the pool.
3. The request is passed to the thread for service.
4. Once the thread completes its service, it returns to the pool.

# OpenMP

OpenMP is an API for programs written in C, C++, or Fortran that provides support for parallel programming in shared-memory environments.

An example of creating threads equals to the number of processing cores in the system:

```cpp
#include <omp.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    /* sequential code */

	#pragma omp parallel
	{
	    printf("I am a parallel region.");
	}

	/* sequential code */

	return 0;
}
```

An example of parallelizing loops:

```cpp
#pragma omp parallel for
for(i = 0; i < N; i++)
{
    c[i] = a[i] + b[i];
}
```

# Grand Central Dispatch

Grand Central Dispatch is a technology for Mac OS X and iOS.

It uses blocks to define a self-contained unit of work. An example of block:

```cpp
^{ printf("I am a block"); }
```

An example of obtaining a default-priority concurrent queue:

```cpp
dispatch_queue_t queue = dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0);

dispatch_async(queue, ^{ print("I am a block."); });
```

---

# Reference


---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.