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