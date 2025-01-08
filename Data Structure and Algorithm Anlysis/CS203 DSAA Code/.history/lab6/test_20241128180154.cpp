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

void dfs(Node* root,Node* final) {
    if (root == nullptr) {
        return;
    }

    root->is_visit = true;
    vector <int> sorted_gaints;
    // DFS遍历子节点
    for (auto& child : root->children) {
        if (!child->is_visit) {
            dfs(child,final);  // 传递 max_time 到子节点
            
            int gaint_time = child->gaint_time;
            // 找到插入位置
            if(gaint_time!=0){
                int i = sorted_gaints.size() - 1;
                while (i >= 0 && sorted_gaints[i] > gaint_time) {
                    i--;
                }
                // 插入到合适的位置
                sorted_gaints.insert(sorted_gaints.begin() + i + 1, gaint_time);
            }
        }
    }
    
    // 处理巨人到达时间的计算
    int max_time=0;
    bool repeat = false;
    
    for (int i = 0; i < sorted_gaints.size(); i++) {
        // cout<<sorted_gaints[i]<<endl;
        if (max_time > sorted_gaints.at(i)) {
            max_time++;     // 时间慢了，说明前面被堵了，继续堵
            repeat = false;
        } else if (max_time == sorted_gaints.at(i)) {
            if (!repeat) {
                repeat = true;    // 第一次重复不要紧，可以通过
            } else {
                max_time++;     // 第二次会拥堵
            }
        } else {
            max_time = sorted_gaints.at(i);  // 可以通过
            repeat=true;   //下一次可能重复
        }
        
    }
    // cout<<endl;
    root->gaint_time += max_time;  // 更新当前节点的最大时间

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
    for (int i = 0; i < m; i++) {
        int xx;
        cin >> xx;
        if(xx!=1){
            nodes[xx]->gaint_time=1;
        }
        
    }

    
    for(int i=0;)

    cout << nodes[1]->gaint_time << endl;
    return 0;
}
