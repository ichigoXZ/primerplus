#ifndef PRIMERPLUS_COMPLEX0_H
#define PRIMERPLUS_COMPLEX0_H

#include <iostream>
using namespace std;

class Complex{
private:
    double real;
    double imaginary;
public:
    Complex(double r=0,double i=0);
    Complex operator+(const Complex & c) const;
    Complex operator-(const Complex & c) const;
    Complex operator*(const Complex & c) const;
    Complex operator~();

    friend Complex operator*(double t, const Complex & c);
    friend ostream & operator << (ostream & os, const Complex & c);
    friend istream & operator >> (istream & is, Complex & c);
};

#endif //PRIMERPLUS_COMPLEX0_H
