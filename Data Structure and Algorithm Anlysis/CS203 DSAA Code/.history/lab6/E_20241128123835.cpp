#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int val;
    int gaint_time = 0;  // 巨人到达时间
    bool is_visit = false; // 是否访问过
    vector<Node*> children;

    Node(int val = 0) : val(val) {}
};

void dfs(Node* root, int &max_time) {
    if (root == nullptr) {
        return;
    }

    root->is_visit = true;
    vector<int> sorted_gaints;

    // DFS遍历子节点
    for (auto& child : root->children) {
        if (!child->is_visit) {
            
            dfs(child, max_time);  // 传递 max_time 到子节点
            int gaint_time = child->gaint_time;

            // 找到插入位置并插入
            int i = sorted_gaints.size() - 1;
            while (i >= 0 && sorted_gaints[i] > gaint_time) {
                i--;
            }
            sorted_gaints.insert(sorted_gaints.begin() + i + 1, gaint_time);
        }
    }
   
    // 如果当前节点是node[1]，直接取子节点的最大时间
    if (root->val == 1) {
        // 如果没有子节点，则max_time保持为1（根节点没有堵塞）
        if (!sorted_gaints.empty()) {
            max_time = sorted_gaints.back()+1;  // 直接取最大时间走一次
        }
    } else {
        // 处理巨人到达时间的计算
        bool repeat = false;
        for (int i = 0; i < sorted_gaints.size(); i++) {
             cout<<sorted_gaints[i]<<',';
            if (max_time > sorted_gaints[i]) {
                max_time++;     // 时间慢了，说明前面被堵了，继续堵
                repeat = false;
            } else if (max_time == sorted_gaints[i]) {
                if (!repeat) {
                    repeat = true;    // 第一次重复不要紧，可以通过
                } else {
                    max_time++;     // 第二次会拥堵
                }
            } else {
                max_time = sorted_gaints[i];  // 可以通过
                repeat = true;  //可能重复
            }
        }
    }
     cout<<endl;
    root->gaint_time = max_time;  // 更新当前节点的最大时间
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
    bool all_root = true;
    
    for (int i = 0; i < m; i++) {
        int xx;
        cin >> xx;
        if (xx != 1) {
            nodes[xx]->gaint_time = 1;  // 给非根节点设置初始到达时间
            all_root = false;
        }
    }

    if (all_root || m <= 0) {
        cout << "0" << endl;  // 如果根节点没有任何堵塞，直接返回0
        return 0;
    }

    int max_time = 1;
    dfs(nodes[1], max_time);  // 传递 max_time

    cout << max_time << endl;  // 输出根节点的最大到达时间
    return 0;
}