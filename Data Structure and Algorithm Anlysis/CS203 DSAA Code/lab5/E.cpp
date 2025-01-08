#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 200005;

int n;
int S[MAXN];
int sa[MAXN], rank_arr[MAXN], tmp_rank[MAXN], cnt[MAXN]={0};
int lcp[MAXN];
int len_s1;

void build_sa(int m) {
    int i, k, p;
    int *x = rank_arr, *y = tmp_rank;

    // Count frequencies
    for (i = 0; i < n; ++i) cnt[x[i] = S[i]]++;
    
    for (i = 1; i < m; ++i) cnt[i] += cnt[i - 1];
   
    for (i = n - 1; i >= 0; --i) sa[--cnt[x[i]]] = i;

    for (k = 1; k <= n; k <<= 1) {
        p = 0;
        
        for (i = n - k; i < n; ++i) y[p++] = i;
        for (i = 0; i < n; ++i)
            if (sa[i] >= k) y[p++] = sa[i] - k;

       
        for (i = 0; i < m; ++i) cnt[i] = 0;
       
        for (i = 0; i < n; ++i) cnt[x[y[i]]]++;
        
        for (i = 1; i < m; ++i) cnt[i] += cnt[i - 1];
        
        for (i = n - 1; i >= 0; --i)
            sa[--cnt[x[y[i]]]] = y[i];

       
        int *tmp = x;
        x = y;
        y = tmp;
        x[sa[0]] = 0;
        p = 1;
        for (i = 1; i < n; ++i) {
            int a1 = y[sa[i]];
            int a2 = y[sa[i - 1]];
            int b1 = y[sa[i] + k < n ? sa[i] + k : 0];
            int b2 = y[sa[i - 1] + k < n ? sa[i - 1] + k : 0];
            x[sa[i]] = (a1 == a2 && b1 == b2) ? p - 1 : p++;
        }
        if (p >= n)
            break;
        m = p;
    }
}

void build_lcp() {
    int i, k = 0;
    for (i = 0; i < n; ++i) rank_arr[sa[i]] = i;
    for (i = 0; i < n; ++i) {
        if (rank_arr[i] == 0) {
            k = 0;
            continue;
        }
        int j = sa[rank_arr[i] - 1];
        while (i + k < n && j + k < n && S[i + k] == S[j + k]) k++;
        lcp[rank_arr[i]] = k;
        if (k > 0) k--;
    }
}

int main() {

    char s1[MAXN], s2[MAXN];
    scanf("%s", s1);
    scanf("%s", s2);

    len_s1 = strlen(s1);
    int len_s2 = strlen(s2);

    n = len_s1 + len_s2 + 1;


    int i;
    for (i = 0; i < len_s1; ++i)
        S[i] = s1[i] + 1; 
    S[len_s1] = 0; 
    for (i = 0; i < len_s2; ++i)
        S[len_s1 + 1 + i] = s2[i] + 1;

    int m = 256 + 2;

    build_sa(m);
    build_lcp();

    
    int ans = 0;
    for (i = 1; i < n; ++i) {
        int pos1 = sa[i - 1];
        int pos2 = sa[i];
        if ((pos1 < len_s1) != (pos2 < len_s1)) {
            if (lcp[i] > ans) ans = lcp[i];
        }
    }

    printf("%d\n", ans);

    return 0;
}
