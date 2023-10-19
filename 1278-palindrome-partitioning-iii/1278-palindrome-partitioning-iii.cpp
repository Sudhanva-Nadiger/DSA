class Solution {
public:
    int dp[100][100], cost[100][100];
    int f(string& s, int ind, int k) {
        if(k < 0) {
            return 1e9;
        }
        
        if(ind == s.size()) {
            return (k == 0) ? 0 : 1e9;
        }
        
        int& st = dp[ind][k];
        if(st != -1) return st;
        
        int ans = 1e9;
        
        for(int i = ind; i <  s.size(); i++) {
            int t = cost[ind][i] + f(s, i+1, k-1);
            ans = min(ans, t);
        }
        
        return st = ans;
    }
    
    int palindromePartition(string s, int k) {
        int n = s.size();
        memset(dp, -1, sizeof dp);
        memset(cost, 0, sizeof dp);
        
        for(int g = 0; g < n; g++) {
            for(int i = 0, j = g; j < n; j++, i++) {
                if(g == 0) {
                    cost[i][j] = 0;
                } else if(g == 1) {
                    cost[i][j] = (s[i] != s[j]);
                } else {
                    cost[i][j] = cost[i+1][j-1] + (s[i] != s[j]);
                }
            }
        }
        
        return f(s, 0, k);
    }
};