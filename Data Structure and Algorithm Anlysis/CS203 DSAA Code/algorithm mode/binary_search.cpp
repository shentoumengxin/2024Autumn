#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int N,Q;
    int a[100005];
        while(left<right&&!left_flag){  //找到数组中最接近x的最靠右的左边界。
            int mid=((left+right)+1)>>1;   //向上取整 防止无限循环
            if(a[mid]<x){
                left=mid;        //record the left boundary do not break!
                
            }
            else if(a[mid]==x){
                left=mid;
            }
            else if(a[mid]>x){
                right=mid-1;  //向下取，所以前面需要向上取。
            }
        }
        left=1,right=N;
        while(left<right&&!right_flag){  //最接近y的最靠左的右边界。
            int mid=(left+right)>>1;  
            if(a[mid]<y){      //因为后面是+1所以不用向上取整
                left=mid+1;
            }
            else if(a[mid]==y){
               
                right=mid;
            }
            else if(a[mid]>y){
                right=mid;
                
            }
        }
       
    }
    
}