/*
* project   : https://github.com/Robin005cr/Design_Patterns
* file name : 2_dependency_factory.cpp
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

class appUpdatebusinessLogic
{
public:
    void loadDatabase()
    {
        cout << "Database created" << endl;
    }
};

// Factory class to provide business logic object
class DataAccessFactory
{
public:
    static appUpdatebusinessLogic* getBusinessLogic()
    {
        return new appUpdatebusinessLogic();
    }
};

class appUpdateUI
{
public:
    void init()
    {
        // Get object from the factory
        appUpdatebusinessLogic *ptr = DataAccessFactory::getBusinessLogic();
        ptr->loadDatabase();
        delete ptr; // Clean up
    }
};

int main()
{
    appUpdateUI ui;
    ui.init();
    return 0;
}
