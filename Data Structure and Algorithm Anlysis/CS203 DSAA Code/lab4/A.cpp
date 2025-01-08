#include<iostream>
using namespace std;
int main(){
    int T;
    cin>>T;
    while (T--)
    {
        int n;
        cin>>n;
        char a;
        int top=0;
        bool flag=true;
        char stack[30005]={' '};
        string input;
        getline(cin,input);
        getline(cin,input);
        for (int i = 0; i < n; i++) {
            switch (input[i]) {
                case '(':
                    top++;
                    stack[top] = '(';
                    break;
                case '[':
                    top++;
                    stack[top] = '[';
                    break;
                case '{':
                    top++;
                    stack[top] = '{';
                    break;
                case ')':
                    if (stack[top] == '(') {
                        top--;  // pop
                    }else{
                        flag=false;
                    }
                    break;
                case ']':
                    if (stack[top] == '[') {
                        top--;  // pop
                    }else{
                        flag=false;
                    }
                    break;
                case '}':
                    if (stack[top] == '{') {
                        top--;  // pop
                    }else{
                        flag=false;
                    }
                    break;
                default:
                    break;
            }
    }

        if(top==0&&flag){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
        
        
    }
    
}