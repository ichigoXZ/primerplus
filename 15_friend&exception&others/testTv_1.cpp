#include <iostream>
#include "tv.h"

void testTv_1()
{
    Tv t;
    t.settings();

    Remote r;
    r.show_gmode();

    r.onoff(t);
    t.settings();

    t.set_gmode(r);
    r.show_gmode();
}