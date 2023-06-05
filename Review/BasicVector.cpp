//
//  main.cpp
//  SampleVector1
//
//  Created by brian on 8/24/22.
//
// This program demonstrates how to initialize a vector and display the values in the vector.
/*
    1. Complete the function getMax()
        Done.

    2. Could you list the points which vector is the same with array?
        Can be accessed with subscript notation, data list, can be defined by programmer or user.

    3. What is the size() function for? Why when using array, there is no such function available for us?
            The size() function is used to return the number of elements within a vector. There is no such function for arrays because they contain no bounds checking, so they are unable to understand the last element within their variable.

    4. In what ways vector is different from array?
            Vectors are dynamically allocated, vectors require the #include <vector> statement, vectors contain their own functions, vectors contain bounds checking.

*/
#include <iostream>
#include <vector>
using namespace std;

int getMax(vector<int>);

int main()
{
   // Define and initialize a vector.
   vector<int> numbers = { 10, 60, 30, 50, 40 };

    cout << "The elements in the vector are: ";
   // Display the vector elements.
   for (int i = 0; i < numbers.size(); i++)
      cout << numbers[i] << endl;

    cout << "The maximum value is: " <<  getMax(numbers) << endl;

   return 0;
}

int getMax(vector<int> input)
{
    int max = input[0];
    for (int i = 1; i < input.size(); i++)
    {
        if (input[i] > max)
            max = input[i];
    }
    
    return max;
}

