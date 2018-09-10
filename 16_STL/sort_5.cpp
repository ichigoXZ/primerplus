#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

template <class T>
int reduce(T ar[], int n);

template <class T>
void showar(T ar[], int n);

void testSord_5(){
    long arr[10] = {12, 12, 5, 6, 11, 5, 6, 77, 11, 12};
    showar(arr, 10);
    int new_size = reduce(arr, 10);
    showar(arr, new_size);

    string ars[8] = {"Hey", "why", "not", "blame", "me", "please",
                        "blame", "me"};
    showar(ars, 8);
    new_size = reduce(ars, 8);
    showar(ars, new_size);
}

template <class T>
int reduce(T ar[], int n)
{
    sort(ar, ar+n);
    return static_cast<int>(unique(ar, ar + n) - ar);
}

template <class T>
void showar(T ar[], int n)
{
    for (int i=0; i<n; i++)
        cout << ar[i] << " ";
    cout << endl;
}