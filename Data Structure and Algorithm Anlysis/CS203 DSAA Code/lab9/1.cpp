#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// 定义堆节点结构体
struct HeapNode {
    long long dist; // 当前节点到 MST 的最小边权
    int vertex;     // 节点编号
};

// 手动实现最小堆
class MinHeap {
public:
    vector<HeapNode> heap; // 堆数组，存储 (dist, vertex)

    // 插入新的节点到堆中，并上浮以保持堆性质
    void push(long long dist, int vertex) {
        HeapNode node;
        node.dist = dist;
        node.vertex = vertex;
        heap.push_back(node);
        heap_up(heap.size() - 1);
    }

    // 弹出堆顶（最小）节点
    HeapNode pop_min() {
        HeapNode min_node = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) {
            heap_down(0);
        }
        return min_node;
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
            if (heap[index].dist < heap[parent].dist) {
                // 交换当前节点和父节点
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
            int smallest = index;
            int left = 2 * index + 1;
            int right = 2 * index + 2;

            if (left < size && heap[left].dist < heap[smallest].dist) {
                smallest = left;
            }
            if (right < size && heap[right].dist < heap[smallest].dist) {
                smallest = right;
            }
            if (smallest != index) {
                // 交换当前节点和最小子节点
                HeapNode temp = heap[index];
                heap[index] = heap[smallest];
                heap[smallest] = temp;
                index = smallest;
            }
            else {
                break;
            }
        }
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    // 初始化邻接表，存储 (邻接节点, 权重)
    vector<vector<pair<int, long long>>> adj(n + 1, vector<pair<int, long long>>());

    long long total = 0; // 所有边的权重总和

    // 读取所有边并构建邻接表（无向图，双向添加）
    for(int i = 0; i < m; ++i){
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
        total += w;
    }

    // 初始化 Prim 算法相关变量
    vector<bool> in_mst(n + 1, false); // 标记节点是否已在 MST 中
    vector<long long> dist(n + 1, LLONG_MAX); // 存储每个节点到 MST 的最小边权
    dist[1] = 0; // 从节点 1 开始

    // 初始化最小堆并将起始节点加入堆
    MinHeap heap;
    heap.push(0, 1);

    long long mst_sum = 0; // 最小生成树的权重总和
    int count = 0; // MST 中的节点数

    while(!heap.empty() && count < n){
        HeapNode current = heap.pop_min();
        int u = current.vertex;
        long long current_dist = current.dist;

        if(in_mst[u]){
            continue; // 如果节点已在 MST 中，跳过
        }

        in_mst[u] = true; // 将节点加入 MST
        mst_sum += current_dist;
        count++;

        // 遍历节点 u 的所有邻接节点
        for(auto &edge : adj[u]){
            int v = edge.first;
            long long w = edge.second;

            if(!in_mst[v] && w < dist[v]){
                dist[v] = w;
                heap.push(w, v);
            }
        }
    }

    // 计算最大化删除边的收益
    long long gain = total - mst_sum;
    cout << gain << "\n";

    return 0;
}
