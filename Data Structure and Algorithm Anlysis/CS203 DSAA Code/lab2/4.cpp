#include<iostream>
#include <map>
using namespace std;
// 合并两个有序的子数组
long long ans=0;
void merge(int a[],int left,int mid,int right){
    int a_1ptr=left;    //左边的数组
    int a_2ptr=mid+1;  //右边数组
    int c_ptr=0;
    int* c =new int[right-left+1];   //合并后数组
    
    while(a_1ptr<=mid&&a_2ptr<=right){
        if(a[a_1ptr]<=a[a_2ptr]){
            c[c_ptr++]=a[a_1ptr++];
        }else{
            c[c_ptr++]=a[a_2ptr++];
            ans += (long long)(mid - a_1ptr + 1) * a[a_2ptr - 1];
        }
    }
    while(a_1ptr<=mid){
        c[c_ptr++]=a[a_1ptr++];
    }
    while(a_2ptr<=right){
        c[c_ptr++]=a[a_2ptr++];
    }
    int k=0;
    for (int i = left; i <= right; i++)  //将 值传递给数组 a
	{
		a[i] = c[k++];
	}
	delete[]c;     // 辅助数组用完后，将其的空间进行释放
    
}
void merge_sort(int a[],int left,int right){
    if(left<right){
        int mid=(left+right)>>1;
        merge_sort(a,left,mid);   //先左后右
        merge_sort(a,mid+1,right);  //递归树，return后每次由上至下循环
        
        merge(a,left,mid,right);
    }
}


int main(){
    int n;
    cin>>n;
    int a[100001];
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    merge_sort(a,1,n);
   
    cout<<ans<<endl;

    return 0;
}