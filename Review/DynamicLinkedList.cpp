//
//  main.cpp
//  q06
//
//  Created by brian on 8/31/22.
//
#include <iostream>
#include <iomanip>
using namespace std;


struct Student
{
    int ID = 0;
    string Name = "";
    string Address = "";
    string phoneNum = "";
    Student* next = nullptr;;
};

void insert(Student**, int, string, string, string);
void display(Student**, int);
void destroy(Student**, int);


int main()
{
    /// Declare an array for holding the pointers of Student objects
    /// Initialize all elements with nullptr
    const int SIZE = 10;
    Student * arrStud[SIZE] = {nullptr};

    insert(arrStud, 12345, "Amy", "113 Main St. Livermore, CA 94578",  "510-123-3454");
    insert(arrStud, 22387, "Bill", "Apt #4, Diablo Ave. Pleasant Hill, CA 94455", "925-456-9082");
    insert(arrStud, 22779, "Carl", "Apt #8, Diablo Ave. Pleasant Hill, CA 94455", "925-765-8979");
    insert(arrStud, 10005, "John", "11112 Broad Way Bublin, CA 94599",  "925-123-3458");
    insert(arrStud, 10005, "John", "11112 Broad Way Bublin, CA 94599",  "925-123-3458");

    display(arrStud, SIZE);
    destroy(arrStud, SIZE);
    
    return 0;
}

//adds Student structure to array
void insert(Student **inStudent, int inID, string inName, string inAdr, string inNumber)
{
    int bucket = inID % 10;

    if (inStudent[bucket] == nullptr)
    {
        inStudent[bucket] = new Student;
        inStudent[bucket]->ID = inID;
        inStudent[bucket]->Name = inName;
        inStudent[bucket]->Address = inAdr;
        inStudent[bucket]->phoneNum = inNumber;
        inStudent[bucket]->next = nullptr;
    }
    else
    {
        Student *tmpPtr = inStudent[bucket];

        while (tmpPtr->next != nullptr)
            tmpPtr = tmpPtr->next;
        
        Student *newPtr = new Student;
        newPtr->ID = inID;
        newPtr->Name = inName;
        newPtr->Address = inAdr;
        newPtr->phoneNum = inNumber;
        
        tmpPtr->next = newPtr;
    }
}

//frees up DMA
void destroy(Student **inStudent, int length)
{
    for (int i = 0; i < length; i++)
    {
        if (inStudent[i] != nullptr)
        {
            Student *prevPtr = nullptr;
            Student *currPtr = inStudent[i];
            while (currPtr != nullptr)
            {
                prevPtr = currPtr;
                delete currPtr;
                currPtr = prevPtr->next;
            }
        }
    }
}

//displays info
void display(Student **inStudent, int length)
{
    Student *tmpPtr = nullptr;
    
    for (int i = 0; i < length; i++)
    {
        if (inStudent[i] != nullptr)
        {
            tmpPtr = inStudent[i];
            cout << "Bucket #" << i << endl;

            while (tmpPtr != nullptr)
            {
                cout << "\t" << tmpPtr->ID << "\t" << setw(5) << tmpPtr->Name << "\t"
                    << setw(50) << tmpPtr->Address << "\t"
                    << setw(20) << tmpPtr->phoneNum << endl;
                tmpPtr  = tmpPtr->next;
            }
            cout << endl;
        }
    }
}


