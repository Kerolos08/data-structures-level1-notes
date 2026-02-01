# Time & Space Complexity - Big O Notation

# Notes

## Time & Space Complexity

An algorithm's time complexity: specifies how long it will take to execute an algorithm as a function of its input size.

Similarly, an algorithm's space complexity: specifies the total amount of
space or memory required to execute an algorithm as a function of the
size of the input.

## What is Big O Notation

**Big O Notation** (where **O** stands for **“Order of”**) is a mathematical way to describe the **efficiency of an algorithm**.

It explains **how an algorithm’s performance changes as the input size (`n`) grows**, rather than measuring exact execution time.

---

## What Big O Measures

Big O is used to measure:

### 1.Time Complexity

- How the **runtime** of an algorithm grows with input size.
- Example: How many operations are performed as `n` increases.

### 2.Space Complexity

- How much **extra memory** an algorithm requires as input size grows.

---

## Characteristics of Big O

- Represented as **O(n)**, where `n` is the **number of inputs**
- Describes the **worst-case complexity**
- Uses **algebraic terms** (like `n`, `n²`, `log n`)
- Focuses on **growth rate**, not exact time
- Ignores:
    - Constants
    - Hardware speed
    - Programming language

---

## What Big O Tells Us

Big O defines:

- The **relationship between input size and performance**
- How an algorithm behaves under **large data sets**
- How scalable an algorithm is

Big O **does NOT** tell:

- Exact runtime in seconds
- Actual CPU or memory usage

---

## Why Big O Is Important

- Allows comparison between algorithms
- Predicts performance for large inputs
- Helps choose efficient solutions
- Independent of machine or environment

Example:

- `O(n)` grows slower than `O(n²)`
- `O(n log n)` is more efficient than `O(n²)` for large `n`

---

## Example

![image.png](Time%20&%20Space%20Complexity%20-%20Big%20O%20Notation/image.png)

| Big-O | Name | Example |
| --- | --- | --- |
| **O(1)** | Constant | Access array element |
| **O(log n)** | Logarithmic | Binary search |
| **O(n)** | Linear | Single loop |
| **O(n log n)** | Linearithmic | Merge sort |
| **O(n²)** | Quadratic | Nested loops |
| **O(2ⁿ)** | Exponential | Recursive Fibonacci |
| **O(n!)** | Factorial | Traveling salesman |

# Quiz

- **An algorithm's time complexity: specifies how long it will take to execute an algorithm as a function of its input size.**
    - **True.**
    
- **An algorithm's space complexity: specifies the total amount of space or memory required to execute an algorithm as a function of the size of the input.**
    - **True.**
    
- **The big-O originally stands for “Order Of“.**
    - **True.**
    
- **Big O tells us about the Efficiency of Algorithm.**
    - **True.**
    
- **Big O, also known as Big O notation, represents an algorithm's worst-case complexity.**
    - **True.**
    
- **Big O represents an algorithm's best-case complexity.**
    - **False.**
    
- **Big O uses algebraic terms to describe the complexity of an algorithm.**
    - **True.**
    
- **Big O describes the relationship between Input Size and Time/Space.**
    - **True.**
    
- **Big O tells you the exact time your algorithm's runtime is.**
    - **False.**
    
- **Big O does not tell you the exact time your algorithm's runtime is.**
    - **True.**
    
- **with Big O Notation, we can look at our algorithm and see that it will take O(n) time to run. Big O Notation, written as O(blank), show us how many operations our code will run, and how its runtime grows in comparison to other possible solutions.**
    - **True.**