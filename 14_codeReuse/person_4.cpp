#include "person_4.h"
#include <iostream>
#include <ctime>
using std::cout;
using std::cin;
using std::endl;

Person::~Person() {}

void Person::Data() const {
    cout << "firstname" << firstname << endl;
    cout << "lastname" << lastname << endl;
}

void Person::Get() {
    cout << "Enter firstname: ";
    cin >> firstname;
    cout << "Enter lastname: ";
    cin >> lastname;
}

void Gunslinger::Data() const
{
    std::cout << "Draw: " << drawtime << std::endl;
    std::cout << "Notches: " << notches << std::endl;
}

void Gunslinger::Get() {
    std::cout << "Enter Drawtime: ";
    std::cin >> drawtime;
    std::cout << "Enter Notches: ";
    std::cin >> notches;
}

void Gunslinger::Show() const
{
    cout << "Category: Gunslinger\n";
    Person::Data();
    Data();
}

void Gunslinger::Set()
{
    Person::Get();
    Get();
}

void PokerPlayer::Show() const {
    cout << "Category: PokerPlayer\n";
    Person::Data();
}

void PokerPlayer::Set() {
    Person::Get();
}

int PokerPlayer::Draw() const
{
    srand(time(0));
    return int(rand()) % 52;
}


void BadDude::Show() const
{
    cout << "Category: Bad Dude\n";
    Person::Data();
    Gunslinger::Data();
}

void BadDude::Set()
{
    Person::Get();
    Gunslinger::Get();
}