#include <iostream>
#include "carlight.h"

using namespace std;

carlight::carlight(color col , lighttype type , brightness brght , float prc)
{
    try
    {
        set_color(col);
    }
    catch(invalid_argument &s)
    {
        cout << s.what() << " White will be set for color." << endl;
        set_color(white);
    }
    try
    {
        set_light_type(type);   
    }
    catch(invalid_argument &s)
    {
        cout << s.what() << " Headlight will be set for light type." << endl;
        set_light_type(headlight);
    }
    try
    {
        set_brightness(brght);   
    }
    catch(invalid_argument &s)
    {
        cout << s.what() << " Brightness will be set to mid." << endl;
        set_brightness(mid);
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

void carlight::set_color(color col)
{
    if(col > 0 && col <=4)
    {
        chosencolor = col;
    }
    else
    {
        throw invalid_argument("This color doesn't exist for carlight.");
    }
}

color carlight::get_color() const
{
    return chosencolor;
}

void carlight::set_light_type(lighttype type)
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

lighttype carlight::get_light_type() const
{
    return light_type;
}

void carlight::set_brightness(brightness brght)
{
    if(brght > 0 && brght <=3)
    {
        chosenbrightness = brght;
    }
    else
    {
        throw invalid_argument("Wrong brightness for carlight.");
    }
}

brightness carlight::get_brighrness() const
{
    return chosenbrightness;
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

void carlight::printinfo() const
{
    cout << "Color : ";
    switch (chosencolor)
    {
    case white:
        cout << "White" << endl;
        break;
    case yellow:
        cout << "Yellow" << endl;
        break;
    case blue:
        cout << "Blue" << endl;
        break;
    case red:
        cout << "Red" << endl;
        break;
    default:
        cout << "No such color exists" << endl;
        break;
    }

    cout << "Light type : ";
    switch (light_type)
    {
    case headlight:
        cout << "Headlight" << endl;
        break;
    case fog_light:
        cout << "Fog light" << endl;
        break;
    case blinker:
        cout << "Blinker" << endl;
        break;
    case brake_light:
        cout << "Brake light" << endl;
        break;
    default:
        cout << "No such type of light exists" << endl;
        break;
    }

    cout << "Brightness : ";
    switch (chosenbrightness)
    {
    case low:
        cout << "Low" << endl;
        break;
    case mid:
        cout << "Mid" << endl;
        break;
    case high:
        cout << "High" << endl;
        break;
    default:
        cout << "No such type of brightness exists" << endl;
        break;
    }

    cout << "Price : " << get_price() << " $" << endl;
}