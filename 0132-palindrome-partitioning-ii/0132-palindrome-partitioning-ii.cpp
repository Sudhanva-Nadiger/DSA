class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        int dp[n], isPal[n][n];
        
        memset(isPal, 0, sizeof isPal);
        memset(dp, 0, sizeof dp);
        
        for(int g = 0; g < n; g++) {
            for(int i = 0, j = g; j < n; i++, j++) {
                if(g == 0) {
                    isPal[i][j] = 1;
                }else if(g ==  1) {
                    isPal[i][j] = (s[i] == s[j]);
                }else {
                    isPal[i][j] = (isPal[i+1][j-1] && (s[i] == s[j]));
                }
            }
        }
        
        dp[0] = 0;
        
        for(int j = 1; j < n; j++) {
            if(isPal[0][j]) {
                dp[j] = 0;
                continue;
            }
            int mini = 1e9;
            for(int i = j; i >= 1; i--) {
                if(isPal[i][j]) {
                    mini = min(mini, dp[i-1]);
                }
            }
            dp[j] = mini+1;
        }
        
        return dp[n-1];
    }
};