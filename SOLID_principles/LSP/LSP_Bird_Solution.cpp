/*
* project   : https://github.com/Robin005cr/Design_Patterns
* file name : LSP_Bird_Solution.cpp
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
//Solution: A new class FlyingBird is derived from Bird class.
//So the class which is derived from FlyingBird should define both eat() and fly().
//Eagle->FlyingBird(fly, eat)
//Penguin->Bird(eat)
//Ostrich->Bird(eat)


#include <iostream>
using namespace std;
class Bird
{
public:
    virtual void eat() = 0;

};
class FlyingBird : public Bird
{
public:
    virtual void fly() = 0;
};
class Eagle : public FlyingBird
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

    void eat() override
    {
        cout << "Penguin will eat" << endl;
    }
};

class Ostrich : public Bird
{
public:

    void eat() override
    {
        cout << "Ostrich will eat" << endl;
    }
};


void makeBirdFly(FlyingBird& bird)
{
    bird.fly();
}
void makeBirdEat(Bird& bird)
{
    bird.eat();
}
int main()
{
    Ostrich ostrich;
    makeBirdEat(ostrich);
    return 0;
}
