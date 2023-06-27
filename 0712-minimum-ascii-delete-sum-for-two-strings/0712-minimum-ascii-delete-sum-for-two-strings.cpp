class Solution {
public:
    
    int dp[1001][1001];
    int f(string& s1, string& s2, int i, int j) {
        if(i >= s1.size()) {
            
            int t = 0;
            while(j < s2.size()) {
                t += int(s2[j++]);                
            }
            
            return t;
        }
        
        if(j >= s2.size()) {
            int t = 0;
            while(i < s1.size()) {
                t += int(s1[i++]);
            }
            
            return t;
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s1[i] == s2[j]) {
            return dp[i][j] = f(s1, s2, i+1, j+1);
        }
        
        int a = int(s1[i]) + f(s1, s2, i+1, j);
        int b = int(s2[j]) + f(s1, s2, i,j+1);
        
        return dp[i][j] = min(a, b);
    }
    
    int minimumDeleteSum(string s1, string s2) {
        memset(dp, -1,sizeof(dp));
        return f(s1, s2, 0, 0);
    }
};