#include<iostream>
#include "screwdriver.h"
#include "carlight.h"

using namespace std;

int main()
{   
    //tarife 2 screwdriver va 2 carlight
    screwdriver a(static_cast<screwdriver_head_size>(1),static_cast<screwdriver_head_type>(1),static_cast<screwdriver_length>(1),12,1);
    screwdriver b(static_cast<screwdriver_head_size>(2),static_cast<screwdriver_head_type>(1),static_cast<screwdriver_length>(2),20,2);
    carlight d(static_cast<color>(1),static_cast<lighttype>(1),static_cast<brightness>(1),16,1);
    carlight e(static_cast<color>(2),static_cast<lighttype>(2),static_cast<brightness>(2),30,2);

    //teste operator haye screwdriver
    cout << "a & b screwdrivers:" << endl;
    if(a >= b)
    {
        cout << "headsize : a >= b" << endl;
    }
    else
    {
        cout << "headsize : a < b" << endl;
    }
    if(b > a)
    {
        cout << "headsize : b > a" << endl;
    }
    else
    {
        cout << "headsize : b <= a" << endl;
    }
    if(a == b)
    {
        cout << "a & b headtypes are equal" << endl;
    }
    else
    {
        cout << "a & b headtypes are not equal" << endl;
    }
    cout << "---------------------------------------" << endl;

    //teste operator haye carlight
    cout << "d & e carlights:" << endl;
    if(d <= e)
    {
        cout << "brightness : d <= e" << endl;
    }
    else
    {
        cout << "brightness : d > e" << endl;
    }
    if(e < d)
    {
        cout << "brightness e < d" << endl;
    }
    else
    {
        cout << "brightness e >= d" << endl;
    }
    if(d == e)
    {
        cout << "d & e lighttypes and colors are equal" << endl;
    }
    else
    {
       cout << "d & e lighttypes and colors are not equal" << endl; 
    }
    cout << "---------------------------------------" << endl;

    //teste operator haye gheymat
    cout << "screwdriver a price before add: " << a.get_price() << endl;
    a+2;
    2+a;
    a+=10;
    //14 ta ezafe shod
    cout << "screwdriver a price after add: " << a.get_price() << endl;
    cout << "---------------------------------------" << endl;
    cout << "carlight e price before decrementation: " << e.get_price() << endl;
    e-3;
    e-=8;
    //11 ta kam shod
    cout << "carlight e price after decrementation: " << e.get_price() << endl;
    cout << "---------------------------------------" << endl;

    //teste esharegare marboot be polymorphism tabe print
    // tools t;// errore chon abstracte va tabe printesh = 0 gharar dade shode va virtual ham hast
    tools * c = nullptr;
    c = &a;
    cout << "using polymorphism and pointer for the function printinfo of screwdriver a: " << endl;
    c->printinfo();
    c = &d;
    cout << "using polymorphism and pointer for the function printinfo of carlight d: " << endl;
    c->printinfo();

}
