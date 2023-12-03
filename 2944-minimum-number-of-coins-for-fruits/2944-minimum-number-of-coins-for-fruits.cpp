class Solution {
public:
    int dp[10001];
    int f(vector<int>& nums, int i) {
        if(i >= nums.size()) {
            return 0;
        }
        
        if(dp[i] != -1) return dp[i];
        
        int ans = 1e9;
        int j = i+1;
        int k = i+1;
        
        while(k >= 0) {
            int t = f(nums, j);
            j++;
            k--;
            
            ans = min(ans, t);
        }
        
        return dp[i] = ans + nums[i];
    }
    
    int minimumCoins(vector<int>& prices) {
        memset(dp, -1, sizeof dp);
        return f(prices, 0);
    }
};