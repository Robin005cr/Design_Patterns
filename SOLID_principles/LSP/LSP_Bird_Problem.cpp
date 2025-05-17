/*
* project   : https://github.com/Robin005cr/Design_Patterns
* file name : LSP_Bird_Problem.cpp
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
// Consider a bird class which has fly() and eat() functions.
// Three classes Eagle, Ostrich and Penguin are derived from Bird class.
// Fly() will be unimplemented in Ostrich and Penguin classes.
// But making fly() pure virtual needs to have some implementation in Ostrich and Penguin class.
// Flying property is not applicable to Penguin and Ostrich.

#include <iostream>
using namespace std;
class Bird
{
public:
    virtual void fly() = 0;
    virtual void eat() = 0;
};

class Eagle : public Bird
{
public:
    void fly() override
    {
        cout << "Eagle will fly" << endl;
    }
    void eat() override
    {
        cout << "Eagle will eat" << endl;
    }
};

class Penguin : public Bird
{
public:
    void fly() override
    {
        cout << "Not implemented" << endl;
    }
    void eat() override
    {
        cout << "Penguin will eat" << endl;
    }
};

class Ostrich : public Bird
{
public:
    void fly() override
    {
        cout << "Not implemented" << endl;
    }
    void eat() override
    {
        cout << "Ostrich will eat" << endl;
    }
};

void makeBirdFly(Bird &bird)
{
    bird.fly();
}
void makeBirdEat(Bird &bird)
{
    bird.eat();
}
int main()
{
    Ostrich ostrich;
    makeBirdFly(ostrich);
    makeBirdEat(ostrich);
    return 0;
}
