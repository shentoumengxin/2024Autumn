#include <iostream>
#include <string>
using namespace std;

const int MAX_LEN = 100005;
const int sigama = 26;  // 字母表大小

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    string P;
    cin >> P;

    int m = P.length();
    int trans[MAX_LEN][sigama] = {0};
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

    // 输出状态转移表
    for (int j = 0; j < m; ++j) {
        for (int a = 0; a < sigama; ++a) {
            cout << trans[j][a] << ' ';
        }
        cout << endl;
    }

    return 0;
}
