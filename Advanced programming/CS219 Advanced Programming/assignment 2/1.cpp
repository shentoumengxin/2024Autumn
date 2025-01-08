#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <bitset>
#include<vector>
using namespace std;
typedef struct Node Node;
/*
The parameters in the following two structures are enough to finish the assignment. However, If adding some parameters to these two structures can be helpful, you can also do that.
*/
typedef struct Node {
    void* data;           // pointer to node data
    size_t byte_num;     // The size of the data in bytes    
    Node* next;    // pointer to next node
} Node;

// Definition of linked list node structure
typedef struct MagicLinkedList {
    Node* head;           // head node
    Node* tail;           // tail node
} MagicLinkedList;

/* Your code starts here */

// Save every three octal string into bytes


void octal2byte(char **dst, char *octal) {
    if (octal == nullptr || strlen(octal) < 2 || strncmp(octal, "0o", 2) != 0) {
        dst=nullptr;
        return ; 
    }
    // 去掉 "0o" 前缀
    octal += 2;
    int octalLength = strlen(octal);

    string paddedOctal;
    size_t padding = (3 - (octalLength % 3)) % 3; // 计算需要补的 '0' 数量
    paddedOctal.append(padding, '0'); 
    paddedOctal += octal;
    // 将八进制转换为二进制
    string binaryString;
    int cnt=0;
    string end_string;
    for (char *ptr = &paddedOctal[0]; *ptr != '\0'; ++ptr) {
        cnt++;
        if (*ptr < '0' || *ptr > '7') {
            *dst=nullptr;
            return ; // 非法
        }

        int value = *ptr - '0';
        binaryString += bitset<3>(value).to_string();   //转换成3位的二进制并拼接
        
        if(cnt==3){
            cnt=0;
            string tmp=binaryString.substr(0,8);    //舍掉最后一位
            int a=stoi(tmp,nullptr,2);      // decimal 
            char aa=static_cast<char>(a);    //根据ascii转换成c
            if (aa >= 33 && aa <= 126) {
                
            } else {
                aa='#';
            }
            end_string+=a;                   //拼接
            binaryString.erase();             //下一对
        }

    }
    char* charArray = new char[end_string.length() + 1]; // +1 for the null terminator

    strcpy(charArray, end_string.c_str());
    
    *dst=charArray;
    
}



// Create a new linked list
MagicLinkedList* create() {
    // Allocate memory for the linked list
    MagicLinkedList* l=new  MagicLinkedList;
    Node *head=new Node;
    Node *tail=new Node;
    head->next=tail;
    tail->next=nullptr;
    l->head=head;
    l->tail=tail;
    return l;
    
}

// Append a new node to the end of the linked list
void append_node(MagicLinkedList* list, void* data) {
    // Allocate memory for a new node and set its data and size
    // Link the new node to the end of the linked list
    // TODO: Implement this function
    if (list == NULL || list->head == NULL) {
        return;// 处理错误或返回
    }
    char *octal=static_cast<char*>(data);
    char * str=nullptr;
    octal2byte(&str,octal);
    if (str == nullptr) {
        return;
    }
    Node *new_node=new Node;
    new_node->data=str;
    size_t ken = strlen(str);
    new_node->byte_num = ken;
    Node *pos_node=list->head;
    while(pos_node->next!=list->tail){
        pos_node=pos_node->next;
    }
    pos_node->next=new_node;
    new_node->next=list->tail;

}

