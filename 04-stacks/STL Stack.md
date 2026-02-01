# STL: Stack

# Code

```cpp
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
```

## Output

```cpp
5

50
40
30
20
10 
//LIFO
```

# Notes

- **To add an Item to a stack you use:**
    - **Push.**
    
- **To remove the top item from stack you use:**
    - **Pop.**
    
- **To access the last item in stack you use:**
    - **Top.**
    
- **To get the count of the items in stack you use:**
    - **size( ).**
    
- **To check if the stack has items or not you use:**
    - **empty( ).**
    
- **LIFO means Last In First Out.**
    - **True.**