class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        
        if(n <= 1) return nums;
        vector<int> dp(n, 1), hash(n);
        sort(begin(nums),end(nums));
        
        int id = -1;
        int maxi = 0;
        
        for(int i = 1; i < n; i++) {
            hash[i] = i;
            for(int prev = 0; prev < i; prev++) {
                if(nums[i]%nums[prev] == 0 and dp[i] < dp[prev] +1) {
                    dp[i] =1+dp[prev];
                    hash[i] = prev;
                }
            }
            
            if(dp[i] > maxi) {
                maxi = dp[i];
                id = i;
            }
            
        }
        
        vector<int> ans;
        ans.push_back(nums[id]);
        while(hash[id] != id) {
            id = hash[id];
            ans.push_back(nums[id]);
        }
        return ans;
    }
};