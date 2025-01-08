#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// 自定义交换函数
void manual_swap(long long &a, long long &b) {
    long long temp = a;
    a = b;
    b = temp;
}

void manual_swap_point(class node* &a, class node* &b) {
    class node* temp = a;
    a = b;
    b = temp;
}


class point {
public:
    int num;
    bool is_mst = false;            // 标记是否已经确实是最短
    long long dist = LLONG_MAX;       // 最短距离，初始化为无穷大
    vector<point*> neighbor;           // 邻接节点
    vector<long long> wei;             // 边的权重

    point(int num) : num(num) {}
};

// 定义堆节点的类，包含指向点的指针和当前距离
class node {
public:
    point* p;
    long long dist;

    node(point* p, long long dist) : p(p), dist(dist) {}
};

// 堆上浮操作，维护最小堆性质
void heap_up(vector<node*> &heap, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[index]->dist < heap[parent]->dist) {
            manual_swap_point(heap[index], heap[parent]);
            index = parent;
        }
        else {
            break;
        }
    }
}

// 堆下沉操作，维护最小堆性质
void heap_down(vector<node*> &heap, int index) {
    int size = heap.size();
    while (true) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if (left < size && heap[left]->dist < heap[smallest]->dist) {
            smallest = left;
        }
        if (right < size && heap[right]->dist < heap[smallest]->dist) {
            smallest = right;
        }

        if (smallest != index) {
            manual_swap_point(heap[index], heap[smallest]);
            index = smallest;
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

    vector<point*> map(n + 1, nullptr);
    for (int i = 1; i <= n; i++) {
        map[i] = new point(i);
    }

    for (int i = 0; i < m; i++) {
        long long u, v, w;
        cin >> u >> v >> w;
        map[u]->neighbor.push_back(map[v]);
        map[u]->wei.push_back(w);
        map[v]->neighbor.push_back(map[u]);
        map[v]->wei.push_back(w);
    }

    // 初始化起点
    map[1]->dist = 0;

    // 初始化堆并插入起点
    vector<node*> heap;
    node* start = new node(map[1], map[1]->dist);
    heap.push_back(start);
    heap_up(heap, heap.size() - 1);

    while (!heap.empty()) {
        // 取出堆顶节点
        node* current = heap[0];
        // 移除堆顶元素
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) {
            heap_down(heap, 0);
        }

        point* current_point = current->p;

        // 如果该点已经被访问过，跳过
        if (current_point->is_mst) {
            //delete current; // 释放已弹出节点的内存
            continue;
        }

        // 标记当前点已访问
        current_point->is_mst = true;

        // 遍历当前点的所有邻接点
        for (int i = 0; i < current_point->neighbor.size(); i++) {
            point* neighbor_point = current_point->neighbor[i];
            long long weight = current_point->wei[i];

            // 如果通过当前节点能找到更短的路径，则更新
            if (current_point->dist + weight < neighbor_point->dist&&) {
                neighbor_point->dist = current_point->dist + weight;
                node* newNode = new node(neighbor_point, neighbor_point->dist);
                heap.push_back(newNode);
                heap_up(heap, heap.size() - 1);
            }
        }


        //delete current;
    }

    // 输出结果
    if (map[n]->dist == LLONG_MAX) {
        cout << -1 << "\n"; 
    }
    else {
        cout << map[n]->dist << "\n"; 
    }

    // // 释放动态分配的内存
    // for (int i = 1; i <= n; i++) {
    //     delete map[i];
    // }

    return 0;
}
