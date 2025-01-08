#include<iostream>
#include<ctime>
#include <cstdlib>
#include<vector>
using namespace std;
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
int partition(std::vector<int> &a, int left, int right) { 
    // 随机选择基准元素的索引
    int pivotIndex = left + rand() % (right - left + 1);
    // 将随机选择的基准值交换到最右边
    swap(a[pivotIndex], a[right]);
    int pivot = a[right];  // 基准值
    int i = left - 1;      // i指向小于基准值的最后一个元素的位置

    // 遍历数组，按大小将元素分成两部分
    for (int j = left; j < right; j++) {
        if (a[j] <= pivot) {  // 如果当前元素小于等于基准值
            i++;  // i前移
            swap(a[i], a[j]);  // 交换元素到左边
        }
    }
    // 将基准值放到它正确的位置上
    swap(a[i + 1], a[right]);
    return i + 1;  // 返回基准值的最终位置
}

void quick_sort(vector<int>&a,int left,int right){
    if (left < right) { // 递归终止条件
    int p=partition(a,left,right);
    quick_sort(a,left,p-1);
    quick_sort(a,p+1,right);
    }else {
        return;
    }
}

int main(){
    int n=0;
    cin>>n;
    vector<int> a(n);
    srand(time(0));
    for(int i=0;i<=n-1;i++){
        cin>>a[i];
    }
    quick_sort(a,0,n-1);
    for(int i=0;i<=n-1;i++){
        cout<<a[i]<<' ';
    }
}