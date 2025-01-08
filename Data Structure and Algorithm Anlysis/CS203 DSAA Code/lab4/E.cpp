#include<iostream>
using namespace std;
struct people{
public:
    long long height;
    int position;
    int left;
    int right;
};
int  main(){
    int T;
    cin>>T;
    people *a=new people[50000+5];
    people *stack=new people[50000+5];
    for(int i=1;i<=T;i++){
        printf("Case %d:\n",i);
        int n;
        scanf("%d",&n);
        int top=-1;
        for(int i=0;i<n;i++){
            scanf("%lld",&a[i].height);
            a[i].position=i+1;
            a[i].left = 0;          // 初始化为 0 表示没有左侧更高的元素
            a[i].right = 0;         // 初始化为 0 表示没有右侧更高的元素
        }
        for(int i=0;i<n;i++){
            if(top==-1){
                stack[++top]=a[i];
            }else{
                if(stack[top].height>=a[i].height){
                    stack[++top]=a[i];
                    stack[top].left=0;
                }else{
                    while(top!=-1&&stack[top].height<a[i].height){
                        a[i].left=stack[top].position;
                        top--;
                    }
                    stack[++top]=a[i];
                }
            }
        }
        top=-1;
        for(int i=n-1;i>=0;i--){
            if(top==-1){
                stack[++top]=a[i];
            }else{
                if(stack[top].height>=a[i].height){
                    stack[++top]=a[i];
                    stack[top].right=0;
                }else{
                    while(top!=-1&&stack[top].height<a[i].height){
                        a[i].right=stack[top].position;
                        top--;
                    }
                    stack[++top]=a[i];
                }
            }
        }
        for(int i=0;i<n;i++){
           printf("%d %d\n",a[i].left,a[i].right);
        }
        
    }
    delete[] stack;  //删除内存耗时很长
    delete[] a;


    return 0;
}