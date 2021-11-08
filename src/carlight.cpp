#include <iostream>
#include "carlight.h"

using namespace std;

carlight::carlight(int col , int type , int brght , float prc)
{
    try
    {
        set_color(col);
    }
    catch(invalid_argument &s)
    {
        cout << s.what() << " White will be set for color." << endl;
        set_color(1);
    }
    try
    {
        set_light_type(type);   
    }
    catch(invalid_argument &s)
    {
        cout << s.what() << " Headlight will be set for light type." << endl;
        set_light_type(1);
    }
    try
    {
        set_brightness(brght);   
    }
    catch(invalid_argument &s)
    {
        cout << s.what() << " Brightness will be set to mid." << endl;
        set_brightness(2);
    }
    try
    {
        set_price(prc);  
    }
    catch(out_of_range &s)
    {
        cout << s.what() << " Symmetric price will be set." << endl;
        set_price(-prc);
    }
}

void carlight::set_color(int col)
{
    if(col > 0 && col <=4)
    {
        color = col;
    }
    else
    {
        throw invalid_argument("This color doesn't exist for carlight.");
    }
}

int carlight::get_color() const
{
    return color;
}

void carlight::set_light_type(int type)
{
    if(type > 0 && type <= 4)
    {
        light_type = type;
    }
    else
    {
        throw invalid_argument("Wrong light type.");
    }
}

int carlight::get_light_type() const
{
    return light_type;
}

void carlight::set_brightness(int brght)
{
    if(brght > 0 && brght <=3)
    {
        brightness = brght;
    }
    else
    {
        throw invalid_argument("Wrong brightness for carlight.");
    }
}

int carlight::get_brighrness() const
{
    return brightness;
}

void carlight::set_price(float prc)
{
    if(prc > 0)
    {
        price = prc;
    }
    else
    {
        throw out_of_range("Wrong price for carlight.");
    }
}

float carlight::get_price() const
{
    return price;
}