//
//  main.cpp
//  Inheritance
//
//  Created by brian on 9/6/22.
//
#include <iostream>
using namespace std;
class  A
{
protected:
    int A_Var = 0;
public:
    A(int val = 10)
    {
        A_Var = val;
        cout << "A constructor: A_Var = " << A_Var << endl;
    }
    ~A()
    {
        cout << "A destructor: A_Var = " << A_Var << endl;
    }
    /*void getVal()
    {
        cout << "A_Var = " << A_Var << endl;
        return;
    }*/
};
class  B: public A
{
protected:
    int B_Var = 0;
public:
    B(int val = 100)
    {
        B_Var = val;
        cout << "B constructor: B_Var = " << B_Var << endl;
    }
    ~B()
    {
        cout << "B destructor: B_Var = " << B_Var << endl;
    }
    void getVal()
    {
        cout << "A_Var = " << A_Var << endl;
        cout << "B_Var = " << B_Var << endl;
        return;
    }
 
};
 
class  C: public B
{
protected:
    int C_Var = 0;
public:
    C(int val = 1000)
    {
        C_Var = val;
        cout << "C constructor: C_Var = " << C_Var << endl;
    }
    ~C()
    {
        cout << "C destructor: C_Var = " << C_Var << endl;
    }
    /*void getVal()
    {
        cout << "A_Var = " << A_Var << endl;
        cout << "B_Var = " << B_Var << endl;
        cout << "C_Var = " << C_Var << endl;
        return;
    }*/
 
};
int main()
{
 
    cout << endl << "\\1\\" << endl;
    C c1;
 
    cout << endl << "\\2\\" << endl;
    c1.getVal();
 
    cout << endl << "\\3\\" << endl;
 
    return 0;
}
