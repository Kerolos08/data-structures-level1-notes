# Important Question, Work Smart.

# Code

```cpp
#include <iostream>
using namespace std;

short FindNumberAlgorhim1(short arr1[10] , short Number)

{
    int n = 10;
    short pos = -1;

    for (int i = 0; i <= n; i++)
    {
        if (arr1[i] == Number)
        {
            pos= i;
        }
    }

    return pos;

}

short FindNumberAlgorhim2(short arr1[10], short Number)

{
    int n = 10;

    for (int i = 0; i <= n; i++)
    {
        if (arr1[i] == Number)
        {
            return i;
        }
    }

    return -1;
   
}

int main()
{
    short arr1[10] = { 10,20,30,40,50,60,70,80,90,100 };

    cout << FindNumberAlgorhim1(arr1, 100) <<"\n";
    cout << FindNumberAlgorhim2(arr1, 100) << "\n";

    system("pause>0");
    return 0;
}
```

# Notes

- Big O is just an indication telling you how good is your algorithm
- so in this example we have the 2 algorithm with the same Big O notation which is O(n) linear but the second one is faster.
- when we say it is faster it is faster when the element we are searching for in the end part of the array as the first algorithm is continue even after finding the element.
- so Big O is not telling us the actual time that our program need to excite its just an indication, and the good developer still can make his algorithm faster by working smarter.