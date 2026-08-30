/*
* project   : https://github.com/Robin005cr/Design_Patterns
* file name : example1.cpp
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

// Here the main dependency is that updating UI logic is touching the business logic and the reverse.
// Consider that Mongo DB is updated with SQLite. In that case it is affecting appUpdateUI as well.
// In large projects each class will be separate header, so the ultimate goal is that changing/modifying one class
// should not lead to building other classes ideally.
#include <iostream>
using namespace std;

class appUpdatebusinessLogic
{
    public:
    
    void loadDatabase()
    {
        cout<<"Data base created : Mongo DB";
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