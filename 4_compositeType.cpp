#include "4_compositeType.h"

struct CandyBar{
    string brand;
    double weight;
    int Calori;
};

template <typename T>
void Show(T &a)
{
    cout << a <<endl;
}

int candyBarShow(){
    CandyBar* snack = new CandyBar[3];

    snack->brand = "Mocha Munch";
    snack->weight = 2.3;
    snack->Calori = 350;

    Show(snack->brand);
    Show(snack->weight);
    Show(snack->Calori);

    delete [] snack;
    return 0;
}

int runTest(){
    int i=0, n=3;
    for i
}