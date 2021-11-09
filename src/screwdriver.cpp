#include <iostream>
#include "screwdriver.h"

using namespace std;

screwdriver::screwdriver(screwdriver_head_size headsize , screwdriver_head_type headtype , screwdriver_length len , float prc)
{
    try
    {
        set_head_size(headsize);
    }
    catch(invalid_argument &s)
    {
        cout << s.what() << " Medium headsize will be set." << endl;
        set_head_size(medium_head);
    }
    try
    {
        set_head_type(headtype);
    }
    catch(invalid_argument &s)
    {
        cout << s.what() << " Slothead will be set." << endl;
        set_head_type(slothead);
    }
    try
    {
        set_length(len);
    }
    catch(invalid_argument &s)
    {
        cout << s.what() << " Medium length will be set" << endl;
        set_length(medium_len);
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

void screwdriver::set_head_size(screwdriver_head_size headsize)
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

screwdriver_head_size screwdriver::get_head_size() const
{
    return head_size;
}

void screwdriver::set_head_type(screwdriver_head_type headtype)
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

screwdriver_head_type screwdriver::get_head_type() const
{
    return head_type;
}

void screwdriver::set_length(screwdriver_length len)
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

screwdriver_length screwdriver::get_length() const
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

void screwdriver::printinfo() const
{
    cout << "Headsize : ";
    switch (head_size)
    {
    case small_head:
        cout << "Small" << endl;
        break;
    case medium_head:
        cout << "Medium" << endl;
        break;
    case large_head:
        cout << "Large" << endl;
        break;
    default:
        cout << "No such headsize exists" << endl;
        break;
    }

    cout << "Headtype : ";
    switch (head_type)
    {
    case slothead:
        cout << "Slothead" << endl;
        break;
    case phillipshead:
        cout << "Phillipshead" << endl;
        break;
    case pozidriv:
        cout << "Pozidriv" << endl;
        break;
    case torx:
        cout << "Torx" << endl;
        break;
    case allen:
        cout << "Allen" << endl;
        break;
    default:
        cout << "No such headtype exists" << endl;
        break;
    }

    cout << "Length : ";
    switch (length)
    {
    case extrasmall_len:
        cout << "Extra Small" << endl;
        break;
    case small_len:
        cout << "Small" << endl;
        break;
    case medium_len:
        cout << "Medium" << endl;
        break;
    case large_len:
        cout << "Large" << endl;
        break;
    case extralarge_len:
        cout << "Extra Large" << endl;
        break;
    default:
        cout << "No such length exists" << endl;
        break;
    }

    cout << "Price : " << get_price() << " $" << endl;
}