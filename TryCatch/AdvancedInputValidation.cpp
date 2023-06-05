//
//  main.cpp
//  hw09
//
//  Created by brian on 11/22/22.
//
//   cin.clear(); -- clears the keyboard buffer after line is read from input, this prevent data from being read
//   after cin is used for something such as assigning a value to a variable and prevents a new line character from
//   being read after it is entered
//
//   cin.ignore(32768, '\n'); -- ignores the next 32768 chars of input or until a new line is reached, ignores extra data in
//   input string if it is entered, this prevents errors if a string is entered instead of a int into the input string
//
//
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
using namespace std;

#define FILE "/Users/messenger01/Desktop/studentRecords2.txt"

//student structure that holds the data of student
struct StudentRecord
{
    long long studentSSN = 0;
    string studentName = "";
    char studentGender = 0;
    
    //default constructor
    StudentRecord(long long SSN, string name, char gender)
    {
        studentSSN = SSN;
        studentName = name;
        studentGender = gender;
    }
};

//class the is responsible for reading and validating all the data
class StudentManager
{
private:
    int numStudents = 0;                       //holds the numbner of total students in the vector
    vector<StudentRecord> studentVector;       //holds the student data in vector format
    
    //private function deletes student using the specified SSN
    //returns true is SSN is found and deleted otherwise it
    //returns false if the SSN isn't found or deleted
    bool deleteStudent(const StudentRecord & in)
    {
        for (typename vector<StudentRecord>::iterator it = studentVector.begin(); it != studentVector.end(); it++)
        {
            if (it->studentSSN == in.studentSSN)
            {
                studentVector.erase(it);
                return true;
            }
        }
        
        throw "1";
        return false;
    }

    //updates information for an element in the 'studentVector'
    bool updateStudent(const StudentRecord & in)
    {
        for (int i = 0; i < studentVector.size(); i++)
        {
            if (studentVector[i].studentSSN == in.studentSSN)
            {
                studentVector[i] = in;
                return true;
            }
        }
        
        throw "2";
        return false;
    }
    
    //adds a student to the vector
    bool addStudent(const StudentRecord & in)
    {
        for (int i = 0; i < studentVector.size(); i++)
        {
            if (studentVector[i].studentSSN == in.studentSSN)
            {
                throw "3";
                return false;
            }
        }
        
        //if there is no match for the 'in' SSN then it is added to the vector
        studentVector.push_back(in);
        return false;
    }
    
public:
    
    //loads data from input file into the 'studentVector' if the data is valid it is good then
    //it is operated on otherwise the data is ignored and an exception is thrown
    StudentManager()
    {
        ifstream iFile(FILE);
        
        if (iFile)
        {
            char operation;
            long long SSN;
            string name;
            char gender;
            
            iFile >> operation >> SSN >> name >> gender;
            while (!iFile.eof())
            {
                //cout << operation << " " << SSN << " " << name << " " << gender << endl;  //used for QA
                
                try
                {
                    //invalid data exceptions
                    if ((SSN < 001010001) || (SSN > 999999999))
                    {
                        throw "0";
                    }
                    if (toupper(operation) != 'D' && toupper(operation) != 'U' && toupper(operation) != 'I')
                    {
                        throw toupper(operation);
                    }
                    if (toupper(gender) != 'M' && toupper(gender) != 'F')
                    {
                        throw toupper(gender);
                    }
                    
                    StudentRecord inputData(SSN, name, gender);
                    
                    //logic erros
                    if (toupper(operation) == 'I')
                    {
                        addStudent(inputData);
                    }
                    else if (toupper(operation) == 'U')
                    {
                        updateStudent(inputData);
                    }
                    else
                    {
                        deleteStudent(inputData);
                    }
                }
                catch (const char * catcher)
                {
                    if (strcmp(catcher, "0") == 0)
                    {
                        cout << "Error! " << SSN << " is not a valid SSN. It must be between 1010001 and 999999999.\n";
                    }
                    else if (strcmp(catcher, "1") == 0)
                    {
                        cout << "Error! " << SSN << " can't be found. No student deleted.\n";
                    }
                    else if (strcmp(catcher, "2") == 0)
                    {
                        cout << "Error! " << SSN << " can't be found. No student updated.\n";
                    }
                    else
                    {
                        cout << "Error! " << SSN << " already exist. No student added.\n";
                    }
                }
                catch (char catcher)
                {
                    if (toupper(operation) == catcher)
                    {
                        cout << "Error! " << operation << " is not a valid operation.\n";
                    }
                    else
                    {
                        cout << "Error! " << operation << " is not a valid sex.\n";
                    }
                }
                
                iFile >> operation >> SSN >> name >> gender;
            }

        }
        else
        {
            cout << "ERROR! FILE NOT OPENED! RETURNING EXIT CODE 1!\n";
            exit(1);
        }
    }
    
    //displays all the students currently in the 'studentVector'
    void displayAll() const
    {
        cout << "\n–––––––––––––––––––––––––––\n";
        for (int i = 0; i < studentVector.size(); i++)
        {
            cout << studentVector[i].studentSSN << " " << studentVector[i].studentName << " "
            << studentVector[i].studentGender << endl;
        }
        cout << "–––––––––––––––––––––––––––\n";

    }
    
    //displays a specific student int the 'studentVector' or returns not foud
    void displayStudent(long long SSN) const
    {
        cout << "\n–––––––––––––––––––––––––––\n";
        for (int i = 0; i < studentVector.size(); i++)
        {
            if (studentVector[i].studentSSN == SSN)
            {
                cout << studentVector[i].studentSSN << " " << studentVector[i].studentName << " "
                << studentVector[i].studentGender << endl;
                cout << "–––––––––––––––––––––––––––\n";
                return;
            }
        }
        
        cout << "Error! Student not found.\n";
        cout << "–––––––––––––––––––––––––––\n";
    }
};


int main()
{
    StudentManager QA;
    char userInput = 0;
    long long userSearchLong = 0;
    char exiter = 1;
    
    while (exiter)
    {
        cout << "\n–––––––––––––––––––––––––––\n";
        cout << "Queries:\n";
        cout << "a: display all student info\n";
        cout << "s: search for a specific student\n";
        cout << "q: quit the application\n";
        cout << "input: ";
        
        cin >> userInput;
        cin.clear();
        cin.ignore(32768, '\n');
        
        switch (toupper(userInput))
        {
            case 'A':
            {
                QA.displayAll();
                break;
            }
            case 'S':
            {
                cout << "\nEnter a string to search for: ";
                cin >> userSearchLong;
                cin.clear();
                cin.ignore(32768, '\n');
                
                QA.displayStudent(userSearchLong);
                break;
            }
            case 'Q':
            {
                cout << "\nExiting...\n";
                cout << "–––––––––––––––––––––––––––\n";
                exiter = 0;
                break;
            }
            default:
            {
                cout << "\n–––––––––––––––––––––––––––\n";
                cout << "Error! Please enter a valid input.\n";
                cout << "–––––––––––––––––––––––––––\n";
            }
        }
    }

    return 0;
}
