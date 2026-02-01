#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> MyQueue;

    MyQueue.push(10);
    MyQueue.push(20);
    MyQueue.push(30);
    MyQueue.push(40);
    MyQueue.push(50);

    cout << "\nCount: " << MyQueue.size() << endl;
    cout << "\nFront: " << MyQueue.front() << endl;
    cout << "\nBack: " << MyQueue.back() << endl;

    cout << "\nMy Queue: ";
    while (!MyQueue.empty())
    {
        cout << MyQueue.front() << " ";
        MyQueue.pop();
    }

    return 0;
}