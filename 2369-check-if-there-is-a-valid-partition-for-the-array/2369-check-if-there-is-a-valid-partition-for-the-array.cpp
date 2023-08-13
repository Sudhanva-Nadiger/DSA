class Solution {
public:
    int dp[100001];
    bool f(vector<int>& nums, int n, int i) {
        if(i >= n) return true;
        
        if(dp[i] != -1) return dp[i];
        
        bool ans = false;
        
        if(i+1 < n) {
            if(nums[i] == nums[i+1]) {
                ans = ans || f(nums, n, i+2);
            }
            if(i+2 < n) {
                if(nums[i] == nums[i+1] && nums[i] == nums[i+2]) {
                    ans = ans || f(nums, n, i+3);
                }
                
                if(nums[i]+1 == nums[i+1] && nums[i+1]+1 == nums[i+2]) {
                    ans = ans || f(nums, n, i+3);
                }
            }
        }
        
        return dp[i] = ans;
    }
    bool validPartition(vector<int>& nums) {
        memset(dp, -1, sizeof dp);
        return f(nums, nums.size(), 0);
    }
};