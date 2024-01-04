class Solution {
public:
    static const int maxN = 1e5;
    int dp[maxN+1];
    
    int f(int n = maxN) {
        if(n == 1 || n < 0)
            return 1e9;
        
        if(n == 0) return 0;
        
        if(dp[n] != -1) return dp[n];
        
        int a = 1 + f(n-2);
        int b = 1 + f(n-3);
        
        return dp[n] = min(a, b);
    }
    
    int minOperations(vector<int>& nums) {
        map<int, int> mp;
        for(auto it : nums) {
            mp[it]++;
        }
        memset(dp, -1, sizeof dp);
        f();
        int ans = 0;
        for(auto it : mp) {
            int t = f(it.second);
            if(t >= 1e9) {
                return -1;
            } 
            
            ans += t;
        }
        
        return ans;
    }
};