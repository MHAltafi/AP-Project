#include <iostream>
#include "carlight.h"

using namespace std;

//tabe constructor ke ba estefade az tavabe set, maghadire avalie ra initialize mikonad
//az try & catch estefade shode ta dar soorate throw shodan dar tavabe set, meghdare pishfarzi jaye meghdare ghalat gharar girad
carlight::carlight(color col , lighttype type , brightness brght , float prc , int quality):tools(quality , prc)
{
    
    try //try marboot be color
    {
        set_color(col); //farakhani tabe set
    }
    catch(invalid_argument &s) //catch marboot be color
    {
        cout << s.what() << " White will be set for color." << endl; //tozihe meghdare pishfarz
        set_color(white); //meghdare pishfarz dar soorate throw shodan
    }

    try //try marboot be light type
    {
        set_light_type(type);    //farakhani tabe set light type
    }
    catch(invalid_argument &s) //catch marboot be light type
    {
        cout << s.what() << " Headlight will be set for light type." << endl; //tozihe meghdare pishfarz
        set_light_type(headlight); //meghdare pishfarz dar soorate throw shodan
    }

    try //try marboot be brightness
    {
        set_brightness(brght); //farakhani tabe set brightness
    }
    catch(invalid_argument &s) //catch marboot be brightness
    {
        cout << s.what() << " Brightness will be set to mid." << endl; //tozihe meghdare pishfarz
        set_brightness(mid); //meghdare pishfarz dar soorate throw shodan
    }

}

carlight::carlight()
{

}

void carlight::set_color(color col) //tabe set color
{
    if(col > 0 && col <=4) //check kardane vorudi color baraye vojude meghdare motabar dar enume tarif shode
    {
        chosencolor = col; //gharar dadane meghdar
    }
    else
    {
        throw invalid_argument("This color doesn't exist for carlight."); //throw baraye catch e dar constructor
    }
}

color carlight::get_color() const //tabe get color ke az noe enume tarif shode ast va const chon taghiri ijad nmikonad
{
    return chosencolor;
}

void carlight::set_light_type(lighttype type) //tabe set light type
{
    if(type > 0 && type <= 4) //check kardane vorudi lighttype baraye vojude meghdare motabar dar enume tarif shode
    {
        light_type = type; //gharar dadane meghdar
    }
    else
    {
        throw invalid_argument("Wrong light type."); //throw baraye catch e dar constructor
    }
}

lighttype carlight::get_light_type() const //tabe get light type ke az noe enume tarif shode ast va const chon taghiri ijad nmikonad
{
    return light_type;
}

void carlight::set_brightness(brightness brght) //tabe set brightness
{
    if(brght > 0 && brght <=3) //check kardane vorudi brightness baraye vojude meghdare motabar dar enume tarif shode
    {
        chosenbrightness = brght; //gharar dadane meghdar
    }
    else
    {
        throw invalid_argument("Wrong brightness for carlight."); //throw baraye catch e dar constructor
    }
}

brightness carlight::get_brighrness() const //tabe get brightness ke az noe enume tarif shode ast va const chon taghiri ijad nmikonad
{
    return chosenbrightness;
}

string carlight::printinfo() const //tabe printinfo baraye chape etelaat , const chon taghiri ijad nmikonad
{
    string tosend;
    tosend.append("Carlight\nColor : ");
    switch (chosencolor) //switch case baraye color bar asase enume tarif shode
    {
    case white:
        tosend.append("White\n");
        break;
    case yellow:
        tosend.append("Yellow\n");
        break;
    case blue:
        tosend.append("Blue\n");
        break;
    case red:
        tosend.append("Red\n");
        break;
    default:
        cout << "No such color exists" << endl;
        break;
    }

    tosend.append("Light type : ");
    switch (light_type) //switch case baraye light type bar asase enume tarif shode
    {
    case headlight:
        tosend.append("Headlight\n");
        break;
    case fog_light:
        tosend.append("Fog Light\n");
        break;
    case blinker:
        tosend.append("Blinker\n");
        break;
    case brake_light:
        tosend.append("Brake Light\n");
        break;
    default:
        cout << "No such type of light exists" << endl;
        break;
    }

    tosend.append("Brightness : ");
    switch (chosenbrightness) //switch case baraye brightness bar asase enume tarif shode
    {
    case low:
        tosend.append("Low\n");
        break;
    case mid:
        tosend.append("Mid\n");
        break;
    case high:
        tosend.append("High\n");
        break;
    default:
        cout << "No such type of brightness exists" << endl;
        break;
    }
    string pedar = tools::printinfo(); //printe classe pedar
    tosend.append(pedar);
    tosend.append("---------------------------------------------\n");
    return tosend;

}

bool carlight::operator==(const carlight & carlight1) //operatore == baraye tasavie lighttype va color
{
    if((this->get_light_type() == carlight1.get_light_type()) && (this->get_color() == carlight1.get_color()))
    {
        return true;
    }
    return false;
}

bool carlight::operator>(const carlight & carlight1) //operatore > baraye moghayese brightness
{
    if(this->get_brighrness() > carlight1.get_brighrness())
    {
        return true;
    }
    return false;
}

bool carlight::operator<(const carlight & carlight1) //operatore < baraye moghayese brightness ba estefade az tabe ghabl
{
    return !(*this>carlight1);
}

bool carlight::operator>=(const carlight & carlight1) //operatore >= baraye moghayese brightness
{
    if(this->get_brighrness() >= carlight1.get_brighrness())
    {
        return true;
    }
    return false;
}

bool carlight::operator<=(const carlight & carlight1) //operatore <= baraye moghayese brightness
{
    if(this->get_brighrness() <= carlight1.get_brighrness())
    {
        return true;
    }
    return false;
}

void carlight::choseandset_price() //tabe gheymat gozari bar asase vizhegi hayi ke shakhs mikhahad, az operatore overload shode + estefade shode
{
    set_price(11);

    if(light_type == headlight)
    {
        *this + 4;
    }
    else if(light_type == fog_light)
    {
        *this + 3;
    }
    else if(light_type == blinker)
    {
        *this + 2;
    }
    else if(light_type == brake_light)
    {
        *this +3;
    }
    
    if(get_quality() == 1)
    {
        *this + 1;
    }
    else if(get_quality() == 2)
    {
        *this + 4;
    }
    else if(get_quality() == 3)
    {
        *this + 7;
    }

    if(chosenbrightness == low)
    {
        *this + 1;
    }
    else if(chosenbrightness == mid)
    {
        *this +3;
    }
    else if(chosenbrightness == high)
    {
        *this + 5;
    }
}
