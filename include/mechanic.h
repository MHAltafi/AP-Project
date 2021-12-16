#ifndef MECHANIC_H
#define MECHANIC_H

#include<vector>
#include "tools.h"
#include "screwdriver.h"
#include "carlight.h"
using namespace std;

class mechanic
{
    public:
        mechanic(float givenmoney, string givenname); //constructor
        void set_money(float givenmoney); //tabe set baraye money
        float get_money(); //tabe get baraye money
        void set_name(string givenname); //tabe set baraye esm
        string get_name(); //tabe get baraye esm
        vector <tools *> alltools; //baraye rahatie kar public dar nazar gerefte shode

    private:
        string name;
        float money;
};

#endif