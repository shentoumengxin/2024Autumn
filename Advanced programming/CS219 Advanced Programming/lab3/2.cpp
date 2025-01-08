#include <stdio.h>
 union data
 {
    int n;
    char ch;
    short m;
 };
 int main()
 {
    union data a;
    printf("%lu, %lu\n", sizeof(a), sizeof(union data) );  //long unsigh
    a.n = 0x40;
    printf("%X, %c, %hX\n", a.n, a.ch, a.m);   //16 c 16short 40->64->@
    a.ch = '9';
    printf("%X, %c, %hX\n", a.n, a.ch, a.m);  //57 ->39 
    a.m = 0x2059;
    printf("%X, %c, %hX\n", a.n, a.ch, a.m);   //
    a.n = 0x3E25AD54;
    printf("%X, %c, %hX\n", a.n, a.ch, a.m);  //hX溢出
    
    return 0;
 }
