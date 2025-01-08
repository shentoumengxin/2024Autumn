#include<iostream>
using namespace std;
long long frac(int n,int k){
    long long ans=1;
    while(n>=k){
       ans*=n;
       n--;
    }
    return ans;
}
int main(){
    int N,K;
    cin>>N>>K;
    if(K>N/2+1){
        K=N-K;
    }
    long long up=frac(N,N-K+1);
    long long down=frac(K,1);
    cout<<up/down<<endl;
    return 0;
}