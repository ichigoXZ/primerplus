#include <iostream>
#include "wine_1.h"
#include "wine_2.h"
using namespace std;
//using namespace Wine1;
using namespace Wine2;

void testWine(){
    cout << "Enter name of wine: ";
    char lab[50];
    cin.getline(lab, 50);
    cout << "Enter number of years: ";
    int yrs;
    cin >> yrs;

    Wine holding(lab, yrs);
    holding.GetBottles();
    holding.Show();

    const int YRS = 3;
    int y[YRS] = { 1993, 1995, 1998 };
    int b[YRS] = { 48, 60, 72 };

    Wine more("Gushing Grape Red", YRS, y, b);
    more.Show();

    cout << "Total bottles for " << more.Label()
         << ": " << more.sum() << endl;

    cout << "Bye\n";
}
