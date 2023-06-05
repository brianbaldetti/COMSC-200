//
//  main.cpp
//  hw05
//
//  Created by brian on 10/24/22.
//
//  function uses a template to create a vector data type
//  functions and template features implemented by programmer
//
//  Why we normally place the entire class template in the .h file?
//
//      The reason that we normally place the entire class template in a .h/.hpp file is because a template is a form of compile-time polymorphism
//  therefore the compilier needs access to the function implementaion to determin how to create and run a overloaded version of a class function.
//  If the compilier does not have access the implementation of a template function then how would it be able to implement a version of the function
//  for differing data types? Without access to the function implementation compile-time polymorphism IS NOT possible.
//
#include <iostream>
using namespace std;

//structure template
template <typename T>
struct intNode
{
    T item;
    intNode * next = nullptr;

    intNode(T x):item(x)  {}
};

//class template
template <class T>
class myVector
{
private:
    intNode<T> * head = nullptr;
    intNode<T> * tail = nullptr;
public:
    //deallocates dynamically allocated memory to prevent memory leak
    ~myVector()
    {
        intNode<T> * prev = head;
        while (prev != nullptr)
        {
            head = prev;
            delete head;
            head = nullptr;
            prev = prev->next;
        }
    }
    void push_back(T item)
    {
        intNode<T> * newItem = new intNode(item);   //creates new pointer to item

        if (head == nullptr)
        {
            head = newItem;
            tail = newItem;
        }
        else
        {
            tail->next = newItem;
            tail = newItem;
        }
    }
    void pop_back()
    {
        intNode<T> * prev = head;
        
        //iterates through
        while (prev->next->next != nullptr)
            prev = prev->next;
        
        tail = prev;    //sets the tail equal to the second to last element
        delete tail->next;    //deletes the previous tail
        tail->next = nullptr;   //sets the previous value to nullptr
    }
    void display()
    {
        intNode<T> *p = head;
        while (p != nullptr)
        {
            cout << p->item << " ";
            p = p ->next;
        }
    }
};

int main()
{
    myVector <int> myVect;

    myVect.push_back(1);
    myVect.push_back(3);
    myVect.push_back(5);
    myVect.display();
    cout << endl << endl;
    myVect.pop_back();
    myVect.push_back(420);
    myVect.display();
    cout << endl << endl;

    myVector <string>  myVect2;
    myVect2.push_back("This ");
    myVect2.push_back("is ");
    myVect2.push_back("my ");
    myVect2.push_back("day. ");
    myVect2.display();
    cout << endl << endl;
    myVect2.pop_back();
    myVect2.pop_back();
    myVect2.pop_back();
    myVect2.display();
    cout << endl << endl;

     return 0;
}
