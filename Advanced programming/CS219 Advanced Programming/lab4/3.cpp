#include <stdio.h>
int main()
{
int aa[2][5] = { 1,2,3,4,5,
6,7,8,9,10 };
int* paa1 = (int*)(&aa + 1);  //移动10之后
int* paa2 = (int*)(*(aa + 1));  //a[2]
printf("%d,%d\n", *(paa1 - 1), *(paa2 - 1));
char* str[] = { "work","at","alibaba" };   //指针数组，指向三个词
char** ps = str;   //ps指向work 双层指针
ps++;   //at
printf("%s\n", *ps);
return 0;
}