#include<iostream>
using namespace std;
int main(){
    int T;
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        int matrix[n+1][n+1]={0};
        for(int i=1;i<=m;i++){
            int x,y;
            cin>>x>>y;
            matrix[x][y]=1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(matrix[i][j]==1)
                cout<<matrix[i][j]<<' ';
                else cout<<0<<' ';
            }
            cout<<endl;
        }
    }
    return 0;
}