//
//  main.cpp
//  q14
//
//  Created by brian on 9/21/22.
//
#include <iostream>
using namespace std;

class A
{
public:
    int pub_int = 0;
};

class B : public A
{
public:
    B()
    {
        pub_int++;
    }
};

class C : private B
{
public:
    C()
    {
        pub_int += 10;
    }
    int get() const
    {
        return pub_int;
    }
};

int main()
{
    //initializing and displaying 'B' class
    B newB;
    cout << "The value of 'B' is: " << newB.pub_int << endl << endl;
    
    //initializing and displaying 'C' class
    C newC;
    cout << "The value of 'C' is: " << newC.get() << endl << endl;
    
    return 0;
}
