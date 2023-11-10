# Paging

## External Fragmentation

The free space in ram is separated rather than consecutive.

### Compaction

A solution to external fragmentation.

Also called defragmentation.

- Migrate allocated memory chunks together to make free space contiguous.
- Slows down the system.

### Paging

Paging treats the physically fragmented free spaces logically contiguous.

- Divide **physical** memory into fixed-sized blocks, called **frames**.
	- The size is the power of 2.
	- The size is between 512 bytes and 8192 bytes.
- Divide **logical** memory into blocks of same size called **pages**.
- To run a program of size $n$ pages, find $n$ frames and load program.
- A page table is used to mapping pages to frames.

An example:

![[Pasted image 20231110164721.png]]

#### hardware support for paging

![[Pasted image 20231110165034.png]]

1. CPU generate a page number $p$ and displacement $d$
2. page number $p$ is passed to the page table to find frame number $f$
3. frame number $f$ and displacement $d$ is passed to physical memory to find the address $f + d$.

##### Example

![[Pasted image 20231110165456.png|]]

Question: How many bits are required to represent:

1. The page number
2. The frame number
3. The displacement
4. A logical address
5. A physical address
6. A page-table entry

---

1. The page number:

There are 4 pages, therefore 3 bits.

2. The frame number:

There are 8 frames, therefore 4 bits.

3. The displacement

Each frame / page has 4 bytes, therefore 3 bits.

4. A logical address

$p + d = 6$

5. A physical address

$f + d = 7$

6. A page-table entry

$p + f = 7$

#### Implementation of Page Table

- Page table is kept in main memory.
- Each process has its page table.
	- Each process has its logical memory.
- Using page table, there are 2 memory access for each data/instruction access.
- The 2 memory access problem can be solved by using fast-lookup hardware cache (associative memory or translation look-aside buffers (TLBs))

#### Paging hardware with TLB

![[Pasted image 20231110171109.png]]

TLB is often fully associative.

#### Locality of Reference

There are two kinds of localities:

- temporal localities: A page is used in a time interval.
- spacial localities: Multiple neighboring pages are used at once.

#### Effective Access Time of TCB

Assume

- Associative lookup takes $\varepsilon$ time unit
- memory cycle time is $1 \mu\rm s$
- Hit ratio: percentage of times that a page number is found in the associative registers. $\alpha$

$$EAT = (1 + \varepsilon)\alpha + (2 + \varepsilon)(1 - \alpha) = 2 + \varepsilon - \alpha$$

Example:

![[Pasted image 20231110172821.png]]