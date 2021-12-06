#include<iostream>
#include "screwdriver.h"
#include "carlight.h"

using namespace std;

int main()
{   
    screwdriver x(static_cast<screwdriver_head_size>(2),static_cast<screwdriver_head_type>(2),static_cast<screwdriver_length>(2),1,1);
    screwdriver b(static_cast<screwdriver_head_size>(2),static_cast<screwdriver_head_type>(2),static_cast<screwdriver_length>(2),2,2);
    carlight a(static_cast<color>(2),static_cast<lighttype>(8),static_cast<brightness>(3),16,2);
    if(x >= b)
    {
        cout << "x > b" << endl;
    }
    if(x <b)
    {
        cout << "x < b" << endl;
    }
    // tools t;// errore chon abstracte
    tools * c = nullptr;
    c = &x;
    c->printinfo();
    c = &a;
    c->printinfo();

}
