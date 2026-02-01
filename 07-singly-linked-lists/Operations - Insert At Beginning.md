# Operations - Insert At Beginning

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

void InsertNewNode(int value, Node *&HEAD)
{
    // allocate new node in heap
    Node *New_Node = new Node;

    // inserting data
    New_Node->value = value;
    New_Node->Next = HEAD;

    // moving HEAD to the new Node
    HEAD = New_Node;
}

void PrintList(Node *HEAD)
{
    while (HEAD != NULL)
    {
        cout << HEAD->value << endl;
        HEAD = HEAD->Next;
    }
}

int main()
{
    Node *HEAD = NULL;

    InsertNewNode(1, HEAD); // HEAD moved to the new node that was added and has value one and it became first node //5
    InsertNewNode(2, HEAD); // HEAD moved to the new node that was added and has value two and it became first node //4
    InsertNewNode(3, HEAD); // HEAD moved to the new node that was added and has value two and it became first node //3
    InsertNewNode(4, HEAD); // HEAD moved to the new node that was added and has value two and it became first node //2
    InsertNewNode(5, HEAD); // HEAD moved to the new node that was added and has value two and it became first node //1

    PrintList(HEAD);

    return 0;
}
```

# Code Explanation

### Singly Linked List – Insert at Beginning

- A **singly linked list** is made of **nodes**
- Each node contains:
    - `value` → data
    - `next` → pointer to the next node

---

### Node Structure

- Nodes are created dynamically in **heap memory**
- They are connected using pointers (not contiguous like arrays)

---

### Head Pointer

- `head` points to the **first node** in the list
- If `head == NULL` → the list is empty
- Losing `head` means losing access to the entire list

---

### Insert at Beginning

- A new node is created using `new`
- The new node’s `next` points to the current `head`
- `head` is updated to point to the new node
- `head` is passed **by reference** (`Node*&`) so the original head changes

---

### Insertion Order

- Inserting at the beginning reverses the order of input
- Example:
    
    ```
    Insert: 1 → 2 → 3 → 4 → 5
    Result: 5 → 4 → 3 → 2 → 1 → NULL
    ```
    

---

### Traversing the List

- Start from `head`
- Print `value`
- Move to `next`
- Stop when `NULL` is reached

# Visuals

![image.png](Operations%20-%20Insert%20At%20Beginning/image.png)