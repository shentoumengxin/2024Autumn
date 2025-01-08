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
    node(long long val = 0, point* p = nullptr) : num(val), p(p), dist(LLONG_MAX) {}
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

    


    if (dist[n] == LLONG_MAX) {
        cout << -1 << endl;  // 如果没有路径到达城市n
    } else {
        cout << dist[n] << endl;  // 输出从城市1到城市n的最短路径
    }



    return 0;
}
