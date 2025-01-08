#include<iostream>
using namespace std;
 struct CandyBar 
{
    char name[20];
    float weight;
    int calories;
 };
int main(){
    CandyBar cdb[4];
    int T=3;
    while(T--){
        cout<<"Enter brand name of a Candybar:";
        cin.getline(cdb[T].name,20);
        cout<<"Enter the weight of the Candybar:";
        cin>>cdb[T].weight;
        cin.get();
        cout<<"Enter calories(Integer) in the Candybar:";
        cin>>cdb[T].calories;
        cin.get();
        
    }
    T=3;
    float max=0;
    int max_t=0;
     cout<<"Here is the output"<<endl;
    while(T--){
       
        cout<<"Brand name:"<<cdb[T].name<<endl;
        cout<<"Weight:"<<cdb[T].weight<<endl;
        cout<<"Calories:"<<cdb[T].calories<<endl;
        float p=cdb[T].calories/float(cdb[T].weight);
        if(p>max){
            max=p;
            max_t=T;
        }
    }
    cout<<"The greates calories per weight is:"<<endl;
    cout<<"Brand name:"<<cdb[max_t].name<<endl;
    cout<<"calories per weight"<<max<<endl;
    return 0;
}