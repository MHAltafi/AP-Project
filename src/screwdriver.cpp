#include <iostream>
#include "screwdriver.h"

using namespace std;

screwdriver::screwdriver(int headsize , int headtype , int len , float prc)
{
    try
    {
        set_head_size(headsize);
    }
    catch(invalid_argument &s)
    {
        cout << s.what() << " Medium headsize will be set." << endl;
        set_head_size(2);
    }
    try
    {
        set_head_type(headtype);
    }
    catch(invalid_argument &s)
    {
        cout << s.what() << " Slothead will be set." << endl;
        set_head_type(1);
    }
    try
    {
        set_length(len);
    }
    catch(invalid_argument &s)
    {
        cout << s.what() << " Medium length will be set" << endl;
        set_length(3);
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

void screwdriver::set_head_size(int headsize)
{
    if(headsize > 0 && headsize <=3)
    {
        head_size = headsize;
    }
    else
    {
        throw invalid_argument("Wrong headsize for screwdriver.");
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
        throw invalid_argument("Wrong headtype for screwdriver.");
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
        throw invalid_argument("Wrong length for screwdriver.");
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
        throw out_of_range("Wrong price for screwdriver.");
    }
}

float screwdriver::get_price() const
{
    return price;
}