//
//  main.cpp
//  Exercise02
//
//  Created by brian on 9/6/22.
//
#include <iostream>
     using namespace std;
 
class base
{
public:
    virtual void print ()
    { cout<< "print base class" <<endl; }
    
    void show ()
    { cout<< "show base class" <<endl; }
    
    virtual void pureVirtual() = 0;
};
    
class derived: public base
{
public:
void print () //print () is a virtual function in the base class
    { cout<< "print derived class" <<endl; }
    
    void show ()
       { cout<< "show derived class" <<endl; }
};
   
//main function
int main()
{
    base *bptr;
    derived d;
    bptr = &d;
        
    //virtual function, bound in runtime (Runtime polymorphism)
    bptr->print();
        
    // Non-virtual function, bound in compile time
    bptr->show();
   
    return 0;
}  
