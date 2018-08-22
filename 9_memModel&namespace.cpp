#include "utils.h"
#include "golf.h"

//第3题
struct chaff
{
    char dross[20];
    int slag;
};
char buffer[1024];
int N=2;

void setChaff(chaff & c, char * dross, int slag){
    strcpy(c.dross, dross);
    c.slag = slag;
}

void showChaff(const chaff & c){
    cout << c.dross << " at " << &c.dross <<endl;
    cout << c.slag << " at " << &c.slag <<endl;
}

void newTest(){
    chaff *pc1, *pc2;
    int i;
    cout << "Calling new and placement new:\n";
    pc1 = new chaff[N];
    pc2 = new (buffer) chaff[N];

    char dross[20];
    int slag;
    for (i=0; i<N; i++){
        cout << "Enter dross of #" << i << " chaff:\n";
        cin.getline(dross, 20);
        cout << "Enter slag of #" << i << " chaff: \n";
        cin >> slag;
        cin.get();
        setChaff(pc1[i], dross, slag);
        setChaff(pc2[i], dross, slag);
    }

    cout << "Memory addresses:\n" << "  heap: " << pc1
        << "  static: " << pc2 << endl;
    for (i=0; i<N; i++){
        cout << "chaff #" << (i + 1) << ":" << endl;
        cout << "heap:\n";
        showChaff(pc1[i]);
        cout << "static:\n";
        showChaff(pc2[i]);
    }

    delete [] pc1;
    delete [] pc2;
    pc1 = NULL;
    pc2 = NULL;
}

// 第1题
void setgolf(golf & g, const char * name, int hc){
    strcpy(g.fullname,name);
    g.handicap = hc;
}

int setgolf(golf & g){
    cout << "Input fullname:";
    cin.getline(g.fullname, 40);
    if(!strcmp(g.fullname, ""))
        return 0;
    cout << "Input handicap:";
    cin >> g.handicap;
    return 1;
}

void showgolf(const golf & g){
    Show(g.fullname);
    Show(g.handicap);
}

void golf_1(){
    cout << "Example:\n";
    golf ann;
    setgolf(ann, "Ann Bridfree", 24);
    showgolf(ann);

    int i=0;
    golf * infos = new golf[Len];
    cout << "Enter info (top "<< Len <<" ), press Enter to quit\n";
    for (; i<Len; i++){
        if(!setgolf(infos[i]))
            break;
        cin.get();
    }

    for (int j=0; j<i; j++){
        showgolf(infos[j]);
    }

    delete[] infos;
    infos = NULL;
};

