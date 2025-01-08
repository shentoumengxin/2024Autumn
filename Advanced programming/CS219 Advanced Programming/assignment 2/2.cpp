//PREPRND BEGIN
#include <iostream>
#include <stdexcept>

using namespace std;
struct ChildNode;
struct OperationNode;

struct ChildNode {
    float value;                
    OperationNode* parent;     

    ChildNode(float val) : value(val), parent(nullptr) {}
};

struct OperationNode {
    char op;                   
    ChildNode* left;          
    ChildNode* right;         

    OperationNode(char operation) 
        : op(operation), left(nullptr), right(nullptr) {}

    ~OperationNode();
    
    void setLeft(ChildNode* leftChild);

    void setRight(ChildNode* rightChild);

    float compute() const;

    void print() const;

    OperationNode* deepCopy() const;

    OperationNode* shallowCopy() const;
};

OperationNode::~OperationNode() {
    if (left && left->parent == this) delete left;  
    if (right && right->parent == this) delete right;  
}
//PREPRND END

// TEMPLATE BEGIN

// Deletes an existing left node and updates the value and pointer
void OperationNode::setLeft(ChildNode* leftChild) {
    //TODO
    if (left && left->parent == this) {
        delete left;
    }
  
    left = leftChild;
    if (left) {
        left->parent = this;
    }
}

// Deletes an existing right node and updates the value and pointer
void OperationNode::setRight(ChildNode* rightChild) {
    //TODO
    if (right && right->parent == this) {
        delete right;
    }
    
    right = rightChild;
    if (right) {
        right->parent = this;
    }
}

// Calculate the result of this computational tree
float OperationNode::compute() const {
    //TODO
    if (!left || !right) {
        return 0;
    }
    float leftValue = left->value;
    float rightValue = right->value;
    switch (op) {
        case '+':
            return leftValue + rightValue;
        case '-':
            return leftValue - rightValue;
        case '*':
            return leftValue * rightValue;
        case '/':
            if (rightValue == 0) {
                return 0;
            }
            return leftValue / rightValue;
        default:
            return 0;
    }
}

// Print the formula according to the fixed format: Parent(*): 10.5 * 2 = 21
void OperationNode::print() const {
    //TODO
    if (!left || !right) {
        return;
    }
    float result = compute();
    cout << "Parent(" << op << "): " << left->value << " " << op << " " << right->value << " = " << result << endl;

}

//Deep copy of both left and right child nodes
OperationNode* OperationNode::deepCopy() const {
    OperationNode* copy = new OperationNode(op);
    // 深拷贝左子节点
    if (left) {
        ChildNode* leftCopy = new ChildNode(left->value);
        copy->setLeft(leftCopy);
    } else {
        copy->left = nullptr;
    }
    // 深拷贝右子节点
    if (right) {
        ChildNode* rightCopy = new ChildNode(right->value);
        copy->setRight(rightCopy);
    } else {
        copy->right = nullptr;
    }
    return copy;
    //TODO
}

//Share the original left and right child nodes
OperationNode* OperationNode::shallowCopy() const {
    OperationNode* copy = new OperationNode(op);

    //TODO
    copy->left = left;
    copy->right = right;
    return copy;
}
//TEMPLATE END

//APPEND BEGIN
void testCalculationTree() {
    OperationNode root('*');
 
    ChildNode* leftChild = new ChildNode(5.5f);   
    ChildNode* rightChild = new ChildNode(3.2f); 
    root.setLeft(leftChild);
    root.setRight(rightChild);

    root.print();  // Parent(*): 5.5 * 3.2 = 17.76

    OperationNode* deepCopy = root.deepCopy();
    root.setLeft(new ChildNode(10.5f));
    root.setRight(new ChildNode(2.0f));

    cout << "Deep Copy Result: ";
    deepCopy->print();  // Parent(*): 5.5 * 3.2 = 17.76
    cout << "Modified Original Result: ";
    root.print();       // Parent(*): 10.5 * 2 = 21

    OperationNode* shallowCopy = root.shallowCopy();
    root.left->value = 1.0f;
    root.right->value = 2.0f;
    cout << "Shallow Copy Result: ";
    shallowCopy->print(); // Parent(*): 1 * 2 = 2

    delete deepCopy;     
    delete shallowCopy;  
}
int main() {
    testCalculationTree();
    return 0;
}
//APPEND END