# Operations - Delete First Node

# Code

```cpp
void DeleteFirstNode(Node *&HEAD)
{
    if (HEAD == nullptr)
    {
        // List is empty
        return;
    }

    Node *NodeToDelete = HEAD;
    HEAD = HEAD->Next;
    if (HEAD != nullptr)
    {
        HEAD->Prev = nullptr;
    }

    delete NodeToDelete;
}
```

# Code Explanation

Deletes the first node (head) from a doubly linked list and frees its memory.

## Function Signature

```cpp
void DeleteFirstNode(Node *&HEAD)
```

**Parameters:**

- `Node*& HEAD` - Passed by **reference** (NECESSARY - we're changing what HEAD points to)

---

## Step-by-Step Breakdown

### Step 1: Safety Check

```cpp
if (HEAD == nullptr)
{
    return;
}
```

- **Why?** Prevents crashes if the list is empty
- Exit early if there's nothing to delete

---

### Step 2: Store the Node to Delete

```cpp
Node *NodeToDelete = HEAD;
```

- **Why?** We need to keep a reference to the first node before moving HEAD
- Without this, we'd lose access to the node we want to delete

---

### Step 3: Update HEAD Pointer

```cpp
HEAD = HEAD->Next;
```
- Move HEAD to point to the second node (which becomes the new first node)
- **This is why HEAD MUST be passed by reference** - we're changing what it points to

**Visual:**
```
Before: HEAD → [A] ⟷ [B] ⟷ [C]
               ↑
          NodeToDelete

After:  [A]    HEAD → [B] ⟷ [C]
        ↑
   NodeToDelete
```

---

### Step 4: Update New First Node's Previous Pointer (CRITICAL CHECK)

```cpp
if (HEAD != nullptr)
{
    HEAD->Prev = nullptr;
}
```

#### Why Check if HEAD != nullptr?

**This handles TWO scenarios:**

**Scenario 1: List has MULTIPLE nodes**
```
HEAD → [B] ⟷ [C]
```
- `HEAD` is NOT null ✓
- Execute: `HEAD->Prev = nullptr`
- **Result:** Node B becomes the proper first node with `Prev = nullptr`

**Scenario 2: List has ONLY ONE node**
```
HEAD → [A] → NULL
```

- After `HEAD = HEAD->Next`, HEAD becomes `NULL`
- `HEAD` is null ✗
- **Skip the update** (can't access `NULL->Prev` - would crash!)
- **Result:** List is now empty, `HEAD = nullptr`

---

### Step 5: Delete the Node

```cpp
delete NodeToDelete;
```

- Frees the memory occupied by the original first node

---

## Common Mistake - WRONG Version ❌

```cpp
if (HEAD != nullptr)
{
    HEAD->Next->Prev = nullptr;  // ❌ WRONG!
}
```

### Why is this wrong?

**After updating HEAD:**
```
[A]    HEAD → [B] ⟷ [C]
       (new first)  (second)
```

- `HEAD` points to Node B (the new first node)
- `HEAD->Next` points to Node C (the second node)
- `HEAD->Next->Prev` updates **Node C's previous pointer** (WRONG!)

**What we actually need:**
- Update **Node B's previous pointer** to `nullptr`
- Solution: `HEAD->Prev = nullptr` ✓

---

## Visual Comparison

### ✓ CORRECT: `HEAD->Prev = nullptr`
```
Step 1: [A]    HEAD → [B] ⟷ [C]

Step 2: [A]    HEAD → [B] ⟷ [C]
               NULL ← Prev (B's prev set to null)

Result: HEAD → [B] ⟷ [C]  ✓ Properly formed list!
```

### ✗ WRONG: `HEAD->Next->Prev = nullptr`
```
Step 1: [A]    HEAD → [B] ⟷ [C]

Step 2: [A]    HEAD → [B]   [C]
                      ↓     ↑
                    Next   NULL ← Prev (C's prev set to null - WRONG!)

Result: HEAD → [B] → [C]  ✗ B and C are disconnected!
```

---

## Edge Cases Handled

### Case 1: Empty List ✓
```
Before: HEAD → NULL
Action: Return immediately (nothing to delete)
After:  HEAD → NULL
```

### Case 2: List with ONE Node ✓
```
Before: HEAD → [A] → NULL
Action: 
  - NodeToDelete = HEAD (Node A)
  - HEAD = NULL
  - Skip updating HEAD->Prev (HEAD is null)
  - Delete Node A
After:  HEAD → NULL
```

### Case 3: List with MULTIPLE Nodes ✓
```
Before: HEAD → [A] ⟷ [B] ⟷ [C]
Action:
  - NodeToDelete = HEAD (Node A)
  - HEAD = Node B
  - HEAD->Prev = nullptr (Node B's prev)
  - Delete Node A
After:  HEAD → [B] ⟷ [C]
```

---

## Key Takeaways

1. **Always check for NULL before de referencing:**
    - Ask: "What if this pointer is NULL?"
    - Missing this check causes crashes
2. **Pointer clarity matters:**
    - After `HEAD = HEAD->Next`, HEAD points to a **different node**
    - `HEAD->Prev` updates the **current** node HEAD points to
    - `HEAD->Next->Prev` updates the **next** node's prev (usually wrong in this context)
3. **Pass by reference when modifying:**
    - HEAD must be passed by reference because we're reassigning it
    - Without `&`, the caller's HEAD wouldn't update
4. **Store before you move:**
    - Save `NodeToDelete = HEAD` before changing HEAD
    - Otherwise you lose the reference to the node you need to delete

# Visuals

![image.png](Operations%20-%20Delete%20First%20Node%202ebd-0caa/image.png)

![image.png](Operations%20-%20Delete%20First%20Node%202ebd-0caa/image%201.png)

![image.png](Operations%20-%20Delete%20First%20Node%202ebd-0caa/image%202.png)