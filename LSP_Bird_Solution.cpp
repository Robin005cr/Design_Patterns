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
