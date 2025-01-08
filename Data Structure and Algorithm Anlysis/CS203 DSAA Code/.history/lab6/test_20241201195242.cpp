#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int val;
    bool is_visit = false; // 是否访问过
    vector<Node*> children;
    bool gaint=0;
    Node(int val = 0) : val(val) {}
};


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
        if (xx != 1) {
            nodes[xx]->gaint = 1;  // 给非根节点设置初始到达时间
        }
    }
    int ans=0;

    nodes[1]->is_visit=true;
    vector<int> sub_nodes;
    vector<Node*>queue;
    for (auto& child : nodes[1]->children) {
        int level=0;   //level
        int max_time=1;
        queueclear();
        int front=0;
        queue.push_back(child);    //根节点入队
        child->is_visit=true;
        while(front < queue.size()){
            Node* head=queue[front++];   //取出栈顶节点
            int i=0;
            for (int i = 0; i < head->children.size(); i++) {
                Node* child = head->children[i];
                if (child->is_visit) continue;  // 已经访问过的节点跳过
                if(child->gaint){
                    int child_level = level;
                    int i = sub_nodes.size() - 1;
                    while (i >= 0 && sub_nodes[i] > child_level) {
                        i--;
                    }
                    sub_nodes.insert(sub_nodes.begin() + i + 1, child_level);
                }
                queue.push_back(child);    //子节点入队
                level++;
            }
        }


         // 处理巨人到达时间的计算
        bool repeat = false;
        for (int i = 0; i < sub_nodes.size(); i++) {
            
            if (max_time > sub_nodes[i]) {
                max_time++;     // 时间慢了，说明前面被堵了，继续堵
                repeat = false;
            } else if (max_time == sub_nodes[i]) {
                if (!repeat) {
                    repeat = true;    // 第一次重复不要紧，可以通过
                } else {
                    max_time++;     // 第二次会拥堵
                }
            } else {
                max_time = sub_nodes[i];  // 可以通过
                repeat = true;  // 可能重复
            }
        }
        if(max_time>ans)ans=max_time;
        sub_nodes.clear();
    }
    
    cout << ans << endl;  // 输出根节点的最大到达时间
    
    return 0;
}
