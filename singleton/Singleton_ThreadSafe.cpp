/*
* project   : https://github.com/Robin005cr/Design_Patterns
* file name : Singleton_ThreadSafe.cpp
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
#include <thread>
#include<mutex>
using namespace std;

class Logger
{
    static int objCtr;
    static Logger* loggerinstance;
    static mutex m;
   
        Logger()
        {
            objCtr++;
            cout<<"New object is created"<<endl;
            cout<<"No of object:"<<objCtr<<endl;
        }
    public:
        
        static Logger* getInstance()
        {
            m.lock();
            if(loggerinstance == nullptr)
            {
                loggerinstance = new Logger();
            }
            m.unlock();
            return loggerinstance;
        }
        void getDevicename(string name)
        {
            cout<<"Device name :"<<name<<endl;
        }
        
    Logger(const Logger&) = delete;  // copy
    Logger(Logger&&) = delete;  // move
    Logger& operator=(const Logger&)=delete; // copy assignment
    Logger& operator=(const Logger&&)= delete; // move assignment
};

int Logger::objCtr = 0;
Logger* Logger:: loggerinstance;
mutex Logger:: m;

void lap()
{
    Logger* lap = Logger::getInstance();
    lap->getDevicename("HP Lap 00124");
}

void desktop()
{
    Logger* desktop = Logger::getInstance();
    desktop->getDevicename("Lenovo PC 00128");

}
int main()
{
    
    thread t1(lap);
    thread t2(desktop);
    
    t1.join();
    t2.join();
    
    return 0;
}
