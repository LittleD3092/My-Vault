Tag: #operating-system 
Previous: [[Process]]
Link: 

[TOC]

---

This section lists some operations and the details of them.

# Process Creation

- The creating process is called a parent process.
- The new processes created is called the children process.
- This can create a [[Tree|tree]] structure.
- Most operating systems identify processes by their **process identifier (pid)**.

![[Pasted image 20230628204721.png]]

- `init`:
	- Always has a pid of 1.
	- The root process for all user processes.
- `kthreadd`:
	- Responsible for creating additional processes that perform tasks on behalf of the kernel.
- `sshd`:
	- Responsible for managing clients that connect to the system by [[Secure Shell|ssh]].
- `login`:
	- Responsible for managing clients that directly log onto the system.
	- In the graph above, user use `bash` shell to login.

On UNIX and Linux systems, we can list process by:

```bash
ps -el
```

Using a UNIX `fork()` to create a new process:

```cpp
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t pid;

	// fork a child process
	pid = fork();

	if (pid < 0) // error occurred
	{
		fprintf(stderr, "Fork Failed");
		return 1;
	}
	else if (pid == 0) // child process
	{
		execlp("/bin/ls", "ls", NULL);
	}
	else // parent process
	{
		// parent will wait for the child to complete
		wait(NULL);
		printf("Child Complete");
	}
	return 0;
}
```

> `execlp` is a version of `exec`.

The program above do the following things:

1. Parent is executed.
2. `fork` is called, child created. Note that child starts its execution at `if`, like its parent.
3. The child use `exec` to replace its memory space with a new program. Meanwhile, the parent move itself out of ready queue using `wait`.
5. The `ls` command is executed.
6. The parent process print `"Child Complete"`, then return.

![[Pasted image 20230628212814.png]]

Some important things:

- The call to `exec` does not return unless an error occurs.
- After `fork`, we have two different processes running the same program.
- The value of `pid` for the child process is `0`, while for the parent is an integer value greater than `0` (the pid of its child).

# Process Termination

For a process that terminates when done:

- A process terminates when it finishes executing its final statement and asks the operating system to delete it by using `exit()`.
- The process may return a status value to its parent process via the `wait()` system call.

A parent may terminate the execution of one of its children. Some reasons:

- The child has exceeded its usage of some of the resources that it has been allocated.
- The task assigned is no longer required.
- The parent is exiting.
	- The phenomenon triggered by this reason is called **cascading termination**.

When a process terminates, but its parent has not called `wait`, the process becomes a **zombie process**.

- When a process terminates, the resources are deallocated.
- However, its entry in the process table must remain before parent called `wait`. This is because that the entry contains the exit status code.
- The process that has terminated, but whose parent has not yet called `wait`, is known as a **zombie process**.
- Zombie process should only exist briefly.

If the parent did not invoke `wait` and instead terminated, the child processes will be left as **orphans**.

- Linux and UNIX solve this by assigning the `init` process as its new parent, and periodically invokes `wait`.

# Interprocess Communication

- A process is *independent* if it cannot affect or be affected by the other processes.
- A process is *cooperating* if it can affect or be affected by the other processes.

There are several reasons that we want cooperating processes:

1. **Information sharing**
2. **Computation speedup**
3. **Modularity**
4. **Convenience**

Cooperating processes require a mechanism called [[Interprocess Communication]].

> [[Interprocess Communication]]

---

# Reference

1. 

---

# Note

This note is included in GitHub repository [My-Vault](https://github.com/LittleD3092/My-Vault.git). Clone this repository and open it in [obsidian](https://obsidian.md/) to enable utilities like wikilinks and graph view.