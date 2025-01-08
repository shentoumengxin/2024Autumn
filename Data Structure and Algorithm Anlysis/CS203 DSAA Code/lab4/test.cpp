#include <iostream>
using namespace std;

class deque {
private:
    int size;
    int left;
    int right;
    long long *value;
    int *index;
public:
    deque(int t) {
        size = t + 1;
        left = 0;
        right = 0;
        value = new long long[size];
        index = new int[size];
    }

    bool is_full() {
        return (right + 1) % size == left;
    }

    bool is_empty() {
        return right == left;
    }

    bool push_right(long long t, int in) {
        if (is_full()) return false;
        value[right] = t;
        index[right] = in;
        right = (right + 1) % size;
        return true;
    }

    long long get_left() {
        if (is_empty()) return -1;
        return value[left];
    }

    long long get_right() {
        if (is_empty()) return -1;
        return value[(right - 1 + size) % size];
    }

    bool delete_left() {
        if (is_empty()) return false;
        left = (left + 1) % size;
        return true;
    }

    int get_leftindex() {
        if (is_empty()) return -1;
        return index[left];
    }
};

template<typename T>
T Max(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    long long k;
    int n;
    long long *a = new long long[3000000 + 5];
    long long max_ans = 0;
    cin >> k >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    deque *maxDeque = new deque(n);
    deque *minDeque = new deque(n);
    int r = 0; // 右指针
    int l = 0; // 左指针
    long long ans = 0;

    while (r < n) {
        // 处理右指针元素
        while (!maxDeque->is_empty() && maxDeque->get_right() < a[r]) {
            maxDeque->delete_right(); // 维护最大值单调队列
        }
        maxDeque->push_right(a[r], r);

        while (!minDeque->is_empty() && minDeque->get_right() > a[r]) {
            minDeque->delete_right(); // 维护最小值单调队列
        }
        minDeque->push_right(a[r], r);

        // 确保当前窗口有效
        while (maxDeque->get_left() - minDeque->get_left() > k) {
            l++;
            // 如果左指针超过右指针，直接跳出
            if (l > r) {
                break;
            }
            // 更新队列，移除左指针的元素
            if (!maxDeque->is_empty() && maxDeque->get_leftindex() == l - 1) {
                maxDeque->delete_left();
            }
            if (!minDeque->is_empty() && minDeque->get_leftindex() == l - 1) {
                minDeque->delete_left();
            }
        }

        // 更新最大长度
        max_ans = Max(max_ans, r - l + 1);
        r++; // 移动右指针
    }

    cout << max_ans << endl;
    return 0;
}
