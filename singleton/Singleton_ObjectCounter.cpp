/*
* project   : https://github.com/Robin005cr/Design_Patterns
* file name : Singleton_ObjectCounter.cpp
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

class Logger
{
    static int objCtr;
    public:
        Logger()
        {
            objCtr++;
            cout<<"New object is created"<<endl;
            cout<<"No of object:"<<objCtr<<endl;
        }
        
        void getDevicename(string name)
        {
            cout<<"Device name :"<<name<<endl;
        }
};

int Logger::objCtr = 0;

int main()
{
    Logger* lap = new Logger();
    lap->getDevicename("HP Lap 00124");
    
    Logger* desktop = new Logger();
    desktop->getDevicename("Lenovo PC 00128");

    return 0;
}
