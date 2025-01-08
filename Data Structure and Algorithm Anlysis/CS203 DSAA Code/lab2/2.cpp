#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
    int T,m,n;
    scanf("%d",&T);
    while(T--){
        int a[100005];
        int b[100005];
        int c[200010];
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<m;i++){
        scanf("%d",&b[i]);
    }
    int i=0,j=0,k=0;  //三个指针用于记录位置
    while(i<n&&j<m){
        if(a[i]<=b[j]){
            c[k++]=a[i++];
        }else{
            c[k++]=b[j++];
        }                 //保证a,b至少有一个数组被排列完
    }
    while(i<n){
        c[k++]=a[i++];
    }
    while(j<m){
        c[k++]=b[j++];
    }
    for(int i=0;i<n+m-1;i++){
        printf("%d ",c[i]);
    }
    printf("%d\n",c[n+m-1]);
    }
    

}