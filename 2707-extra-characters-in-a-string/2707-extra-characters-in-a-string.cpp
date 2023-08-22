class Solution {
public:
    int minExtraChar(string s, vector<string>& d) {
        int n = s.size();
        
        unordered_set<string> st(d.begin(), d.end());
        int dp[n][n];
        memset(dp, 0, sizeof dp);
        
        for(int g = 0; g < n; g++) {
            for(int i = 0, j = g; j < n; i++, j++) {
                string str = s.substr(i, j-i+1);
                if(st.count(str)) {
                    dp[i][j] = 0;
                } else {
                    if(g == 0) {
                        dp[i][j] = 1;
                    } else {
                        
                        int mini = INT_MAX;
                        for(int k = i; k < j; k++) {
                            int l = dp[i][k];
                            int r = dp[k+1][j];
                            
                            mini = min(mini, l+r);
                        }
                        
                        dp[i][j] = mini;
                    }
                }
            }
        }
        
        return dp[0][n-1];
    }
};