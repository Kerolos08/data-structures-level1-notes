# Singly Linked List Implementation

## Code

```cpp
#include <iostream>
using namespace std;

// creating node class
class Node
{
public:
    int Value;
    Node *Next;
};

int main()
{
		// Initialize 3 pointers in stack with initial value NULL
    Node *Head;
    Node *Node1 = NULL;
    Node *Node2 = NULL;
    Node *Node3 = NULL;

    // Allocating 3 Nodes in Heap
    Node1 = new Node();
    Node2 = new Node();
    Node3 = new Node();

    // Assigning Values
    Node1->Value = 1;
    Node2->Value = 2;
    Node3->Value = 3;

    // Connecting Nodes
    Node1->Next = Node2;
    Node2->Next = Node3;
    Node3->Next = NULL;

    //Print the linked list values
    Head = Node1;
    while (Head != NULL)
    {
        cout << Head->Value << endl;
        Head = Head->Next;
    }

    return 0;
}
```

## Output

```cpp
1
2
3
```

## Visual Diagram

![image.png](Singly%20Linked%20List%20Implementation/720206d7-6aaa-454a-a8f7-ff45be98ac04.png)