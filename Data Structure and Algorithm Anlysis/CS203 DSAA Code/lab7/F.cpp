#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


inline long long my_abs(long long x) {
    return x < 0 ? -x : x;
}

struct AVLNode {
    int key;       
    int height;     // 高度
    int count;      // 相同键值的计数
    AVLNode* left;  // 左子节点
    AVLNode* right; // 右子节点

    AVLNode(int k) : key(k), height(1), count(1), left(nullptr), right(nullptr) {}
};

// 获取节点高度
int getHeight(AVLNode* node) {
    return node ? node->height : 0;
}

// 获取平衡因子
int getBalanceFactor(AVLNode* node) {
    if (!node) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

// 更新节点高度
void updateHeight(AVLNode* node) {
    if (node) {
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);
        node->height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
    }
}

// 右旋
AVLNode* rightRotate(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    // 旋转
    x->right = y;
    y->left = T2;

    // 更新高度
    updateHeight(y);
    updateHeight(x);

    return x;
}

// 左旋
AVLNode* leftRotate(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    // 旋转
    y->left = x;
    x->right = T2;

    // 更新高度
    updateHeight(x);
    updateHeight(y);

    return y;
}

// 插入节点
AVLNode* insertNode(AVLNode* node, int key) {
    if (!node) {
        return new AVLNode(key);
    }

    if (key < node->key) {
        node->left = insertNode(node->left, key);
    }
    else if (key > node->key) {
        node->right = insertNode(node->right, key);
    }
    else {
        // 相同键值，增加计数
        node->count++;
        return node;
    }

    // 更新高度
    updateHeight(node);

    // 获取平衡因子
    int balance = getBalanceFactor(node);

    // 左左情况
    if (balance > 1 && key < node->left->key) {
        return rightRotate(node);
    }
    // 右右情况
    if (balance < -1 && key > node->right->key) {
        return leftRotate(node);
    }
    // 左右情况
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    // 右左情况
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// 查找最小值节点
AVLNode* minValueNode(AVLNode* node) {
    AVLNode* current = node;
    while (current->left) {
        current = current->left;
    }
    return current;
}

// 删除节点
AVLNode* deleteNode(AVLNode* node, int key) {
    if (!node) return node;

    if (key < node->key) {
        node->left = deleteNode(node->left, key);
    }
    else if (key > node->key) {
        node->right = deleteNode(node->right, key);
    }
    else {
        // 找到要删除的节点
        if (node->count > 1) {
            node->count--;
            return node;
        }

        if (!node->left || !node->right) {
            AVLNode* temp = node->left ? node->left : node->right;
            if (!temp) {
             
                temp = node;
                node = nullptr;
            }
            else {
                // 一个子节点
                *node = *temp;
            }
            delete temp;
        }
        else {
            // 两个子节点，找到中序后继
            AVLNode* temp = minValueNode(node->right);
            node->key = temp->key;
            node->count = temp->count;
            temp->count = 1; // 重置计数
            node->right = deleteNode(node->right, temp->key);
        }
    }

    if (!node) return node;

    // 更新高度
    updateHeight(node);

    // 获取平衡因子
    int balance = getBalanceFactor(node);

    // 左左情况
    if (balance > 1 && getBalanceFactor(node->left) >= 0) {
        return rightRotate(node);
    }
    // 左右情况
    if (balance > 1 && getBalanceFactor(node->left) < 0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    // 右右情况
    if (balance < -1 && getBalanceFactor(node->right) <= 0) {
        return leftRotate(node);
    }
    // 右左情况
    if (balance < -1 && getBalanceFactor(node->right) > 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// 查找最接近的值，如果有两个相同距离的，选择较小的那个
bool findClosestHelper(AVLNode* node, int key, int& closest) {
    if (!node) return false;
    closest = node->key;
    AVLNode* current = node;
    while (current) {
        if (my_abs((long long)current->key - (long long)key) < my_abs((long long)closest - (long long)key)) {
            closest = current->key;
        }
        else if (my_abs((long long)current->key - (long long)key) == my_abs((long long)closest - (long long)key)) {
            if (current->key < closest) {
                closest = current->key;
            }
        }

        if (key < current->key) {
            current = current->left;
        }
        else if (key > current->key) {
            current = current->right;
        }
        else {
            break;
        }
    }
    return true;
}

// AVL 树类封装
class AVLTree {
public:
    AVLNode* root;

    AVLTree() : root(nullptr) {}

    void insert(int key) {
        root = insertNode(root, key);
    }

    void remove(int key) {
        root = deleteNode(root, key);
    }

    bool isEmpty() const {
        return root == nullptr;
    }

    // 查找最接近的值
    bool findClosest(int key, int& closest) const {
        if (!root) return false;
        closest = root->key;
        AVLNode* current = root;
        while (current) {
            if (my_abs((long long)current->key - (long long)key) < my_abs((long long)closest - (long long)key)) {
                closest = current->key;
            }
            else if (my_abs((long long)current->key - (long long)key) == my_abs((long long)closest - (long long)key)) {
                if (current->key < closest) {
                    closest = current->key;
                }
            }

            if (key < current->key) {
                current = current->left;
            }
            else if (key > current->key) {
                current = current->right;
            }
            else {
                break;
            }
        }
        return true;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    AVLTree pets;      
    AVLTree adopters;  
    long long total_dissatisfaction = 0;

    for(int i = 0; i < n; ++i){
        int a, b;
        cin >> a >> b;

        if(a == 0){
            // 宠物到达
            if(!adopters.isEmpty()){
                // 查找与 p=b 最接近的领养者 q
                int q;
                adopters.findClosest(b, q);
                total_dissatisfaction += my_abs((long long)b - (long long)q);
                // 移除选择的领养者
                adopters.remove(q);
            }
            else{
                // 没有等待的领养者，将宠物加入等待队列
                pets.insert(b);
            }
        }
        else{
            // 领养者到达
            if(!pets.isEmpty()){
                // 查找与 q=b 最接近的宠物 p
                int p;
                pets.findClosest(b, p);
                total_dissatisfaction += my_abs((long long)b - (long long)p);
                // 移除选择的宠物
                pets.remove(p);
            }
            else{
                // 没有等待的宠物，将领养者加入等待队列
                adopters.insert(b);
            }
        }
    }

    cout << total_dissatisfaction;
    return 0;
}
