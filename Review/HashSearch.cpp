//
//  main.cpp
//  hw02
//
//  Created by brian on 8/29/22.
//  creates file input and searches it using hash algorithm
//
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Ship
{
    int serial;
    int type;
    string name;
    int year;
    int capacity;
    Ship *link = nullptr;
};

const int SIZE = 10;

class HashManager
{
private:
    Ship* shipArr[SIZE] = {nullptr};
public:
    HashManager()
    {
        //initializes variables
        int field0, field1, field3, field4, bucket;
        string field2;
        ifstream inputFile("/Users/messenger01/Desktop/shipRecords.txt");
        
        //checks that file is open
        if (inputFile.is_open())
        {
            while (!inputFile.eof())
            {
                inputFile >> field0 >> field1 >> field2 >> field3 >> field4;
                bucket = field0 % 10;
                
                //runs if bucket is empty
                if (shipArr[bucket] == nullptr)
                {
                    shipArr[bucket] = new Ship;
                    shipArr[bucket]->serial = field0;
                    shipArr[bucket]->type = field1;
                    shipArr[bucket]->name = field2;
                    shipArr[bucket]->year = field3;
                    shipArr[bucket]->capacity = field4;
                }
                //runs if bucket isn't empty
                else
                {
                    Ship *bucketPtr = shipArr[bucket];
                    
                    while (bucketPtr->link != nullptr)
                        bucketPtr = bucketPtr->link;
                    
                    Ship *tmp = new Ship;
                    tmp->serial = field0;
                    tmp->type = field1;
                    tmp->name = field2;
                    tmp->year = field3;
                    tmp->capacity = field4;
                    bucketPtr->link = tmp;
                }

            }
        }
    }
    //frees up memory
    ~HashManager()
    {
        for (int i = 0; i < SIZE; i++)
        {
            if (shipArr[i] != nullptr)
            {
                Ship *curr = nullptr;
                Ship *nxt = shipArr[i];
                while (curr != nullptr)
                {
                    nxt = curr->link;
                    delete curr;
                    curr = nxt;
                    
                }
            }
        }
    }
    //displays all items in the shipArr
    void displayAll() const
    {
        for (int i = 0; i < SIZE; i++)
        {
            if (shipArr[i] != nullptr)
            {
                cout << "The information for bucket number " << (i + 1) << " is:\n";
                
                Ship *tmpPtr = shipArr[i];
                while (tmpPtr != nullptr)
                {
                    cout << tmpPtr->serial << "\t" << tmpPtr->type << "\t" << tmpPtr->name << "\t" << tmpPtr->year << "\t" << tmpPtr->capacity << "\n";
                    tmpPtr = tmpPtr->link;
                }
            }
        }
    }
    //displays a specific index in the shipArr or "Not Found." otherwise
    void displayOne(int inputID) const
    {
        //checks bucket
        int bucket = inputID % 10, found = 0;
        
        //returns if bucket is empty
        if (shipArr[bucket] == nullptr)
            cout << "\nNot found.\n";
        else
        {
            Ship *tmpPtr = shipArr[bucket];
            while (tmpPtr != nullptr)
            {
                //true if tmpPtr's serial is equal to the input ID
                if (tmpPtr->serial == inputID)
                {
                    cout << "The ships information is:\n";
                    cout << tmpPtr->serial << "\t" << tmpPtr->type << "\t" << tmpPtr->name << "\t" << tmpPtr->year << "\t" << tmpPtr->capacity;
                    found = 1;
                }
                
                tmpPtr = tmpPtr->link;
            }
            
            //runs if nothing found
            if (!found)
                cout << "Not found.\n";
        }
    }
    //deletes a specifc item from the list if it has the same as the specified ID
    void deleteOne(int inputID)
    {
        int bucket = inputID % 10;
        Ship *backPtr = shipArr[bucket];
        
        if (shipArr[bucket] == nullptr)
            return;
        else if (shipArr[bucket]->serial == inputID)
        {
            shipArr[bucket] = shipArr[bucket]->link;
            delete backPtr;
        }
        else
        {
            backPtr = shipArr[bucket];
            Ship *frontPtr = backPtr->link;
            while (frontPtr != nullptr)
            {
                if (frontPtr->serial == inputID)
                {
                    backPtr->link = frontPtr->link;
                    delete frontPtr;
                }
                
                backPtr = frontPtr;
                frontPtr = frontPtr->link;
            }
        }
    }
    
    
    
};

int main()
{
    HashManager hm;
    hm.displayAll();
    
    cout << endl << endl;
    
    hm.displayOne(1009);
    hm.displayOne(1010);
    hm.displayOne(1019);
    hm.displayOne(1029);
    hm.displayOne(1039);
    hm.displayOne(1014);
    hm.displayOne(1008);
    
    cout << endl << endl;
    
    hm.deleteOne(19);
    hm.deleteOne(1010);
    hm.deleteOne(1019);
    
    hm.displayAll();
    
    return 0;
}
