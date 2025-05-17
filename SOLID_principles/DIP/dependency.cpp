/*
* project   : https://github.com/Robin005cr/Design_Patterns
* file name : dependency.cpp
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
        cout<<"Data base created";
    }
    
};
class appUpdateUI
{
    public:
    
    void init()
    {
        appUpdatebusinessLogic *ptr = new appUpdatebusinessLogic();  // Dependency
        ptr->loadDatabase();
        delete ptr;
    }
};


int main()
{
    appUpdateUI obj;
    obj.init();

    return 0;
}