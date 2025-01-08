#include <iostream>
#include <cstdio>
using namespace std;

typedef struct {
    int red;
    int blue;
} strings;

// 对 left_strings 按 blue 升序排序
void sort_left(strings a[], int size) {
    const int MAX_VALUE = 10000;
    int count[MAX_VALUE + 1] = {0};
    for(int i = 0; i < size; i++) {
        count[a[i].blue]++;
    }
    for(int i = 1; i <= MAX_VALUE; i++) {
        count[i] += count[i - 1];
    }
    strings temp[100005];
    for(int i = size - 1; i >= 0; i--) {
        int pos = count[a[i].blue] - 1;
        temp[pos] = a[i];
        count[a[i].blue]--;
    }
    for(int i = 0; i < size; i++) {
        a[i] = temp[i];
    }
}

// 对 right_strings 按 red 降序排序
void sort_right(strings a[], int size) {
    const int MAX_VALUE = 10000;
    int count[MAX_VALUE + 1] = {0};
    for(int i = 0; i < size; i++) {
        count[a[i].red]++;
    }
    for(int i = MAX_VALUE - 1; i >= 0; i--) {
        count[i] += count[i + 1];
    }
    strings temp[100005];
    for(int i = 0; i < size; i++) {
        int pos = count[a[i].red] - 1;
        temp[pos] = a[i];
        count[a[i].red]--;
    }
    for(int i = 0; i < size; i++) {
        a[i] = temp[i];
    }
}

int magic_cancel(strings* left_strings, int left_size, strings* right_strings, int right_size){
    int total_magic = 0;
    int remaining_red = 0;
    int remaining_blue = 0;

    for(int i = 0; i < left_size; i++){
        strings current = left_strings[i];

        if(i == 0){
            // 第一个串，直接更新剩余珠子数量
            remaining_red += current.red;
            remaining_blue += current.blue;
        } else {
            // 计算可消除的珠子数量
            int cancel_magic = min(remaining_red, current.blue);
            total_magic += cancel_magic;

            // 更新剩余珠子数量
            remaining_red = remaining_red - cancel_magic + current.red;
            remaining_blue = remaining_blue - cancel_magic + current.blue;
        }
    }

    for(int i = 0; i < right_size; i++){
        strings current = right_strings[i];

        if(i == 0 && left_size == 0){
            // 如果没有 left_strings，且是第一个 right_strings
            remaining_red += current.red;
            remaining_blue += current.blue;
            continue;
        }

        
        int cancel_magic = min(remaining_red, current.blue);
        total_magic += cancel_magic;

        remaining_red = remaining_red - cancel_magic + current.red;
        remaining_blue = remaining_blue - cancel_magic + current.blue;
    }

    return total_magic;
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int n;
        scanf("%d", &n);
        strings left_strings[100005];
        strings right_strings[100005];
        int left_size = 0;
        int right_size = 0;
        for(int i = 0; i < n; i++){
            int blue, red;
            scanf("%d %d", &blue, &red);
            if(blue <= red){
                left_strings[left_size].blue = blue;
                left_strings[left_size].red = red;
                left_size++;
            } else {
                right_strings[right_size].blue = blue;
                right_strings[right_size].red = red;
                right_size++;
            }
        }

        if(left_size > 0){
            sort_left(left_strings, left_size);
        }
        if(right_size > 0){
            sort_right(right_strings, right_size);
        }

        int total_magic = magic_cancel(left_strings, left_size, right_strings, right_size);
        printf("%d\n", total_magic);
    }
    return 0;
}
