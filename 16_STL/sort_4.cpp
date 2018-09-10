#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int reduce(long ar[], int n);
void showar(long ar[], int n);

void testSord_4(){
    long arr[10] = {12, 12, 5, 6, 11, 5, 6, 77, 11, 12};
    showar(arr, 10);
    int new_size = reduce(arr, 10);
    showar(arr, new_size);
}

int reduce(long ar[], int n)
{
    vector <long>::iterator vec;
    sort(ar, ar+n);
    return static_cast<int>(unique(ar, ar + n) - ar);
}

void showar(long ar[], int n)
{
    for (int i=0; i<n; i++)
        cout << ar[i] << " ";
    cout << endl;
}