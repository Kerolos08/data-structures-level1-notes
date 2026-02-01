# Array is One of the Most Important Data Structures

## Array Data Structure

An **array** is a data structure that stores **multiple values of the same data type** in **contiguous memory locations**.

All elements are **homogeneous** (same type) and can be accessed using an index.

---

## Characteristics of an Array

- Stores elements of the **same data type**
- Elements are stored in **contiguous memory**
- Each element can be accessed using its **index**
- Supports **random access**
- Size is usually **fixed after creation** time.

---

## Array Indexing and Order

![image.png](Array%20is%20One%20of%20the%20Most%20Important%20Data%20Structures/image.png)

- Array elements are stored sequentially
- Indexing usually starts from **0**
- For an array of size `N`, valid indices are `0` to `N - 1`

---

## Array Size

- In **C language**, arrays have a **fixed size**
- In **C++**, raw arrays are still **fixed size**
- Dynamic allocation is possible using:
    - `new[]` (manual memory management)
    - `std::vector` (resizable and recommended)

---

## Operations on Arrays

### Accessing Elements

- Direct access using index
- Very fast due to contiguous memory

**Time Complexity**

- Access one element: **O(1)**
- Access all elements: **O(N)**

---

### Updating Elements

- Replacing a value at a known index

**Time Complexity**

- Update one element: **O(1)**

---

### Insertion in Array

- Inserting at a specific position requires **shifting elements**
- True insertion is **not efficient**

**Time Complexity**

- Insert at end (if space exists): **O(1)**
- Insert at beginning or middle: **O(N)**

---

### Searching in Array

- To find a value, elements are checked one by one (linear search)

**Time Complexity**

- Searching an element: **O(N)**

---

## Advantages of Arrays

- Fast access to elements
- Simple and easy to use
- Efficient memory usage
- Cache-friendly
- Useful when data size is known in advance

---

## Disadvantages of Arrays

- Fixed size
- Costly insertion and deletion
- Cannot store mixed data types
- Possible memory wastage or overflow

---

## Applications of Arrays

- Storing multiple values of the same type
- Matrix and table representation
- Lookup tables
- Implementing other data structures:
    - Stack
    - Queue
    - Heap
    - Hash tables
- Used in sorting and searching algorithms
- Used in CPU scheduling and system-level tasks