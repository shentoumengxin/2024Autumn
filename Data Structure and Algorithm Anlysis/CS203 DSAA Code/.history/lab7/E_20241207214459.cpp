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
    long long num;
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
int heap_down(vector<node*>&heap,int index){
    
    int size = heap.size();
    while(true){
        int left=index/2+1;
        int right=index/2+2;
        int small=index;
        if(left<size&&heap[small]>heap[left])small=left;
        if(right<size&&heap[small]>heap[right])small=right;
        if(small != index){
            swap(heap[index], heap[small]);
            index = small;
        }
        else{
            break;
        }
    }
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    int N;
    cin>>N;
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
    for(int i=1;i<N;i++){
        node *top=carrots_heap.at(0);
        if(top->is_visit){
            while(top->is_visit){
                top=carrots_heap.back();
                heap_down(top)
            }
        }
        long long new_right_value=0;
        long long new_left_value=0;
        if(top->next!=nullptr)
        new_right_value=(top->next->num^top->num)+1;
        if(top->prev!=nullptr)
        new_left_value=(top->prev->num^top->num)+1;
        if(i=N-1){
            if(new_left_value>new_right_value){
                cout<<new_left_value<<endl;
            }else{
                cout<<new_right_value<<endl;
            }
        }
        if(new_right_value>new_left_value){
            top->next->is_visit=true;  //ghost node
            top->next=top->next->next;  //右边的最近值]
            if(top->next!=nullptr)top->next->prev=top;
            
            top->num=new_right_value;
        }else{
            top->prev->is_visit=1;
            top->prev=top->prev->prev;
            if(top->prev!=nullptr)top->prev->next=top;
            top->num=new_left_value;
        }
        

    }

    return 0;
}