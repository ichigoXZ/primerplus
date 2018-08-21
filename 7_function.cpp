/* 7 函数——C++的编程模块
 * 尽可能使用const
 * 函数指针
 * auto 和 typedef 进行简化 */

#include "utils.h"

 typedef double (*pf)(double, double);

 double add(double x, double y){
     return x + y;
 }

 double multiply(double x, double y){
     return x * y;
 }

 double divide(double x, double y){
     if(y==0){
         cout << "Divided by zero!\n";
         exit(0);
     }
     return x / y;
 }

 double calculate(double x, double y, pf p){
     return p(x,y);
 }

void cal_10(){
     double x,y;
     int choice;
     pf operations[3];
     operations[0] = &add;
     operations[1] = &multiply;
     operations[2] = &divide;

     cout << "choose an operation:\n";
     cout << "(0)add\t(1)multiply\t(2)divide\n";
     cin >> choice;
     while (cin){
         cin >> x >> y;
         cout << "result: " <<
            calculate(x, y ,operations[choice]) << endl;
         cout << "next: ";
         cin >> choice;
     }
};

