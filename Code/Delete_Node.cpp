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

void DeleteNode(Node *&HEAD, int value)
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

void DeleteNode2(Node *&HEAD, int value)
{
    Node *Prev = HEAD, *Current = HEAD;

    if (Current->Next == NULL)
    {
        return;
    }

    if (Current->value == value)
    {
        HEAD = Current->Next;
        delete Current;
        return;
    }

    while (Current != NULL)
    {
        if (Current->value == value)
        {
            Prev->Next = Current->Next;
            delete Current;
            return;
        }

        Prev = Current;
        Current = Current->Next;
    }
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
    DeleteNode2(HEAD, 5);

    PrintList(HEAD);

    return 0;
}
