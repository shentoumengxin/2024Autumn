#include <iostream>
#include <vector>
using namespace std;

int sum_of_digits(long long n) {
    int sum = 0;
    while(n > 0){
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    long long t;
    int k;
    long long s;
    cin >> t >> k >> s;
    
    vector<long long> top_k;

    long long last_ans = s;
    

    long long min_number = 0;
    
    // 存储输出结果
    vector<long long> outputs;
    
    for(long long i = 1; i <= t; i++){
        long long n = i + last_ans;
        long long a_n = n + sum_of_digits(n);
        

        if(i == 1){
            min_number = a_n;
        }
        else{
            if(a_n < min_number){
                min_number = a_n;
            }
        }
        
    
        int pos = top_k.size();
        while(pos > 0 && a_n < top_k[pos - 1]){
            pos--;
        }
        top_k.insert(top_k.begin() + pos, a_n);
        
        // 如果超过 k 个，移除最小的数
        if(top_k.size() > k){
            top_k.erase(top_k.begin());
        }
        
        if(i % 100 == 0){
            long long ans;
            if(top_k.size() >= k){
                ans = top_k[0]; 
            }
            else{
                ans = min_number;
            }
            outputs.push_back(ans);
            last_ans = ans;
        }
    }
    
    for(auto it = outputs.begin(); it != outputs.end(); it++){
        if(it != outputs.begin()) cout << ' ';
        cout << *it;
    }
    cout << '\n';
    return 0;
}
