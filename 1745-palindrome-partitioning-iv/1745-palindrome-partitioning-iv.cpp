class Solution {
public:
    int isPal[2001][2001], dp[2001][4];
    
    int f(string& s, int index, int c) {
        if(c < 0) {
            return false;
        }
        
        if(index == s.size()) {
            return c == 0;
        }
        
        int& st = dp[index][c];
        if(st != -1) return st;
        
        bool ans = false;
        for(int i = index; i < s.size() && !ans; i++) {
            if(isPal[index][i]) {
                ans = ans | f(s, i+1, c-1);
            }
        }
        
        return st = ans;
    }
    
    bool checkPartitioning(string s) {
        int n = s.size();
        
        for(int g = 0; g <n; g++) {
            for(int i = 0, j = g; j < n; j++, i++) {
                if(g == 0) {
                    isPal[i][j] = 1;
                } else if (g == 1) {
                    isPal[i][j] = (s[i] == s[j]);
                } else {
                    isPal[i][j] = (s[i] == s[j] && isPal[i+1][j-1]);
                }
            }
        }
        
        memset(dp, -1, sizeof dp);
        return f(s, 0, 3);
    }
};