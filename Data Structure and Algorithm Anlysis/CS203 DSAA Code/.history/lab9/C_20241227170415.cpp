#include <iostream>
#include <vector>
using namespace std;

// 定义边结构体
struct Edge {
    int to;          // 目标节点
    long long weight; // 边的权重（Cij * Cxy）
};

// 定义堆节点结构体
struct HeapNode {
    long long weight; // 边的权重
    int node;          // 目标节点
};

// 自定义最大堆类
class MaxHeap {
public:
    vector<HeapNode> heap;

    // 插入新的节点到堆中，并上浮以保持堆性质
    void push(long long weight, int node) {
        HeapNode hn;
        hn.weight = weight;
        hn.node = node;
        heap.push_back(hn);
        heap_up(heap.size() - 1);
    }

    // 弹出堆顶（最大）节点
    HeapNode pop_max() {
        HeapNode max_node = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) {
            heap_down(0);
        }
        return max_node;
    }

    // 检查堆是否为空
    bool empty() const {
        return heap.empty();
    }

private:
    // 堆上浮操作，从 index 开始
    void heap_up(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index].weight > heap[parent].weight) {
                // 交换
                HeapNode temp = heap[index];
                heap[index] = heap[parent];
                heap[parent] = temp;
                index = parent;
            }
            else {
                break;
            }
        }
    }

    // 堆下沉操作，从 index 开始
    void heap_down(int index) {
        int size = heap.size();
        while (true) {
            int largest = index;
            int left = 2 * index + 1;
            int right = 2 * index + 2;

            if (left < size && heap[left].weight > heap[largest].weight) {
                largest = left;
            }
            if (right < size && heap[right].weight > heap[largest].weight) {
                largest = right;
            }
            if (largest != index) {
                // 交换
                HeapNode temp = heap[index];
                heap[index] = heap[largest];
                heap[largest] = temp;
                index = largest;
            }
            else {
                break;
            }
        }
    }
};

// 主函数
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    // 读取网格的点系数
    vector<vector<long long>> grid(n, vector<long long>(m, 0));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> grid[i][j];
        }
    }

    // 将2D网格映射到1D编号
    auto node = [&](int i, int j) -> int {
        return i * m + j; // 0-based indexing
    };

    // 构建邻接表
    vector<vector<Edge>> adj(n * m, vector<Edge>());
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            // 右邻居
            if(j + 1 < m){
                Edge e;
                e.to = node(i, j + 1);
                e.weight = grid[i][j] * grid[i][j + 1];
                adj[node(i, j)].push_back(e);
            }
            // 下邻居
            if(i + 1 < n){
                Edge e;
                e.to = node(i + 1, j);
                e.weight = grid[i][j] * grid[i + 1][j];
                adj[node(i, j)].push_back(e);
            }
            // 左邻居
            if(j - 1 >= 0){
                Edge e;
                e.to = node(i, j - 1);
                e.weight = grid[i][j] * grid[i][j - 1];
                adj[node(i, j)].push_back(e);
            }
            // 上邻居
            if(i - 1 >= 0){
                Edge e;
                e.to = node(i - 1, j);
                e.weight = grid[i][j] * grid[i - 1][j];
                adj[node(i, j)].push_back(e);
            }
        }
    }

    // 初始化 Prim 算法相关变量
    vector<bool> in_mst(n * m, false); // 标记节点是否已在 MST 中
    long long total_gain = 0; // MST 的边权和
    int count = 0; // MST 中的节点数

    // 初始化最大堆并将起始节点的所有边加入堆
    MaxHeap heap;
    // 选择起始节点为0（对应网格的 (0,0)）
    in_mst[0] = true;
    count++;
    for(auto &e : adj[0]){
        heap.push(e.weight, e.to);
    }

    // 主循环
    while(!heap.empty() && count < n * m){
        HeapNode current = heap.pop_max();
        int u = current.node;
        long long w = current.weight;

        if(in_mst[u]){
            continue; // 如果节点已在 MST 中，跳过
        }

        // 将节点加入 MST
        in_mst[u] = true;
        total_gain += w;
        count++;

        // 将新加入节点的所有边加入堆
        for(auto &e : adj[u]){
            if(!in_mst[e.to]){
                heap.push(e.weight, e.to);
            }
        }
    }

    // 输出 MST 的边权和
    cout << total_gain;

    return 0;
}
