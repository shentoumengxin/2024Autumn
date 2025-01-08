#include <iostream>
using namespace std;
//几个关键问题： 1.空间k+1其实并无卵，只是提醒在is_full and isempty的逻辑判断情况下
//会有一个内存空间的浪费。这么做是为了区分full和isempty
//2.为了提高利用率，在数组中把首尾连起来的办法是 (right+1)%size 向右时折回头
//(left-1+size)%size 向左减时折到尾部
//3. 为了防止重复赋值覆盖，这部分代码实现是左指针指向头部元素，右指向头部元素前一个位置。
//4. 队列和栈很重要的一个特性就是可以维护进入的顺序。即内部元素存在先出现和后出现的关系
class Deque {
private:
    int *arr;
    int left;
    int right;
    int size;

public:
    Deque(int k) {
        size = k + 1;  // 从逻辑上多分配一个空间
        arr = new int[size];
        left = 0;
        right = 0;
    }

    bool isEmpty() const {
        return left == right;
    }

    bool isFull() const {
        return (right + 1) % size == left;
    }

    bool insertFront(int value) {
        if (isFull()) {
            cout << "队列已满，无法从前端插入元素\n";
            return false;
        }
        left = (left - 1 + size) % size;
        arr[left] = value;
        return true;
    }

    bool insertRear(int value) {
        if (isFull()) {
            cout << "队列已满，无法从后端插入元素\n";
            return false;
        }
        arr[right] = value;
        right = (right + 1) % size;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) {
            cout << "队列为空，无法从前端删除元素\n";
            return false;
        }
        left = (left + 1) % size;
        return true;
    }

    bool deleteRear() {
        if (isEmpty()) {
            cout << "队列为空，无法从后端删除元素\n";
            return false;
        }
        right = (right - 1 + size) % size;
        return true;
    }

    int getFront() const {
        if (isEmpty()) {
            cout << "队列为空\n";
            return -1;
        }
        return arr[left];
    }

    int getRear() const {
        if (isEmpty()) {
            cout << "队列为空\n";
            return -1;
        }
        return arr[(right - 1 + size) % size];
    }

    
};
// 自己写的
class deque{
    private:
    int  size;
    int  left;
    int right;
    long long *value;
public:
    deque(int t){
        size=t+1;
        left=0;
        right=0;
        value=new long long[size];
    }
    bool is_full(){
        if((right+1)%size==left)return true;
        else return false;
    }
    bool is_empty(){
        if(right==left)return true;
        else return false;
    }
    bool push_left(long long t){
        if(is_full()){
            return false;
        }
        left=(left-1+size)%size;
        value[left]=t;
        return true;
    }
    bool push_right(long long t){
        if(is_full()){
            return false;
        }
        
        value[right]=t;
        right=(right+1)%size;
        return true;
    }
    long long get_left(){
        if(is_empty()){
            return false;
        }
        return value[left];
    }
    long long get_right(){
        if(is_empty()){
            return false;
        }
        return value[(right - 1 + size) % size];
    }
    bool delete_left(){
        if(is_empty()){
            return false;
        }
        left=(left+1)%size;
        return true;
    }
    bool delete_right(){
        if(is_empty()){
            return false;
        }
        right=(right-1+size)%size;
        return true;
    }
    
    
};
int main() {
    deque dq(3);

    dq.push_right(5);
    dq.push_right(10);
    //dq.push_left(20);
    cout << "队列尾部元素: " << dq.get_right() << endl;

    dq.delete_right();
    cout << "队列尾部元素: " << dq.get_right() << endl;

    dq.push_left(15);
    cout << "队列头部元素: " << dq.get_left() << endl;

    dq.delete_left();
    cout << "队列头部元素: " << dq.get_left() << endl;

    return 0;
}
