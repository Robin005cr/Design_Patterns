/*
* project   : https://github.com/Robin005cr/Design_Patterns
* file name : Singleton_Base.cpp
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
    static Logger* loggerinstance;

    Logger()
    {
        objCtr++;
        cout << "New object is created" << endl;
        cout << "No of objects: " << objCtr << endl;
    }

public:
    static Logger* getInstance()
    {
        if (loggerinstance == nullptr)
        {
            loggerinstance = new Logger();
        }
        return loggerinstance;
    }

    void getDevicename(string name)
    {
        cout << "Device name: " << name << endl;
    }

    // Prevent copy and move operations
    Logger(const Logger&) = delete;  // copy constructor
    Logger(Logger&&) = delete;  // move constructor
    Logger& operator=(const Logger&) = delete;  // copy assignment
    Logger& operator=(const Logger&&) = delete;  // move assignment
};

// Initialize static variables
int Logger::objCtr = 0;
Logger* Logger::loggerinstance = nullptr;

int main()
{
    Logger* lap = Logger::getInstance();
    lap->getDevicename("HP Lap 00124");
    
    Logger* desktop = Logger::getInstance();
    desktop->getDevicename("Lenovo PC 00128");

    return 0;
}
