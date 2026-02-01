#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> MyStack1;
    stack<int> MyStack2;

    // Push into stack1
    MyStack1.push(10);
    MyStack1.push(20);
    MyStack1.push(30);
    MyStack1.push(40);

    // Push into stack2
    MyStack2.push(50);
    MyStack2.push(60);
    MyStack2.push(70);
    MyStack2.push(80);

    // swabing stack1 and stack2
    MyStack1.swap(MyStack2);

    // Printing stack1
    cout << "MyStack1: ";
    while (!MyStack1.empty())
    {
        cout << MyStack1.top() << " ";
        MyStack1.pop();
    }

    cout << "\n";

    // Printing stack2
    cout << "MyStack2: ";
    while (!MyStack2.empty())
    {
        cout << MyStack2.top() << " ";
        MyStack2.pop();
    }
    return 0;
}