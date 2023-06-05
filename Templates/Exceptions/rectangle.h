//
//  rectangle.h
//  Exceptions
//
//  Created by brian on 10/24/22.
//

#ifndef rectangle_h
#define rectangle_h

class Rectangle
{
private:
    int height;
    int width;
public:
    class errHeight
    {
    private:
        int height;
    public:
        errHeight(int h)
        {
            height = h;
        }
        int getHeight()
        {
            return height;
        }
    };
    class errWidth
    {
    private:
        int width;
    public:
        errWidth(int w)
        {
            width = w;
        }
        int getWidth()
        {
            return width;
        }
    };
    Rectangle(int h = 0, int w = 0)
    {
        setHeight(h);
        setWidth(w);
    }
    void setHeight(int h)
    {
        if (h > 0)
            height = h;
        else
            throw errHeight(h);
    }
    void setWidth(int w)
    {
        if (w > 0)
            width = w;
        else
            throw errWidth(w);
    }
};

#endif /* rectangle_h */
