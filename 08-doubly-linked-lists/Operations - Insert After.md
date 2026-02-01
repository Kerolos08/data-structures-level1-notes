# Operations - Insert After

# Code

```cpp
void InsertAfter(int value, Node* Current)
{
    if (Current == nullptr)
        return;

    Node* NewNode = new Node;
    NewNode->value = value;
    NewNode->Prev = Current;
    NewNode->Next = Current->Next;

    if (Current->Next != nullptr)
        Current->Next->Prev = NewNode;

    Current->Next = NewNode;
}
```

# Notes

## **Insert After**

Insert a new node **after a given node (`Current`)** in a doubly linked list.

### Before:

```
Current <-> OldNext
```

### After:

```
Current <-> NewNode <-> OldNext
```

---

## **Node Structure Reminder**

```cpp
classNode {
public:
int value;
    Node* Prev;
    Node* Next;
};
```

Each node must always correctly know:

- Who is **before** it (`Prev`)
- Who is **after** it (`Next`)

---

## **Required Conditions**

- `Current` must not be `nullptr`
- `Current` can be:
    - A middle node
    - The last node

---

## **Conceptual Steps (Important)**

To insert `NewNode` after `Current`, we must fix **four connections**:

1. `NewNode` → knows who is before it
2. `NewNode` → knows who is after it
3. Old next node → updates who is before it
4. `Current` → updates who is after it

---

## **Logic**

### Step 1: Create the new node

```cpp
Node* NewNode =new Node;
NewNode->value = value;
```

---

### Step 2: Connect New Node backward

```cpp
NewNode->Prev = Current;
```

New Node now knows who comes before it.

---

### Step 3: Connect New Node forward

```cpp
NewNode->Next = Current->Next;
```

New Node now knows who comes after it.

---

### Step 4: Fix the old next node (CRITICAL)

```cpp
if (Current->Next !=nullptr)
    Current->Next->Prev = NewNode;
```

### Why this is necessary:

- Before insertion:

```cpp
Current <-> OldNext
```

- After insertion:

```cpp
NewNode <-> OldNext
```

So `OldNext->Prev` must change from `Current` to `NewNode`.

---

### Step 5: Fix Current’s next pointer

```cpp
Current->Next = NewNode;
```

Current now points forward to New Node.

---

## **Why Checking for NULL**

```cpp
if (Current->Next !=nullptr)
```

- If `Current` is the last node:

```cpp
Current->Next ==nullptr
```

- There is no `OldNext` to update
- Skipping the check causes a crash

# Visuals

![image.png](Operations%20-%20Insert%20After%202e7d-ad63/image.png)

![image.png](Operations%20-%20Insert%20After%202e7d-ad63/image%201.png)

![image.png](Operations%20-%20Insert%20After%202e7d-ad63/image%202.png)