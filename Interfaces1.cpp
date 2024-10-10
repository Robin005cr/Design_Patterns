/*
Scenario: Here we are creating a pointer variant1 of type IEngine.This allows the program to handle
different types of engines(Diesel or Petrol) through the same interface.

A class can have 2 methods open and close.If any method / functions is declared as virtual then it
indicates that it is open for definition in the child class.

Never add pure virtual functions in base class, since it will lead to a modification in its child objects
*/



#include <iostream>
using namespace std;

// Abstract class to define engine interface
class IEngine
{
public:
    virtual void getEngineDetails() = 0; // Pure virtual function
};

// DieselEngine class inheriting from IEngine
class DieselEngine : public IEngine
{
public:
    void getEngineDetails() override
    {
        cout << "The details of diesel engine" << endl;
    }
};

// PetrolEngine class inheriting from IEngine
class PetrolEngine : public IEngine
{
public:
    void getEngineDetails() override
    {
        cout << "The details of Petrol engine" << endl;
    }
};

int main()
{
    // Create a DieselEngine object using IEngine pointer
    IEngine* variant1 = new DieselEngine;
    variant1->getEngineDetails();
    delete variant1; // Free allocated memory

    return 0;
}
