#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void manual_swap(long long &a, long long &b) {
    long long temp = a;
    a = b;
    b = temp;
}

void manual_swap_state(struct State* &a, struct State* &b) {
    State* temp = a;
    a = b;
    b = temp;
}

// 道路和传送门
struct Road {
    int to;
    long long weight;
};

struct Portal {
    int to;
};


struct State {
    int city;
    int portals_used;
    long long distance;
};

class HeapNode {
public:
    State* state;

    HeapNode(State* s) : state(s) {}
};


void heap_up(vector<HeapNode*> &heap, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[index]->state->distance < heap[parent]->state->distance) {
            manual_swap_state(heap[index]->state, heap[parent]->state);
            index = parent;
        }
        else {
            break;
        }
    }
}

void heap_down(vector<HeapNode*> &heap, int index) {
    int size = heap.size();
    while (true) {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && heap[left]->state->distance < heap[smallest]->state->distance) {
            smallest = left;
        }
        if (right < size && heap[right]->state->distance < heap[smallest]->state->distance) {
            smallest = right;
        }

        if (smallest != index) {
            manual_swap_state(heap[index]->state, heap[smallest]->state);
            index = smallest;
        }
        else {
            break;
        }
    }
}

// 自定义堆类
class MinHeap {
public:
    vector<HeapNode*> heap;

    // 插入新状态，并上浮
    void push(State* state) {
        HeapNode* node = new HeapNode(state);
        heap.push_back(node);
        heap_up(heap, heap.size() - 1);
    }

    // 弹出堆顶状态
    State* pop_min() {
        if (heap.empty()) return nullptr;
        State* min_state = heap[0]->state;
        manual_swap_state(heap[0]->state, heap[heap.size() - 1]->state);
        delete heap.back();
        heap.pop_back();
        if (!heap.empty()) {
            heap_down(heap, 0);
        }
        return min_state;
    }

    // 检查堆是否为空
    bool empty() const {
        return heap.empty();
    }
};

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int n, m, p, k;
    cin >> n >> m >> p >> k;

    // 构建道路的邻接表
    vector<vector<Road>> roads(n + 1, vector<Road>());
    for(int i = 0; i < m; i++){
        int u, v;
        long long w;
        cin >> u >> v >> w;
        Road road;
        road.to = v;
        road.weight = w;
        roads[u].push_back(road);
    }

    // 构建传送门的邻接表
    vector<vector<Portal>> portals(n + 1, vector<Portal>());
    for(int i = 0; i < p; i++){
        int u, v;
        cin >> u >> v;
        Portal portal;
        portal.to = v;
        portals[u].push_back(portal);
    }

    int S, T;
    cin >> S >> T;

    // dist[city][portals_used] = 最小距离
    vector<vector<long long>> dist(n + 1, vector<long long>(k + 1, LLONG_MAX));
    dist[S][0] = 0;

    // 初始化堆并插入起点
    MinHeap heap;
    State* start = new State{S, 0, 0};
    heap.push(start);

    while(!heap.empty()){
        State* current = heap.pop_min();
        int u = current->city;
        int pu = current->portals_used;
        long long d = current->distance;

        // 如果当前距离大于已记录的最小距离
        if(d > dist[u][pu]){
            delete current;
            continue;
        }

        // 通过道路移动
        for(auto &road : roads[u]){
            int v = road.to;
            long long w = road.weight;
            if(d + w < dist[v][pu]){
                dist[v][pu] = d + w;
                State* newState = new State{v, pu, d + w};
                heap.push(newState);
            }
        }

        // 还可以激活传送门
        if(pu < k){
            for(auto &portal : portals[u]){
                int v = portal.to;
                long long w = 0; // 传送门的距离为0
                if(d + w < dist[v][pu + 1]){
                    dist[v][pu + 1] = d + w;
                    State* newState = new State{v, pu + 1, d + w};
                    heap.push(newState);
                }
            }
        }

        delete current;
    }

    // 找到从 S 到 T 的最小距离 所有可能激活传送门的情况
    long long answer = LLONG_MAX;
    for(int i = 0; i <= k; i++){
        if(dist[T][i] < answer){
            answer = dist[T][i];
        }
    }


    if(answer == LLONG_MAX){
        cout << -1 << "\n";
    }
    else{
        cout << answer << "\n";
    }

    return 0;
}
