#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// 定义道路和传送门的结构体
struct Road {
    int to;
    long long weight;
};

struct Portal {
    int to;
};

// 定义状态结构体
struct State {
    int city;
    int portals_used;
    long long distance;
};

// 自定义最小堆类
class MinHeap {
public:
    vector<State> heap;

    // 插入新状态，并上浮
    void push(const State& state) {
        heap.push_back(state);
        heap_up(heap.size() - 1);
    }

    // 弹出堆顶状态
    State pop_min() {
        State min_state = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) {
            heap_down(0);
        }
        return min_state;
    }

    // 检查堆是否为空
    bool empty() const {
        return heap.empty();
    }

private:
    // 堆上浮操作
    void heap_up(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index].distance < heap[parent].distance) {
                // 交换
                State temp = heap[index];
                heap[index] = heap[parent];
                heap[parent] = temp;
                index = parent;
            }
            else {
                break;
            }
        }
    }

    // 堆下沉操作
    void heap_down(int index) {
        int size = heap.size();
        while (true) {
            int smallest = index;
            int left = 2 * index + 1;
            int right = 2 * index + 2;

            if (left < size && heap[left].distance < heap[smallest].distance) {
                smallest = left;
            }
            if (right < size && heap[right].distance < heap[smallest].distance) {
                smallest = right;
            }
            if (smallest != index) {
                // 交换
                State temp = heap[index];
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

    // 初始化距离数组
    // dist[city][portals_used] = 最小距离
    // 使用一维数组模拟二维数组，方便实现
    vector<vector<long long>> dist(n + 1, vector<long long>(k + 1, LLONG_MAX));
    dist[S][0] = 0;

    // 初始化最小堆，并将起始状态入堆
    MinHeap heap;
    State start;
    start.city = S;
    start.portals_used = 0;
    start.distance = 0;
    heap.push(start);

    while(!heap.empty()){
        State current = heap.pop_min();
        int u = current.city;
        int pu = current.portals_used;
        long long d = current.distance;

        // 如果当前距离大于已记录的最小距离，跳过
        if(d > dist[u][pu]){
            continue;
        }

        // 通过道路移动
        for(auto &road : roads[u]){
            int v = road.to;
            long long w = road.weight;
            if(d + w < dist[v][pu]){
                dist[v][pu] = d + w;
                State newState;
                newState.city = v;
                newState.portals_used = pu;
                newState.distance = d + w;
                heap.push(newState);
            }
        }

        // 如果还可以激活传送门）
        if(pu < k){
            for(auto &portal : portals[u]){
                int v = portal.to;
                long long w = 0; // 传送门的距离为0
                if(d + w < dist[v][pu + 1]){
                    dist[v][pu + 1] = d + w;
                    State newState;
                    newState.city = v;
                    newState.portals_used = pu + 1;
                    newState.distance = d + w;
                    heap.push(newState);
                }
            }
        }
    }

    // 找到从 S 到 T 的最小距离，遍历所有可能激活传送门的情况
    long long answer = LLONG_MAX;
    for(int i = 0; i <= k; i++){
        if(dist[T][i] < answer){
            answer = dist[T][i];
        }
    }

    cout << answer << "\n";

    return 0;
}
