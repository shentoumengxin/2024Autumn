#include<iostream>
#include<vector>
using namespace std;
class Node {
public:
    int val;
    int p;
    int max = 0;  // 巨人到达时间
    bool is_visit = false; // 是否访问过
    vector<Node*> children;

    Node(int val = 0) : val(val) {}
};
void dfs(Node* root){
    if(root==nullptr)return;
    int max=
    for(auto child : root->children){

        dfs(child);
    }
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n;
    cin>>n;
    vector<Node*>nodes(n,nullptr);
    for(int i=1;i<=n;i++){
        Node* new_n=new Node(i);
        nodes.push_back(new_n);
    }
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        nodes[u]->children.push_back(nodes[v]);
        nodes[v]->children.push_back(nodes[u]);
    }
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        nodes[i]->p=x;
    }
    return 0;
}