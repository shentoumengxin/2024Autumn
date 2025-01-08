#include<iostream>
using namespace std;
int main(){
    string input;
    int count=0;
    getline(cin,input);
    for(int i=0;i<input.size();i++){
        input[i]=tolower(input[i]);
        if (input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u') {
            count++;
        }
    }
    cout<<count<<endl;
    int p=0;
    count=0;
    while(p<input.size()){
        if (input[p] == 'a' || input[p] == 'e' || input[p] == 'i' || input[p] == 'o' || input[p] == 'u') {
            count++;
        }
        p++;
    }
    cout<<count<<endl;
    return 0;
}