class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        int dp[amount+1][n+1];
        memset(dp, 0, sizeof dp);
        
        dp[0][0] = 1;
        
        for(int i = 1; i <= n; i++) {
            dp[0][i] = 1;
            for(int t = 1; t <= amount; t++) {
                if(coins[i-1] <= t) {
                    dp[t][i] = dp[t-coins[i-1]][i];
                }
                
                dp[t][i] += dp[t][i-1];
            }
        }
        
        return dp[amount][n];
    }
};