#include<iostream>
#include "screwdriver.h"
#include "carlight.h"

using namespace std;


int main()
{   

    screwdriver x(1,2,2,2);
    cout << x.get_head_size() << endl;
    x.set_price(3);
    carlight m(6,5,6,-6);
    cout << m.get_price() << endl;
}