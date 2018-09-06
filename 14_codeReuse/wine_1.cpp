#include "wine_1.h"
#include <iostream>
#include <valarray>
using std::cout;
using std::cin;
using std::endl;

namespace  Wine1 {
    Wine::Wine(const char *l, int y, const int *yr, const int *bot) {
        label = l;
        years = y;
        product.first() = ArrayInt(y);
        product.second() = ArrayInt(y);
        for (int i = 0; i < years; i++) {
            product.first()[i] = yr[i];
            product.second()[i] = bot[i];
        }
    }

    Wine::Wine(const char *l, int y) {
        label = l;
        years = y;
        product.first() = ArrayInt(y);
        product.second() = ArrayInt(y);
        for (int i = 0; i < years; i++) {
            product.first()[i] = 0;
            product.second()[i] = 0;
        }
    }

    void Wine::GetBottles() {
        cout << "Enter " << label << " data for "
             << years << " year(s):" << endl;
        for (int i = 0; i < years; i++) {
            cout << "Enter year: ";
            cin >> product.first()[i];
            cout << "Enter bottles for that year: ";
            cin >> product.second()[i];
        }
        while (cin.get() != '\n')
            continue;
    }

    void Wine::Show() {
        cout << "Wine: " << label << endl;
        cout << "  Year    Bottles" << endl;
        for (int i = 0; i < years; i++) {
            cout << "  " << product.first()[i] << " "
                 << product.second()[i] << endl;
        }
    }

    int Wine::sum() {
        int total = 0;
        for (int i = 0; i < years; i++)
            total += product.second()[i];
        return total;
    }

}