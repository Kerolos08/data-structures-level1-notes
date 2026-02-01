# Big O(Log n) : Logarithmic Time Function

# Notes

## Big O(log n) — Logarithmic Time Complexity

**Big O(log n)** represents a **logarithmic time algorithm**, meaning the execution time **increases very slowly** as the input size (`n`) grows.

---

## Key Concept

> In O(log n) algorithms, the problem size is reduced by a constant factor (usually half) in each step.
> 
- Input size = 8 → 3 steps
- Input size = 16 → 4 steps
- Input size = 1,024 → 10 steps

Every step **cuts the problem size**.

---

## Why It Is Called Logarithmic

- The algorithm **does not check every element**
- Each step eliminates a large portion of the data
- Commonly uses **divide and conquer**

---

## Example:

```cpp
void fun1(short n)
{
short x = n ;
while ( x > 0 )
{
x = x / 2 ;
cout << x << endl ;
}
}
```

x = x / 2 cut the iteration count to half so it is not gonna be linear O(n) it will be Log x for the base of 2.

---

## Common O(log n) Algorithms

- Binary Search
- Tree operations (balanced BST)
- Finding element in sorted data
- Divide and conquer techniques

## Why O(log n) Is Very Efficient

- Much faster than O(n)
- Huge difference for large inputs

Example:

- `n = 1,000,000`
- O(n) → 1,000,000 steps
- O(log n) → ~20 steps

# Quiz

- **Log2 always half itself.**
    - **True.**
    
- **Log means that the number of iterations in the loop is always less than n.**
    - **True.**
    
- **O( log n ) is much faster than O(n)**
    - **True.**