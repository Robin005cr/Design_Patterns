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
