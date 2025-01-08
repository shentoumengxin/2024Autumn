#include<iostream> 
#include<ctime>
#include<cstdlib>
using namespace std;
class node{
    public:
    node *next;
    node *prev;
    int value;
    node() : value(0) {
        this->next=nullptr;
        this->prev=nullptr;
    }            // 默认构造函数
    node(int value){
        this->value=value;
        this->next=nullptr;
        this->prev=nullptr;
    }
};

void swap(node* &a, node* &b){
    node* temp = a;
    a = b;
    b = temp;
}

int partition(node* a[], int left, int right) { 
    int pivotIndex = left + rand() % (right - left + 1);
    swap(a[left], a[pivotIndex]);
    node* pivot = a[left];
    int i = left + 1;
    int j = right;
    while (i <= j) {
        while (i <= j && a[i]->value <= pivot->value) i++;
        while (i <= j && a[j]->value >= pivot->value) j--;
        if (i < j) {
            swap(a[i], a[j]);
        }
    }
    swap(a[left], a[j]);
    return j;
}


void quick_sort(node* a[], int left, int right){
    if (left < right) {
        int p = partition(a, left, right);
        quick_sort(a, left, p - 1);
        quick_sort(a, p + 1, right);
    }
}     //快速排序

int main(){
    int n;
    srand(time(0));
    scanf("%d",&n);
    node **unsort_node=new node*[2000005];
    node ** sort_node=new node*[2000005];
    for(int i=0;i<n;i++){
        int tmp;
        scanf("%d",&tmp);
        node *new_node=new node(tmp);
        unsort_node[i]=new_node;
    }

    for(int i=0;i<n;i++){     //copy the link to array in order to sort
       sort_node[i] = unsort_node[i];
    }
    quick_sort(sort_node,0,n-1); //对指针进行交换
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            sort_node[i]->prev = nullptr;
            sort_node[i]->next = sort_node[i + 1];
        } else if (i == n - 1) {
            sort_node[i]->prev = sort_node[i - 1];
            sort_node[i]->next = nullptr;
        } else {
            sort_node[i]->prev = sort_node[i - 1];
            sort_node[i]->next = sort_node[i + 1];
        }
    }

    for(int i=0;i<n-1;i++){
        int t1=0,t2=0;
        if(unsort_node[i]->prev==nullptr){
            t2=abs(unsort_node[i]->value-unsort_node[i]->next->value);
            unsort_node[i]->next->prev=nullptr;
            printf("%d ",t2);
            continue;
        }
        if(unsort_node[i]->next==nullptr){
            t1=abs(unsort_node[i]->value-unsort_node[i]->prev->value);
            unsort_node[i]->prev->next=unsort_node[i]->next;
            printf("%d ",t1);
            continue;
        }
        t1=abs(unsort_node[i]->value-unsort_node[i]->prev->value);
        t2=abs(unsort_node[i]->value-unsort_node[i]->next->value);
        if(t1>t2){
            printf("%d ",t2);
        }else{
            printf("%d ",t1);
        }     //找到最小的
        //接下来删除这个节点，保证后面的点找不到这个点
        unsort_node[i]->prev->next=unsort_node[i]->next;
        unsort_node[i]->next->prev=unsort_node[i]->prev;
    }
    printf("\n");
    delete []sort_node;
    delete []unsort_node;
    return 0;
    
}