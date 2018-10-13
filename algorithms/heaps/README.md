*** Heaps and Heap sort

** Priority Queue

Structure that implements a set "S" of elements
each element is associated with a key

Pick the max or min priority, delete from queue, change from priorities etc..

Operations:
Insert(S,x): insert element x into set S
max(S): return element of S with the largest key
extract_max(S): above + remove it from S
increase_key(S,x,k): increase the value of x's key to the new value k

** Heap

It's an implementation of a priority queue
An array visualised as a nearly complete binary tree

￼
Index 1 is the root of the tree (16)

indices 2 and 3 are the children, 4,5,6,7 are the grand children etc.


Heaps as a tree

root of three: first element (i =1)
parent(i) = i/2
left(i) = 2i   right(i) = 2i + 1

Max-Heap property:
The key of a node is >= the keys of it's parents

How to build a max heap out of an initially unsorted array?

Heap Operations:
build_max_heap: produces max heap from an unordered array
max_heapify: correct a single violation of the heap property in a subtree's root

Max Heapify Assumes that the trees rooted at left(i) and right(i) are max heaps

￼
not a max heap because 2(4) violates max heap property
max_heapify(A,2)
heap_size(A) = 10
look at both children and exchange with the bigger child
(exchange A[2] with A[4]
￼
recursively call call max_heapify(A,4)
exchange a[4] and A[9]


convert a[1..n] into a max heap

build_max_heap(A):
	for i = n/2 downto 1
		do max_heapify(A,i)


elements A[n/2 + 1 .. n] are all leaves (they satisfy max_heap property)
