//
//  main.cpp
//  StringExercise01
//
//  Created by brian on 10/10/22.
//
#include <iostream>
using namespace std;


int main()
{
const int SIZE = 10;
char s1[SIZE] = "Hello";
     
int i = 0;
char c = s1[i];

while (c != '\0')
{
    i++;
    cout << c;
    c = s1[i];
}
    
cout << endl;
}
