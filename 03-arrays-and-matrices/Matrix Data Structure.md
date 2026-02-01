# Matrix Data Structure

## Matrix Data Structure

A **matrix** is a data structure that stores elements in a **two-dimensional array** arranged in **rows and columns**.

All elements are of the **same data type** and stored in **contiguous memory locations (row-wise)**.

---

## Characteristics of a Matrix

- Two-dimensional data structure
- Stored in **rows and columns**
- Elements are **homogeneous** (same data type)
- Supports **random access** using row and column indices
- Memory is allocated **contiguously**

---

## Matrix Indexing and Order

![image.png](Matrix%20Data%20Structure/image.png)

- Indexing usually starts from **0**
- Element access format:
    
    ```cpp
    matrix[row][column]
    ```
    
- For a matrix of size `R × C`:
    - Row indices: `0 → R - 1`
    - Column indices: `0 → C - 1`

Example:

```cpp
matrix[2][1] =10;
```

---

## Matrix Size

- Matrix size is **fixed after creation**
- In C/C++:
    - Static matrices → fixed size
    - Dynamic allocation is possible, but size remains fixed after creation
- Resizable behavior requires advanced structures (not raw matrices)

---

## Operations on Matrix

### Accessing Elements

- Direct access using row and column index

**Time Complexity**

- Access single element: **O(1)**
- Access all elements: **O(R × C)**

---

### Updating / Inserting Elements

- Assigning a value to a specific position

```cpp
matrix[i][j] = value;
```

**Time Complexity**

- Update single element: **O(1)**
- Update all elements: **O(R × C)**

---

### Searching in Matrix

- Linear search through all rows and columns

**Time Complexity**

- Searching an element: **O(R × C)**

---

## Advantages of Matrix

- Simple representation of 2D data
- Fast access to elements
- Efficient memory layout
- Easy implementation using arrays
- Ideal for mathematical computations

---

## Disadvantages of Matrix

- Fixed size
- Costly resizing
- Memory waste if sparsely populated
- Not suitable for dynamic data