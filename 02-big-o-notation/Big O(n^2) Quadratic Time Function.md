# Big O(n^2) : Quadratic Time Function

# Notes

## Big O(n²) — Quadratic Time Function

**Big O(n²)** represents a **quadratic time algorithm**, meaning the execution time grows **proportional to the square of the input size (`n`)**.

---

## Key Concept

> In O(n²) algorithms, for every input element, the algorithm performs another full pass over the input.
> 
- Input size = 10 → ~100 operations
- Input size = 100 → ~10,000 operations
- Input size = 1,000 → ~1,000,000 operations

---

## Why It Is Called Quadratic Time

- Usually caused by **nested loops**
- Each loop runs `n` times
- Total operations ≈ `n × n = n²`

---

## Example: Nested Loops

```cpp
int MultiplicationSum(short n)
{
int Sum = 0 ;
for (int i = 1 ; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			{
				Sum = Sum + (i * j) ;
			}
	}
return Sum ;
}
```

### Step Analysis

- Outer loop → `n` times
- Inner loop → `n` times per outer iteration

Total steps ≈ `n²`

**Time Complexity: O(n²)**

## Common O(n²) Algorithms

- Bubble Sort
- Selection Sort
- Insertion Sort (worst case)
- Checking all pairs
- Duplicate detection using nested loops

---

## Summary

- O(n²) becomes **very slow for large inputs**
- Acceptable only for **small data sets**
- Often a sign that optimization is needed    **Big O(n^2) : Quadratic Time Function**

# Quiz

- Big O(n^2) is Quadratic Time Function.
    - True.
    
- O(n) is much faster than O(n^2).
    - True.
    
- O(1) is slower than O(n^2).
    - False.
    
- O(1) < O(n) < O(n^2) < O(n^3).
    - True.
    
- if you have f= 3 + 5n + 6n^2 , then big O is O(n^2).
    - True.