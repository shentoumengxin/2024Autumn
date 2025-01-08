#include<iostream>
#include<fstream>
using namespace std;
int main(){
    string input;
    getline(cin,input);
    ofstream outf1,outf2;
    outf1.open("f1.txt");
    outf2.open("f2.txt");
    if(outf1.is_open()){
        outf1<<input;
        outf1.close();
    }else{
        cout<<"fail"<<endl;
    }
    for(char &c: input){
        c=toupper(c);
    }
    if(outf2.is_open()){
        outf2<<input;
        outf2.close();
    }else{
        cout<<"fail"<<endl;
    }
    ifstream inf1("f1.txt");
    ifstream inf2("f2.txt");
    if (inf1.is_open()) {
        std::string line;
        while (std::getline(inf1, line)) {
            std::cout << line << std::endl;
        }

        inf1.close();
    } else {
        cout << "Unable to open the file." << endl;
    }
    if (inf2.is_open()) {
        string line;
        while (getline(inf2, line)) {
            cout << line << endl;
        }
        inf2.close();
    } else {
        cout << "Unable to open the file." << endl;
    }



    return 0;
}