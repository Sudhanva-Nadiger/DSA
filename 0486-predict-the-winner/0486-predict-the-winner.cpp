class Solution {
public:
    int dp[20][20];
    
    int f(vector<int>& nums, int i, int j) {
        if(i > j) {
            return 0;
        }
        
        int& st = dp[i][j];
        
        if(st != -1) return st;
        
        int takeStart = nums[i] + min(f(nums, i+1, j-1), f(nums, i+2, j));
        int takeEnd = nums[j] + min(f(nums, i+1, j-1), f(nums, i, j-2));
        
        return st = max(takeStart, takeEnd);
    }
    
    bool PredictTheWinner(vector<int>& nums) {
         memset(dp, -1, sizeof dp);
         int maxScore = f(nums, 0, nums.size()-1);
         int totSum = accumulate(nums.begin(), nums.end(), 0);
         return maxScore >= totSum - maxScore;
    }
};