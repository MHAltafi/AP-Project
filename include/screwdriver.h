#ifndef SCREWDRIVER_H
#define SCREWDRIVER_H
#include"tools.h"

enum screwdriver_head_size {small_head = 1 , medium_head , large_head}; //head size enum
enum screwdriver_head_type {slothead = 1 , phillipshead, pozidriv , torx , allen}; //head type enum
enum screwdriver_length {extrasmall_len = 1 , small_len , medium_len , large_len , extralarge_len}; //length enum

class screwdriver : public tools//classe screwdriver marboot be anvae pich gooshti ke public inheritance az tools darad
{
    friend void operator+(tools &screw1 , const int addedprice); //operatore + baraye ezafe shodane gheymat
    friend void operator+(const int addedprice , tools &screw1); //operatore + baraye ezafe shodane gheymat
    friend void operator-(tools &screw1 , const int decreasedprice); //operatore - baraye kam shodane gheymat
    //operator haye += va -= dar classe tools tarif shode and

    public:
    screwdriver(screwdriver_head_size headsize , screwdriver_head_type headtype , screwdriver_length len , float prc , int quality); //tabe constructor
    screwdriver();
    void set_head_size(screwdriver_head_size headsize); //tabe set baraye head size
    screwdriver_head_size get_head_size() const; //tabe get baraye head size (az noe enume tarif shode)
    void set_head_type(screwdriver_head_type headtype); //tabe set baraye head type
    screwdriver_head_type get_head_type() const; //tabe get baraye head type (az noe enume tarif shode)
    void set_length(screwdriver_length len); //tabe set baraye length
    screwdriver_length get_length() const; //tabe get baraye length (az noe enume tarif shode)
    virtual void printinfo() const override; //tabe chape etelaat
    bool operator==(const screwdriver &screw1); //operatore == baraye check kardane tasavie headtype
    bool operator>(const screwdriver &screw1); //operatore > baraye moghayese headsize
    bool operator<(const screwdriver &screw1); //operatore < baraye moghayese headsize
    bool operator>=(const screwdriver &screw1); //operatore >= baraye moghayese headsize
    bool operator<=(const screwdriver &screw1); //operatore <= baraye moghayese headsize

    private:
    screwdriver_head_size head_size; //estefade az enum baraye tarife noe head size
    screwdriver_head_type head_type; //estefade az enum baraye tarife noe head type
    screwdriver_length length; //estefade az enum baraye tarife andaze length

};

#endif