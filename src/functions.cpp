#include<iostream>
#include "screwdriver.h"
#include "carlight.h"
#include <vector>
#include "mechanic.h"

using namespace std;

void makescrewdriver(mechanic & karbar);
void makecarlight(mechanic & karbar);

void maketools(mechanic & karbar)
{
    int choice = 5;
    while(choice != 3)
    {
        cout << "What type of tools do you want? (enter 3 to exit)" << endl;
        cout << "1- Screwdrier" << endl;
        cout << "2- Carlight" << endl;
        cout << "Enter the number of your choice: ";
        cin >> choice;
        while (choice > 3 || choice < 0)
        {
            cout << "Wrong choice. Please enter 1 for Screwdriver, or 2 for Carlight:";
            cin >> choice;
        }
        if(choice == 1)
        {
            makescrewdriver(karbar);
        }
        if(choice ==2)
        {
            makecarlight(karbar);
        }
        if(choice == 3)
        {
            return;
        }
    }
    
}

void makescrewdriver(mechanic & karbar)
{
    screwdriver a;
    cout << "What type of Screwdriver Head Type do you want?" << endl;
    cout << "1- Slothead" << endl;
    cout << "2- Phillipshead" << endl;
    cout << "3- Posizdriv" << endl;
    cout << "4- Torx" << endl;
    cout << "5 - Allen" << endl;
    cout << "Enter the number of your choice: ";
    int headtype;
    cin >> headtype;
    try
    {
        a.set_head_type(static_cast<screwdriver_head_type>(headtype));
    }
    catch(const exception& s)
    {
        cout << s.what() <<endl;
        while(headtype > 5 || headtype < 0)
        {
            cout << "Wrong choice, Please enter a valid one:" << endl;
            cin >> headtype;
        }
        a.set_head_type(static_cast<screwdriver_head_type>(headtype));   
    }
    
    cout << "What type of Screwdriver Head Size do you want?" << endl;
    cout << "1- Small Head Size" << endl;
    cout << "2- Medium Head Size" << endl;
    cout << "3- Large Head Size" << endl;
    cout << "Enter the number of your choice: ";
    int headsize;
    cin >> headsize;
    try
    {
        a.set_head_size(static_cast<screwdriver_head_size>(headsize));
    }
    catch(const exception& s)
    {
        cout << s.what() <<endl;
        while(headsize > 3 || headsize < 0)
        {
            cout << "Wrong choice, Please enter a valid one:" << endl;
            cin >> headsize;
        }
        a.set_head_size(static_cast<screwdriver_head_size>(headsize));   
    }

    cout <<"Which length do you want for this screwdriver?" << endl;
    cout << "1- Extrasmall" << endl;
    cout << "2- Small" << endl;
    cout << "3- Medium" << endl;
    cout << "4- Large" << endl;
    cout << "5- Extralarge" << endl;
    cout << "Enter the number of your choice: ";
    int length;
    cin >> length;
    try
    {
        a.set_length(static_cast<screwdriver_length>(length));
    }
    catch(const exception& s)
    {
        cout << s.what() <<endl;
        while(length >5 || length < 0)
        {
            cout << "Wrong choice, Please enter a valid one:" << endl;
            cin >> length;
        }
        a.set_length(static_cast<screwdriver_length>(length));
    }

    cout << "What quality do you want?" << endl;
    cout << "1- Low quality" << endl;
    cout << "2- Average quality" << endl;
    cout << "3- High quality" << endl;
    cout << "Enter the number of your choice: ";
    int quality;
    cin >> quality;
    try
    {
        a.set_quality(quality);
    }
    catch(const exception& s)
    {
        cout << s.what() <<endl;
        while(quality >3 || quality < 0)
        {
            cout << "Wrong choice, Please enter a valid one:" << endl;
            cin >> quality;
        }
         a.set_quality(quality);
    }

    a.choseandset_price();
    if(karbar.get_money() > a.get_price())
    {
        karbar.set_money(karbar.get_money()-a.get_price());
        karbar.alltools.push_back(&a);
    }
    else
    {
        cout << "You don't have enough money to buy this!" << endl;
    }

}

void makecarlight(mechanic & karbar)
{
    carlight a;
    cout << "What type of light do you want?" << endl;
    cout << "1- Headlight" << endl;
    cout << "2- Fog light" << endl;
    cout << "3- Blinker" << endl;
    cout << "4- Brake light" << endl;
    cout << "Enter the number of your choice: ";
    int type;
    cin >> type;
    try
    {
        a.set_light_type(static_cast<lighttype>(type));
    }
    catch(const exception& s)
    {
        cout << s.what() <<endl;
        while(type > 4 || type < 0)
        {
            cout << "Wrong choice, Please enter a valid one:" << endl;
            cin >> type;
        }
         a.set_light_type(static_cast<lighttype>(type));
    }

    cout << "What color do you want?" << endl;
    cout << "1- White" << endl;
    cout << "2- Yellow" << endl;
    cout << "3- Red" << endl;
    cout << "4- Blue" << endl;
    cout << "Enter the number of your choice: ";
    int col;
    cin >> col;
    try
    {
        a.set_color(static_cast<color>(col));
    }
    catch(const exception& s)
    {
        cout << s.what() <<endl;
        while(col > 4 || col < 0)
        {
            cout << "Wrong choice, Please enter a valid one:" << endl;
            cin >> col;
        }
         a.set_color(static_cast<color>(col));
    }

    cout << "What brightness do you want?" << endl;
    cout << "1- Low" << endl;
    cout << "2- Mid" << endl;
    cout << "3- High" << endl;
    cout << "Enter the number of your choice: ";
    int brght;
    cin >> brght;
    try
    {
        a.set_brightness(static_cast<brightness>(brght));
    }
    catch(const exception& s)
    {
        cout << s.what() <<endl;
        while(brght >3 || brght < 0)
        {
            cout << "Wrong choice, Please enter a valid one:" << endl;
            cin >> brght;
        }
         a.set_brightness(static_cast<brightness>(brght));
    }

    cout << "What quality do you want?" << endl;
    cout << "1- Low quality" << endl;
    cout << "2- Average quality" << endl;
    cout << "3- High quality" << endl;
    cout << "Enter the number of your choice: ";
    int quality;
    cin >> quality;
    try
    {
        a.set_quality(quality);
    }
    catch(const exception& s)
    {
        cout << s.what() <<endl;
        while(quality >3 || quality < 0)
        {
            cout << "Wrong choice, Please enter a valid one:" << endl;
            cin >> quality;
        }
         a.set_quality(quality);
    }

    a.choseandset_price();
    if(karbar.get_money() > a.get_price())
    {
        karbar.set_money(karbar.get_money()-a.get_price());
        karbar.alltools.push_back(&a);
    }
    else
    {
        cout << "You don't have enough money to buy this!" << endl;
    }

}