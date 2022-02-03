#include <iostream>
#include "mechanic.h"
#include <vector>
#include "manage.h"
#include "screwdriver.h"
#include "carlight.h"

using namespace std;

void manage::holderscrew() //maghadir daroone moteghayer ha negahdari mishavand va sepas dar in tabe screwdriver bar asase anha sakhte mishavad
{
    screwdriver *a;        //pointer
    a = new screwdriver(); //new kardan

    a->set_head_type(static_cast<screwdriver_head_type>(hht)); //headtype

    a->set_head_size(static_cast<screwdriver_head_size>(hhs)); //headsize

    a->set_length(static_cast<screwdriver_length>(hl)); //length

    a->set_quality(hq); //quality

    a->choseandset_price();                  //farakhani tabe gheymat gozari bar asase vorudi haye karbar
    if (karbar.get_money() >= a->get_price()) //check kardane mojudi karbar
    {
        karbar.set_money(karbar.get_money() - a->get_price()); //kam shodan az poole karbar
        karbar.alltools.push_back(a);                          //pushback be vectore abzare kharide shode
        emit bought(); //emit kardane signale bought baraye daryaft dar barname va namayeshe peygham
    }
    else //agar mojudi karbar kafi nabashad
    {
        emit notbought(); //emit kardane signale notbought baraye daryaft dar barname va namayesh peygham
        delete a; //delete kardan, chon shei nabayad sakhte shavad
    }
}

void manage::setholdheadtype(int hht) //meghdare headtype daryafti ra dar moteghayere class gharar midahad
{
    this->hht = hht;
}
void manage::setholdheadsize(int hhs) //meghdare headsize daryafti ra dar moteghayere class gharar midahad
{
    this->hhs = hhs;
}

void manage::setholdlen(int hl) //meghdare length daryafti ra dar moteghayere class gharar midahad
{
    this->hl = hl;
}

void manage::setholdquality(int hq) //meghdare quality daryafti ra dar moteghayere class gharar midahad
{
    this->hq = hq;
}

void manage::holdercarlight()
{

    carlight *a;        //pointer
    a = new carlight(); //new kardan

    a->set_light_type(static_cast<lighttype>(lt)); //try baraye headtype

    a->set_color(static_cast<color>(lc)); //try baraye color

    a->set_brightness(static_cast<brightness>(brght)); //try baraye brightness

    a->set_quality(cq); //try baraye quality

    a->choseandset_price();                  //farakhani tabe gheymat gozari bar asase vorudi haye karbar
    if (karbar.get_money() >= a->get_price()) //check kardane mojudi karbar
    {
        karbar.set_money(karbar.get_money() - a->get_price()); //kam shodan az poole karbar
        karbar.alltools.push_back(a);                          //pushback be vectore abzare kharide shode
        emit bought();
    }
    else //agar mojudi karbar kafi nabashad
    {
        emit notbought();
        delete a; //delete kardan, chon shei nabayad sakhte shavad
    }
}

void manage::endapp() //tabe khoruj
{
    for (auto i : karbar.alltools) //delete kardan tamami hafeze haye gerefte shode
    {
        delete i;
    }
    exit(0); //khoruj
}
void manage::setholdlighttype(int lt) //meghdare lighttype daryafti ra dar moteghayere class gharar midahad
{
    this->lt = lt;
}
void manage::setholdlightcolor(int lc) //meghdare lightcolor daryafti ra dar moteghayere class gharar midahad
{
    this->lc = lc;
}
void manage::setholdbrightness(int brght) //meghdare brightness daryafti ra dar moteghayere class gharar midahad
{
    this->brght = brght;
}
void manage::setholdqualitycarlight(int cq) //meghdare quality daryafti ra dar moteghayere class gharar midahad
{
    this->cq = cq;
}

void manage::setboughtscewqstring() //tabe peyda kardane screwdriver haye kharidari shode dar vector va gharar dadan dar stringi ke dar barname chap mishavad
{
    string tosave; //stringi ke dar barname chap mishavad
    screwdriver *x = nullptr;
        bool check = false;
        for (auto i : karbar.alltools) //halghe estefade az vizhegi haye polimorphism
        {
            x = dynamic_cast<screwdriver*>(i);
            if(x != nullptr)
            {
                tosave.append(x->printinfo());
                check = true;
            }
        }
        if(check == false) //agar screwdriveri nakharide bashad
        {
            tosave.append(("You haven't bought any screwdrivers.\n"));
        }
        qstringtoshow = QString::fromStdString(tosave); //tabdile string be qstring
}

