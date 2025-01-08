#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
T maxn(T arr[], int n) {
    T max_val = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }
    return max_val;
}

template<>  
const char* maxn(const char* arr[], int n) {
    const char* longest_str = arr[0];
    int max_length = strlen(arr[0]);

    for (int i = 1; i < n; i++) {
        int len = strlen(arr[i]);
        if (len > max_length) {
            max_length = len;
            longest_str = arr[i];
        }
    }
    return longest_str;
}

int main() {
    int int_arr[] = {1, 2, 3, 4, 5};
    int int_arr_size = sizeof(int_arr) / sizeof(int_arr[0]);
    cout << "Max int is: " << maxn(int_arr, int_arr_size) << endl;

    double double_arr[] = {1.1, 2.7, -3.5, -2.0};
    int double_arr_size = sizeof(double_arr) / sizeof(double_arr[0]);
    cout << "Max double is: " << maxn(double_arr, double_arr_size) << endl;

    const char* str_arr[] = {"this", "no body", "morning", "birds", "sky"};
    int str_arr_size = sizeof(str_arr) / sizeof(str_arr[0]);
    cout << "Longest string is: " << maxn(str_arr, str_arr_size) << endl;

    return 0;
}
