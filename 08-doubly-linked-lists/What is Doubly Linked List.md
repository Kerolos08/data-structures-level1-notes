# What is Doubly Linked List?

# Notes

## Doubly Linked List (DLL)

A **doubly linked list** is a **linear data structure** where **each node contains three parts**:

1. **Data**
2. **Pointer to the previous node**
3. **Pointer to the next node**

This allows **traversal in both directions**.

---

## Node Structure

```
[ Prev | Data | Next ]
```

- `Prev` → address of the previous node
- `Next` → address of the next node

---

## Visualization

![image.png](What%20is%20Doubly%20Linked%20List/image.png)

```
NULL ← [ * | 1 | * ] ⇄ [ * | 2 | * ] ⇄ [ * | 3 | * ] → NULL
```

- First node: `Prev = NULL`
- Last node: `Next = NULL`
- Middle nodes point **both ways**

---

## Core Idea (Compared to Singly)

### Singly Linked List

```
[ Data | Next ] → → →
```

- One direction only

### Doubly Linked List

```
← ← [ Prev | Data | Next ] → →
```

- Two-direction navigation

---

## Why Use a Doubly Linked List?

Because sometimes you need:

- Move **forward and backward**
- Delete a node **without needing the previous node externally**
- Implement **undo/redo**, navigation systems, LRU cache

---

## Array vs Singly vs Doubly (Quick Compare)

| Feature | Singly LL | Doubly LL | Array |
| --- | --- | --- | --- |
| Traversal | One direction | Both directions | Random |
| Memory | Low | Higher (extra pointer) | Lowest |
| Deletion | Need previous node | Easy (has `Prev`) | Costly |
| Insertion | Efficient | Efficient | Costly |
| Access | O(n) | O(n) | O(1) |

# Quiz

- **In Doubly Linked List Each node consists of a data value, a pointer to the next node, and a pointer to the previous node.**
    - **True.**
    
- **In Doubly Linked List: Traversal can occur in both ways..**
    - **True.**
    
- **In singly linked list: Traversal can occur in both ways..**
    - **False.**
    
- **In Doubly Linked List: It requires more space because of an extra pointer..**
    - **True.**