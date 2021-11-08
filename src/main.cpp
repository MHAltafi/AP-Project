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
    carlight m(6,5,6,-6);
    cout << "Carlight m:" << endl;
    cout << "Color :" << m.get_color() << endl;
    cout << "Light type :" << m.get_light_type() << endl;
    cout << "Brightness :" << m.get_brighrness() << endl;
    cout << "Price :" << m.get_price() << endl;
}