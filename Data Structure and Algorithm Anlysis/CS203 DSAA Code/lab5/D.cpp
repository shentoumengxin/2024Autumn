#include<iostream>
#include<cstring>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--){
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
        if(n%(n-next[n-1])==0&&next[n-1]!=0){
                cout<<"0"<<endl;
            }else{
                int a=n-next[n-1]-(n%(n-next[n-1]));
                cout<<a<<endl;
            }
            
            
        }
        
} 
