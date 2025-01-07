//Consider a bird class which has fly() and eat() functions.
//Three classes Eagle, Ostrich and Penguin are derived from Bird class.
//Fly() will be unimplemented in Ostrich and Penguin classes.
//But making fly() pure virtual needs to have some implementation in Ostrich and Penguin class.
//Flying property is not applicable to Penguin and Ostrich.

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


void makeBirdFly(Bird& bird)
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
    makeBirdFly(ostrich);
    makeBirdEat(ostrich);
    return 0;
}
