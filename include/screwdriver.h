#ifndef SCREWDRIVER_H
#define SCREWDRIVER_H

enum screwdriver_head_size {small_head = 1 , medium_head , large_head}; //head size enum
enum screwdriver_head_type {slothead = 1 , phillipshead, pozidriv , torx , allen}; //head type enum
enum screwdriver_length {extrasmall_len = 1 , small_len , medium_len , large_len , extralarge_len}; //length enum

class screwdriver
{
    public:
    void set_head_size(int headsize);
    int get_head_size() const;
    void set_head_type(int headtype);
    int get_head_type() const;
    void set_length(int len);
    int get_length() const;

    private:
    int head_size;
    int head_type;
    int length;

};

#endif