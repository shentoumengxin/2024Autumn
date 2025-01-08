#include <iostream>
using namespace std;
int main()
{
    int a[][4]={1,3,5,7,
    9,11,13,15,
    17,19}; 
    int *p=*(a+1); //a[1][0]
    p += 3;   //a[1][3]
    cout << "*p++ = " << *p++ << ",*p = " << *p << endl;
    const char *pc = "Welcome to programming.", 
    *r;
    long *q = (long *)pc;
    q++;  //q后移8byte
    r = (char *)q;  
    cout << r << endl;
    unsigned int m = 0x3E56AF67;   //m指向地址4byte
    unsigned short *pm = (unsigned short *) &m;  //指向m内存的内存，short 4byte 故取一半
    cout << "*pm = " << hex << *pm << endl;
return 0;
}