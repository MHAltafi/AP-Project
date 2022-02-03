#include <iostream>
#include "mechanic.h"
#include <vector>

using namespace std;

mechanic::mechanic(float givenmoney, string givenname) //constructor ba estefade az set_money o get_money
{
    set_money(givenmoney);
    set_name(givenname);
}

mechanic::mechanic()
{

}

void mechanic::set_money(float givenmoney) //tabe set baraye money
{
    if(givenmoney >= 0) //gharar dadane meghdar dar soorate dorost boodan
    {
        money = givenmoney;
    }
    else //gharar dadane meghdar dar soorate ghalat boodan
    {
        cout << "Symmetric money will be set." << endl;
        money = -givenmoney;
    }
}

float mechanic::get_money() //tabe get money
{
    return money;
}

void mechanic::set_name(string givenname) //tabe baraye gharar dadane esme mechanic
{
    name = givenname;
}

string mechanic::get_name() //tabe get name mechanic
{
    return name;
}
