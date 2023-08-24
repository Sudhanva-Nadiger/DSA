class Solution {
public:
    int dp[100001][3];
    int f(vector<int>& nums, int i, int count) {
        if(count == 0) return 0;
        
        if(i == nums.size()) {
            if(count == 0) {
                return 0;
            }
            
            return -1e9;
        }
        if(dp[i][count] != -1) return dp[i][count];
        int take = nums[i] + ((count == 2) ? i : -1*i) + f(nums, i+1, count-1);
        int notTake = f(nums, i+1, count);
        
        return dp[i][count] = max(take, notTake);
    }
    int maxScoreSightseeingPair(vector<int>& values) {
        memset(dp, -1, sizeof dp);
        return f(values, 0, 2);
    }
};