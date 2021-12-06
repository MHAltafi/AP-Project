#include <iostream>
#include "tools.h"

using namespace std;

tools::tools(int givenquality , float prc)
{
    try //try marboot be gheymat
    {
        set_price(prc);   //farakhani tabe set price
    }
    catch(out_of_range &s) //catch marboot be gheymat
    {
        cout << s.what() << " Symmetric price will be set." << endl; //tozihe meghdare pishfarz
        set_price(-prc); //prc manfi ast , pas -prc jaye gheymat gharar migirad
    }

    try
    {
        set_quality(givenquality);
    }
    catch(out_of_range &s)
    {
        cout << s.what() << "Quality will be set to Average" << endl;
        set_quality(2);
    }
}

void tools::set_price(float prc) //tabe set price
{
    if(prc > 0) //check kardane mosbat boodane gheymate vorudi
    {
        price = prc; //gharar dadane gheymat
    }
    else
    {
        throw out_of_range("Wrong price for carlight."); //throw baraye catch e dar constructor
    }
}

float tools::get_price() const //tabe get price , const chon taghiri ijad nmikonad
{
    return price;
}

void tools::set_quality(int givenquality)
{
    if(givenquality>0 && givenquality<4)
    {
        quality = givenquality;
    }
    else
    {
        throw out_of_range("Wrong quality.");
    }
}

int tools::get_quality() const
{
    return quality;
}

void tools::printinfo() const
{
    cout << "Price : " << get_price() << " $" << endl; //chape gheymat
    cout << "Quality : ";
    switch (quality) //switch case baraye brightness bar asase enume tarif shode
    {
    case 1:
        cout << "Low" << endl;
        break;
    case 2:
        cout << "Average" << endl;
        break;
    case 3:
        cout << "High" << endl;
        break;
    default:
        cout << "No such quality exists" << endl;
        break;
    }
}

void tools::operator+=(const int addedprice)
{
    this->set_price(this->get_price()+addedprice);
}

void tools::operator-=(const int decreasedprice)
{
    this->set_price(this->get_price()- decreasedprice);
}

void operator+(tools &tools1 , const int addedprice)
{
    tools1.set_price(tools1.get_price()+addedprice);
}

void operator+(const int addedprice, tools & tools1)
{
    tools1 + addedprice;
}

void operator-(tools &tools1 , const int decreasedprice)
{
    tools1.set_price(tools1.get_price()-decreasedprice);
}

void operator-(const int decreasedprice, tools & tools1)
{
    tools1 - decreasedprice;
}
