//
//  main.cpp
//  Exceptions
//
//  Created by brian on 10/24/22.
//
#include <iostream>
#include "rectangle.h"
using namespace std;

string onlyPositives(int in)
{
    if (in < 0)
        throw static_cast<string>("Error! Negative!\n");
    
    return "Good! Positive!\n";
}

int main()
{
    try
    {
        cout << onlyPositives(10);
    }
    catch(string exception)
    {
        cout << exception;
    }
    
    try
    {
        Rectangle QA(0, 19);
    }
    catch (Rectangle::errHeight e)
    {
        cout << "Error! Wrong height!\n";
        cout << e.getHeight() << " is not valid!\n";
    }
    catch (Rectangle::errWidth e)
    {
        cout << "Error! Wrong width!\n";
        cout << e.getWidth() << " is not valid!\n";
    }
    
    
    return 0;
}

