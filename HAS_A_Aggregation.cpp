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

    Employee(string n, int i) : name(n), id(i) {}
};

class Department
{
public:
    string deptName;
    vector<Employee*> EmployeeData;

    void addEmployee(Employee* e)
    {
        EmployeeData.push_back(e);
    }

    void showEmployees()
    {
        for (auto emp : EmployeeData)
        {
            cout << "Name: " << emp->name 
                 << ", ID: " << emp->id << endl;
        }
    }
};

int main()
{
    Employee e1("Robin", 101);
    Employee e2("John", 102);

    Department d;
    d.deptName = "Engineering";

    d.addEmployee(&e1);
    d.addEmployee(&e2);

    d.showEmployees();

    return 0;
}