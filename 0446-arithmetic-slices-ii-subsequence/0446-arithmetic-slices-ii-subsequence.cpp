class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        unordered_map<long, int> dp[n];
        int ans = 0;
        
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                long diff = (long) nums[i] - nums[j];
                int count = dp[j].count(diff) ? dp[j][diff] : 0;
                dp[i][diff] += count + 1;
                ans += count;
            }
        }
        return ans;
    }
};