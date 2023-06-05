//
//  main.cpp
//  SampleVector2
//
//  Created by brian on 8/24/22.
//
// This program stores the hours worked by N employees and their hourly pay rates in vectors.
/*

    1. What is the function push_back() for? Why the function is named as "push_back"?
        push_back() adds a value to the end of the vector array, it is called push_back because it adds data to the vector stack.

    2. If the function push_back() is for adding a new element to the end of the vector,
       what is the name of the function which deletes an element at the end?
            The funciton pop_back() removes the last element of a vector.

    3. Can we add a new element to the front of the vector? Could we delete an element
       at the front?
            Yes you can do both. To delete a element from the front of the vector you can use the erase() function and to add an element to the front you can use the insert() function.

    4. Use this program as the base and implement a function which returns the biggest value in the int vector.
            Done.

    5. We are using 2 vectors to handle hours and payRate. If we need to handle employee information,
       which consists of 20 fields, can we use 20 vectors to do this? If not, what is the better
       design?
            The better design is to use a structure object that contains all the fields.

*/
#include <iostream>
#include <iomanip>
#include <vector>    // Needed to define vectors
using namespace std;

int main()
{
   vector<int> hours;      // hours is an empty vector
   vector<double> payRate; // payRate is an empty vector
   int numEmployees;       // The number of employees
   int index;              // Loop counter

   // Get the number of employees.
   cout << "How many employees do you have? ";
   cin >> numEmployees;

   // Input the payroll data.
   cout << "Enter the hours worked by " << numEmployees;
   cout << " employees and their hourly rates.\n";
   for (index = 0; index < numEmployees; index++)
   {
      int tempHours;    // To hold the number of hours entered
      double tempRate;  // To hold the payrate entered

      cout << "Hours worked by employee #" << (index + 1);
      cout << ": ";
      cin >> tempHours;
      hours.push_back(tempHours);      // Add an element to hours
      cout << "Hourly pay rate for employee #";
      cout << (index + 1) << ": ";
      cin >> tempRate;
      payRate.push_back(tempRate);  // Add an element to payRate
   }

   // Display each employee's gross pay.
   cout << "Here is the gross pay for each employee:\n";
   cout << fixed << showpoint << setprecision(2);
   for (index = 0; index > -1; index++)                 //causes program to crash by causing infinate loop
   {
      double grossPay = hours[index] * payRate[index];
      cout << "Employee #" << (index + 1);
      cout << ": $" << grossPay << endl;
   }
    
    //returns the biggest value in the hours vector
    cout << "The most hours worked by an employee is: ";
    int max = hours[0];
    for (index = 1; index < numEmployees; index++)
    {
        if (hours[index] > max)
        {
            max = hours[index];
        }
    }
    cout << max << endl;
    
    
   return 0;
}
