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