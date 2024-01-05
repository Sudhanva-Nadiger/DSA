class Solution {
public:
   int solve(vector<int>& nums,int idx,int prev_idx,vector<vector<int>>& dp){
       if(idx>=nums.size()){
           return 0;
       }
       
       if(dp[idx][prev_idx+1] != -1){
           return dp[idx][prev_idx+1] ;
       }
       
       int include = INT_MIN;
       int exclude = INT_MIN;
       if(prev_idx == -1 or nums[idx]>nums[prev_idx]){
           include = max(1+solve(nums,idx+1,idx,dp),solve(nums,idx+1,prev_idx,dp));
       }
       else{
           exclude = solve(nums,idx+1,prev_idx,dp);
       }
       
       return dp[idx][prev_idx+1] = max(include,exclude);
   }
    
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+2,-1));
        return solve(nums,0,-1,dp);
    }
};