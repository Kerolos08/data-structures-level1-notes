# Operations - Insert At End

# Code

```cpp
#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *Next;
};

void InsertAtBeginning(int value, Node *&HEAD)
{
    Node *new_Node = new Node;

    new_Node->value = value;
    new_Node->Next = HEAD;

    HEAD = new_Node;
}

void InsertAtTheEnd(int value, Node *&HEAD)
{
    Node *New_Node = new Node;
    New_Node->value = value;
    New_Node->Next = NULL;

    if (HEAD == NULL)
    {
        HEAD = New_Node;
        return;
    }

    Node *LastNode = HEAD; // HEAD is an initial value that will change to store the actual node address
    while (LastNode->Next != NULL)
    {
        // Loop ends when we have the LastNode Pointing to the final node
        LastNode = LastNode->Next;
    }

    LastNode->Next = New_Node;
    return;
}

void PrintList(Node *HEAD)
{
    while (HEAD != NULL)
    {
        cout << HEAD->value << " ";
        HEAD = HEAD->Next;
    }
    cout << "\n";
}

int main()
{
    Node *HEAD = NULL;

    InsertAtTheEnd(1, HEAD);
    InsertAtTheEnd(2, HEAD);
    InsertAtTheEnd(3, HEAD);

    InsertAtBeginning(99, HEAD);
    PrintList(HEAD);

    InsertAtTheEnd(4, HEAD);
    InsertAtTheEnd(5, HEAD);

    PrintList(HEAD);

    return 0;
}
```

# Code Explanation

### Function Parameters

- `HEAD` → pointer to the first node (passed **by reference**).
- `value` → data stored in the new node.

> HEAD must be passed by reference because it may change when the list is empty.
> 

---

### Node Creation

- A new node is created dynamically using `new`.
- The node is stored in **heap memory**.
- The pointer stores the **address** of the node.

---

### Node Initialization (VERY IMPORTANT)

- The node’s data must be assigned.
- `Next` must be initialized to `NULL`.

> Forgetting to set Next = NULL causes undefined behavior.
> 

---

### Case 1: Empty List

- If `HEAD == NULL`:
    - The new node becomes the **first and last node**.
    - `HEAD` is updated to point to the new node.
    - Function returns immediately.

---

### Case 2: List Is Not Empty

- Start from `HEAD`.
- Traverse the list until reaching the last node.
- The last node is identified when `Next == NULL`.

---

### Linking at the End

- The last node’s `Next` is updated to point to the new node.
- The new node becomes the new tail of the list.

---

### Final Structure

Before insertion:

```
1 → 2 → 3 → NULL
```

After insertion:

```
1 → 2 → 3 → NewNode → NULL
```

---

### Time Complexity

- **O(n)** — traversal is required to reach the last node.

---

### Common Weak Points / Mistakes

- Forgetting to set `New_Node->Next = NULL`.
- Not assigning the value to the new node.
- Not passing `HEAD` by reference.
- Using `while (LastNode != NULL)` instead of checking `LastNode->Next`.

---

### 🧠 Important Note

- Insert at Beginning → **O(1)**
- Insert at End → **O(n)**
- Using a `tail` pointer can optimize Insert at End to **O(1)**.

# Visual

![image.png](Operations%20-%20Insert%20At%20End/3f3730f4-1aa2-4764-aaf8-275f85d28f48.png)

![image.png](Operations%20-%20Insert%20At%20End/image.png)

![image.png](Operations%20-%20Insert%20At%20End/image%201.png)