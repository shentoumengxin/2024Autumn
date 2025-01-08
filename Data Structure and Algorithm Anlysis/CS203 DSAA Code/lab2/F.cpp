#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
typedef struct 
{
    int red;
    int blue;/* data */
}strings;
//red
int partition(strings a[],int left,int right){
    int pivot_ind=left+rand()%(right-left+1);
    strings pivot=a[pivot_ind];
    a[pivot_ind]=a[left];
    a[left]=pivot;
    int i=left,j=right;
    while(i<j){
        
        while(i<=j&&a[i].blue<=pivot.blue)i++;
        while(i<=j&&a[j].blue>=pivot.blue)j--;
        if(i<j){
            strings temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
        
    }
    a[left]=a[j];   //降序返回j
    a[j]=pivot;
    return j;
}
void quicksort(strings a[],int left,int right){
    if(left<right){
        int p=partition(a,left,right);
        quicksort(a,left,p-1);
        quicksort(a,p+1,right);
    }else{
        return;
    }
}

//red
int partition_red(strings a[],int left,int right){
    int pivot_ind=left+rand()%(right-left+1);
    strings pivot=a[pivot_ind];
    a[pivot_ind]=a[right];
    a[right]=pivot;
    int i=left,j=right;
    while(i<j){
        while(i<=j&&a[j].red<=pivot.red)j--;
        while(i<=j&&a[i].red>=pivot.red)i++;
        
        if(i<j){
            strings temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
        
    }    //升序返回i
    a[right]=a[i];
    a[i]=pivot;
    return i;
}
void quicksort_red(strings a[],int left,int right){
    if(left<right){
        int p=partition_red(a,left,right);
        quicksort_red(a,left,p-1);
        quicksort_red(a,p+1,right);
    }else{
        return;
    }
}
int magic_cancel(strings* left_strings, int left_size, strings* right_strings, int right_size){
    int total_magic = 0;
    int remaining_red = 0;
    int remaining_blue = 0;

    // 遍历 left_strings 数组
    for(int i = 0; i < left_size; i++){
        strings current = left_strings[i];

        if(i == 0){
            // 第一个串，直接更新剩余珠子数量
            remaining_red += current.red;
            remaining_blue += current.blue;
        } else {
            // 计算可消除的珠子数量
            int cancel_magic = min(remaining_red, current.blue);
            total_magic += cancel_magic;

            // 更新剩余珠子数量
            remaining_red = remaining_red - cancel_magic + current.red;
            remaining_blue = remaining_blue - cancel_magic + current.blue;
        }
    }

    // 遍历 right_strings 数组
    for(int i = 0; i < right_size; i++){
        strings current = right_strings[i];

        if(i == 0 && left_size == 0){
            // 如果没有 left_strings，且是第一个 right_strings
            remaining_red += current.red;
            remaining_blue += current.blue;
            continue;
        }

        // 计算可消除的珠子数量
        int cancel_magic = min(remaining_red, current.blue);
        total_magic += cancel_magic;

        // 更新剩余珠子数量
        remaining_red = remaining_red - cancel_magic + current.red;
        remaining_blue = remaining_blue - cancel_magic + current.blue;
    }

    return total_magic;
}

  
int main(){
    int T;
    srand(time(0));
    cin>>T;
    while(T--){
       
        int n;
        scanf("%d",&n);
        strings left_strings[100005];
        strings right_strings[100005];
        int left_size=0;
        int right_size=0;
        for(int i=0;i<=n-1;i++){
            int blue,red;
            scanf("%d %d",&blue,&red);
            if(blue<=red){
                left_strings[left_size].blue=blue;
                left_strings[left_size].red=red;
                left_size++;
            }else{
                right_strings[right_size].blue=blue;
                right_strings[right_size].red=red;
                right_size++;
            }

        }
       
        if(left_size > 0){
            quicksort(left_strings, 0, left_size - 1);
        }
        if(right_size > 0){
            quicksort_red(right_strings, 0, right_size - 1);
        }

        int total_magic = magic_cancel(left_strings, left_size, right_strings, right_size);
        printf("%d\n",total_magic);
        
    }
    return 0;
}