/*
 * project   : https://github.com/Robin005cr/Design_Patterns
 * file name : HAS_A_Composition.cpp
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

class Engine
{
public:
    string fuel;
};
class Car
{
public:
    Engine Diesel;
    string type;
};

int main()
{
    cout << "Has a composition example" << endl;

    return 0;
}