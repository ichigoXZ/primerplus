#include "stonewt_5&6.h"
using std::cout;
using std::endl;
using std::cin;

void show(Stonewt & s){
    s.set_mode(Stonewt::STONES);
    cout << s;
    s.set_mode(Stonewt::IPOUNDS);
    cout << s;
    s.set_mode(Stonewt::DPOUNDS);
    cout << s;
}

void useStonewt_5(){
    Stonewt st1(120);
    Stonewt st2(120.37);
    Stonewt st3(120, 13.56);

    Stonewt st4 = 15.6 + st1;
    Stonewt st5 = 13 * st2;
    Stonewt st6 = 13 - st2;

    Stonewt st7 = st1 + 15.6;
    Stonewt st8 = st1 - 15.6;
    Stonewt st9 = st1 * 10;

    show(st1);
    show(st2);
    show(st3);
    show(st4);
    show(st5);
    show(st6);
    show(st7);
    show(st8);
    show(st9);
}

void useStonewt_6(){
    Stonewt max, min;
    int num = 0;

    Stonewt st[6] = {
            Stonewt(11,0),
            Stonewt(222.2),
            Stonewt(333.33)
    };

    for (int i = 0; i < 3; i++)
    {
        double pounds = 0;
        cout << "Enter the pounds: ";
        cin >> pounds;
        Stonewt tmp(pounds);
        st[3 + i] = tmp;
    }

    min = max = st[0];
    for (int i = 0; i < 6; i++)
    {
        if (max < st[i])
        {
            max = st[i];
        }
        else if (min > st[i])
        {
            min = st[i];
        }

        if (st[i] >= st[0])
        {
            num++;
        }
    }

    cout << "Max element: " << max;
    cout << "Min element: " << min;
    cout << "There are " << num << " element large than 11 stones." << endl;
}
