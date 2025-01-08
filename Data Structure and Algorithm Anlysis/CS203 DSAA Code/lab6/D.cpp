#include <iostream>
using namespace std;

int min(int stick[], int &size) {
    int a = 0;

    int min1 = stick[0];
    int min1_index = 0;
    for (int i = 1; i < size; i++) {
        if (stick[i] < min1) {
            min1 = stick[i];
            min1_index = i;
        }
    }
    a += min1;
    stick[min1_index] = stick[size - 1];
    size--;

    int min2 = stick[0];
    int min2_index = 0;
    for (int i = 1; i < size; i++) {
        if (stick[i] < min2) {
            min2 = stick[i];
            min2_index = i;
        }
    }
    a += min2;
    stick[min2_index] = stick[size - 1];
    size--;

    int new_stick = min1 + min2;
    stick[size] = new_stick;
    size++;

    return a;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int ans = 0;
        int n;
        cin >> n;
        
        int stick[n];
        for (int i = 0; i < n; i++) {
            cin >> stick[i];
        }
        
        while (n > 1) {
            ans += min(stick, n);
        }
        
        cout << ans << endl;
    }
    
    return 0;
}
