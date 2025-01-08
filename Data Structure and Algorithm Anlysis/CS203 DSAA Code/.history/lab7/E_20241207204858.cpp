// 找出最小的，左和右都试一次，选最大的合并。
// 链表，小顶堆.
// 和他爸比较，决定上浮或者下沉
// 删除这个表，幽灵节点。打标记.
// 删除时检查堆顶，如果是幽灵，就删除幽灵
#include<iostream>
#include<vector>
using namespace std;
class node{
    public:
    node* next=nullptr;
    node* prev=nullptr;
    int num;
    bool is_visit=false;
    node(int val=0):num(val){}
};
int heap_up(vector<node*>&heap,int index){
    while(index>0){
        int parent=(index-1)/2;
        if(heap[index]<heap[parent]){
            swap(heap[index],heap[parent]);
        }
        index=parent;
    }
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    int N;
    cin>>N;
    long long ans; 
    vector<node*>carrots_heap(N+1);
    node ca[N+1];
    for(int i=0;i<N;i++){
        int x;
        cin>>x;
        ca[i].num=x;
        if(i>0){
            ca[i].prev=&ca[i-1];
        }
        if(i<N){
            ca[i].next=&ca[i+1];
        }
    }
    for(int i=0;i<N;i++){
        node* new_node=&ca[i];
        carrots_heap.push_back(new_node);
        heap_up(carrots_heap,i);
        
    }
    while(carrots_heap.size()){
        node *top=carrots_heap.at(0);
        if(top->is_visit){
            
        }
        if(top->next!=nullptr)
        int new_left_value=(top->next->num^top.)+1

    }

    return 0;
}