#include <iostream>
#include <climits>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    char map[26];
    for (int i = 0; i < 26; i++) {
        cin >> map[i];  
    }

    // 输入字符串 S
    string input;
    cin >> input;
    int n = input.length();

    string m_input;
    for (int i = 0; i < n; i++) {
        char c = map[input[i] - 'a'];
        m_input += c;
    }
    string combined = input + m_input;

    // KMP算法中的 next 数组，用于查找最大前后缀匹配
    int next[combined.length() + 1] = {0};
    int i = 1, j = 0;

    // 计算 next 数组
    while (i < combined.length()) {
        if (combined[i] == combined[j]) {
            if(j<n-1){
                j++;
                next[i] = j;
                i++;
            }else{
                next[i]=j;
                i++;
                j=0;
            }
            
        } else if (j != 0) {
            j = next[j - 1];
        } else {
            next[i] = 0;
            i++;
        }
    }
    // cout<<combined<<endl;
    // for(int i=0;i<combined.length();i++){
    //     cout<<next[i]<<" ";
    // }
    int ans=n - next[combined.length()-1];
    if(ans<(n+1)/2){
        cout<<(n+1)/2;
    }else{
        cout << ans << endl;
    }
    

    return 0;
}
