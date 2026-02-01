# Operations  - Delete First Node

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

void DeleteFirstNode(Node *&HEAD)
{
    Node *FirstNode = HEAD;
    if (HEAD == nullptr)
    {
        return;
    }

    HEAD = FirstNode->Next;
    delete FirstNode;
    return;
}

int main()
{
    Node *HEAD = NULL;

    InsertAtTheEnd(1, HEAD);
    InsertAtTheEnd(2, HEAD);
    InsertAtTheEnd(3, HEAD);
    InsertAtTheEnd(4, HEAD);
    InsertAtTheEnd(5, HEAD);
    InsertAtTheEnd(6, HEAD);

    PrintList(HEAD);

    DeleteFirstNode(HEAD);

    PrintList(HEAD);

    return 0;
}
```

# Code Explanation

### Purpose

Delete the **first node (head)** of a singly linked list.

---

### Function Signature

```cpp
voidDeleteFirstNode(Node*& HEAD)
```

- `HEAD` is passed **by reference** because it will change.
- No value is needed because we always delete the first node.

---

### Steps

### Check if the list is empty

```cpp
if (HEAD ==NULL)
return;

```

- If the list is empty, there is nothing to delete.
- Prevents segmentation fault.

---

### Store the current head

```cpp
Node* FirstNode = HEAD;
```

- Keep a temporary pointer to the first node.
- Needed so we can delete it later.

---

### Move head to the next node

```cpp
HEAD = FirstNode->Next;
```

- The second node becomes the new head.
- Works for:
    - one-node list (HEAD becomes NULL)
    - multi-node list

---

### Delete the old head

```cpp
delete FirstNode;
```

- Frees memory.
- Prevents memory leak.

# Visuals

![image.png](Operations%20-%20Delete%20First%20Node/image.png)

![image.png](Operations%20-%20Delete%20First%20Node/image%201.png)