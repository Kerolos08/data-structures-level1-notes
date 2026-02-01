# Operations - Find Node

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

Node * Find (int value, Node * HEAD)
{
    while (HEAD != nullptr)
    {
        if (HEAD->value == value)
        {
            return HEAD;
        }
        HEAD = HEAD->Next;
    }
    return nullptr;
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

    Node * N1 = Find (3, HEAD);
    if (N1 != nullptr)
    {
        cout << "\nNode Found!";
    }
    else
    {
        cout << "\nNode is not Found!";
    }

    return 0;
}
```