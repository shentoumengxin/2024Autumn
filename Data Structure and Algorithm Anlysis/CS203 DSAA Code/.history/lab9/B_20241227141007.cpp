#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// 定义图中的每个节点
class point {
public:
    int num;
    vector<point*> neibor;  // 邻接节点
    vector<long long> wei;  // 边的权重
    point(int num) : num(num) {}
};

// 定义堆中的节点
class node {
public:
    long long num;      // 节点编号
    point* p;           // 指向图中的节点
    long long dist;     // 当前节点到 MST 的最小边权
    bool is_visit;      // 标记节点是否已被访问

    node(long long val = 0, point* p = nullptr) : num(val), p(p), dist(LONG_LONG_MAX), is_visit(false) {}
};

// 上浮操作，保持最小堆性质
void heap_up(vector<node*>& heap, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[index]->dist < heap[parent]->dist) {
            swap(heap[index], heap[parent]);
            index = parent;
        }
        else {
            break;
        }
    }
}

// 下沉操作，保持最小堆性质
void heap_down(vector<node*>& heap, int index) {
    int size = heap.size();
    while (true) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int small = index;

        if (left < size && heap[left]->dist < heap[small]->dist) {
            small = left;
        }
        if (right < size && heap[right]->dist < heap[small]->dist) {
            small = right;
        }
        if (small != index) {
            swap(heap[index], heap[small]);
            index = small;
        }
        else {
            break;
        }
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    // 初始化图
    vector<point*> map(n + 1, nullptr);
    for (int i = 1; i <= n; i++) {
        map[i] = new point(i);
    }

    long long total = 0;  // 所有边的权重总和

    // 输入图的边（无向图，双向添加）
    for (int i = 1; i <= m; i++) {
        long long u, v, w;
        cin >> u >> v >> w;
        total += w;  // 每条边的权重加一次
        map[u]->neibor.push_back(map[v]);
        map[u]->wei.push_back(w);
        map[v]->neibor.push_back(map[u]);  // 双向添加
        map[v]->wei.push_back(w);
    }

    // 初始化最短路径数组
    vector<long long> dist(n + 1, LLONG_MAX);
    dist[1] = 0;  // 从节点1开始

    // 初始化堆并将起始节点加入堆
    vector<node*> heap;
    node* start = new node(1, map[1]);
    start->dist = 0;
    heap.push_back(start);
    heap_up(heap, 0);  // 插入源节点并上浮

    long long mst_sum = 0;  // 最小生成树的权重总和

    while (!heap.empty()) {
        node* current = heap[0];  // 取出堆顶节点

        // 将堆顶节点移出堆
        heap[0] = heap.back();
        heap.pop_back();
        heap_down(heap, 0);  // 堆化

        // 如果节点已经被访问过，则跳过
        if (current->is_visit) {
            continue;
        }

        // 标记当前节点为已访问
        current->is_visit = true;

        // 将当前节点的最小边权加入 MST（跳过起始节点）
        if (current->dist != 0) {  
            mst_sum += current->dist;
        }

        // 遍历当前节点的所有邻接点
        for (int i = 0; i < current->p->neibor.size(); i++) {
            point* neighbor = current->p->neibor[i];
            long long weight = current->p->wei[i];
            long long v = neighbor->num;

            // 如果通过当前节点能找到更短的边权，则更新
            if (weight < dist[v]) {  // 正确的条件判断
                dist[v] = weight;

                // 创建新节点并加入堆
                node* newNode = new node(v, neighbor);
                newNode->dist = weight;
                heap.push_back(newNode);
                heap_up(heap, heap.size() - 1);  // 插入新节点并上浮
            }
        }
    }

    // 计算最大化删除边的收益
    long long gain = total - mst_sum;
    cout << gain << "\n";

    
    return 0;
}
