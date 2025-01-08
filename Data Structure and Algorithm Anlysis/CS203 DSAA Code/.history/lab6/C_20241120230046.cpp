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

    while(front < queue.size()){
        node* head=queue[front++];
        head->is_visit=true;
        int i=0;
        for(auto &child : head->sons){
            if(head->sons[i]->is_visit)continue;
            queue.push_back(child);
            head->sons.at(i)->path=head;
            head->sons.at(i)->is_visit=true;
            i++;
        }
    }
    return 0;
}