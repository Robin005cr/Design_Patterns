/*
Scenario: Here we are having a class ToyotaInnova and we want to call
getEngineDetails() inside this class.

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

// Class to represent Toyota Innova
class ToyotaInnova
{
public:

    // Method to call getEngineDetails() on an IEngine object
    void showEngineDetails(IEngine* engine)
    {
        engine->getEngineDetails();
    }
};

int main()
{
    // Create ToyotaInnova object
    ToyotaInnova innova;

    // Create a DieselEngine object
    IEngine* dieselEngine = new DieselEngine;
    IEngine* petrolEngine = new PetrolEngine;

    // Show engine details using ToyotaInnova object
    innova.showEngineDetails(dieselEngine);
    innova.showEngineDetails(petrolEngine);

    // Clean up
    delete dieselEngine;
    delete petrolEngine;

    return 0;
}
