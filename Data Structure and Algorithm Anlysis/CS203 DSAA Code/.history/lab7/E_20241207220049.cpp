#include <iostream>
#include <vector>
using namespace std;

class node {
public:
    node* next = nullptr;
    node* prev = nullptr;
    long long num;
    bool is_visit = false;
    node(long long val=0) : num(val) {}
};

// 堆上浮操作，确保最小堆性质
void heap_up(vector<node*>& heap, int index){
    while(index > 0){
        int parent = (index - 1) / 2;
        if(heap[index]->num < heap[parent]->num){
            swap(heap[index], heap[parent]);
            index = parent;
        }
        else{
            break;
        }
    }
}

// 堆下沉操作，确保最小堆性质
void heap_down(vector<node*>& heap, int index){
    int size = heap.size();
    while(true){
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int small = index;

        if(left < size && heap[left]->num < heap[small]->num){
            small = left;
        }
        if(right < size && heap[right]->num < heap[small]->num){
            small = right;
        }
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
    ios::sync_with_stdio(false);
    
    int N;
    cin >> N;

    // 使用 vector 动态分配节点，避免栈溢出
    vector<node> ca(N);

    for(int i = 0; i < N; i++){
        int x;
        cin >> x;
        ca[i].num = x;
        if(i > 0){
            ca[i].prev = &ca[i-1];
        }
        if(i < N - 1){
            ca[i].next = &ca[i+1];
        }
    }

    // 构建最小堆
    vector<node*> carrots_heap;
    carrots_heap.reserve(N); 

    for(int i = 0; i < N; i++){
        node* new_node = &ca[i];
        carrots_heap.push_back(new_node);
        heap_up(carrots_heap, carrots_heap.size() - 1);
    }

    for(int merge_count = 0; merge_count < N - 1; merge_count++){
        if(carrots_heap.empty()) break;
        node* top = carrots_heap[0];

        // 如果堆顶是幽灵节点，移除它
        if(top->is_visit){
            // 将堆顶与最后一个节点交换，并弹出
            swap(carrots_heap[0], carrots_heap.back());
            carrots_heap.pop_back();
            if(!carrots_heap.empty()){
                heap_down(carrots_heap, 0);
            }
            continue; // 重新检查新的堆顶
        }

        // 计算与左、右相邻节点合并后的值
        long long new_left_value = (top->prev != nullptr) ? ((top->num ^ top->prev->num) + 1) : -1;
        long long new_right_value = (top->next != nullptr) ? ((top->num ^ top->next->num) + 1) : -1;

        // 如果当前是最后一次合并，输出结果并结束
        if(merge_count == N - 2){
            long long final_value = max(new_left_value, new_right_value);
            cout << final_value << "\n";
            break;
        }


        if(new_right_value > new_left_value){
            // 合并右侧
            if(top->next != nullptr){
                node* right_node = top->next;
                right_node->is_visit = true;

                // 更新链接
                top->next = right_node->next;
                if(right_node->next != nullptr){
                    right_node->next->prev = top;
                }
            }
            top->num = new_right_value;
        }
        else{
            // 合并左侧
            if(top->prev != nullptr){
                node* left_node = top->prev;
                left_node->is_visit = true;

                top->prev = left_node->prev;
                if(left_node->prev != nullptr){
                    left_node->prev->next = top;
                }
            }
            top->num = new_left_value;
        }
        heap_down(carrots_heap, 0);
    }

    return 0;
}
