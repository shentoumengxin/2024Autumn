#include<iostream> 
using namespace std;
class node{
    public:
    int value;
    node *next;
    node *pre;
    node(int x){
        value = x;
        next = nullptr;
        pre = nullptr;
    }
};
class link_list{
    public:
    int size;
    node *head;
    node *tail;
    link_list(){
        size = 0;
        head = nullptr;
        tail = nullptr;
    }
};
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int n;
        scanf("%d", &n);
        link_list *l = new link_list();
        l->head = new node(-1);
        l->tail = new node(200005);
        int cnt=0;
        node *pos_node=l->head;
        node **node_list = new node*[100005];
        for(int i = 1; i <= n; i++){
            int tmp;
            scanf("%d", &tmp);
            node * new_node=new node(tmp);
            pos_node->next = new_node;
            new_node->pre = pos_node;
            pos_node = new_node;
        }
        pos_node->next = l->tail;
        l->tail->pre = pos_node;
        pos_node = l->head->next;
        while(pos_node!=l->tail){
            if(pos_node->value<=pos_node->next->value){
                pos_node = pos_node->next;
                continue;
            }
            else{
                node_list[cnt++] = pos_node->pre;
                pos_node = pos_node->next;
                while(pos_node->next!=l->tail&&pos_node->value>pos_node->next->value){
                    pos_node = pos_node->next;
                }
                node_list[cnt-1]->next = pos_node->next;
                pos_node->next->pre = node_list[cnt-1];
                
            }
        }
        
        bool success = false;
        while(!success){
            // int count=0;
            // count++;
            // for(int i = 0; i < cnt; i++){
            //     cout<<i+1<<" "<<node_list[i]->value<<"cnt:"<<cnt<<endl;
            // }
            success = true;
            node ** check_list=new node*[cnt+5];
            int check_cnt = 0;
            //cout<<"count: "<<count<<"cnt:"<<cnt<<"check_cnt: "<<check_cnt<<endl;
            for(int i = 0; i < cnt&&node_list[i]!=nullptr; i++){
                
                if(node_list[i]->value<=node_list[i]->next->value){
                    //node_list[i] = node_list[i]->next;
                    continue;

                }else{
                    success = false;
                    check_list[check_cnt++] = node_list[i]->pre;
                    node_list[i]->pre->next = node_list[i]->next;
                    node_list[i]->next->pre = node_list[i]->pre;
                    node *end=node_list[i];
                    while(end->next!=l->tail&&end->value>end->next->value){
                        end =end->next;
                        check_list[check_cnt-1] ->next = end;
                        end->pre = check_list[check_cnt-1];
                        //delete end->pre;
                    }
                    check_list[check_cnt-1] ->next = end->next;
                    end->next->pre = check_list[check_cnt-1];
                    
                } 
                
                }
                // pos_node = l->head->next;
                // printf("\n");
                // while(pos_node!=l->tail){
                // printf("%d ", pos_node->value);
                // pos_node = pos_node->next;
                // }
                // for(int i=0;i<check_cnt;i++){
                //     printf("check_list[%d]:%d \n", i,check_list[i]->value);
                // }
            // printf("\n");
            delete []node_list;
            node_list = check_list;
            cnt=check_cnt;
        }
        pos_node = l->head->next;
        while(pos_node!=l->tail){
            printf("%d ", pos_node->value);
            pos_node = pos_node->next;
        }
        printf("\n");

    }
}