//
//  main.cpp
//  q17
//
//  Created by brian on 9/28/22.
//
//  program shows that when redefining a memeber function the compiler picks what function
//  to run based on the object reference not on the object itself
//
#include <iostream>
using namespace std;

//definition of class A with 'f()' function
class A
{
private:
    int a = 'A';
public:
    int f() const
    {
        return a;
    }
};

//definition of class B with 'f()' funciton
class B : public A
{
private:
    int b = 'b';
public:
    int f() const
    {
        return b;
    }
};

int main()
{
    //case 1 - regular case
    B testB;
    cout << "The function 'f()' returns " << testB.f() << " when called on a B object type.\n";
    cout << "––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n";
    //type B is called
    
    //case 2 - object of type B but a reference to type A
    A* aPtr = new B;
    cout << "The function 'f()' returns " << aPtr->f() << " when called on a B object type referenced by an A object.\n";
    cout << "––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n";
    //type A is called

    
    //case 3 - object of type B and referenced by type B
    B* bPtr = new B;
    cout << "The function 'f()' returns " << bPtr->f() << " when called on a B object type and B object reference.\n";
    cout << "––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n";
    //type B is called

    
    //clears up memory
    delete aPtr;
    delete bPtr;
    
    return 0;
}
