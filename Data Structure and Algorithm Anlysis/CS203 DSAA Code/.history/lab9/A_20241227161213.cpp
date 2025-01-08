#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class point {
public:
    int num;
    vector<point*> neibor;  // 邻接节点
    vector<long long> wei;  // 边的权重
    point(int num) : num(num) {}
};

class node {
public:
    node* parent = nullptr;
    long long num;
    point* p;
    long long dist;
    bool is_ghost = false;  // 新增的标记属性，用于标记节点是否已访问

    node(long long val = 0, point* p = nullptr) : num(val), p(p), dist(LONG_LONG_MAX) {}
};


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

// 堆下沉操作，确保最小堆性质
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
    ios::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    vector<point*> map(n + 1, nullptr);  // 保存每个城市的点
    for (int i = 1; i <= n; i++) {
        map[i] = new point(i);
    }

    // 输入图的边
    for (int i = 1; i <= m; i++) {
        long long u, v, w;
        cin >> u >> v >> w;
        map[u]->neibor.push_back(map[v]);
        map[u]->wei.push_back(w);
    }

    // Dijkstra 初始化
    vector<long long> dist(n + 1, LLONG_MAX);  // 用一个数组记录每个城市到城市1的最短距离
    dist[1] = 0;

    vector<node*> heap;
    node* start = new node(1, map[1]);
    start->dist = 0;
    heap.push_back(start);
    heap_up(heap, 0);  // 插入源节点并上浮

    while (!heap.empty()) {
        node* current = heap[0];  // 取出堆顶节点

        // 如果节点已经被处理过（is_ghost == true），就跳过它
        if (current->is_ghost) {
            heap[0] = heap.back();  // 将堆底元素移到堆顶
            heap.pop_back();
            heap_down(heap, 0);  // 堆化
            continue;
        }

        // 标记当前节点已处理
        current->is_ghost = true;

        // 遍历当前节点的邻接点
        for (int i = 0; i < map[current->num]->neibor.size(); i++) {
            long long v = map[current->num]->neibor[i]->num;
            long long weight = map[current->num]->wei[i];

            // 如果通过当前节点能找到更短的路径，则更新
            if (current->dist + weight < dist[v]) {
                dist[v] = current->dist + weight;

                // 创建新节点并加入堆
                node* newNode = new node(v, map[v]);
                newNode->dist = dist[v];
                heap.push_back(newNode);
                heap_up(heap, heap.size() - 1);  // 插入新节点并上浮
            }
        }
    }



    if (dist[n] == LLONG_MAX) {
        cout << -1 << endl;  // 如果没有路径到达城市n
    } else {
        cout << dist[n] << endl;  // 输出从城市1到城市n的最短路径
    }



    return 0;
}
