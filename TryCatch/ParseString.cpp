//
//  main.cpp
//  q36
//  Created by brian on 11/23/22.
//
//  program processes text data from and then parses the data to tokenize and filter the data
//  program must filter out spaces, and other leading data form the input string and tokens
//  are seperated from each other using double quotes
//
//
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//used to hold ShipData
struct ShipData
{
    string inputData = "";
    vector<string> tokenData;
    
    //used to initialize the 'inputData' varaible using a constructor
    ShipData(string in)
    {
        inputData = in;
    }
};

//function prototypes
void filterString(string &);
ShipData * parseString(string);

int main()
{
    //initializes 3 string values to be tested
    string str1 = " \"Royal  Caribbean    International \" \" Jurre Van Wouw\" 1987 \"For Sale\" ";
    string str2 = " \" Royal Caribbean   International   \" \" Jurre Van Wouw\" 1987 \"For Sale\" \\10\\02\\2009 ";
    string str3 = "\"      Royal Caribbean International    \"\" Jurre Van Wouw\" 1987 \" For Sale\" \\10\\02\\2009 925-123-2346";
    
    //initializes variables
    const int SIZE = 3;
    ShipData * QA[SIZE] { parseString(str1), parseString(str2), parseString(str3) };

    
    //displays values inside of QA
    for (int i = 0; i < SIZE; i++)
    {
        cout << "––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n";
        cout << "Orginal String: " << QA[i]->inputData << endl;
        
        for (int j = 0; j < QA[i]->tokenData.size(); j++)
        {
            cout << "Data token #" << (j + 1) << ": " << QA[i]->tokenData[j] << endl;
        }
        
        cout << endl << endl << endl;
    }
        
    //frees dynamically allocated memory that is pointed to by 'QA'
    //note that 'QA' is not dynamically allocated itself
    for (int i = 0; i < SIZE; i++)
    {
        delete QA[i];
        QA[i] = nullptr;

    }
    
    
    return 0;
}

//function will filter out unwanted chars from string
void filterString(string & in)
{
    bool isGood = false;
    while (!isGood)
    {
    //
    //start:;
    //
        //if there is leading whitespace remove it
        if (isblank(in[0]))
        {
            in.erase(0, 1);
            continue;
        }
        //if there is trailing whitespace remove it
        if (isblank(in[(in.size() - 1)]))
        {
            in.erase((in.size() -1), 1);
            continue;
        }
        
        //if there are multiple white space characters in a row remove the dublicates
        for (int i = 1; i < in.size(); i++)
        {
            if (isblank(in[(i - 1)]) && isblank(in[i]))
            {
                in.erase(i, 1);
                isGood = true;
                //
                //goto start;   //though not implemented i have included this code as it shows another option for the problem
                //
            }
        }
        
        isGood = !isGood;
    }
}

//function pares a string and then returns a 'ShipData' struccture holding the informaiton parsed from the string
ShipData * parseString(string in)
{
    //initializes default variables
    ShipData * newShipData = new ShipData(in);                 //initalizes the 'ShipData' structure to be returned by the function
    size_t foundFirst = 0, foundSecond = 0;                    //holds unsigned int values of the index of certain elements
    string tester = "";                                        //holds data to be added to the 'newShipData' 'tokenData' vector
    

    //program ends when found first is set to -1 indicating that there is no more elements in the string
    while ((foundFirst != -1 || foundSecond != -1))
    {
        foundFirst = in.find("\"");                     //returns index of first occurance of quotation deliminator
        foundSecond = in.find(" ");                     //returns indix of first occurance of space deliminator
        bool add = false;                               //used to determin whether or not to add 'tester' to 'tokenData' vector

        
        if (foundFirst != -1)
        {
            tester = in.substr(0, foundFirst);  //holds substring of 'in' up until the first occurance of the "
            in = in.substr((foundFirst + 1));   //'in' is set to its substring after the 'foundFirst' value effectively skipping over the " delimator
        }
        else
        {
            tester = in.substr(0, foundSecond);  //holds substring of 'in' up until the first occuracne of a space if there are no spaces left
            in = in.substr((foundSecond + 1));   //'in' is set to its substring after the 'foundFirst' value effectively skipping over the " delimator
        }
        
        //if tester is not only blank characters then it will set add to true
        for (int i = 0; i < tester.length() && !add; i++)
        {
            char c = tester[i];
            if (!isblank(c))
            {
                add = true;
            }
        }
        
        //if the tester is more than just blank characters add it to the array
        if (add)
        {
            filterString(tester);   //calls 'filterString' function which removes whitespace
            newShipData->tokenData.push_back(tester);
        }
    }
    
    return newShipData;
}
