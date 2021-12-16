#include<iostream>
#include "screwdriver.h"
#include "carlight.h"
#include <vector>
#include "mechanic.h"

using namespace std;

void maketools(mechanic & karbar);

int main()
{   
    cout << "Welcome to the mechanic app!" << endl;
    cout << "Please enter your name: ";
    string name;
    cin >> name;
    cout << "How much money do you have?" << endl;
    float money;
    cin >> money;
    mechanic karbar(money,name);
    maketools(karbar);

    /*alltools.push_back(&a);
    alltools.push_back(&d);

    tools * c = nullptr;
    screwdriver *x = nullptr;
    carlight * y = nullptr;
    x = dynamic_cast<screwdriver*>(alltools[0]);
    if(x != nullptr)
    {
        cout << "kar kard" << endl;
    }
    x = dynamic_cast<screwdriver *>(alltools[1]);
    if(x != nullptr)
    {
        cout << "kar nkard" << endl;
    }*/
    

}
