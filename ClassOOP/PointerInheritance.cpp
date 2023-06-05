//
//  main.cpp
//  InheritanceExercise4
//
//  Created by brian on 9/6/22.
//
#include <iostream>
using namespace std;

class A
{
protected:
    int a = 0;
public:
    A()
    {
        cout << "A\n";
    }
    ~A()
    {
        cout << "~A\n";
    }
    void display()
    {
        cout << "Display A\n";
    }
};
class B : public A
{
protected:
    int b = 10;
public:
    B()
    {
        cout << "B\n";
    }
    ~B()
    {
        cout << "~B\n";
    }
    void display()
    {
        cout << "Display B\n";
    }
    
};
class C : public B
{
protected:
    int c = 100;
public:
    C()
    {
        cout << "C\n";
    }
    ~C()
    {
        cout << "~C\n";
    }
    void display()
    {
        cout << "Display C\n";
    }
    
};

int main()
{
    C* cPtr = new C;
    A* ptrArr[3] = {nullptr};
    ptrArr[0] = new A;
    ptrArr[1] = new B;
    ptrArr[2] = new C;
    ptrArr[1]->display();
    cPtr->display();
    delete ptrArr[2];
    
    
    return 0;
}
