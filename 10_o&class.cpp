#include "utils.h"

#define MAX 10

//第6题
class Move
{
private:
    double x;
    double y;
public:
    Move(double a = 0, double b =0 );
    void showmove() const;
    Move add(const Move & m) const;
    void reset(double a = 0, double b = 0);
};

Move::Move(double a, double b){
    x = a;
    y = b;
}

void Move::showmove() const {
    cout << "x=" << x
        << " ,y=" << y << endl;
}

Move Move::add(const Move & m) const {
    Move tmp;
    tmp.x = x + m.x;
    tmp.y = y + m.y;
    return tmp;
}

void Move::reset(double a, double b) {
    x = a;
    y = b;
}

void move_6(){
    Move a(3,4);
    Move b(4,5);
    Move c;
    cout << "a:\n";
    a.showmove();
    cout << "b:\n";
    b.showmove();
    cout << "c:\n";
    c.showmove();
    cout << "a+b:\n";
    c = a.add(b);
    c.showmove();
    a.reset(1,1);
    cout << "a:\n";
    a.showmove();
};

// 第8题
typedef int item;

class List{
private:
    item items[MAX];
    int top;
public:
    List(){ top = 0; }
    int add(item & x);
    bool isempty() const { return top == 0; }
    bool isfull() const { return top == MAX; }
    item visit(int pos);
};

int List::add(item &x) {
    if (isfull()) {
        cout << "List full! cannot add.\n";
        return 0;
    }
    items[top] = x;
    top ++;
    return top;
}
item List::visit(int pos) {
    if (pos >= top){
        cout << "no this element!\n";
        exit(EXIT_FAILURE);
    }
    return items[pos-1];
}

void list_8(){
    List list;
    item x = 27;
    int i;
    if (list.isempty())
        cout << "List is empty" << endl;

    item d[MAX] = {1,2,3,4,5,6,7,8,9,10};
    for(i=0; i< 3; i++)
        list.add(d[i]);

    if (list.isempty())
        cout << "List is empty" << endl;
    else if (list.isfull())
        cout << "List is full" << endl;
    else
        cout << "Some items in the list" << endl;

//    cout << "items[4]: " << list.visit(4) << endl;

    for (;i<MAX;i++)
        list.add(d[i]);
    if (list.isempty())
        cout << "List is empty" << endl;
    else if (list.isfull())
        cout << "List is full" << endl;
    else
        cout << "Some items in the list" << endl;

    cout << "items[4]: " << list.visit(4) << endl;

    list.add(x);
};



