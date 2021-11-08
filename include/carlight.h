#ifndef CARLIGHT_H
#define CARLIGHT_H

enum lighttype {headlight = 1 , fog_light , blinker , brake_light};
enum color {white = 1 , yellow , red , blue};
enum brightness {low = 1 , mid , high};

class carlight
{
    public:
    carlight(int col , int type , int brght , float prc);
    void set_color(int col);
    int get_color() const;
    void set_light_type(int type);
    int get_light_type() const;
    void set_brightness(int brght);
    int get_brighrness() const;
    void set_price(float prc);
    float get_price() const;

    private:
    int color;
    int light_type;
    int brightness;
    float price;

};

#endif