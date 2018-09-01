#include <iostream>
#include <ctime>
using namespace std;

#include "stack_4.h"

void testStack_4(void)
{
    Stack st1(10);
    srand(time(0));
    for (size_t i = 0; i < 10; i++)
    {
        if (!st1.push(rand() % 100))
        {
            cout << "Push error!" << endl;;
        }

    }
    if (!st1.push(0))
    {
        cout << "Push 0 error!" << endl;
    }
    Stack st2(st1);
    Stack st3 = st1;
    // 故意导致pop error
    for (size_t i = 0; i < 11; i++)
    {
        Item item;
        cout << "#" << i+1 << ": " << endl;
        if (!st1.pop(item))
        {
            cout << "st1 pop error!" << endl;
        }
        else
            cout << "st1: " << item << endl;

        if (!st2.pop(item))
        {
            cout << "st2 pop error!" << endl;
        }
        else
            cout << "st2: " << item << endl;

        if (!st3.pop(item))
        {
            cout << "st3 pop error!" << endl;
        }
        else
            cout << "st3: " << item << endl;

        cout << endl;
    }
}

