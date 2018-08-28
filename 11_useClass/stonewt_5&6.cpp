// stonewt.cpp -- Stonewt methods
#include <iostream>
using std::cout;
#include "stonewt_5&6.h"
using std::iostream;

// construct Stonewt object from double value
    Stonewt::Stonewt(double lbs) {
        stone = int(lbs) / Lbs_per_stn;    // integer division
        pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
        pounds = lbs;
        mode = DPOUNDS;
    }

// construct Stonewt object from stone, double values
    Stonewt::Stonewt(int stn, double lbs) {
        stone = stn;
        pds_left = lbs;
        pounds = stn * Lbs_per_stn + lbs;
        mode = STONES;
    }

    Stonewt::Stonewt()          // default constructor, wt = 0
    {
        stone = pounds = pds_left = 0;
    }

//    Stonewt::~Stonewt()         // destructor
//    {
//    }
    Stonewt Stonewt::operator+(double t){
            double p = t + pounds;
            return Stonewt(p);
    }

    Stonewt Stonewt::operator-(double t){
        Stonewt temp;
        double p = pounds - t;
        return Stonewt(p);
    }

    Stonewt Stonewt::operator*(double t){
        Stonewt temp;
        double p = pounds * t;
        return Stonewt(p);
    }

    std::ostream & operator<<(std::ostream & os, const Stonewt & s){
        if (s.mode == Stonewt::STONES)
            cout << s.stone << " stone, " << s.pds_left << " pounds\n";
        else if (s.mode == Stonewt::DPOUNDS)
            cout << s.pounds << "pounds.\n";
        else if (s.mode == Stonewt::IPOUNDS)
            cout << (int)s.pounds << "pounds.\n";
    }

