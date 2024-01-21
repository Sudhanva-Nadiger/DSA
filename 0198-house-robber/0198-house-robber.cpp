class Solution {
public:
    int dp[101][101];
    int f(vector<int>& nums,int prev,int i){
        if(i >= nums.size()){
            return 0;
        }
        
        int& store = dp[prev+1][i];
        if(store != -1){
            return store;
        }
        int rob = 0;
        int dontRob = 0;
        
        if(prev == -1 or prev != i-1){
            rob = nums[i] + f(nums,i,i+1);
        }
        
        dontRob = f(nums,prev,i+1);
        
        return store = max(rob,dontRob);
    }
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return f(nums,-1,0);
    }
};