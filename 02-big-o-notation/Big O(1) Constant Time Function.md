# Big O(1) : Constant Time Function

# Notes

## Big O(1) — Constant Time Function

- **Big O(1)** means that an algorithm **always takes the same amount of time**, no matter how large or small the input size is.
- The runtime **does not depend on `n`** (number of inputs).

---

## Key Idea

> The algorithm performs a fixed number of operations, even if the input size increases.
> 

So:

- Input size = 10 → same time
- Input size = 1,000,000 → same time

---

## Example

```cpp
char GetLastCharacter(string S1)
{
return S1[ S1.length() - 1 ];
}
```

- Only **one operation**
- No loops
- No recursion

**Time Complexity: O(1)**

---

## Common O(1) Operations

- Accessing an array element by index
    
    `arr[5]`
    
- Assigning a value to a variable
    
    `x = 10`
    
- Arithmetic operations
    
    `+ - * /`
    
- Returning a value from a function
- Hash table lookup (average case)

# Quiz

- **O(1) Means Constant Time Function.**
    - **True.**
    
- **O(1) is affected by Input Size?**
    - **False.**
    
- **O(1) is not affected by Input Size, so it always takes the same time.**
    - **True.**
    
- **O(1) is the fastest notation, which means that your algorithm is excellent.**
    - **True.**