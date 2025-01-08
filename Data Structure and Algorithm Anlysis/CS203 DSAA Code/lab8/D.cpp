#include <iostream>
#include <vector>
using namespace std;

// 定义节点结构体
struct node {
    node* fa;                // 父节点指针
    int val;                 // 节点值
    int in_time;             // 进入时间
    int out_time;            // 退出时间
    bool is_visit;           // 标记是否已经访问
    vector<node*> children;  // 子节点列表

    node(int val = 0) : fa(nullptr), val(val), in_time(0), out_time(0), is_visit(false) {}
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin >> T;
    while(T--){
        int n, m;
        cin >> n >> m;
        

        vector<node> nodes(n + 1, node(0));
        for(int i = 1; i <= n; i++) {
            nodes[i].val = i;
        }
        

        for(int i = 1; i < n; i++){
            int x, y;
            cin >> x >> y;
            nodes[x].fa = &nodes[y]; 
            nodes[y].children.push_back(&nodes[x]);
        }

        node* root = nullptr;
        for(int i =1; i <=n; i++){
            if(nodes[i].fa == nullptr){
                root = &nodes[i];
                break;
            }
        }
        

        if(root == nullptr){
            for(int i =1; i <= m; i++){
                int x, y;
                cin >> x >> y;
                cout << "No\n";
            }
            continue;
        }
        
        vector<int> in_time(n +1, 0);
        vector<int> out_time(n +1, 0);
        int timer = 1;
        
        vector<node*> stk;
        stk.push_back(root);
        
        while(!stk.empty()){
            node* current_node = stk.back();
            stk.pop_back();
            
            if(!current_node->is_visit){
                // 记录进入时间
                in_time[current_node->val] = timer++;
                // 标记为已访问
                current_node->is_visit = true;
     
                stk.push_back(current_node);
             
                for(auto it = current_node->children.rbegin(); it != current_node->children.rend(); ++it){
                    stk.push_back(*it);
                }
            }
            else{
        
                out_time[current_node->val] = timer++;
            }
        }
        
        // 处理查询
        for(int i=1; i<=m; i++){
            int x, y;
            cin >> x >> y;
            if(in_time[y] <= in_time[x] && out_time[x] <= out_time[y]){
                cout << "Yes\n";
            }
            else{
                cout << "No\n";
            }
        }
        
        for(int i =1; i <=n; i++){
            nodes[i].is_visit = false;
            nodes[i].in_time = 0;
            nodes[i].out_time = 0;
        }
    }
    return 0;
}
