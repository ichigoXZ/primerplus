// randwalk.cpp -- using the Vector class
// compile with the vect.cpp file
#include <iostream>
#include <cstdlib>      // rand(), srand() prototypes
#include <ctime>        // time() prototype
#include "vect_2.h"

void randwalk_3()
{
    using namespace std;
    using VECTOR2::Vector;
    srand(time(0));     // seed random-number generator
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;

    int high, low, total;
    high = low = total = 0;
    int n;

    cout << "Enter target distance (q to quit): ";
    while (cin >> target)
    {
        cout << "Enter step length: ";
        if (!(cin >> dstep))
            break;

        cout << "Enter test times: ";
        if (!(cin >> n))
            break;

        for(int i=0; i<n; i++){
            while (result.magval() < target)
            {
                direction = rand() % 360;
                step.reset(dstep, direction, Vector::POL);
                result = result + step;
                steps++;
            }
            if (steps > high || high == 0)
                high = steps;
            if (steps < low || low == 0)
                low = steps;
            total += steps;
            steps = 0;
            result.reset(0,0);
        }

        cout << "After " << n << " times test: \n ";
        cout << "High: " << high << endl;
        cout << "Low: " << low << endl;
        cout << "Average: " << (double)total / n << endl;

        high = low = total = 0;
        cout << "Enter target distance (q to quit): ";
    }
    cout << "Bye!\n";
/* keep window open
    cin.clear();
    while (cin.get() != '\n')
        continue;
    cin.get();
*/
}
