#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <vector>

using namespace std;

bool isPalindrome(string & s);
string reduce(string & s);

void testPalindrome_3()
{
    vector <string> input;
    string s;
    ifstream infile;
    infile.open("words.txt");
    if(!infile.is_open()) {
        cout << "Cannot open file!\n";
        exit(EXIT_FAILURE);
    }
    while(infile >> s)
        input.push_back(s);

    int num = input.size(), i=0;
    cout << num << " words in words.txt.\n";

    for(auto iter = input.begin(); iter != input.end(); iter++){
        s = reduce(*iter);
        cout << i++ << ": ";
        if (isPalindrome(s))
            cout << s << " is palindrome!\n";
        else
            cout << s << " is not palindrome!\n";
    }
}




