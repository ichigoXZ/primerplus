#include "port_4.h"
#include <cstring>

Port::Port(const char *br, const char *st, int b) {
    brand = new char[strlen(br) + 1];
    strcpy(brand, br);
    strncpy(style, st, 20);
    bottles = b;
}

Port::Port(const Port &p) {
    brand = new char[strlen(p.brand) + 1];
    strcpy(brand, p.brand);
    strcpy(style, p.style);
    bottles = p.bottles;
}

Port& Port::operator=(const Port &p) {
    if (this == &p)
        return *this;
    delete [] brand;
    brand = new char[strlen(p.brand) + 1];
    strcpy(brand, p.brand);
    strcpy(style, p.style);
    bottles = p.bottles;
    return *this;
}

Port& Port::operator+=(int b) {
    bottles += b;
    return *this;
}

Port& Port::operator-=(int b) {
    bottles -= b;
    return *this;
}

void Port::Show() const {
    std::cout << "Brand: " << brand << std::endl;
    std::cout << "Style: " << style << std::endl;
    std::cout << "Bottles: " << bottles << std::endl;
}

ostream & operator<<(ostream & os, const Port & p){
    os << p.brand << ", " << p.style << ", " << p.bottles;
    return os;
}

VintagePort::VintagePort(const char *br, int b, const char *nn, int y) :
    Port(br, "vintage" , b)
{
    nickname = new char[strlen(nn) + 1];
    strcpy(nickname, nn);
    year = y;
}

VintagePort::VintagePort(const VintagePort &vp) : Port(vp){
    nickname = new char[strlen(vp.nickname) + 1];
    strcpy(nickname, vp.nickname);
    year = vp.year;
}

VintagePort& VintagePort::operator=(const VintagePort &vp) {
    if (this == &vp)
        return *this;
    Port::operator=(vp);
    delete [] nickname;
    nickname = new char[strlen(vp.nickname) + 1];
    strcpy(nickname, vp.nickname);
    year = vp.year;
    return *this;
}

void VintagePort::Show() const {
    Port::Show();
    cout << "Nickname: " << nickname << endl;
    cout << "Year: " << year << endl;
}

ostream & operator<<(ostream & os, const VintagePort & vp){
    os << Port(vp);
    os << ", " << vp.nickname << ", " << vp.year;
    return os;
}
