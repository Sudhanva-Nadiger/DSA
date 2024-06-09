class Solution {
public:
    int dp[501][500][26];
    int f(vector<int>& nums, int i, int prev, int count, int k) {
        if(i == nums.size()) {
            return 0;
        }
        
        int& st = dp[i][prev+1][count];
        
        if(st != -1) return st;
        
        int newCount = count + (prev != -1 && nums[i] != nums[prev]);
        int take = 0;
        
        if(newCount <= k)
            take = 1 + f(nums, i+1, i, newCount, k);
        int notTake = f(nums, i+1, prev, count, k);
        
        return st = max(take, notTake);
    }
    
    int maximumLength(vector<int>& nums, int k) {
        memset(dp, -1, sizeof dp);
        return f(nums, 0, -1, 0, k);
    }
};