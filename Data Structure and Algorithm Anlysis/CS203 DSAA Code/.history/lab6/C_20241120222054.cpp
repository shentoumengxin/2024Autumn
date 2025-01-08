//有一个儿子的节点是叶子（只有一个活爹）
#include<iostream>
#include<vector>
using namespace std;
struct node{
    int val;
    bool is_visit=false; //确认真父
    vector<int>wei;   //存边
    vector<node*>son;
    node(int val = 0) : val(val) {}
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n,num;
    cin>>n>>num;
    vector<node*> nodes(n + 1, nullptr);
    for(int i = 1; i <= n; i++){
        nodes[i] = new node(i);
    }  //new 节点
    for(int i=1;i<n;i++){
        int u,v,w;
        cin>>u>>v>>w;
        nodes[u]->son.push_back(nodes[v]);
        nodes[u]->wei.push_back(w);
    }
    vector<node*> queue;
    int front=0;
    queue.push_back(nodes[1]);

    while(front < queue.size()){
        node* head=queue[front++];
        for(auto &child : head->sons)
    }
    return 0;
}