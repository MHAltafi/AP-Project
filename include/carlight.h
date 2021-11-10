#ifndef CARLIGHT_H
#define CARLIGHT_H

enum lighttype {headlight = 1 , fog_light , blinker , brake_light}; //light type enum
enum color {white = 1 , yellow , red , blue}; //color enum
enum brightness {low = 1 , mid , high}; //brightness enum

class carlight //classe carlight marboot be anvae cheragh haye mashin
{
    public:
    carlight(color col , lighttype type , brightness brght , float prc); //tabe constructor
    void set_color(color col); //tabe set baraye color
    color get_color() const; //tabe get baraye color (az noe enume tarif shode)
    void set_light_type(lighttype type); //tabe set baraye light type
    lighttype get_light_type() const; //tabe get baraye light type (az noe enume tarif shode)
    void set_brightness(brightness brght); //tabe set baraye brightness
    brightness get_brighrness() const; //tabe get baraye brightness (az noe enume tarif shode)
    void set_price(float prc); //tabe set baraye gheymat
    float get_price() const; //tabe get baraye gheymat
    void printinfo() const; //tabe chape etelaat

    private:
    color chosencolor; //estefade az enum baraye tarife noe color
    lighttype light_type; //estefade az enum baraye tarife noe light type
    brightness chosenbrightness; //estefade az enum baraye tarife noe brightness
    float price; //gheymat

};

#endif