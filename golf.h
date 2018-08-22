#ifndef PRIMERPLUS_GOLF_H
#define PRIMERPLUS_GOLF_H

const int Len = 40;
struct golf
{
    char fullname[Len];
    int handicap;
};

void setgolf(golf & g, const char * name, int hc);

// non-interactive version
int setgolf(golf &g);

// interactive version
int setgolf(golf & g);

void showgolf(const golf & g);

#endif //PRIMERPLUS_GOLF_H
