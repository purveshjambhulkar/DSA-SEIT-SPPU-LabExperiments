# DSA-SEIT-SPPU-LabExperiments
A comprehensive repository housing Data Structures and Algorithms lab experiments tailored for SPPU's SE IT curriculum, aimed at hands-on learning and practical implementation of fundamental algorithms and data structures.



PRATICAL NO.1
Linear Search:
Iterates through each element in the list until a match is found.
Binary Search:
divide the search space in half until the target element is found.
Bubble Sort:
Bubble Sort is a simple sorting algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. 
Insertion sort:
Insertion Sort is a simple sorting algorithm that builds the final sorted array one element at a time. 
Quick Sort:
uses a divide-and-conquer strategy to sort an array or list.
Practical 2:
A stack is a fundamental data structure that follows the Last In, First Out (LIFO) principle. In a stack, the last element added is the first one to be removed. Think of it like a stack of plates; you add a plate to the top, and you remove the topmost plate.
Here are the main operations associated with a stack:
Push:
Adds an element to the top of the stack.
Pop:
Removes the element from the top of the stack.
Peek or Top:
Returns the element at the top of the stack without removing it.
isEmpty:
Checks if the stack is empty.
Practical 3:
Circular queue:
the last element is connected back to the first element to form a circle. 
Here are the main operations associated with a circular queue:
Enqueue (Insert):
Adds an element to the rear of the queue.
Dequeue (Delete):
Removes the element from the front of the queue.
Front:
Returns the element at the front of the queue without removing it.
isEmpty:
Checks if the queue is empty.
isFull:
Checks if the queue is full.
Practical 4:
Expression Tree:
An expression tree is a binary tree representation of an arithmetic expression. In this tree structure, each leaf node represents an operand (variable or constant), and each internal node represents an operator.
Practical 5:
Tree:
A tree is a widely used data structure in computer science that represents a hierarchical structure.
Here are some key concepts related to trees:
Root: The topmost node in a tree, from which all other nodes are descended.
Parent: A node in a tree that has one or more child nodes.
Child: A node in a tree that has a parent node.
Leaf: A node in a tree that has no children.
Subtree: A tree formed by a node and its descendants.
Siblings: Nodes that share the same parent.
Depth: The level or distance of a node from the root. The root has depth 0.
Height: The length of the longest path from a node to a leaf. The height of the tree is the height of the root
Practical 6:
Binary Threaded Tree:
A threaded binary tree is a binary tree in which each node contains additional information to facilitate traversal of the tree without using a stack or recursion.
Inorder Threaded Binary Tree:
In an inorder threaded binary tree, each node points to its in-order predecessor and successor.
Preorder Threaded Binary Tree:
In a preorder threaded binary tree, each node points to its preorder predecessor and successor.
Practical 7:
MST:
A minimum spanning tree (MST) of a connected, undirected graph is a subgraph that is a tree and connects all the vertices together with the minimum possible total edge weight. 
Prim's Algorithm:
Prim's algorithm starts with an arbitrary node and repeatedly adds the shortest edge that connects a vertex in the spanning tree to a vertex outside the spanning tree until all vertices are included.
Kruskal's Algorithm:
Kruskal's algorithm sorts all the edges by weight and then adds them to the spanning tree if adding an edge won't create a cycle.

PARTICAL 8
Shortes path:

Finding the shortest path in a graph is a common problem in graph theory and network analysis.
Dijkstra's Algorithm:
Dijkstra's algorithm finds the shortest paths from a source vertex to all other vertices in a weighted graph with non-negative edge weights.
Practical 9:
Heap Sort is a comparison-based sorting algorithm that uses a binary heap data structure to build a heap and then sorts the elements in the heap. 
Here's a step-by-step explanation of how Heap Sort works:
Build Heap:
Build a binary heap from the input array. This involves starting from the last non-leaf node and repeatedly heapifying the subtrees until the entire array is transformed into a heap.
Heapify:
Heapify is the process of maintaining the heap property (either max heap or min heap) by repeatedly swapping elements to move a violating element down the heap.
Sort:
Repeatedly extract the maximum (for max heap) or minimum (for min heap) element from the heap, and place it at the end of the array.
Repeat:

