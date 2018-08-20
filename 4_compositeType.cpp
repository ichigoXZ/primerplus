#include "utils.h"

struct CandyBar{
    string brand;
    double weight;
    int Calori;
};

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
    int i, n=3;
    array<double, 3> score;
    double average = 0;
    for (i=0; i<n; i++) {
        cin >> score[i];
        average += score[i];
    }
    average = average/3;

    cout<<"You got average score:" <<average<<"in totally "<<n<<" times test."<<endl;

    return 0;
}