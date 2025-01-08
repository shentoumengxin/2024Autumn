#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Node {
public:
    int val;          
    int p;            
    int max_val = 0;  
    bool is_visit = false;  
    vector<Node*> children; // 子节点列表

    Node(int val = 0, int p = 0) : val(val), p(p) {}
};
// 从根节点开始的深度优先搜索，后序遍历，寻找每个节点的最大激活值
void dfs_find(Node* root) {
    if (root == nullptr) return;
    root->is_visit = true;
    
    for (auto child : root->children) {
        if (!child->is_visit) {
            dfs_find(child);  
            root->max_val = max(root->max_val, child->max_val);
        }
    }

    root->max_val = max(root->max_val, root->p);  // 当前节点的最大激活值至少是它自己的 p 值
}

// 第二次 DFS，计算每个节点的激活值
void dfs_div(Node* root) {
    if (root == nullptr) return;

    bool can_active = false;
    int max_val = INT_MIN;
    Node* max_node = nullptr;

    for (auto child : root->children) {
        if (!child->is_visit) {  
            if (root->max_val <= child->max_val) {
                can_active = true;
            }
            if (child->max_val > max_val) {
                max_val = child->max_val;
                max_node = child;
            }
        }
    }

    if (!can_active && max_node != nullptr) {
        max_node->max_val = root->max_val;
    }

    root->is_visit = true;
    for (auto child : root->children) {
        if (!child->is_visit) {
            dfs_div(child);
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n;
    cin >> n;

    // 创建节点
    vector<Node*> nodes(n + 1, nullptr);  // 索引从1开始，大小为n+1
    for (int i = 1; i <= n; i++) {
        nodes[i] = new Node(i);  // 创建节点并初始化
    }

    // 输入树的边
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        nodes[u]->children.push_back(nodes[v]);
        nodes[v]->children.push_back(nodes[u]);
    }

    // 输入每个节点的p值
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        nodes[i]->p = x;
    }

    // 找到最大 p 值的节点并从该节点开始 DFS
    int max_p_index = 1;
    for (int i = 2; i <= n; i++) {
        if (nodes[i]->p > nodes[max_p_index]->p) {
            max_p_index = i;
        }
    }

    // 如果根节点只有一个子节点，直接处理
    if (nodes[max_p_index]->children.size() == 1) {
        nodes[max_p_index]->max_val = nodes[max_p_index]->p;
        nodes[max_p_index]->is_visit = true;
        dfs_find(nodes[max_p_index]->children[0]);

        // 重置访问标记
        for (int i = 1; i <= n; i++) {
            nodes[i]->is_visit = false;
        }

        nodes[max_p_index]->is_visit = true;
        dfs_div(nodes[max_p_index]->children[0]);

        long long total = 0;
        for (int i = 1; i <= n; i++) {
            if (nodes[i]->children.size() == 1) {
                total += nodes[i]->max_val;
            }
        }

        cout << total << endl;
        return 0;
    }
    dfs_find(nodes[max_p_index]);
    // 从最大 p 值的节点开始第一次 DFS
    Node *max1 = nullptr, *max2 = nullptr;
    for (auto child : nodes[max_p_index]->children) {
        if (max1 == nullptr || child->max_val > max1->max_val) {
            max2 = max1;
            max1 = child;
        } else if (max2 == nullptr || child->max_val > max2->max_val) {
            max2 = child;
        }
    }

    if (max1!=numax2 != nullptr) {
        max2->max_val = nodes[max_p_index]->p;
        max1->max_val = nodes[max_p_index]->p;
    }

    // 重置访问标记
    for (int i = 1; i <= n; i++) {
        nodes[i]->is_visit = false;
    }

    // 第二次 DFS 更新激活值
    dfs_div(nodes[max_p_index]);

    // 计算总激活值
    long long total = 0;
    for (int i = 1; i <= n; i++) {
        if (nodes[i]->children.size() == 1) {
            total += nodes[i]->max_val;
        }
    }

    cout << total << endl;
    return 0;
}
