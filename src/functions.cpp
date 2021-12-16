#include<iostream>
#include "screwdriver.h"
#include "carlight.h"
#include <vector>
#include "mechanic.h"

using namespace std;

void makescrewdriver(mechanic & karbar);
void makecarlight(mechanic & karbar);
void printboughtscrewdrivers(mechanic & kabar);
void printboughtcarlights(mechanic & karbar);
void printall(mechanic & karbar);
void balancecheck(mechanic & karbar);
void incrementbalance(mechanic & karbar);
void endapp(mechanic & karbar);

void maketools(mechanic & karbar)
{
    int choice = 9;
    while(choice != 8)
    {
        cout << "Choose your option:" << endl; //entekhabe choice
        cout << "1- Buy a Screwdrier" << endl;
        cout << "2- Buy a Carlight" << endl;
        cout << "3- Print bought Screwdrivers" << endl;
        cout << "4- Print bought Carlights" << endl;
        cout << "5- Print all bought tools" << endl;
        cout << "6- Your balance" << endl;
        cout << "7- Increment your balance" << endl;
        cout << "8- Exit" << endl;
        cout << "Enter the number of your choice: ";
        cin >> choice;
        while (choice > 8 || choice < 1) //daryafte dobare choice dar soorate eshtebah boodan
        {
            cout << "Wrong choice." << endl;
            cout << "1- Buy a Screwdrier" << endl;
            cout << "2- Buy a Carlight" << endl;
            cout << "3- Print bought Screwdrivers" << endl;
            cout << "4- Print bought Carlights" << endl;
            cout << "5- Print all bought tools" << endl;
            cout << "6- Your balance" << endl;
            cout << "7- Increment your balance" << endl;
            cout << "8- Exit" << endl;
            cout << "Enter the number of your choice: ";
            cin >> choice;
        }
        
        switch (choice) //switch case baraye choice
        {
        case 1:
            makescrewdriver(karbar);
            break;
        case 2:
            makecarlight(karbar);
            break;
        case 3:
            printboughtscrewdrivers(karbar);
            break;
        case 4:
            printboughtcarlights(karbar);
            break;
        case 5:
            printall(karbar);
            break;
        case 6:
            balancecheck(karbar);
            break;
        case 7:
            incrementbalance(karbar);
            break;
        case 8:
            endapp(karbar);
            return;
        
        default:
            break;
        }
    }
    
}

