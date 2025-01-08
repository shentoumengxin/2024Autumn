#include <iostream>
#include<cmath>
using namespace std;

typedef long long ll;
const int MOD = 998244353;

// 快速幂函数，用于计算 a^b mod MOD
ll power_pow(ll a, ll b, ll mod) {
    ll res = 1;
    a %= mod;
    while(b > 0){
        if(b & 1LL){
            res = res * a % mod;
        }
        a = a * a % mod;
        b >>=1LL;
    }
    return res;
}

// 计算阶乘 mod MOD
ll factorial(int n) {
    ll res = 1;
    for(int i = 1; i <= n; ++i){
        res = res * i % MOD;
    }
    return res;
}

// 计算 C(n, k) mod MOD
ll comb(int n, int k) {
    if(n < k || k < 0) return 0;
    ll numer = factorial(n);
    ll denom = (power_pow(factorial(k), MOD-2, MOD) * power_pow(factorial(n - k), MOD-2, MOD)) % MOD;
    return (numer * denom) % MOD;
}

int get_left(int n){
    if(n == 0) return 0;
    int h = (int)floor(log2(n)); // 堆的高度
    int max_last_level = 1 << h; 
    int nodes_before_last = (1 << h) -1; // 除最后一层外的节点数
    int last_level_nodes = n - nodes_before_last; // 最后一层的实际节点数
    int left = (1 << (h-1)) -1; // 左子树除最后一层外的节点数
    left += min(last_level_nodes, 1 << (h-1)); // 最后一层分配到左子树的节点数
    return left;
}

ll H(int n){
    if(n <=1) return 1;
    int L = get_left(n);
    ll c = comb(n-1, L);
    ll left = H(L);
    ll right = H(n-1-L);
    return c * left % MOD * right % MOD;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    cout << H(N) << "\n";
    return 0;
}
