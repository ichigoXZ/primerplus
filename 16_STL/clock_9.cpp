#include <algorithm>
#include <vector>
#include <list>
#include <ctime>
#include <random>
#include <iostream>

using namespace std;

const int SIZE = 1000000;

void timeTest(){
    vector <int> vi0(SIZE);
    vector <int> vi(SIZE);
    list <int> vl(SIZE);

    srand(time(0));
    for(int i=0; i<SIZE; i++)
        vi0[i] = rand();
    copy(vi0.begin(), vi0.end(), vi.begin());
    copy(vi0.begin(), vi0.end(), vl.begin());

    // vector sort time
    clock_t start = std::clock();
    sort(vi.begin(), vi.end());
    clock_t end = clock();
    cout << "sort vector time: "
         << (double)(end - start)/CLOCKS_PER_SEC << endl;

    // list sort time
    start = std::clock();
    vl.sort();
    end = clock();
    cout << "sort list time: "
         << (double)(end - start)/CLOCKS_PER_SEC << endl;

    copy(vi0.begin(), vi0.end(), vl.begin());
    // list sort by converting to vector
    start = std::clock();
    copy(vl.begin(), vl.end(), vi.begin());
    sort(vi.begin(), vi.end());
    copy(vi.begin(), vi.end(), vl.begin());
    end = clock();
    cout << "list sort time (convert to vector): "
         << (double)(end - start)/CLOCKS_PER_SEC << endl;
}