void makescrewdriver(mechanic & karbar) //sakhte pichgooshti bar asase vizhegi haye morede nazare karbar
{
    screwdriver * a; //pointer
    a = new screwdriver(); //new kardan
    cout << "What type of Screwdriver Head Type do you want?" << endl; //anvae headtype va daryafte an
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
        a->set_head_type(static_cast<screwdriver_head_type>(headtype)); //try baraye head type
    }
    catch(const exception& s) //catch baraye head type dar soorate invalid boodane vorudi
    {
        cout << s.what() <<endl;
        while(headtype > 5 || headtype < 1) //daryafte dobare head type
        {
            cout << "Wrong choice, Please enter a valid one:" << endl;
            cin >> headtype;
        }
        a->set_head_type(static_cast<screwdriver_head_type>(headtype)); //gharar dadane headtype
    }
    
    cout << "What type of Screwdriver Head Size do you want?" << endl; //anvae headsize va daryafte an
    cout << "1- Small Head Size" << endl;
    cout << "2- Medium Head Size" << endl;
    cout << "3- Large Head Size" << endl;
    cout << "Enter the number of your choice: ";
    int headsize;
    cin >> headsize;
    try
    {
        a->set_head_size(static_cast<screwdriver_head_size>(headsize)); //try baraye headsize
    }
    catch(const exception& s) //catch baraye headsize dar soorate invalid boodane vorudi
    {
        cout << s.what() <<endl;
        while(headsize > 3 || headsize < 1)
        {
            cout << "Wrong choice, Please enter a valid one:" << endl;
            cin >> headsize; //daryafte dobare headsize
        }
        a->set_head_size(static_cast<screwdriver_head_size>(headsize));  //gharar dadane headsize  
    }

    cout <<"Which length do you want for this screwdriver?" << endl; //anvae length va daryafte an
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
        a->set_length(static_cast<screwdriver_length>(length)); //try baraye length
    }
    catch(const exception& s) //catch baraye length dar soorate invalid boodane vorudi
    {
        cout << s.what() <<endl;
        while(length >5 || length < 1)
        {
            cout << "Wrong choice, Please enter a valid one:" << endl;
            cin >> length; //daryafte dobare length
        }
        a->set_length(static_cast<screwdriver_length>(length)); //gharar dadane length
    }

    cout << "What quality do you want?" << endl; //anvae quality va daryafte an
    cout << "1- Low quality" << endl;
    cout << "2- Average quality" << endl;
    cout << "3- High quality" << endl;
    cout << "Enter the number of your choice: ";
    int quality;
    cin >> quality;
    try
    {
        a->set_quality(quality); //try baraye quality
    }
    catch(const exception& s) //catch baraye quality dar soorate invalid boodane vorudi
    {
        cout << s.what() <<endl;
        while(quality >3 || quality < 1)
        {
            cout << "Wrong choice, Please enter a valid one:" << endl;
            cin >> quality; //daryafte dobare quality
        }
         a->set_quality(quality); //gharar dadane quality
    }

    a->choseandset_price(); //farakhani tabe gheymat gozari bar asase vorudi haye karbar
    if(karbar.get_money() > a->get_price()) //check kardane mojudi karbar
    {
        karbar.set_money(karbar.get_money()-a->get_price()); //kam shodan az poole karbar
        karbar.alltools.push_back(a); //pushback be vectore abzare kharide shode
        cout << "-----------------------------------------------" << endl;
    }
    else //agar mojudi karbar kafi nabashad
    {
        cout << "-----------------------------------------------" << endl;
        cout << "You don't have enough money to buy this!" << endl;
        cout << "Money needed to buy this: " << a->get_price() << "$" << endl;
        cout << "Your money: " << karbar.get_money() << "$" << endl;
        cout << "-----------------------------------------------" << endl;
        delete a; //delete kardan, chon shei nabayad sakhte shavad
    }

}

void makecarlight(mechanic & karbar) //sakhte carlight bar asase vizhegi haye morede nazare karbar
{
    carlight * a; //pointer
    a = new carlight(); //new kardan
    cout << "What type of light do you want?" << endl; //anbae lighttype va daryafte an
    cout << "1- Headlight" << endl;
    cout << "2- Fog light" << endl;
    cout << "3- Blinker" << endl;
    cout << "4- Brake light" << endl;
    cout << "Enter the number of your choice: ";
    int type;
    cin >> type;
    try
    {
        a->set_light_type(static_cast<lighttype>(type)); //try baraye headtype
    }
    catch(const exception& s) //catch baraye headtype dar soorate invalid boodane vorudi
    {
        cout << s.what() <<endl;
        while(type > 4 || type < 1)
        {
            cout << "Wrong choice, Please enter a valid one:" << endl;
            cin >> type; //daryafte dobare headtype
        }
         a->set_light_type(static_cast<lighttype>(type));//gharar dadane headtype
    }

    cout << "What color do you want?" << endl; //anvae color va daryafte an
    cout << "1- White" << endl;
    cout << "2- Yellow" << endl;
    cout << "3- Red" << endl;
    cout << "4- Blue" << endl;
    cout << "Enter the number of your choice: ";
    int col;
    cin >> col;
    try 
    {
        a->set_color(static_cast<color>(col)); //try baraye color
    }
    catch(const exception& s) //catch baraye color dar soorate invalid boodane vorudi
    {
        cout << s.what() <<endl;
        while(col > 4 || col < 1)
        {
            cout << "Wrong choice, Please enter a valid one:" << endl;
            cin >> col; //daryafte dobare color
        }
         a->set_color(static_cast<color>(col)); //gharar dadane color
    }

    cout << "What brightness do you want?" << endl; //anvae brightness va daryafte an
    cout << "1- Low" << endl;
    cout << "2- Mid" << endl;
    cout << "3- High" << endl;
    cout << "Enter the number of your choice: ";
    int brght;
    cin >> brght;
    try
    {
        a->set_brightness(static_cast<brightness>(brght)); //try baraye brightness
    }
    catch(const exception& s) //catch baraye brightness dar soorate invalid boodane vorudi
    {
        cout << s.what() <<endl;
        while(brght >3 || brght < 1)
        {
            cout << "Wrong choice, Please enter a valid one:" << endl;
            cin >> brght; //daryafte dobare brightness
        }
         a->set_brightness(static_cast<brightness>(brght)); //gharar dadane brightness
    }

    cout << "What quality do you want?" << endl; //anvae quality va daryafte an
    cout << "1- Low quality" << endl;
    cout << "2- Average quality" << endl;
    cout << "3- High quality" << endl;
    cout << "Enter the number of your choice: ";
    int quality;
    cin >> quality;
    try
    {
        a->set_quality(quality); //try baraye quality
    }
    catch(const exception& s) //catch baraye quality dar soorate invalid boodane vorudi
    {
        cout << s.what() <<endl;
        while(quality >3 || quality < 1)
        {
            cout << "Wrong choice, Please enter a valid one:" << endl;
            cin >> quality; //daryafte dobare quality
        }
         a->set_quality(quality); //gharar dadane quality
    }

    a->choseandset_price(); //farakhani tabe gheymat gozari bar asase vorudi haye karbar
    if(karbar.get_money() > a->get_price()) //check kardane mojudi karbar
    {
        karbar.set_money(karbar.get_money()-a->get_price()); //kam shodan az poole karbar
        karbar.alltools.push_back(a); //pushback be vectore abzare kharide shode
        cout << "-----------------------------------------------" << endl;
    }
    else //agar mojudi karbar kafi nabashad
    {
        cout << "-----------------------------------------------" << endl;
        cout << "You don't have enough money to buy this!" << endl;
        cout << "Money needed to buy this: " << a->get_price() << "$" << endl;
        cout << "Your money: " << karbar.get_money() << "$" << endl;
        cout << "-----------------------------------------------" << endl;
        delete a; //delete kardan, chon shei nabayad sakhte shavad
    }

}

