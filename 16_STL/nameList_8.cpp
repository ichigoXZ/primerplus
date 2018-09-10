#include <ctime>
#include <vector>
#include <algorithm>
#include <iostream>

using std::vector;
using std::string;
using std::cout;
using std::cin;

inline void show(std::string & s) { cout << s << " "; }

void nameList_8(){
    vector <string> Mat;
    vector <string> Pat;
    vector <string> both;
    string s;

    cout << "Mat! Enter your friends' name:"
            "(q to quit)\n";
    while (cin >> s && s != "q")
        Mat.push_back(s);

    cout << "Pat! Enter your friends' name:"
            "(q to quit)\n";
    while (cin >> s && s != "q")
        Pat.push_back(s);

    sort(Mat.begin(), Mat.end());
    sort(Pat.begin(), Pat.end());

    cout << "Mat's friends:\n";
    for_each(Mat.begin(), Mat.end(), show);
    cout << std::endl;
    cout << "Pat's friends:\n";
    for_each(Pat.begin(), Pat.end(), show);

    both.resize(Mat.size() + Pat.size());
    merge(Mat.begin(), Mat.end(), Pat.begin(), Pat.end(), both.begin());
    unique(both.begin(), both.end());

    cout << std::endl;
    cout << "Pat's friends or Mat's friends:\n";
    for_each(both.begin(), both.end(), show);
};
