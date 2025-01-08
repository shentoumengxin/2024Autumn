#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int val;
    int gaint_time = 0;  // 巨人到达时间
    bool is_visit = false;  // 是否访问过
    vector<Node*> children;
    bool gaint = false;  // 是否是巨人节点
    Node(int val = 0) : val(val) {}
};

void dfs(Node* root, int level, vector<int>& sorted_gaints) {
    if (root == nullptr) {
        return;
    }

    root->is_visit = true;
    root->gaint_time = level;  // 更新节点的巨人到达时间

    // 遍历当前节点的子节点
    for (auto& child : root->children) {
        if (!child->is_visit) {
            dfs(child, level + 1, sorted_gaints);  // 递归访问子节点，递增深度

            // 如果子节点是巨人节点，更新排序
            if (child->gaint) {
                int gaint_time = child->gaint_time;
                int i = sorted_gaints.size() - 1;
                while (i >= 0 && sorted_gaints[i] > gaint_time) {
                    i--;
                }
                sorted_gaints.insert(sorted_gaints.begin() + i + 1, gaint_time);  // 插入排序
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<Node*> nodes(n + 1, nullptr);

    // 创建城市节点
    for (int i = 1; i <= n; i++) {
        Node* node = new Node(i);
        nodes[i] = node;
    }

    // 构建图
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        nodes[u]->children.push_back(nodes[v]);
        nodes[v]->children.push_back(nodes[u]);
    }

    int m;
    cin >> m;
    
    // 设置巨人节点
    for (int i = 0; i < m; i++) {
        int xx;
        cin >> xx;
        if (xx != 1) {
            nodes[xx]->gaint = true;  // 给非根节点设置初始到达时间
        }
    }

    int ans = 0;
    // 遍历根节点的每个子节点
    for (auto& child : nodes[1]->children) {
        int max_time = 0;
        vector<int> sub_nodes;
        dfs(child, 1, sub_nodes);  // 从根节点的子节点开始DFS

        // 输出调试信息
        for (int i = 0; i < sub_nodes.size(); i++) {
            cout << sub_nodes[i] << ',';
        }
        cout << endl;

        // 计算巨人到达的最大时间
        bool repeat = false;
        for (int i = 0; i < sub_nodes.size(); i++) {
            if (max_time > sub_nodes[i]) {
                max_time++;  // 时间慢了，说明前面被堵了，继续堵
                repeat = false;
            } else if (max_time == sub_nodes[i]) {
                if (!repeat) {
                    repeat = true;  // 第一次重复没有问题，可以通过
                } else {
                    max_time++;  // 第二次会拥堵
                }
            } else {
                max_time = sub_nodes[i];  // 可以通过
                repeat = true;  // 可能重复
            }
        }

        if (max_time > ans) ans = max_time + 1;
        cout << max_time << endl;
    }

    cout << ans << endl;  // 输出根节点的最大到达时间
    return 0;
}
