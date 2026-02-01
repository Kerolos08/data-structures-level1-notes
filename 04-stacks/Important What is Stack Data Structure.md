# Important: What is Stack Data Structure?

A **stack** is a **linear data structure** that stores elements in a specific order and follows the principle:

### **LIFO — Last In, First Out**

![image.png](Important%20What%20is%20Stack%20Data%20Structure/image.png)

This means the **last element added** to the stack is the **first one removed**.

---

## Stack (Data Structure)

- A stack stores **multiple elements of the same type**.
- Access is **restricted** to **one end only**, called the **top**.
- Elements can be **added or removed only from the top**.
- It follows the **LIFO** principle.

---

## Basic Stack Operations

- **Push** → Add an element to the top of the stack
- **Pop** → Remove the top element from the stack
- **Peek / Top** → View the top element without removing it
- **Is-empty** → Check if the stack is empty
- **Is-full** → Check if the stack is full (for fixed-size stacks)

---

## Stack vs Vector

- **Stack** is a **container adapter** that is implemented using another container such as **`deque`** (default) or **`vector`**.
- **Vector** is an **independent container** (dynamic array).

Both are **homogeneous data structures** (store elements of the same data type).

However:

- **Stack** restricts access and follows **LIFO**
- **Vector** allows **random access** using an index

---

## Container Adapter

A **container adapter** is a special kind of container that **does not store data by itself**, but instead **wraps another container** and **restricts how data can be accessed**.

- It **adapts** an existing container to behave in a specific way
- It **limits the interface** (allowed operations)
- It enforces a **specific rule or behavior**

> A container adapter is a wrapper that uses another container internally and restricts access to enforce a specific behavior, such as LIFO in stack.
> 

---

## Common Uses of Stack

- Function calls (call stack)
- Undo / Redo operations
- Expression evaluation
- Backtracking (e.g., maze solving)
- Reversing data (strings, arrays)