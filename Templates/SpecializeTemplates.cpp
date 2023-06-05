//
//  main.cpp
//  TemplateTest
//
//  Created by brian on 10/24/22.
//
#include <iostream>
using namespace std;

//class used to test overloaded operator and function templates
class QA
{
private:
    int data = 0;
public:
    QA(int in = 0)  //default constructor
    {
        data = in;
    }
    int getData() const //returns data
    {
        return data;
    }
    bool operator > (const QA & in) //overloads '>' operator as only one needs to be overloaded
    {
        if (getData() > in.getData())
            return true;
        
        return false;
    }
    void printer() const    //prints out data
    {
        cout << data << endl;
    }
};


//regular template
template <typename T>
T getMax(T inOne, T inTwo)
{
    if (inOne > inTwo)
        return inOne;
    return inTwo;
}
//specialized template
template <>
const char * getMax(const char * inOne, const char * inTwo)
{
    /*
    //code is used to find the the max constant char evaluated in alphabetical order
    //different than the way string are evaluated
    int sumOne = 0, sumTwo = 0, i = 0, j = 0;   //defines int data types
    
    //sums value of the first string literal
    while (inOne[i] != '\0')
        sumOne += static_cast<int>(inOne[i++]);
    
    //sums value of second string literal
    while (inTwo[j] != '\0')
        sumTwo += static_cast<int>(inTwo[j++]);
     */
    
    //if the value of the first is greater than the second then it is returned
    //otherwise the first string literal is returned
    int i = 0;
    while (inOne[i] != '\0' && inTwo[i] != '\0')
    {
        if (inOne[i] > inTwo[i])
        {
            i++;
            return inOne;
        }
        else if (inOne[i] < inTwo[i])
        {
            i++;
            return inTwo;
        }
        
        i++;
    }
    
    if (inOne[i] != '\0')
        return inOne;
    else
        return inTwo;
}


int main()
{
    QA tester1(3);
    QA tester2(75);
    string tester3 = "ABC";
    string tester4 = "AAA";
    unsigned tester5 = 19389;
    unsigned tester6 = 22342;
    
    cout << "Testing code: \n";
    getMax(tester1, tester2).printer();     //uses overloaded operator in template
    cout << getMax("AAA", "ABC") << endl;   //calls to specialized template
    cout << getMax(tester3, tester4) << endl;
    cout << getMax(tester5, tester6) << endl;
    cout << getMax(100, 1000) << endl;
    cout << getMax(5.8, 5.5) << endl;
    cout << getMax('A', 'a') << endl;
    cout << getMax(true, false) << endl;
    
    //causes erros because template is of different data type
    //cout << getMax(100, 10.1) << endl;
    
    cout << endl << endl;
    
    return 0;
}
