#include "complex0.h"

Complex::Complex(double r,double i){
    real = r;
    imaginary = i;
}

Complex Complex::operator+(const Complex & c) const{
    return Complex(real+c.real, imaginary+c.imaginary);
}

Complex Complex::operator-(const Complex & c) const{
    return Complex(real-c.real, imaginary-c.imaginary);
}

Complex Complex::operator*(const Complex & c) const{
    return Complex(real*c.real, imaginary*c.imaginary);
}

Complex Complex::operator~(){
    return Complex(real, -imaginary);
}

Complex operator*(double t, const Complex & c){
    return (t*c.real, t*c.imaginary);
}

ostream & operator << (ostream & os, const Complex & c){
    os << "(" << c.real <<", " << c.imaginary << "i)\n";
    return os;
}

istream & operator >> (istream & is, Complex & c){
    cout << "real: ";
    is >> c.real;
    if (!is)
        return is;
    cout << "imaginary: ";
    is >> c.imaginary;
    cin.get();
    return is;
}