# Doubly Linked List Implementation

# Code

```cpp
#include <iostream>
using namespace std;

class Node
{
    public:
    int value;
    Node * Prev;
    Node * Next;
};

int main ()
{
    Node * HEAD;

    //Creating 3 Nodes
    Node * Node1 = nullptr;
    Node * Node2 = nullptr;
    Node * Node3 = nullptr;

    //Allocating 3 Nodes in Heap
    Node1 = new Node();
    Node2 = new Node();
    Node3 = new Node();

    //Assigning values
    Node1->value = 1;
    Node2->value = 2;
    Node3->value = 3;

    //Connecting Nodes together
    Node1->Prev = nullptr;
    Node1->Next = Node2;

    Node2->Prev = Node1;
    Node2->Next = Node3;

    Node3->Prev = Node2;
    Node3->Next = nullptr;

    //Print Nodes
    HEAD = Node1;
    while (HEAD != nullptr)
    {
        cout << HEAD->value << endl;
        HEAD = HEAD->Next;
    }
}
```

# Output

```cpp
1
2
3
```

# Visual Diagram

![image.png](Doubly%20Linked%20List%20Implementation/image.png)