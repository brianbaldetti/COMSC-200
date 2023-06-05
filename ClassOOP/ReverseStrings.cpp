//
//  main.cpp
//  q22
//
//  Created by brian on 10/12/22.
//
#include <iostream>
using namespace std;

void reverseCString(char[]);
void reverseCPPString(string&);

int main()
{
    cout << "Testing 'reverseCString' function: \n";
    char qA[] = "LIVE";
    cout << "Before: " << qA << endl;
    reverseCString(qA);
    cout << "After: " << qA << endl;
    cout << "––––––––––––––––––––––––––––––––––––––––––––––\n";
    cout << "Testing 'reverseCPPString' function: \n";
    string qA1 = "EVIL";
    cout << "Before: " << qA1 << endl;
    reverseCPPString(qA1);
    cout << "After: " << qA1 << endl;
    
    cout << endl << endl << endl;
    
    return 0;
}

void reverseCString(char inputStr[])
{
    int i = 0, j = 0;
    
    while (inputStr[i--] != '\0')
        i += 2;
    
    while (i > j)
        swap(inputStr[j++], inputStr[i--]);
}

void reverseCPPString(string & inputStr)
{
    int i = static_cast<int>(inputStr.length() - 1), j = 0;
    
    while (i > j)
        swap(inputStr[j++], inputStr[i--]);
}
