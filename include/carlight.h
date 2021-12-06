#ifndef CARLIGHT_H
#define CARLIGHT_H
#include "tools.h"

enum lighttype {headlight = 1 , fog_light , blinker , brake_light}; //light type enum
enum color {white = 1 , yellow , red , blue}; //color enum
enum brightness {low = 1 , mid , high}; //brightness enum

class carlight : public tools//classe carlight marboot be anvae cheragh haye mashin
{
    friend void operator+(tools &carlight1 , const int addedprice);
    friend void operator+(const int addedprice , tools & carlight1);
    friend void operator-(tools &carlight1 , const int decreasedprice);
    friend void operator-(const int decreasedprice , tools & carlight1);

    public:
    carlight(color col , lighttype type , brightness brght , float prc, int quality); //tabe constructor
    void set_color(color col); //tabe set baraye color
    color get_color() const; //tabe get baraye color (az noe enume tarif shode)
    void set_light_type(lighttype type); //tabe set baraye light type
    lighttype get_light_type() const; //tabe get baraye light type (az noe enume tarif shode)
    void set_brightness(brightness brght); //tabe set baraye brightness
    brightness get_brighrness() const; //tabe get baraye brightness (az noe enume tarif shode)
    //void set_price(float prc); //tabe set baraye gheymat
    //float get_price() const; //tabe get baraye gheymat
    virtual void printinfo() const override; //tabe chape etelaat
    bool operator==(const carlight & carlight1);
    bool operator>(const carlight & carlight1);
    bool operator<(const carlight & carlight1);
    bool operator>=(const carlight & carlight1);
    bool operator<=(const carlight & carlight1);

    private:
    color chosencolor; //estefade az enum baraye tarife noe color
    lighttype light_type; //estefade az enum baraye tarife noe light type
    brightness chosenbrightness; //estefade az enum baraye tarife noe brightness
    //float price; //gheymat

};

#endif