// Insert a new node at a specific position in the linked list
void insert_node(MagicLinkedList* list, int position, void* data) {
    // Allocate memory for a new node and set its data and size
    // Insert the node at the specified position in the linked list 
    // position is non-negative and start from 0. If position is invalid or out of bound, don't operate on list.
    // TODO: Implement this function
    if(position<0)return;
    if (list == NULL || list->head == NULL) {
        return;// 处理错误或返回
    }
    char *octal=static_cast<char*>(data);
    char* str=nullptr;
    octal2byte(&str,octal);
    if (str == NULL) {
        return;// 处理错误或返回
    }
    Node *new_node=new Node;
    new_node->data=str;
    Node *pos_node=list->head;
    size_t ken = strlen(str);
    new_node->byte_num = ken;
    int step=0;   //step
    while(pos_node->next!=list->tail&&step<position){
        pos_node=pos_node->next;
        step++;
    }
    if(step!=position|| pos_node == list->tail)return;
    //cout<<new_node->data;
    new_node->next = pos_node->next;
    pos_node->next = new_node;
}

// Delete a node from the linked list at a specific position
void delete_node(MagicLinkedList* list, int position) {
    // Remove the node at the specified position and free its memory. 
    // position is non-negative and start from 0. If position is invalid or out of bound, don't operate on list.
    // TODO: Implement this function
     // Remove the node at the specified position and free its memory.
    if (list == NULL || list->head == NULL) {
        return;// 处理错误或返回
    }
    if (position < 0) return;
    Node *pos_node = list->head;
    int step = 0;
    while (pos_node->next != list->tail && step < position) {
        pos_node = pos_node->next;
        step++;
    }

    if (step != position || pos_node->next == list->tail) return;

    Node *to_delete = pos_node->next;
    pos_node->next = to_delete->next;
    delete[] static_cast<char*>(to_delete->data);
    delete to_delete;  // 释放节点内存
}


// Destroy the linked list and free all allocated memory
void destroy(MagicLinkedList* list) {
    // Free all nodes in the list and the list itself
    // TODO: Implement this function
    if (list == NULL || list->head == NULL) {
        return;// 处理错误或返回
    }
     Node *current = list->head;
    while (current != nullptr) {
        Node *next = current->next;
        delete current; // Free the current node
        current = next; // Move to the next node
    }
    delete list;

}

void printx(MagicLinkedList *LinkedList){
    // TODO: print the node's data with its corresponding ASCII character from head node to tail node. Print each node in one line.
    /*
    Note:
    For each node, print every 1 byte (char) in [33, 127) as a character, if data is not within the domain, use '#' instead. You should print a node in one line.
    */
    if (LinkedList == NULL || LinkedList->head == NULL) {
        return;// 处理错误或返回
    }
    Node *current = LinkedList->head->next;
    while (current != LinkedList->tail) {
        char *data = static_cast<char*>(current->data); // 将 void* 转换为 char*
        for (size_t i = 0; i < current->byte_num; i++) { // 使用 byte_num 确定字符数
            char c = data[i]; // 从 data 中提取字符
            if (c >= 33 && c <= 126) {
                putchar(c);
            } else {
                putchar('#');
            }

        }
        cout << endl; 
        current = current->next; 
    }
    return;
}

void printx_reverse(MagicLinkedList *LinkedList){
    if (LinkedList == NULL || LinkedList->head == NULL) {
        return;// 处理错误或返回
    }
    // TODO: Similar with printx, only reverse the order of nodes, the values inside the nodes are not reversed.
    vector<Node*> nodes;
    Node *current = LinkedList->head->next;
    // 遍历链表并将节点存入 vector 的前面
    while (current != LinkedList->tail) {
        nodes.insert(nodes.begin(), current); // 在前面插入
        current = current->next;
    }

    // 正序遍历 vector 中的节点并打印
    for ( auto& node : nodes) {
        char *data = static_cast<char*>(node->data);
        for (size_t i = 0; i < node->byte_num; i++) {
            
            char c = data[i];
            if (c >= 33 && c < 127) {
                cout << c;
            } else {
                cout << '#';
            }
        }
        cout << endl; 
    }
}
// Do not make any modifications to this main function
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
        default: {
            break;
        }
        }
    }

    if (m_list != NULL) {
        destroy(m_list);
    }

    return 0;
}