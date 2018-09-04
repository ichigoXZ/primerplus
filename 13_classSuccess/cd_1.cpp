#include "cd_1.h"
#include <cstring>
#include <iostream>

using std::cout;
using std::endl;

namespace Cd1 {

    Cd::Cd(char *s1, char *s2, int n, double x) {
        strncpy(performers, s1, 20);
        strncpy(label, s2, 20);
        selections = n;
        playtime = x;
    }

    Cd::Cd(const Cd &d) {
        strcpy(performers, d.performers);
        strcpy(label, d.label);
        selections = d.selections;
        playtime = d.playtime;
    }

    Cd::Cd() {
        performers[0] = '\n';
        label[0] = '\n';
        selections = 0;
        playtime = 0;
    }

    void Cd::Report() const {
        cout << "Performers: " << performers << endl;
        cout << "Label: " << label << endl;
        cout << "Selections: " << selections << endl;
        cout << "Playtime: " << playtime << endl;
    }

    Classic::Classic(char *s1, char *s2, char *s3, int n, double x) :
            Cd(s2, s3, n, x) {
        strncpy(hit, s1, 80);
    }

    Classic::Classic(const Classic &d) : Cd(d) {
        strcpy(hit, d.hit);
    }

    Classic::Classic() : Cd() {
        hit[0] = '\0';
    }

    void Classic::Report() const {
        Cd::Report();
        cout << "Hit song: " << hit << endl;
    }

}