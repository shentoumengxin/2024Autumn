#include<iostream>
#include<vector>
#include<cmath> // 用于计算层级
using namespace std;

// 定义节点类，添加 original_index 字段以跟踪原始索引
class node {
public:
    int level;          // 层级 x
    int index_in_level; // 层内索引 y
    int val;            // 节点值
    int original_index; // 原始索引

    node(int val, int original_index, int level = 0, int index_in_level = 0)
        : val(val), original_index(original_index), level(level), index_in_level(index_in_level) {}
};

// 修改 heap_up 函数的返回类型为 void
void heap_up(vector<node*> &heap, int index){
    while(index > 0){
        int parent = (index - 1) / 2;
        if(heap[parent]->val < heap[index]->val){
            // 交换指针
            swap(heap[parent], heap[index]);
            index = parent;
        }
        else{
            break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        int n;
        cin >> n;
        
        // 在每个测试用例中独立声明 nodes 向量
        vector<node*> nodes;
        nodes.reserve(n); // 预留空间，提高效率
        
        // 插入堆
        for (int i = 1; i <= n; i++) { // 原始索引从1开始
            int x;
            cin >> x;
            // 创建新节点，记录其原始索引
            node* new_node = new node(x, i);
            nodes.push_back(new_node); 
            heap_up(nodes, i-1); // heap_up 使用0-based索引
        }
        
        int p;
        cin >> p;
        
        // 查找具有原始索引 p 的节点在堆中的位置
        int heap_idx = -1;
        for(int i = 0; i < n; i++){
            if(nodes[i]->original_index == p){
                heap_idx = i;
                break;
            }
        }
        
        if(heap_idx == -1){
            // 如果未找到，输出错误信息
            cout << "Invalid index!\n";
            // 释放分配的内存
            for(auto node_ptr : nodes){
                delete node_ptr;
            }
            continue;
        }
        
        // 计算层级 (level) 和层内索引 (y)
        int level = 1;
        int nodes_in_previous_levels = 0;
        while(heap_idx >= nodes_in_previous_levels + (1 << (level - 1))){
            nodes_in_previous_levels += (1 << (level - 1));
            level++;
        }
        
        // 计算 y-index
        int start_index_of_level = nodes_in_previous_levels;
        int y = heap_idx - start_index_of_level + 1; // 1-based y-index
        
        cout << level << " " << y << "\n";
        
    }
    
    return 0;
}
