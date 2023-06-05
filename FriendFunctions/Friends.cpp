//
//  main.cpp
//  q33
//
//  Created by brian on 11/14/22.
//
#include <iostream>
using namespace std;

class Rectangle {
private:
    int width = 0;
    int height = 0;
    
public:
    Rectangle() {}
    Rectangle (int x, int y) : width(x), height(y) {}
    int area() {return width * height;}
    
    friend void doubleIt(Rectangle &);
    friend Rectangle * tenTime(const Rectangle &);
};

void doubleIt(Rectangle & param)
{
    param.width = param.width * 2;
    param.height = param.height * 2;
}

Rectangle * tenTime(const Rectangle & param)
{
    Rectangle * rtrn = new Rectangle((param.width * 10), (param.height * 10));
    return rtrn;
}

int main ()
{
    
Rectangle bar (2,3);
cout << "Before: " << bar.area() << '\n';

doubleIt(bar);
cout << "After: " << bar.area() << '\n';

Rectangle foo = bar;
cout << "foo After: " << foo.area() << '\n';

Rectangle * p = tenTime(bar);
cout << "After: " << p->area() << '\n';

return 0;
}
