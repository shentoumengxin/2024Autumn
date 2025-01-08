#include <iostream>
#include <vector>

using namespace std;

struct node {
public:
    int value;
    vector<node*> sons;

    node(int val = 0) : value(val) {}
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;

        if(N <= 0){
            cout << '\n';
            continue;
        }

        vector<node*> nodes(N + 1, nullptr);
        for(int i = 1; i <= N; i++){
            nodes[i] = new node(i);
        }

        // 构建树的边
        for(int i = 1; i < N; i++){
            int x;
            cin >> x;
            nodes[x]->sons.push_back(nodes[i + 1]);
        }


        vector<node*> queue;
        int front = 0; 
        queue.push_back(nodes[1]); // 入队第一个节点

        while(front < queue.size()){
            node* head = queue[front++]; // 出队
            cout << head->value << ' ';
            for(auto &child : head->sons){
                queue.push_back(child); // 入队子节点
            }
        }
        cout << endl;

    }
    return 0;
}
