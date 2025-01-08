#include <iostream>
#include <cstring>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string pattern;
    string str;
    cin >> str;
    cin >> pattern;

    int n = pattern.length();
    int m = str.length();
    int *next = new int[n];
    next[0] = 0;  // 初始化 next 数组的第一个元素
    
    int i = 1, j = 0;  // i 为当前指针，j 为前缀指针
    while (i < n) {   // 计算前缀数组 next
        if (pattern[i] == pattern[j]) {
            j++;
            next[i] = j;
            i++;
        } else if (j != 0) {
            j = next[j - 1];  //在这个j的前一位置前缀和后缀是相同的，因此我们回退多少呢？就是前缀的前后缀相等的位置即[next]
        } else {     //如果为0，则说明到头了，前缀为0，开始找下一个字母
            next[i] = 0;
            i++;
        }
    }

    i = 0;  // 用作 pattern 指针
    j = 0;  // 用作 str 指针
    int ans = 0;

    while (j < m) {  // 使用 KMP 算法查找模式出现次数
        if (pattern[i] == str[j]) {
            i++;
            j++;
            if (i == n) {  // 完整匹配
                ans++;
                i = next[i - 1];  // 重置 i 为上一个匹配位置
            }
        } else if (i != 0) {
            i = next[i - 1];
        } else {
            j++;
        }
    }

    cout << ans << endl;

    delete[] next;  // 释放动态数组内存
    return 0;

}
