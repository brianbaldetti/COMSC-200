//
//  main.cpp
//  HW1StructVector
//
//  Created by brian on 8/24/22.
//
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

struct Course
{
    string courseName = "";
    int courseCredit = 0;
    int courseScore = 0;
    int courseGrade = 0;
};

struct Student
{
     int ID = 0;
     string Name = "";
     vector<Course> studentCourse;
};

int isInArray(vector<Student>, int);
int grade(Course);



int main()
{
    //defines variables
    fstream inputFile;
    string fileName = "/Users/messenger01/Desktop/StudentRecords.txt";
    inputFile.open(fileName, ios::in);
    vector<Student> arrStu;

    if (inputFile.is_open())
    {
        int index = 0;
        int ID;
        string Name;
        string CourseName;
        int Credit;
        int Score;
        while(!inputFile.eof())
        {
            inputFile >> ID >> Name >> CourseName >> Credit >> Score;
            int foundIndex = isInArray(arrStu, ID);

            if (foundIndex == - 1) // The student record does not exist
            {
                //creates two temporary structs used to hold data before it is added to the arrStu vector
                Student tmpStudent;
                Course tmpCourse;
                
                //adds data to the student struct
                tmpStudent.ID = ID;
                tmpStudent.Name = Name;
                
                //adds data to course struct
                tmpCourse.courseName = CourseName;
                tmpCourse.courseCredit = Credit;
                tmpCourse.courseScore = Score;
                tmpCourse.courseGrade = grade(tmpCourse);
                
                //adds data to student struct
                tmpStudent.studentCourse.push_back(tmpCourse);
                
                //adds data to student vector
                arrStu.push_back(tmpStudent);
                index++;
            }
            //runs if The student exists
            else
            {
                Course tmpCourse;
                tmpCourse.courseName = CourseName;
                tmpCourse.courseCredit = Credit;
                tmpCourse.courseScore = Score;
                tmpCourse.courseGrade = grade(tmpCourse);
                
                arrStu[foundIndex].studentCourse.push_back(tmpCourse);
            }
        }

        inputFile.close();

    }
    else
        cout << "File cannot be opened." << endl;
    
    //calculating grade for student
    for (int i = 0; i < arrStu.size(); i++)
    {
        //defines variables and calculates GPA
        double earnedCred = 0, totalCred = 0;
        for (int k = 0; k < arrStu[i].studentCourse.size(); k++)
        {
            earnedCred += arrStu[i].studentCourse[k].courseCredit * arrStu[i].studentCourse[k].courseGrade;
            totalCred += arrStu[i].studentCourse[k].courseCredit;
        }
        
        //outputs student info
        cout << fixed << setprecision(2);
        cout << arrStu[i].ID << "   " << arrStu[i].Name << endl;
        cout << "––––––––––––––––––––\n";
        for (int j = 0; j < arrStu[i].studentCourse.size(); j++)
        {
            cout << arrStu[i].studentCourse[j].courseName << " " << arrStu[i].studentCourse[j].courseCredit << " ";
            cout << arrStu[i].studentCourse[j].courseScore << " " << arrStu[i].studentCourse[j].courseGrade << endl;
        }
        cout << "––––––––––––––––––––\n";
        cout << "GPA: " << earnedCred / totalCred << endl << endl << endl;
    }
    
    return 0;
}



//checks if a student is already within the structure vector
int isInArray(vector<Student> arr, int target)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i].ID == target)
            return i;
    }
    
    return - 1;
}

//calculates a students grade
int grade(Course input)
{
    if (input.courseScore >= 90)
        return 4;
    else if (input.courseScore >= 80)
        return 3;
    else if (input.courseScore >= 70)
        return 2;
    else if (input.courseScore >= 60)
        return 1;
    else
        return 0;
    
}
