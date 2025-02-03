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