void printboughtscrewdrivers(mechanic & karbar) //tabe chape screwdriverhaye kharide shode ba estefade az esharegar o polymorphism
{
    cout << "-----------------------------------------------" << endl;
    cout << "Informations about screwdrivers you have bought:" << endl;
    screwdriver *x = nullptr;
    bool check = false;
    for (auto i : karbar.alltools)
    {
        x = dynamic_cast<screwdriver*>(i);
        if(x != nullptr)
        {
            x->printinfo();
            check = true;
        }
    }
    if(check == false) //agar screwdriveri nakharide bashad
    {
        cout << "You haven't bought any screwdrivers." << endl;
        cout << "------------------------------------" << endl;
    }   
}

void printboughtcarlights(mechanic & karbar) //tabe chape carlight haye kharide shode ba estefade az esharegar o polymorphism
{
    cout << "-----------------------------------------------" << endl;
    cout << "Informations about carlights you have bought:" << endl;
    carlight *x = nullptr;
    bool check = false;
    for(auto i : karbar.alltools)
    {
        x= dynamic_cast<carlight*>(i);
        if(x != nullptr)
        {
            x->printinfo();
            check = true;
        }
    }
    if(check == false)
    {
        cout << "You haven't bought any carlights." << endl;
        cout << "------------------------------------" << endl;
    }
}

void printall(mechanic & karbar) //tabe chape tamame abzar haye kharide shode
{
    tools * c = nullptr;
    bool check = false;
    for(auto i : karbar.alltools)
    {
        c = i;
        if(c != nullptr)
        {
            c->printinfo();
            check = true;
        }
    }
    if(check == false)
    {
        cout << "------------------------------------" << endl;
        cout << "You haven't bought any tools." << endl;
        cout << "------------------------------------" << endl; 
    }
}

void balancecheck(mechanic & karbar) //tabe chape poole karbar
{
    cout <<"Your balance is :" << karbar.get_money() << "$" << endl;
    cout << "------------------------------------" << endl; 
}

void incrementbalance(mechanic & karbar) //tabe afzayeshe mojudi karbar
{
    cout << "--------------------------------------------------" << endl; 
    cout << "How much money do you want to add to your balance?";
    float addedmoney;
    cin >> addedmoney;
    karbar.set_money(karbar.get_money()+addedmoney);
    cout << "--------------------------------------------------" << endl; 
}

void endapp(mechanic & karbar) //delete kardane faza haye gerefte shode
{
    for (auto i : karbar.alltools)
    {
        delete i;
    }
    
}