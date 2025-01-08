#include <iostream> 
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

typedef struct Node Node;

typedef struct Node {
    void* data;           // pointer to node data
    size_t byte_num;      // The size of the data in bytes    
    Node* next;           // pointer to next node
} Node;

typedef struct MagicLinkedList {
    Node* head;           // head node
    Node* tail;           // tail node
} MagicLinkedList;

void octal2byte(char **dst, char *octal) {
    if (octal == nullptr || strlen(octal) < 2 || strncmp(octal, "0o", 2) != 0) {
        *dst = nullptr;
        return;
    }

    const char* octalPtr = octal + 2;
    size_t octalLength = strlen(octalPtr);

    size_t padding = (3 - (octalLength % 3)) % 3;
    std::string paddedOctal(padding, '0');
    paddedOctal += octalPtr;

    std::string result;

    for (size_t i = 0; i < paddedOctal.length(); i += 3) {
        char c1 = paddedOctal[i];
        char c2 = paddedOctal[i + 1];
        char c3 = paddedOctal[i + 2];

        if (c1 < '0' || c1 > '7' || c2 < '0' || c2 > '7' || c3 < '0' || c3 > '7') {
            *dst = nullptr;
            return;
        }

        int b1 = c1 - '0';
        int b2 = c2 - '0';
        int b3 = c3 - '0';

        int bits9 = (b1 << 6) | (b2 << 3) | b3;
        int byte = bits9 >> 1;

        result += static_cast<char>(byte);
    }

    char* buffer = new char[result.length() + 1];
    memcpy(buffer, result.c_str(), result.length());
    buffer[result.length()] = '\0';
    *dst = buffer;
}

MagicLinkedList* create() {
    MagicLinkedList* l = new MagicLinkedList;
    l->head = new Node{nullptr, 0, nullptr};
    l->tail = l->head;
    return l;
}

void append_node(MagicLinkedList* list, void* data) {
    if (list == NULL || list->head == NULL) return;

    char *octal = static_cast<char*>(data);
    char *str = nullptr;
    octal2byte(&str, octal);
    if (str == nullptr) return;
    Node *new_node = new Node{str, strlen(str), list->tail};
    Node *pos_node = new Node{str, strlen(str), list->tail};
    while(pos_node->next!=list->tail){
        pos_node=pos_node->next;
    }
    pos_node->next=new_node

}

void insert_node(MagicLinkedList* list, int position, void* data) {
    if (position < 0 || list == NULL || list->head == NULL) return;

    char *octal = static_cast<char*>(data);
    char* str = nullptr;
    octal2byte(&str, octal);
    if (str == NULL) return;

    Node *new_node = new Node{str, strlen(str), nullptr};
    Node *pos_node = list->head;
    int step = 0;

    while (pos_node->next != nullptr && step < position) {
        pos_node = pos_node->next;
        step++;
    }

    if (step != position) {
        delete[] str;
        delete new_node;
        return;
    }

    new_node->next = pos_node->next;
    pos_node->next = new_node;
    if (new_node->next == nullptr) list->tail = new_node;
}

void delete_node(MagicLinkedList* list, int position) {
    if (list == NULL || list->head == NULL || position < 0) return;

    Node *pos_node = list->head;
    int step = 0;

    while (pos_node->next != nullptr && step < position) {
        pos_node = pos_node->next;
        step++;
    }

    if (pos_node->next == nullptr) return;

    Node *to_delete = pos_node->next;
    pos_node->next = to_delete->next;
    if (to_delete == list->tail) list->tail = pos_node;

    delete[] static_cast<char*>(to_delete->data);
    delete to_delete;
}

void destroy(MagicLinkedList* list) {
    if (list == NULL || list->head == NULL) return;

    Node *current = list->head;
    while (current != nullptr) {
        Node *next = current->next;
        delete[] static_cast<char*>(current->data);
        delete current;
        current = next;
    }
    delete list;
}

void printx(MagicLinkedList *LinkedList) {
    if (LinkedList == NULL || LinkedList->head == NULL) return;

    Node *current = LinkedList->head->next;
    while (current != nullptr) {
        char *data = static_cast<char*>(current->data);
        for (size_t i = 0; i < current->byte_num; i++) {
            char c = data[i];
            putchar((c >= 33 && c <= 126) ? c : '#');
        }
        cout << endl;
        current = current->next;
    }
}

void printx_reverse(MagicLinkedList *LinkedList) {
    if (LinkedList == NULL || LinkedList->head == NULL) return;

    vector<Node*> nodes;
    Node *current = LinkedList->head->next;

    while (current != nullptr) {
        nodes.insert(nodes.begin(), current);
        current = current->next;
    }

    for (auto& node : nodes) {
        char *data = static_cast<char*>(node->data);
        for (size_t i = 0; i < node->byte_num; i++) {
            char c = data[i];
            cout << ((c >= 33 && c < 127) ? c : '#');
        }
        cout << endl;
    }
}

int main() {
    int T;
    scanf("%d", &T);
    MagicLinkedList *m_list = NULL;

    while (T--) {
        char op;
        scanf(" %c", &op);
        switch (op) {
        case 'C': {
            if (m_list != NULL) {
                destroy(m_list);
            }
            m_list = create();
            break;
        }
        case 'A': {
            int len;
            scanf("%d", &len);
            char *octal_str = (char *)malloc(len + 1);
            scanf("%s", octal_str);
            append_node(m_list, octal_str);
            free(octal_str);
            break;
        }
        case 'I': {
            int index;
            scanf("%d", &index);
            int len;
            scanf("%d", &len);
            char *octal_str = (char *)malloc(len + 1);
            scanf("%s", octal_str);
            insert_node(m_list, index, octal_str);
            free(octal_str);
            break;
        }
        case 'D': {
            int item_id;
            scanf("%d", &item_id);
            delete_node(m_list, item_id);
            break;
        }
        case 'X': {
            destroy(m_list);
            m_list = NULL;
            break;
        }
        case 'Q': {
            printx(m_list);
            break;
        }
        case 'R': {
            printx_reverse(m_list);
            break;
        }
        default:
            break;
        }
    }

    if (m_list != NULL) {
        destroy(m_list);
    }

    return 0;
}
