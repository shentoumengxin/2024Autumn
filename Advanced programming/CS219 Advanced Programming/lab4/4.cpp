#include<iostream>
using namespace std;
int main(){
    int * pArray=new int [5];
    int *t;
    for(int i=0;i<=4;i++){
        pArray[i]=i;
    }
    for(t = pArray + 4; t >= pArray; t--) {
        cout << *t << endl;
    }
    delete []pArray;
    return 0;
}