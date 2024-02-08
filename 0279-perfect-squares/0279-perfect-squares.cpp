class Solution {
public:
    int dp[101][10001];
    
    int f(vector<int>& nums, int i, int target) {
        if(target == 0) {
            return 0;
        }
        
        if(i == nums.size() || target < 0) {
            return 10001;
        }
        
        int& st = dp[i][target];
        
        if(st != -1) return st;
        
        int take = 1 + f(nums, i, target-nums[i]);
        int notTake = f(nums, i+1, target);
        
        
        return st = min(take, notTake);
    }
    
    int numSquares(int n) {
        vector<int> nums;
        
        for(int i = 1; i*i <= n; i++) {
            nums.push_back(i*i);
        }
        
        memset(dp, -1, sizeof dp);
        return f(nums, 0, n);
    }
};