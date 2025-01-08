#include <iostream>
#include <string>

using namespace std;

const int MOD = 514329;
const int MAX_SIZE = 100000 + 5; 
int main() {
    string s;
    cin >> s;
    int stack[MAX_SIZE]; 
    int top = -1;        
    for (char c : s) {
        if (c == '(') {
            stack[++top] = -1; 
        } else { 
            int sum = 0;
            while (top >= 0 && stack[top] != -1) {
                sum = (sum + stack[top]) % MOD;   //同一级，累加    
                top--;
            }
            if (top >= 0 && stack[top] == -1) {
                top--; // 弹出匹配的 '(' 标记
            }
            int score = (sum == 0) ? 1 : (2 * sum) % MOD;   //()则产生一个1，(A)则产生2A
            stack[++top] = score; // 将计算得到的得分压入栈
        }
    }

    int ans = 0;
    while (top >= 0) {
        ans = (ans + stack[top]) % MOD;
        top--;
    }

    cout << ans << endl;
    return 0;
}
