#ifndef TOOLS_H
#define TOOLS_H

class tools
{
    public:
    tools(int givenquality , float prc);
    void set_price(float prc); //tabe set baraye gheymat
    float get_price() const; //tabe get baraye gheymat
    void set_quality(int givenquality); //tabe set baraye keyfiat
    int get_quality() const; //tabe get baraye keyfait
    virtual void printinfo() const = 0; //tabe print etelaat ke = 0 baraye abstract shodane tools estefade shode
    void operator+=(const int addedprice); //operatore += baraye gheymat
    void operator-=(const int decreasedprice); //operatore -= baraye gheymat

    private:
    float price;
    int quality;

    
};

#endif

