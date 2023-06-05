//
//  main.cpp
//  hw08
//
//  Created by brian on 11/14/22.
//
//  Answer the question: In what situations we can justify the uses of Friend Function or Friend Class?
//      Though friend classes are unique they do have a few situations where they are very useful. One situation is for QA (quality analysis) of code, friend functions allow you to easily create functions that can access encapsulated data allowing the programmer to test how code is ran and the state of encapsulated code. Friend functions can be used as a WINDOW to look into a block of encapsulated code.
//      Also, friend classes are especially useful when you want a class to be able to access the data available for another class even if it is a different class. For example, though a child's grades does not belong to the childs parent it may be useful for that parent to be able to access the child's grades even if they don't belong to them. Also, manager classes can have increased functionality if they are able to access sub-class data.
//
//
#include <iostream>
using namespace std;

class Rectangle {
private:
    int width = 0;
    int height = 0;
    
public:
    Rectangle() {}
    
    Rectangle (int x, int y)
    {
        if (x < 0)
            width = 1;
        else
            width = x;
        
        if (y < 0)
            height = 1;
        else
            height = y;
    }
    int area() {return width * height;}
    void doubleIt()
    {
        width *= 2;
        height *= 2;
    }
    Rectangle * tenTime()
    {
        Rectangle * returnRectangle = new Rectangle((width * 10), (height * 10));
        return returnRectangle;
    }
};

int main ()
{
        
    Rectangle bar (2,3);
    cout << "Before: " << bar.area() << '\n';

    bar.doubleIt();
    cout << "After: " << bar.area() << '\n';

    Rectangle foo = bar;
    cout << "foo After: " << foo.area() << '\n';

    Rectangle * p = bar.tenTime();
    cout << "After: " << p->area() << '\n';

    return 0;
}
