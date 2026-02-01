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

int main()
{
    Node *HEAD = nullptr;
    InserAtBeginning(5, HEAD);
    InserAtBeginning(4, HEAD);
    InserAtBeginning(3, HEAD);
    InserAtBeginning(2, HEAD);
    InserAtBeginning(1, HEAD);

    PrintList(HEAD);

    cout << "\n\n";

    InsertAtEnd(HEAD, 600);

    PrintList(HEAD);

    return 0;
}