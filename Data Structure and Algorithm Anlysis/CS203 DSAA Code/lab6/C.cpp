//有一个儿子的节点是叶子（只有一个活爹）
#include<iostream>
#include<vector>
using namespace std;
struct node{
    int val;
    long long path=0;
    bool is_visit=false; //确认真父
    vector<int>wei;   //存边
    vector<node*>sons;
    node(int val = 0) : val(val) {}
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n,num;
    long long ans=0;
    cin>>n>>num;
    vector<node*> nodes(n + 1, nullptr);
    for(int i = 1; i <= n; i++){
        nodes[i] = new node(i);
    }  //new 节点
    for(int i=1;i<n;i++){

        int u,v,w;
        cin>>u>>v>>w;
        nodes[u]->sons.push_back(nodes[v]);
        nodes[u]->wei.push_back(w);
        nodes[v]->sons.push_back(nodes[u]);
        nodes[v]->wei.push_back(w);

    }
    vector<node*> queue;
    int front=0;
    queue.push_back(nodes[1]);
    nodes[1]->is_visit=true;
    while(front < queue.size()){
        node* head=queue[front++];
        int i=0;
        for (int i = 0; i < head->sons.size(); i++) {
            node* child = head->sons[i];
            if (child->is_visit) continue;  // 已经访问过的节点跳过
            child->path = head->path + head->wei[i];  // 更新路径
            child->is_visit = true;
            queue.push_back(child);
        }
    }
    for(int i=1;i<=n;i++){
        if(i != 1&&nodes[i]->sons.size()==1){
            
            if(nodes[i]->path==num){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}