class Solution {
public:
    int solve(vector<int>& cost,int i,vector<int> &dp){
        if(i>=cost.size()){
            return 0;
        }
        
        // if(i==cost.size()-1){
        //     return cost[i];
        // }
    
        if(dp[i] != -1){
            return dp[i];
        }
        
       return dp[i] =cost[i]+min(solve(cost,i+1,dp),solve(cost,i+2,dp));
  
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1,-1);
        int a = solve(cost,0,dp);
        dp = vector<int>(cost.size()+1,-1);
        int b = solve(cost,1,dp);
        
        return min(a,b);
    }
};