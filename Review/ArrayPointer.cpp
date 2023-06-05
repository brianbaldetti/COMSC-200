//
//  main.cpp
//  Q4_array_pointer_coding
//
//  Created by brian on 8/29/22.
//
#include <iostream>
#include <string>
using namespace std;

struct Student
{
    int ID = 0;
    string Name = "";
    string Address = "";
    string phoneNum = "";
};

void display(Student**, int);

int main()
{
    /// Declare an array for holding the pointers of Student objects
    /// Initialize all elements with nullptr
    const int SIZE = 9;
    Student * arrStud[SIZE] = {nullptr};

    /// Add the first student info
    ///  (12345, "Amy", "113 Main St. Livermore, CA 94578",  "510-123-3454")
    /// into the array.
    ///
    arrStud[0] = new Student;
    arrStud[0]->ID = 12345;
    arrStud[0]->Name = "Amy";
    arrStud[0]->Address = "113 Main St. Livermore, CA 94578";
    arrStud[0]->phoneNum = "510-123-3454";
    
    /// Add the second student info
    ///  (22387, "Bill", "Apt #4, Diablo Ave. Pleasant Hill, CA 94455", "925-456-9082")
    /// into the array.
    ///
    ///
    arrStud[1] = new Student;
    arrStud[1]->ID = 22387;
    arrStud[1]->Name = "Bill";
    arrStud[1]->Address = "Apt #4, Diablo Ave. Pleasant Hill, CA 94455";
    arrStud[1]->phoneNum = "925-456-908";
    /// Add the third student info
    ///  (22779, "Carl", "Apt #8, Diablo Ave. Pleasant Hill, CA 94455". "925-765-8979")
    /// into the array.
    ///
#ifdef bugger
    cout << "HEllo\n";
#endif
    ///
    ///
    arrStud[2] = new Student;
    arrStud[2]->ID = 22779;
    arrStud[2]->Name = "Bill";
    arrStud[2]->Address = "Apt #8, Diablo Ave. Pleasant Hill, CA 94455";
    arrStud[2]->phoneNum = "925-765-8979";
    
    /// The following display() function will display the information of all students in the array
    /// The function should check if an element is null first. If it is not null, the information is displayed.
    display(arrStud, SIZE);


    return 0;
}

void display(Student ** input, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (input[i] != nullptr)
        {
            cout << "\n––––––––––––––––––––––––––––\nDisplaying Input for Student " << (i + 1) << "\n––––––––––––––––––––––––––––\n";
            cout << "The ID of the student is: " << input[i]->ID  << endl;
            cout << "The name of the student is: " << input[i]->Name << endl;
            cout << "The address of the student is: " << input[i]->Address << endl;
            cout << "The phone number of the student is: " << input[i]->phoneNum << endl;
        }
        else
            return;
    }
}
