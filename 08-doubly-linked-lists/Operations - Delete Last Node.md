# Operations - Delete Last Node

# Code

```cpp
void DeleteLastNode(Node *&HEAD)
{
    if (HEAD == nullptr)
    {
        // List is empty
        return;
    }
    
    // Special case: Only one node in the list
    if (HEAD->Next == nullptr)
    {
        delete HEAD;     // Delete the node at the address stored in HEAD
        HEAD = nullptr;  // Set HEAD pointer to null
        return;          // EXIT - Critical!
    }
    
    // Find the last node
    Node *LastNode = HEAD;
    while (LastNode->Next != nullptr)
    {
        LastNode = LastNode->Next;
    }
    
    // Update the second-to-last node's Next pointer
    LastNode->Prev->Next = nullptr;
    
    // Delete the last node
    delete LastNode;
}
```

```cpp
void DeleteLastNode(Node *&HEAD)
{
    if (HEAD == nullptr)
    {
        // List is empty
        return;
    }

    if (HEAD->Next == nullptr)
    {
        delete HEAD;
        HEAD = nullptr;
        return;
    }

    Node *Current = HEAD;
    // find the node before last node
    while (Current->Next->Next != nullptr)
    {
        Current = Current->Next;
    }
    Node *Temp = Current->Next; // temp points to the actual next node because we have the node before the last
    Current->Next = nullptr;
    delete Temp;
```

# Code Explanation

Deletes the last node from a doubly linked list and frees its memory.

---

## Function Signature

```cpp
void DeleteLastNode(Node *&HEAD)
```

**Parameters:**

- `Node*& HEAD` - Passed by **reference** (NECESSARY for the single node case - we need to set HEAD to null)

---

## Corrected Code

---

## Step-by-Step Breakdown

### Step 1: Safety Check - Empty List

```cpp
if (HEAD == nullptr)
{
    return;
}
```

- **Why?** Prevents crashes if the list is empty
- Exit early if there's nothing to delete

---

### Step 2: Special Case - Single Node (CRITICAL SECTION)

```cpp
if (HEAD->Next == nullptr)
{
    delete HEAD;
    HEAD = nullptr;
    return;
}
```

#### Why is this a special case?

**Single node list:**
```
HEAD → [Node A] → NULL
```
- There's no "second-to-last" node
- We need to update HEAD itself to nullptr
- **This is why HEAD must be passed by reference!**

#### Understanding `delete HEAD` vs `HEAD = nullptr`

**Common Question:** "How can I delete HEAD then assign it to null?"

**Answer:** `delete HEAD` doesn't delete the HEAD pointer variable - it deletes the **NODE whose address is stored in HEAD**.

**Visual Explanation:**

**Before deletion:**
```
HEAD = 0x1000  (HEAD stores this address)
       ↓
Memory 0x1000: [Node A: value=5, Next=NULL, Prev=NULL]
```

**After `delete HEAD;`:**
```
HEAD = 0x1000  (still contains old address - DANGEROUS!)
       ↓
Memory 0x1000: [FREED MEMORY - invalid]
```
- The **Node** is deleted/freed
- The **HEAD pointer variable** still exists
- HEAD contains an invalid address (dangling pointer)

**After `HEAD = nullptr;`:**
```
HEAD = nullptr  (now safely points nowhere)

Memory 0x1000: [FREED MEMORY]
```

- HEAD is updated to point to nothing
- Safe and clear - no dangling pointer

### Two Correct Ways to Handle This:

**Method 1: Delete first, then nullify (Most common)**

```cpp
delete HEAD;      // Free the node at address stored in HEAD
HEAD = nullptr;   // Update HEAD to point nowhere
```

**Method 2: Save, nullify, then delete**

```cpp
Node *NodeToDelete = HEAD;  // Save the address
HEAD = nullptr;             // Update HEAD first
delete NodeToDelete;        // Delete using saved reference
```

Both methods work! Method 1 is shorter and more commonly used.

### ❌ WRONG Approach - Memory Leak:

```cpp
HEAD = nullptr;  // Lost the reference!
delete HEAD;     // Deleting nullptr does nothing - NODE STILL IN MEMORY!
```

**Problem:** When you set `HEAD = nullptr` first, you **lose the only pointer** to the node, so you can never delete it. This creates a **memory leak**.

### CRITICAL: The `return` Statement

```cpp
return;  // MUST EXIT HERE!
```

**Why is this essential?**

Without `return`, the code continues executing:

```cpp
// After handling single node WITHOUT return:
HEAD = nullptr;  // HEAD is now null

Node *LastNode = HEAD;  // LastNode = nullptr
while (LastNode->Next != nullptr)  // ⚠️ CRASH! nullptr->Next
```

**The `return` prevents this crash** by exiting the function after handling the single node case.

---

### Step 3: Find the Last Node (Multiple Node Case)

```cpp
Node *LastNode = HEAD;
while (LastNode->Next != nullptr)
{
    LastNode = LastNode->Next;
}
```

**How this works:**
```
HEAD → [A] ⟷ [B] ⟷ [C] → NULL

Iteration 1: LastNode = A, A->Next != null ✓, move to B
Iteration 2: LastNode = B, B->Next != null ✓, move to C
Iteration 3: LastNode = C, C->Next == null ✗, exit loop

LastNode now points to C (the last node)
```

**Why we can do this safely:**

