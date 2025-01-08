#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std;

// 定义节点结构
class node {
public:
    node *next;
    node *prev;
    int value;
    node() : value(0), next(nullptr), prev(nullptr) {} // 默认构造函数
    node(int value) : value(value), next(nullptr), prev(nullptr) {}
};

// 交换指针
inline void swap_nodes(node* &a, node* &b){
    node* temp = a;
    a = b;
    b = temp;
}

// 归并排序辅助函数：合并两个子数组
void merge(node* a[], node* temp[], int left, int mid, int right){
    int i = left;     // 左子数组起始
    int j = mid + 1;  // 右子数组起始
    int k = left;     // 临时数组起始

    while (i <= mid && j <= right) {
        if (a[i]->value <= a[j]->value) {
            temp[k++] = a[i++];
        }
        else {
            temp[k++] = a[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = a[i++];
    }

    while (j <= right) {
        temp[k++] = a[j++];
    }

    // 将合并后的内容复制回原数组
    for (int l = left; l <= right; l++) {
        a[l] = temp[l];
    }
}

// 归并排序主函数
void merge_sort(node* a[], node* temp[], int left, int right){
    if (left >= right) return; // 递归终止条件

    int mid = left + (right - left) / 2;
    merge_sort(a, temp, left, mid);
    merge_sort(a, temp, mid + 1, right);
    merge(a, temp, left, mid, right);
}

int main(){
    int n;
    srand(time(0));
    scanf("%d", &n);

    // 动态分配节点数组，预分配足够的内存
    node **unsort_node = new node*[n];
    for(int i = 0; i < n; i++){
        int tmp;
        scanf("%d", &tmp);
        unsort_node[i] = new node(tmp);
    }

    // 复制指针到排序数组
    node **sort_node = new node*[n];
    for(int i = 0; i < n; i++){
        sort_node[i] = unsort_node[i];
    }

    // 分配辅助数组用于归并排序
    node **temp = new node*[n];

    // 归并排序
    merge_sort(sort_node, temp, 0, n-1);

    // 释放辅助数组内存
    delete [] temp;

    // 建立排序后的双向链表
    for(int i = 0; i < n; i++){
        if(i > 0){
            sort_node[i]->prev = sort_node[i-1];
        }
        else{
            sort_node[i]->prev = nullptr;
        }

        if(i < n-1){
            sort_node[i]->next = sort_node[i+1];
        }
        else{
            sort_node[i]->next = nullptr;
        }
    }

    // 处理每个节点，找到最小差值
    // 注意：原代码中循环到 n-1，这里假设需要处理前 n-1 个节点
    for(int i = 0; i < n-1; i++){
        int t1 = 0, t2 = 0;
        node* current = unsort_node[i];
        
        if(current->prev == nullptr && current->next != nullptr){
            t2 = abs(current->value - current->next->value);
            current->next->prev = nullptr;
            printf("%d ", t2);
            continue;
        }
        if(current->next == nullptr && current->prev != nullptr){
            t1 = abs(current->value - current->prev->value);
            current->prev->next = nullptr;
            printf("%d ", t1);
            continue;
        }
        if(current->prev != nullptr && current->next != nullptr){
            t1 = abs(current->value - current->prev->value);
            t2 = abs(current->value - current->next->value);
            if(t1 > t2){
                printf("%d ", t2);
            }
            else{
                printf("%d ", t1);
            } // 找到最小的
            // 删除当前节点
            current->prev->next = current->next;
            current->next->prev = current->prev;
        }
    }
    printf("\n");

    // 释放内存
    for(int i = 0; i < n; i++){
        delete unsort_node[i];
    }
    delete [] sort_node;
    delete [] unsort_node;
    return 0;
}
