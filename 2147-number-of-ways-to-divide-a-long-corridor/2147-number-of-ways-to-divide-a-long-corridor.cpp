class Solution {
public:
    int dp[100001][3];
    int mod = 1e9 + 7;
    int f(string& s, int i, int count) {
        if(i == s.size()) return count == 0;
        if(dp[i][count] != -1) return dp[i][count];
        
        int ans = 0;
        if(s[i] == 'S') {
            if(count == 0) {
                ans = (ans + f(s, i+1, 1))%mod;
            } else {
                ans = (ans + f(s, i+1, count-1))%mod;
            }
        } else {
            if(count == 0) {
                // break;
                ans = (ans + f(s, i+1, 2))%mod;
                
                // notBreak
                ans = (ans+ f(s, i+1, 0))%mod;
            } else {
                ans = (ans + f(s, i+1, count))%mod;
            }
        }
        
        return dp[i][count] = ans%mod;
    }
    
    int numberOfWays(string corridor) {
        memset(dp, -1, sizeof dp);
        return f(corridor, 0, 2);
    }
};