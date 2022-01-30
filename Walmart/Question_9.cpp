class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        for(int i = 0;i<n;i++) dp[i][i] = 0;
        for(int len = 2;len<=n;len++){
            for(int i = 0;i+len-1<n;i++){
                int j = i+len-1;
                for(int k = i;k<=j;k++){
                    if(k == i){
                        dp[i][j] = min(dp[i][j],dp[k+1][j]+k+1);
                    }else if(k == j){
                        dp[i][j] = min(dp[i][j],dp[i][k-1]+k+1);
                    }else{
                        dp[i][j] = min(dp[i][j],max(dp[i][k-1],dp[k+1][j])+k+1);
                    }
                }
            }
        }
        return dp[0][n-1];
    }
};