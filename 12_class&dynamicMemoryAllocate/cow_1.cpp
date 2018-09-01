#include <iostream>
#include <cstring>

using namespace std;

class Cow{
private:
    char name[20];
    char * hobby;
    double weight;
public:
    Cow();
    Cow(const char * nm, const char * ho, double wt);
    Cow(const Cow & c);
    ~Cow();
    Cow & operator=(const Cow &c);
    void ShowCow() const;
};

Cow::Cow() {
    name[0] = '/0';
    hobby = nullptr;
    weight = 0;
}

Cow::Cow(const char *nm, const char *ho, double wt) {
    strncpy(name, nm, 20);
    hobby = new char[strlen(ho)+1];
    strcpy(hobby, ho);
    weight = wt;
}

Cow::Cow(const Cow & c){
    strcpy(name, c.name);
    hobby = new char[strlen(c.hobby)+1];
    strcpy(hobby, c.hobby);
    weight = c.weight;
}

Cow::~Cow() {
    delete [] hobby;
    weight = 0;
}

Cow & Cow::operator=(const Cow &c){
    delete [] hobby;
    hobby = new char[strlen(c.hobby)+1];
    strcpy(hobby, c.hobby);
    weight = c.weight;
}

void Cow::ShowCow() const{
    cout << "Cow name: " << name << endl;
    cout << "Cow hobby: " << hobby << endl;
    cout << "Cow weight: " << weight << endl;
}

void cow_1(){
    Cow cow1("Lovely", "eat", 123.4);
    Cow cow2("Cute", "drink", 321.2);
    Cow cow3(cow2);
    Cow cow4 = cow1;

    cow1.ShowCow();
    cow2.ShowCow();
    cow3.ShowCow();
    cow4.ShowCow();
}