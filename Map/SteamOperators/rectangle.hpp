//
//  rectangle.hpp
//  OperatorOverloading
//
//  Created by brian on 10/31/22.
//

#ifndef rectangle_hpp
#define rectangle_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

class Rectangle
{
private:
    int length;
    int width;
public:
    Rectangle(int w, int l)
    {
        length = l;
        width = w;
    }
    friend ostream& operator<<(ostream& OS, const Rectangle &out)
    {
        OS << " (" <<out.length << ", " << out.width << ") \n";
        return OS;
    }


    
};

#endif /* rectangle_hpp */
