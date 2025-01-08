#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void swap_n(long long &a, long long &b) {
    long long temp = a;
    a = b;
    b = temp;
}

void swap_n(pair<long long, int> &a, pair<long long, int> &b) {
    pair<long long, int> temp = a;
    a = b;
    b = temp;
}


struct Edge {
    int to;
    long long weight;
};


class MaxHeap {
public:
    vector<pair<long long, int>> heap; // first: weight, second: node

    void push(long long weight, int node) {
        pair<long long, int> hn = {weight, node};
        heap.push_back(hn);
        heap_up(heap.size() - 1);
    }

    pair<long long, int> pop_max() {
        if (heap.empty()) return {0, -1};
        pair<long long, int> max_node = heap[0];
        swap_n(heap[0], heap[heap.size() - 1]);
        heap.pop_back();
        if (!heap.empty()) {
            heap_down(0);
        }
        return max_node;
    }

    bool empty() const {
        return heap.empty();
    }

private:
    void heap_up(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index].first > heap[parent].first) {
                swap_n(heap[index], heap[parent]);
                index = parent;
            }
            else {
                break;
            }
        }
    }

    void heap_down(int index) {
        int size = heap.size();
        while (true) {
            int largest = index;
            int left = 2 * index + 1;
            int right = 2 * index + 2;

            if (left < size && heap[left].first > heap[largest].first) {
                largest = left;
            }
            if (right < size && heap[right].first > heap[largest].first) {
                largest = right;
            }
            if (largest != index) {
                swap_n(heap[index], heap[largest]);
                index = largest;
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

    int n, m;
    cin >> n >> m;

    // 读取网格的点系数
    vector<vector<long long>> grid(n, vector<long long>(m, 0));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> grid[i][j];
        }
    }


    auto node = [&](int i, int j) -> int {
        return i * m + j;
    };

    // 构建邻接表
    vector<vector<Edge>> adj(n * m, vector<Edge>());
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(j + 1 < m){
                adj[node(i, j)].push_back(Edge{node(i, j + 1), grid[i][j] * grid[i][j + 1]});
            }
            if(i + 1 < n){
                adj[node(i, j)].push_back(Edge{node(i + 1, j), grid[i][j] * grid[i + 1][j]});
            }
            if(j - 1 >= 0){
                adj[node(i, j)].push_back(Edge{node(i, j - 1), grid[i][j] * grid[i][j - 1]});
            }
            if(i - 1 >= 0){
                adj[node(i, j)].push_back(Edge{node(i - 1, j), grid[i][j] * grid[i - 1][j]});
            }
        }
    }


    vector<bool> in_mst(n * m, false);
    long long total_gain = 0;
    int count = 0;

    // 初始化最大堆并将起始节点的所有边加入堆
    MaxHeap heap;
    in_mst[0] = true;
    count++;
    for(auto &e : adj[0]){
        heap.push(e.weight, e.to);
    }

    while(!heap.empty() && count < n * m){
        pair<long long, int> current = heap.pop_max();
        long long w = current.first;
        int u = current.second;

        if(in_mst[u]){
            continue;
        }

        in_mst[u] = true;
        total_gain += w;
        count++;

        for(auto &e : adj[u]){
            if(!in_mst[e.to]){
                heap.push(e.weight, e.to);
            }
        }
    }

    cout << total_gain;
    return 0;
}
