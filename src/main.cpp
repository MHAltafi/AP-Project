#include<iostream>
#include "screwdriver.h"
#include "carlight.h"

using namespace std;


int main()
{   

    screwdriver x(2,2,2,2);
    cout << x.get_head_size() << endl;
    x.set_price(3);
    carlight m(2,2,2,2);

}