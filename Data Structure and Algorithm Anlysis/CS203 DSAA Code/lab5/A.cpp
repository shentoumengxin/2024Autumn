#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n; // 使用cin来读取n
    while (n--) {
        string s;
        cin >> s; // 使用cin来读取字符串s
        int len = s.length();
        long long ans = (len * (len + 1)) / 2; // 使用求和公式
        cout << ans << endl; // 使用cout来输出答案
    }
    return 0;
}
