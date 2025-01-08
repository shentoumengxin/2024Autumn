#include <iostream>

using namespace std;

const int MAX_N = 300000 + 5;
int A[MAX_N];      // 存储输入的卡片序列
int stack[MAX_N];  // 用数组模拟栈
int min(int a,int b){
    return a<b?a:b;
}
int main() {
    ios::sync_with_stdio(false); // 加速输入输出
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int top = -1;      
        int n;
        cin >> n;
        int *min_from_now=new int [n+5];  // 从当前位置到最后的最小值
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        min_from_now[n]=10000000;
        for (int i = n-1; i >= 0; i--) {
            min_from_now[i]=min(min_from_now[i+1],A[i]);
        }
        
        // 处理剩余的栈元素
        for(int i=0;i<n;i++){
            stack[++top]=A[i];
            while(top>=0&&stack[top]<=min_from_now[i+1]){
                cout << stack[top] << ' ';
                top--;
            }
            
        }
        for (int i = 0; i <= top; ++i) {
           
            cout  << stack[i]<<' ';
        }

        cout << '\n';
        delete [] min_from_now;
    }

    return 0;
}
