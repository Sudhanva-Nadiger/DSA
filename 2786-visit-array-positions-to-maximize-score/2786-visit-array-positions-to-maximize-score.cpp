class Solution {
public:
    long long dp[(int)1e5+2][2];
    long long f(vector<int>& nums, int i, int parity, int x) {
        if(i == nums.size()) return 0;
        
        long long& st = dp[i][parity];
        if(st != -1) return st;
        
        long long take = nums[i] + f(nums, i+1, nums[i]%2, x);
        if(parity != -1 && parity != nums[i]%2) {
            take -= x;
        }
        long long notTake = f(nums, i+1, parity, x);
        
        return st = max(take, notTake);
    }
    long long maxScore(vector<int>& nums, int x) {
        memset(dp, -1, sizeof dp);
        return nums[0] + f(nums, 1, nums[0]%2, x);
    }
};