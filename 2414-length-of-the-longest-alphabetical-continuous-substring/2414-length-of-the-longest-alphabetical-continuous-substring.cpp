class Solution {
public:
    int longestContinuousSubstring(string s) {
        int n = s.size();
        vector<int> dp(n, 1);
        
        int ans = 1;
        for(int i = 1; i < n; i++) {
            if(s[i-1]+1 == s[i]) {
                dp[i] += dp[i-1];
            }
            
            ans = max(ans, dp[i]);
        }
        
        return ans;
    }
};