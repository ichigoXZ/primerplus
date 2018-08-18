//
// Created by atath on 2018/8/18.
//
#include "5_loop&relation.h"

struct car{
    string producer;
    int year;
};

void CleoDaphne(){
    double Cleo=100, Daphne=100;
    double Dbase=Daphne;
    int count=0;
    for (; Cleo <= Daphne; count++){
        Cleo = Cleo * (1+0.05);
        Daphne = Daphne + Dbase * 0.1;
    }
    cout << "After " << count << " years, Cleo has:"
        << Cleo << " while Daphne has:" << Daphne <<endl;
}

void carInfo(){
    int n, i;
    struct car * cars;

    cout << "How many cars do you wish to catalog? ";
    cin >> n;
    cin.get();
    cars = new struct car[n];

    for(i=0; i<n; i++) {
        cout << "Car #" << i+1 << ":" << endl;
        cout << "Please enter the make:";
        getline(cin, cars[i].producer);
        cout << "Please enter the year made:";
        cin >> cars[i].year;
        cin.get();
    }

    cout << "Here is your collection:" << endl;
    for (i=0; i<n; i++){
        cout << cars[i].year << " " << cars[i].producer << endl;
    }

    delete[] cars;
    cars = NULL;
}

void checkDone(){
//    char word[10];
    string word;
    int count=0;

    cout << "Enter words (to stop, type the word done):\n";
    cin >> word;
//    while(!strcmp(word, "done")==0){
    while(word != "done"){
        count ++;
        cin >> word;
    }

    cout << "You entered a total of " << count << " words";
}

void starLine(){
    int n;
    cout << "Enter number of rows:";
    cin >> n;

    for(int i=n-1; i>=0; i--){
        for(int j=0; j<n; j++){
            if (j<i)
                cout << '_';
            else
                cout << '*';
        }
        cout << endl;
    }
}