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
        mechanic(float givenmoney, string givenname);
        void set_money(float givenmoney);
        float get_money();
        void set_name(string givenname);
        vector <tools *> alltools;

    private:
        string name;
        float money;
};







#endif