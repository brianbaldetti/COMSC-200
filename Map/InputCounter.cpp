//
//  main.cpp
//  hw06
//
//  Created by brian on 10/31/22.
//
//  program counts the occurance of every word in the input file
//  if a word is a combined word then it is not counted all
//  punctuation is removed from the words and they are stored in
//  a lower case format
//
#include <iostream>
#include <cctype>
#include <map>
#include <fstream>
using namespace std;

int main()
{
    //initializes input file 'iFile' variables
    ifstream iFile("/Users/messenger01/Desktop/NotesBetweenTwoSisters.txt");
    
    //declares variables
    string reader;
    bool compoundWord;
    map<string, unsigned> wordCount;
    
    //test to see if 'iFile' opens sucessfully
    if (iFile.good())
    {
        //loop iterates through 'iFile'
        while (!iFile.eof())
        {
            //initializes variables
            compoundWord = false;
            iFile >> reader;
            
            //converts 'reader' to lower case format
            for (int i = 0; i < reader.size(); i++)
                reader[i] = tolower(reader[i]);
            
            
            //checks if 'reader' contains punctuation on either end
            if (ispunct(reader[0]))
            {
                reader.erase(0, 1);
            }
            if (ispunct(reader[(reader.size() - 1)]))
            {
                reader.erase((reader.size() - 1), 1);
            }
            //checks if 'reader' contains punctuation and ignores 'reader' if it does
            for (int i = 0; i < reader.size(); i++)
            {
                if (ispunct(reader[i]))
                {
                    compoundWord = true;
                }
            }
            
            //if 'reader' doesn't contain punctuation then the string is either added to 'wordCount'
            //map or the unsigned int that corresponds to the string is iterated by a value of one
            if (!compoundWord)
            {
                if(wordCount.find(reader) == wordCount.end())
                    wordCount.insert( {reader, 1} );
                else
                    wordCount[reader]++;
            }
        }
    }
    //runs if 'iFile' fails to open sucessfully
    else
    {
        cout << "Error! FILE NOT OPENED!\n";
        exit(EXIT_FAILURE);
    }
    
    //outputs word count data
    cout << "––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n";
    cout << left << setw(10) << "Word:" << right << setw(10) << "Count:\n";
    cout << "––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n";
    for (auto it = wordCount.begin(); it != wordCount.end(); it++)
        cout << left << setw(10) << it->first << right << setw(10) << it->second << endl;
    cout << "––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n";

    
    return 0;
}
