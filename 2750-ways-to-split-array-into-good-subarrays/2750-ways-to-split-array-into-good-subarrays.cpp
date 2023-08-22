class Solution {
public:
    int mod = 1e9+7;
    int dp[100001][2];
    int f(vector<int>& nums, int i, bool found) {
        if(i >= nums.size()) return found;
        
        if(dp[i][found] != -1) return dp[i][found];
        
        int ans = 0;
        if(nums[i] == 0) {
            if(found) {
                // split
                int a = f(nums, i+1, false);
                
                // dont split
                int b = f(nums, i+1, found);
                
                ans = (ans%mod + (a%mod + b%mod)%mod)%mod;
            }else {
                int c = f(nums, i+1, found);
                
                ans = (ans%mod + c%mod)%mod;
            }
        }else {
            int a = f(nums, i+1, true);
            ans =(ans%mod + a%mod)%mod;
        }
        
        return dp[i][found] = ans;
    }
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return f(nums, 0, false);
    }
};