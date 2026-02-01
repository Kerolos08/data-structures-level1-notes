#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *Next;
};

void InsertAtBeginning(int value, Node *&HEAD)
{
    Node *new_Node = new Node;

    new_Node->value = value;
    new_Node->Next = HEAD;

    HEAD = new_Node;
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

Node *Find(Node *HEAD, int value)
{
    while (HEAD != NULL)
    {
        if (HEAD->value == value)
        {
            return HEAD;
        }
        HEAD = HEAD->Next;
    }
    return NULL;
}

void Insert_After(Node *Prev, int value)
{
    if (Prev == NULL)
    {
        cout << "\nThe given prevous node should not be NULL";
        return;
    }

    Node *New_Node = new Node;
    New_Node->value = value;
    New_Node->Next = Prev->Next;
    Prev->Next = New_Node;
}

int main()
{
    Node *HEAD = NULL;

    InsertAtBeginning(1, HEAD);
    InsertAtBeginning(2, HEAD);
    InsertAtBeginning(3, HEAD);
    InsertAtBeginning(4, HEAD);
    InsertAtBeginning(5, HEAD);

    PrintList(HEAD);
    Node *N1 = NULL;

    N1 = Find(HEAD, 2);
    Insert_After(N1, 500);

    PrintList(HEAD);
    return 0;
}
