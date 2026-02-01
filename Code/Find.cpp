#include <iostream>
using namespace std;

class Node
{
    public:
    int value;
    Node * Next;
};

void InsertAtBeginning (int value, Node * &HEAD)
{
    Node * new_Node = new Node;

    new_Node->value = value;
    new_Node->Next = HEAD;

    HEAD = new_Node;
}

void PrintList(Node *HEAD)
{
    while (HEAD != NULL)
    {
        cout << HEAD->value << endl;
        HEAD = HEAD->Next;
    }
}

Node *Find (Node * HEAD, int value)
{
    while(HEAD != NULL)
    {
        if (HEAD->value == value)
        {
            return HEAD;
        }
        HEAD = HEAD->Next;
    }
    return NULL;
}

int main ()
{
    Node *HEAD = NULL;

    InsertAtBeginning(1, HEAD);
    InsertAtBeginning(2, HEAD);
    InsertAtBeginning(3, HEAD);
    InsertAtBeginning(4, HEAD);
    InsertAtBeginning(5, HEAD);

    PrintList(HEAD);

    if (Find(HEAD, 3) != NULL)
    {
        cout << "\nNode is found :)";
    }
    else
    {
        cout << "\nNode is not found";
    }

    return 0;
}
