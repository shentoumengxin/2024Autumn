// 相邻八个方向都不可以选
// 不会是一个满树，很稀疏
// dfs(x)
// 选x，打标记
// if(x可选)
// sum+=x.val
// dfs(x+1)
// x*(取消标记) sum-=x.val
// else
// dfs(x+1)
#include <iostream>
#include<vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--){
        int N, M;
        cin >> N >> M;
        vector<vector<int>> matrix(N, vector<int>(M));
        for(int i=0;i<N;i++) {
            for(int j=0;j<M;j++) {
                cin >> matrix[i][j];
            }
        }
        
        vector<int> valid_masks;
        for(int mask=0; mask<(1<<M); mask++) {
            if( (mask & (mask <<1)) ==0 ){
                valid_masks.push_back(mask);
            }
        }
        
        vector<vector<int>> row_mask_sum(N, vector<int>(valid_masks.size(),0));
        for(int i=0;i<N;i++) {
            for(int k=0; k<valid_masks.size(); k++) {
                int mask = valid_masks[k];
                int sum =0;
                for(int j=0; j<M; j++) {
                    if(mask & (1<<j)){
                        sum += matrix[i][j];
                    }
                }
                row_mask_sum[i][k] = sum;
            }
        }
        
        int num_masks = valid_masks.size();
        vector<vector<bool>> compatible(num_masks, vector<bool>(num_masks, false));
        for(int k=0; k<num_masks; k++) {
            for(int l=0; l<num_masks; l++) {
                int mask1 = valid_masks[k];
                int mask2 = valid_masks[l];
                if( (mask1 & mask2) ==0 && 
                    (mask1 & (mask2 <<1)) ==0 &&
                    (mask1 & (mask2 >>1)) ==0 ){
                    compatible[k][l] = true;
                }
                else{
                    compatible[k][l] = false;
                }
            }
        }
        
        vector<vector<int>> dp(N+1, vector<int>(num_masks, -1));
        int zero_mask_idx = -1;
        for(int k=0; k<num_masks; k++) {
            if(valid_masks[k]==0){
                zero_mask_idx = k;
                break;
            }
        }
        if(zero_mask_idx != -1){
            dp[0][zero_mask_idx] =0;
        }
        
        for(int i=1; i<=N; i++) {
            for(int curr=0; curr<num_masks; curr++) {
                int curr_mask = valid_masks[curr];
                int curr_sum = row_mask_sum[i-1][curr];
                for(int prev=0; prev<num_masks; prev++) {
                    if(dp[i-1][prev]==-1) continue;
                    if(compatible[curr][prev]){
                        dp[i][curr] = max(dp[i][curr], dp[i-1][prev] + curr_sum);
                    }
                }
            }
        }
        
        int answer =0;
        for(int k=0; k<num_masks; k++) {
            if(dp[N][k] > answer){
                answer = dp[N][k];
            }
        }
        cout << answer << "\n";
    }
    return 0;
}
