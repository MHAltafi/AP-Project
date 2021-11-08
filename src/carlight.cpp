#include <iostream>
#include "carlight.h"

using namespace std;

carlight::carlight(int col , int type , int brght , float prc)
{
    set_color(col);
    set_light_type(type);
    set_brightness(brght);
    set_price(prc);
}

void carlight::set_color(int col)
{
    if(col > 0 && col <=4)
    {
        color = col;
    }
    else
    {
        throw invalid_argument("Wrong color");
    }
}

int carlight::get_color()
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
        throw invalid_argument("Wrong type");
    }
}

int carlight::get_light_type()
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
        throw invalid_argument("Wrong brightness");
    }
}

int carlight::get_brighrness()
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
        throw out_of_range("wrong price");
    }
}

float carlight::get_price()
{
    return price;
}