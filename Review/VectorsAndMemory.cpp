//
//  main.cpp
//  Quiz2
//
//  Created by brian on 8/24/22.
//
// employeeNumber[empNumber] = tmp; –– segmentation fault
//
// This line breakes the program because it references a part of memory that does not exist. This is a type of runtime error because it occures while the program is running. For this code to work it should be changed to:
//  employeeNumber.push_back(tmp); –– good code
//



#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Employee
{
    string name;
    int hours;
    double payRate;
};

int main()
{
   
    vector<Employee> employeeData;
    int empNumber;
    
    cout << "How many employees data would you like to store: ";
    cin >> empNumber;
    cin.ignore();
        
    for (int i = 0; i < empNumber; i++)
    {
        Employee tmp;
        // employeeData[empNumber] = tmp; //

        cout << "Enter the name for employee #" << i + 1 << ": ";
        getline(cin, tmp.name);
        cout << "Enter the hours worked for employee #" << i + 1 << ": ";
        cin >> tmp.hours;
        cin.ignore();
        cout << "Enter the pay rate for employee #" << i + 1 << ": ";
        cin >> tmp.payRate;
        cin.ignore();
        cout << "------------------------------------------------------\n";
        
        employeeData.push_back(tmp);
    }
    
    
    for (int i = 0; i < empNumber; i++)
    {
        cout << "The total pay for employee " << employeeData[i].name << " is $";
        cout << employeeData[i].payRate * employeeData[i].hours << endl;
    }
    
   return 0;
}
