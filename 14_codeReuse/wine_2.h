#ifndef PRIMERPLUS_WINE_2_H
#define PRIMERPLUS_WINE_2_H

#include <iostream>
using std::string;
#include "pair.h"
#include <valarray>
using std::valarray;

namespace Wine2 {

    class Wine : private string,
                 private Pair<valarray<int>, valarray<int> > {
    private:
        typedef valarray<int> ArrayInt;
        typedef Pair<ArrayInt, ArrayInt> PairArray;
        int years;
    public:
        Wine(const char *l, int y, const int yr[], const int bot[]) :
                string(l), years(y), PairArray(ArrayInt(yr, y), ArrayInt(bot, y)) {};

        Wine(const char *l, int y) :
                string(l), years(y), PairArray(ArrayInt(y), ArrayInt(y)) {};

        void GetBottles();

        const string &Label() const { return (const string &) *this; }

        void Show();

        int sum() const { return PairArray::second().sum(); };
    };

}
#endif //PRIMERPLUS_WINE_2_H
