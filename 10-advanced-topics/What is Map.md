# What is Map?

A **map** (also called a dictionary, hash table, or associative array) is a data structure that stores data as **key-value pairs**. It allows you to efficiently look up values using their associated keys.

In C++, a `std::map` is a container in the Standard Template Library (STL) that represents an associative array. It is a sorted associative container that contains key-value pairs, where each key must be unique. The elements are ordered based on the keys, which are sorted in ascending order by default. This sorting allows for efficient search, insertion, and deletion of elements.

## Key Characteristics

- **Keys are unique** - each key can only appear once in the map
- **Fast lookup** - finding a value by its key is typically very fast (O(1) average time)
- **Unordered or ordered** - depending on the implementation, maps may or may not maintain insertion order
- **Keys map to values** - each key is associated with exactly one value

## Common Operations

- **Insert/Put** - add a new key-value pair
- **Get/Lookup** - retrieve the value associated with a key
- **Delete/Remove** - remove a key-value pair
- **Contains/Has** - check if a key exists
- **Update** - change the value associated with an existing key

## Example

```cpp
#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<string, int> StudentsGrades;
    StudentsGrades["Kero"] = 90;
    StudentsGrades["Ali"] = 80;
    StudentsGrades["Mohamed"] = 60;

    // Printing all map values
    cout << "\nPrinting all map values..\n\n";
    // Iterating over the map
    for (const auto &pair : StudentsGrades)
    {
        cout << "Student: " << pair.first << " , Grade: " << pair.second << endl;
    }

    // Finding Kero's Grade
    string StudentName = "Kero";
    if (StudentsGrades.find(StudentName) != StudentsGrades.end())
    {
        cout << StudentName << "'s grade: " << StudentsGrades[StudentName] << endl;
    }
    else
    {
        cout << "Grade not found for " << StudentName << endl;
    }

    // Finding Kero's Grade
    StudentName = "Omar";
    if (StudentsGrades.find(StudentName) != StudentsGrades.end())
    {
        cout << StudentName << "'s grade: " << StudentsGrades[StudentName] << endl;
    }
    else
    {
        cout << "Grade not found for " << StudentName << endl;
    }

    return 0;
}
```