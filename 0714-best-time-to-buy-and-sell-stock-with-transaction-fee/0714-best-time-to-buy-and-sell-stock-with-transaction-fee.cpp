class Solution {
public:
    int dp[(int)5*10000][2];
    int f(vector<int>& nums, int fee, int i, int buy) {
        if(i >= nums.size()) return 0;
        
        if(dp[i][buy] != -1) return dp[i][buy];
        
        int ans = 0;
        if(buy) {
            ans = max(-nums[i] + f(nums, fee, i+1, !buy), f(nums, fee, i+1, buy));
        }else {
            ans = max(nums[i]-fee + f(nums, fee, i+1, !buy), f(nums, fee, i+1, buy));
        }
        
        return dp[i][buy] = ans;
    }
    int maxProfit(vector<int>& prices, int fee) {
        memset(dp, -1, sizeof(dp));
        return f(prices, fee, 0, 1);
    }
};