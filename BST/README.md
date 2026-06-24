# Binary Search Tree (BST)

This folder contains Binary Search Tree implementations and projects written in C.

The focus is on understanding how BSTs work internally and how common tree operations are implemented using recursion.

---

## Files

```text
BST
├── project_student_management.c
└── README.md
```

---

## Project: Student Management System

File:

```text
project_student_management.c
```

This project stores student information inside a Binary Search Tree.

Each student record contains:

- Roll Number
- Name
- Marks

---

## Features Implemented

### Insert Student

Insert student records into the BST based on student names.

### Search Student

Search for a student using their name.

### Tree Traversals

- In-Order Traversal
- Pre-Order Traversal
- Post-Order Traversal

### BST Validation

Checks whether the tree satisfies BST properties.

### Height Calculation

Calculates the height of a tree or subtree.

### Balance Factor

Computes:

```text
Height(Left Subtree) - Height(Right Subtree)
```

### AVL Rotation Detection

Detects:

- LL Case
- RR Case
- LR Case
- RL Case

### Delete Operation

Handles all BST deletion cases:

1. Leaf Node
2. Single Child
3. Two Children

---

## Concepts Practiced

- Structures
- Dynamic Memory Allocation
- Pointers
- Recursion
- Trees
- Binary Search Trees
- AVL Tree Concepts

---

## Time Complexity

| Operation | Average Case |
|------------|-------------|
| Insert | O(log n) |
| Search | O(log n) |
| Delete | O(log n) |

Worst Case:

```text
O(n)
```

when the tree becomes skewed.

---

## YouTube Tutorial

Detailed explanation available on:

https://youtube.com/@ssutradhar35

---

## Author

Subir Sutradhar