- We already handled the empty list case (Step 1)
- We already handled the single node case (Step 2)
- So we're guaranteed to have at least 2 nodes here
- Therefore, HEAD is not null and the traversal is safe

---

### Step 4: Update Second-to-Last Node's Next Pointer

```cpp
LastNode->Prev->Next = nullptr;
```

**Breaking this down:**
```
HEAD → [A] ⟷ [B] ⟷ [C] → NULL
              ↑        ↑
           Prev    LastNode
```

- `LastNode` = Node C (the last node)
- `LastNode->Prev` = Node B (the second-to-last node)
- `LastNode->Prev->Next` = Node B's Next pointer
- Set it to `nullptr` to make B the new last node

**After this step:**
```
HEAD → [A] ⟷ [B] → NULL   [C] (orphaned, ready to delete)
```

**No null check needed here because:**

- We already handled single node case (where there's no Prev)
- In multiple node case, `LastNode->Prev` is guaranteed to exist

---

### Step 5: Delete the Last Node

```cpp
delete LastNode;
```

- Frees the memory occupied by the last node
- The node at the address stored in `LastNode` is deleted

**Final result:**
```
HEAD → [A] ⟷ [B] → NULL  ✓
```

---

## Common Mistake

### 1.Not Understanding `delete HEAD`

```cpp
// Misunderstanding: "delete HEAD makes HEAD disappear"
delete HEAD;  // HEAD still exists! Just points to freed memory
```

**Fix:** Understand that:
- `delete HEAD` deletes the **Node** at the address in HEAD
- HEAD (the pointer variable) still exists
- That's why we need `HEAD = nullptr` after

---

## Edge Cases Handled

### Case 1: Empty List ✓
```
Before: HEAD → NULL
Action: Return immediately
After:  HEAD → NULL
```

### Case 2: List with ONE Node ✓
```
Before: HEAD → [A] → NULL

Steps:
1. Check: HEAD->Next == nullptr ✓
2. delete HEAD (frees Node A)
3. HEAD = nullptr
4. return (EXIT)

After:  HEAD → NULL
```

### Case 3: List with TWO Nodes ✓
```
Before: HEAD → [A] ⟷ [B] → NULL

Steps:
1. Skip single node check (A->Next != nullptr)
2. Traverse: LastNode = B
3. B->Prev->Next = nullptr (A->Next = nullptr)
4. delete LastNode (delete B)

After:  HEAD → [A] → NULL
```

### Case 4: List with MULTIPLE Nodes ✓
```
Before: HEAD → [A] ⟷ [B] ⟷ [C] ⟷ [D] → NULL

Steps:
1. Skip single node check
2. Traverse to last: LastNode = D
3. D->Prev->Next = nullptr (C->Next = nullptr)
4. delete LastNode (delete D)

After:  HEAD → [A] ⟷ [B] ⟷ [C] → NULL
```

---

## Key Concepts Explained

### 1. What `delete HEAD` Actually Does
```
HEAD is a POINTER VARIABLE that stores an ADDRESS
The NODE is the actual data in memory at that address

HEAD = 0x1000 → [Node at 0x1000: value, Next, Prev]
      ↑               ↑
   Pointer         Actual Node

delete HEAD:
- Deletes the NODE at address 0x1000
- HEAD (the variable) still exists
- HEAD still contains 0x1000 (now invalid - dangling pointer)

HEAD = nullptr:
- Updates HEAD to point nowhere
- Makes it safe (no dangling pointer)
```

### 2. Why We Need `return` After Special Cases

Special cases are **complete solutions** for specific scenarios. After handling them, there's nothing left to do. The `return` prevents the rest of the code from executing when it shouldn't.

### 3. Order of Operations Matters

```cpp
// ✓ CORRECT
delete HEAD;
HEAD = nullptr;

// ✓ ALSO CORRECT
Node *temp = HEAD;
HEAD = nullptr;
delete temp;

// ✗ WRONG - Memory leak
HEAD = nullptr;
delete HEAD;
```

---

## Logic Flow Diagram
```
START
  ↓
Is HEAD null? ──YES──> Return (empty list)
  ↓ NO
Is HEAD->Next null? ──YES──> Delete HEAD, Set HEAD=nullptr, Return (single node)
  ↓ NO
Traverse to find last node
  ↓
Update second-to-last node's Next = nullptr
  ↓
Delete last node
  ↓
END
```

---

## Summary

This function correctly deletes the last node by:

1. **Checking for empty list** - Safety first
2. **Handling single node specially** - Requires updating HEAD and returning
3. **Understanding `delete` vs pointer assignment** - Delete frees memory, nullptr makes pointer safe
4. **Always returning after special cases** - Prevents continuing when done
5. **Traversing to find last node** - For multiple node case
6. **Updating second-to-last node** - Makes it the new last node
7. **Deleting the last node** - Frees memory

**Critical Takeaways:**

- `delete HEAD` deletes the node at HEAD's address, not the HEAD pointer itself
- Always delete BEFORE setting to nullptr (or save reference first)
- Always `return` after handling complete special cases
- Pass HEAD by reference when you need to modify it

# Visuals

![image.png](Operations%20-%20Delete%20Last%20Node%202edd-5c35/image.png)

![image.png](Operations%20-%20Delete%20Last%20Node%202edd-5c35/image%201.png)

![image.png](Operations%20-%20Delete%20Last%20Node%202edd-5c35/image%202.png)