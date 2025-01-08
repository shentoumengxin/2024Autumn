#include<iostream>
using namespace std;
class node{
public:
    int data;
    node *next;
    // 带参数的构造函数
    node(int data) {
        this->data = data;
        this->next = nullptr;
    }

};
class list{
public:
    node* head;
    node* tail;
    int size;
    list() {
        head = new node(-1); // 使用一个哨兵节点，数据设为 0
        tail =new node(-1);
        head->next=tail;
        size = 0;
    }
};

void list_insert(list *l,int pos,int value){
    if(l==NULL){
        pos=0;
    }
    node *new_node=new node(value);
    new_node->next=NULL;
    node *pos_node=l->head;   //从头开始找
    if(pos>l->size+1)return;
    for(int i=1;i<pos;i++){
        pos_node=pos_node->next;
    }                                 //得到插入位置的前一个指针
    if(pos=l->size+1){
        pos_node->next=new_node;
        new_node->next=l->tail;
    }else{
        new_node->next=pos_node->next;   //先把新指针的next连到后
        pos_node->next=new_node;
    }
    
    l->size++;               //l长度++
}
void list_replace(list* l,int pos,int value){
    if(l==NULL){
        pos=0;
    }
    node *new_node=new node(value);
    new_node->next=NULL;
    node *pos_node=l->head;   //从头开始找
    if(pos>l->size)return;
    for(int i=1;i<pos;i++){
        pos_node=pos_node->next;
    }
    node * q=pos_node->next;                                //得到插入位置的前一个指针
    new_node->next=q->next;   //先把新指针的next连到后
    pos_node->next=new_node;
    delete q;

}
void list_delete(list* l,int pos){
    if(l==NULL ||l->size<1 || pos>l->size )return;
    node *pos_node=l->head;
    for(int i=1;i<pos;i++){
        pos_node=pos_node->next;
    }                //pos前一个指针
    node *q=pos_node->next;
    pos_node->next=q->next;
    delete q;   //删除内存
    l->size--;
}
void list_print(list* l){
    node *pos_node=l->head->next;
    int cnt=l->size;
    while(cnt--){
        cout<<pos_node->data<<' ';
        pos_node=pos_node->next;
    }
    cout<<pos_node->data;
}
int main(){
    list *l=new list();
    for(int i=1;i<=10;i++){
        list_insert(l,i,i);
    }
    list_delete(l,2);
    list_print(l);
    return 0;
}