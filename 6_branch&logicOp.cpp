#include "utils.h"

/* cctype
 * 处理cin错误 cin.clear()
 * 简单文件输入/输出 fstream ofstream/ifstream
 * 浮点固定输出：fixed */

struct donation{
    string name;
    double sum;
};

void upperLower_1(){
    char ch;
    while (cin>>ch && ch!='@'){
        if (isdigit(ch))
            continue;
        else if (isupper(ch))
            ch = (char)tolower(ch);
        else if (islower(ch))
            ch = (char)toupper(ch);
        cout << ch;
    }
}

double taxCal(double s){
    if (s < 5000)
        return 0;
    else if (s < 15000)
        return (s-5000)*0.1;
    else if (s < 35000)
        return 10000*0.1 + (s-10000)*0.15;
    else
        return 10000*0.1 + 20000*0.15 + (s-35000)*0.2;
}

void tax_5(){
    double salary;

    cin >> salary;
    while(salary > 0){
        cout << "Tax should pay: "
            << taxCal(salary) <<endl;
        cout << "next: ";
        cin >> salary;
    }

}

bool isVowel(char c){
    switch (c){
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return true;
        default:
            return false;
    }
}

void beginVowel_7(){
    int v=0 , c=0, o=0;
    string s;

    cout << "Enter words (q to quit):\n";
    cin >> s;

    while (s!="q"){
        if (isalpha(s[0])){
            if (isVowel(s[0]))
                v++;
            else
                c++;
        }
        else
            o++;
        cin >> s;
    }

    cout << v << " words beginning with vowels\n";
    cout << c << " words beginning with consonats\n";
    cout << o << " others\n";
}

void readFile_8(){
    ifstream inFile;
    int count=0;
    char ch;

    inFile.open("c6_8.txt");
    if(!inFile.is_open()) {
        cout << "Can not open the file!\n";
        exit(EXIT_FAILURE);
    }

    while(inFile.good()){
        inFile >> ch;
        count++;
    }
    if(inFile.eof())
        cout << "End of file reached.\n";
    else if (inFile.fail())
        cout << "Input terminated by data mismatch.\n";
    else
        cout << "Input terminated for unknown reason.\n";
    inFile.close();

    cout << "Total " << count << " characters.";
}

void readFileLine_9(){
    int n;
    struct donation *donations;
    ifstream inFile;

    inFile.open("c6_9.txt");
    if(!inFile.is_open()) {
        cout << "Can not open the file!\n";
        exit(EXIT_FAILURE);
    }

    inFile >> n;
    inFile.get();
    donations = new donation[n];
    for(int i=0; i<n; i++){
        getline(inFile,donations[i].name);
        inFile >> donations[i].sum;
        inFile.get();
    }

    cout << n << " people include:\n";
    for (int i=0; i<n; i++){
        cout << donations[i].name << endl;
        cout << donations[i].sum << endl;
    }

}