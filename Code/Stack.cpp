#include <iostream>
#include <stack>
using namespace std;

int main()
{
    // Create stack of ints
    stack<int> stkNumbers;

    // Push into stack
    stkNumbers.push(10);
    stkNumbers.push(20);
    stkNumbers.push(30);
    stkNumbers.push(40);
    stkNumbers.push(50);

    cout << "Count: " << stkNumbers.size() << endl;

    // Can access the element by getting the top element and pop it from the stack.
    // Until the stack is empty.
    while (!stkNumbers.empty())
    {
        // Printing the first element in stack
        cout << stkNumbers.top() << endl;

        // Popping top element that accessed from the stack
        stkNumbers.pop();
    }

    return 0;
}