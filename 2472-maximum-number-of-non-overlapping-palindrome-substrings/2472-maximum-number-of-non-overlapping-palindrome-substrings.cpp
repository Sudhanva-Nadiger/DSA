class Solution {
public:
    int dp[2000][2000], mem[2000];
    vector<int> nums[2000];
    
    int f(int n,int i, int k) {
        if(i >= n) {
            return 0;
        }
        
        if(mem[i] != -1) return mem[i];
        
        int ans = 0;
        for(int j : nums[i]) {
            int t = f(n, j+1, k) + (j-i+1 >= k);
            ans = max(ans, t);
        }
        
        ans = max(ans, f(n, i+1, k));
        
        return mem[i] = ans;
    }
    
    int maxPalindromes(string s, int k) {
        int n = s.size();

        memset(dp, 0, sizeof dp);
        memset(mem, -1, sizeof mem);
        
        for(int g = 0; g < n; g++) {
            for(int i = 0, j = g; j < n; j++, i++) {
                if(g == 0) {
                    dp[i][j] = 1;
                } else if(g == 1) {
                    dp[i][j] = (s[i] == s[j]);
                } else {
                    dp[i][j] = (s[i]==s[j] && dp[i+1][j-1]);
                }
                
                if(dp[i][j]) {
                    nums[i].push_back(j);
                }
            }
        }
        memset(dp, -1, sizeof dp);
        return f(n, 0, k);
    }
};