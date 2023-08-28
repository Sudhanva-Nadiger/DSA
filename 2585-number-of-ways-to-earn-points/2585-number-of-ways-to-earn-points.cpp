class Solution {
public:
    int dp[51][1001];
    int mod = 1e9+7;
    int f(vector<vector<int>>& nums, int i, int target) {
        if(target == 0) {
            return 1;
        }
        
        if(i >= nums.size() || target < 0) return 0;
        if(dp[i][target] != -1) return dp[i][target];
        
        int ans = 0;
        int count = 0;
        while(count <= nums[i][0]) {
            if(count == 0) {
                ans = (ans + f(nums, i+1, target))%mod;
            }
            else
                ans = (ans + f(nums, i+1,target-count*nums[i][1]))%mod;
            count++;
        }
        
        return dp[i][target] = ans%mod;
    }
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        memset(dp, -1, sizeof dp);
        return f(types, 0, target)%mod;
    }
};