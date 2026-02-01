# STL: Queue

# Code

```cpp
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
```

## Output

```cpp
Count: 5

Front: 10

Back: 50

My Queue: 10 20 30 40 50
```

# Quiz

- FIFO: means First In First Out.
    - True.
    
- If you want to print the first item in Queue, you use:
    - Front ( ).

- If you want to print the last item in Queue, you use:
    - Back ( ).
    
- If you want to print the count of items in Queue, you use:
    - Size ( ).
    
- If you want add item in Queue, you use:
    - Push.
    
- If you want to remove item from Queue, you use:
    - Pop.
    
- Queue is using LIFO.
    - False.
    
- Queue is using FIFO.
    - True.