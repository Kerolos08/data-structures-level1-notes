# Operations -Insert At Beginning

# Code

```cpp
#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *Prev;
    Node *Next;
};

void PrintList(Node *HEAD)
{
    while (HEAD != nullptr)
    {
        cout << HEAD->value << " ";
        HEAD = HEAD->Next;
        cout << endl;
    }
}

void InserAtBeginning(int value, Node *&HEAD)
{
		/*
    1-Create a new node with the desired value.
    2-Set the next pointer of the new node to the current head of the list.
    3-Set the previous pointer of the current head to the new node.
    4-Set the new node as the new head of the list.
    */
    
    Node *NewNode = new Node;
    NewNode->value = value;
    NewNode->Next = HEAD;
    NewNode->Prev = nullptr;

    if (HEAD != nullptr)
    {
        // if the node is added to an empty linked list
        HEAD->Prev = NewNode;
    }

    HEAD = NewNode;
}

int main()
{
    Node *HEAD = nullptr;
    InserAtBeginning(5, HEAD);
    InserAtBeginning(4, HEAD);
    InserAtBeginning(3, HEAD);
    InserAtBeginning(2, HEAD);
    InserAtBeginning(1, HEAD);

    PrintList(HEAD);

    return 0;
}
```

# Notes

### **Each Node**

A node has two pointers:

```cpp
Node* Next;// points to the next node
Node* Prev;// points to the previous node
```

---

### **Steps to Insert at the Beginning**

When inserting a new node `NewNode` at the start:

1. Create the new node:

```cpp
Node* NewNode =newNode();
NewNode->value = value;
```

1. Point it forward to the current head:

```cpp
NewNode->Next = HEAD;
```

1. Its previous pointer should be NULL:

```cpp
NewNode->Prev =nullptr;
```

1. **If the list is not empty**, make the old first node point back to the new node:

```cpp
if (HEAD !=nullptr)
    HEAD->Prev = NewNode;
```

1. Move the head to the new node:

```cpp
HEAD = NewNode;
```

---

### **Remember**

- `HEAD` itself **does not have a Prev pointer**.
    
    The `Prev` belongs to the node `HEAD` is pointing to.
    
- Forward and backward links must **always be consistent**:

```
NewNode <-> OldFirst
```

- If the list is empty (`HEAD == nullptr`), skip step 4 because there’s no old node.

---

### Important

- Empty list: the new node becomes first → no old node to update
- Non-empty list: the new node becomes first → old first node’s `Prev` must point to new node

# Visuals

![image.png](Operations%20-Insert%20At%20Beginning/image.png)

![image.png](Operations%20-Insert%20At%20Beginning/b4b8acd6-822a-48a3-b825-7db9a1ab29fb.png)

![image.png](Operations%20-Insert%20At%20Beginning/image%201.png)

![image.png](Operations%20-Insert%20At%20Beginning/image%202.png)