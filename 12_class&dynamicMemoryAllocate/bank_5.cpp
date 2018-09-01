// bank.cpp -- using the Queue interface
// compile with queue.cpp
#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()
#include "queue.h"
const int MIN_PER_HR = 60;

bool newcustomer(double x); // is there a new customer?

void bank_5()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;
// setting things up
    std::srand(std::time(0));    //  random initializing of rand()

    cout << "Case Study: Bank of Heather Automatic Teller\n";
    cout << "Enter maximum size of queue: ";
    int qs;
    cin >> qs;
    Queue line(qs);         // line queue holds up to qs people

    cout << "The number of simulation hours: 100\n";
    int hours = 100;              //  hours of simulation
    // simulation will run 1 cycle per minute
    long cyclelimit = MIN_PER_HR * hours; // # of cycles

    Item temp;              //  new customer data
    long customers = 0;     //  joined the queue
    long served = 0;        //  served during the simulation
    long sum_line = 0;      //  cumulative line length
    int wait_time = 0;      //  time until autoteller is free
    long line_wait = 0;     //  cumulative time in line
    double average_wait = 0;

    cout << "Enter the low and high average number of customers per hour: "
            "(make sure they are enough high and low)\n";
    double high, low;
    cin >> high >> low;
    double perhour;         //  average # of arrival per hour
    perhour;
    double min_per_cust;    //  average time between arrivals

    do {
        customers = 0;     //  joined the queue
        served = 0;        //  served during the simulation
        sum_line = 0;      //  cumulative line length
        wait_time = 0;      //  time until autoteller is free
        line_wait = 0;     //  cumulative time in line
        while(!line.isempty())
            line.dequeue(temp);
        perhour = (high + low) / 2;
        min_per_cust = MIN_PER_HR / perhour;
        // running the simulation
        for (int cycle = 0; cycle < cyclelimit; cycle++) {
            if (newcustomer(min_per_cust))  // have newcomer
                if (!line.isfull()){
                    customers++;
                    temp.set(cycle);    // cycle = time of arrival
                    line.enqueue(temp); // add newcomer to line
                }
            if (wait_time <= 0 && !line.isempty()) {
                line.dequeue(temp);      // attend next customer
                wait_time = temp.ptime(); // for wait_time minutes
                line_wait += cycle - temp.when();
                served++;
            }
            if (wait_time > 0)
                wait_time--;
            sum_line += line.queuecount();
        }

// reporting results
        if (customers > 0) {
            average_wait = (double) line_wait / served;
        } else
            cout << "No customers!\n";

        if (average_wait > 1)
            high = perhour;
        else
            low = perhour;

    }while(average_wait < 0.95 ||average_wait > 1.05);

    cout << "Customer per hour: " << perhour << endl;
    cout << "Average wait minutes: " << average_wait << endl;
    cout << "Done!\n";
    // cin.get();
    // cin.get();
}

