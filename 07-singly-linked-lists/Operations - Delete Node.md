# Operations  - Delete Node

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

void DeleteNode(Node *HEAD, int value)
{
    Node *Current = HEAD, *Prev = HEAD;

    if (HEAD == NULL)
    {
        // Checks if the list is empty
        return;
    }

    if (Current->value == value)
    {
        // Checks if the first node is our node
        HEAD = Current->Next;
        delete Current;
        return;
    }

    while (Current != NULL && Current->value != value)
    {
        // Setting the Prev and current to its right values
        Prev = Current;
        Current = Current->Next;
    }

    if (Current == NULL)
    {
        // Checks if the value is not present
        // If we reach the end of the list
        return;
    }

    // Remove Node
    Prev->Next = Current->Next;
    delete Current;
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

    DeleteNode(HEAD, 3);

    PrintList(HEAD);

    return 0;
}
```

# Code Explanation

### Goal

Delete a node that contains a **specific value** from a singly linked list.

---

### Function Signature

```cpp
voidDeleteNode(Node*& head, int Value)
```

- `head` is passed **by reference** because it may change.
- `Value` is the value we want to delete.

---

### Pointers Used

```cpp
Node* Current = head;
Node* Prev = head;
```

- `Current` → used to search for the node.
- `Prev` → keeps track of the node **before** `Current`.

---

### Case 1: Empty List

```cpp
if (head == NULL)
return;
```

- No nodes → nothing to delete.
- Must check this first to avoid errors.

---

### Case 2: The Node to Delete is the Head

```cpp
if (Current->value == Value)
{
head = Current->next;
delete Current;
return;
}
```

Why this case is special:

- `head` has no previous node.
- We must move `head` to the next node.
- Then delete the old head.

---

### Searching for the Node

```cpp
while (Current !=NULL && Current->value != Value)
{
    Prev = Current;
    Current = Current->next;
}
```

Important notes:

- The loop stops for **two reasons**:
    1. Value is found
    2. We reached the end (`Current == NULL`)

---

### Case 3: Value Not Present

```cpp
if (Current == NULL)
return;
```

Why this check is mandatory:

- The loop does NOT tell us why it stopped.
- If `Current == NULL`, the value was not found.
- We must stop to avoid accessing:
    
    ```cpp
    Current->next //= NULL
    ```
    

---

### Case 4: Delete a Middle or Last Node

```cpp
Prev->next = Current->next;
delete Current;
```

 Explanation:

- Bypass the node to be deleted.
- Free memory to avoid leaks.

# Visuals

![image.png](Operations%20-%20Delete%20Node/image.png)

![image.png](Operations%20-%20Delete%20Node/image%201.png)