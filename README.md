# 📚 Data Structures and Algorithms (C Implementation)

![Language](https://img.shields.io/badge/Language-C-blue.svg)
![Course](https://img.shields.io/badge/Course-Data%20Structures-green.svg)
![Status](https://img.shields.io/badge/Status-Active-orange.svg)

This repository contains a comprehensive collection of data structures and algorithms implemented in **C**. It serves as a portfolio for the **Data Structures** course, demonstrating low-level memory management, algorithmic logic, and time complexity analysis.

## 🚀 Project Overview

The primary goal of this project is to implement fundamental computer science concepts from scratch, without relying on high-level libraries. This ensures a deep understanding of:
* **Pointers & Memory Allocation** (`malloc`, `free`)
* **Abstract Data Types (ADTs)**
* **Algorithmic Complexity** (Big O Notation)
* **Recursion & Iteration**

## 📂 Repository Contents

### 1. Linked Lists (Linear Data Structures)
Implementations of dynamic data storage with various linkage types.
* **Singly Linked List:** Creation, Traversal, Insertion (Head/Tail/Middle), Deletion by value.
* **Doubly Linked List:** bidirectional navigation using `prev` and `next` pointers.
* **Circular Linked List:** Ring topology implementation; handling traversal without NULL termination and specific deletion logic for Head/Tail nodes.

### 2. Stacks & Queues (LIFO/FIFO)
* **Shunting Yard Algorithm:** An implementation of Dijkstra's algorithm to parse mathematical expressions.
    * Converts **Infix** expressions (e.g., `a*b+c`) to **Postfix** (e.g., `ab*c+`).
    * Handles operator precedence and parenthesis.

### 3. Trees & Heaps (Hierarchical Data Structures)
* **Tree Creation from Array:** Algorithm to convert a linear array into a Binary Tree using index mapping (`2i+1`, `2i+2`).
* **Heaps (Priority Queues):**
    * **Max Heap:** Insertion, Deletion (Extract Max), and Heapify operations.
    * **Min Heap:** Logic adaptation for priority management.
    * *Includes array-based representation analysis.*

### 4. Graphs (Complex Relationships)
* **Graph Traversals:**
    * **DFS (Depth First Search):** Recursive implementation using Stack logic.
    * **BFS (Breadth First Search):** Iterative implementation using Queue logic.
* **Clustering (Connected Components):** Algorithm to detect and separate disconnected sub-graphs (clusters) using Adjacency Matrices.

### 5. Matrix & Array Optimization
* **Sparse Matrix Transformation:** Optimization technique to compress large 2D arrays with mostly zero values into a coordinate list (Row, Col, Value) to save memory.
* **Complexity Analysis:** Big O analysis for fundamental array operations (Reverse, Insertion, Deletion).

---

## 🛠️ Compilation & Usage

Each module is self-contained. You can compile the C files using the GCC compiler.

**Prerequisites:**
* GCC Compiler (MinGW for Windows, default on Linux/macOS)
* Visual Studio Code (Recommended)

**Example: Running the Linked List Program**
```bash
# Compile
gcc LinkedList.c -o program

# Run (Windows)
.\program.exe

# Run (Linux/Mac)
./program
