#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string & s);

void testPalindrome_1()
{
    string input;

    cout << "Enter a word: (q to quit)";
    while(cin>>input && input!="q"){
        if (isPalindrome(input))
            cout << input << " is palindrome!\n";
        else
            cout << input << " is not palindrome!\n";
        cout << "Enter a word: (q to quit)";
    }
}

bool isPalindrome(string & s){
    string rev(s.rbegin(),s.rend());
    return (rev == s);
}


