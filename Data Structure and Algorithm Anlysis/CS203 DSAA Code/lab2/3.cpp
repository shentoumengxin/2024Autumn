#include<iostream>
using namespace std;
long long binary_find(int j, int n, int tar, int a[]) {
    int left = j + 1, right = n - 1;
    int left_f = -1, right_f = -1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (a[mid] < tar) {
            left = mid + 1;
        } else {
              if (a[mid] == tar) left_f = mid;
            right = mid - 1;
        }
    }

    // If tar is not found, no need to proceed
    if (left_f == -1) {
        return 0;
    }

    // Find rightmost occurrence of tar
    left = left_f; right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (a[mid] > tar) {
            right = mid - 1;
        } else {
            if (a[mid] == tar) right_f = mid;
            left = mid + 1;
        }
    }

    return right_f - left_f + 1;
}
int main(){
    int n,m;
    int a[3005];
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }   
   
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            
            if(a[j]>a[j+1]){
                int temp;
                temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
            }
        }
    }  //sort
    long long ans=0;
    for(int i=0;i<=n-3;i++){
        if(a[i]>m)continue;
        for(int j=i+1;j<=n-2;j++){
            if(i==j||a[j]>m)continue;

            if(a[i]+a[j]>m)continue;
            ans += binary_find(j, n, m - a[i] - a[j], a);
        }
    }
    cout<<ans<<endl;
    return 0;
}