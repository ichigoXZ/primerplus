#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool isPalindrome(string & s);
string reduce(string & s);

void testPalindrome_2()
{
    string input;

    cout << "Enter a word: (q to quit)";
    while(cin>>input && input!="q"){
        input = reduce(input);
        if (isPalindrome(input))
            cout << input << " is palindrome!\n";
        else
            cout << input << " is not palindrome!\n";
        cout << "Enter a word: (q to quit)";
    }
}

string reduce(string & s){
    char ch;
    string ret;
    for(auto iter = s.begin(); iter != s.end(); iter++){
        ch = *iter;
        if(isalpha(ch))
            ret.push_back(tolower(ch));
    }
    return ret;
}


