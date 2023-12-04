class Solution {
public:
    bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'); 
    }
    
    int beautifulSubstrings(string s, int k) {
        int n = s.size();
        int dp[n][n];
        memset(dp, 0, sizeof dp);
        
        for(int g = 0; g < n; g++) {
            for(int i = 0, j = g; j < n; i++,j++) {
                if(g == 0) {
                    if(isVowel(s[i])) {
                        dp[i][j] = 1;
                    }
                } else if(g == 1) {
                    dp[i][j] = isVowel(s[i]) + isVowel(s[j]);
                } else {
                    dp[i][j] = isVowel(s[i]) + dp[i+1][j-1] + isVowel(s[j]);
                }
            }
        }
        
        int ans = 0;
        for(int g = 0; g < n; g++) {
            for(int i = 0, j = g; j < n; i++,j++) {
                int len = j-i+1;
                int v = dp[i][j], c = len-v;
                
                ans += ((v == c) && ((v*c)%k == 0));
            }
        }
        
        return ans;
    }
};