#include<iostream>
#include "screwdriver.h"
#include "carlight.h"

using namespace std;


int main()
{   

    screwdriver x(10,10,10,-2);
    cout << "Screwdriver x:" << endl;
    cout << "Headsize : " << x.get_head_size() << endl;
    cout << "Headtype : " << x.get_head_type() << endl;
    cout << "Length : " <<  x.get_length() << endl;
    cout << "Price : " << x.get_price() << endl;
    carlight m(static_cast<color>(6),static_cast<lighttype>(5),static_cast<brightness>(6),-6);
    cout << "Carlight m:" << endl;
    m.printinfo();
}