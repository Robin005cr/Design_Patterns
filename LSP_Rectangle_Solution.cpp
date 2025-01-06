#include <iostream>
using namespace std;
class Shape
{
    virtual void calculateArea() = 0;
};
class Rectangle : public Shape
{

public:
    int length, breadth;
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

class Square : public Shape
{

public:
    int side;
    void setSide(int s)
    {
        side = s;
    }
    void calculateArea()
    {
        int area = side * side;
        cout << "Area :" << area;
    }

};
int main()
{
    Square S1;
    S1.setSide(12);
    S1.calculateArea();

    return 0;
}
