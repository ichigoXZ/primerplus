#ifndef PRIMERPLUS_WORKER_H
#define PRIMERPLUS_WORKER_H

#include <string>
#include <iostream>
using namespace std;

class Person{
private:
    string firstname;
    string lastname;
protected:
    virtual void Data() const;
    virtual void Get();
public:
    Person() : firstname("none"), lastname("none") {};
    Person(const string & fn, const string & ln):
        firstname(fn), lastname(ln) {};
    virtual ~Person() = 0;
    virtual void Show() const = 0;
    virtual void Set() = 0;
};

class Gunslinger : virtual public Person{
private:
    double drawtime;
    int notches;
protected:
    void Data() const;
    void Get();
public:
    Gunslinger(): Person(), drawtime(0.0),notches(0){};
    Gunslinger(const string & fn, const string & ln, double dt, int n) :
            Person(fn, ln), drawtime(dt), notches(n) {}
    double Draw() const{return drawtime;}
    double Notches() const { return notches; }
    void Show() const ;
    void Set();
};

class PokerPlayer : virtual public Person
{
public:
    PokerPlayer(): Person() {};
    PokerPlayer(const char * fn, const char * ln)
            : Person(fn, ln) {}
    int Draw() const;
    void Show() const;
    void Set();
};

class BadDude : public PokerPlayer, public Gunslinger
{
public:
    BadDude() : Person(), Gunslinger(), PokerPlayer() {};
    BadDude(const string & fn, const string & ln, double dt, int n) :
            Person(fn, ln), Gunslinger(fn, ln, dt, n), PokerPlayer()  {}
    double Gdraw() const { return Gunslinger::Draw(); }
    double Cdraw() const { return PokerPlayer::Draw(); }
    void Show() const;
    void Set();
};




#endif //PRIMERPLUS_WORKER_H
