#include <iostream>
#include <string>
using namespace std;

const int MAX_LEN = 1005;
const int sigama = 26;  // 字母表大小
void trans_func(string P,int m,int trans[][sigama]){
    int X = 0;

    for (int a = 0; a < sigama; ++a) {
        if (P[0] - 'a' == a)
            trans[0][a] = 1;
    }

    // 构造 δ(j,a)
    for (int j = 1; j < m; ++j) {
        for (int a = 0; a < sigama; ++a) {
            if (P[j] - 'a' == a)
                trans[j][a] = j + 1;
            else
                trans[j][a] = trans[X][a];
        }
        X = trans[X][P[j] - 'a'];
    }
}
int main() {

    string in;
    cin>>in;
    string P;
    cin >> P;
    
    int m = P.length();
    int trans[MAX_LEN][sigama] = {0};
    int ans=0;
    trans_func(P,m,trans);
    int x=0;
    for(int i=0;i<in.length();i++){
        x=trans[x][in[i]-'a'];
        if (x == m) {  // 达到模式串长度，表示匹配成功
            ans++;
            // 使用转移表中记录的状态来回退
             x = 0;  // 重置 x 为 0，继续寻找下一个匹配;  
        }
    }

    cout<<ans<<endl;

    return 0;
}
