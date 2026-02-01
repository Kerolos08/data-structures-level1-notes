# Vector Data Structure

## Just title for a quick review about vector.

| Aspect | **Stack** | **Vector** |
| --- | --- | --- |
| **Type** | Abstract Data Type (ADT) | Container / Data Structure |
| **Nature** | Restricted access | Flexible access |
| **Access Principle** | **LIFO** (Last In, First Out) | Random access |
| **Element Access** | Only top element | Any element by index |
| **Insertion** | `push()` (only at top) | `push_back()`, `insert()` |
| **Deletion** | `pop()` (only from top) | `pop_back()`, `erase()` |
| **Peek / Top** | `top()` | `front()`, `back()`, `[index]` |
| **Traversal** | Not allowed directly | Allowed using loops / iterators |
| **Indexing** | ❌ Not allowed | ✅ Allowed |
| **Size Change** | Grows/Shrinks at top only | Dynamic resizing |
| **Memory Layout** | Depends on implementation | Contiguous memory |
| **Implementation** | Implemented using array, vector, or linked list | Implemented using dynamic array |
| **Performance Access** | O(1) for top | O(1) random access |
| **Insertion Cost** | O(1) | O(1) at end, O(n) in middle |
| **Deletion Cost** | O(1) | O(1) at end, O(n) in middle |
| **Use Case Focus** | Control flow, undo, recursion | General-purpose storage |
| **STL Header (C++)** | `<stack>` | `<vector>` |