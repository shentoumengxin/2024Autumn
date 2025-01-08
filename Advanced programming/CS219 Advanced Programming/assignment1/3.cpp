#include<iostream>
using namespace std;
int main(){
    string in;
    int  token=0;
    getline(cin,in);
    if((in.length())>=8)token++;
    //2
    bool hasL=false;
    bool hasu=false;
    bool hasD=false;
    bool hasS=false;
    bool con=false;
    string specialChars = "!@#$%^&*()-+";
    for (char c : in) {
        if (isupper(c)) {
            hasu = true;
            
        }
        if (isdigit(c)) {
            hasD = true;
            
        }
        if (islower(c)) {
            hasL = true;
           
        }
        if(specialChars.find(c)!=string::npos){
            hasS=true;
           
        }
        
    }

    for(int i=0;i<in.length();i++){
        if(in[i]==in[i+1]){
            con=true;
            break;
        }
        
    }
    if(hasL)token++;
    if(hasu)token++;
    if(hasD)token++;
    if(hasS)token++;
    if(!con)token++;
    if(token==6)cout<<"Jett"<<endl;
    if(token==5)cout<<"Raze"<<endl;
    if(token==4)cout<<"Neon"<<endl;
    if(token<4)cout<<"No"<<endl;
    return 0;
}
