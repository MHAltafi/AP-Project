#include <iostream>
#include "screwdriver.h"

using namespace std;

screwdriver::screwdriver(int headsize , int headtype , int len , float pricebydollar)
{
    set_head_size(headsize);
    set_head_type(headtype);
    set_length(len);
    set_price(pricebydollar);
}

void screwdriver::set_head_size(int headsize)
{
    if(headsize > 0 && headsize <=3)
    {
        head_size = headsize;
    }
    else
    {
        throw out_of_range("Wrong headsize");
    }
}

int screwdriver::get_head_size() const
{
    return head_size;
}

void screwdriver::set_head_type(int headtype)
{
    if(headtype > 0 && headtype <= 5)
    {
        head_type = headtype;
    }
    else
    {
        throw invalid_argument("Wrong headtype");
    }
}

int screwdriver::get_head_type() const
{
    return head_type;
}

void screwdriver::set_length(int len)
{
    if(len > 0 && len <= 5)
    {
        length = len;
    }
    else
    {
        throw out_of_range("Wrong length");
    }
}

int screwdriver::get_length() const
{
    return length;
}

void screwdriver::set_price(float prc)
{
    if(prc > 0)
    {
        price = prc;
    }
    else
    {
        throw invalid_argument("Wrong price");
    }
}

float screwdriver::get_price() const
{
    return price;
}