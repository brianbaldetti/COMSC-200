//
//  main.cpp
//  StringExercise02
//
//  Created by brian on 10/10/22.
//  program uses 'mystrcpy' to copy the contents of the second string to the first string argument
//
#include <iostream>
#include <cstring>
using namespace std;

void mystrcpy(char str1[], char str2[])
{
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0')
    {
        str1[i] = str2[i];
        i++;
    }
    
    str1[i] = '\0';
}

int main()
{
    char overwrite[] = "test";
    char copy[] = "word";
    
    mystrcpy(overwrite, copy);
    
    int i = 0;
    while (overwrite[i] != '\0')
        cout << overwrite[i++];
    cout << endl;
    
    return 0;
}
