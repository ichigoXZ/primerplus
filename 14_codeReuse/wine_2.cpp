#include "wine_2.h"

#include <iostream>
#include <valarray>

namespace Wine2 {

    using std::cin;
    using std::cout;
    using std::endl;
    using std::valarray;

    void Wine::GetBottles() {
        cout << "Enter " << (string &) *this << " data for "
             << years << " year(s):" << endl;
        for (int i = 0; i < years; i++) {
            cout << "Enter year: ";
            cin >> PairArray::first()[i];
            cout << "Enter bottles for that year: ";
            cin >> PairArray::second()[i];
        }
        while (cin.get() != '\n')
            continue;
    }

    void Wine::Show() {
//        cout << "Wine 2\n";
        cout << "Wine: " << (string &) *this << endl;
        cout << "  Year    Bottles" << endl;
        for (int i = 0; i < years; i++) {
            cout << "  " << PairArray::first()[i] << " "
                 << PairArray::second()[i] << endl;
        }
    }
}