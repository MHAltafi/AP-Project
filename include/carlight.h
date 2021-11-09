#ifndef CARLIGHT_H
#define CARLIGHT_H

enum lighttype {headlight = 1 , fog_light , blinker , brake_light};
enum color {white = 1 , yellow , red , blue};
enum brightness {low = 1 , mid , high};

class carlight
{
    public:
    carlight(color col , lighttype type , brightness brght , float prc);
    void set_color(color col);
    color get_color() const;
    void set_light_type(lighttype type);
    lighttype get_light_type() const;
    void set_brightness(brightness brght);
    brightness get_brighrness() const;
    void set_price(float prc);
    float get_price() const;
    void printinfo() const;

    private:
    color chosencolor;
    lighttype light_type;
    brightness chosenbrightness;
    float price;

};

#endif