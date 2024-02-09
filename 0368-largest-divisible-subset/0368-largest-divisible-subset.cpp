class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        
        if(n <= 1) return nums;
        sort(nums.begin(), nums.end());
        int dp[n], hash[n];
        memset(dp, 0, sizeof dp);
        memset(hash, -1, sizeof hash);
        
        int maxi = -1, id = -1;
        
        for(int i = 1; i < n; i++) {
            
            for(int prev = 0; prev < i; prev++) {
                if(nums[i]%nums[prev] == 0 && dp[i] < dp[prev]+1) {
                    dp[i] = dp[prev] + 1;
                    hash[i] = prev;
                }
            }
            
            if(dp[i] > maxi) {
                maxi = dp[i];
                id = i;
            }
        }
        vector<int> ans;
        while(id != -1) {
            ans.push_back(nums[id]);
            id = hash[id];
        }
        
        return ans;
    }
};