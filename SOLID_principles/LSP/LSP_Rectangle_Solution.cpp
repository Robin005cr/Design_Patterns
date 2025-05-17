/*
* project   : https://github.com/Robin005cr/Design_Patterns
* file name : LSP_Rectangle_Solution.cpp
* author    : Robin CR
* mail id   : robinchovallurraju@gmail.com
* LinkedIn  : https://www.linkedin.com/in/robin-cr/
* portfolio : https://robin005cr.github.io/
*
* Note : If any mistakes, errors, or inconsistencies are found in the code, please feel free to mail me.
* Suggestions for improvements or better methods are always welcome and appreciated.
* I value constructive feedback and aim to continuously improve the quality of the work.
*
*/
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
