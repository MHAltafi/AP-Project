#include<iostream>
#include "screwdriver.h"
#include "carlight.h"
#include<vector>
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
    

}
