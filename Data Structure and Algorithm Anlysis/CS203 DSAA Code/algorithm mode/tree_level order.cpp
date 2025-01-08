//有一个儿子的节点是叶子（只有一个活爹）
//tree 的几个重要要确定的事情：
//1.确定有没有根，根是谁。
//2.边的方向是什么，如果没有就按照下面的连双边的方式，在bfs的时候确定真爹。
#include<iostream>
#include<vector>
using namespace std;
struct node{
    int val;
    long long path=0;
    bool is_visit=false; //确认真父
    vector<int>wei;   //存边
    vector<node*>sons;   //son nodes's address
    node(int val = 0) : val(val) {}
};

int main(){
    int n,num;
    long long ans=0;
    cin>>n>>num;
    vector<node*> nodes(n + 1, nullptr);
    for(int i = 1; i <= n; i++){
        nodes[i] = new node(i);   //创建无边的节点
    }  //new 节点
    for(int i=1;i<n;i++){

        int u,v,w;
        cin>>u>>v>>w;
        nodes[u]->sons.push_back(nodes[v]);    //双向连边
        nodes[u]->wei.push_back(w);
        nodes[v]->sons.push_back(nodes[u]);
        nodes[v]->wei.push_back(w);

    }
    vector<node*> queue;    //bfs遍历 level traversal
    int front=0;
    queue.push_back(nodes[1]);    //根节点入队
    nodes[1]->is_visit=true;
    while(front < queue.size()){
        node* head=queue[front++];   //取出栈顶节点
        int i=0;
        for (int i = 0; i < head->sons.size(); i++) {
            node* child = head->sons[i];
            if (child->is_visit) continue;  // 已经访问过的节点跳过
            child->path = head->path + head->wei[i];  // 更新路径
            child->is_visit = true;    //enque and is_visit
            queue.push_back(child);    //子节点入队
        }
    }
    for(int i=1;i<=n;i++){
        if(i != 1&&nodes[i]->sons.size()==1){   //leaf nodes
            
            if(nodes[i]->path==num){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}