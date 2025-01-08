#include<iostream>
#include<vector>
using namespace std;

struct node {
    int val;
    bool is_visit = false;
    int path = -1; // 层级
    vector<node*> sons;
    node(int val = 0) : val(val) {}
};

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    
    int T;
    cin >> T;
    while(T--){
        int n, m;
        cin >> n >> m;

        vector<node> nodes(n+1, node(0));
        for(int i = 1; i <= n; i++) {
            nodes[i].val = i;
        }

        for(int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            nodes[u].sons.push_back(&nodes[v]);
            nodes[v].sons.push_back(&nodes[u]);
        }
        
        // BFS 分层
        vector<node*> queue;
        int front = 0;
        // 从节点1开始
        queue.push_back(&nodes[1]);
        nodes[1].is_visit = true;
        nodes[1].path = 0;
        
        while(front < queue.size()){
            node* head = queue[front++];
            for(auto child : head->sons){
                if(!child->is_visit){
                    child->is_visit = true;
                    child->path = head->path + 1;
                    queue.push_back(child);
                }
            }
        }
        
        vector<int> even_nodes, odd_nodes;
        for(int i = 1; i <= n; i++){
            if(nodes[i].path % 2 == 0){
                even_nodes.push_back(i);
            }
            else{
                odd_nodes.push_back(i);
            }
        }
        

        vector<int> chosen;
        if(even_nodes.size() <= odd_nodes.size()){
            chosen = even_nodes;
        }
        else{
            chosen = odd_nodes;
        }
        

        cout << chosen.size() << "\n";
        for(int i = 0; i < chosen.size(); i++){
            cout << chosen[i] << (i < chosen.size() - 1 ? ' ' : '\n');
        }
    }
    
    return 0;
}
