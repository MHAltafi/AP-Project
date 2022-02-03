#include <iostream>
#include "screwdriver.h"

using namespace std;

//tabe constructor ke ba estefade az tavabe set, maghadire avalie ra initialize mikonad
//az try & catch estefade shode ta dar soorate throw shodan dar tavabe set, meghdare pishfarzi jaye meghdare ghalat gharar girad
screwdriver::screwdriver(screwdriver_head_size headsize , screwdriver_head_type headtype , screwdriver_length len , float prc, int quality):tools(quality , prc)
{
    try //try marboot be headsize
    {
        set_head_size(headsize); //farakhani tabe set
    }
    catch(invalid_argument &s) //catch marboot be headsize
    {
        cout << s.what() << " Medium headsize will be set." << endl; //tozihe meghdare pishfarz
        set_head_size(medium_head); //meghdare pishfarz dar soorate throw shodan
    }

    try //try marboot be headtype
    {
        set_head_type(headtype); //farakhani tabe set
    }
    catch(invalid_argument &s) //catch marboot be headtype
    {
        cout << s.what() << " Slothead will be set." << endl; //tozihe meghdare pishfarz
        set_head_type(slothead); //meghdare pishfarz dar soorate throw shodan
    }

    try //try marboot be length
    {
        set_length(len); //farakhani tabe set
    }
    catch(invalid_argument &s) //catch marboot be length
    {
        cout << s.what() << " Medium length will be set" << endl; //tozihe meghdare pishfarz
        set_length(medium_len); //meghdare pishfarz dar soorate throw shodan
    }

}

screwdriver::screwdriver()
{

}

void screwdriver::set_head_size(screwdriver_head_size headsize) //tabe set head size
{
    if(headsize > 0 && headsize <=3) //check kardane vorudi headsize baraye vojude meghdare motabar dar enume tarif shode
    {
        head_size = headsize; //gharar dadane meghdar
    }
    else
    {
        throw invalid_argument("Wrong headsize for screwdriver."); //throw baraye catch e dar constructor
    }
}

screwdriver_head_size screwdriver::get_head_size() const //tabe get head size ke az noe enume tarif shode ast va const chon taghiri ijad nmikonad
{
    return head_size;
}

void screwdriver::set_head_type(screwdriver_head_type headtype) //tabe set head type
{
    if(headtype > 0 && headtype <= 5) //check kardane vorudi baraye vojude meghdare motabar dar enume tarif shode
    {
        head_type = headtype; //gharar dadane meghdar
    }
    else
    {
        throw invalid_argument("Wrong headtype for screwdriver."); //throw baraye catch e dar constructor
    }
}

screwdriver_head_type screwdriver::get_head_type() const //tabe get head type ke az noe enume tarif shode ast va const chon taghiri ijad nmikonad
{
    return head_type;
}

void screwdriver::set_length(screwdriver_length len) //tabe set length
{
    if(len > 0 && len <= 5) //check kardane vorudi baraye vojude meghdare motabar dar enume tarif shode
    {
        length = len; //gharar dadane meghdar
    }
    else
    {
        throw invalid_argument("Wrong length for screwdriver."); //throw baraye catch e dar constructor
    }
}

screwdriver_length screwdriver::get_length() const //tabe get length ke az noe enume tarif shode ast va const chon taghiri ijad nmikonad
{
    return length;
}


string screwdriver::printinfo() const //tabe printinfo baraye chape etelaat , const chon taghiri ijad nmikonad
{
    string tosend;
    tosend.append("Screwdriver\nHeadsize : ");
    switch (head_size) //switch case baraye head size bar asase enume tarif shode
    {
    case small_head:
        tosend.append("Small\n");
        break;
    case medium_head:
        tosend.append("Medium\n");
        break;
    case large_head:
        tosend.append("Large\n");
        break;
    default:
        cout << "No such headsize exists" << endl;
        break;
    }

    tosend.append("Headtype : ");
    switch (head_type) //switch case baraye head type bar asase enume tarif shode
    {
    case slothead:
        tosend.append("Slothead\n");
        break;
    case phillipshead:
        tosend.append("Phillipshead\n");
        break;
    case pozidriv:
        tosend.append("Pozidriv\n");
        break;
    case torx:
        tosend.append("Torx\n");
        break;
    case allen:
        tosend.append("Allen\n");
        break;
    default:
        cout << "No such headtype exists" << endl;
        break;
    }

    tosend.append("Length : ");
    switch (length) //swtich case baraye length bar asase enume tarif shode
    {
    case extrasmall_len:
        tosend.append("Extra Small\n");
        break;
    case small_len:
        tosend.append("Small\n");
        break;
    case medium_len:
        tosend.append("Medium\n");
        break;
    case large_len:
        tosend.append("Large\n");
        break;
    case extralarge_len:
        tosend.append("Extra Large\n");
        break;
    default:
        cout << "No such length exists" << endl;
        break;
    }

    string pedar;
    pedar = tools::printinfo(); //printe classe pedar
    tosend.append(pedar);
    tosend.append("---------------------------------------------\n");
    return tosend;
}

bool screwdriver::operator==(const screwdriver &screw1) //operatore == baraye check kardane tasavie headtype
{
    if(this->get_head_type() == screw1.get_head_type())
    {
        return true;
    }
    return false;
}

bool screwdriver::operator>(const screwdriver &screw1) //operatore > baraye moghayese headsize
{
    if(this->get_head_size() > screw1.get_head_size())
    {
        return true;
    }
    return false;
}

bool screwdriver::operator<(const screwdriver &screw1) //operatore < baraye moghayese headsize ba estefade az tabe ghabl
{
    return !(*this>screw1);
}

bool screwdriver::operator>=(const screwdriver &screw1) //operatore >= baraye moghayese headsize
{
    if(this->get_head_size() >= screw1.get_head_size())
    {
        return true;
    }
    return false;
}

bool screwdriver::operator<=(const screwdriver &screw1) //operatore <= baraye moghayese headsize
{
    if(this->get_head_size() <= screw1.get_head_size())
    {
        return true;
    }
    return false;
}

void screwdriver::choseandset_price() //tabe gheymat gozari bar asase vizhegi hayi ke shakhs mikhahad, az operatore overload shode + estefade shode
{
    set_price(15);
    if(head_type == slothead)
    {
        *this + 5;
    }
    else if(head_type == phillipshead)
    {
        *this + 6;
    }
    else if(head_type == pozidriv)
    {
        *this + 5;
    }
    else if(head_type == torx)
    {
        *this + 4;
    }
    else if(head_type == allen)
    {
        *this + 5;
    }

    if(head_size == small_head)
    {
        *this + 1;
    }
    else if(head_size == medium_head)
    {
        *this + 2;   
    }
    else if(head_size == large_head)
    {
        *this + 3;
    }
    
    if(length == extrasmall_len)
    {
        *this + 1;
    }
    else if(length == small_len)
    {
        *this + 2;
    }
    else if(length == medium_len)
    {
        *this + 3;
    }
    else if(length == large_len)
    {
        *this + 4;
    }
    else if(length == extralarge_len)
    {
        *this + 5;
    }

    if(get_quality() == 1)
    {
        *this + 1;
    }
    else if(get_quality() == 2)
    {
        *this + 3;
    }
    else if(get_quality() == 3)
    {
        *this + 5;
    }
}
