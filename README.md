# 📚 Algorithms & Data Structures — Laboratory Works

> **Language:** C++ | **Course:** Algorithms and Data Structures  
> **Labs:** 15 | **Topics:** Sorting · Recursion · Arrays · Linked Lists · Trees · Graphs · Hashing

---

## 📋 Table of Contents

- [Overview](#overview)
- [Repository Structure](#repository-structure)
- [Laboratory Works](#laboratory-works)
- [Technologies](#technologies)

---

## Overview

This repository contains implementations of classic algorithms and data structures completed as part of the **Algorithms and Data Structures** course.
Each laboratory work focuses on a specific topic, includes practical benchmarking, and provides analysis of theoretical vs. real-world performance.

---

## Repository Structure

```
algorithms-and-data-structures/
├── Lab01/   # Sorting Algorithms Comparison
├── Lab02/   # Recursion & Tail Recursion
├── Lab03/   # Arrays & Dictionaries
├── Lab04/   # 2D Arrays & Matrix Traversal
├── Lab05/   # Bubble Sort vs Insertion Sort
├── Lab06/   # Quick Sort & Shell Sort
├── Lab07/   # Counting Sort & Bucket Sort
├── Lab08/   # Singly & Doubly Linked Lists
├── Lab09/   # Stack (Array & Linked List)
├── Lab10/   # Queue (Array & Linked List)
├── Lab11/   # Binary Search Tree (BST)
├── Lab12/   # Graph Representations
├── Lab13/   # DFS & BFS Graph Traversal
├── Lab14/   # Linear & Binary Search
├── Lab15/   # Hash Table
└── README.md
```

---

## Laboratory Works

### Lab 01 — Sorting Algorithms: Empirical Analysis
**Topic:** Comparison of Bubble Sort O(n²) and Quick Sort O(n log n)

- Implemented both sorting algorithms from scratch
- Measured execution time on multiple datasets (random, sorted, reversed)
- Verified that real-world performance matches theoretical complexity estimates

---

### Lab 02 — Recursion & Tail Recursion Optimization
**Topic:** Factorial, Fibonacci, and optional recursive problems

- Standard recursive and **tail-recursive** factorial implementations
- Standard recursive and **tail-recursive** Fibonacci implementations
- Memory and time benchmarks for large input values
- Optional: tail-recursive power function

---

### Lab 03 — Arrays & Dictionaries
**Topic:** Basic data structure operations

- **Linear search** on arrays
- **Bubble sort** on arrays
- Dictionary (key-value store): insert, update, delete, lookup by key

---

### Lab 04 — 2D Arrays & Matrix Traversal
**Topic:** Multi-dimensional arrays and traversal algorithms

- 5×5 matrix filled with random integers (1–100)
- Row-by-row and column-by-column traversal
- **Spiral traversal** starting from the top-left corner
- Performance analysis for large matrix sizes

---

### Lab 05 — Bubble Sort vs Insertion Sort
**Topic:** Elementary sorting algorithm comparison

| Algorithm      | Comparisons | Swaps/Inserts | Complexity |
|---------------|-------------|---------------|------------|
| Bubble Sort   | ✅ tracked  | ✅ tracked    | O(n²)      |
| Insertion Sort| ✅ tracked  | ✅ tracked    | O(n²)      |

- Benchmarked on arrays of **100 / 1,000 / 10,000** elements
- Analysis of which algorithm performs better under specific conditions

---

### Lab 06 — Quick Sort & Shell Sort
**Topic:** Advanced comparison-based sorting

- **Quick Sort** with configurable pivot selection (middle element)
- **Shell Sort** with standard gap sequences
- Performance comparison on small, medium, and large datasets
- Analysis of pivot choice impact on Quick Sort performance

---

### Lab 07 — Counting Sort & Bucket Sort
**Topic:** Non-comparison sorting algorithms

- **Counting Sort** with element frequency tracking
- **Bucket Sort** using insertion sort within each bucket
- Tested on three dataset types:
  - Array with identical elements
  - Array with wide value range
  - Uniformly distributed array

---

### Lab 08 — Linked Lists
**Topic:** Singly and doubly linked list implementations

**Singly Linked List (`SinglyLinkedList`):**
- `Node` class with data + `next` pointer
- Push front / push back / delete operations

**Doubly Linked List (`DoublyLinkedList`):**
- `DoublyNode` class with `next` + `prev` pointers
- All singly list operations + backward traversal

- Benchmarks: insert at middle, delete from front/back
- Analysis: memory overhead vs. operation speed

---

### Lab 09 — Stack
**Topic:** Stack implementations using different underlying structures

| Implementation     | Underlying Structure |
|--------------------|----------------------|
| `Stack`            | Array                |
| `LinkedListStack`  | Linked List          |

- Operations: `push`, `pop`, `peek`, `isEmpty`
- Performance comparison on large datasets

---

### Lab 10 — Queue
**Topic:** Queue implementations using different underlying structures

| Implementation      | Underlying Structure |
|---------------------|----------------------|
| `Queue`             | Array                |
| `LinkedListQueue`   | Linked List          |

- Operations: `enqueue`, `dequeue`, `peek`, `isEmpty`
- Performance comparison on large datasets

---

### Lab 11 — Binary Search Tree (BST)
**Topic:** Tree data structure with standard operations

**`BinarySearchTree` class:**
- `insert(value)` — add a node
- `search(value)` — find a node
- `delete(value)` — remove a node

**Traversal methods:**
- 🔹 Preorder (Root → Left → Right)
- 🔹 Inorder (Left → Root → Right) — produces sorted output
- 🔹 Postorder (Left → Right → Root)

- Correctness testing on multiple datasets
- Execution time measurement for large trees

---

### Lab 12 — Graph Representations
**Topic:** Adjacency list vs. adjacency matrix

| Feature          | Adjacency List | Adjacency Matrix |
|-----------------|----------------|-----------------|
| Space           | O(V + E)       | O(V²)           |
| Add Edge        | O(1)           | O(1)            |
| Find Neighbors  | O(degree)      | O(V)            |

- Add/remove vertices and edges
- Neighbor lookup
- Benchmarked on graphs of varying size and density

---

### Lab 13 — Graph Traversal: DFS & BFS
**Topic:** Depth-First Search and Breadth-First Search

- **DFS** — recursive stack-based traversal
- **BFS** — queue-based level-order traversal
- Compared on graphs of different sizes and structures
- Analysis of when DFS outperforms BFS and vice versa

---

### Lab 14 — Search Algorithms
**Topic:** Linear search vs. binary search

| Algorithm     | Precondition   | Complexity |
|--------------|----------------|------------|
| Linear Search | None           | O(n)       |
| Binary Search | Sorted array   | O(log n)   |

- Benchmarked on arrays of varying sizes
- Analysis of execution time dependency on input size

---

### Lab 15 — Hash Table
**Topic:** Custom hash table implementation

- Implemented a hash table with a chosen hash function
- Operations: insert, search, delete
- Tested with different:
  - Table sizes
  - Collision resolution strategies
- Performance analysis on datasets of different magnitudes

---

## Technologies

| Tool        | Version  |
|-------------|----------|
| Language    | C++17    |
| Compiler    | MSVC     |
| Build System| MSBuild  |
| OS          | Windows  |

---

> 📌 *Each lab folder contains its own source files and, where applicable, sample output or benchmark results.*
