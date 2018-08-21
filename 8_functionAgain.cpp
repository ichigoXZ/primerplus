/* 函数模板
 * 具体化：隐式实例化、显式具体化、显式实例化
 * decltype & auto */

#include "utils.h"

 template <typename T>
 T maxn(T a[], int size){
     T max=a[0];
     for (int i=1; i<size; i++){
         if(a[i] > max)
             max = a[i];
     }
     return max;
 }

 // 显式具体化
 template <>
 const char* maxn(const char** s, int size){
     const char * str = s[0];
     int max = strlen(s[0]),len;
     for (int i=0; i<size; i++){
         len = strlen(s[i]);
         if (len > max){
             str = s[i];
             max = len;
         }
     }
     return str;
 }

 void maxnTemplate(){
     int int_array[6] = { 43, 235, 54, 232, 123, 65 };
     double double_array[4] = { 32.1, 453.2, 53.3, 67.4 };
     const char * str_array[5] = { "Hello Jimmy!", "Hello World!", "ABCDEFG,HIJKLMN", "Today is a goood day!", "C++ Primer Plus!" };

     int int_max = maxn(int_array, 6);
     double double_max = maxn(double_array, 4);
     const char * length_max_str = maxn(str_array, 5);

     cout << "max of int array: " << int_max << endl;
     cout << "max of double array: " << double_max << endl;
     cout << "max length string of string array: " << length_max_str << endl;
 }
