// 找出最小的，左和右都试一次，选最大的合并。
// 链表，小顶堆.
// 和他爸比较，决定上浮或者下沉
// 删除这个表，幽灵节点。打标记.
// 删除时检查堆顶，如果是幽灵，就删除幽灵
#include<iostream>
#include<vector>
using namespace std;
class node{
    node* next;
    node* pre
};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    int N;
    cin>>N;
    long long ans; 
    int carrots[N+1];
    for(int i=1;i<=N;i++){
        int x;
        cin>>x;
        carrots[i]=x;
    }

    return 0;
}