#ifndef PRIMERPLUS_WINE_1_H
#define PRIMERPLUS_WINE_1_H

#include <iostream>
using std::string;
#include <valarray>
#include "pair.h"

namespace  Wine1 {
    typedef std::valarray<int> ArrayInt;
    typedef Pair<ArrayInt, ArrayInt> PairArray;

    class Wine {
    private:
        string label;
        PairArray product;
        int years;
    public:
        Wine(const char *l, int y, const int yr[], const int bot[]);

        Wine(const char *l, int y);

        void GetBottles();

        const string &Label() const { return label; }

        void Show();

        int sum();
    };


}
#endif //PRIMERPLUS_WINE_1_H
