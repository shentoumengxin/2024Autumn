#include <iostream>
using namespace std;

typedef unsigned long Item;

class Stack {
private:
    enum { MAX = 10 };
    Item* pitems;  // Pointer to the array holding the stack items
    int size;      // Maximum size of the stack
    int top;       // Index of the next available slot in the stack

public:
    // Default constructor
    Stack(int n = MAX) : size(n), top(0) {
        pitems = new Item[size];  // Dynamically allocate memory for the stack
    }

    // Copy constructor (Deep copy)
    Stack(const Stack& st) : size(st.size), top(st.top) {
        pitems = new Item[size];  // Allocate new memory for the stack
        for (int i = 0; i < top; ++i) {
            pitems[i] = st.pitems[i];  // Copy each element
        }
    }

    // Destructor
    ~Stack() {
        delete[] pitems;  // Deallocate memory
    }

    // Check if the stack is empty
    bool isempty() const {
        return top == 0;
    }

    // Check if the stack is full
    bool isfull() const {
        return top == size;
    }

    // Push an item onto the stack
    bool push(const Item& item) {
        if (isfull()) {
            return false;  // Stack is full
        }
        pitems[top++] = item;  // Add item to the stack
        return true;
    }

    // Pop an item from the stack
    bool pop(Item& item) {
        if (isempty()) {
            return false;  // Stack is empty
        }
        item = pitems[--top];  // Remove item from the stack
        return true;
    }

    // Assignment operator (Deep copy)
    Stack& operator=(const Stack& st) {
        if (this != &st) {  // Avoid self-assignment
            delete[] pitems;  // Free existing memory
            size = st.size;  // Copy size and top
            top = st.top;
            pitems = new Item[size];  // Allocate new memory
            for (int i = 0; i < top; ++i) {
                pitems[i] = st.pitems[i];  // Copy elements
            }
        }
        return *this;  // Return the current object to support chain assignment
    }

    // Display stack contents
    void display() const {
        if (isempty()) {
            cout << "Stack is empty!" << endl;
        } else {
            cout << "Stack contents: ";
            for (int i = 0; i < top; ++i) {
                cout << pitems[i] << " ";
            }
            cout << endl;
        }
    }
};

// Demonstration program
int main() {
    Stack s1;  
    Stack s2(5); 

    
    cout << "Pushing items into s2: ";
    for (int i = 1; i <= 5; ++i) {
        if (s2.push(i)) {
            cout << i << " ";
        } else {
            cout << "Stack full, unable to push " << i << " ";
        }
    }
    cout << endl;
    s2.display();

    
    cout << "Popping items from s2: ";
    for (int i = 0; i < 5; ++i) {
        Item item;
        if (s2.pop(item)) {
            cout << item << " ";
        } else {
            cout << "Stack empty, unable to pop ";
        }
    }
    cout << endl;

    
    Stack s3 = s2;  // Copy constructor is called here
    cout << "Stack s3 (after copy from s2): ";
    s3.display();


    Stack s4;
    s4 = s2;  
    cout << "Stack s4 (after assignment from s2): ";
    s4.display();

    return 0;
}
