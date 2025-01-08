#include<iostream>
#include<vector>
using namespace std;
class Node {
public:
    int val;
    int max = 0;  // 巨人到达时间
    bool is_visit = false; // 是否访问过
    vector<Node*> children;

    Node(int val = 0) : val(val) {}
};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        Node* new_n=new Node
    }
    return 0;
}