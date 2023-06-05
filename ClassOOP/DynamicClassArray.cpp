//
//  main.cpp
//  q09
//
//  Created by brian on 9/12/22.
//

#include <iostream>

using namespace std;

class Student
{
private:
    int ID = 0;
    string Name = "";
    string Address = "";
    string phoneNum = "";
public:
    Student(int id, string name, string addr, string num)
    {
        setter(id, name, addr, num);
    }
    void setter(int id, string name, string addr, string num)
    {
        if (id % 100000 != id)
        {
            cout << "\nError! " << id << " Is not a correct ID.\n\n";
            ID = -1;
            Name = name;
            Address = addr;
            phoneNum = num;
        }
        else
        {
            ID = id;
            Name = name;
            Address = addr;
            phoneNum = num;
        }
    }
    void display()
    {
        cout << "ID: " << ID << "\nName: " << Name << "\nAddress: " << Address << "\nPhone Number: " << phoneNum << "\n";
    }
};

int main()
{
    const int SIZE = 4;
    /// Declare an array for holding the pointers of Student objects
    /// Initialize all elements with nullptr
    Student * arrStud[SIZE] = {nullptr};
    /// Add the first student info
    ///  (12345, "Amy", "113 Main St. Livermore, CA 94578",  "510-123-3454")
    /// into the array.
    arrStud[0] = new Student(12345, "Amy", "113 Main St. Livermore, CA 94578", "510-123-3454");
    /// Add the second student info
    ///  (22387, "Bill", "Apt #4, Diablo Ave. Pleasant Hill, CA 94455", "925-456-9082")
    /// into the array.
    arrStud[1] = new Student(12345, "Amy", "113 Main St. Livermore, CA 94578", "510-123-3454");
    /// Add the third student info
    ///  (22779, "Carl", "Apt #8, Diablo Ave. Pleasant Hill, CA 94455". "925-765-8979")
    /// into the array
    arrStud[2] = new Student(22779, "Carl", "Apt #8, Diablo Ave. Pleasant Hill, CA 94455", "925-765-8979");
    ///add the fourth student
    ///555556, "Err", "666 Main St. Walnut Creek, CA 94589", "510-555-6666"
    ///into the array
    arrStud[3] = new Student(555556, "Err", "666 Main St. Walnut Creek, CA 94589", "510-555-6666");
    
    //display array information
    cout << "–––––––––––––––––––––––––\n";
    for (int i = 0; i < SIZE; i++)
        arrStud[i]->display();
    cout << "–––––––––––––––––––––––––\n";

    //deletes dynamical array memory
    for (int i = 0; i < SIZE; i++)
        delete arrStud[i];
         
    return 0;
}
