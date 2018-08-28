#include "complex0.h"

void useComplex_7(){
    Complex a(3.0, 4.0);
    Complex c;
    cout << "Enter a complex number (q to quit):\n";
    while (cin >> c)
    {
        cout << "c is" << c;
        cout << "Complex conjugate is " << ~c;
        cout << "a is " << a;
        cout << "a + c is " << a + c;
        cout << "a - c is " << a - c;
        cout << "a * c is " << a * c;
        cout << "2 + c is " << 2 * c;
        cout << "Enter a complex number (q to quit):\n";
    }
    cout << "Done!\n";
}
