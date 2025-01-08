#include<iostream>
using namespace std;
class deque{
private:
    int  size;
    int  left;
    int right;
    long long *value;
    int *index;
public:
    deque(int t){
        size=t+1;
        left=0;
        right=0;
        value=new long long[size];
        index=new int[size];
    }
    bool is_full(){
        if((right+1)%size==left)return true;
        else return false;
    }
    bool is_empty(){
        if(right==left)return true;
        else return false;
    }
    bool push_left(long long t,int in){
        if(is_full()){
            return false;
        }
        left=(left-1+size)%size;
        value[left]=t;
        index[left]=in;
        return true;
    }
    bool push_right(long long t,int in){
        if(is_full()){
            return false;
        }
        value[right] = t;
        index[right]=in;
        right = (right + 1) % size;
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
            return -1;
        }
        return value[(right - 1 + size) % size];
    }
    int get_leftindex(){
        if(is_empty()){
            return false;
        }
        return index[left];
    }
    int get_rightindex(){
        if(is_empty()){
            return -1;
        }
        return index[(right - 1 + size) % size];
    }
    bool delete_left(){
        if(is_empty()){
            return -1;
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

template<typename T>
T Max(T a, T b) {
    return (a > b) ? a : b;  
}

int main(){
    long long k;
    int n;
    long long *a=new long long[3000000+5];
    long long ans=1;
    scanf("%lld %d",&k,&n);
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    long long max_ans=0;
    deque *max=new deque(n);
    deque *min=new deque(n);
    int r=0;   //right point
    int l=0;   //left point
    while(l<n){
        while(!max->is_empty()&&max->get_leftindex()<l){
            max->delete_left();   //从左边删除index超过当前左指针元素
        }
        
        while(!min->is_empty()&&min->get_leftindex()<l){
            min->delete_left();   //从左边删除index超过当前左指针元素
        }

        if(l==r){  //一个元素直接入栈
            ans=1;
            max->push_right(a[l],l);
            min->push_right(a[l],l);
            max_ans=Max(ans,max_ans);
            r++;
        }
        while(true){
            while(!max->is_empty()&&max->get_right()<a[r]){
                max->delete_right();   //进入单调队列
            }
            max->push_right(a[r],r);
            while(!min->is_empty()&&min->get_right()>a[r]){
                min->delete_right();   //进入单调队列
            }
            min->push_right(a[r],r);
            if(r<n&&(long long)max->get_left()-min->get_left()<=k){
                ans++;
                max_ans=Max(ans,max_ans);
                r++;
            }else{
                l++;
                ans--;
                break;
            }
        }
        
        
    }
    printf("%lld",max_ans);
    return 0;
}