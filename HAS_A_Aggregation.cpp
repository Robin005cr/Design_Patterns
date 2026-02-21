/*
 * project   : https://github.com/Robin005cr/Design_Patterns
 * file name : HAS_A_Aggregation.cpp
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
#include <vector>
using namespace std;

class Employee
{
public:
    string name;
    int id;
};
class Department
{
public:
    string deptName;
    std::vector<Employee *> EmployeeData;
};

int main()
{
    cout << "Has a aggregation example" << endl;

    return 0;
}