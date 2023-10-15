class Solution {
public:
    int dp[501][501];
    int mod = 1e9 + 7;
    
    int f(int i, int steps, int len) {
        if((steps == 0) && (i == 0)) {
            return 1;
        }
        
        if((steps == 0) || (i >= len) || (i < 0) || (i > steps)) {
            return 0;
        }
        
        if(dp[i][steps] != -1) return dp[i][steps];
        
        int a = f(i+1, steps-1, len)%mod;
        int b = f(i-1, steps-1, len)%mod;
        int c = f(i, steps-1, len)%mod;
        
        return dp[i][steps] = ((a+b)%mod + c)%mod;
    }
    
    int numWays(int steps, int arrLen) {
        memset(dp, -1, sizeof dp);
        return f(0, steps, arrLen);
    }
};