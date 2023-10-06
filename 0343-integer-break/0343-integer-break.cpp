class Solution {
public:
    int dp[60][60];
    int f(int n, int count) {
        if(n == 0) {
            return (count >= 2);
        }
        
        if(dp[n][count] != -1) {
            return dp[n][count];
        }
        
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            if(i <= n) {
                ans = max(ans, i*f(n-i, count+1));
            }
        }
        
        return dp[n][count] = ans;
    }
    
    int integerBreak(int n) {
        memset(dp, -1, sizeof dp);
        return f(n, 0);
    }
};