# 📚 Data Structures and Algorithms in C

This repository serves as a comprehensive collection of data structure implementations and algorithm analyses using the **C programming language**. 

It reflects my learning journey and practical applications within the **Data Structures** course. The repository is actively maintained and updated as I progress through advanced topics.

## 🚀 Project Overview

The primary goal of this project is to understand the inner workings of data storage, memory management (pointers), and algorithmic efficiency (Big O notation) by implementing them from scratch without relying on high-level libraries.

## 📂 Current Contents

### 1. Arrays & Complexity Analysis
* **Array Operations:** Low-level implementation of insertion, deletion, and reversing algorithms.
* **Big O Notation:** Analysis of time complexity for the first 7 fundamental algorithm questions.

### 2. Singly Linked Lists
* **CRUD Operations:** Creating a list, inserting nodes (Head, Middle, Tail), and deleting nodes by value.
* **Traversal:** Iterating through the list to display data.
* **Complexity:** Documentation of time complexity for each operation ($O(1)$ vs $O(N)$).

### 3. Doubly Linked Lists
* **Bidirectional Navigation:** Implementation of `prev` and `next` pointers.
* **Insertion Logic:** * Insert at End (Tail manipulation).
    * Insert After a specific node (Handling 4-pointer updates).
* **Recursive Operations:** A recursive approach to traverse and delete all nodes, demonstrating stack memory usage and post-order traversal logic.

### 4. Circular Linked Lists
* **Structural Differences:** Comparison between Linear and Circular lists.
* **Algorithmic Behavior:** Observations on how sorting algorithms react to circular boundaries (avoiding infinite loops).

### 5. Stack Applications (Shunting Yard Algorithm)
* **Infix to Postfix Conversion:** Implementation of Dijkstra's Shunting Yard algorithm.
* **Logic:**
    * Handling operator precedence (`*`, `/` vs `+`, `-`).
    * Parenthesis management using a Stack data structure.
    * *Example:* Converts `a*b+c` to `ab*c+`.

## 🔜 Future Roadmap

This repository will be updated with the following topics in the upcoming weeks:
- [ ] **Stacks & Queues:** Array and Linked List based implementations.
- [ ] **Trees:** Binary Search Trees (BST), AVL Trees, and Traversals.
- [ ] **Graphs:** Representation (Adjacency Matrix/List), BFS, and DFS algorithms.
- [ ] **Sorting & Searching:** Merge Sort, Quick Sort, Binary Search implementation and analysis.

## 🛠️ How to Compile & Run

You can compile any C file in this repository using the GCC compiler.

**Example for Linked List:**
```bash
gcc src/linked_list.c -o program
./program