void manage::setboughtcarlightqstring() //tabe peyda kardane carlight haye kharidari shode dar vector va gharar dadan dar stringi ke dar barname chap mishavad
{
    string tosave; //stringi ke dar barname chap mishavad
    carlight *x = nullptr;
        bool check = false;
        for(auto i : karbar.alltools) //halghe estefade az vizhegi haye polimorphism
        {
            x= dynamic_cast<carlight*>(i);
            if(x != nullptr)
            {
                tosave.append(x->printinfo());
                check = true;
            }
        }
        if(check == false)
        {
            tosave.append(("You haven't bought any carlights.\n"));
        }
        qstringtoshow = QString::fromStdString(tosave); //tabdile string be qstring
}

void manage::setallboughtqstring() //tabe peyda kardane abzar haye kharidari shode dar vector va gharar dadan dar stringi ke dar barname chap mishavad
{
    string tosave; //stringi ke dar barname chap mishavad
    tools * c = nullptr;
    bool check = false;
    for(auto i : karbar.alltools)
    {
        c = i;
        if(c != nullptr)
        {
            tosave.append(c->printinfo());
            check = true;
        }
    }
    if(check == false)
    {
        tosave.append("You haven't bought any tools.\n");
    }
    qstringtoshow = QString::fromStdString(tosave); //tabdile string be qstring
}

bool manage::mechaniclogin(QString name, QString money) //tabe vorude karbar
{
    string strname = name.toStdString(); //tabdile qstring be string
    string strmoney = money.toStdString(); //tabdile qstring be string
    for(auto i : strmoney) //check kardane adad boodane vorudi pool
    {
        if(isalpha(i))
        {
            return false;
        }
    }
    float mon = stof(strmoney); //tabdil pool be float
    karbar.set_name(strname); //gharar dadane meghdar
    karbar.set_money(mon); //gharar dadane meghdar
    return true;
}

void manage::headtypeslot(int x) //slot baraye estefade az tabe haye ghabl
{
    setholdheadtype(x);
}

void manage::headsizeslot(int x) //slot baraye estefade az tabe haye ghabl
{
    setholdheadsize(x);
}

void manage::screwlen(int x) //slot baraye estefade az tabe haye ghabl
{
    setholdlen(x);
}

void manage::screwquality(int x) //slot baraye estefade az tabe haye ghabl
{
    setholdquality(x);
}

void manage::lighttypeslot(int x) //slot baraye estefade az tabe haye ghabl
{
    setholdlighttype(x);
}

void manage::lightcolorslot(int x) //slot baraye estefade az tabe haye ghabl
{
    setholdlightcolor(x);
}

void manage::lightbrightnessslot(int x) //slot baraye estefade az tabe haye ghabl
{
    setholdbrightness(x);
}

void manage::lightqualityslot(int x) //slot baraye estefade az tabe haye ghabl
{
    setholdqualitycarlight(x);
}

QString manage::showqstring(int x) //meghdare daryafti dar in tabe neshan midahad ke kodam string be qstring tabdil shavad va be karbar namayesh dade shavad
{
    switch (x) {
    case 1:
        setboughtscewqstring();
        break;
    case 2:
        setboughtcarlightqstring();
        break;
     case 3:
        setallboughtqstring();
        break;
    }
    return qstringtoshow;
}

QString manage::showbalance() //namayeshe mojudi
{
    string a = to_string(karbar.get_money());
    a.resize(a.size() - 4);
    a.append(" $");
    QString b = QString::fromStdString(a);
    return b;

}

bool manage::incbalance(QString add) //afzayeshe mojudi
{
    string asd = add.toStdString(); //tabdile qstring be string
    for(auto i : asd) //check kardane adad boodan
    {
        if(isalpha(i))
        {
            return false;
        }
    }
    float addedmoney = stof(asd); //strign be float
    karbar.set_money(karbar.get_money()+addedmoney); //set money baraye karbar
    return true;

}

