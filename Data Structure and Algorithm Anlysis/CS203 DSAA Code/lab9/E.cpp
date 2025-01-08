#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 50001;
const int INF = 1e9;

vector<int> graph[MAX_N ], reverseGraph[MAX_N];
vector<int> scc[MAX_N ];
int disc[MAX_N], low[MAX_N], sccId[MAX_N];
bool inStack[MAX_N];

int stk[MAX_N];
int top = -1;  // 栈的顶部指针

void push(int u) {
    stk[++top] = u;
}

int pop() {
    return stk[top--];
}

bool isEmpty() {
    return top == -1;
}

int timeStamp = 0, sccCount = 0;

void tarjan(int u) {
    disc[u] = low[u] = ++timeStamp;
    push(u);
    inStack[u] = true;

    // 深度优先遍历邻接节点
    for (int v : graph[u]) {
        if (disc[v] == -1) {
            tarjan(v);
            low[u] = (low[u] < low[v]) ? low[u] : low[v]; // 手动实现 min 操作
        } else if (inStack[v]) {
            low[u] = (low[u] < disc[v]) ? low[u] : disc[v]; // 手动实现 min 操作
        }
    }

    // 如果 u 是一个强连通分量的根
    if (disc[u] == low[u]) {
        ++sccCount;
        while (true) {
            int v = pop();
            inStack[v] = false;
            scc[sccCount].push_back(v);
            sccId[v] = sccCount;
            if (v == u) break;
        }
    }
}

int solve(int n, int m, int S) {
    // 初始化
    for (int i = 1; i <= n; i++) {
        disc[i] = -1;
        low[i] = -1;
    }

    // 执行 Tarjan 算法找强连通分量
    for (int i = 1; i <= n; i++) {
        if (disc[i] == -1) {
            tarjan(i);
        }
    }

    // 构建缩点后的图（SCC 图）
    vector<int> Indegree(sccCount + 1, 0);
    vector<int> Outdegree(sccCount + 1, 0);

    for (int u = 1; u <= n; u++) {
        for (int v : graph[u]) {
            int sccU = sccId[u], sccV = sccId[v];
            if (sccU != sccV) {
                Indegree[sccV]++;    //说明是两个不同的scc
            }
        }
    }

    // 找到 S 的 SCC
    int startSCC = sccId[S];

    // 统计无法从 S 到达的 SCC 数量
    int unreachable = 0;
    for (int i = 1; i <= sccCount; i++) {
        if (i != startSCC && Indegree[i] == 0) {
            unreachable++;
        }
    }

    return unreachable;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, S;
    cin >> n >> m >> S;

    // 读取图的边
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    // 求解并输出结果
    cout << solve(n, m, S) << endl;
    return 0;
}
