#include <iostream>
#include <vector>
using namespace std;

// 定义一个结构体来存储 a 和 b 的对应值
struct Pair {
    int a;
    int b;
};

// 归并函数，按 b 的值排序，同时保持 a 和 b 的对应关系
void merge(Pair arr[], int left, int mid, int right){
    int n1 = mid - left + 1; // 左半部分的大小
    int n2 = right - mid;    // 右半部分的大小

    // 创建临时数组
    Pair* leftArr = new Pair[n1];
    Pair* rightArr = new Pair[n2];

    // 拷贝数据到临时数组
    for(int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for(int i = 0; i < n2; i++)
        rightArr[i] = arr[mid + 1 + i];

    // 合并临时数组回原数组
    int i = 0; // 左临时数组的索引
    int j = 0; // 右临时数组的索引
    int k = left; // 原数组的索引

    while(i < n1 && j < n2){
        if(leftArr[i].b <= rightArr[j].b){
            arr[k++] = leftArr[i++];
        }
        else{
            arr[k++] = rightArr[j++];
        }
    }

    // 拷贝剩余元素
    while(i < n1){
        arr[k++] = leftArr[i++];
    }
    while(j < n2){
        arr[k++] = rightArr[j++];
    }

    // 释放临时数组的内存
    delete[] leftArr;
    delete[] rightArr;
}

// 归并排序函数
void merge_sort(Pair arr[], int left, int right){
    if(left < right){
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// 堆化上调函数
void heapify_up(vector<int> &heap, int index){
    while(index > 0){
        int parent = (index - 1) / 2;
        if(heap[index] < heap[parent]){
            swap(heap[index], heap[parent]);
            index = parent;
        }
        else{
            break;
        }
    }
}

// 堆化下调函数
void heapify_down(vector<int> &heap, int index){
    int size = heap.size();
    while(true){
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if(left < size && heap[left] < heap[smallest]){
            smallest = left;
        }
        if(right < size && heap[right] < heap[smallest]){
            smallest = right;
        }
        if(smallest != index){
            swap(heap[index], heap[smallest]);
            index = smallest;
        }
        else{
            break;
        }
    }
}

// 插入到小顶堆
void insert_heap(vector<int> &heap, int val){
    heap.push_back(val);
    heapify_up(heap, heap.size() - 1);
}

// 替换堆顶元素并堆化
void replace_heap_top(vector<int> &heap, int val){
    if(heap.empty()){
        return;
    }
    heap[0] = val;
    heapify_down(heap, 0);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--){
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

        // 对 arr 按 b 的值进行归并排序
        merge_sort(arr, 0, n - 1);
        
        // 找到最大的截止时间
        int t_max = arr[n-1].b;

        // 初始化小顶堆
        vector<int> heap;  // 存储已选择球员的能力值

        for(int i = 0; i < n; i++){
            int deadline = arr[i].b;
            int power = arr[i].a;
            
            if(heap.size() < (size_t)deadline){
                // 如果堆的大小小于截止时间，可以直接加入
                insert_heap(heap, power);
            }
            else{
                // 堆已满，检查当前球员的能力值是否大于堆顶
                if(power > heap[0]){
                    // 替换堆顶为当前球员的能力值
                    replace_heap_top(heap, power);
                }
                // 否则，跳过当前球员
            }
        }

        // 计算堆中所有球员的能力值总和
        for(auto power : heap){
            ans += power;
        }

        cout << ans << "\n";

        // 释放 arr 的内存
        delete[] arr;
    }
    return 0;
}
