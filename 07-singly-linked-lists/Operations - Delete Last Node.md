# Operations - Delete Last Node

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

void DeleteLastNode(Node *&HEAD)
{
    Node *Current = HEAD;
    Node *Prev = HEAD;

    if (HEAD == nullptr)
    {
        return;
    }

    if (Current->Next == nullptr)
    {
        HEAD = nullptr;
        delete Current;
        return;
    }

    while (Current->Next != nullptr)
    {
        Prev = Current;
        Current = Current->Next;
    }

    Prev->Next = nullptr;
    delete Current;
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

    DeleteLastNode (HEAD);

    PrintList(HEAD);

    return 0;
}
```

# Code Explanation

### Purpose

Delete the **last node** in a singly linked list.

---

### Function Signature

```cpp
voidDeleteLastNode(Node*& HEAD)
```

- `HEAD` is passed **by reference** because it may change.
- No value is needed — we always delete the last node.

---

### Pointers Used

```cpp
Node* Current = HEAD;
Node* Prev = HEAD;
```

- `Current` → used to reach the last node.
- `Prev` → keeps the node **before** `Current`.

---

### Case 1: Empty List

```cpp
if (HEAD ==NULL)
return;
```

- No nodes → nothing to delete.
- Prevents segmentation fault.

---

### Case 2: One Node Only

```cpp
if (Current->Next ==NULL)
{
HEAD =NULL;
delete Current;
return;
}
```

- The only node is both head and last node.
- After deletion, the list becomes empty.

---

### Case 3: More Than One Node

### Traverse to the last node

```cpp
while (Current->Next !=NULL)
{
    Prev = Current;
    Current = Current->Next;
}
```

Why this condition?

- The last node is the one whose `Next == NULL`.
- When the loop ends:
    - `Current` → last node
    - `Prev` → node before last

---

### Remove the last node

```cpp
Prev->Next =NULL;
delete Current;
```

- Disconnect the last node.
- Free memory.

# Visuals

![image.png](Operations%20-%20Delete%20Last%20Node/image.png)

![image.png](Operations%20-%20Delete%20Last%20Node/image%201.png)