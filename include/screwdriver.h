#ifndef SCREWDRIVER_H
#define SCREWDRIVER_H

enum screwdriver_head_size {small_head = 1 , medium_head , large_head}; //head size enum
enum screwdriver_head_type {slothead = 1 , phillipshead, pozidriv , torx , allen}; //head type enum
enum screwdriver_length {extrasmall_len = 1 , small_len , medium_len , large_len , extralarge_len}; //length enum

class screwdriver
{
    public:
    screwdriver(screwdriver_head_size headsize , screwdriver_head_type headtype , screwdriver_length len , float prc);
    void set_head_size(screwdriver_head_size headsize);
    screwdriver_head_size get_head_size() const;
    void set_head_type(screwdriver_head_type headtype);
    screwdriver_head_type get_head_type() const;
    void set_length(screwdriver_length len);
    screwdriver_length get_length() const;
    void set_price(float prc);
    float get_price() const;
    void printinfo() const;

    private:
    screwdriver_head_size head_size;
    screwdriver_head_type head_type;
    screwdriver_length length;
    float price;

};

#endif