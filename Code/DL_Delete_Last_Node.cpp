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

void DeleteLastNode(Node *&HEAD)
{
    if (HEAD == nullptr)
    {
        // List is empty
        return;
    }

    if (HEAD->Next == nullptr)
    {
        delete HEAD;
        HEAD = nullptr;
        return;
    }

    // Node *LastNode = HEAD;
    // while (LastNode->Next != nullptr)
    // {
    //     LastNode = LastNode->Next;
    // }
    // LastNode->Prev->Next = nullptr;
    // delete LastNode;

    Node *Current = HEAD;
    // find the node before last node
    while (Current->Next->Next != nullptr)
    {
        Current = Current->Next;
    }
    Node *Temp = Current->Next; // temp points to the actual next node because we have the node before the last
    Current->Next = nullptr;
    delete Temp;
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

    DeleteLastNode(HEAD);

    PrintList(HEAD);

    return 0;
}