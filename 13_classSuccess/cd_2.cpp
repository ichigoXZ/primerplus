#include "cd_2.h"
#include <cstring>
#include <iostream>

using std::cout;
using std::endl;

namespace Cd2 {

    Cd::Cd(char *s1, char *s2, int n, double x) {
        performers = new char[strlen(s1) + 1];
        strcpy(performers, s1);
        label = new char[strlen(s2) + 1];
        strcpy(label, s2);
        selections = n;
        playtime = x;
    }

    Cd::Cd(const Cd &d) {
        performers = new char[strlen(d.performers) + 1];
        strcpy(performers, d.performers);
        label = new char[strlen(d.label) + 1];
        strcpy(label, d.label);
        selections = d.selections;
        playtime = d.playtime;
    }

    Cd::Cd() {
        performers = new char[1];
        performers[0] = '\0';
        label = new char[1];
        label[0] = '\0';
        selections = 0;
        playtime = 0;
    }

    Cd::~Cd() {
        delete [] performers;
        delete [] label;
    }

    void Cd::Report() const {
        cout << "Performers: " << performers << endl;
        cout << "Label: " << label << endl;
        cout << "Selections: " << selections << endl;
        cout << "Playtime: " << playtime << endl;
    }

    Cd& Cd::operator=(const Cd &d) {
        if (this == &d)
            return *this;
        delete [] performers;
        delete [] label;
        performers = new char[strlen(d.performers) + 1];
        strcpy(performers, d.performers);
        label = new char[strlen(d.label) + 1];
        strcpy(label, d.label);
        selections = d.selections;
        playtime = d.playtime;
        return *this;
    }

    Classic::Classic(char *s1, char *s2, char *s3, int n, double x) :
            Cd(s2, s3, n, x) {
        hit =  new char[strlen(s1) + 1];
        strcpy(hit, s1);
    }

    Classic::Classic(const Classic &d) : Cd(d) {
        delete [] hit;
        hit =  new char[strlen(d.hit) + 1];
        strcpy(hit, d.hit);
    }

    Classic::Classic() : Cd() {
        hit = new char[1];
        hit[0] = '\0';
    }

    Classic::~Classic() {
        delete [] hit;
    }

    void Classic::Report() const {
        Cd::Report();
        cout << "Hit song: " << hit << endl;
    }

    Classic& Classic::operator=(const Classic &d) {
        if (this == &d)
            return *this;
        Cd::operator=(d);
        delete [] hit;
        hit =  new char[strlen(d.hit) + 1];
        strcpy(hit, d.hit);
        return *this;
    }
}
