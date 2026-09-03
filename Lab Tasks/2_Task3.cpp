#include<iostream>
using namespace std;
#include<string>

// we will use Jagged array structure

int main()
{
    float gpa[4][4] = {
        {3.1, 3.5, 3.7},       
        {3.9, 3.6, 3.9, 3.5},  
        {3.4, 3.75},            
        {3.95}                   
    };

    int courses[4] = {3, 4, 2, 1};

    string departments[4] = {
        "Software Engineering",
        "Artificial Intelligence",
        "Computer Science",
        "Data Science"
    };

    // Display GPAs
    for (int i = 0; i < 4; i++)
    {
        cout << departments[i] << " " << endl;

        for (int j = 0; j < courses[i]; j++)
        {
            cout << "  Course " << j + 1
                 << " GPA = " << gpa[i][j] << endl;
        }

        cout << endl;
    }

    return 0;
}