class Solution {
public:
    int mod = 1e9+7;
    int countPalindromicSubsequences(string s) {
        int n = s.size();
        long long dp[n][n];
        int next[n], prev[n];
        memset(dp, 0, sizeof dp);
        unordered_map<char, int> mp;
        
        for(int i = 0; i < n; i++) {
            if(mp.find(s[i]) == mp.end()) {
                prev[i] = -1;
            }else {
                prev[i] = mp[s[i]];
            }
            
            mp[s[i]] = i;
        }
        
        mp.clear();
        for(int i = n-1; i >= 0; i--) {
            if(mp.find(s[i]) == mp.end()) {
                next[i] = n;
            }else {
                next[i] = mp[s[i]];
            }
            
            mp[s[i]] = i;
        }
        
        for(int g = 0; g < n; g++) {
            for(int i = 0, j = g; j < n; j++,i++) {
                if(g == 0) {
                    dp[i][j] = 1ll;
                }else if(g == 1) {
                    if(s[i] == s[j]) {
                        dp[i][j] = 2ll;
                    }else {
                        dp[i][j] = 2ll;
                    }
                }else {
                    if(s[i] == s[j]) {
                        int nis = next[i];
                        int pie = prev[j];
                        
                        if(nis > pie) {
                            dp[i][j] = (2*dp[i+1][j-1]+2)%mod;
                        }else if(nis == pie) {
                            dp[i][j] = (2*dp[i+1][j-1]+1)%mod;
                        }else {
                            dp[i][j] = (2*dp[i+1][j-1]-dp[nis+1][pie-1])%mod;
                        }
                    }else {
                        dp[i][j] = (dp[i][j-1]+dp[i+1][j]-dp[i+1][j-1])%mod;
                    }
                }
            }
        }
        if(dp[0][n-1] < 0) dp[0][n-1] += mod;
        return dp[0][n-1]%mod;
    }
};