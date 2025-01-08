#include<iostream>
using namespace std;
class node{
public:
    int coe;
    int exp;
    node *next;
    node(int coe,int exp){
        this->coe=coe;
        this->exp=exp;
    }
};
int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        node jiahead = node(0,-1);
        node cur=jiahead;
        for(int i=0;i<n;i++){
            int a,b;
            cin>>a>>b;
            node temp= node(a,b);
            cur.next=&temp;
            cur=cur.next;
        }
        node jiatail=new node(0,2000000000);
        cur.next=jiatail;
        int m;
        cin>>m;
        for(int j=0;j<m;j++){
            int coe,exp;
            cin>>coe>>exp;
            while(cur.next->exp<=exp){
                cur=cur.next;
            }
            if(cur->exp==exp){
                  cur.coe+=coe//合并同类项
            }else{
                node temp=node(coe,exp);
                temp.next=cur.next;
                cur.next=temp;
            }
        }
        int qq;
        cin>>qq;
        cur=jiahead.next;
        for(int j=0;j<qq;j++){
            int x;
            cin>>x;
            while(cur.next->exp<=x){
                cur=cur.next;
            }if(cur.exp==x){
                cout<<cur.coe<<" ";
            }else{
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
    return 0;
}