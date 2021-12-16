#include<iostream>
#include "screwdriver.h"
#include "carlight.h"
#include <vector>

using namespace std;

vector <tools *> alltools(0);

int main()
{   
    //tarife 2 screwdriver va 2 carlight
    screwdriver a(static_cast<screwdriver_head_size>(1),static_cast<screwdriver_head_type>(1),static_cast<screwdriver_length>(1),12,1);
    screwdriver b(static_cast<screwdriver_head_size>(2),static_cast<screwdriver_head_type>(1),static_cast<screwdriver_length>(2),20,2);
    carlight d(static_cast<color>(1),static_cast<lighttype>(1),static_cast<brightness>(1),16,1);
    carlight e(static_cast<color>(2),static_cast<lighttype>(2),static_cast<brightness>(2),30,2);

    alltools.push_back(&a);
    alltools.push_back(&d);

    tools * c = nullptr;
    screwdriver *x = nullptr;
    carlight * y = nullptr;
    x = dynamic_cast<screwdriver*>(alltools[0]);
    if(x != nullptr)
    {
        cout << "kar kard" << endl;
    }
    x = dynamic_cast<screwdriver *>(alltools[1]);
    if(x != nullptr)
    {
        cout << "kar nkard" << endl;
    }
    

}
