#include<iostream>
#include<vector>
using namespace std;
struct node{
    int val;
    bool is_visit=false; //确认真父
    int path=-1;
    vector<node*>sons;
    node(int val = 0) : val(val) {}
};
int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int T;
    cin>>T;
    while(T--){
        int n,m,s;
        cin>>n>>m;
        vector<node>nodes(n+1,0);
        for(int i=0;i<n;i++)nodes[i].val=i;
        for(int i=1;i<=m;i++){
            int x,y;
            cin>>x>>y;
            nodes[x].sons.push_back(&nodes[y]);   //邻接链表存图
            nodes[y].sons.push_back(&nodes[x]);
        }
        vector<node*> queue;
        int front=0;    //队列头部指针
        queue.push_back(&nodes[s]);   
        nodes[s].is_visit=true;
        nodes[s].path=0;
        while(front < queue.size()){
            node* head=queue[front++];   //出队
            for (int i = 0; i < head->sons.size(); i++) {
                node* child = head->sons[i];
                if (child->is_visit) continue;  // 已经访问过的节点跳过
                child->path=head->path+1;   //儿子的层=父的层+1
                child->is_visit = true;
                queue.push_back(child);
            }
        }
        for(int i=1;i<n;i++){
            cout<<nodes[i].path<<' ';
        }
        cout<<nodes[n].path<<endl;

    }
    
    return 0;

}