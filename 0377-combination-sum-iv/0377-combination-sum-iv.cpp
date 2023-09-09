class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        unsigned dp[target+1];
        memset(dp,0, sizeof dp);
        dp[0] = 1ll;
        
        for(int t = 1; t <= target; t++) {
            for(auto it : nums) {
                if(t >= it) {
                    dp[t] += dp[t-it];
                }
            }
        }
        
        return dp[target];
    }
};