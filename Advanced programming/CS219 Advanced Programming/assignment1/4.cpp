#include<cstring>
#include<iostream>
using namespace std;
int main(){
    int n;
    string in;
    string opr;
    int cnt_opr=0;
    int a[102][102]={-1};
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    while(cin>>opr){

    if (opr=="left") {
        for (int i = 1; i <= n; i++) {
            int cnt = 0;
            int tmp[102]={-1};
            int tmp2[102]={-1};
            for (int j = 1; j <= n; j++) {
                if (a[i][j] != 0) {
                    tmp[++cnt] = a[i][j];
                }
            }
        // 移动
        int cnt2 = 0;
        for (int j = 1; j <= cnt; j++) {
            if (tmp[j] == tmp[j + 1] && tmp[j] != 2048) {
                tmp2[++cnt2] = tmp[j] * 2; // 合并同类项
                j++; // 跳过被合并的块
            } else {
                tmp2[++cnt2] = tmp[j];
            }
        }
       
        for (int j = 1; j <= cnt2; j++) {
            a[i][j] = tmp2[j];
        }
        for (int j = cnt2 + 1; j <= n; j++) {
            a[i][j] = 0; // 剩余的部分填充0
        }
    }
} else if (opr=="right") {
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        int tmp[102]={-1};
        int tmp2[102]={-1};
        for (int j = n; j >= 1; j--) {
            if (a[i][j] != 0) {
                tmp[++cnt] = a[i][j];
            }
        }
        // 移动
        int cnt2 = 0;
        for (int j = 1; j <= cnt; j++) {
            if (tmp[j] == tmp[j + 1] && tmp[j] != 2048) {
                tmp2[++cnt2] = tmp[j] * 2;
                j++;
            } else {
                tmp2[++cnt2] = tmp[j];
            }
        }
        
        for (int j = 1; j <= cnt2; j++) {
            a[i][n - j + 1] = tmp2[j];
        }
        for (int j = cnt2 + 1; j <= n; j++) {
            a[i][n - j + 1] = 0;
        }
    }
} else if (opr=="up") {
    for (int j = 1; j <= n; j++) {
        int cnt = 0;
        int tmp[102]={-1};
        int tmp2[102]={-1};
        for (int i = 1; i <= n; i++) {
            if (a[i][j] != 0) {
                tmp[++cnt] = a[i][j];
            }
        }
        // 移动
        int cnt2 = 0;
        for (int i = 1; i <= cnt; i++) {
            if (tmp[i] == tmp[i + 1] && tmp[i] != 2048) {
                tmp2[++cnt2] = tmp[i] * 2;
                i++;
            } else {
                tmp2[++cnt2] = tmp[i];
            }
        }
       
        for (int i = 1; i <= cnt2; i++) {
            a[i][j] = tmp2[i];
        }
        for (int i = cnt2 + 1; i <= n; i++) {
            a[i][j] = 0;
        }
    }
} else if (opr=="down") {
    for (int j = 1; j <= n; j++) {
        int cnt = 0;
       int tmp[102]={-1};
        int tmp2[102]={-1};
        for (int i = n; i >= 1; i--) {
            if (a[i][j] != 0) {
                tmp[++cnt] = a[i][j];
            }
        }
        // 移动
        int cnt2 = 0;
        for (int i = 1; i <= cnt; i++) {
            if (tmp[i] == tmp[i + 1] && tmp[i] != 2048) {
                tmp2[++cnt2] = tmp[i] * 2;
                i++;
            } else {
                tmp2[++cnt2] = tmp[i];
            }
        }
        
        // 将结果填回原数组
        for (int i = 1; i <= cnt2; i++) {
            a[n - i + 1][j] = tmp2[i];
        }
        for (int i = cnt2 + 1; i <= n; i++) {
            a[n - i + 1][j] = 0;
        }
    }
}
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<a[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}