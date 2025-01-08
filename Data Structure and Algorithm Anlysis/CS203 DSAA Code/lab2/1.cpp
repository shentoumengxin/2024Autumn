#include<iostream>
using namespace std;
int main(){
    int T;
    int a[105]={-1};
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n-1;i++){  //bubble sort
            for(int j=1;j<=n-i;j++){
                if(a[j]>a[j+1]){
                    int temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                }
            }
        }
        
        int ans=a[n-2];
        if(a[n-1]==ans||a[n-3]==ans){
            cout<<"wa"<<endl;
        }else{
            cout<<ans<<endl;
        }
    }
    return 0;
}