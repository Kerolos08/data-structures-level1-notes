# Operations - Delete Node

# Code

```cpp
void DeleteNode(Node *&HEAD, Node *&NodeToDelete)
{
    if (HEAD == nullptr || NodeToDelete == nullptr)
    {
        // List is empty
        return;
    }

    if (HEAD == NodeToDelete)
    {
        HEAD = NodeToDelete->Next;
    }

    if (NodeToDelete->Prev != nullptr)
    {
        NodeToDelete->Prev->Next = NodeToDelete->Next;
    }

    if (NodeToDelete->Next != nullptr)
    {
        NodeToDelete->Next->Prev = NodeToDelete->Prev;
    }

    delete NodeToDelete;
}
```

# Code Explanation

Deletes a specific node from a doubly linked list and frees its memory.

## Function Signature

```cpp
void DeleteNode(Node*& head, Node*& NodeToDelete)
```

**Parameters:**

- `Node*& head` - Passed by **reference** (necessary - we might update the head pointer)
- `Node*& NodeToDelete` - Passed by **reference** (NOT strictly necessary in this implementation)

---

## Step-by-Step Breakdown

### Step 1: Safety Check

```cpp
if (head == NULL || NodeToDelete == NULL) 
{
    return;
}
```

- Prevents crashes if the list is empty or the node pointer is invalid
- Exit early if there's nothing to delete

### Step 2: Handle Deleting the Head Node

```cpp
if (head == NodeToDelete) 
{
    head = NodeToDelete->next;
}
```

- If we're deleting the first node, update `head` to point to the second node
- **This is why `head` MUST be passed by reference** - we're changing what it points to

### Step 3: Update Next Node's Previous Pointer

```cpp
if (NodeToDelete->next != NULL) 
{
    NodeToDelete->next->prev = NodeToDelete->prev;
}
```

- **Why check?** If `next == NULL`, the node is the last one, so there's no next node to update
- **What happens if next is NULL?** This block is **skipped** entirely (implicit behavior)
- **If next exists:** Connect the next node's `prev` to skip over the deleted node

### Step 4: Update Previous Node's Next Pointer

```cpp
if (NodeToDelete->prev != NULL) 
{
    NodeToDelete->prev->next = NodeToDelete->next;
}
```

- **Why check?** If `prev == NULL`, the node is the first one (head), so there's no previous node to update
- **What happens if prev is NULL?** This block is **skipped** entirely (implicit behavior)
- **If prev exists:** Connect the previous node's `next` to skip over the deleted node

### Step 5: Delete the Node

```cpp
delete NodeToDelete;
```
- Frees the memory occupied by the node

---

## Key Points About Pointer Checks

### The checks prevent null pointer dereferencing:

**Scenario 1: Deleting the LAST node**
```
[Node A] ⟷ [Node B] ⟷ [Node C (delete)] → NULL
```
- `prev` exists ✓ → Update Node B's next pointer
- `next` is NULL ✗ → Skip trying to update (would crash without the check)

**Scenario 2: Deleting the FIRST node**
```
NULL ← [Node A (delete)] ⟷ [Node B] ⟷ [Node C]
```
- `prev` is NULL ✗ → Skip trying to update (would crash without the check)
- `next` exists ✓ → Update Node B's prev pointer

**Scenario 3: Deleting a MIDDLE node**
```
[Node A] ⟷ [Node B (delete)] ⟷ [Node C]
```

- Both `prev` and `next` exist ✓ → Update both neighbors

---

## Pass-by-Reference Analysis

### Why `head` is passed by reference:

✓ **NECESSARY** - We modify what `head` points to when deleting the first node

### Why `NodeToDelete` is passed by reference:

✗ **NOT NECESSARY** in this implementation because:

- We never reassign `NodeToDelete` (like `NodeToDelete = something`)
- We only delete the memory it points to
- **Better practice would be:** Set `NodeToDelete = NULL` after deletion to prevent dangling pointers

**Improved version would look like:**

```cpp
delete NodeToDelete;
NodeToDelete = NULL;  // ← Now pass-by-reference makes sense!
```

---

## Implicit Behavior Notes

The code doesn't explicitly document what happens when `next` or `prev` is `NULL`:

- **Implicit logic:** "If there's no node on that side, skip updating it"
- The necessary connections are maintained by the checks that DO execute
- After deletion, remaining nodes stay properly linked

### Scenario 1: When `next == NULL` (Deleting LAST node)

```cpp
[Node A] ⟷ [Node B] ⟷ [Node C (delete)] → NULL
                        ↑
                     prev exists
                     next is NULL
```

**What happens:**

1. **Skip updating next node** (because there is no next node):

```cpp
   if (NodeToDelete->next != NULL) {  // FALSE - skipped
       NodeToDelete->next->prev = NodeToDelete->prev;
   }
```

1. **Update previous node's next pointer**:

```cpp
   if (NodeToDelete->prev != NULL) {  // TRUE - executed
       NodeToDelete->prev->next = NodeToDelete->next;
       // Node B's next = NULL
   }
```

**Result:** Node B becomes the new last node with `next = NULL`

---

## Scenario 2: When `prev == NULL` (Deleting FIRST node)
```
NULL ← [Node A (delete)] ⟷ [Node B] ⟷ [Node C]
          ↑
       prev is NULL
       next exists
```

**What happens:**

1. **Update next node's previous pointer**:

```cpp
   if (NodeToDelete->next != NULL) {  // TRUE - executed
       NodeToDelete->next->prev = NodeToDelete->prev;
       // Node B's prev = NULL
   }
```

1. **Skip updating previous node** (because there is no previous node):

```cpp
   if (NodeToDelete->prev != NULL) {  // FALSE - skipped
       NodeToDelete->prev->next = NodeToDelete->next;
   }
```

**Result:** Node B becomes the new first node with `prev = NULL`

---

## Summary

✓ **If `next == NULL`:** Update the previous node's `next` to `NULL` (making it the new last node)

✓ **If `prev == NULL`:** Update the next node's `prev` to `NULL` (making it the new first node)

The code assigns the `NULL` value to the appropriate pointer, effectively "closing" that end of the list!

# Visuals

![image.png](Operations%20-%20Delete%20Node%202ebd-6ede/image.png)

![image.png](Operations%20-%20Delete%20Node%202ebd-6ede/image%201.png)

![image.png](Operations%20-%20Delete%20Node%202ebd-6ede/image%202.png)