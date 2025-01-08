#include <iostream>
#include <vector>
using namespace std;
void merge(pair a[],int left,int mid,int right){
    int n1 = mid - left + 1; // 左半部分的大小
    int n2 = right - mid;    // 右半部分的大小
    Pair* left_a =new Pair(n1);
    Pair* right_a=new Pair(n2);
    for(int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for(int i = 0; i < n2; i++)
        rightArr[i] = arr[mid + 1 + i];
    
    int a=0;
    int b=0;
    int c=left;
    while(a<n1&&b<n2){
        if(left.)
    }
}
void merge_sort(Pair a[],int left,int right){
    mid=(left+right)>>1;
    merge_sort(a[],left,mid);
    merge_sort(a[],mid+1,right);
    merge(left,mid,right);
}
// 定义一个结构体来存储 a 和 b 的对应值
struct Pair {
    int a;
    int b;
};
int main(){
    int n;
        long long ans = 0;
        cin >> n;
        Pair* arr = new Pair[n];
        
        // 读取 a 数组
        for(int i = 0; i < n; i++){
            cin >> arr[i].a;
        }
        // 读取 b 数组
        for(int i = 0; i < n; i++){
            cin >> arr[i].b;
        }

}