Continue this process until the entire heap is sorted.

PRATICAL 10
File Handling :
File handling in C++ involves operations related to reading from and writing to files. 

Opening and Closing Files:
To work with files, you need to open them before performing any read or write operations. 

Reading from Files:
You can use the if stream (input file stream) class to read data from files.

Appending to Files:
You can use the std::ios::app flag to open a file in append mode, which means that new data will be added to the end of the file.

. Binary Search Tree (BST):

Concept: A tree where each node's key is greater than all the keys in its left subtree and less than all the keys in its right subtree.
Operations:
Insert:
Find the correct position based on the key value.
Create a new node and insert it at the position.
Handle duplicates (e.g., ignore, replace, store additional information).
Delete:
Find the node to delete (using search).
Handle cases based on the node's children (0, 1, or 2 children).
Update parent pointers and adjust the tree structure.
Search:
Traverse the tree using a comparison function to find the target key.
Return the node containing the key or indicate not found.
Traversal:
Visit nodes in a specific order (inorder, preorder, postorder).
Use recursion or iterative approaches.
Depth:
Find the longest path from the root to a leaf node.
Mirror image:
Swap left and right subtrees recursively for each node.
Copy:
Create a new node for each node in the original tree.
Copy key and child pointers to the new tree.
Note: Implement insertion, deletion, search, and traversal for full credit. Choose any three operations from the remaining options for demonstration.
2. In-order Threaded Binary Tree (ITBT):

Concept: A modification of BST where links are used to navigate between nodes in inorder sequence without using recursion.
Operations:
Traversal:
Use the threads to visit nodes in inorder and preorder.
No need for additional stack or recursion.
Note: Implement inorder and preorder traversal for ITBT.
3. Graph Representation and Minimum Spanning Tree (MST):

Representation:
Adjacency List: Each node stores a list of its neighbors. Efficient for space for sparse graphs.
Adjacency Matrix: A 2D matrix where each entry indicates the presence of an edge. Efficient for dense graphs.
Minimum Spanning Tree:
Kruskal's algorithm: Sort edges by weight, select edges that don't create cycles till all nodes are connected.
Prim's algorithm: Start with a node, select the minimum weight edge connecting it to an unvisited node, repeat until all nodes are connected.
Note: Implement Kruskal's and Prim's algorithms for finding MST on the given graph representation.
4. Shortest Path Algorithm:

Dijkstra's algorithm: Finds the shortest path from a single source to all other nodes in a weighted graph.
Steps:
Initialize distances from the source to all nodes as infinity.
Set distance to source as 0.
Repeatedly relax edges (update distances if a shorter path is found).
Stop when all nodes are processed or no updates occur.
Note: Implement Dijkstra's algorithm to find the shortest path from the chosen source in the city graph.
5. Heap Sort:

Concept: Utilizes a heap data structure to sort a list of elements.
Steps:
Build a max-heap (or min-heap) from the input list.
Swap the root (largest/smallest element) with the last element.
Heapify the remaining heap (restore heap property).
Repeat swapping and heapifying till only one element remains.
Note: Implement heap sort using a max-heap or min-heap to sort the given set of values.
6. Student Database Management:

Sequential file: Store student data sequentially in a file.
Operations:
Add: Write new student data to the end of the file.
Delete: Mark the record as deleted (flag, separate file).
Search: Read records sequentially till the target roll number is found or the end of file is reached.
Note: Implement add, delete, and search operations for the student database.
Remember: These are just brief notes to provide a starting point. You need to research and implement the specific algorithms and data structures for each topic. Feel free to ask further questions or clarify any aspects in more detail.

I hope this helps! Good luck with your studies!
