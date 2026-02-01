# What is Linked List?

# Notes

## Singly Linked List (Data Structure)

A **singly linked list** is a **linear data structure** consisting of a sequence of **connected nodes**, where each node contains:

- **Data** → the value stored
- **Next** → the address (pointer) to the **next node**

The **next pointer of the last node is `NULL`**, which indicates the **end of the list**.

Like an array, a linked list stores **homogeneous (same-type) data elements**.

---

## Node Structure

```css
[ Data | Next ]
```

---

## Visualization

![image.png](What%20is%20Linked%20List/image.png)

```css
HEAD → [ data|next] → [ data|next] → [ data|next] → NULL
```

- Each block represents a **node**
- Nodes are connected using **pointers**
- Memory locations are **not contiguous**

---

## Types of Linked Lists

- **Singly Linked List**
- **Doubly Linked List**
- **Circular Linked List**

---

## Linked List Applications

- Dynamic memory allocation
- Implementation of **stack** and **queue**
- **Undo/Redo** functionality in software
- Used in **hash tables** and **graphs**

---

| Aspect | Singly Linked List | Array |
| --- | --- | --- |
| Memory Allocation | Dynamic, nodes allocated separately | Static, contiguous memory |
| Access Time | O(n) | O(1) |
| Insertion | O(1) at beginning/end | O(n) (requires shifting) |
| Deletion | O(1) (if node is known) | O(n) |
| Memory Overhead | Extra memory for pointer | Low |
| Dynamic Resizing | No resizing needed | May require reallocation |
| Traversal | One direction only | Random access |
| Implementation | More complex (pointers) | Simple |

# Quiz

- **A linked list is a linear data structure that includes a series of connected nodes.**
    - **True.**
    
- **In singly linked list each node consists of two parts: Data and Pointer to the address of next node.**
    - **True.**
    
- **Linked List is a data structure used to build other data structures like Stack, Queue , and others.**
    - **True.**
    
- **Linked list allows you to add data dynamically on run time.**
    - **True.**