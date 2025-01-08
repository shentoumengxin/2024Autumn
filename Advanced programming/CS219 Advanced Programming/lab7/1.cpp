#include<iostream>
#include<cstring>
using namespace std;
struct stringy{
    char * str;
    int ct;
};
void set(stringy &beany,char * testing){
    int len=strlen(testing);
    beany.ct=len;
    char *st=new char[len+1];
    st=testing;
    beany.str=st;

};

void show(stringy &b,int c=1){
    while(c--){
        cout<<b.str;
        cout<<endl;
    }
    
};
void show(const char* testing,int a=1){
    while(a--){
        for (int i = 0; testing[i] != '\0'; i++) {
        std::cout << testing[i];
        };
         cout<<endl;
    }
   
};
int main(){
    stringy beany;
    char testing[]="Reality isn't what it used to be.";
    set(beany,testing);
    show(beany);
    show(beany,2);
    testing[0]='D';
    testing[1]='u';
    show(testing);
    show(testing,3);
    show("Done!");
    return 0;
}