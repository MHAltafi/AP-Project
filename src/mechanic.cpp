#include <iostream>
#include "mechanic.h"
#include <vector>

using namespace std;

mechanic::mechanic(float givenmoney, string givenname)
{
    set_money(givenmoney);
    set_name(givenname);
}

void mechanic::set_money(float givenmoney)
{
    if(givenmoney > 0)
    {
        money = givenmoney;
    }
    else
    {
        cout << "Symmetric money will be set." << endl;
        money = -givenmoney;
    }
}

float mechanic::get_money()
{
    return money;
}

void mechanic::set_name(string givenname)
{
    name = givenname;
}
