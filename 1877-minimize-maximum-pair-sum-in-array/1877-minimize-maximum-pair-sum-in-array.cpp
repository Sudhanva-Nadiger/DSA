class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int ans = -1e9, n = nums.size();
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n/2; i++) {
            ans = max(ans, nums[i]+nums[n-i-1]);
        }
        return ans;
    }
};