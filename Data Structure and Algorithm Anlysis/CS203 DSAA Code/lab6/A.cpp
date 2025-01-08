#include<iostream>
using namespace std;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    int T;

    cin>>T;
    while(T--){
        long long N,K,k;
        cin>>N>>K;
        k=K;
        if(N>0){
            N=N-1;
        }else{
            cout<<0<<endl;
        }
        while(N>=K){
            N=N-K;
            K=K*K;
        }
            long long up_leaf=(K-N)/(K/k);
            cout<<up_leaf+N<<endl;
        

    }
    return 0;
}