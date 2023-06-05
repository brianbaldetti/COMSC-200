//
//  main.cpp
//  TryCatchTest
//
//  Created by brian on 11/16/22.
//
#include <iostream>
using namespace std;

int main()
{
    int a = 101;
    
    try
    {
        if (a == 0)
        {
            throw a;
        }
        if (a > 100)
        {
            throw "I don't like large numbers";
        }
    }
    catch (int)
    {
        cout << "A is zero.\n";
    }
    catch (...)
    {
        cout << "An error has occured, though I don't know what one.\n";
    }
    
    return 0;
}
