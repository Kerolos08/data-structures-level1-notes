# Operations - Insert After

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

void PrintList(Node *HEAD)
{
    while (HEAD != NULL)
    {
        cout << HEAD->value << " ";
        HEAD = HEAD->Next;
    }
    cout << "\n";
}

Node *Find(Node *HEAD, int value)
{
    while (HEAD != NULL)
    {
        if (HEAD->value == value)
        {
            return HEAD;
        }
        HEAD = HEAD->Next;
    }
    return NULL;
}

void Insert_After(Node *Prev, int value)
{
    if (Prev == NULL)
    {
        cout << "\nThe given prevous node should not be NULL";
        return;
    }

    Node *New_Node = new Node;
    New_Node->value = value;
    New_Node->Next = Prev->Next;
    Prev->Next = New_Node;
}

int main()
{
    Node *HEAD = NULL;

    InsertAtBeginning(1, HEAD);
    InsertAtBeginning(2, HEAD);
    InsertAtBeginning(3, HEAD);
    InsertAtBeginning(4, HEAD);
    InsertAtBeginning(5, HEAD);

    PrintList(HEAD);
    Node *N1 = NULL;

    N1 = Find(HEAD, 2);
    Insert_After(N1, 500);

    PrintList(HEAD);
    return 0;
}
```

# Code Explanation

### Singly Linked List – Insert After

### Purpose

- Insert a **new node after a given node** in a singly linked list
- The position is defined by a **pointer to an existing node**

---

### Function Parameters

- `Prev` → pointer (address) of the node **after which** insertion happens
- `value` → data to be stored in the new node
- `Prev` **must not be NULL**

---

### Validation

- If `Prev == NULL`, insertion is not possible
- Prevents accessing invalid memory

---

### Node Creation

- A new node is created dynamically using `new`
- The node is allocated in **heap memory**

---

### Linking Steps

1. The new node’s `next` is set to `Prev->Next`
2. `Prev->Next` is updated to point to the new node

---

### Resulting Structure

Before insertion:

```
Prev → A → B → NULL
```

After insertion:

```
Prev → NewNode → A → B → NULL
```

---

### Key Points

- The function does not return anything
- The list is modified using **pointers (addresses)**
- Time complexity: **O(1)** (direct access to position)
- Safe insertion requires a valid `Prev` pointer

# Visuals

![image.png](Operations%20-%20Insert%20After/image.png)