#ifndef SCREWDRIVER_H
#define SCREWDRIVER_H

enum screwdriveheadrsize {small_head = 1 , medium_head , large_head};
enum screwdriverheadtype {slothead = 1 , phillipshead, pozidriv , torx , allen};
enum screwdriverlength {extrasmall_len = 1 , small_len , medium_len , large_len , extralarge_len};

class screwdriver
{
    public:
    void set_headsize();
    void get_headsize();
    void set_headtype();
    void get_headtype();
    void set_length();
    void get_length();
    private:
    int headsize;
    int headtype;
    int length;

};

#endif