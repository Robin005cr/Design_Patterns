/*
* project   : https://github.com/Robin005cr/Design_Patterns
* file name : ObserverPattern.cpp
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
#include<string>
#include<list>
using namespace std;

class ISubscriber
{
public:
    virtual void notify(string msg) = 0;
};

class User : public ISubscriber
{
private:
    int userId;
public:
    User(int userId)
    {
        this->userId = userId;
    }
    void notify(string msg)
    {
        cout << "User " << userId << "Recived msg" << msg << endl;
    }
};
class Group {

private:
    list<ISubscriber*> users;
public:
    void subscribe(ISubscriber* user)
    {
        users.push_back(user);
    }
    void unsubscribe(ISubscriber* user)
    {
        users.remove(user);
    }
    void notify(string msg)
    {
        for (auto user : users)
        {
            user->notify(msg);
        }
    }
};

int main()
{
    Group* group = new Group;

    User* user1 = new User(1);
    User* user2 = new User(2);
    User* user3 = new User(3);

    group->subscribe(user1);
    group->subscribe(user2);
    group->subscribe(user3);

    group->notify("Climate control :Rain is expected around 11 am");

    group->unsubscribe(user2);
    group->notify("Climate control : Sunny temperature will go till 40 degrees");

}
