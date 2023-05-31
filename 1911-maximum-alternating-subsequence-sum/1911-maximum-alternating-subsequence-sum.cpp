class Solution {
public:
    long long dp[(int)1e5+1][2];
    long long f(vector<int>& nums, int i, bool isEvenIndex) {
        if(i >= nums.size()) {
            return 0ll;
        }
        
        auto& st = dp[i][isEvenIndex];
        
        if(st != -1) {
            return st;
        }
        
        long long int ans = INT_MIN;
        if(isEvenIndex) {
            long long take = nums[i] + f(nums, i+1, !isEvenIndex);
            long long notTake = f(nums, i+1, isEvenIndex);
            
            ans = max(ans, notTake);
            ans = max(ans, take);
        }else {
            long long take = -nums[i] + f(nums, i+1, !isEvenIndex);
            long long notTake = f(nums, i+1, isEvenIndex);
            
            ans = max(ans, max(take, notTake));
        }
        
        return st = ans;
    }
    long long maxAlternatingSum(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return f(nums, 0, true);
    }
};