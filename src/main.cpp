#include<iostream>
#include "screwdriver.h"
#include "carlight.h"

using namespace std;


int main()
{   
    cout << "Screwdriver X :" << endl;
    screwdriver x(static_cast<screwdriver_head_size>(10),static_cast<screwdriver_head_type>(10),static_cast<screwdriver_length>(10),-2);
    cout << "-------------------------------------------------------" << endl;
    cout << "Screwdriver X info :" << endl;
    x.printinfo();
    cout << "-------------------------------------------------------" << endl;
    cout << "Screwdriver B :" << endl;
    screwdriver b(static_cast<screwdriver_head_size>(2),static_cast<screwdriver_head_type>(3),static_cast<screwdriver_length>(4),54.25);
    cout << "-------------------------------------------------------" << endl;
    cout << "Screwdriver B info :" << endl;
    b.printinfo();
    cout << "-------------------------------------------------------" << endl;
    cout << "Carlight M :" << endl;
    carlight m(static_cast<color>(6),static_cast<lighttype>(5),static_cast<brightness>(6),-6);
    cout << "-------------------------------------------------------" << endl;
    cout << "Carlight M info :" << endl;
    m.printinfo();
    cout << "-------------------------------------------------------" << endl;
    cout << "Carlight A :" << endl;
    carlight a(static_cast<color>(1),static_cast<lighttype>(8),static_cast<brightness>(3),16);
    cout << "-------------------------------------------------------" << endl;
    cout << "Carlight A info :" << endl;
    a.printinfo();
    cout << "-------------------------------------------------------" << endl;

}