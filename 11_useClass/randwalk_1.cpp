// 第1题

#include <fstream>
#include <cstdlib>
#include <ctime>
#include "vect.h"

using namespace std;

void randwalk_1()
{
    using VECTOR::Vector;
    ofstream outFile;
    srand(time(0));

    outFile.open("randwalk.text", ios::app);
    if(!outFile.is_open()){
        cout << "can not open file!\n";
        exit(EXIT_FAILURE);
    }

    double target;
    double dstep;
    double direction;
    unsigned long steps = 0;
    Vector step;
    Vector result(0,0);

    cout << "Enter target distance (q to quit): ";
    while (cin >> target) {
        cout << "Enter step length: ";
        if (!(cin >> dstep))
            break;

        outFile << "Target Distance: " << target
            << ", Step size: " << dstep << endl;
        while(result.magval() < target)
        {
            outFile << steps << ": " << result << endl;
            direction = rand() % 360;
            step.reset(dstep, direction, Vector::POL);
            result = result + step;
            steps ++;
        }

        outFile << "After " << steps << " steps, the subject "
                                        "has the following location:\n";
        outFile << result << endl
            << "or\n";
        result.polar_mode();
        outFile << result << endl;
        outFile << "Average outward distance per step ="
            << result.magval()/steps << endl;
        steps = 0;
        result.reset(0.0, 0.0);
        outFile << endl;
        cout << "Enter target distance (q to quit): ";
    }
}
