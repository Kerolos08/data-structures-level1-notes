# Operations - Insert at End

# Code

```cpp
void InsertAtEnd(Node *HEAD, int value)
{
    /*
        1-Create a new node with the desired value.
        2-Traverse the list to find the last node.
        3-Set the next pointer of the last node to the new node.
        4-Set the previous pointer of the new node to the last node.
    */
    Node *NewNode = new Node();
    NewNode->value = value;
    NewNode->Next = nullptr;
    if (HEAD == nullptr)
    {
        NewNode->Prev = nullptr;
        HEAD = NewNode;
    }
    else
    {
        Node *LastNode = HEAD;
        while (LastNode->Next != nullptr)
        {
            LastNode = LastNode->Next;
        }
        LastNode->Next = NewNode;
        NewNode->Prev = LastNode;
    }
}
```

# Code Explanation

inserts a new node at the **end** of a doubly linked list.

## Step-by-Step Breakdown

**Step 1: Create the new node**

- A new node is created and assigned the value you want to insert
- Its `Next` pointer is set to `nullptr` (since it will be the last node)

**Step 2: Handle empty list case**

- If the list is empty (`HEAD == nullptr`):
    - Set the new node's `Prev` pointer to `nullptr` (it's the first node, so no previous node)
    - Make this new node the head of the list

**Step 3: Handle non-empty list case**

- If the list already has nodes:
    - Start at the head and traverse through the list
    - Keep moving to the next node until you reach the last node (the one whose `Next` pointer is `nullptr`)
    - Once you find the last node:
        - Connect the last node's `Next` pointer to the new node
        - Connect the new node's `Prev` pointer back to the last node

# Visuals

![image.png](Operations%20-%20Insert%20at%20End/image.png)

![image.png](Operations%20-%20Insert%20at%20End/image%201.png)