class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        int dp[n];
        int count[n];
        for(int i = 0; i < n; i++) {
            dp[i] = 1;
            count[i] = 1;
        }
        
        for(int i = 1; i < n; i++) {
            for(int j = i-1; j >= 0; j--) {
                if(nums[i] > nums[j]) {
                    if(dp[i] < dp[j]+1) {
                        dp[i] = dp[j] + 1;
                        count[i] = count[j];
                    }else if(dp[i] == dp[j]+1) {
                        count[i] += count[j];
                    }
                }
            }
        }
        
        int lis = 0;
        int res = 0;
        
        for(int i = 0; i < n; i++) {
            if(lis < dp[i]) {
                lis = dp[i];
                res = count[i];
            }else if(lis == dp[i]) {
                res += count[i];
            }
        }
        
        return res;
    }
};