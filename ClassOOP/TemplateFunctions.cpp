//
//  main.cpp
//  q23
//
//  Created by brian on 10/12/22.
//
//  Answer the following  question at the top of the main.cpp file.
//
//  Question: The getQuotient() function takes two integers or doubles as input and returns the quotient. Taking the getQuotient() as example, what may go wrong when using this template?
//
//  rounding error - there may a a rounding error if templates are used for integers as integers will ALWAYS round down and therefore not return good quotient values this can happen if the return type is an integer
//  divide by zero - if the value 0 is provided as a demoninator then this will result in an error and the program WILL crash
//  differing inputs - if one value provided is an integer and the second is a template then the funnction will may return an integer as the template has been set to an integer
//
//
#include <iostream>
#include <ctime>
using namespace std;

template <typename T>
T randomPick(T, T, T);
template <typename T>
T getChoice(string, string, T, T);

int main()
{
    srand(static_cast<unsigned>(time(0)));

    cout << "––––––––––––––––––––––––––––––––––––––––––––\n";
    cout << "Part one:\n";
    int testOne = 1, testTwo = 5, testThree = 8;
    cout << randomPick(testOne, testTwo, testThree) << endl;
    cout << randomPick('1','2','3') << endl;
    cout << randomPick (11,22,33) << endl;
    cout << randomPick ("Mac","PC","Others") << endl << endl;
    
    cout << "––––––––––––––––––––––––––––––––––––––––––––\n";
    cout << "Part two:\n";
    cout << getChoice("x","y", 1, 2) << endl << endl;
    
    return 0;
}

template <typename T>
T randomPick(T inputOne, T inputTwo, T inputThree)
{
    int tmp = rand() % 3 + 1;

        
    switch(tmp)
    {
        case 1:
            return inputOne;
            break;
        case 2:
            return inputTwo;
            break;
        default:
            return inputThree;
    }
}

template <typename T>
T getChoice(string firstString, string secondString, T firstData, T secondData)
{
    while (1)
    {
        string input;
        cout << "Please enter either " << firstString << " or " << secondString << " : ";
        getline(cin, input);
        
        if (input.compare(firstString) == 0)
            return firstData;
        else if (input.compare(secondString) == 0)
            return secondData;
        else
            cout << "Please enter a valid input! Please.\n";
    }
}


