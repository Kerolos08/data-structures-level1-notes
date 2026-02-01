#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *Next;
};

void InsertNewNode(int value, Node *&HEAD)
{
    // allocate new node in heap
    Node *New_Node = new Node;

    // inserting data
    New_Node->value = value;
    New_Node->Next = HEAD;

    // moving HEAD to the new Node
    HEAD = New_Node;
}

void PrintList(Node *HEAD)
{
    while (HEAD != NULL)
    {
        cout << HEAD->value << endl;
        HEAD = HEAD->Next;
    }
}

int main()
{
    Node *HEAD = NULL;

    InsertNewNode(1, HEAD); // HEAD moved to the new node that was added and has value one and it became first node //5
    InsertNewNode(2, HEAD); // HEAD moved to the new node that was added and has value two and it became first node //4
    InsertNewNode(3, HEAD); // HEAD moved to the new node that was added and has value two and it became first node //3
    InsertNewNode(4, HEAD); // HEAD moved to the new node that was added and has value two and it became first node //2
    InsertNewNode(5, HEAD); // HEAD moved to the new node that was added and has value two and it became first node //1

    PrintList(HEAD);

    return 0;
}
