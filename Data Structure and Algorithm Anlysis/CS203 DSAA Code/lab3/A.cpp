#include <iostream>
using namespace std;

class node {
public:
    int value;
    node(int v) {
        this->value = v;
        this->next = nullptr;
    }
    node* next;
};

class link_l {
public:
    int size;
    node* head;
    node* top;
    link_l() {
        size = 0;
        head = nullptr;
        top = nullptr;
    }
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        link_l* l = new link_l();
        node* head = new node(1);
        l->head = head;
        l->top = head;
        l->size++;

        for (int i = 2; i <= n; i++) {
            node* dish = new node(i);
            l->size++;
            l->top->next = dish;
            l->top = dish;
        }

        l->top->next = l->head;
        l->top = l->head;

        node* current = l->top;
        node* prev = nullptr;

        while (l->size > 0) {
            if (l->size == 1) {
                cout << current->value << endl;
                delete current;
                l->size--;
                break;
            }
            for (int i = 1; i < k; ++i) {
                prev = current;
                current = current->next;
            }
            cout << current->value << " ";
            
            if (prev != nullptr) {
                prev->next = current->next;
            }
            node* toDelete = current;
            current = current->next;
            delete toDelete;
            l->size--;
        }
        
    }

    return 0;
}
