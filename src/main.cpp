#include<iostream>
#include "screwdriver.h"
#include "carlight.h"

using namespace std;

//dar tabe main  chand nemune baraye teste class ha va tavabe an ha neveshte shode
//screwdriver x , tamame vorudi ha ghalat ast
//screw driver b , tamame vorudi ha dorost ast
//carlight m , tamame vorudi ha ghalat ast
//carlight a , faghat yek vorudi ghalat ast(light type) va baghie dorost hastand
//az static cast baraye tabdile noe int be noe enum haye tarif shode estefade shode
int main()
{   
    cout << "-------------------------------------------------------" << endl;
    cout << "Screwdriver X errors:" << endl;
    screwdriver x(static_cast<screwdriver_head_size>(10),static_cast<screwdriver_head_type>(10),static_cast<screwdriver_length>(10),-2);
    cout << "-------------------------------------------------------" << endl;
    cout << "Screwdriver X info :" << endl;
    x.printinfo();
    cout << "-------------------------------------------------------" << endl;
    cout << "Screwdriver B errors:" << endl;
    screwdriver b(static_cast<screwdriver_head_size>(2),static_cast<screwdriver_head_type>(3),static_cast<screwdriver_length>(4),54.25);
    cout << "-------------------------------------------------------" << endl;
    cout << "Screwdriver B info :" << endl;
    b.printinfo();
    cout << "-------------------------------------------------------" << endl;
    cout << "Carlight M errors:" << endl;
    carlight m(static_cast<color>(6),static_cast<lighttype>(5),static_cast<brightness>(6),-6);
    cout << "-------------------------------------------------------" << endl;
    cout << "Carlight M info :" << endl;
    m.printinfo();
    cout << "-------------------------------------------------------" << endl;
    cout << "Carlight A errors:" << endl;
    carlight a(static_cast<color>(2),static_cast<lighttype>(8),static_cast<brightness>(3),16);
    cout << "-------------------------------------------------------" << endl;
    cout << "Carlight A info :" << endl;
    a.printinfo();
    cout << "-------------------------------------------------------" << endl;

}