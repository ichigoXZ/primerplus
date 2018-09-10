#include <ctime>
#include <vector>
#include <algorithm>
#include <iostream>

using std::vector;

vector<int> lotto(int total, int select);


void testLotto(){
    vector<int> winners;
    winners = lotto(51, 6);
    std::cout << "Winner numbers:\n";
    for(int i=0; i<6; i++)
        std::cout << winners[i] << " ";
}

vector<int> lotto(int total, int select)
{
    vector <int> items;
    for(int i=0; i<total; i++)
        items.push_back(i);
    srand(time(0));
    random_shuffle(items.begin(), items.end());
    vector <int> lucky(items.begin(),items.begin()+select);
    sort(lucky.begin(), lucky.end());
    return lucky;
}
