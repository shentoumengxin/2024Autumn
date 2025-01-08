#include <iostream>  
using namespace std;

class node {
public:
    int value;
    node* next;
    node* prev;
    node(int value) {
        this->value = value;
        this->next = nullptr;
        this->prev = nullptr;   // 双向链表
    }
};
class link_list{
public:
    int size;
    node *head;
    node *tail;
    link_list(){
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
};

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N, M;
        scanf("%d %d", &N, &M);
        link_list *m = new link_list();
        m->head = new node(-1);
        m->tail = new node(-1);
        m->head->next = m->tail;
        m->tail->prev = m->head;

        node *pos_node = m->head;
        node* find_n[100005]; // 用于快速查找节点

        // 初始化链表
        for (int i = 1; i <= N; i++) {
            int tmp;
            scanf("%d", &tmp);
            node* new_node = new node(tmp);
            new_node->prev = pos_node;
            pos_node->next = new_node;

            pos_node = new_node;
            find_n[tmp] = new_node;   // 记录当前节点
        }
        // 连接尾节点
        pos_node->next = m->tail;
        m->tail->prev = pos_node;

        m->size = N;

        for (int i = 1; i <= M; i++) {
            int x1, y1, x2, y2;
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

            node* x1_n = find_n[x1];
            node* y1_n = find_n[y1];
            node* x2_n = find_n[x2];
            node* y2_n = find_n[y2];

            node* pre_x1 = x1_n->prev;
            node* next_y1 = y1_n->next;
            node* pre_x2 = x2_n->prev;
            node* next_y2 = y2_n->next;

            // 检查区间是否相邻
            if (y1_n->next == x2_n) { // 第一个区间紧接着第二个区间
                // 连接 pre_x1 和 x2_n
                pre_x1->next = x2_n;
                x2_n->prev = pre_x1;

                // 连接 y2_n 和 x1_n
                y2_n->next = x1_n;
                x1_n->prev = y2_n;

                // 连接 y1_n 和 next_y2
                y1_n->next = next_y2;
                next_y2->prev = y1_n;
            } else if (y2_n->next == x1_n) { // 第二个区间紧接着第一个区间
                // 连接 pre_x2 和 x1_n
                pre_x2->next = x1_n;
                x1_n->prev = pre_x2;

                // 连接 y1_n 和 x2_n
                y1_n->next = x2_n;
                x2_n->prev = y1_n;

                // 连接 y2_n 和 next_y1
                y2_n->next = next_y1;
                next_y1->prev = y2_n;
            } else { // 区间不相邻
                // 连接 pre_x1 和 x2_n
                pre_x1->next = x2_n;
                x2_n->prev = pre_x1;

                // 连接 y2_n 和 next_y1
                y2_n->next = next_y1;
                next_y1->prev = y2_n;

                // 连接 pre_x2 和 x1_n
                pre_x2->next = x1_n;
                x1_n->prev = pre_x2;

                // 连接 y1_n 和 next_y2
                y1_n->next = next_y2;
                next_y2->prev = y1_n;
            }

            // 无需更新 find_n，因为节点本身没有变化
        }

        // 输出链表
        pos_node = m->head->next;
        while (pos_node != m->tail) {
            printf("%d ", pos_node->value);
            pos_node = pos_node->next;
        }
        printf("\n");

        // 释放内存（建议在实际应用中释放所有节点）
        delete m;
    }
    return 0;
}
