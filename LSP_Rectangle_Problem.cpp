//• Rectangle is the base class and it have 3 member functions.setLength(), setBreadth() and calculateArea().
//• Square is the class derived from Rectangle.Square is also a rectangle with length and breadth equal.
//• The object of Square need to pass the same values for length and breadth while calling setLength() and setBreadth().
//• If the values are different the basic standard / Property of the class Square is affected.
//• This code is not handling the situation.


#include <iostream>
using namespace std;
class Rectangle
{

public:
    int length, breadth;
    virtual void setLength(int l) = 0;
    virtual void setBreadth(int b) = 0;
    virtual void calculateArea() = 0;
};

class Square : public Rectangle
{

public:

    void setLength(int l)
    {
        length = l;
    }

    void setBreadth(int b)
    {
        breadth = b;
    }
    void calculateArea()
    {
        int area = length * breadth;
        cout << "Area :" << area;
    }
};
int main()
{
    Square S1;
    S1.setLength(12);
    S1.setBreadth(12);
    S1.calculateArea();

    return 0;
}
