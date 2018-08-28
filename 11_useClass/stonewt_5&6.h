#ifndef PRIMERPLUS_STONEWT_5_H
#define PRIMERPLUS_STONEWT_5_H

#include <iostream>
class Stonewt {
    public:
        enum Mode {STONES, IPOUNDS, DPOUNDS};
    private:
        enum {
            Lbs_per_stn = 14
        };      // pounds per stone
        int stone;                    // whole stones
        double pds_left;              // fractional pounds
        double pounds;                // entire weight in pounds
        Mode mode;
    public:
        Stonewt(double lbs);          // constructor for double pounds
        Stonewt(int stn, double lbs); // constructor for stone, lbs
        Stonewt();                    // default constructor
        void set_mode(Mode m) {mode=m;};
//        ~Stonewt();

        Stonewt operator+(double t);
        Stonewt operator-(double t);
        Stonewt operator*(double t);
        friend Stonewt operator+(double t, Stonewt & s)
        {return s + t;}
        friend Stonewt operator-(double t, Stonewt & s)
        {return s - t;}
        friend Stonewt operator*(double t, Stonewt & s)
        {return s * t;}
        friend std::ostream & operator<<(std::ostream & os, const Stonewt & s);

        bool operator< (Stonewt & s) const {return pounds < s.pounds;}
        bool operator<= (Stonewt & s) const {return pounds <= s.pounds;}
        bool operator> (Stonewt & s) const {return pounds > s.pounds;}
        bool operator>= (Stonewt & s) const {return pounds >= s.pounds;}
        bool operator== (Stonewt & s) const {return pounds == s.pounds;}
        bool operator!= (Stonewt & s) const {return pounds != s.pounds;}
    };
#endif //PRIMERPLUS_STONEWT_5_H
