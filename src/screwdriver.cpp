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


void screwdriver::printinfo() const //tabe printinfo baraye chape etelaat , const chon taghiri ijad nmikonad
{
    cout << "Screwdriver" << endl;
    cout << "Headsize : ";
    switch (head_size) //switch case baraye head size bar asase enume tarif shode
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
    switch (head_type) //switch case baraye head type bar asase enume tarif shode
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
    switch (length) //swtich case baraye length bar asase enume tarif shode
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

    tools::printinfo();
    cout << "---------------------------------------------" << endl;
}

bool screwdriver::operator==(const screwdriver &screw1)
{
    if(this->get_head_type() == screw1.get_head_type())
    {
        return true;
    }
    return false;
}

bool screwdriver::operator>(const screwdriver &screw1)
{
    if(this->get_head_size() > screw1.get_head_size())
    {
        return true;
    }
    return false;
}

bool screwdriver::operator<(const screwdriver &screw1)
{
    return !(*this>screw1);
}

bool screwdriver::operator>=(const screwdriver &screw1)
{
    if(this->get_head_size() >= screw1.get_head_size())
    {
        return true;
    }
    return false;
}

bool screwdriver::operator<=(const screwdriver &screw1)
{
    if(this->get_head_size() <= screw1.get_head_size())
    {
        return true;
    }
    return false;
}
