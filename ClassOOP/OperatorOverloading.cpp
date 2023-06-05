//
//  main.cpp
//  OperatorOverloading
//
//  Created by brian on 9/7/22.
//
#include <iostream>
using namespace std;
template <typename T>

T findLow(T inArray[], int length)
{
    T low = inArray[0];
    
    for (int i = 1; i < length; i++)
    {
        if (low > inArray[i])
            low = inArray[i];
    }
    
    return (low);
}

int sumUpTo(int n) {
   int sum = 1;
   if (n > 1)
      sum = n + sumUpTo(n - 1);
   return sum;
}

int main()
{
    int intArray[10] {10, 1, 01, -4, -31, 9, 0};
    double doubleArray[10] = {3.3, 4.4, 452.31, 31.9, 31, 0.41, -1, .49, 91, 99};
    
    int intLow = findLow(intArray, 10);
    int doubleLow = findLow(doubleArray, 10);
    
    cout << intLow << endl;
    cout << doubleLow << endl;
    
    cout << sumUpTo(3) << endl;
    
    return 0;
}


