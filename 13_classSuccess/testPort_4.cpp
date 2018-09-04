#include "port_4.h"

void testPort(void)
{
    Port port1("Gallo", "tawny", 20);
    VintagePort vp("None", 20, "The Noble", 1997);

    port1.Show();
    vp.Show();

    VintagePort vp2 = vp;
    Port port2 = port1;

    cout << vp2 << endl;
    cout << port2 << endl;
}
