class Solution {
public:
    int countSubstrings(string s) {
        const int n = s.size();
        int dp[n][n];
        memset(dp, 0, sizeof dp);
        int ans = 0;
        
        for(int g = 0; g < n; g++) 
            for(int i = 0, j = g; j < n; i++, j++) {
                if(g == 0) {
                    dp[i][j] = 1;
                } else if(g == 1) {
                    dp[i][j] = (s[i]==s[j]);
                } else {
                    dp[i][j] = (s[i]==s[j]) && dp[i+1][j-1];
                }
                
                ans += dp[i][j];
            }
        
        return ans;
    }
};