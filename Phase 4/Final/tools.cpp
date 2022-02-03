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
        set_quality(givenquality); //farakhani tabe set quality
    }
    catch(out_of_range &s) //catch marboot be quality
    {
        cout << s.what() << "Quality will be set to Average" << endl; //tozihe meghdare pishfarz
        set_quality(2); //meghdare pishfarze Average
    }
}

tools::tools()
{
    
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

void tools::set_quality(int givenquality) //tabe set quality baraye gharar dadane maghadire 1 2 3 bar asase keyfiat
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

int tools::get_quality() const //tabe get quality , const chon taghiri ijad nmikonad
{
    return quality;
}

string tools::printinfo() const
{
    string tosend;
    tosend.append("Price : ");
    tosend.append(to_string(get_price()));
    tosend.resize(tosend.size() - 4);
    tosend.append(" $\n");
    tosend.append("Quality : ");
    switch (quality) //switch case baraye quality
    {
    case 1:
        tosend.append("Low\n");
        break;
    case 2:
        tosend.append("Average\n");
        break;
    case 3:
        tosend.append("High\n");
        break;
    default:
        cout << "No such quality exists" << endl;
        break;
    }
    return tosend;
}

void tools::operator+=(const int addedprice) //operatore += baraye gheymat
{
    this->set_price(this->get_price()+addedprice);
}

void tools::operator-=(const int decreasedprice) //operatore -= baraye gheymat
{
    this->set_price(this->get_price()- decreasedprice);
}

void operator+(tools &tools1 , const int addedprice) //operatore + baraye ezafe shodane gheymat
{
    tools1.set_price(tools1.get_price()+addedprice);
}

void operator+(const int addedprice, tools & tools1) //operatore + baraye ezafe shodane gheymat ba estefade az tabe ghabl
{
    tools1 + addedprice;
}

void operator-(tools &tools1 , const int decreasedprice) //operatore - baraye ezafe shodane gheymat
{
    tools1.set_price(tools1.get_price()-decreasedprice);
}

