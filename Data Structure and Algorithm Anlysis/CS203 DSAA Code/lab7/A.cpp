#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N + 1); 
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    bool isMaxHeap = true, isMinHeap = true;

    for (int i = 1; i <= N / 2; i++) { 
        int left = 2 * i, right = 2 * i + 1;

        if (left <= N && A[i] < A[left]) isMaxHeap = false;
        if (right <= N && A[i] < A[right]) isMaxHeap = false;

        if (left <= N && A[i] > A[left]) isMinHeap = false;
        if (right <= N && A[i] > A[right]) isMinHeap = false;
    }

    if (isMaxHeap) {
        cout << "Max" << endl;
    } else if (isMinHeap) {
        cout << "Min" << endl;
    } else {
        cout << "Neither" << endl;
    }

    return 0;
}
