#include<iostream>
#include<cstring>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string input;
    cin>>input;
    int n=input.length();
    int *next=new int[n+5];
    int i=1;
    int j=0;
    while(i<n){
        if(input[i]==input[j]){
            next[i]=j+1;
            i++;
            j++;
        }else if(j!=0){
            j=next[j-1];
        }else{
            next[i]=0;
            i++;
        }
    }
    for(int i=0;i<n;i++){
        cout<<next[i]<<endl;
    }
}