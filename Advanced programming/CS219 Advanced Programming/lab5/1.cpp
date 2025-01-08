#include<iostream>
using namespace std;
int main(){
    string input;
    int count=0;
    while(true){
        cin>>input;
        if(input=="done")break;
        count++;

    }
    cout<<count<<endl;
    return 0;
}